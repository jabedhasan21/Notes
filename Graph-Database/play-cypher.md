# Play Cypher

## Cypher
+ Cypher is Neo4j's graph query language.
+ Working with a graph is all about understanding patterns of data, which are central to Cypher queries.
+ Use `MATCH` clauses for reading data, and `CREATE` or `MERGE` for writing data.

## CREATE
Create a node: `CREATE (ee:Person {name: "Emil", from: "Sweden", klout:99})`

## MATCH
Finding nodes: `MATCH (ee:Person) WHERE ee.name = "Emil" RETURN ee`

## CREATE more
+ Nodes and relationships.
+ CREATE clauses can create many nodes and relationships at once.
```
MATCH (ee:Person) WHERE ee.name="Emil"
CREATE (js:Person { name: "Johan", from: "Sweden", learn: "surfing"}),
       (ir:Person { name: "Ian" from: "England", title:"author"}),
       (rbv:Person { name: "Rik" from: "Belgium", pet: "Orval"}),
       (ally:Person {name: "Allison", from: "California", hobby: "surfing"}),
       (ee)-[:KNOWS {since: 2001}]->(js),
       (ee)-[:KNOWS {rating: 5}]->(ir),
       (js)-[:KNOWS]->(ir),
       (js)-[:KNOWS]->(rbv),
       (ir)-[:KNOWS]->(js),
       (ir)-[:KNOWS]->(ally),
       (rvb)-[:KNOWS]->(ally)
```

## Pattern matching
Describe what to find in the graph
For instance, a pattern can be used to find Emil's friends:
```
MATCH (ee:Person)-[:KNOWS]-(friends)
WHERE ee.name="Emil" RETURN ee, friends
```

## Recommend
+ Using patterns
+ Pattern matching can be used to make recommendations.
+ Johan is learning to surf, so he may want to find a new friend who already does:

```
MATCH (js:Person)-[:KNOWS]-()-[:KNOWS]-(surfer)
WHERE js.name="Johan" AND surfer.hobby="surfing"
RETURN js, surfer
```

## Analyze
+ Using the visual query plan
+ Understand how your query works by prepending `EXPLAIN` or `PROFILE`:




# Reference
+ [Cypher-Manual](https://neo4j.com/docs/cypher-manual/current/)