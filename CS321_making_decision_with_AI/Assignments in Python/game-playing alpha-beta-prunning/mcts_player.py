"""MCTS game player starter code. Fill in the methods as indicated below.

Feel free to add additional helper methods or functions.

Originally based on work by:
@author Bryce Wiedenbeck
@author Anna Rafferty
@author Dave Musicant
"""

from __future__ import annotations
import random
from game_board import GameBoard, Location
from typing import Optional
from player import Player
from common_values import (
    EMPTY, MAX_PLAYER, MIN_PLAYER, RED, RED_MARKER, YELLOW, YELLOW_MARKER,
    COLOR_NAMES)
import math


class MctsPlayer(Player):
    """Uses MCTS to find the best move.

    Plays random games from the root node to a terminal state. In each playout,
    play proceeds according to UCB while all children have been expanded. The
    first node with unexpanded children has a random child expanded. After
    expansion, play proceeds by selecting uniform random moves. Upon reaching a
    terminal state, values are propagated back along the expanded portion of
    the path. After all playouts are completed, the move generating the highest
    value child of root is returned.
    """

    def __init__(self, playouts, ucb_const):
        self.playouts = playouts
        self.ucb_const = ucb_const

    def choose_move(self, board) -> Optional[Location]:
        root = MctsNode(board, None, self.ucb_const)
        return root.choose_move_via_mcts(self.playouts)


class MctsNode:
    """Node used in MCTS. It is a wrapper to contain a board/state as a node
    within a tree."""

    def __init__(self, state: GameBoard, parent: Optional[MctsNode],
                 ucb_const: float) -> None:
        """Constructor for a new node representing game state
        state. parent_node is the Node that is the parent of this
        one in the MCTS tree.
        """

        self.state = state
        self.parent = parent
        self.ucb_const = ucb_const

        # All of the known children for this node. To get to each child, a move
        # (specificed by a Location) is used.
        self.children: dict[Location, MctsNode] = {}


        # Stats of games played out from this node, from the perspective of the
        # player at this node.
        self.wins_for_this_player = 0
        self.total_games_for_this_player = 0

        # All legal moves that can me made from this node; useful to have once
        # to avoid recalculating later. Your code will be faster if you use
        # this value rather than calculating it when you need it.
        self.legal_moves = self.state.get_legal_moves()

        # You may add additional fields if needed below.

    def get_win_percentage_if_chosen_by_parent(self) -> float:
        """Gets the win percentage for the current node, from the perspective
        of the parent node that is trying to decide whether or not to select
        this node.

        You will need this for computing the UCB weight when doing playouts,
        and also for making the final choice on which move to make.
        """
        if self.total_games_for_this_player == 0:
            raise ValueError("division by 0")
        percent = (self.total_games_for_this_player - self.wins_for_this_player) / self.total_games_for_this_player
        return percent


    def get_UCB_weight_from_parent_perspective(self) -> float:
        """Weight from the UCB formula for this node, when used by its parent
        to select a node proportionally to its weight. The win percentage
        aspect of this formula must be from the parent's perspective, since
        that is the node making the decision.

        You will need to use this as part of the selection phase when doing
        playouts.
        """
        pt1 = self.get_win_percentage_if_chosen_by_parent() #first part of the ucb formula
        pt2 = math.sqrt(math.log(self.parent.total_games_for_this_player)/self.total_games_for_this_player) #second part of the ucb formula
        sum = pt1 + self.ucb_const*pt2 #the ucb value of the node from parent perspective
        return sum


    def update_play_counts(self, outcome: int) -> None:
        """Updates the total games played from this node, as well as the number
        of wins from this node for the current player.

        You will need this for backpropagating wins/losses back up the tree.

        outcome: +1 for 1st player win, -1 for 2nd player win.
        """

        if self.state.get_active_player() == MAX_PLAYER:
            if outcome == 1:
                self.wins_for_this_player += 1
        else:
            if outcome == -1:
                self.wins_for_this_player += 1
        self.total_games_for_this_player += 1
        return None


    def all_explored(self):
        '''
        return true if all children of the node are explored, otherwise false
        '''
        return len(self.legal_moves) == len(self.children)
        
    def UCBchoose(self) -> MctsNode:
        '''
        return the child with highest UCB weight from parent perspective
        '''
        ans = float('-inf')
        pick = None
        for child in self.children.values():
            UCBvalue = child.get_UCB_weight_from_parent_perspective()
            if (UCBvalue > ans):
                pick = child
                ans = UCBvalue
        return pick

    def pick_unexplored(self) -> Location:
        '''
        return an unexplored child of a node
        '''
        for move in self.legal_moves:
            if self.children.get(move, 0.0) == 0.0: #check whether the move is explored
                return move
        return None

    def random_playout(self) -> int:
        '''
        simulate games from the node, all moves are chosen randomly until a terminal stage is reached
        '''
        board = self.state
        while board.is_terminal() == False:
            move = board.get_random_legal_move()
            board = board.make_move(move)
        return board.value()
    
    def backprop(self, outcome) -> None:
        '''
        backward propagation stage, update play counts for the node's parent, the node's parent's parent, until reaching the root
        '''
        node = self
        while (node != None):
            node.update_play_counts(outcome)  
            node = node.parent   
        return None


    def choose_move_via_mcts(self, playouts: int) -> Optional[Location]:
        """Select a move by Monte Carlo tree search. Plays playouts random
        games from the root node to a terminal state. In each playout, play
        proceeds according to UCB while all children have been expanded. The
        first node with unexpanded children has a random child expanded. After
        expansion, play proceeds by selecting uniform random moves. Upon
        reaching a terminal state, values are propagated back along the
        expanded portion of the path. After all playouts are completed, the
        move generating the highest value child of root is returned.

        Returns None if no legal moves are available. If playouts is 0, returns
        a random/first choice from the legal moves.

        You will undoubtedly want to use helper functions when writing this,
        both some that I've provided, as well as helper functions of your own.
        """
        if playouts == 0:
            if len(self.legal_moves) > 0:
                return self.legal_moves[0]      #return the first legal move
            else:
                return None  #when there's no legal move, return None

        for i in range(1,playouts+1):
            node = self
            #selection stage
            while(node.all_explored() and node.state.is_terminal() == False):
                node = node.UCBchoose() #self.state.get_active_player())
            #expansion
            if node.state.is_terminal() == False:
                unexplored = node.pick_unexplored()
                node.children[unexplored] = MctsNode(node.state.make_move(unexplored),node, node.ucb_const)
                #simulation
                outcome = node.children[unexplored].random_playout()
                #back propagation stage
                node.children[unexplored].backprop(outcome)
            else:
                outcome = node.state.value()
                #back propagation stage
                node.backprop(outcome) 
        #choose move
        best_move = None
        win_percentage = float('-inf')
        for move in self.children.keys():
            current_percentage = self.children[move].get_win_percentage_if_chosen_by_parent()
            if current_percentage > win_percentage:
                win_percentage = current_percentage
                best_move = move
        return best_move
