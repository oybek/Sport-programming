
#!/bin/bash

if [[ $1 == "" ]];
then
	prob_id=$[1000+$RANDOM%1000]
else
	prob_id=$1
fi

lynx -dump "http://acm.timus.ru/problem.aspx?space=1&num=$prob_id&locale=ru" | ./format

