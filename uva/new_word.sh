#!/bin/bash

if	[[ $# == 2 ]] && \
	[[ $1 =~ ^[_a-z]+$ ]] &&\
	[[ $2 =~ ^[_а-я]+$ ]];
then
	echo $1 $2 >> .words.txt
else
	echo "usage: ./push [_a-z]+ [_а-я]+"
fi

