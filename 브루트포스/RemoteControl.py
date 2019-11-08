n = int(input())
m = int(input())

broken = [False] * 10
if m > 0:
    mList = list(map(int,input().split()))
else:
    mList = []

for x in mList:
    broken[x] = True

def possible(c):
    if c == 0:
        if broken[0]: return 0
        else: return 1
    len = 0
    while c > 0:
        if broken[c % 10]: return 0
        len += 1
        c //= 10
    return len

ans = abs(n - 100)
for i in range(0, 1000000 + 1):
    c = i
    len = possible(c)
    if len > 0:
        press = abs(c - n)
        if ans > len + press: ans = len + press
print(ans)
