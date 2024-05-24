# https://codeforces.com/problemset/problem/1145/A
# A. Thanos Sort

from queue import Queue

n = int(input())
queue = Queue()
queue.put(list(map(int, input().split())))
while not queue.empty():
    nums = queue.get()
    if sorted(nums) == nums:
        result = nums
        break
    l = len(nums)
    p1, p2 = nums[:int(l/2)], nums[int(l/2):]
    queue.put(p1)
    queue.put(p2)

print(len(result))

