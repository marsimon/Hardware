
# Documents

## Description

Google Cloud Firestore database Documents class


```cpp
class Documents
```

## Functions

<<<<<<< Updated upstream
1. ## 🔹 String batchGet(AsyncClientClass &aClient, const Firestore::Parent &parent, BatchGetDocumentOptions batchOptions)

 Gets multiple documents.
=======
1. ## 🔹 bool batchGet(AsyncClientClass &aClient, const Firestore::Parent &parent, BatchGetDocumentOptions batchOptions)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
addDocument, mask, transaction, newTransaction and readTime functions.

addDocument used for adding the document path to read.
mask used for setting the mask fields to return. If not set, returns all fields. If the document has a field that is not present in this mask,
that field will not be returned in the response. Use comma (,) to separate between the field names.

The following function used for creating the union field consistency_selector and can be only one of the following field e.g.
transaction, newTransaction and readTime functions.

Then the following functions can't be mixed used.
- transaction used for reading the document in a transaction. A base64-encoded string.
- newTransaction used for creating the transaction.
- readTime used for setting the documents as they were at the given time. This may not be older than 270 seconds.
A timestamp in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits.
Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".


This function requires ServiceAuth authentication.

For more detail, see https://cloud.google.com/firestore/docs/reference/rest/v1/projects.databases.documents/batchGet


