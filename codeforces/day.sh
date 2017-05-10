#!/bin/bash

ufiles=$(git ls-files --others --exclude-standard | grep cpp)
if [[ ${ufiles} =~ .*\.cpp ]];
then
	echo "(~˘▾˘)~ today you solved $(stat -c %y ${ufiles} | grep -c $(date +%Y-%m-%d) )"
else
	echo "(~˘▾˘)~ today you solved 0"
fi

