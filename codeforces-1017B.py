# https://codeforces.com/problemset/problem/1017/B
# B. The Bits
from collections import defaultdict

n = int(input())
num1 = input()
num2 = input()

dict = defaultdict(int)

for x, y in zip(num1, num2):
    dict[x] += 1
    dict[(x, y)] += 1


result = dict[('0', '0')] * dict['1'] + dict[('0', '1')] * dict[('1', '0')] \
        + dict[('1', '0')] * dict['0'] + dict[('1', '1')] * dict[('0', '0')]
print(result // 2)

