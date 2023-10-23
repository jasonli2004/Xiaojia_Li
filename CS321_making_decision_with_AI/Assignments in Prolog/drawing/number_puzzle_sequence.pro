valid_puzzle([],[]).

valid_puzzle(List1, [M | Sequence]) :-
    append(Left, [M | Right], List1),
    append(Left, Right, WithoutM),
    can_draw(M, WithoutM, Sequence).

can_draw(_,[],[]).

can_draw(Number, List, [M | Tail]) :-
    append(Left, [M | Right], List),
    append(Left, Right, WithoutM),
    Number+1 =:= M,
    can_draw(Number+1, WithoutM, Tail).

can_draw(Number, List, [M | Tail2]) :-
    append(Left, [M | Right], List),
    append(Left, Right, WithoutM),
    Number-1 =:= M,
    can_draw(Number-1, WithoutM, Tail2).