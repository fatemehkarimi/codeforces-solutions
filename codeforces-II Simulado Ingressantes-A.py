#http://codeforces.com/gym/101744/my
# MaratonIME helps Pablito

from fractions import gcd

T = int(input())

while T > 0:
    T -= 1
    a, b = map(int, input().strip().split())

    if gcd(a, b) == 1:
        print("Nao")
    else:
        print("Sim")

