
read a
read b
read c

if (( $a == $b ));
then
	if (( $b == $c ));
	then
		echo "EQUILATERAL"
	else
		echo "ISOSCELES"
	fi
elif (( $b == $c ));
then
	if (( $a == $b ));
	then
		echo "EQUILATERAL"
	else
		echo "ISOSCELES"
	fi
else
	echo "SCALENE"
fi

