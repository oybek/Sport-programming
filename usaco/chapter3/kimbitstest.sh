#!/bin/bash

# Stringsobits
# by Kim Schrijvers
# 
# Consider an ordered set S of strings of N (1 <= N <= 31) bits. Bits, of course, are either 0 or 1.
# 
# This set of strings is interesting because it is ordered and contains all possible strings of length N that have L (1 <= L <= N) or fewer bits that are `1'.
# 
# Your task is to read a number I (1 <= I <= sizeof(S)) from the input and print the Ith element of the ordered set for N bits with no more than L bits that are `1'.
#
# PROGRAM NAME: kimbits
#
# INPUT FORMAT
# A single line with three space separated integers: N, L, and I.
#
# SAMPLE INPUT (file kimbits.in)
# 
# 5 3 19
# 
# OUTPUT FORMAT
#
# A single line containing the integer that represents the Ith element from the order set, as described.
#
# SAMPLE OUTPUT (file kimbits.out)
# 
# 10011

if [ "$1" == "" ];
then
	echo "usage: ./kimbitstest.sh <binary>"
	exit 1
fi

echo -n -e "\e[39mtest 1: "
[ "$(echo "4 2 1" | $1)" == "0000" ]										&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 2: "
[ "$(echo "1 1 2" | $1)" == "1" ]											&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 3: "
[ "$(echo "8 4 30" | $1)" == "00011101" ]									&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 4: "
[ "$(echo "10 2 56" | $1)" == "1100000000" ]								&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 5: "
[ "$(echo "7 7 64" | $1)" == "0111111" ]									&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 6: "
[ "$(echo "18 3 300" | $1)" == "000001000000000000" ]						&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 7: "
[ "$(echo "21 10 1048576" | $1)" == "111111111100000000000" ]				&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 8: "
[ "$(echo "24 20 12936478" | $1)" == "110001010110011100110000" ]			&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 9: "
[ "$(echo "31 24 10000000" | $1)" == "0000000100110001001011001111111" ]	&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 10: "
[ "$(echo "31 31 2147483648" | $1)" == "1111111111111111111111111111111" ]	&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 11: "
[ "$(echo "31 26 12345678" | $1)" == "0000000101111000110000101001101" ]	&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 12: "
[ "$(echo "31 26 123456789" | $1)" == "0000111010110111100110100010100" ]	&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 13: "
[ "$(echo "31 26 1234567890" | $1)" == "1001001100101100001010010011011" ]	&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }


echo -n -e "\e[39\nmWork time:"

time {
	echo "4 2 1"			| $1 > /dev/null
	echo "1 1 2"			| $1 > /dev/null
	echo "8 4 30"			| $1 > /dev/null
	echo "10 2 56"			| $1 > /dev/null
	echo "7 7 64"			| $1 > /dev/null
	echo "18 3 300"			| $1 > /dev/null
	echo "21 10 1048576"	| $1 > /dev/null
	echo "24 20 12936478"	| $1 > /dev/null
	echo "31 24 10000000"	| $1 > /dev/null
	echo "31 31 2147483648"	| $1 > /dev/null
	echo "31 26 12345678"	| $1 > /dev/null
	echo "31 26 123456789"	| $1 > /dev/null
	echo "31 26 1234567890"	| $1 > /dev/null
}

cowsay "Congratulations! Mooooooooou!!"

