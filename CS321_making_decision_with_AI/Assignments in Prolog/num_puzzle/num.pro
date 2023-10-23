% instruction on how to run this : add init(row, column, number) on the top and run "solve(X)." in the terminal where X will be the solution. You can run "solve(X), show(X)." to see it visually.
% this is the second sample puzzle Dave gave 
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

adjacent(I, J, X, Y) :-
    X is I,
    (Y is J+1; Y is J-1),
    X >= 1,
    X =< 9,
    Y >=1,
    Y =< 9.

adjacent(I, J, X, Y) :-
    Y is J,
    (X is I+1; X is I-1),
    X >= 1,
    X =< 9,
    Y >= 1,
    Y =< 9.

solve(Finished) :-
    complete([], Finished).

complete([], Finished) :-
    member(X, [1,2,3,4,5,6,7,8,9]),
    member(Y, [1,2,3,4,5,6,7,8,9]),   
    append([X,Y | []],[], List),
    complete([List], Finished).

complete(Partial,Partial):-
    length(Partial, 81).

complete(Partial, Finished):-
    %[Head|Tail] is Partial, 
    append([Head|[]], _, Partial),
    %[I, J] is Head,
    append([ I,J | []],[], Head),
    adjacent(I, J, X, Y),
    \+ member([X,Y],Partial),
    length(Partial, Temp),
    Len is Temp + 1,
    (init(X,Y,Len); (\+ init(X,Y,_), \+ init(_,_, Len))),   
    append([X,Y|[]],[], A),
    complete([A | Partial], Finished).

show(Soln) :-
    reverse(Soln, Forwards),
    write('\n'),
    member(Row, [1,2,3,4,5,6,7,8,9]),
    write('\n'),
    member(Col, [1,2,3,4,5,6,7,8,9]),
    nth1(Value, Forwards, [Row, Col]),
    write(Value),
    write('\t'),
    fail.