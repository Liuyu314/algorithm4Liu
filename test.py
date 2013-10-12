# !/usr/bin/python
import os

f = open("data.txt", "w")

for i in [100000, 200000, 300000, 400000, 500000]:
	os.system("make generation")
	os.system("./generation ")
