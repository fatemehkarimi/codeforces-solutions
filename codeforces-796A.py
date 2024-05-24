# https://codeforces.com/problemset/problem/796/A
# A. Buying A House

n, m, k = map(int, input().split())
houses = list(map(int, input().split()))

m -= 1
best_house = -1

for i, v in enumerate(houses):
    if v != 0 and v <= k:
        if best_house == -1:
            best_house = i
        elif abs(best_house - m) > abs(i - m):
            best_house = i
print(abs(best_house - m) * 10)

