times = int(input())
for i in range(times):
    s1 = input()
    s2 = input()
    if s1 == s2:
        print("Yes")
    else:
        print("No")
    if i + 1 < times:
        input()
