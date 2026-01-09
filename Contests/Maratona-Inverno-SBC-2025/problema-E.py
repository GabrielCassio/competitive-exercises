lr = input().split(" ")

# Apliacando recursão
def termicEquilibrium(pd, l, r):
    pd *= l
    if (l < r):
        ret = termicEquilibrium(pd, l + 1, r)
        if (ret != None): return ret
    else:
        return pd

val = termicEquilibrium(1, int(lr[0]), int(lr[1]))
if (val >= 0): print("Y")
else: print("N")
