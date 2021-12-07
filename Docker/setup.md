# Get started with Docker for Mac
+ **Check versions of Docker Engine, Compose, and Machine**
+ `docker --version`
+ `docker-compose --version`
+ `docker-machine --version`
+ You can check whether you are running experimental mode or not by typing `docker version` on the command line. Experimental mode is listed under `Server` data. If `Experimental` is `true`, then Docker is running in experimental mode, as shown here. (If `false`, Experimental mode is off.)
+ access docker container: `docker exec -it <mycontainer> bash or sh`


# Get Started.
### Part 1: Orientation and setup
+ An `image` is a lightweight, stand-alone, executable package that includes everything needed to run a piece of software, including the code, a runtime, libraries, environment variables, and config files.

+ A `container` is a runtime instance of an image—what the image becomes in memory when actually executed. It runs completely isolated from the host environment by default, only accessing host files and ports if configured to do so.

### Part 2: Containers
+ Stack:  defining the interactions of all the services
+ Services:  which defines how containers behave in production
+ Container (you are here)

+ Run app: `docker run -p 4000:80 application-image-name`

+  Run app in the background: `docker run -d -p 4000:80 application-image-name`

+ Container is running in the background. You can also see the abbreviated container ID with `docker container ls`
#### Share your image
+ Log in to the Docker public registry on your local machine:`docker login`

+ Tag the image: The notation for associating a local image with a repository on a registry is `username/repository:tag`. The tag is optional, but recommended, since it is the mechanism that registries use to give Docker images a version. Give the repository and tag meaningful names for the context, such as `get-started:part1`. This will put the image in the `get-started` repository and tag it as `part1`.

+ `docker tag image username/repository:tag
`

+ Example: `docker tag friendlyhello jabedhasan21/get-started:part1`

+ Publish the image: `docker push jabedhasan21/get-started:part1`

+ Pull and run the image from the remote repository: `docker run -d -p 4000:80 jabedhasan21/get-started:part1`

Now, put it all together to tag the image. Run docker tag image with your username, repository, and tag names so that the image will upload to your desired destination. The syntax of the command is:

**Here is a list of the basic Docker commands from this page, and some related ones if you’d like to explore a bit before moving on.**
```
docker build -t friendlyname .  # Create image using this directory's Dockerfile
docker run -p 4000:80 friendlyname  # Run "friendlyname" mapping port 4000 to 80
docker run -d -p 4000:80 friendlyname         # Same thing, but in detached mode
docker container ls                                # List all running containers
docker container ls -a             # List all containers, even those not running
docker container stop <hash>           # Gracefully stop the specified container
docker container kill <hash>         # Force shutdown of the specified container
docker container rm <hash>        # Remove specified container from this machine
docker container rm $(docker container ls -a -q)         # Remove all containers
docker image ls -a                             # List all images on this machine
docker image rm <image id>            # Remove specified image from this machine
docker image rm $(docker image ls -a -q)   # Remove all images from this machine
docker login             # Log in this CLI session using your Docker credentials
docker tag <image> username/repository:tag  # Tag <image> for upload to registry
docker push username/repository:tag            # Upload tagged image to registry
docker run username/repository:tag                   # Run image from a registry
```
### Part 3: Services
In part 3, we scale our application and enable load-balancing.
#### Services
`In a distributed application, different pieces of the app are called “services.”`For example, if you imagine a video sharing site, it probably includes a service for storing application data in a database, a service for video transcoding in the background after a user uploads something, a service for the front-end, and so on.

`Services are really just “containers in production.”` A service only runs one image, but it codifies the way that image runs—what ports it should use, how many replicas of the container should run so the service has the capacity it needs, and so on. Scaling a service changes the number of container instances running that piece of software, assigning more computing resources to the service in the process.

Luckily it’s very easy to define, run, and scale services with the Docker platform – just write a `docker-compose.yml` file.

#### Your first `docker-compose.yml` file

A `docker-compose.yml` file is a YAML file that defines how Docker containers should behave in production.
+  Update this `.yml` by replacing `username/repo:tag` with your image details
```
version: "3"
services:
  web:
    # replace username/repo:tag with your name and image details
    image: username/repository:tag
    deploy:
      replicas: 5
      resources:
        limits:
          cpus: "0.1"
          memory: 50M
      restart_policy:
        condition: on-failure
    ports:
      - "80:80"
    networks:
      - webnet
networks:
  webnet:
```

This `docker-compose.yml` file tells Docker to do the following:

+ Pull the image from the registry.
+ Run 5 instances of that image as a service called `web`, limiting each one to use, at most, 10% of the CPU (across all cores), and 50MB of RAM.
+ Immediately restart containers if one fails.
+ Map port 80 on the host to `web`’s port 80.
+ Instruct `web`’s containers to share port 80 via a load-balanced network called `webnet`. (Internally, the containers themselves will publish to `web`’s port 80 at an ephemeral port.)
+ Define the `webnet` network with the default settings (which is a load-balanced overlay network).

