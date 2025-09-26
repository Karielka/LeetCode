n, k = map(int, input().split())
mas = [int(x) for x in input().split()]
total = sum(mas)
mas_sorted = sorted(mas)
M = max(abs(mas_sorted[0]),mas_sorted[-1])
for i in range(min(k, n)):
    total += M - mas_sorted[i]
print(total)