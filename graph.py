from __future__ import division
import numpy
import matplotlib.pyplot as pyplot

data = numpy.zeros((1,4))

with open("C:\msys64\home\Connor\Bunny Simulator\Turn stats.txt") as stats_file:
    contents_list = [word for line in stats_file for word in line.split()]
    file_lines = int(len(contents_list)/4)
array_temp = numpy.zeros((file_lines-1,4))
for i in range(file_lines-1):
    for k in range(4):
        array_temp[i,k] = int(contents_list[(i*4)+k+4])
data = numpy.append(data, array_temp, axis = 0)
data = data[1:,:]

turns = numpy.zeros(file_lines-1)
for i in range(file_lines-1):
    turns[i] = i+1
totals = data[:,0]
males = data[:,1]
females = data[:,2]
infected = data[:,3]

pyplot.figure()
pyplot.plot(turns, totals, color='red')
pyplot.plot(turns, males, color='blue')
pyplot.plot(turns, females, color='pink')
pyplot.plot(turns, infected, color='black')
pyplot.title('Bunny count')
pyplot.xlabel('Turns')
pyplot.ylabel('Number of bunnies')
pyplot.show()