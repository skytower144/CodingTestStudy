from sys import stdin
input = stdin.readline

n,m = map(int,input().split())
trees = list(map(int,input().split()))
left = 0
right = max(trees)

while left<=right:
    mid = (left+right)//2
    ct = 0
    flag = False
    for t in trees:
        if t>mid:
            ct += t-mid
        if ct>=m:
            flag = True
            break
    if flag:
        left = mid + 1
    else:
        right = mid - 1

print(right)