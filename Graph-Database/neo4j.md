+ Default login is username `'neo4j'` and password `'neo4j'`

## Explore Sample Datasets
Explore two sample datasets built into the Neo4j Browser using the following commands:
+ `:help`
+ `:play movie graph`
+ `:play northwind graph`
+ `:play cypher`

### Creating Nodes
+ `CREATE (node_name);` Semicolon (;) is optional.

+ `CREATE (Shakib)`

+ Create multiple nodes: `CREATE (node1),(node2)`

+ `CREATE (Shakib), (Tamim)`

### Creating a Node with a Label
+ `CREATE (node:label)`

+ `CREATE (Shakib:player)`

+ Creating a Node with Multiple Labels: `CREATE (node:label1:label2:. . . . labeln)`

+ `CREATE (Shakib:person:player)`

### Create Node with Properties
+ `CREATE (node:label { key1: value, key2: value, . . . . . . . . .  })`

+ `CREATE (Shakib:player{name: "Shakib Al Hasan", YOB: 1985, POB: "Jessore"})`

### Returning the Created Node
+ `CREATE (Node:Label{properties. . . . }) RETURN Node`

+ `CREATE (Shakib:player{name: "Shakib Al Hasan", YOB: 1985, POB: "Jessore"}) RETURN Shakib;`

### Creating a Relationship
+ `CREATE (node1)-[:RelationshipType]->(node2)`

+ `CREATE (Mustafizur:player{name: "Mustafizur Rahman", YOB: 1995, POB: "Satkhira"}) RETURN Mustafizur;`

+ `CREATE (Ban:Country {name: "Bangladesh"}) RETURN Ban;`

+ `CREATE (Mustafizur)-[r:BATSMAN_OF]->(Ban)`

+ `RETURN Mustafizur, Ban`

### Creating a Relationship Between the Existing Nodes
+ `MATCH (a:LabeofNode1), (b:LabeofNode2) WHERE a.name = "nameofnode1" AND b.name = " nameofnode2" CREATE (a)-[: Relation]->(b) RETURN a,b `

+ `MATCH (a:player), (b:Country) WHERE a.name = "Shakib Al Hasan" AND b.name = "Bangladesh" CREATE (a)-[r:BATSMAN_OF]->(b) RETURN a,b`

+ List all bangladeshi players:`MATCH (a:player), (b:Country) WHERE  b.name = "Bangladesh" RETURN a,b;`

### Creating a Relationship with Label and Properties
+ `CREATE (node1)-[label:Rel_Type {key1:value1, key2:value2, . . . n}]-> (node2)`

+ `MATCH (a:player), (b:Country) WHERE a.name = "Shakib Al Hasan" AND b.name = "Bangladesh" CREATE (a)-[r:BATSMAN_OF {Matches:5, Avg:90.75}]->(b) RETURN a,b`

### Creating a Complete Path
+ a path is formed using continuous relationships.

+ `CREATE p = (Node1 {properties})-[:Relationship_Type]-> (Node2 {properties})[:Relationship_Type]->(Node3 {properties}) RETURN p`

+ `CREATE p = (Shakib {name: "Shakib Al Hasan"})-[:TOPSCORRER_OF]-> (Ban {name: "Bangladesh"})-[:WINNER_OF]->(CT2013 {name: "Champions Trophy 2013"}) RETURN p`

### Merge Command
+ MERGE command is a combination of CREATE command and MATCH command.

+ Neo4j CQL MERGE command searches for a given pattern in the graph. If it exists, then it returns the results.

+ If it does NOT exist in the graph, then it creates a new node/relationship and returns the results.

+ `MERGE (node: label {properties . . . . . . . })`

+ `MERGE (Masrafi:player) RETURN Masrafi`

+ `MERGE (CT2013:Tournament{name: "ICC Champions Trophy 2013"}) RETURN CT2013, labels(CT2013)`

