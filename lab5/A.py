import _heapq
def minimum_merge_cost(arr):
    _heapq.heapify(arr)

    total_cost = 0

    while len(arr) > 1:
        first = _heapq.heappop(arr)
        second = _heapq.heappop(arr)

        merge_cost = first + second
        total_cost += merge_cost

        _heapq.heappush(arr, merge_cost)

    return total_cost


n = int(input())
arr = list(map(int, input().split()))

print(minimum_merge_cost(arr))


