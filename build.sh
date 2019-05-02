#!/bin/bash
if [ ! -d "bin" ]; then
  mkdir bin
fi
g++ -Wall -g -std=gnu++11 -o bin/out.exe src/*.cpp