### Merging a Node with Properties
+ You can also merge a node with a set of properties. If you do so, Neo4j searches for an equal match for the specified node, including the properties. If it doesn’t find any, it creates one.

+ `MERGE (node:label {key1:value, key2:value,key3:value . . . . . . . . })`

+ `MERGE (Masrafi:player {name: "Mashrafe Mortaza", YOB: 1988, POB: "Narial"}) RETURN Masrafi`


### OnCreate and OnMatch
+ Whenever, we execute a merge query, a node is either matched or created. Using on create and on match, you can set properties for indicating whether the node is created or matched.

+ `MERGE (node:label {properties . . . . . . . . . ..}) ON CREATE SET property.isCreated ="true" ON MATCH SET property.isFound ="true"`

+ `MERGE (Masrafi:player {name: "Mashrafe Mortaza", YOB: 1988, POB: "Narial"}) ON CREATE SET Masrafi.isCreated = "true" ON MATCH SET Masrafi.isFound = "true" RETURN Masrafi`

### Merge a Relationship
+ Just like nodes, you can also merge the relationships using the MERGE clause.

+ `MATCH (a:Country), (b:Tournament) WHERE a.name = "Bangladesh" AND b.name = "ICC Champions Trophy 2013" MERGE (a)-[r:WINNERS_OF]->(b)RETURN a, b`

### Set Clause
+ Using Set clause, you can add `new properties` to an existing Node or Relationship, and also add or `update` existing Properties values.

+ `MATCH (node:label{properties . . . . . . . . . . . .. . }) SET node.property = value RETURN node`

+ `MATCH (Shakib:player{name: "Shakib Al Hasan", YOB: 1985, POB: "Jessore"}) SET Shakib.highestscore = 137 RETURN Shakib`

#### Removing a Property
+ You can remove an existing property by passing `NULL` as value to it.

+ `MATCH (node:label {properties}) SET node.property = NULL RETURN node `

+ `MATCH (Shakib:player{name: "Shakib Al Hasan", YOB: 1985, POB: "Jessore"}) SET Shakib.POB = NULL RETURN Shakib`

#### Setting Multiple Properties
+ In the same way, you can create multiple properties in a node using the Set clause. To do so, you need to specify these key value pairs with `commas`.

+ `MATCH (node:label {properties}) SET node.property1 = value, node.property2 = value RETURN node`

+ `MATCH (Shakib:player {name: "Shakib Al Hasan", YOB: 1985}) SET Shakib.POB = "Jessore", Shakib.HS = 90 RETURN Shakib;`

#### Setting a Label on a Node
+ You can set a label to an existing node using the SET clause.

+ `MATCH (n {properties . . . . . . . }) SET n :label RETURN n`

+ `CREATE (Subbir {name: "Subbir Rahaman", YOB: 1982, POB: "Rajshahi"})`

+ `MATCH (Subbir {name: "Subbir Rahaman", YOB: 1982, POB: "Rajshahi"}) SET Subbir: player RETURN Subbir`

#### Setting Multiple Labels on a Node
+ You can set multiple labels to an existing node using the SET clause. Here you need to specify the labels by separating them with colons `:`.

+ `MATCH (n {properties . . . . . . . }) SET n :label1:label2 RETURN n`

+ `CREATE (Mahmudullah {name: "Mohammad Mahmudullah Riyad", YOB: 1986, POB: "Dhaka"})`

+ `MATCH (plr {name: "Mohammad Mahmudullah Riyad", YOB: 1986, POB: "Dhaka"}) SET plr: player:person RETURN plr`


### Delete Clause
+ You can delete `nodes` and `relationships` from a database using the `DELETE` clause.

+ Deleting All Nodes and Relationships: `MATCH (n) DETACH DELETE n`.This will delete all the nodes and relationships from your neo4j database and make it empty.

#### Deleting a Particular Node
+ `MATCH (node:label {properties . . . . . . . . . .}) DETACH DELETE node`

+ `CREATE (plr:player {name: "Rubel Hossain", YOB: 1990, POB: "Bagerhat"}) RETURN plr;`

