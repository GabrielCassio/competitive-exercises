numInput = int(input())
lineInt  = [int(i) for i in input().split(" ")]
total    = (numInput*(numInput+1))//2
print(total - sum(lineInt))