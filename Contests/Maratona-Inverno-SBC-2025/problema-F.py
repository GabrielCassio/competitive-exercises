abk = input().split(" ")

def fibonacci(a, b, k):
    c = (b + 1) ^ a
    if (k > 0):
        ret = fibonacci(b, c, k - 1)
        if (ret != None): return ret
    else:
        return c

if (int(abk[2]) == 1): print(int(abk[0]))
elif (int(abk[2]) == 2): print(int(abk[1]))
else:
    print(fibonacci(int(abk[0]), int(abk[1]), int(abk[2])))