+ `MATCH (plr:player {name: "Rubel Hossain", YOB: 1990, POB: "Bagerhat"}) DETACH DELETE plr`

+ Assuming you're referring to Neo4j's internal node id:

+ `MATCH (p:player) where ID(p)=28
OPTIONAL MATCH (p)-[r]-() //drops p's relations
DELETE r,p`

+ `MATCH(n) WHERE ID(n) = 27 RETURN n;`

### Remove Clause
+ The `REMOVE` clause is used to remove `properties` and `labels` from graph elements (Nodes or Relationships).

+ The main difference between Neo4j CQL `DELETE` and `REMOVE` commands is −
  - `DELETE` operation is used to delete `nodes` and associated `relationships`.

  - `REMOVE` operation is used to remove `labels` and `properties`.

#### Removing a Property
+ `MATCH (node:label{properties . . . . . . . }) REMOVE node.property RETURN node`

+ `CREATE (plr:player {name: "Nasir Hossain", YOB: 1991, POB: "Rangpur City"})`

+ `MATCH (n:player {name: "Nasir Hossain", YOB: 1991, POB: "Rangpur City"}) REMOVE n.POB RETURN n`

#### Removing a Label From a Node
+ `MATCH (node:label {properties . . . . . . . . . . .}) REMOVE node:label RETURN node`

+ `MATCH (n:player {name: "Nasir Hossain", YOB: 1991}) REMOVE n:player RETURN n;`

+ `MATCH (n:player {name: "Nasir Hossain", YOB: 1991}) REMOVE n: person:player RETURN n;`

+ Again set multiple label:
`MATCH (n{name: "Nasir Hossain", YOB: 1991}) SET n: person:player RETURN n;`


### Foreach Clause
+ The `FOREACH` clause is used to `update` data within a `list` whether components of a path, or result of aggregation.

+ `MATCH p = (start node)-[*]->(end node)
WHERE start.node = "node_name" AND end.node = "node_name"
FOREACH (n IN nodes(p)| SET n.marked = TRUE)`

+ `CREATE p = (Shakib {name:"Shakib AL Hasan"})-[:TOPSCORRER_OF]->(Ban{name:"Bangladesh"})-[:WINNER_OF]->(CT2013{name: "Champions Trophy 2013"}) RETURN p`

+ `MATCH p = (player)-[*]->(CT2013) WHERE player.name = "Shakib AL Hasan" AND CT2013.name="Champions Trophy 2013" FOREACH (n IN nodes(p)| SET n.marked = TRUE) RETURN p`

### Match Clause
+ Match by Relationship: `MATCH (node:label)<-[: Relationship]-(n) RETURN n`
+ All Actors of The Matrix: `MATCH(mv:Movie {title:"The Matrix"})<-[ac:ACTED_IN]-(pr:Person) RETURN mv,ac, pr;`
+ You can delete all the nodes using the MATCH clause: `MATCH (n) detach delete n `

### Optional Match Clause
+ The `OPTIONAL MATCH` clause is used to search for the pattern described in it, while using nulls for missing parts of the pattern.

+ `MATCH (node:label {properties. . . . . . }) OPTIONAL MATCH (node)-->(x) RETURN x`

+ This query is return all the relation of this Person:`MATCH(pr:Person {name:"Emil Eifrem"}) OPTIONAL MATCH(pr) -->(x) RETURN pr, x;`

+ `MATCH(pr:Person{name:"Cameron Crowe"}) OPTIONAL MATCH(pr) -->(x) RETURN pr,x;`

### Where Clause
+ `MATCH (label) WHERE label.country = "property" RETURN label`

+ `MATCH (n) WHERE (n)-[:TOP_SCORER_OF]->( {name: "Bangladesh"}) RETURN n`

+ `MATCH (mv:Movie)<-[*]-(all) WHERE mv.title="Cloud Atlas" RETURN mv,all;`