```cpp
<<<<<<< Updated upstream
String batchGet(AsyncClientClass &aClient, const Firestore::Parent &parent, BatchGetDocumentOptions batchOptions)
=======
bool batchGet(AsyncClientClass &aClient, const Firestore::Parent &parent, BatchGetDocumentOptions batchOptions)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `batchOptions` - The BatchGetDocumentOptions object which provided the member functions to construct the requst body.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

2. ## 🔹 void batchGet(AsyncClientClass &aClient, const Firestore::Parent &parent, BatchGetDocumentOptions batchOptions, AsyncResult &aResult)

 Gets multiple documents.
=======
- Boolean value, indicates the success of the operation.

2. ## 🔹 void batchGet(AsyncClientClass &aClient, const Firestore::Parent &parent, BatchGetDocumentOptions batchOptions, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
addDocument, mask, transaction, newTransaction and readTime functions.

addDocument used for adding the document path to read.
mask used for setting the mask fields to return. If not set, returns all fields. If the document has a field that is not present in this mask,
that field will not be returned in the response. Use comma (,) to separate between the field names.

The following function used for creating the union field consistency_selector and can be only one of the following field e.g.
transaction, newTransaction and readTime functions.

Then the following functions can't be mixed used.
- transaction used for reading the document in a transaction. A base64-encoded string.
- newTransaction used for creating the transaction.
- readTime used for setting the documents as they were at the given time. This may not be older than 270 seconds.
A timestamp in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits.
Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".


This function requires ServiceAuth authentication.

For more detail, see https://cloud.google.com/firestore/docs/reference/rest/v1/projects.databases.documents/batchGet


```cpp
void batchGet(AsyncClientClass &aClient, const Firestore::Parent &parent, BatchGetDocumentOptions batchOptions, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `batchOptions` - The BatchGetDocumentOptions object which provided the member functions to construct the requst body.
- `aResult` - The async result (AsyncResult).


3. ## 🔹 void batchGet(AsyncClientClass &aClient, const Firestore::Parent &parent, BatchGetDocumentOptions batchOptions, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
 Gets multiple documents.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
addDocument, mask, transaction, newTransaction and readTime functions.

addDocument used for adding the document path to read.
mask used for setting the mask fields to return. If not set, returns all fields. If the document has a field that is not present in this mask,
that field will not be returned in the response. Use comma (,) to separate between the field names.

The following function used for creating the union field consistency_selector and can be only one of the following field e.g.
transaction, newTransaction and readTime functions.

Then the following functions can't be mixed used.
- transaction used for reading the document in a transaction. A base64-encoded string.
- newTransaction used for creating the transaction.
- readTime used for setting the documents as they were at the given time. This may not be older than 270 seconds.
A timestamp in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits.
Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".


This function requires ServiceAuth authentication.

For more detail, see https://cloud.google.com/firestore/docs/reference/rest/v1/projects.databases.documents/batchGet


```cpp
void batchGet(AsyncClientClass &aClient, const Firestore::Parent &parent, BatchGetDocumentOptions batchOptions, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `batchOptions` - The BatchGetDocumentOptions object which provided the member functions to construct the requst body.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
4. ## 🔹 String batchWrite(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes)

Applies a batch of write operations.
=======
4. ## 🔹 bool batchWrite(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For the write object, see https://firebase.google.com/docs/firestore/reference/rest/v1/Write


This function requires ServiceAuth authentication.

For more description, see https://cloud.google.com/firestore/docs/reference/rest/v1/projects.databases.documents/batchWrite


```cpp
<<<<<<< Updated upstream
String batchWrite(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes)
=======
bool batchWrite(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `writes` - The writes to apply. This Writes object accepts the Write object and Labels (MapValue) associated with this batch write, in its constructor.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

5. ## 🔹 void batchWrite(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes, AsyncResult &aResult)

Applies a batch of write operations.
=======
- Boolean value, indicates the success of the operation.

5. ## 🔹 void batchWrite(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
For the write object, see https://firebase.google.com/docs/firestore/reference/rest/v1/Write

This function requires ServiceAuth authentication.

For more description, see https://cloud.google.com/firestore/docs/reference/rest/v1/projects.databases.documents/batchWrite


```cpp
void batchWrite(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `writes` - The writes to apply. This Writes object accepts the Write object and Labels (MapValue) associated with this batch write, in its constructor.
- `aResult` - The async result (AsyncResult).


6. ## 🔹 void batchWrite(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Applies a batch of write operations.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
For the write object, see https://firebase.google.com/docs/firestore/reference/rest/v1/Write

This function requires ServiceAuth authentication.

For more description, see https://cloud.google.com/firestore/docs/reference/rest/v1/projects.databases.documents/batchWrite


```cpp
void batchWrite(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `writes` - The writes to apply. This Writes object accepts the Write object and Labels (MapValue) associated with this batch write, in its constructor.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
7. ## 🔹 String beginTransaction(AsyncClientClass &aClient, const Firestore::Parent &parent, const TransactionOptions &transOptions)

Starts a new transaction.
=======
7. ## 🔹 bool beginTransaction(AsyncClientClass &aClient, const Firestore::Parent &parent, const TransactionOptions &transOptions)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

The TransactionOptions object can be initialized with two objects represent two modes
readOnly and readWrite.

Use readOnly option used when transaction can only be used for read operations.
Use readWrite option used when transaction can be used for both read and write operations.

The readOnly object (option) accepts the readTime (timestamp) in the constructor for reading the documents at the given time.
This must be a microsecond precision timestamp within the past one hour, or if Point-in-Time Recovery is enabled, can additionally be a whole minute timestamp within the past 7 days.

The readWrite object (option) accepts the retryTransaction (base64 encoded string) in the constructor represents a transaction that can be used to read and write documents.

See https://cloud.google.com/firestore/docs/reference/rest/v1/TransactionOptions for transaction options.


This function requires ServiceAuth authentication.

```cpp
<<<<<<< Updated upstream
String beginTransaction(AsyncClientClass &aClient, const Firestore::Parent &parent, const TransactionOptions &transOptions)
=======
bool beginTransaction(AsyncClientClass &aClient, const Firestore::Parent &parent, const TransactionOptions &transOptions)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `transOptions` - Options for creating a new transaction.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

8. ## 🔹 void beginTransaction(AsyncClientClass &aClient, const Firestore::Parent &parent, const TransactionOptions &transOptions, AsyncResult &aResult)

Starts a new transaction.
=======
- Boolean value, indicates the success of the operation.

8. ## 🔹 void beginTransaction(AsyncClientClass &aClient, const Firestore::Parent &parent, const TransactionOptions &transOptions, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

The TransactionOptions object can be initialized with two objects represent two modes
readOnly and readWrite.

Use readOnly option used when transaction can only be used for read operations.
Use readWrite option used when transaction can be used for both read and write operations.

The readOnly object (option) accepts the readTime (timestamp) in the constructor for reading the documents at the given time.
This must be a microsecond precision timestamp within the past one hour, or if Point-in-Time Recovery is enabled, can additionally be a whole minute timestamp within the past 7 days.

The readWrite object (option) accepts the retryTransaction (base64 encoded string) in the constructor represents a transaction that can be used to read and write documents.

See https://cloud.google.com/firestore/docs/reference/rest/v1/TransactionOptions for transaction options.


This function requires ServiceAuth authentication.

```cpp
void beginTransaction(AsyncClientClass &aClient, const Firestore::Parent &parent, const TransactionOptions &transOptions, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `transOptions` - Options for creating a new transaction.
- `aResult` - The async result (AsyncResult).


9. ## 🔹 void beginTransaction(AsyncClientClass &aClient, const Firestore::Parent &parent, const TransactionOptions &transOptions, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Starts a new transaction.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

The TransactionOptions object can be initialized with two objects represent two modes
readOnly and readWrite.

Use readOnly option used when transaction can only be used for read operations.
Use readWrite option used when transaction can be used for both read and write operations.

The readOnly object (option) accepts the readTime (timestamp) in the constructor for reading the documents at the given time.
This must be a microsecond precision timestamp within the past one hour, or if Point-in-Time Recovery is enabled, can additionally be a whole minute timestamp within the past 7 days.

The readWrite object (option) accepts the retryTransaction (base64 encoded string) in the constructor represents a transaction that can be used to read and write documents.

See https://cloud.google.com/firestore/docs/reference/rest/v1/TransactionOptions for transaction options.


This function requires ServiceAuth authentication.

```cpp
void beginTransaction(AsyncClientClass &aClient, const Firestore::Parent &parent, const TransactionOptions &transOptions, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `transOptions` - Options for creating a new transaction.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
10. ## 🔹 String commit(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes)

Commits a transaction, while optionally updating documents.
=======
10. ## 🔹 bool commit(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For the write object, see https://firebase.google.com/docs/firestore/reference/rest/v1/Write


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
<<<<<<< Updated upstream
String commit(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes)
=======
bool commit(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `writes` - The writes to apply.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

11. ## 🔹 void commit(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes, AsyncResult &aResult)

Commits a transaction, while optionally updating documents.
=======
- Boolean value, indicates the success of the operation.

11. ## 🔹 void commit(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For the write object, see https://firebase.google.com/docs/firestore/reference/rest/v1/Write

This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
void commit(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `writes` - The writes to apply.
- `aResult` - The async result (AsyncResult).


12. ## 🔹 void commit(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Commits a transaction, while optionally updating documents.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For the write object, see https://firebase.google.com/docs/firestore/reference/rest/v1/Write

This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
void commit(AsyncClientClass &aClient, const Firestore::Parent &parent, Writes &writes, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `writes` - The writes to apply. This Writes object accepts the Write object and transaction string (base64 encoded string) in its constructor.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
13. ## 🔹 String createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &documentPath, DocumentMask mask, Document<Values::Value> &document)

Create a document at the defined document path.
=======
13. ## 🔹 bool createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &documentPath, DocumentMask mask, Document<Values::Value> &document)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
See https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.documents#Document


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
<<<<<<< Updated upstream
String createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &documentPath, DocumentMask mask, Document<Values::Value> &document)
=======
bool createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &documentPath, DocumentMask mask, Document<Values::Value> &document)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to create in the collection.
- `mask` - The fields to return. If not set, returns all fields. Use comma (,) to separate between the field names.
- `document` - A Firestore document.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

14. ## 🔹 void createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &documentPath, DocumentMask mask, Document<Values::Value> &document, AsyncResult &aResult)

Create a document at the defined document path.
=======
- Boolean value, indicates the success of the operation.

14. ## 🔹 void createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &documentPath, DocumentMask mask, Document<Values::Value> &document, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
See https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.documents#Document

This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
void createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &documentPath, DocumentMask mask, Document<Values::Value> &document, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to create in the collection.
- `mask` - The fields to return. If not set, returns all fields. Use comma (,) to separate between the field names.
- `document` - A Firestore document.
- `aResult` - The async result (AsyncResult)


15. ## 🔹 void createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &documentPath, DocumentMask mask, Document<Values::Value> &document, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Create a document at the defined document path.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
See https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.documents#Document

This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
void createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &documentPath, DocumentMask mask, Document<Values::Value> &document, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to create in the collection.
- `mask` - The fields to return. If not set, returns all fields. Use comma (,) to separate between the field names.
- `document` - A Firestore document.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
16. ## 🔹 String createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &collectionId, const String &documentId, DocumentMask mask, Document<Values::Value> &document)

Create a document at the defined document path.
=======
16. ## 🔹 bool createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &collectionId, const String &documentId, DocumentMask mask, Document<Values::Value> &document)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
See https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.documents#Document


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
<<<<<<< Updated upstream
String createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &collectionId, const String &documentId, DocumentMask mask, Document<Values::Value> &document)
=======
bool createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &collectionId, const String &documentId, DocumentMask mask, Document<Values::Value> &document)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The relative path of document collection id to create the document.
- `documentId` - The document id of document to be created.
- `mask` - The fields to return. If not set, returns all fields. Use comma (,) to separate between the field names.
- `document` - A Firestore document.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

17. ## 🔹 void createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &collectionId, const String &documentId, DocumentMask mask, Document<Values::Value> &document, AsyncResult &aResult)

Create a document at the defined document path.
=======
- Boolean value, indicates the success of the operation.

17. ## 🔹 void createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &collectionId, const String &documentId, DocumentMask mask, Document<Values::Value> &document, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
See https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.documents#Document


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
void createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &collectionId, const String &documentId, DocumentMask mask, Document<Values::Value> &document, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The relative path of document collection id to create the document.
- `documentId` - The document id of document to be created.
- `mask` - The fields to return. If not set, returns all fields. Use comma (,) to separate between the field names.
- `document` - A Firestore document.
- `aResult` - The async result (AsyncResult)


18. ## 🔹 void createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &collectionId, const String &documentId, DocumentMask mask, Document<Values::Value> &document, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Create a document at the defined document path.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
See https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.documents#Document


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
void createDocument(AsyncClientClass &aClient, Firestore::Parent parent, const String &collectionId, const String &documentId, DocumentMask mask, Document<Values::Value> &document, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The relative path of document collection id to create the document.
- `documentId` - The document id of document to be created.
- `mask` - The fields to return. If not set, returns all fields. Use comma (,) to separate between the field names.
- `document` - A Firestore document.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
19. ## 🔹 String deleteDoc(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const Precondition &currentDocument)

Delete a document at the defined path.
=======
19. ## 🔹 bool deleteDoc(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const Precondition &currentDocument)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
The request will fail if this is set and not met by the target document.

There are the member functions exists and updateTime for creating the union field exists and updateTime respectively.

The exists option, when set to true, the target document must exist. When set to false, the target document must not exist.
The updateTime (timestamp) option, when set, the target document must exist and have been last updated at that time.
A timestamp is in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits.
Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
<<<<<<< Updated upstream
String deleteDoc(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const Precondition &currentDocument)
=======
bool deleteDoc(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const Precondition &currentDocument)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to delete.
- `currentDocument` - The Precondition object for an optional precondition on the document.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

20. ## 🔹 void deleteDoc(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const Precondition &currentDocument, AsyncResult &aResult)

Delete a document at the defined path.
=======
- Boolean value, indicates the success of the operation.

20. ## 🔹 void deleteDoc(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const Precondition &currentDocument, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
The request will fail if this is set and not met by the target document.

There are the member functions exists and updateTime for creating the union field exists and updateTime respectively.

The exists option, when set to true, the target document must exist. When set to false, the target document must not exist.
The updateTime (timestamp) option, when set, the target document must exist and have been last updated at that time.
A timestamp is in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits.
Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
void deleteDoc(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const Precondition &currentDocument, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to delete.
- `currentDocument` - The Precondition object for an optional precondition on the document.
- `aResult` - The async result (AsyncResult).


21. ## 🔹 void deleteDoc(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const Precondition &currentDocument, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Delete a document at the defined path.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
The request will fail if this is set and not met by the target document.

There are the member functions exists and updateTime for creating the union field exists and updateTime respectively.

The exists option, when set to true, the target document must exist. When set to false, the target document must not exist.
The updateTime (timestamp) option, when set, the target document must exist and have been last updated at that time.
A timestamp is in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits.
Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
void deleteDoc(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const Precondition &currentDocument, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to delete.
- `currentDocument` - The Precondition object for an optional precondition on the document.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
22. ## 🔹 String get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const GetDocumentOptions &options)

Get a document at the defined path.
=======
22. ## 🔹 bool get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const GetDocumentOptions &options)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
- mask is the fields to return. If not set, returns all fields. If the document has a field that is not present in this mask,
that field will not be returned in the response. Use comma (,) to separate between the field names.
- transaction is a base64-encoded string. If set, reads the document in a transaction.
- readTime is a timestamp in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits.
If set, reads the version of the document at the given time. This may not be older than 270 seconds.
Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
<<<<<<< Updated upstream
String get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const GetDocumentOptions &options)
=======
bool get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const GetDocumentOptions &options)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to get.
- `options` - The GetDocumentOptions object included mask, transaction and readTime in its constructor.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

23. ## 🔹 void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const GetDocumentOptions &options, AsyncResult &aResult)

Get a document at the defined path.
=======
- Boolean value, indicates the success of the operation.

23. ## 🔹 void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const GetDocumentOptions &options, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
- mask is the fields to return. If not set, returns all fields. If the document has a field that is not present in this mask,
that field will not be returned in the response. Use comma (,) to separate between the field names.
- transaction is a base64-encoded string. If set, reads the document in a transaction.
- readTime is a timestamp in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits.
If set, reads the version of the document at the given time. This may not be older than 270 seconds.
Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".

This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const GetDocumentOptions &options, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to get.
- `options` - The GetDocumentOptions object included mask, transaction and readTime in its constructor.
- `aResult` - The async result (AsyncResult).


24. ## 🔹 void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const GetDocumentOptions &options, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Get a document at the defined path.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
- mask is the fields to return. If not set, returns all fields. If the document has a field that is not present in this mask,
that field will not be returned in the response. Use comma (,) to separate between the field names.
- transaction is a base64-encoded string. If set, reads the document in a transaction.
- readTime is a timestamp in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits.
If set, reads the version of the document at the given time. This may not be older than 270 seconds.
Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".

This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, const GetDocumentOptions &options, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to get.
- `options` - The GetDocumentOptions object included mask, transaction and readTime in its constructor.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
25. ## 🔹 String list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, ListDocumentsOptions listDocsOptions)

List the documents in the defined documents collection.
=======
25. ## 🔹 bool list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, ListDocumentsOptions listDocsOptions)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
showMissing for creating the query string options pageSize, pageToken, orderBy, mask and showMissing respectively.
The option pageSize is for setting the maximum number of documents to return.
The option pageToken is the nextPageToken value returned from a previous List request, if any.
The option orderBy is the order to sort results by. For example: priority desc, name.
The option mask is for setting the fields to return. If not set, returns all fields.
If a document has a field that is not present in this mask, that field will not be returned in the response.
The option showMissing is for setting if the list should show missing documents.
A missing document is a document that does not exist but has sub-documents.


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
<<<<<<< Updated upstream
String list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, ListDocumentsOptions listDocsOptions)
=======
bool list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, ListDocumentsOptions listDocsOptions)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The relative path of document colection.
- `listDocsOptions` - The ListDocumentsOptions object that provides the member functions pageSize, pageToken, orderBy, mask and

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

26. ## 🔹 void list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, ListDocumentsOptions listDocsOptions, AsyncResult &aResult)

List the documents in the defined documents collection.
=======
- Boolean value, indicates the success of the operation.

26. ## 🔹 void list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, ListDocumentsOptions listDocsOptions, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
showMissing for creating the query string options pageSize, pageToken, orderBy, mask and showMissing respectively.
The option pageSize is for setting the maximum number of documents to return.
The option pageToken is the nextPageToken value returned from a previous List request, if any.
The option orderBy is the order to sort results by. For example: priority desc, name.
The option mask is for setting the fields to return. If not set, returns all fields.
If a document has a field that is not present in this mask, that field will not be returned in the response.
The option showMissing is for setting if the list should show missing documents.
A missing document is a document that does not exist but has sub-documents.


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
void list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, ListDocumentsOptions listDocsOptions, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The relative path of document colection.
- `listDocsOptions` - The ListDocumentsOptions object that provides the member functions pageSize, pageToken, orderBy, mask and
- `aResult` - The async result (AsyncResult).


27. ## 🔹 void list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, ListDocumentsOptions listDocsOptions, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
List the documents in the defined documents collection.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
showMissing for creating the query string options pageSize, pageToken, orderBy, mask and showMissing respectively.
The option pageSize is for setting the maximum number of documents to return.
The option pageToken is the nextPageToken value returned from a previous List request, if any.
The option orderBy is the order to sort results by. For example: priority desc, name.
The option mask is for setting the fields to return. If not set, returns all fields.
If a document has a field that is not present in this mask, that field will not be returned in the response.
The option showMissing is for setting if the list should show missing documents.
A missing document is a document that does not exist but has sub-documents.


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
void list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, ListDocumentsOptions listDocsOptions, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The relative path of document colection.
- `listDocsOptions` - The ListDocumentsOptions object that provides the member functions pageSize, pageToken, orderBy, mask and
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
28. ## 🔹 String listCollectionIds(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, ListCollectionIdsOptions listCollectionIdsOptions)

List the document collection ids in the defined document path.
=======
28. ## 🔹 bool listCollectionIds(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, ListCollectionIdsOptions listCollectionIdsOptions)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
for creating the query string options pageSize, pageToken and readTime respectively.
The option pageSize is for setting the  maximum number of results to return.
The option pageToken is the page token. Must be a value from ListCollectionIdsResponse.
The option readTime is the timestamp for reading the documents as they were at the given time.
This must be a microsecond precision timestamp within the past one hour, or if Point-in-Time Recovery is enabled,
can additionally be a whole minute timestamp within the past 7 days.


This function requires ServiceAuth authentication.


```cpp
<<<<<<< Updated upstream
String listCollectionIds(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, ListCollectionIdsOptions listCollectionIdsOptions)
=======
bool listCollectionIds(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, ListCollectionIdsOptions listCollectionIdsOptions)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to get its collections' id.
- `listCollectionIdsOptions` - The ListCollectionIdsOptions object that provides the member functions pageSize, pageToken and readTime

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

29. ## 🔹 void listCollectionIds(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, ListCollectionIdsOptions listCollectionIdsOptions, AsyncResult &aResult)

List the document collection ids in the defined document path.
=======
- Boolean value, indicates the success of the operation.

29. ## 🔹 void listCollectionIds(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, ListCollectionIdsOptions listCollectionIdsOptions, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
for creating the query string options pageSize, pageToken and readTime respectively.
The option pageSize is for setting the  maximum number of results to return.
The option pageToken is the page token. Must be a value from ListCollectionIdsResponse.
The option readTime is the timestamp for reading the documents as they were at the given time.
This must be a microsecond precision timestamp within the past one hour, or if Point-in-Time Recovery is enabled,
can additionally be a whole minute timestamp within the past 7 days.


This function requires ServiceAuth authentication.


```cpp
void listCollectionIds(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, ListCollectionIdsOptions listCollectionIdsOptions, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to get its collections' id.
- `listCollectionIdsOptions` - The ListCollectionIdsOptions object that provides the member functions pageSize, pageToken and readTime
- `aResult` - The async result (AsyncResult).


30. ## 🔹 void listCollectionIds(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, ListCollectionIdsOptions listCollectionIdsOptions, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
List the document collection ids in the defined document path.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
for creating the query string options pageSize, pageToken and readTime respectively.
The option pageSize is for setting the  maximum number of results to return.
The option pageToken is the page token. Must be a value from ListCollectionIdsResponse.
The option readTime is the timestamp for reading the documents as they were at the given time.
This must be a microsecond precision timestamp within the past one hour, or if Point-in-Time Recovery is enabled,
can additionally be a whole minute timestamp within the past 7 days.


This function requires ServiceAuth authentication.


```cpp
void listCollectionIds(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, ListCollectionIdsOptions listCollectionIdsOptions, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to get its collections' id.
- `listCollectionIdsOptions` - The ListCollectionIdsOptions object that provides the member functions pageSize, pageToken and readTime
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
31. ## 🔹 String patch(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, patchDocumentOptions patchOptions, Document<Values::Value> &document)

Patch or update a document at the defined path.
=======
31. ## 🔹 bool patch(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, patchDocumentOptions patchOptions, Document<Values::Value> &document)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

updateMask is he fields to update. If the document exists on the server and has fields not referenced in the mask,
they are left unchanged.
Fields referenced in the mask, but not present in the input document (content), are deleted from the document on the server.
Use comma (,) to separate between the field names.
mask is fields to return. If not set, returns all fields. If the document has a field that is not present in
this mask, that field will not be returned in the response. Use comma (,) to separate between the field names.
And currentDocument is an optional precondition on the document. The request will fail if this is set and not met by the target document.

When currentDocument as defined with true or false as constructor argument, the exists condition will be set.
When currentDocument as defined with string(Timestamp format) as constructor argument, the updateTime condition will be set.

When exists condition was set to true, the target document must exist. When set to false, the target document must not exist.
When updateTime was set, the target document must exist and have been last updated at that time.
A timestamp in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits.
Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".
 @param document A Firestore document.


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
<<<<<<< Updated upstream
String patch(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, patchDocumentOptions patchOptions, Document<Values::Value> &document)
=======
bool patch(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, patchDocumentOptions patchOptions, Document<Values::Value> &document)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to patch with the input document.
- `patchOptions` - The patchDocumentOptions object that included the DocumentMask (updateMask), DocumentMask (mask), Precondition (currentDocument) in its constructor.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

32. ## 🔹 void patch(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, patchDocumentOptions patchOptions, Document<Values::Value> &document, AsyncResult &aResult)

Patch or update a document at the defined path.
=======
- Boolean value, indicates the success of the operation.

32. ## 🔹 void patch(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, patchDocumentOptions patchOptions, Document<Values::Value> &document, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

updateMask is he fields to update. If the document exists on the server and has fields not referenced in the mask,
they are left unchanged.
Fields referenced in the mask, but not present in the input document (content), are deleted from the document on the server.
Use comma (,) to separate between the field names.
mask is fields to return. If not set, returns all fields. If the document has a field that is not present in
this mask, that field will not be returned in the response. Use comma (,) to separate between the field names.
And currentDocument is an optional precondition on the document. The request will fail if this is set and not met by the target document.

When currentDocument as defined with true or false as constructor argument, the exists condition will be set.
When currentDocument as defined with string(Timestamp format) as constructor argument, the updateTime condition will be set.

When exists condition was set to true, the target document must exist. When set to false, the target document must not exist.
When updateTime was set, the target document must exist and have been last updated at that time.
A timestamp in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits.
Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".
 @param document A Firestore document.


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
void patch(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, patchDocumentOptions patchOptions, Document<Values::Value> &document, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to patch with the input document.
- `patchOptions` - The patchDocumentOptions object that included the DocumentMask (updateMask), DocumentMask (mask), Precondition (currentDocument) in its constructor.
- `aResult` - The async result (AsyncResult).


33. ## 🔹 void patch(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, patchDocumentOptions patchOptions, Document<Values::Value> &document, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Patch or update a document at the defined path.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

updateMask is he fields to update. If the document exists on the server and has fields not referenced in the mask,
they are left unchanged.
Fields referenced in the mask, but not present in the input document (content), are deleted from the document on the server.
Use comma (,) to separate between the field names.
mask is fields to return. If not set, returns all fields. If the document has a field that is not present in
this mask, that field will not be returned in the response. Use comma (,) to separate between the field names.
And currentDocument is an optional precondition on the document. The request will fail if this is set and not met by the target document.

When currentDocument as defined with true or false as constructor argument, the exists condition will be set.
When currentDocument as defined with string(Timestamp format) as constructor argument, the updateTime condition will be set.

When exists condition was set to true, the target document must exist. When set to false, the target document must not exist.
When updateTime was set, the target document must exist and have been last updated at that time.
A timestamp in RFC3339 UTC "Zulu" format, with nanosecond resolution and up to nine fractional digits.
Examples: "2014-10-02T15:01:23Z" and "2014-10-02T15:01:23.045123456Z".
 @param document A Firestore document.


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.


```cpp
void patch(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, patchDocumentOptions patchOptions, Document<Values::Value> &document, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to patch with the input document.
- `patchOptions` - The patchDocumentOptions object that included the DocumentMask (updateMask), DocumentMask (mask), Precondition (currentDocument) in its constructor.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
34. ## 🔹 String rollback(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &transaction)

Rolls back a transaction.
=======
34. ## 🔹 bool rollback(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &transaction)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".


This function requires ServiceAuth authentication.

```cpp
<<<<<<< Updated upstream
String rollback(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &transaction)
=======
bool rollback(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &transaction)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `transaction` - Required. A base64-encoded string of the transaction to roll back.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

35. ## 🔹 void rollback(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &transaction, AsyncResult &aResult)

Rolls back a transaction.
=======
- Boolean value, indicates the success of the operation.

35. ## 🔹 void rollback(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &transaction, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".


This function requires ServiceAuth authentication.

```cpp
void rollback(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &transaction, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `transaction` - Required. A base64-encoded string of the transaction to roll back.
- `aResult` - The async result (AsyncResult).


36. ## 🔹 void rollback(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &transaction, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Rolls back a transaction.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
This function requires ServiceAuth authentication.

```cpp
void rollback(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &transaction, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `transaction` - Required. A base64-encoded string of the transaction to roll back.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
37. ## 🔹 String runQuery(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, QueryOptions queryOptions)

Runs a query.
=======
37. ## 🔹 bool runQuery(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, QueryOptions queryOptions)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
structuredQuery, transaction, newTransaction and readTime functions.

The following function used for creating the union field consistency_selector and can be only one of the following field e.g.
transaction, newTransaction and readTime  functions.

Then the following functions can't be mixed used.
- transaction used for running the query within an already active transaction. A base64-encoded string.
- newTransaction used for starting a new transaction and reads the documents. Defaults to a read-only transaction.
The new transaction ID will be returned as the first response in the stream.
- readTime used for reading the documents as they were at the given time.


This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.documents/runQuery


```cpp
<<<<<<< Updated upstream
String runQuery(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, QueryOptions queryOptions)
=======
bool runQuery(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, QueryOptions queryOptions)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to get.
- `queryOptions` - The QueryOptions object that provides the function to create the query (StructuredQuery) and consistency mode which included

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

38. ## 🔹 void runQuery(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, QueryOptions queryOptions, AsyncResult &aResult)

Runs a query.
=======
- Boolean value, indicates the success of the operation.

38. ## 🔹 void runQuery(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, QueryOptions queryOptions, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
structuredQuery, transaction, newTransaction and readTime functions.

The following function used for creating the union field consistency_selector and can be only one of the following field e.g.
transaction, newTransaction and readTime  functions.

Then the following functions can't be mixed used.
- transaction used for running the query within an already active transaction. A base64-encoded string.
- newTransaction used for starting a new transaction and reads the documents. Defaults to a read-only transaction.
The new transaction ID will be returned as the first response in the stream.
- readTime used for reading the documents as they were at the given time.

This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.documents/runQuery


```cpp
void runQuery(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, QueryOptions queryOptions, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to get.
- `queryOptions` - The QueryOptions object that provides the function to create the query (StructuredQuery) and consistency mode which included
- `aResult` - The async result (AsyncResult).


39. ## 🔹 void runQuery(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, QueryOptions queryOptions, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Runs a query.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
structuredQuery, transaction, newTransaction and readTime functions.

The following function used for creating the union field consistency_selector and can be only one of the following field e.g.
transaction, newTransaction and readTime  functions.

Then the following functions can't be mixed used.
- transaction used for running the query within an already active transaction. A base64-encoded string.
- newTransaction used for starting a new transaction and reads the documents. Defaults to a read-only transaction.
The new transaction ID will be returned as the first response in the stream.
- readTime used for reading the documents as they were at the given time.

This function requires ServiceAuth, CustomAuth, UserAuth, CustomToken or IDToken authentication.

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.documents/runQuery


```cpp
void runQuery(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &documentPath, QueryOptions queryOptions, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `documentPath` - The relative path of document to get.
- `queryOptions` - The QueryOptions object that provides the function to create the query (StructuredQuery) and consistency mode which included
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


# Databases

## Description

Google Cloud Firestore database Databases class


```cpp
class Databases
```

## Functions

<<<<<<< Updated upstream
1. ## 🔹 String exportDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions exportOptions)

Export the documents in the database to the Firebase Storage data bucket.
=======
1. ## 🔹 bool exportDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions exportOptions)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
The EximDocumentOptions constructor parameters.
- collectionIds is collection ids to export. Unspecified means all collections. Use comma (,)
  to separate between the collection ids.
- bucketID is the Firebase storage bucket ID in the project.
- storagePath is the path in the Firebase Storage data bucket to store the exported database.


This function requires ServiceAuth or AccessToken authentication.


```cpp
<<<<<<< Updated upstream
String exportDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions exportOptions)
=======
bool exportDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions exportOptions)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `exportOptions` - The EximDocumentOptions object included collectionIds, bucketID and storagePath in its constructor.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

2. ## 🔹 void exportDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions exportOptions, AsyncResult &aResult)

Export the documents in the database to the Firebase Storage data bucket.
=======
- Boolean value, indicates the success of the operation.

2. ## 🔹 void exportDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions exportOptions, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
The EximDocumentOptions constructor parameters.
- collectionIds is collection ids to export. Unspecified means all collections. Use comma (,)
  to separate between the collection ids.
- bucketID is the Firebase storage bucket ID in the project.
- storagePath is the path in the Firebase Storage data bucket to store the exported database.

This function requires ServiceAuth or AccessToken authentication.


```cpp
void exportDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions exportOptions, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `exportOptions` - The EximDocumentOptions object included collectionIds, bucketID and storagePath in its constructor.
- `aResult` - The async result (AsyncResult)


3. ## 🔹 void exportDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions exportOptions, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Export the documents in the database to the Firebase Storage data bucket.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
The EximDocumentOptions constructor parameters.
- collectionIds is collection ids to export. Unspecified means all collections. Use comma (,)
  to separate between the collection ids.
- bucketID is the Firebase storage bucket ID in the project.
- storagePath is the path in the Firebase Storage data bucket to store the exported database.

This function requires ServiceAuth or AccessToken authentication.


```cpp
void exportDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions exportOptions, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `exportOptions` - The EximDocumentOptions object included collectionIds, bucketID and storagePath in its constructor.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
4. ## 🔹 String importDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions importOptions)

Import the exported documents stored in the Firebase Storage data bucket.
=======
4. ## 🔹 bool importDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions importOptions)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
The EximDocumentOptions constructor parameters.
- collectionIds is collection ids to import. Unspecified means all collections included in the import.
  Use comma (,) to separate between the collection ids.
- bucketID is the Firebase storage bucket ID in the project.
- storagePath is the path in the Firebase Storage data bucket that stores the exported database.


This function requires ServiceAuth or AccessToken authentication.


```cpp
<<<<<<< Updated upstream
String importDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions importOptions)
=======
bool importDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions importOptions)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `importOptions` - The EximDocumentOptions object included collectionIds, bucketID and storagePath in its constructor.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

5. ## 🔹 void importDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions importOptions, AsyncResult &aResult)

Import the exported documents stored in the Firebase Storage data bucket.
=======
- Boolean value, indicates the success of the operation.

5. ## 🔹 void importDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions importOptions, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
The EximDocumentOptions constructor parameters.
- collectionIds is collection ids to import. Unspecified means all collections included in the import.
  Use comma (,) to separate between the collection ids.
- bucketID is the Firebase storage bucket ID in the project.
- storagePath is the path in the Firebase Storage data bucket that stores the exported database.

This function requires ServiceAuth or AccessToken authentication.


```cpp
void importDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions importOptions, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `importOptions` - The EximDocumentOptions object included collectionIds, bucketID and storagePath in its constructor.
- `aResult` - The async result (AsyncResult)


6. ## 🔹 void importDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions importOptions, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Import the exported documents stored in the Firebase Storage data bucket.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".
The EximDocumentOptions constructor parameters.
- collectionIds is collection ids to import. Unspecified means all collections included in the import.
  Use comma (,) to separate between the collection ids.
- bucketID is the Firebase storage bucket ID in the project.
- storagePath is the path in the Firebase Storage data bucket that stores the exported database.

This function requires ServiceAuth or AccessToken authentication.


```cpp
void importDocuments(AsyncClientClass &aClient, const Firestore::Parent &parent, EximDocumentOptions importOptions, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `importOptions` - The EximDocumentOptions object included collectionIds, bucketID and storagePath in its constructor.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
7. ## 🔹 String create(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database)

Create a database.
=======
7. ## 🔹 bool create(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database Id is the Id of database to create.

The Database information should be set via the following functions befor creation.
concurrencyMode, appEngineIntegrationMode, deleteProtectionState, pointInTimeRecoveryEnablement, databaseType, locationId and name.


This function requires ServiceAuth or AccessToken authentication.


```cpp
<<<<<<< Updated upstream
String create(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database)
=======
bool create(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `database` - The Firestore::Database object that hold the database information to create.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

8. ## 🔹 void create(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database, AsyncResult &aResult)

Create a database.
=======
- Boolean value, indicates the success of the operation.

8. ## 🔹 void create(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database Id is the Id of database to create.

The Database information should be set via the following functions befor creation.
concurrencyMode, appEngineIntegrationMode, deleteProtectionState, pointInTimeRecoveryEnablement, databaseType, locationId and name.

This function requires ServiceAuth or AccessToken authentication.


```cpp
void create(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `database` - The Firestore::Database object that hold the database information to create.
- `aResult` - The async result (AsyncResult).


9. ## 🔹 void create(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Create a database.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database Id is the Id of database to create.

The Database information should be set via the following functions befor creation.
concurrencyMode, appEngineIntegrationMode, deleteProtectionState, pointInTimeRecoveryEnablement, databaseType, locationId and name.

This function requires ServiceAuth or AccessToken authentication.


```cpp
void create(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `database` - The Firestore::Database object that hold the database information to create.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
10. ## 🔹 String deleteDatabase(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &etag)

Deletes a database.
=======
10. ## 🔹 bool deleteDatabase(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &etag)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database Id is the Id of database to delete.
If an etag is provided and does not match the current etag of the database, deletion will be blocked and a FAILED_PRECONDITION error will be returned.


This function requires ServiceAuth or AccessToken authentication.


```cpp
<<<<<<< Updated upstream
String deleteDatabase(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &etag)
=======
bool deleteDatabase(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &etag)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `etag` - The current etag of the Database.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

11. ## 🔹 void deleteDatabase(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &etag, AsyncResult &aResult)

Deletes a database.
=======
- Boolean value, indicates the success of the operation.

11. ## 🔹 void deleteDatabase(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &etag, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database Id is the Id of database to delete.
If an etag is provided and does not match the current etag of the database, deletion will be blocked and a FAILED_PRECONDITION error will be returned.

This function requires ServiceAuth or AccessToken authentication.


```cpp
void deleteDatabase(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &etag, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `etag` - The current etag of the Database.
- `aResult` - The async result (AsyncResult).


12. ## 🔹 void deleteDatabase(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &etag, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Deletes a database.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database Id is the Id of database to delete.
If an etag is provided and does not match the current etag of the database, deletion will be blocked and a FAILED_PRECONDITION error will be returned.

This function requires ServiceAuth or AccessToken authentication.


```cpp
void deleteDatabase(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &etag, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `etag` - The current etag of the Database.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
13. ## 🔹 String get(AsyncClientClass &aClient, const Firestore::Parent &parent)

Gets information about a database.
=======
13. ## 🔹 bool get(AsyncClientClass &aClient, const Firestore::Parent &parent)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database Id is the Id of database to get the infomation.


This function requires ServiceAuth or AccessToken authentication.


```cpp
<<<<<<< Updated upstream
String get(AsyncClientClass &aClient, const Firestore::Parent &parent)
=======
bool get(AsyncClientClass &aClient, const Firestore::Parent &parent)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

14. ## 🔹 void get(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResult &aResult)

Gets information about a database.
=======
- Boolean value, indicates the success of the operation.

14. ## 🔹 void get(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database Id is the Id of database to get the infomation.

This function requires ServiceAuth or AccessToken authentication.


```cpp
void get(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `aResult` - The async result (AsyncResult).


15. ## 🔹 void get(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Gets information about a database.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database Id is the Id of database to get the infomation.

This function requires ServiceAuth or AccessToken authentication.


```cpp
void get(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
16. ## 🔹 String list(AsyncClientClass &aClient, const Firestore::Parent &parent)

List all the databases in the project.
=======
16. ## 🔹 bool list(AsyncClientClass &aClient, const Firestore::Parent &parent)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
Leave the Firestore database Id to be empty for this case.


This function requires ServiceAuth or AccessToken authentication.


```cpp
<<<<<<< Updated upstream
String list(AsyncClientClass &aClient, const Firestore::Parent &parent)
=======
bool list(AsyncClientClass &aClient, const Firestore::Parent &parent)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

17. ## 🔹 void list(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResult &aResult)

List all the databases in the project.
=======
- Boolean value, indicates the success of the operation.

17. ## 🔹 void list(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
Leave the Firestore database Id to be empty for this case.

This function requires ServiceAuth or AccessToken authentication.


```cpp
void list(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `aResult` - The async result (AsyncResult).


18. ## 🔹 void list(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
List all the databases in the project.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
Leave the Firestore database Id to be empty for this case.

This function requires ServiceAuth or AccessToken authentication.


```cpp
void list(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
19. ## 🔹 String patch(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database, const String &updateMask)

Updates a database.
=======
19. ## 🔹 bool patch(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database, const String &updateMask)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database Id is the Id of database to update.
Example: "user.displayName,photo"

The Database information should be set via the following functions befor creation.
concurrencyMode, appEngineIntegrationMode, deleteProtectionState, pointInTimeRecoveryEnablement, databaseType, locationId and name.


This function requires ServiceAuth or AccessToken authentication.


```cpp
<<<<<<< Updated upstream
String patch(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database, const String &updateMask)
=======
bool patch(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database, const String &updateMask)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `database` - The Firestore::Database object that hold the database information to update.
- `updateMask` - The list of fields to be updated. This is a comma-separated list of fully qualified names of fields.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

20. ## 🔹 void patch(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database, const String &updateMask, AsyncResult &aResult)

Updates a database.
=======
- Boolean value, indicates the success of the operation.

20. ## 🔹 void patch(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database, const String &updateMask, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database Id is the Id of database to update.
Example: "user.displayName,photo"

The Database information should be set via the following functions befor creation.
concurrencyMode, appEngineIntegrationMode, deleteProtectionState, pointInTimeRecoveryEnablement, databaseType, locationId and name.

This function requires ServiceAuth or AccessToken authentication.


```cpp
void patch(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database, const String &updateMask, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `database` - The Firestore::Database object that hold the database information to update.
- `updateMask` - The list of fields to be updated. This is a comma-separated list of fully qualified names of fields.
- `aResult` - The async result (AsyncResult).


21. ## 🔹 void patch(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database, const String &updateMask, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Updates a database.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database Id is the Id of database to update.
Example: "user.displayName,photo"

The Database information should be set via the following functions befor creation.
concurrencyMode, appEngineIntegrationMode, deleteProtectionState, pointInTimeRecoveryEnablement, databaseType, locationId and name.

This function requires ServiceAuth or AccessToken authentication.


```cpp
void patch(AsyncClientClass &aClient, const Firestore::Parent &parent, Database &database, const String &updateMask, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `database` - The Firestore::Database object that hold the database information to update.
- `updateMask` - The list of fields to be updated. This is a comma-separated list of fully qualified names of fields.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
22. ## 🔹 String create(AsyncClientClass &aClient, const Firestore::Parent &parent, DatabaseIndex::Index index)

Creates the specified index.
=======
22. ## 🔹 bool create(AsyncClientClass &aClient, const Firestore::Parent &parent, DatabaseIndex::Index index)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".


For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.indexes/create

This function requires ServiceAuth authentication.


```cpp
<<<<<<< Updated upstream
String create(AsyncClientClass &aClient, const Firestore::Parent &parent, DatabaseIndex::Index index)
=======
bool create(AsyncClientClass &aClient, const Firestore::Parent &parent, DatabaseIndex::Index index)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `index` - The Index object that provides an index definition.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

23. ## 🔹 void create(AsyncClientClass &aClient, const Firestore::Parent &parent, DatabaseIndex::Index index, AsyncResult &aResult)

Creates the specified index.
=======
- Boolean value, indicates the success of the operation.

23. ## 🔹 void create(AsyncClientClass &aClient, const Firestore::Parent &parent, DatabaseIndex::Index index, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.indexes/create

This function requires ServiceAuth authentication.


```cpp
void create(AsyncClientClass &aClient, const Firestore::Parent &parent, DatabaseIndex::Index index, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `index` - The Index object that provides an index definition.
- `aResult` - The async result (AsyncResult).


24. ## 🔹 void create(AsyncClientClass &aClient, const Firestore::Parent &parent, DatabaseIndex::Index index, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Creates the specified index.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.indexes/create

This function requires ServiceAuth authentication.


```cpp
void create(AsyncClientClass &aClient, const Firestore::Parent &parent, DatabaseIndex::Index index, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `index` - The Index object that provides an index definition.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
25. ## 🔹 String deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId)

Deletes an index.
=======
25. ## 🔹 bool deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".


For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.indexes/delete

This function requires ServiceAuth authentication.


```cpp
<<<<<<< Updated upstream
String deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId)
=======
bool deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `indexId` - The index to delete.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

26. ## 🔹 void deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId, AsyncResult &aResult)

Deletes an index.
=======
- Boolean value, indicates the success of the operation.

26. ## 🔹 void deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.indexes/delete

This function requires ServiceAuth authentication.


```cpp
void deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `indexId` - The index to delete.
- `aResult` - The async result (AsyncResult).


27. ## 🔹 void deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Deletes an index.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.indexes/delete

This function requires ServiceAuth authentication.


```cpp
void deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `indexId` - The index to delete.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
28. ## 🔹 String get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId)

Gets an index.
=======
28. ## 🔹 bool get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".


For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.indexes/get

This function requires ServiceAuth authentication.


```cpp
<<<<<<< Updated upstream
String get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId)
=======
bool get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `indexId` - The index to get.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

29. ## 🔹 void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId, AsyncResult &aResult)

Gets an index.
=======
- Boolean value, indicates the success of the operation.

29. ## 🔹 void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.indexes/get

This function requires ServiceAuth authentication.


```cpp
void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `indexId` - The index to get.
- `aResult` - The async result (AsyncResult).


30. ## 🔹 void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Gets an index.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.indexes/get

This function requires ServiceAuth authentication.


```cpp
void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &indexId, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `indexId` - The index to get.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
31. ## 🔹 String list(AsyncClientClass &aClient, const Firestore::Parent &parent)

Lists the indexes.
=======
31. ## 🔹 bool list(AsyncClientClass &aClient, const Firestore::Parent &parent)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".


For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.indexes/list

This function requires ServiceAuth authentication.


```cpp
<<<<<<< Updated upstream
String list(AsyncClientClass &aClient, const Firestore::Parent &parent)
=======
bool list(AsyncClientClass &aClient, const Firestore::Parent &parent)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

32. ## 🔹 void list(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResult &aResult)

Lists the indexes.
=======
- Boolean value, indicates the success of the operation.

32. ## 🔹 void list(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.indexes/list

This function requires ServiceAuth authentication.


```cpp
void list(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `indexId` - The index to get.
- `aResult` - The async result (AsyncResult).


33. ## 🔹 void list(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Lists the indexes.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1beta1/projects.databases.indexes/list

This function requires ServiceAuth authentication.


```cpp
void list(AsyncClientClass &aClient, const Firestore::Parent &parent, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


# CollectionGroups

## Description

Google Cloud Firestore database CollectionGroups class


```cpp
class CollectionGroups
```


<<<<<<< Updated upstream
1. ## 🔹 String create(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, CollectionGroupsIndex::Index index)

Creates a composite index.
=======
1. ## 🔹 bool create(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, CollectionGroupsIndex::Index index)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.collectionGroups.indexes/create

This function requires ServiceAuth authentication.


```cpp
<<<<<<< Updated upstream
String create(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, CollectionGroupsIndex::Index index)
=======
bool create(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, CollectionGroupsIndex::Index index)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The collection Id.
- `index` - The Cloud Firestore indexes enable simple and complex queries against documents in a database.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

2. ## 🔹 void create(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, CollectionGroupsIndex::Index index, AsyncResult &aResult)

Creates a composite index.
=======
- Boolean value, indicates the success of the operation.

2. ## 🔹 void create(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, CollectionGroupsIndex::Index index, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.collectionGroups.indexes/create

This function requires ServiceAuth authentication.


```cpp
void create(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, CollectionGroupsIndex::Index index, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The collection Id.
- `index` - The Cloud Firestore indexes enable simple and complex queries against documents in a database.
- `aResult` - The async result (AsyncResult).


3. ## 🔹 void create(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, CollectionGroupsIndex::Index index, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Creates a composite index.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.collectionGroups.indexes/create

This function requires ServiceAuth authentication.


```cpp
void create(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, CollectionGroupsIndex::Index index, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The collection Id.
- `index` - The Cloud Firestore indexes enable simple and complex queries against documents in a database.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
4. ## 🔹 String deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId)

Deletes a composite index.
=======
4. ## 🔹 bool deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".


For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.collectionGroups.indexes/delete

This function requires ServiceAuth authentication.


```cpp
<<<<<<< Updated upstream
String deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId)
=======
bool deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The collection Id.
- `indexId` - The index to delete.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

5. ## 🔹 void deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId, AsyncResult &aResult)

Deletes a composite index.
=======
- Boolean value, indicates the success of the operation.

5. ## 🔹 void deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.collectionGroups.indexes/delete

This function requires ServiceAuth authentication.


```cpp
void deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The collection Id.
- `indexId` - The index to delete.
- `aResult` - The async result (AsyncResult).


6. ## 🔹 void deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Deletes a composite index.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.collectionGroups.indexes/delete

This function requires ServiceAuth authentication.


```cpp
void deleteIndex(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The collection Id.
- `indexId` - The index to delete.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
7. ## 🔹 String get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId)

Gets a composite index.
=======
7. ## 🔹 bool get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.collectionGroups.indexes/get

This function requires ServiceAuth authentication.


```cpp
<<<<<<< Updated upstream
String get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId)
=======
bool get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The collection Id.
- `indexId` - The index to get.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

8. ## 🔹 void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId, AsyncResult &aResult)

Gets a composite index.
=======
- Boolean value, indicates the success of the operation.

8. ## 🔹 void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.collectionGroups.indexes/get

This function requires ServiceAuth authentication.


```cpp
void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The collection Id.
- `indexId` - The index to get.
- `aResult` - The async result (AsyncResult).


9. ## 🔹 void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Gets a composite index.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.collectionGroups.indexes/get

This function requires ServiceAuth authentication.


```cpp
void get(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, const String &indexId, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `collectionId` - The collection Id.
- `indexId` - The index to get.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).


<<<<<<< Updated upstream
10. ## 🔹 String list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId)

Lists composite indexes.
=======
10. ## 🔹 bool list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".


For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.collectionGroups.indexes/list

This function requires ServiceAuth authentication.


```cpp
<<<<<<< Updated upstream
String list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId)
=======
bool list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId)
>>>>>>> Stashed changes
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.

**Returns:**

<<<<<<< Updated upstream
- `String` - The response payload.

11. ## 🔹 void list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, AsyncResult &aResult)

Lists composite indexes.
=======
- Boolean value, indicates the success of the operation.

11. ## 🔹 void list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, AsyncResult &aResult)

>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.collectionGroups.indexes/list

This function requires ServiceAuth authentication.


```cpp
void list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, AsyncResult &aResult)
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `indexId` - The index to get.
- `aResult` - The async result (AsyncResult).


12. ## 🔹 void list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, AsyncResultCallback cb, const String &uid = "")

<<<<<<< Updated upstream
Lists composite indexes.
=======
>>>>>>> Stashed changes

The Firebase project Id should be only the name without the firebaseio.com.
The Firestore database id should be (default) or empty "".

For more description, see https://firebase.google.com/docs/firestore/reference/rest/v1/projects.databases.collectionGroups.indexes/list

This function requires ServiceAuth authentication.


```cpp
void list(AsyncClientClass &aClient, const Firestore::Parent &parent, const String &collectionId, AsyncResultCallback cb, const String &uid = "")
```

**Params:**

- `aClient` - The async client.
- `parent` - The Firestore::Parent object included project Id and database Id in its constructor.
- `cb` - The async result callback (AsyncResultCallback).
- `uid` - The user specified UID of async result (optional).

