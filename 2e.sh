echo 'enter limit'
read lim
a=0
b=1
i=0
echo 'The series is: '
echo $a
echo $b
while [ $i -lt $(expr $lim - 2) ]
	do
		c=$(expr $a \+ $b)
		a=$b
		b=$c
		i=$(expr $i + 1)
		echo $c
	done

