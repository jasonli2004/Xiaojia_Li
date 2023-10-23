import puzzle8 as p8
from typing import List
import time

def iterative_deepening_search(state: int) -> List[int]:
    limit = 0
    # last = time.time()
    # start = last
    while True:
        # print("iteration", limit, time.time() - last, time.time() - start)
        last = time.time()
        ans = dfs(state, 0, limit, p8.solution())
        if ans != None:
            return ans
        limit += 1

def dfs(curr: int, depth: int, limit: int, target: int) -> List[int]:
    ans = None
    if curr == target:
        return []
    if depth == limit:
        return None
    blk = p8.blank_square(curr)
    reachable = p8.neighbors(blk)
    for i in reachable:
        newState = p8.move_blank(curr, i)
        result = dfs(newState, depth+1, limit, target)
        if result != None:
            result = [i] + result
            ans = result
    return ans

print(iterative_deepening_search(247860748))
print(iterative_deepening_search(253206748))
print(iterative_deepening_search(253780508))
print(iterative_deepening_search(152293420))


