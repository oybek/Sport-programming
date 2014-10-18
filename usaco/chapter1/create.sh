#!/bin/bash

case $1 in
	("")
		echo "usage: ./create.sh <text>"
	;;

	(*)
		if [[ $1 =~ ^[_A-Za-z0-9]+\.cpp ]];
		then
			name=${1:0:$[${#1}-4]}
			src=$1
		else
			name=$1
			src="$1.cpp"
		fi

		echo 														>  "$src"
		echo "/*"													>> "$src"
		echo "ID: aybek.h2"											>> "$src"
		echo "PROG: $name"											>> "$src"
		echo "LANG: C++"											>> "$src"
		echo "*/"													>> "$src"
		echo														>> "$src"
		echo "#define PROB_NAME \"$name\""							>> "$src"
		echo														>> "$src"
		echo "#include <fstream>"									>> "$src"
		echo "#include <iostream>"									>> "$src"
		echo														>> "$src"
		echo "/*"													>> "$src"
		echo "std::ifstream cin	(PROB_NAME\".in\");"				>> "$src"
		echo "std::ofstream cout	(PROB_NAME\".out\");"			>> "$src"
		echo "*/"													>> "$src"
		echo														>> "$src"
		echo "int main() {"											>> "$src"
		echo														>> "$src"
		echo "	return 0;"											>> "$src"
		echo "}"													>> "$src"
		echo														>> "$src"
	;;
esac

