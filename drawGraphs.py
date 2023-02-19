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
      
    with open(name,'r') as csvfile:
        lines = csv.reader(csvfile, delimiter=';')
        for row in lines:
            if (len(row) != 0):
              x.append(int(row[0]))
              y1.append(int(row[1]))
              y2.append(int(row[2]))
              y3.append(int(row[3]))
              y4.append(int(row[4]))
    
    plt.plot(x, y1, color = 'red', label = "от 0 до 5")
    plt.plot(x, y2, color = 'blue', label = "от 0 до 4000")
    plt.plot(x, y3, color = 'green', label = "почти отсортирован")
    plt.plot(x, y4, color = 'orange', label = "обратно отсортирован")
    
    plt.xlabel('Размер массива', fontweight="bold")
    if int(name[-5]) <= 2:
      plt.ylabel('Время, нс', fontweight="bold")
    else:
      plt.ylabel('Кол-во эл. оп.')
    plt.title(name[:-4:], fontsize = 20, fontweight="bold")
    plt.grid()
    plt.legend(bbox_to_anchor=(1, 0.6))
    plt.show()
    plt.savefig(folder + name[:-3:] + 'png')