+ `MATCH (mv:Movie {title:"Cloud Atlas"})<-[*]-(all)RETURN mv,all;`

### Count Function
+ `MATCH(mv:Movie {title:"Cloud Atlas"})--(x) RETURN count(x) AS NumberOfRow;`
#### Group Count
+ The COUNT clause is also used to count the `groups of relationship types`.

+ `MATCH(mv:Movie {title:"Cloud Atlas"})-[r]-(x) RETURN type(r) AS Relationship, count(x) AS NumberOfRow;`

### Return Clause

### Limit Clause

### Skip Clause

### With Clause
+ You can `chain` the query arts together using the `WITH` clause.
+ `MATCH (n) WITH n ORDER BY n.property RETURN collect(n.property)`

### Unwind Clause
+ The `unwind` clause is used to `unwind a list` into a `sequence of rows`.

+ `UNWIND [a, b, c, d] AS x RETURN x`

+ One common usage of unwind is to create `distinct lists`.

+ Another is to create data from parameter lists that are provided to the query.

+ `UNWIND` requires you to `specify a new name` for the `inner values`.

##### Create a distinct list
+ We want to transform a list of duplicates into a set using `DISTINCT`.

+ `WITH [1, 1, 2, 2] AS coll UNWIND coll AS x WITH DISTINCT x RETURN collect(x) AS SET`
+ Result:
    ```
    +-------+
    | set   |
    +-------+
    | [1,2] |
    +-------+
     1 row
  ```

#### Create nodes from a list parameter
+ Create a number of nodes and relationships from a parameter-list without using `FOREACH`.

