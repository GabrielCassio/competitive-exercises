import sys
textInput = sys.stdin.readlines()
textInput = [[int(j[i][0]), int(j[1])] for i in range(len(textInput)) for j in textInput[i].split(" ")]

print(textInput)