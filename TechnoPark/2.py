word_count = int(input())
s = input()
mas = "order-66"
f = False
words = s.split()
for st in words:
    if len(st) == 8:
        st = st.lower()
        if sorted(mas) == sorted(st):
            f = True
        break
if f:
    print("Detected")
else:
    print("Not_Detected")