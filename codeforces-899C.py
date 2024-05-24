#https://codeforces.com/problemset/problem/899/C
#C. Dividing the numbers

import math

n = int(input())
sum = n * (n + 1) / 2
sum1 = math.ceil(sum / 2)
sum2 = math.floor(sum / 2)

diff = abs(sum1 - sum2)

group1 = []

for i in range(n, 0, -1):
    if sum1 - i == 0:
        group1.append(i)
        break
    elif sum1 - i > 0:
        sum1 -= i
        group1.append(i)
        
print(diff)
print(len(group1), end=' ')
for num in group1:
    print(num, end=' ')
print("")
