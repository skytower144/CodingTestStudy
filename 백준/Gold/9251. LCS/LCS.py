from sys import stdin
input = stdin.readline

s1 = input().strip()
s2 = input().strip()
a = len(s1)
b = len(s2)

chart = [[0 for _ in range(a+1)] for _ in range(b+1)]

for i in range(b):
  for j in range(a):
    if s2[i] == s1[j]:
      chart[i+1][j+1] = chart[i][j] + 1
    else:
      chart[i+1][j+1] = max(chart[i][j+1],chart[i+1][j])

print(chart[-1][-1])