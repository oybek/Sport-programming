#!/bin/bash

for i in $(seq 1 1000);
do
	printf "1\n$i\n" | ./a.out
done

