#!/bin/bash

color="\e[1m\e[32m"
reset="\e[0m"

echo -e "${color}run.sh: g++ $1 -std=c++11 -g -Wall -DLOCAL${reset}"
g++ $1 -std=c++11 -g -Wall -DLOCAL

if [ -f "$2" ]; then
	echo -e "${color}run.sh: ./a.out < $2${reset}"
	./a.out < $2
else
	echo -e "${color}run.sh: ./a.out${reset}"
	./a.out
fi

echo -e "${color}run.sh: Press ctrl+c to exit${reset}"
sleep 10000

