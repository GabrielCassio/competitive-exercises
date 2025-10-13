qt = int(input()) # Quantidade test cases
for _ in range(qt):
    i = input().split(" ") # Recebe 3 valores
    x, y, z = int(i[0]), int(i[1]), int(i[2])
    if ( (x & y & ~z) == 0 and (x & z & ~y) == 0 and (y & z & ~x) == 0):
        print("YES")
    else:
        print("NO")