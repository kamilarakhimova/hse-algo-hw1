import os
import csv
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import rcParams
rcParams['figure.figsize'] = 8, 8
rcParams['font.size'] = '16'

files = []
for file in os.listdir(r'TablesForGraphs'):
    files.append(file)

folder = "Graphs/"

for name in files:
    x = []
    y1 = []
    y2 = []
    y3 = []
    y4 = []
    y5 = []
    y6 = []
    y7 = []
    y8 = []
    y9 = []
    y10 = []
    y11 = []
    y12 = []
    y13 = []
    y14 = []
      
    with open(name,'r') as csvfile:
        lines = csv.reader(csvfile, delimiter=';')
        for row in lines:
            if (len(row) != 0):
              x.append(int(row[0]))
              y1.append(int(row[1]))
              y2.append(int(row[2]))
              y3.append(int(row[3]))
              y4.append(int(row[4]))
              y5.append(int(row[5]))
              y6.append(int(row[6]))
              y7.append(int(row[7]))
              y8.append(int(row[8]))
              y9.append(int(row[9]))
              y10.append(int(row[10]))
              y11.append(int(row[11]))
              y12.append(int(row[12]))
              y13.append(int(row[13]))
              y14.append(int(row[14]))
    
    plt.plot(x, y1, color = 'red', label = "Selection Sort")
    plt.plot(x, y2, color = 'blue', label = "Bubble Sort")
    plt.plot(x, y3, color = 'green', label = "Bubble Sort Iverson 1")
    plt.plot(x, y4, color = 'orange', label = "Bubble Sort Iverson 2")
    plt.plot(x, y5, color = 'purple', label = "Insertion Sort")
    plt.plot(x, y6, color = 'yellow', label = "Binary Insertion Sort")
    plt.plot(x, y7, color = 'pink', label = "Counting Sort")
    plt.plot(x, y8, color = 'orange', label = "Radix Sort")
    plt.plot(x, y9, color = 'cyan', label = "Merge Sort")
    plt.plot(x, y10, color = 'magenta', label = "Quick Sort (first support)")
    plt.plot(x, y11, color = 'black', label = "Quick Sort (middle support)")
    plt.plot(x, y12, color = 'orange', label = "Heap Sort")
    plt.plot(x, y13, color = 'brown', label = "Shell Sort (Ciur sequence)")
    plt.plot(x, y14, color = 'grey', label = "Shell Sort (Shell sequence)")
    
    plt.xlabel('Размер массива', fontweight="bold")
    if int(name[-5]) <= 2:
      plt.ylabel('Время, нс', fontweight="bold")
    else:
      plt.ylabel('Кол-во эл. оп.')
    plt.title(name[:-4:], fontsize = 20, fontweight="bold")
    plt.grid()
    plt.legend(bbox_to_anchor=(1, 0.6))
    plt.savefig(name[:-3:] + 'png')
