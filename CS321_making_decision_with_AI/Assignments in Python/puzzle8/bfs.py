import puzzle8 as p8
from typing import List
from collections import deque

def breadth_first_search(state: int) -> List[int]:
    """Finds path to solution via breadth-first search. Returns a list of
    squares that the blank moves to in order to get to solution.
    """
    curr = state
    currpath = deque() 
    path = deque([deque()])
    frontier = deque([state]) 
    explored = deque() #anything related to "explored" can be deleted if we want to result in infinite loops when there's no solution
    while (len(frontier)!= 0):
        curr = frontier.popleft()
        currpath = path.popleft()
        if curr == p8.solution():
            return currpath
        explored.append(curr)
        blk = p8.blank_square(curr)
        reachable = p8.neighbors(blk)
        for i in reachable:
            newState = p8.move_blank(curr, i)
            if (explored.count(newState) == 0 and frontier.count(newState)==0): #check whether the state is already in the frontier or it's explored, if it is, then we do not add it to the frontier
                frontier.append(newState)
                cpy = currpath.copy() #creating a copy of the parent path 
                cpy.append(i)
                path.append(cpy)
    return [] #return an empty list if there's no solution
    raise NotImplementedError("You must implement this method")

