# https://codeforces.com/problemset/problem/1334/A
# A. Level Statistics

T = int(input())
while T:
    valid = True
    n = int(input())
    games, clears = 0, 0
    for _ in range(n):
        a, b = map(int, input().split())
        d1, d2 = (a - games), (b - clears)
        if a < b or a < games or b < clears or d1 < d2:
            valid = False
        games, clears = a, b
    print("YES" if valid else "NO")
    T -= 1