#### Run your new load-balanced app
+ Before we can use the `docker stack deploy` command we’ll first run:

    `docker swarm init`

+ Now let’s run it. You have to give your app a name. Here, it is set to `getstartedlab`:

  `docker stack deploy -c docker-compose.yml getstartedlab`

+ Our `single service` stack is running 5 container instances of our deployed image on one host.

+ Let’s investigate.Get the service ID for the one service in our application:`docker service ls`

+ Docker swarms run tasks that spawn containers. Tasks have state and their own IDs:`docker service ps <service>`

+ Let’s inspect one task and limit the output to container ID: `docker inspect --format='{{.Status.ContainerStatus.ContainerID}}' <task>`

+ Vice versa, inspect the container ID, and extract the task ID:`docker inspect --format="{{index .Config.Labels \"com.docker.swarm.task.id\"}}" <container>`

+ Now list all 5 containers:`docker container ls -q`

+ Take down the app and the swarm: `docker stack rm getstartedlab`

+ This removes the app, but our one-node swarm is still up and running (as shown by `docker node ls`).

+ Take down the swarm with `docker swarm leave --force`.

Some commands to explore at this stage:
```
docker stack ls                                            # List stacks or apps
docker stack deploy -c <composefile> <appname>  # Run the specified Compose file
docker service ls                 # List running services associated with an app
docker service ps <service>                  # List tasks associated with an app
docker inspect <task or container>                   # Inspect task or container
docker container ls -q                                      # List container IDs
docker stack rm <appname>                             # Tear down an application
```

###  Part 4: Swarms
Here in part 4, you deploy this application onto a cluster, running it on multiple machines. Multi-container, multi-machine applications are made possible by joining multiple machines into a “Dockerized” cluster called a swarm.

#### Understanding Swarm clusters
A swarm is a group of machines that are running Docker and joined into a cluster.

#### Set up your swarm

### Part 5: Stacks
 + A stack is a group of `interrelated services` that share dependencies, and can be `orchestrated` and `scaled` together.
 + A single stack is capable of defining and coordinating the functionality of an entire application (though very complex applications may want to use multiple stacks).

### Part 6: Deploy your app


## Link Amazon Web Services to Docker Cloud

### Dockerfile
This is the sample php hello world application docker file
  ```
  FROM php:7.0-apache
  COPY src/ /var/www/html/
  EXPOSE 80
  ```

