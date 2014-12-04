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
		echo "#include <cmath>"										>> "$src"
		echo "#include <bitset>"									>> "$src"
		echo "#include <cstdio>"									>> "$src"
		echo "#include <vector>"									>> "$src"
		echo "#include <cstdlib>"									>> "$src"
		echo "#include <iostream>"									>> "$src"
		echo "#include <algorithm>"									>> "$src"
		echo "using namespace std;"									>> "$src"
		echo														>> "$src"
		echo "int main()"											>> "$src"
		echo "{"													>> "$src"
		echo "#ifndef LOCAL"										>> "$src"
		echo "	freopen(PROB_NAME\".in\", \"rt\", stdin);"			>> "$src"
		echo "	freopen(PROB_NAME\".out\", \"wt\", stdout);"		>> "$src"
		echo "#endif"												>> "$src"
		echo														>> "$src"
		echo "	return 0;"											>> "$src"
		echo "}"													>> "$src"
		echo														>> "$src"
	;;
esac

echo compile with option -DLOCAL

