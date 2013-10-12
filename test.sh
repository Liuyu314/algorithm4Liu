# !/bin/bash

#NumLen=(50000 100000 150000 200000 250000 300000)
NumLen=(100 1000 10000 100000 1000000 10000000)

if [ "$1" == "insertSort" ]; then
	if [ -f "data" ]; then
		echo "#data file" > "data"
	fi

	for ((i=0; i<6; ++i))  
	do  
		./genRandomNum ${NumLen[i]}
		make insertSort
		./insertSort >> data
	done  
	python plot.py insertSort
fi

if [ "$1" == "mergeSort" ]; then
	if [ -f "data2" ]; then
		echo "#data2 file" > "data2"
	fi

	for ((i=0; i<6; ++i))  
	do  
		./genRandomNum ${NumLen[i]}
		make mergeSort
		./mergeSort >> data2
	done  
	python plot.py mergeSort
fi
