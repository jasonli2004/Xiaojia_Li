valid_puzzle([]).

valid_puzzle(List1) :-
    append(Left, [M | Right], List1),
    append(Left, Right, WithoutM),
    can_draw(M, WithoutM).

can_draw(_,[]).

can_draw(Number, List) :-
    append(Left, [M | Right], List),
    append(Left, Right, WithoutM),
    Number+1 =:= M,
    can_draw(Number+1, WithoutM).

can_draw(Number, List) :-
    append(Left, [M | Right], List),
    append(Left, Right, WithoutM),
    Number-1 =:= M,
    can_draw(Number-1, WithoutM).