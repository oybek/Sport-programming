#!/bin/bash

for i in {0..9};
do
	read n
	calc -p $n > input0$i.txt
	cat input0$i.txt | ./a.out > output$i.txt
	echo "ok"
done

