echo 'enter num'
read a
echo 'enter num'
read b
echo 'enter num'
read c
if [ $a -gt $b  ]
	then
	if [ $a -gt $c ]
		then
			echo $a' is greater'
		else
			echo $c' is greater'
	fi
	else
	if [ $b -gt $c ]
		then
			echo $b' is greater'
		else
			echo $c' is greater'
	fi
fi
