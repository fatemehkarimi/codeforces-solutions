# https://codeforces.com/problemset/problem/394/A
# A. Counting Sticks

input_str = input()
b1, b2, b3 = 0, 0, 0
in_b1, in_b2 = True, False

for x in input_str:
    if x == '|':
        if in_b1:
            b1 += 1
        elif in_b2:
            b2 += 1
        else:
            b3 += 1
    elif x == '+':
        in_b1, in_b2 = False, True
    else:
        in_b2 = False

if b1 + b2 == b3:
    pass
elif b1 + b2 == b3 + 2:
    if b1 > 1:
        b1 -= 1
    else:
        b2 -= 1
    b3 += 1
elif b1 + b2 + 2 == b3:
    b2 += 1
    b3 -= 1
else:
    print("Impossible")
    exit()

print('|' * b1 + '+' + '|' * b2 + '=' + b3 * '|')

