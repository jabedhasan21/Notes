# MongoDB
+ MongoDB is an open-source document database and leading NoSQL database. MongoDB is written in C++.

+ `Collection` is a group of MongoDB documents. It is the equivalent of an RDBMS `table`.

+ A document is a set of key-value pairs. Documents have dynamic schema. Dynamic schema means that documents in the same collection do not need to have the same set of fields or structure, and common fields in a collection's documents may hold different types of data.

+ `_id` is a 12 `bytes` hexadecimal number( 96 Bit )
  - first 4 bytes for the current timestamp
  - next 3 bytes for machine id
  - next 2 bytes for process id of MongoDB server
  - remaining 3 bytes are simple incremental VALUE.

## Why Use MongoDB?
+ Index on any attribute
+ Replication and high availability
+ Auto-sharding
+ Rich queries
+ Fast in-place updates

## Where to Use MongoDB?
+ Big Data
+

## Indexing
Indexes are special data structures, that store a small portion of the data set in an easy-to-traverse form. The index stores the value of a specific field or set of fields, ordered by the value of the field as specified in the index.

## Aggregation
+ Aggregation operations group values from multiple documents together


## Replication
Replication is the process of synchronizing data across multiple servers.

## Sharding
Sharding is the process of storing data records across multiple machines.

# Utils
+ `mongodump --collection <collection-name> --db <db-name> --username mongodevdb --password YourSecretPwd`


+ `mongodump --host <IP> --port <port-number>  --collection <collection-name> --db <db-name> --out <output-directory-path>`


+ `mongorestore --collection <collection-name> --db <db-name> path-to/file.bson`

# Install
+ [ubuntu 16.04](https://www.digitalocean.com/community/tutorials/how-to-install-mongodb-on-ubuntu-16-04)

# References
+ [mongodb-auth](https://ianlondon.github.io/blog/mongodb-auth/)
