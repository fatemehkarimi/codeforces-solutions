# https://codeforces.com/problemset/problem/393/A
# A. Nineteen

str = input()
counts = {'n': 0, 'i': 0, 'e': 0, 't': 0}

for c in str:
    if c in 'niet':
        counts[c] += 1

ans = len(str)
for c, v in counts.items():
    if c == 'n':
        if not (v % 2):
            v -= 1
        v = int(v / 2)
    elif c == 'e':
        v = int(v / 3)
    ans = min(ans, v)

print(ans)

