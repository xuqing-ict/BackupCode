#!/bin/sh
#!/bin/bash

echo "IN shell!!!"

i=1
while getopts "1:2:t:" arg
do
	case $arg in
		1)
		read_file_name1=$OPTARG
		echo $read_file_name1
		;;
		2)
		read_file_name2=$OPTARG
		echo $read_file_name2
		;;
		t)
		training=$OPTARG
		echo $training
		;;
		?)
		echo "Invalid parameter!!!"
	exit 1
	;;
	esac
done

#do
#	if [ "${$i}" == "-1" ]
#	then
#		let i=$i+1
#		readfile1=${$i}
#		echo $readfile1
#	elif [ ${$i} == '-2' ]
#	then 
#		let i=$i+1
#		readfile2=${$i}
#	else
#		echo "Invalid parameter!!!"
#	fi
#	let i=$i+1
#done
#BLOCK


echo $read_file_name1
echo $read_file_name2

echo $trainingfile

./a.out 
./perm10K $training -v 10 -a -1 $read_file_name1 -2 $read_file_name2 -s $training.index -o $training.sam
echo "perm10K end..."
