# Hello World
### Dockerfile
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
