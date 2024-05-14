/**
 * Created March 24, 2024
 *
 * The MIT License (MIT)
 * Copyright (c) 2024 K. Suwatchai (Mobizt)
 *
 *
 * Permission is hereby granted, free of charge, to any person returning a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef CORE_FILE_CONFIG_H
#define CORE_FILE_CONFIG_H

#include <Arduino.h>
#include "./Config.h"
#include "./core/Memory.h"

#if defined(ENABLE_FS)
#include <FS.h>
#define FILEOBJ File
#else

#endif

#define FIREBASE_CHUNK_SIZE 2048

enum file_operating_mode
{
    file_mode_open_read,
    file_mode_open_write,
    file_mode_open_append,
    file_mode_remove
};

struct firebase_blob_writer
{
public:
    firebase_blob_writer() {}
    void init(uint8_t *data, size_t size)
    {
        this->data = data;
        this->size = size;
        index = 0;
    }

    size_t curIndex() const { return index; }

    size_t write(const uint8_t *buf, size_t size)
    {
        uint32_t towrite = size;
        if (index + towrite > this->size)
            towrite = this->size - index;
        if (towrite > 0)
        {
            memcpy(data + index, buf, towrite);
            index += towrite;
        }
        return towrite;
    }

private:
    size_t size = 0;
    uint8_t *data = nullptr;
    uint32_t index = 0;
};

#if defined(ENABLE_FS)
typedef void (*FileConfigCallback)(FILEOBJ &file, const char *filename, file_operating_mode mode);
#endif

#if defined(ENABLE_FS) && defined(ENABLE_CLOUD_STORAGE)

struct file_upload_resumable_data
{
private:
    enum resume_state
    {
        resume_state_undefined,
        resume_state_send_header,
        resume_state_send_payload,
        resume_state_read_response
    };
    int index = 0;
    int size = 0;
    int read = 0;
    bool enable = false;
    String location;
    int len = 0;
    resume_state state = resume_state_undefined;

public:
    file_upload_resumable_data() {}
    bool isEnabled() { return enable; }
    void setSize(size_t size)
    {
        this->size = size;
        enable = size > 0;
    }
    void getRange()
    {
        int minChunkSize = 256 * 1024; // required by google
        read = size - index <= minChunkSize ? size - index : minChunkSize;
    }
    void updateRange()
    {
        index += read;
        getRange();
        len = read;
    }
    int getChunkSize(int size, int payloadIndex, int dataIndex)
    {
        int chunkSize = size - dataIndex < FIREBASE_CHUNK_SIZE ? size - dataIndex : FIREBASE_CHUNK_SIZE;

        if (payloadIndex + chunkSize > index + read)
            chunkSize = index + read - payloadIndex;

        return chunkSize;
    }
    void updateState(uint32_t &payloadIndex)
    {
        if (location.length() > 0)
        {
            if (state == resume_state_send_header)
            {
                state = resume_state_send_payload;
                payloadIndex = index;
            }
            else if (state == resume_state_send_payload)
            {
                state = resume_state_undefined;
                clear();
            }
        }
    }
    bool isUpload() { return state == resume_state_send_payload; }
    void setHeaderState()
    {
        if (location.length())
            state = resume_state_send_header;
    }
    int isComplete(int size, int payloadIndex)
    {
        if (payloadIndex < index + read)
            return 1;
        else if (payloadIndex < size)
        {
            state = resume_state_read_response;
            return 2;
        }
        return 0;
    }
    void getHeader(String &header, const String &host, const String &ext)
    {
        header = FPSTR("PUT ");
        header += ext;
        header += FPSTR(" HTTP/1.1\r\nHost: ");
        header += host;
        header += FPSTR("\r\nConnection: keep-alive\r\nContent-Length: ");
        header += len;
        header += FPSTR("\r\nContent-Range: bytes ");
        header += index;
        header += '-';
        header += index + read - 1;
        header += '/';
        header += size;
        header += FPSTR("\r\n\r\n");
    }
    void clear()
    {
        location.remove(0, location.length());
        index = 0;
        size = 0;
        read = 0;
        enable = false;
        len = 0;
    }
    String &getLocationRef() { return location; }
    String getLocation() { return location.c_str(); }
};

struct file_upload_multipart_data
{
    enum multipart_state
    {
        multipart_state_undefined,
        multipart_state_send_header,
        multipart_state_send_options_payload,
        multipart_state_send_data_payload,
        multipart_state_send_last_payload,
        multipart_state_read_response
    };

private:
    bool enable = false;
    int index = 0;
    int size = 0;
    int read = 0;
    String boaundary, options_part, last_part;
    multipart_state state = multipart_state_undefined;

public:
    file_upload_multipart_data() {}
    bool isEnabled() { return enable; }
    void setSize(size_t size)
    {
        this->size = size;
        enable = size > 0;
    }
    int getChunkSize(int size, int payloadIndex, int dataIndex)
    {
        int chunkSize = size - dataIndex < FIREBASE_CHUNK_SIZE ? size - dataIndex : FIREBASE_CHUNK_SIZE;

        if (state == multipart_state_send_options_payload && options_part.length() && payloadIndex + chunkSize > index + (int)options_part.length())
        {
            chunkSize = index + options_part.length() - payloadIndex;
        }
        else if (state == multipart_state_send_data_payload && size && payloadIndex + chunkSize > index + size)
        {
            chunkSize = index + size - payloadIndex;
        }
        else if (state == multipart_state_send_last_payload && last_part.length() && payloadIndex + chunkSize > index + (int)last_part.length())
        {
            chunkSize = index + last_part.length() - payloadIndex;
        }

        return chunkSize;
    }
    bool isUpload() { return state == multipart_state_send_options_payload || state == multipart_state_send_data_payload || state == multipart_state_send_last_payload; }
    void updateState(uint32_t payloadIndex)
    {
        if (enable)
        {
            if (state == multipart_state_undefined)
            {
                state = multipart_state_send_header;
            }
            else if (state == multipart_state_send_header)
            {
                state = multipart_state_send_options_payload;
            }
            else if (state == multipart_state_send_options_payload)
            {
                if (options_part.length() && payloadIndex == index + options_part.length())
                {
                    state = multipart_state_send_data_payload;
                    index += options_part.length();
                }
            }
            else if (state == multipart_state_send_data_payload)
            {
                if (size && (int)payloadIndex >= index + size)
                {
                    state = multipart_state_send_last_payload;
                    index += size;
                }
            }
            else if (state == multipart_state_send_last_payload)
            {
                if (last_part.length() && payloadIndex == index + last_part.length())
                {
                    state = multipart_state_read_response;
                    index += last_part.length();
                }
            }
        }
    }

    multipart_state getState() { return state; }

    void clear()
    {
        boaundary.remove(0, boaundary.length());
        options_part.remove(0, options_part.length());
        last_part.remove(0, last_part.length());
        enable = false;
        size = 0;
        index = 0;
        state = multipart_state_undefined;
    }

    void setOptions(const String &options)
    {
        options_part = "--";
        options_part += getBoundary();
        options_part += "\r\n";
        options_part += FPSTR("Content-Type: application/json; charset=UTF-8\r\n\r\n");
        options_part += options;
        options_part += "\r\n\r\n";
        options_part += "--";
        options_part += getBoundary();
        options_part += "\r\n\r\n";
    }

    String getOptions()
    {
        return options_part;
    }

    void setLast()
    {
        last_part = "\r\n--";
        last_part += getBoundary();
        last_part += "--";
    }

    String getLast()
    {
        setLast();
        return last_part;
    }

    String getBoundary(bool newLine = false)
    {
        if (boaundary.length() == 0)
            boaundary = makeBoundary(15);
        if (newLine)
            return String(boaundary + "\r\n");
        return boaundary;
    }

    String makeBoundary(size_t len)
    {
        Memory mem;
        String temp = FPSTR("=_abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        char *buf = reinterpret_cast<char *>(mem.alloc(len));
        if (len)
        {
            --len;
            buf[0] = temp[0];
            buf[1] = temp[1];
            for (size_t n = 2; n < len; n++)
            {
                int key = rand() % (int)(temp.length() - 1);
                buf[n] = temp[key];
            }
            buf[len] = '\0';
        }
        String out = buf;
        mem.release(&buf);
        return out;
    }
};

#endif

struct file_config_data
{
    enum file_operating_status
    {
        file_status_closed,
        file_status_opened
    };
#if defined(ENABLE_FS)
    FILEOBJ file;
#endif
    String filename;
    size_t file_size = 0;

#if defined(ENABLE_FS) && defined(ENABLE_CLOUD_STORAGE)
    file_upload_resumable_data resumable;
    file_upload_multipart_data multipart;
#endif
#if defined(ENABLE_FS)
    FileConfigCallback cb = NULL;
#endif
    file_operating_status file_status = file_status_closed;
    uint8_t *data = nullptr;
    size_t data_pos = 0;
    size_t data_size = 0;
    bool internal_data = false;
    firebase_blob_writer outB;
    bool initialized = false;

    void clearInternalData()
    {
        if (internal_data && data && data_size > 0)
        {
            delete data;
            data = nullptr;
        }
        data_size = 0;
        internal_data = false;
    }

    void initBlobWriter(size_t size)
    {
        clearInternalData();
        data = new uint8_t[size];
        if (data)
        {
            data_size = size;
            internal_data = true;
            outB.init(data, size);
        }
    }

public:
    file_config_data &operator=(file_config_data rhs)
    {
        copy(rhs);
        return *this;
    }

    void copy(file_config_data rhs)
    {
#if defined(ENABLE_FS)
        this->file = rhs.file;
#endif
        this->filename = rhs.filename;
#if defined(ENABLE_FS)
        this->cb = rhs.cb;
#endif
        if (!rhs.internal_data && rhs.data && rhs.data_size > 0)
        {
            clearInternalData();
            this->data = rhs.data;
            this->data_size = rhs.data_size;
            this->internal_data = false;
        }

        this->initialized = rhs.initialized;
    }

    void clear()
    {
        clearInternalData();
        filename.remove(0, filename.length());
#if defined(ENABLE_FS)
        cb = NULL;
#endif
        data = nullptr;
        data_size = 0;
        internal_data = false;
        initialized = false;
    }
};

#if defined(ENABLE_FS)

class FileConfig
{

public:
    FileConfig(const String &filename, FileConfigCallback cb)
    {
        clear();
        setFilename(filename);
        setCallback(cb);
        data.initialized = true;
    }
    ~FileConfig() {}
    void clear() { data.clear(); }

    FileConfig &setFilename(const String &filename)
    {
        if (filename.length() > 0 && filename[0] != '/')
            data.filename += '/';
        data.filename += filename;
        return *this;
    }

    FileConfig &setCallback(FileConfigCallback cb)
    {
        data.cb = cb;
        return *this;
    }

    file_config_data &get() { return data; }

private:
    file_config_data data;
};

#endif

class DefaultFileConfig
{

public:
    template <typename T = const char *>
    DefaultFileConfig() {}
    ~DefaultFileConfig() {}
    file_config_data &get() { return data; }

private:
    file_config_data data;
};

class BlobConfig
{

public:
    BlobConfig(uint8_t *data = nullptr, size_t size = 0)
    {
        clear();
        if (data && size > 0)
        {
            this->data.data = data;
            this->data.data_size = size;
            this->data.internal_data = false;
        }

        this->data.initialized = true;
    }
    ~BlobConfig() {}
    void clear() { data.clear(); }

    uint8_t *blob() const { return data.data; }
    size_t size() const { return data.data_size; }

    file_config_data &getData() { return data; }

private:
    file_config_data data;
};

template <typename T>
static file_config_data &getFile(T &file) { return file.get(); }

template <typename T>
static file_config_data &getBlob(T &blob) { return blob.getData(); }

#endif