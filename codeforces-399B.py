# https://codeforces.com/problemset/problem/399/B
# B. Red and Blue Balls

n = int(input())
input_str = input()
count_op = 0

count = 0
for c in input_str:
    if c == 'B':
        count_op += 2 ** count
    count += 1
print(count_op)

