# Messaging

## Description

Google Cloud Messaging class


```cpp
class Messaging
```

## Functions


1. ## 🔹  void url(const String &url)

Set the Messaging URL

```cpp
void url(const String &url)
```

**Params:**

- `url` - The Messaging URL.


2. ## 🔹  void loop()

Perform the async task repeatedly.
Should be places in main loop function.

```cpp
void loop()
```


<<<<<<< Updated upstream
3. ## 🔹  String send(AsyncClientClass &aClient, const Messages::Parent &parent, const Messages::Message &message)
=======
3. ## 🔹  bool send(AsyncClientClass &aClient, const Messages::Parent &parent, const Messages::Message &message)
>>>>>>> Stashed changes


The Firebase project Id should be only the name without the firebaseio.com.

This function requires ServiceAuth authentication.

Read more details about HTTP v1 API here https://firebase.google.com/docs/reference/fcm/rest/v1/projects.messages

```cpp
<<<<<<< Updated upstream
String send(AsyncClientClass &aClient, const Messages::Parent &parent, const Messages::Message &message)
=======
bool send(AsyncClientClass &aClient, const Messages::Parent &parent, const Messages::Message &message)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Messages::Parent object included project Id in its constructor.
- `message` - The Messages::Message object that holds the information to send.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.
=======
- Boolean type status indicates the success of the operation.
>>>>>>> Stashed changes

4. ## 🔹  void send(AsyncClientClass &aClient, const Messages::Parent &parent, const Messages::Message &message, AsyncResult &aResult)


The Firebase project Id should be only the name without the firebaseio.com.

This function requires ServiceAuth authentication.

Read more details about HTTP v1 API here https://firebase.google.com/docs/reference/fcm/rest/v1/projects.messages

```cpp
void send(AsyncClientClass &aClient, const Messages::Parent &parent, const Messages::Message &message, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Messages::Parent object included project Id in its constructor.
- `message` - The Messages::Message object that holds the information to send.
- `aResult` - The async result (AsyncResult).


5. ## 🔹  void send(AsyncClientClass &aClient, const Messages::Parent &parent, const Messages::Message &message, AsyncResultCallback cb, const String &uid = "")


The Firebase project Id should be only the name without the firebaseio.com.

This function requires ServiceAuth authentication.

Read more details about HTTP v1 API here https://firebase.google.com/docs/reference/fcm/rest/v1/projects.messages

```cpp
void send(AsyncClientClass &aClient, const Messages::Parent &parent, const Messages::Message &message, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Messages::Parent object included project Id in its constructor.
- `message` - The Messages::Message object that holds the information to send.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).

