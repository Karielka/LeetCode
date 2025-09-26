# 1

# n = int(input())

# for i in range(n - 1):
#     s1 = input()
#     s2 = input()
#     if s1 == s2:
#         print("OK")
#     else:
#         print("WA")
#     input()

# s1 = input()
# s2 = input()
# if s1 == s2:
#     print("OK")
# else:
#     print("WA")


# 2

# input()
# words = input().split()
# order = sorted("order-66")
# f = False
# for st in words:
#     if len(st) == 8:
#         if sorted(st.lower()) == order:
#             f = True
# if f:
#     print("Detected")
# else:
#     print("Not_Detected")

# 3

# input()
# s = input()
# total = 0
# open_bracket_count = 0
# close_bracket_count = 0
# for st in s:
#     if st == "(":
#         open_bracket_count += 1
#     else:
#         close_bracket_count += 1
#     if open_bracket_count == close_bracket_count:
#         total += 1
#         open_bracket_count = 0
#         close_bracket_count = 0
# print((2 ** (total - 1) - 1) % (10 ** 9 + 7))


# 4

# n, k = map(int, input().split())
# data = [int(x) for x in input().split()]
# total = sum(data)
# mas = sorted(data)
# M = max(abs(mas[0]), mas[-1])
# for i in range(min(n,k)):
#     total += M - mas[i]
# print(total)


# 5

# def gcd(a,b):
#     while b:
#         a, b = b, a % b
#     return a
# input()
# data = [int(x) for x in input().split()]
# total = 0
# prev = {}
# for x in data:
#     cur = {}
#     cur[x] = cur.get(x, 0) + 1
#     for g, cnt in prev.items():
#         ng = gcd(x,g)
#         cur[ng] = cur.get(ng, 0) + cnt
#     for g, cnt in cur.items():
#         total += g * cnt
#     prev = cur
# print(total)















### Again

# n = int(input())
# for i in range(n):
#     s1 = input()
#     s2 = input()
#     if s1 == s2:
#         print("OK")
#     else:
#         print("WA")
#     if i + 1 < n:
#         input()



# input()
# s = input().split()
# order = sorted("order-66")
# f = False
# for word in s:
#     if len(word) == 8:
#         if sorted(word) == order:
#             f = True

# if f: print("Not_Detected") 
# else: print("Detected")


# input()
# s = input()
# open_bracket_count = 0
# close_bracket_count = 0
# total = 0

# for st in s:
#     if st == "(":
#         open_bracket_count += 1
#     else:
#         close_bracket_count += 1
#     if open_bracket_count == close_bracket_count:
#         open_bracket_count = 0
#         close_bracket_count = 0
#         total += 1
# print((2 ** (total - 1) -1) % (10 ** 9 + 7))


# n, k = map(int, input().split())
# data = sorted([int(x) for x in input().split()])
# total = sum(data)
# MAX = max(abs(data[0]), data[-1])
# for i in range(min(k,n)):
#     total += (MAX - data[i])
# print(total)


# def nod(a,b): 
#     while b:
#         a, b = b, a % b
#     return a

# input()
# data = [int(x) for x in input().split()]

# prev = {}
# total = 0

# for x in data:
#     cur = {}
#     cur[x] = cur.get(x, 0) + 1
#     for g, count in prev.items():
#         nigger = nod(x, g)
#         cur[nigger] = cur.get(nigger, 0) + count
#     for g, count in cur.items():
#         total += g * count
#     prev = cur
# print(total)