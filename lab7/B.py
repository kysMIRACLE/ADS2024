n = int(input().strip())
a = list(map(int, input().strip().split()))


m = int(input().strip())
b = list(map(int, input().strip().split()))

b.extend(a)

b.sort()

print(" ".join(map(str, b)))