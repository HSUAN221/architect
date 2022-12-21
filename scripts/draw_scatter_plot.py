import numpy as np
import matplotlib.pyplot as plt
import sys

system_arg = sys.argv
label_file = system_arg[1]

#------------------------parser for input
txt_name = label_file
fread = open(txt_name,'r')
f = fread.read().split("\n")

# Create data
N = 500
x = np.random.rand(N)
y = np.random.rand(N)
colors = (0,0,0)
area = np.pi*3

# # Plot
# plt.scatter(x, y, s=area, c=colors, alpha=0.5)
# plt.title('Scatter plot pythonspot.com')
# plt.xlabel('x')
# plt.ylabel('y')
# plt.show()
