# https://codeforces.com/problemset/problem/399/A
# A. Pages

n, p, k = map(int, input().split())
lower, upper = max(1, p - k), min(n, p + k)
if lower != 1:
    result = '<<'
else:
    result = ''
for i in range(lower, upper + 1):
    if i == p:
        result += ' (' + str(i) + ')'
    else:
        result += ' ' + str(i)
if upper != n:
    result += ' >>'
print(result)

