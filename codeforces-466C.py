#https://codeforces.com/contest/466/problem/C
#C. Number of Ways

n = int(input())
nums = [int(x) for x in input().strip().split()]

sum = 0
for x in nums:
    sum += x

if sum % 3 != 0:
    print(0)
    exit()

sum /= 3
t = 0
ct = 0
res = 0
for i in range(0, n - 1):
    t += nums[i]
    if t == 2 * sum:
        res += ct
    if t == sum:
        ct += 1

print(res)

