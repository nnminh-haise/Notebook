# MongoDB handbook

---

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [MongoDB handbook](#mongodb-handbook)
  - [Creating new database](#creating-new-database)
  - [Create new collection](#create-new-collection)
  - [Insert function](#insert-function)
    - [Inserting one document at one time](#inserting-one-document-at-one-time)
    - [Inserting many documents at one time](#inserting-many-documents-at-one-time)
  - [Listing all documents inside a collection](#listing-all-documents-inside-a-collection)
  - [Data types](#data-types)
  - [Sorting and Limiting](#sorting-and-limiting)
    - [Sorting](#sorting)
    - [Limiting](#limiting)

<!-- /code_chunk_output -->

---

## Creating new database

To create new database:

```
use [<database name>]
```

This command also can be used to access to an existing database

Example: Create new database called: "itmc-web-chat"

```sh
use "itmc-web-chat"
```

If the database "itmc-web-chat" does not exist, it will create a new one. Otherwise, it will access to the existing one

## Create new collection

Creating new collection inside a database is quite similar to creating new table inside a database in the relational database system.

To create new collection in a database:

```
db.createCollection([<collection name>])
```

Example: Create new "users" collection(table) in a database

```sh
db.createCollection("users")
```

Example: Create new "group_chats" collection(table) in a database

```sh
db.createCollection("group_chats")
```

Example: Create new "user_to_group" collection(table) in a database

```sh
db.createCollection("user_to_group")
```

Example: Create new "chat_history" collection(table) in a database

```sh
db.createCollection("chat_history")
```

Example: Create new "chat_ban" collection(table) in a database

```sh
db.createCollection("chat_ban")
```

## Insert function

### Inserting one document at one time

To insert a new document (kind of similar to a row in relational database):

```
db.[<table name>].insertOne([<key - value pairs>])
```

The `[<key - value pairs>]` is kind of similar to a json object.

Example: Create a new document inside the collection "users".

- Inserting document:

```json
{
  "email": "nnminh.sam.1803@gmail.com",
  "password": "12345678",
  "first_name": "Nhat Minh",
  "last_name": "Nguyen",
  "dob": "2003-03-18",
  "gender": "male",
  "create_at": "2024-03-12",
  "delete_at": null
}
```

- Inserting command:

```sh
db.users.insertOne({
    email: "aaaaaaaa@gmail.com",
    password: "aaaaaaaa",
    first_name: "Van A",
    last_name: "Nguyen",
    dob: "2000-01-01",
    gender: "male",
    create_at: "2024-03-12",
    delete_at: null
})
```

### Inserting many documents at one time

To insert many documents at one time, use this function:

```
db.[<collection name>].insertMany([<an array of key - value pairs>])
```

Example: inserting three documents into "users" collection:

- Inserting documents:

```json
[
  {
    "email": "bbbbbbbb@gmail.com",
    "password": "bbbbbbbb",
    "first_name": "Van B",
    "last_name": "Nguyen",
    "dob": "2000-01-01",
    "gender": "male",
    "create_at": "2024-03-12",
    "delete_at": null
  },
  {
    "email": "cccccccc@gmail.com",
    "password": "cccccccc",
    "first_name": "Van C",
    "last_name": "Nguyen",
    "dob": "2000-01-01",
    "gender": "male",
    "create_at": "2024-03-12",
    "delete_at": null
  },
  {
    "email": "dddddddd@gmail.com",
    "password": "dddddddd",
    "first_name": "Van D",
    "last_name": "Nguyen",
    "dob": "2000-01-01",
    "gender": "male",
    "create_at": "2024-03-12",
    "delete_at": null
  }
]
```

- Inserting command:

```sh
db.users.insertMany([
  {
    "email": "bbbbbbbb@gmail.com",
    "password": "bbbbbbbb",
    "first_name": "Van B",
    "last_name": "Nguyen",
    "dob": "2000-01-01",
    "gender": "male",
    "create_at": "2024-03-12",
    "delete_at": null
  },
  {
    "email": "cccccccc@gmail.com",
    "password": "cccccccc",
    "first_name": "Van C",
    "last_name": "Nguyen",
    "dob": "2000-01-01",
    "gender": "male",
    "create_at": "2024-03-12",
    "delete_at": null
  },
  {
    "email": "dddddddd@gmail.com",
    "password": "dddddddd",
    "first_name": "Van D",
    "last_name": "Nguyen",
    "dob": "2000-01-01",
    "gender": "male",
    "create_at": "2024-03-12",
    "delete_at": null
  }
])
```

## Listing all documents inside a collection

To list all documents inside a collection:

```
db.[<collection name>].find()
```

Example: finding all the documents inside the "users" collection

```sh
db.users.find()
```

## Data types

Here are some data type representing inside a document:

```json
{
  "email": "eeeeeeee@gmail.com", // String type
  "password": "eeeeeeee", // String type
  "first_name": "Van E", // String type
  "last_name": "Nguyen", // String type
  "dob": "2000-01-01", // String type
  "gender": "male", // String type
  "create_at": "2024-03-12", // String type
  "delete_at": null
}
```

The key `dob`, `create_at`, `delete_at` shoule be a date object, to change to a date object, we can use the `new Date()` function:

```json
{
  "email": "eeeeeeee@gmail.com", // String type
  "password": "eeeeeeee", // String type
  "first_name": "Van E", // String type
  "last_name": "Nguyen", // String type
  "dob": new Date("2000-01-01"), // Date type
  "gender": "male", // String type
  "create_at": new Date("2024-03-12"), // Date type
  "delete_at": null
}
```

Example: inserting the above document into the "users" collection

```sh
db.users.insertOne({
  "email": "eeeeeeee@gmail.com",
  "password": "eeeeeeee",
  "first_name": "Van E",
  "last_name": "Nguyen",
  "dob": new Date("2000-01-01"),
  "gender": "male",
  "create_at": new Date("2024-03-12"),
  "delete_at": null
})
```

Since inside the above examples, we've used string type for `dob`, `create_at` and `delete_at`, after we run the above command, the type of them will be mixed type.

There are also the array type and object type such as:

```json
{
  "subjects": ["Math", "Physic", "English"],
  "Teacher": {
    "name": "Joe",
    "age": 48
  }
}
```

## Sorting and Limiting

### Sorting

To select and sort the documents we can use:

```
db.[<collection name>].find().sort({[<sort by field:sort direction>]})
```

Sort direction is either 1 or -1 which stands for ASC or DESC

Example: sorting all document inside "user" collection by `first_name` in DESC

```sh
db.users.find().sort({first_name:-1})
```

### Limiting

We can limiting the number of return document by using the `limit()` method:

```
db.[<collection name>].find().limit([<number of return document>])
```

Example: select first three documents sorted by `first_name` in DESC in "users" collection

```sh
db.users.find().sort({first_name:-1}).limit(3)
```
