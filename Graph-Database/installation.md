# Installation
###  On ubuntu 16.04
#### Installing Java
Neo4j is implemented in Java, so you’ll need to have the `Java` Runtime Environment (`JRE`) installed. If you already have this up and running, go ahead and skip this step.

+ `sudo apt install default-jre default-jre-headless`

+ Check whether you can now run the `java` executable.

#### Installing Neo4j
First we’ll add the repository key to our keychain.
+ `wget --no-check-certificate -O - https://debian.neo4j.org/neotechnology.gpg.key | sudo apt-key add -`

Then add the repository to the list of apt sources.

+ `echo 'deb http://debian.neo4j.org/repo stable/' | sudo tee /etc/apt/sources.list.d/neo4j.list`

Finally update the repository information and install Neo4j
```
sudo apt update
sudo apt install neo4j
```

The server should have started automatically and should also be restarted at boot. If necessary the server can be stopped with

`sudo service neo4j stop`

and restarted with

`sudo service neo4j start`


#### Accessing Neo4j
+ You should now be able to access the database server via http://localhost:7474/browser/.

+ Sometimes you may fetch  some problems logging in with the default username and password (`neo4j` and `neo4j`), but this was easily resolved by deleting the file `/var/lib/neo4j/data/dbms/auth` and restarting the server.

####  Enable automatically starting Neo4j when the system starts.

+ Go to the `cd /lib/systemd/system/` directory.

+ Then :`cat neo4j.service` & the output should be following.

```
[Unit]
Description=Neo4j Graph Database
After=network-online.target
Wants=network-online.target

[Service]
ExecStart=/usr/share/neo4j/bin/neo4j console
Restart=on-failure
User=neo4j
Group=neo4j
Environment="NEO4J_CONF=/etc/neo4j" "NEO4J_HOME=/var/lib/neo4j"
LimitNOFILE=60000
TimeoutSec=120

[Install]
WantedBy=multi-user.target
```
This file has a simple structure:

+ The **Unit** section contains the overview (e.g. a human-readable description for Neo4j service) as well as dependencies that must be satisfied before the service is started. In our case, Neo4j depends on networking already being available, hence `network-online.target` here.

+ The **Service** section how the service should be started. The User directive specifies that the server will be run under the `neo4j` user, and the ExecStart directive defines the startup command for Neo4j server.

+ The last section, **Install**, tells systemd when the service should be automatically started. The `multi-user.target` is a standard system startup sequence, which means the server will be automatically started during boot.

To enable automatically starting Neo4j when the system starts.

`sudo systemctl enable neo4j`

The Neo4j server now configured and running, and you can manage the Neo4j service using the systemctl command (e.g. `sudo systemctl neo4j stop`, `sudo systemctl neo4j start/status`)

+ Set initial password: `neo4j-admin set-initial-password <password>`

+ To `cypher-shell` logging need to enable `bolt`
**Bolt connector:**
`dbms.connector.bolt.enabled=true`

+ [connectors](https://neo4j.com/docs/operations-manual/current/configuration/connectors/)
