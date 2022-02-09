import matplotlib.pyplot as mat
import math
f = open("sample.txt", "r")
cm = []
numct = []
for x in range(30):
    n = f.readline()
    n = n[:-2]
    n = n.split(",")
    numct.append(len(n))
    for y in range(numct[x]):
        n[y] = int(n[y])
        cm.append(0)
    for z in range(1, numct[x]):
        k = n[z]
        u = z-1
    while(u >= 0 and n[u] > k):
        cm[x] += 1
        n[u+1] = n[u]
        u -= 1
print("Case ", x+1, ":")
print("Total numbers: ", numct[x])
print("Total comparisons: ", cm[x])
print("Sorted array: ", n, "\n")
f.close()
mat.scatter(numct, cm)
mat.xlabel("No. of elements in array")
mat.ylable("No. of comparisions")
