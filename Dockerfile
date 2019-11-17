FROM ubuntu

RUN apt-get update && apt-get install -y make g++ valgrind
