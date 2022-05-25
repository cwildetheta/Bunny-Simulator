from __future__ import division
import numpy
import matplotlib.pyplot as pyplot
import os

file_list = [file for file in os.listdir("C:\msys64\home\Connor\Bunny Simulator\output") if file.endswith('stats.txt')]

os.chdir('output')

pyplot.figure()
for file in file_list:
    with open(file) as stats_file:
        contents_list = [word for line in stats_file for word in line.split()]
        file_lines = int(len(contents_list)/4)
    data = numpy.zeros((file_lines-1,4))
    for i in range(file_lines-1):
        for k in range(4):
            data[i,k] = int(contents_list[(i*4)+k+4])
    turns = numpy.zeros(file_lines-1)
    for i in range(file_lines-1):
        turns[i] = i+1
    totals = data[:,0]
    #males = data[:,1]
    #females = data[:,2]
    #infected = data[:,3]
    pyplot.plot(turns, totals)
    #pyplot.plot(turns, males, color='blue')
    #pyplot.plot(turns, females, color='pink')
    #pyplot.plot(turns, infected, color='black')
pyplot.title('Bunny count')
pyplot.xlabel('Turns')
pyplot.ylabel('Number of bunnies')
pyplot.show()