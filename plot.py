import matplotlib.pyplot as plt  
import os
import sys

if len(sys.argv) != 2:
	print "Error: Wrong argument"
	sys.exit()

x_data = []
y_data = []

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
	plt.title(sys.argv[1])

plt.plot(x_data, y_data)  
plt.ylabel('Time(s)')  
plt.xlabel('Data Scale')  
plt.show()  