+ Parameters:
```
{
  "events" : [ {
    "year" : 2014,
    "id" : 1
  }, {
    "year" : 2014,
    "id" : 2
  } ]
}
```
+ Query:
```
UNWIND $events AS event
 MERGE (y:Year { year: event.year })
 MERGE (y)<-[:IN]-(e:Event { id: event.id })
 RETURN e.id AS x ORDER BY x
 ```
 ## Function
 ###  String Functions

 + [Functions String](https://neo4j.com/docs/developer-manual/current/cypher/functions/string/).

 + Like SQL, Neo4J CQL has provided a set of String functions to use them in CQL Queries to get the required results.

 + Following is the list of prominent String functions in Neo4j.
   - `UPPER` : It is used to change all letters into upper case letters.

   - `MATCH (n:player) RETURN UPPER(n.name), n.YOB, n.POB`

   - `LOWER` : `MATCH (n:player) RETURN LOWER(n.name), n.YOB, n.POB`

   - `SUBSTRING`: It takes a string as an input and `two indexes`: one is the `start of the index` and another is the `end of the index` and returns a substring from Start Index to End Index-1.

   - `MATCH (n:player) RETURN SUBSTRING(n.name,0,5), n.YOB, n.POB`

   - `Replace`: It is used to replace a `substring` with a `given substring` of a String.

 ### Aggregation Function
 + Like SQL, Neo4j CQL has provided some aggregation functions to use in RETURN clause. It is similar to `GROUP BY` clause in SQL.

 + `COUNT`: It returns the `number of rows` returned by MATCH command.

 + `MATCH (n:employee) WHERE n.sal>27000 RETURN COUNT(n)`

 + `MAX`: It returns the `maximum value` from a set of rows returned by MATCH command.

 + `MATCH (n:employee) RETURN MAX(n.sal)`

 + `MIN`: `MATCH (n:employee) RETURN MIN(n.sal)`

 + `SUM`: `MATCH (n:employee) RETURN SUM(n.sal)`

 + `AVG`: `MATCH (n:employee) RETURN AVG(n.sal)`

## Backup & Restore
## Index
+ Neo4j SQL supports Indexes on `node` or `relationship properties` to improve the performance of the application.

+ We can create indexes on `properties for all nodes`, which have the `same label name`.

+ We can use these indexed columns on `MATCH` or `WHERE` or `IN` operator to improve the execution of CQL command.

+ Creating an Index: `CREATE INDEX ON:label (node)`

+ `CREATE (Shakib:player{name: "Shakib Al Hasan", YOB: 1995, POB: "Magura"})`

+ `CREATE INDEX ON:player(Shakib)`

+ Deleting an Index: `DROP INDEX ON:player(Shakib)`

#### Create Unique Constraint
+ UNIQUE constraint is used to avoid duplicate records and to enforce data integrity rule.

+ Neo4j CQL provides `CREATE CONSTRAINT` command to create unique constraints on node or relationship properties.


+ `CREATE (Shakib:player{id:001,name: "Shakib Al Hasan", YOB: 1995, POB: "Magura"})`

+ `CREATE CONSTRAINT ON (n:player) ASSERT n.id IS UNIQUE`

+ Verification: `CREATE (Shakib:player{id:001,name: "Shakib Al Hasan", YOB: 1995, POB: "Magura"})`

#### Drop Unique
+ Neo4j CQL provides `DROP CONSTRAINT` command to delete existing Unique constraint from a node or relationship property.

+ `DROP CONSTRAINT ON (node:label) ASSERT node.id IS UNIQUE`

+ `DROP CONSTRAINT ON (n:player) ASSERT n.id IS UNIQUE`

# Quick Guide
## Overview
+ Neo4j is the world's leading open source Graph Database which is developed using `Java technology`.

+ It is `highly scalable` and `schema free (NoSQL)`.

+ What is a Graph Database?
  - A graph is a pictorial representation of a `set of objects` where some pairs of objects are connected by links.

  - It is composed of two elements - `nodes (vertices)` and `relationships (edges)`.

  - the `nodes` of a graph depict the `entities`
  - while the `relationships` depict the `association` of these nodes.


+ Why Graph Databases?
 - Nowadays, most of the `data exists` in the form of the `relationship` between different objects and more often.

 - the `relationship` between the data is `more valuable` than the `data itself`.

 - Relational databases store `highly structured data` which have several records storing the `same type of data` so they can be used to store structured data and, they `do not store the relationships` between the data.
 - Unlike other databases, graph databases `store relationships` and `connections` as `first-class entities`.

 #### Advantages of Neo4j

  + `Flexible data model`: which can be `easily changed` according to the applications and industries.

  + `No joins`: it does NOT require `complex joins` to retrieve connected/related data as it is very easy to retrieve its adjacent node or relationship details without `joins or indexes`.

  + `Real-time insights`: provides results based on real-time data.

  + `High availability`: highly available for `large enterprise real-time applications` with transactional guarantees.

  + `Connected and semi structures data`: can easily represent connected and semi-structured data.

  + `Easy retrieval`: easily retrieve (traverse/navigate) connected data faster when compared to other databases.

  + `Cypher query language`: provides a `declarative query language` to represent the graph visually, using an `ascii-art syntax`. The commands of this language are in human readable format and very easy to learn.

 #### Features of Neo4j
+ Neo4j uses Native `GPE` (`Graph Processing Engine`) to work with its Native graph storage format.

+ The main building blocks of Graph DB Data Model are −
  - Nodes
  - Relationships
  - Properties
  - Labels
  - Data Browser

### Labels
+ Label associates a `common name` to a set of nodes or relationships.

+ A node or relationship can contain one or more labels.

+ We can create new labels to existing nodes or relationships.

+ We can remove the existing labels from the existing nodes or relationships.

+ Relationship between those two nodes also has a Label: ex. `WORKS_FOR`.

`Note` − Neo4j stores data in `Properties` of Nodes or Relationships.
## References
+ [Download 1](https://neo4j.com/artifact.php?name=neo4j-desktop-1.0.2.dmg)

+ [Download 2](https://neo4j.com/download-thanks/?edition=desktop&flavour=osx&release=1.0.2)

+ [Developer Manual](http://neo4j.com/docs/developer-manual/3.2/introduction/)
