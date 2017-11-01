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

## References
+ [Download 1](https://neo4j.com/artifact.php?name=neo4j-desktop-1.0.2.dmg)

+ [Download 2](https://neo4j.com/download-thanks/?edition=desktop&flavour=osx&release=1.0.2)

+ [Developer Manual](http://neo4j.com/docs/developer-manual/3.2/introduction/)
