# EECS448 - Lab6: Unit Tests


## Usage
Due to the include/obfuscated `Queue.o` file being compiled for Linux x86_64, the easiest way to run
the project is through using docker.

### Building the image
Can run in docker using by building the image:

`docker build -t 448-cpp .`

### Using the image interactively
And then run mounting the current director as a volume:

`docker run -it -v "$(pwd)":/opt/app 448-cpp`