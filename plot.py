import matplotlib.pyplot as plt  
import os

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

plt.title("Insert Sort")
plt.plot(x_data, y_data)  
plt.ylabel('Time(s)')  
plt.xlabel('Data Scale')  
plt.show()  
