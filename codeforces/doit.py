#!/usr/bin/python

import requests
import glob, os

r = requests.get('http://codeforces.com/api/problemset.problems')

arr = r.json()["result"]["problemStatistics"]

def extract_solvedCount(json):
    try:
        return int(json['solvedCount'])
    except KeyError:
        return 0


arr.sort( key = extract_solvedCount, reverse = True )

firefox_arguments = ""
count = 0

for problem in arr:
    filename = str( problem[ 'contestId' ] ) + str( problem[ 'index' ] ) + ".cpp"
    if not os.path.isfile(filename):
        firefox_arguments += " http://codeforces.com/problemset/problem/" + str( problem[ 'contestId' ] ) + "/" + str( problem[ 'index' ] )
        count += 1
        if count == 10:
            break

os.system( "firefox" + firefox_arguments )

