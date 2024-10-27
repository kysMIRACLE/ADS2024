T = int(input().strip())

for _ in range(T):
    
    strings = input().strip().split()
    
   
    sorted_strings = sorted(strings, key=len)
    print(" ".join(sorted_strings))