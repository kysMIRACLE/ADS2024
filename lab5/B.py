import heapq

def last_stone_weight(stones):
   
    stones = [-s for s in stones]
    heapq.heapify(stones)
    
    
    while len(stones) > 1:
       
        first = -heapq.heappop(stones)
        second = -heapq.heappop(stones)
        
        
        if first != second:
            heapq.heappush(stones, -(first - second))
    
    
    return -stones[0] if stones else 0


n = int(input())  
stones = list(map(int, input().split()))  # Weights of the stones


print(last_stone_weight(stones))