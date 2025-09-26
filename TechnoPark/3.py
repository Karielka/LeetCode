t = input()
s = input()
count = 0
open_braket_count = 0
close_braket_count = 0
for sym in s:
    if sym == "(":
        open_braket_count += 1
    else:
        close_braket_count += 1
    if open_braket_count == close_braket_count:
        count += 1
        open_braket_count = 0
        close_braket_count = 0
print((2 ** (count - 1) - 1) % (10 ** 9 + 7))