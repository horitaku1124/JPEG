# docker build . -t circleci -f Dockerfile
FROM debian:stretch

# WARNING: apt does not have a stable CLI interface. Use with caution in scripts.
RUN apt update -y
RUN apt install -y make gcc clang libomp-dev
RUN apt install -y git vim