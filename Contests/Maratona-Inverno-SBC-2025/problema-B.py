nm, val   = input().split(" "), input().split(" ")
nm[0], nm[1] = int(nm[0]), int(nm[1])

# Importância dos bairros
valsn = input().split(" ")

for _ in range(nm[1]):
    # Ruas que ligam os bairros u e v
    uv  = input().split(" ")
    uv[0], uv[1] = int(uv[0]), int(uv[1])

q = int(input())
for _ in range(q):
    
    valsq = input().split(" ")