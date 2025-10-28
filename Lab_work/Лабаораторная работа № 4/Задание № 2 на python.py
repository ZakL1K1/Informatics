a = set(map(int, input('Vedite chisla dli mnojestva A:').split()))
b = set(map(int, input('Vedite chisla dli mnojestva B:').split()))
print({x for x in a & b if x % 3 == 0})