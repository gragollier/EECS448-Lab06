FROM ubuntu

RUN apt-get update && echo "Cache Busting"
RUN apt-get install -y make g++
