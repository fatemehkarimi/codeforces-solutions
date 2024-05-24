# https://codeforces.com/problemset/problem/397/A
# A. On Segment's Own Points

n = int(input())
rope = [True] * 100
x1, y1 = map(int, input().split())

for _ in range(1, n):
    x , y = map(int, input().split())
    for i in range(x, y):
        rope[i] = False

total_len = sum(rope[x1:y1])
print(total_len)

