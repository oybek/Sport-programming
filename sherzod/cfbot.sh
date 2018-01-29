#!/bin/bash

user_name=oybek
user_name_2=sherzod_

bot_token="395620033:AAEVwL8tQu8ORUk9SHqpbzaT75gcXsWQUqw"
group_id="-1001238879443"

while :
do
	json=`curl -s "http://codeforces.com/api/user.status?handle=${user_name}&from=1&count=1"`
	verdict=`echo ${json} | python -c 'import json,sys;obj=json.load(sys.stdin);print obj["result"][0]["verdict"]'`
	test_num=`echo ${json} | python -c 'import json,sys;obj=json.load(sys.stdin);print obj["result"][0]["passedTestCount"]'`
	name=`echo ${json} | python -c 'import json,sys;obj=json.load(sys.stdin);print obj["result"][0]["problem"]["name"]'`
	time=`echo ${json} | python -c 'import json,sys;obj=json.load(sys.stdin);print obj["result"][0]["creationTimeSeconds"]'`
	lang=`echo ${json} | python -c 'import json,sys;obj=json.load(sys.stdin);print obj["result"][0]["programmingLanguage"]'`

	if [ "$time" != "$prev_time_oybek" ];
	then
		curl -s -X POST https://api.telegram.org/bot${bot_token}/sendMessage -d chat_id=${group_id} -d text="Name: *$user_name*%0AProblem: *$name*%0AVerdict: \`$verdict\`%0ALanguage: *$lang*" -d parse_mode="markdown" 
	fi

	prev_time_oybek=${time}

	json=`curl -s "http://codeforces.com/api/user.status?handle=${user_name_2}&from=1&count=1"`
	verdict=`echo ${json} | python -c 'import json,sys;obj=json.load(sys.stdin);print obj["result"][0]["verdict"]'`
	test_num=`echo ${json} | python -c 'import json,sys;obj=json.load(sys.stdin);print obj["result"][0]["passedTestCount"]'`
	name=`echo ${json} | python -c 'import json,sys;obj=json.load(sys.stdin);print obj["result"][0]["problem"]["name"]'`
	time=`echo ${json} | python -c 'import json,sys;obj=json.load(sys.stdin);print obj["result"][0]["creationTimeSeconds"]'`
	lang=`echo ${json} | python -c 'import json,sys;obj=json.load(sys.stdin);print obj["result"][0]["programmingLanguage"]'`

	if [ "$time" != "$prev_time_sherzod" ];
	then
		curl -s -X POST https://api.telegram.org/bot${bot_token}/sendMessage -d chat_id=${group_id} -d text="Name: *$user_name_2*%0AProblem: *$name*%0AVerdict: \`$verdict\`%0ALanguage: *$lang*" -d parse_mode="markdown" 
	fi

	prev_time_sherzod=${time}

	sleep 10
done

