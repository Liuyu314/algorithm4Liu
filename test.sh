# !/bin/bash

#NumLen=(50000 100000 150000 200000 250000 300000)
NumLen=(100 1000 10000 100000 1000000 10000000)

PRE="data_"
BIN="./bin/"
EXEC=$BIN$1
if [ -f "data" ]; then
	echo "#data file" > "data"
fi

for ((i=0; i<6; ++i))
do
	$EXEC $PRE${NumLen[i]} >> data
done  
	python plot.py $1
