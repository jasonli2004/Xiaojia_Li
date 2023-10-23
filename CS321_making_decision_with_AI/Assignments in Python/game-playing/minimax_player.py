"""Minimax game player. You should modify the choose_move code for the
finimaxPlayer class. You should also modify the heuristic function, which
should return a number indicating the value of that board position.

Feel free to add additional helper methods or functions.
"""

from __future__ import annotations
from game_board import GameBoard, Location
from common_values import (
    EMPTY, MAX_PLAYER, MIN_PLAYER, RED, RED_MARKER, YELLOW, YELLOW_MARKER,
    COLOR_NAMES)
from typing import Optional, Callable
from player import Player
from typing import Optional, List


def sum_neighbours(board, location, piece) -> int:
    '''Counts the number of friendly pieces that are orthogonal or diagonal
    to the provided location.'''
    row = location.row
    col = location.column
    numAdjacentFriendlies = 0
    for rowIncrement in [-1, 0, 1]:
        for colIncrement in [-1, 0, 1]:
            if rowIncrement == 0 and colIncrement == 0:
                continue
            if board.grid[row + rowIncrement][col + colIncrement] == piece:
                numAdjacentFriendlies += 1
    return numAdjacentFriendlies

def get_value_at(board, location, piece) -> float:
        ''' Returns the value of the square at this location'''
        row = location.row
        col = location.column

        # If there is already some piece there the potential is always 0
        if board.grid[row][col] != EMPTY:
            return 0

        if piece == MAX_PLAYER:
            piece = RED
        else:
            piece = YELLOW

        friends = sum_neighbours(board,location, piece)
        if friends == 1:
            return 1/3
        if friends >= 2:
            return 1
        return 0

# Grid squares that only have one valid adjacent have a value of 1/3
# if it has at least two adjacents it has a value of 1 
def get_value_board(board, piece) -> float:
    """Returns the sum of the values at each element of the board,
       the total value roughly represents the number of total potential points of a player
    """

    value = 0
    for row in range(1, board.size+1):
        for column in range(1, board.size+1):
            location = Location(row, column)
            value += get_value_at(board, location, piece)
    return value

def heuristic(board: GameBoard) -> float:
    """Measure the value of the game board, where a high number means that is
    good for the max player, and a low number means that it is good for the min
    player. The maximum possible value should be 1, which is the value that
    should be returned if the board supplied is a guaranteed win for the max
    player. Likewise, the minimum possible value should be a -1, which is a
    guaranteed win for the min player.

    (The textbook indicates at some point in passing that this heuristic should
    range from 0 to 1, but there's no theoretical reason for 0 as opposed to -1
    for the bottom end, and the asymmetry just makes everything more
    complicated. What does matter is that the heuristic value for a
    non-terminal state should never be bigger in magnitude than that for an
    terminal state, because that would suggest that it the non-terminal state
    is more conclusive than a terminal state (which it can't be).
    """

    if board.is_terminal():
        return board.value()

    sum = get_value_board(board,MAX_PLAYER) - get_value_board(board,MIN_PLAYER) 
    magnitude = board.size**2
    # return math.tanh((sum/(2*board.size))) #scale to -1 to 1 in a non-linear way
    return sum/magnitude # scale to [-1, 1]


class MinimaxPlayer(Player):
    """Minimax player: uses minimax to find the best move."""

    def __init__(self,
                 heuristic: Callable[[GameBoard], float],
                 plies: int) -> None:
        self.heuristic = heuristic
        self.plies = plies
        self.called = 0
    def numcalled(self):
        return self.called

    def get_best(self, board: GameBoard, depth: int) -> List[int, Location]:
        if depth == 0 or board.is_terminal():
            self.called += 1
            return self.heuristic(board), None
        
        player = board.get_active_player()
        ans = -1 if player == MAX_PLAYER else 1 # starts with the worst possible answer for the player
        best_move = None

        for move in board.get_legal_moves():
            new_board = board.make_move(move)
            here, next_move = self.get_best(new_board, depth-1)
            if player == MAX_PLAYER:
                if here > ans:
                    ans = here
                    best_move = move
            else:
                if here < ans:
                    ans = here
                    best_move = move

        return ans, best_move

    def choose_move(self, board: GameBoard) -> Optional[Location]:
        # print("VALUE", self.heuristic(board))

        ans, best_move = self.get_best(board, self.plies)

        return best_move

