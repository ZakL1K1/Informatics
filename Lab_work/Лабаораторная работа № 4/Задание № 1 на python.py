from functools import reduce
a = list(map(lambda x: int(x), input("Masive A, vedite 5 chisel:").split()))
b = list(map(lambda x: int(x), input("Masive B, vedite 4 chisla:").split()))
if reduce(lambda x, y: x * y, a) > reduce(lambda x, y: x * y, b):
    print(f"Masive B: {b}\nMasive A: {a}")
else:
    print(f"Masive A: {a}\nMasive B: {b}")