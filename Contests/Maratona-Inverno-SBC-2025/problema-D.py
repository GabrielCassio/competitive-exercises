n = int(input())
a = input().split(" ")
q = 0
for i in range(n):
    for j in range(n):
        if (i != j) and (abs(int(a[i]) - int(a[j])) == 1):
            print(f"({a[i]},{a[j]})")
            q += 1
q = q//2
print(q)