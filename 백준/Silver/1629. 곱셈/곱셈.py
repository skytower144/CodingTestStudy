from sys import stdin
input = stdin.readline

def multiply(n,x):
  global c
  if x == 0:
    return 1
  temp = multiply(n,x//2)
  if x % 2 == 0:
    return (temp * temp) % c
  elif x % 2 == 1:
    return (n * temp * temp) % c

a,b,c = map(int,input().split())
print(multiply(a,b))