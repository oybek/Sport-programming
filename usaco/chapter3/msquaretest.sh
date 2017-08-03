#!/bin/bash

# Magic Squares
# IOI'96
# 
# Following the success of the magic cube, Mr. Rubik invented its planar version, called magic squares. This is a sheet composed of 8 equal-sized squares:
# 1234
# 8765
# 
# In this task we consider the version where each square has a different color. Colors are denoted by the first 8 positive integers. A sheet configuration
# is given by the sequence of colors obtained by reading the colors of the squares starting at the upper left corner and going in clockwise direction. For
# instance, the configuration of Figure 3 is given by the sequence (1,2,3,4,5,6,7,8). This configuration is the initial configuration.
# 
# Three basic transformations, identified by the letters `A', `B' and `C', can be applied to a sheet:
# 
#     'A': exchange the top and bottom row,
#     'B': single right circular shifting of the rectangle,
#     'C': single clockwise rotation of the middle four squares.
# 
# Below is a demonstration of applying the transformations to the initial squares given above:
# A:
# 8765
# 1234
#
# B:
# 4123
# 5876
#
# C:
# 1724
# 8635
# 
# All possible configurations are available using the three basic transformations.
# 
# You are to write a program that computes a minimal sequence of basic transformations that transforms the initial configuration above to a specific target configuration.
# PROGRAM NAME: msquare
# INPUT FORMAT
# 
# A single line with eight space-separated integers (a permutation of (1..8)) that are the target configuration.
# SAMPLE INPUT: (stdin)
# 
# 2 6 8 4 5 7 3 1 
# 
# OUTPUT FORMAT
# Line 1:	The lexically earliest string of transformations expressed as a string of characters, 60 per line except possibly the last line.
# SAMPLE OUTPUT: (stdout)
# 
# 7
# BCABCCB

if [ "$1" == "" ];
then
	echo "usage: ./msquaretest.sh <binary>"
	exit 1
fi

echo -n -e "\e[39mtest 1: "
[ "$(echo "2 6 8 4 5 7 3 1" | $1)" == "BCABCCB" ]					&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 2: "
[ "$(echo "1 2 3 4 5 6 7 8" | $1)" == "" ]							&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 3: "
[ "$(echo "6 7 4 1 8 5 2 3" | $1)" == "CCBBB" ]						&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 4: "
[ "$(echo "5 1 2 4 3 7 8 6" | $1)" == "ABBBCABB" ]					&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 5: "
[ "$(echo "6 1 5 4 3 2 7 8" | $1)" == "ABBBCABBBCBBBC" ]			&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 6: "
[ "$(echo "4 1 2 3 5 8 7 6" | $1)" == "CCBCBCBBCBCBCCB" ]			&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 7: "
[ "$(echo "3 4 2 1 5 6 7 8" | $1)" == "ABCABBBCBBBCBCABCB" ]		&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }

echo -n -e "\e[39mtest 8: "
[ "$(echo "4 3 1 2 5 6 7 8" | $1)" == "ABBBCABBBCBBBCBCABCBBB" ]	&& echo -e "\e[32mOK" || { echo -e "\e[31mFAIL"; exit 1; }


echo -n -e "\e[39\nmWork time:"

time {
	echo "2 6 8 4 5 7 3 1" | $1 > /dev/null;
	echo "1 2 3 4 5 6 7 8" | $1 > /dev/null;
	echo "6 7 4 1 8 5 2 3" | $1 > /dev/null;
	echo "5 1 2 4 3 7 8 6" | $1 > /dev/null;
	echo "6 1 5 4 3 2 7 8" | $1 > /dev/null;
	echo "4 1 2 3 5 8 7 6" | $1 > /dev/null;
	echo "3 4 2 1 5 6 7 8" | $1 > /dev/null;
	echo "4 3 1 2 5 6 7 8" | $1 > /dev/null;
}

cowsay "Congratulations! ${time}"

