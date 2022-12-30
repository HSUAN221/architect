import numpy as np
import matplotlib.pyplot as plt
import sys
from itertools import cycle

system_arg = sys.argv
label_file = system_arg[1]

#------------------------parser for input
txt_name = label_file
fread = open(txt_name,'r')
N = 500
x = []
y = []
idx = list(zip(x, y))
dict = {}
temp = 0
while True:
    line = fread.readline()
    if not line:
        break
    f = line.strip().split(" ")

    if len(f) == 2:
        idx.append((f[0], f[1]))
    elif len(f) == 1:
        print(temp)
        dict[temp] = list()
        for i in idx:
            print(i)
            dict[temp].append(i)
        idx.clear()
        temp = int(f[0])


fig = plt.figure()
cycol = cycle('bgrcmk')
for key in dict:
    if key == 63:
        x, y = zip(*dict[key])
        area = np.pi*10
        # plt.xticks(range(len(x)), x, rotation=90)
        plt.scatter(y, x, s=area, c=next(cycol), alpha=0.5)
        plt.title('void')
        plt.xlabel('x')
        plt.ylabel('y')


png_name = sys.argv[2] 
plt.savefig(png_name)

# plt.scatter(x, y, s=area, c=colors, alpha=0.5)
# plt.title('Scatter plot pythonspot.com')
# plt.xlabel('x')
# plt.ylabel('y')
# plt.show()
