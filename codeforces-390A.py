# https://codeforces.com/problemset/problem/390/A
# A. Inna and Alarm Clock

n = int(input())

vert = set()
hor = set()

for _ in range(n):
    x, y = map(int, input().split())
    vert.add(x)
    hor.add(y)

print(min(len(vert), len(hor)))

