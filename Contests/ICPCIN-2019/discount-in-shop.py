t = int(input())

for _ in range(t):  
    n = list(input())
    id = None
    for d in range(len(n)):
        if (d+1) < len(n):
            if int(n[d]) > int(n[d+1]): 
                id = d
                break
    if id is not None:
        n.pop(id)
        n = "".join(n)
    else: n = 1
    print(n)