### Command
+ [CLI](https://docs.docker.com/engine/reference/commandline/docker/)

+ docker build -t hello-world .

+ The `-t` flag sets a tag for our image

+ docker run -p 9000:80 hello-world

+ docker run -p 9000:80 -v /Users/jabed/Documents/demo-docker/src/:/var/www/html/ hello-world

+ docker run hello-world (To test docker is working )

+ Run with environment variables: `docker run --env-file .env -it --rm -p 9000:3000 mn-api`

+ `docker pull alpine` (
The `pull` command fetches the alpine image from the Docker registry and saves it in our system.)

+ `docker run alpine ls -l` (The Docker daemon creates the container and then runs a command in that container.)

+ `docker run -it alpine /bin/sh` (You are now inside the container shell and you can try out a few commands like `ls -l`, `uname -a` and others. Exit out of the container by giving the `exit` command.)

+ `-it` – This param tells Docker to run our image and create a psuedo-TTY connected to the container’s stdin as well as create a bash shell. Basically it makes it accessible from the command line like we would normally see running our node app with “npm start” or similar.

+ `-–rm` – This param tells Docker to automatically remove the container when it exits. *NOTE*: We cannot combine the –rm and -d flags together.

+ `docker ps` ( To see all running container `-a` for all created & running container)

+ To find out more about a Docker image, run: `docker inspect alpine`

+ `docker rm -f b40f99146490` (To removed the running container)

+ If you want to stop the webserver, type: `docker stop webserver` and start it again with `docker start webserver`

  You can always push a new image to this repository using the CLI
+ `docker tag local-image:tagname new-repo:tagname`

+ `docker push new-repo:tagname`

+ To know IP addresses of VM: `docker-machine env myvm1`

+ You can also search for images directly from the command line using `docker search`.

+ `docker attach` will let you connect to your Docker container, but this isn't really the same thing as  ssh. If your container is running a webserver, for example, `docker attach` will probably connect you to the stdout of the web server process. It won't necessarily give you a shell.

+ The `docker exec` command is let you ssh the container ; this will let you run arbitrary commands inside an existing container. For example: `docker exec -it <mycontainer> bash`

+ docker-stack-and-private-registry: `docker stack deploy -c docker-compose.yml --with-registry-auth`

+ `docker login -u #DockerHub Username# -p #DockerHub Password# registry.hub.Docker.com/#Organization-Or-DockerHubUserName# && Docker stack deploy -c Docker-swarm.yml #STACK-NAME# --with-registry-auth`


## Get Started
+ [get-started](https://docs.docker.com/get-started/)
+ [Beginners](https://docker-curriculum.com/)
+ [Automated Builds with Docker Cloud](https://docs.docker.com/docker-cloud/builds/automated-build/)
+ [Docker Cloud repositories](https://docs.docker.com/docker-cloud/builds/repos/)
+ [Docker for beginners](https://github.com/docker/labs/tree/master/beginner)

## Webapps with Docker
+ `docker run -d dockersamples/static-site`

+ `docker run --name static-site -e AUTHOR="Jabed Bangali" -d -P dockersamples/static-site`

+ If you are using Docker Machine on Mac or Windows, you can find the hostname on the command line using docker-machine as follows (assuming you are using the default machine).
`docker-machine ip default`
### Docker Images

+ An important distinction with regard to images is between `base images` and `child images`.

+ `Base images` are images that have no parent images, usually images with an OS like ubuntu, alpine or debian.

+ `Child images` are images that build on base images and add additional functionality.


## Write a Dockerfile
+ A `Dockerfile` is a text file that contains a list of commands that the Docker daemon calls while creating an image.

## Build the image
+ `docker build -t jabedhasan21/myfirstapp .`

## Run your image
+ `docker run -p 8888:5000 --name myfirstapp jabedhasan21/myfirstapp`

## Push your image
+ `docker login`. Enter `YOUR_USERNAME` and `password` when prompted.

+ `docker push YOUR_USERNAME/myfirstapp`


## Deploying an app to a Swarm
+ create a Swarm:`docker swarm init`

+  deploy it: `docker stack deploy --compose-file docker-stack.yml vote`

+ To verify your stack has deployed, use `docker stack services vote`

+ Remove the stack from the swarm: `docker stack rm vote`

## Container networking on a single Docker host
+ We will use `Docker Machine` to create our test Docker Host. Driver's option is set to virtualbox so the host is created on the local machine as a virtualbox virtual machine.
`docker-machine create --driver virtualbox node1`

+ Get the IP of node1 `docker-machine ip node1` (⇒ 192.168.99.100)

# All command
``` docker-machine start myvm1
 docker-machine env myvm1
 eval $(docker-machine env myvm1)

docker-machine ssh myvm1 "docker swarm init --advertise-addr 192.168.99.100"


Need to join a worker node in swarm: 
docker swarm join --token SWMTKN-1-4y0sw35m2g90r5viqycogfm20p6dv1vg0f1tl6omythjgwn4tq-aepaw7v4ze6aw4x7xhdx8cflz 192.168.99.100:2377


In manager node: docker node ls

docker-machine ls


docker stack deploy -c docker-sample-composer.yml test
```

## References
+ [Docker For Mac](https://docs.docker.com/docker-for-mac/#explore-the-application-and-run-examples)
+ [Video Tutorial](https://www.youtube.com/watch?v=pGYAg7TMmp0&list=PLoYCgNOIyGAAzevEST2qm2Xbe3aeLFvLc)
+ [How To Use Docker](https://github.com/docker/labs)
+ [Container Tutorials](http://containertutorials.com/)
+ [Docker Machine](https://github.com/docker/machine)
+ [Official repositories on Docker Hub](https://docs.docker.com/docker-hub/official_repos/)
+ [Dockerfile reference commands](https://docs.docker.com/engine/reference/builder/)
+ [Networking](https://github.com/docker/labs/tree/master/networking)

+ [Organizations and Teams in Docker Cloud](https://docs.docker.com/docker-cloud/orgs/)

+ [Link Amazon Web Services to Docker Cloud](https://docs.docker.com/docker-cloud/cloud-swarm/link-aws-swarm/)

+ [Automated Builds with Docker Cloud](https://www.youtube.com/watch?v=sl2mfyjnkXk&feature=youtu.be)

+ [Deploy a Node.js and MongoDB Application](https://www.digitalocean.com/community/tutorials/how-to-deploy-a-node-js-and-mongodb-application-with-rancher-on-ubuntu-14-04)

+ [Container Management Platform](http://rancher.com/rancher/)

+ [Moby](https://github.com/moby/moby)

+ [Docker Compose](https://docs.docker.com/compose/)

+ [Compose command-line reference](https://docs.docker.com/compose/reference/)

+ [Deploy your app on Docker for AWS](https://docs.docker.com/docker-for-aws/deploy/)

+ [Installing Docker Images from private repositories in Docker Swarm](http://littlebigextra.com/installing-docker-images-private-repositories-docker-swarm/)

+ [Register Swarms](https://docs.docker.com/docker-cloud/cloud-swarm/register-swarms/)

+ [katacoda courses](https://www.katacoda.com/courses/docker)
