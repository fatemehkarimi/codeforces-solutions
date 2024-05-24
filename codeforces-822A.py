# https://codeforces.com/problemset/problem/822/A
# A. I'm bored with life

def factorial(n):
    if n == 1:
        return 1
    return n * factorial(n - 1)

a, b = map(int, input().split())
print(factorial(min(a, b)))

