
read c

if [[ $c =~ y|Y ]];
then
	echo "YES"
elif [[ $c =~ n|N ]];
then
	echo "NO"
fi
