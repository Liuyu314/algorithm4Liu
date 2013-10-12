# !/bin/bash

NumLen=(50000 100000 150000 200000 250000 300000)

if [ -f "data" ]; then
	echo "#data file" > "data"
fi

for ((i=0; i<6; ++i))  
do  
	./genRandomNum ${NumLen[i]}
	make
	./insertSort >> data
done  
	python plot.py
