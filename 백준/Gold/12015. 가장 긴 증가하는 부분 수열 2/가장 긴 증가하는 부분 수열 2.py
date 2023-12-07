from sys import stdin
input = stdin.readline

n = int(input())
numlist = list(map(int,input().split()))
C = [numlist[0]]

def findSpot(target,left,right):
  while left<=right:
    mid = (left + right)//2
    if C[mid] < target:
      left = mid + 1
    else:
      right = mid - 1
  return left

for i in range(1,n):
  if C[-1]<numlist[i]:
    C.append(numlist[i])
  else:
    idx = findSpot(numlist[i],0,len(C)-1)
    C[idx] = numlist[i]


print(len(C))