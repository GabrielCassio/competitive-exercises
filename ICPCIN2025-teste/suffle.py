n =  0
order = []
cowOrder = []

with open('shuffle.in', 'r') as fin:
    n = int(fin.readline())
    order = [int(i.strip("\n")) for i in fin.readline().split(" ")]
    cowOrder = [i.strip("\n") for i in fin.readline().split(" ")]

for _ in range(3):
    anteriorOrder = [0]*n
    for i in range(n):
        anteriorOrder[i] = cowOrder[order[i]-1]
    cowOrder = anteriorOrder
cowOrder = anteriorOrder

with open('shuffle.out', 'w') as fout:
    for cowID in range(n):
        fout.write(str(cowOrder[cowID])+"\n")
