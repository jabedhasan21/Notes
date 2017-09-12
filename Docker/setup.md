# Get started with Docker for Mac
+ **Check versions of Docker Engine, Compose, and Machine**
+ `docker --version`
+ `docker-compose --version`
+ `docker-machine --version`
+ You can check whether you are running experimental mode or not by typing `docker version` on the command line. Experimental mode is listed under `Server` data. If `Experimental` is `true`, then Docker is running in experimental mode, as shown here. (If `false`, Experimental mode is off.)

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

### Dockerfile
This is the sample php hello world application docker file
  ```
  FROM php:7.0-apache
  COPY src/ /var/www/html/
  EXPOSE 80
  ```
### Command
+ docker build -t hello-world .

+ docker run -p 9000:80 hello-world

+ docker run -p 9000:80 -v /Users/jabed/Documents/demo-docker/src/:/var/www/html/ hello-world

+ docker run hello-world (To test docker is working )

+ `docker pull alpine` (
The `pull` command fetches the alpine image from the Docker registry and saves it in our system.)

+ `docker run alpine ls -l` (The Docker daemon creates the container and then runs a command in that container.)

+ `docker run -it alpine /bin/sh` (You are now inside the container shell and you can try out a few commands like `ls -l`, `uname -a` and others. Exit out of the container by giving the `exit` command.)

+ `docker ps` ( To see all running container `-a` for all created & running container)

+ To find out more about a Docker image, run: `docker inspect alpine`

+ `docker rm -f b40f99146490` (To removed the running container)

+ If you want to stop the webserver, type: `docker stop webserver` and start it again with `docker start webserver`

+ You can also search for images directly from the command line using `docker search`.


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
