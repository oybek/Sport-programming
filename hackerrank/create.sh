#!/bin/bash
case $1 in
	("")
		echo "usage: ./create.sh <text>"
	;;

	(*)
		if [[ $1 =~ ^[0-9a-z\-]+\.cpp ]];
		then
			if [[ -f "$1" ]];
			then
				echo "File exists: $1"
			else
				cat 00000.cpp > $1
			fi
			gvim $1
		else
			echo "arg format: ^[0-9]+\.cpp";
		fi;;
esac

