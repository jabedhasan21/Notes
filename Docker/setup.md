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

## Get Started
+ [get-started](https://docs.docker.com/get-started/)
+ [Beginners](https://docker-curriculum.com/)
## References
+ [Docker For Mac](https://docs.docker.com/docker-for-mac/#explore-the-application-and-run-examples)
+ [Video Tutorial](https://www.youtube.com/watch?v=pGYAg7TMmp0&list=PLoYCgNOIyGAAzevEST2qm2Xbe3aeLFvLc)
+ [How To Use Docker](https://github.com/docker/labs)
+ [Container Tutorials](http://containertutorials.com/)
