#!/bin/bash

echo "(~˘▾˘)~"
echo "today you solved $(stat -c %y *.cpp | grep -c $(date +%Y-%m-%d) ) problems"
echo "yesterday you solved $(stat -c %y *.cpp | grep -c $(date +%Y-%m-%d -d '1 day ago') ) problems"
echo "2 days ago you solved $(stat -c %y *.cpp | grep -c $(date +%Y-%m-%d -d '2 days ago') ) problems"

