FROM gcc:latest 

WORKDIR /app

RUN apt-get update && apt-get install -y build-essential gdb

COPY . .