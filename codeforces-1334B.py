# https://codeforces.com/problemset/problem/1334/B
# B. Middle Class

T = int(input())
while T:
    n, x  = map(int, input().strip().split())
    savings = list(map(int, input().strip().split()))
    total_sum = sum(savings)
    savings.sort()
    idx = 0
    while n > idx and total_sum / (n - idx) < x:
        total_sum -= savings[idx]
        idx += 1
    print(n - idx)
    T -= 1

