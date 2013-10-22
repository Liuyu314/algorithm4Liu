# !/bin/bash
# generate the file including random number

#NumLen=(50000 100000 150000)
NumLen=(50000 100000 150000 200000 250000 300000)
#NumLen=(100 1000 10000 100000 1000000 10000000)

PRE="data_"

echo $FILE${NumLen[0]}
for ((i=0; i<6; ++i))
do
	FILE=$PRE${NumLen[i]}
	if [ -f $FILE ]; then
		echo "#data file" > $FILE
	fi
	./genRandomNum ${NumLen[i]} $FILE
done
