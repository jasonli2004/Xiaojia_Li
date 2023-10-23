import puzzle8 as p8
from typing import List
import time

def iterative_deepening_search(state: int) -> List[int]:
    """Finds path to solution via iterative deepening. Returns a list of
    squares that the blank moves to in order to get to solution.
    """
    limit = 0
    result = 0
    timelst = []
    while True:
        begin = time.time()
        result = depth_limited_search(state, limit)
        if result != [99]:
            break
        limit += 1
        end = time.time()
        timelst = timelst + [end - begin]
    sum = 0
    print(timelst)
    for i in range(0,len(timelst)-1):
        sum = sum + timelst[i]
    print(sum,timelst.pop())
    return result

def depth_limited_search(state: int, limit: int) -> List[int]:
    if state == p8.solution():
        return []
    if limit == 0:
        return [99]
    blk = p8.blank_square(state)
    reachable = p8.neighbors(blk)
    for i in reachable:
        newState = p8.move_blank(state, i)
        path = depth_limited_search(newState, limit - 1)
        if path != [99]:
            return [i] + path
    return [99]

print(iterative_deepening_search(247860748))