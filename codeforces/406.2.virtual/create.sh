#!/bin/bash
case $1 in
	("")
		echo "usage: ./create.sh <text>"
	;;

	(*)
		if [[ -f "$1" ]];
		then
			echo "File exists: $1"
		else
			cat 00000.cpp > $1
		fi
		gvim -p $1 file.in file.out
esac

