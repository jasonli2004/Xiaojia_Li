init(1,1,13).
init(1,5,27).
init(1,9,39).

init(2,2,11).
init(2,5,24).
init(2,8,37).

init(5,1,71).
init(5,2,70).
init(5,8,34).
init(5,9,43).

init(8,2,81).
init(8,5,62).
init(8,8,53).

init(9,1,79).
init(9,5,63).
init(9,9,51).

adjacent(I,J,X,Y) :-
    X is I + 1,
    Y is J,
    in_bound(X, Y).

adjacent(I,J,X,Y) :-
    X is I - 1,
    Y is J,
    in_bound(X, Y).

adjacent(I,J,X,Y) :-
    X is I,
    Y is J + 1,
    in_bound(X, Y).

adjacent(I,J,X,Y) :-
    X is I,
    Y is J - 1,
    in_bound(X, Y).

in_bound(X,Y) :-
    X =< 9,
    X >= 1,
    Y =< 9,
    Y >= 1.
complete(Partial,Partial):-
    length(Partial, 81).

% Recursive case: extending the chain to an adjacent position.
complete( [[ I , J ] | Partial],Finished) :-
    adjacent(I, J, X, Y),
    \+ member([X,Y], Partial),
    length(Partial, Len),
    Num is Len + 2,
    (init(X, Y, Num) ; \+ init(X,Y,_), \+ init(_,_,Num)),
    complete([[X, Y],[I, J] | Partial], Finished).
    
solve(Final) :-
    between(1, 9, I),
    between(1, 9, J),
    complete([[I, J]], Final).

% show/1 predicate:
show(Soln) :-
    reverse(Soln, Forwards),
    writeln('\n'),
    member(Row, [1, 2, 3, 4, 5, 6, 7, 8, 9]),
    writeln(''),
    member(Col, [1, 2, 3, 4, 5, 6, 7, 8, 9]),
    nth1(Value, Forwards, [Row, Col]),
    write(Value),
    write('\t'),
    fail.