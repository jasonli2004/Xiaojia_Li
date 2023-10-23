import puzzle8 as p8
from typing import List
import heapq

def num_wrong_tiles(state) -> int:
    """Given a puzzle, returns the number of tiles that are in the wrong
    location. Does not count the blank space.
    """
    cnt = 0
    sol = p8.solution()
    for i in range(0,9):
        tile = p8.get_tile(state, i) 
        if (tile != 0 and tile != p8.get_tile(sol, i)):
            cnt += 1
    return cnt


def manhattan_distance(state) -> int:
    """Given a puzzle, returns the Manhattan distance to the solution state.
    Does not count the distance from blank space to its correct location as
    part of the distance.
    """
    correct = [(1,1),(0,0),(0,1),(0,2),(1,2),(2,2),(2,1),(2,0),(1,0)]
    dis = 0
    for i in range(0,9):
        tile = p8.get_tile(state, i)
        y, x = correct[tile]
        a, b = p8.xy_location(i)
        if (tile != 0):
            dis = dis + abs(x - a) + abs(y - b)
    return dis


def astar_search(state: int, heuristic) -> List[int]:
    """Finds path to solution via A* search, using the provided heuristic.
    Returns a list of squares that the blank moves to in order to get to
    solution.
    """
    frontier = []
    path = []
    heapq.heappush(frontier,(heuristic(state), 0, state, path))
    while (len(frontier)!= 0):
        fn, gn, curr, currpath = heapq.heappop(frontier)
        if curr == p8.solution():
            return currpath
        blk = p8.blank_square(curr)
        reachable = p8.neighbors(blk)
        for i in reachable:
            newState = p8.move_blank(curr, i) 
            hn = heuristic(newState) #obtaining h(n)
            cpy = currpath.copy() #creating a copy of the parent path 
            cpy.append(i)
            heapq.heappush(frontier, (hn + gn + 1, gn + 1 , newState, cpy)) #since the cost for every action is one, we just add 1 to g(n)
    return [] 

print(astar_search(247860748, num_wrong_tiles))