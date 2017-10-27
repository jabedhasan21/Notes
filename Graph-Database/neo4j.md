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
