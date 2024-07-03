echo 'enter num'
read a
echo 'enter num'
read b
if [ $a -gt $b ]
	then
		echo $a\ 'is greater'
	else
		echo $b\ 'is greater'
fi
