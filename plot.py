import matplotlib.pyplot as plt  
import os
import sys

if len(sys.argv) != 2:
	print "Error: Wrong argument"
	sys.exit()

x_data = []
y_data = []

if sys.argv[1] == "insertSort":
	if not os.path.exists("data"):
		print "Error: Missing data file"
		sys.exit()
	else:
		f = open("data", "r")
		while True:
			line = f.readline()
			if len(line) == 0:
				break
			if not line.startswith('#'):
				y_data.append(line.split(',')[0])
				x_data.append(line.split(',')[1])
	f.close()
	plt.title("Insert Sort")

if sys.argv[1] == "mergeSort":
	if not os.path.exists("data2"):
		print "Error: Missing data2 file"
		sys.exit()
	else:
		f = open("data2", "r")
		while True:
			line = f.readline()
			if len(line) == 0:
				break
			if not line.startswith('#'):
				y_data.append(line.split(',')[0])
				x_data.append(line.split(',')[1])
	f.close()
	plt.title("Merge Sort")

plt.plot(x_data, y_data)  
plt.ylabel('Time(s)')  
plt.xlabel('Data Scale')  
plt.show()  
