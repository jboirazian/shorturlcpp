#/bin/bash

rm src/shorturlcpp
g++ src/main.cpp -o src/shorturlcpp -lpthread -ljsoncpp -lcurl -I includes