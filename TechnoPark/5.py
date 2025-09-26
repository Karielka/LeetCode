def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


input()
a = list(map(int, input().split()))


total = 0
prev = {} 

for x in a:
    cur = {}
    cur[x] = cur.get(x, 0) + 1
    for g, count in prev.items():
        nigger = gcd(g, x)
        cur[nigger] = cur.get(nigger, 0) + count
    for g, count in cur.items():
        total += g * count
    prev = cur
print(total)
