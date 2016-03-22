#!/bin/bash

a="Hello"
for folder in $(ls -d */);
do
	mv $folder ${folder,,}
done

