init(2,2,1).
init(3,1,7).
init(1,3,3).
init(2,3,2).


adjacent(I, J, X, Y) :-
    Y is I,
    (X is J+1; X is J-1),
    X >= 1,
    X =< 3,
    Y >=1,
    Y =< 3.

adjacent(I, J, X, Y) :-
    X is J,
    (Y is I+1; Y is I-1),
    X >= 1,
    X =< 3,
    Y >= 1,
    Y =< 3.

complete(Partial,Partial):-
    length(Partial, 9).

complete(Partial, Finished):-
    %[Head|Tail] is Partial, 
    append([Head|[]], _, Partial),
    %[I, J] is Head,
    append([ I,J | []],[], Head),
    adjacent(I, J, Y, X),
    \+ member([X,Y],Partial),
    length(Partial, Temp),
    Len is Temp + 1,
    (init(X,Y,Len); (\+ init(X,Y,_), \+ init(_,_, Len))),   
    append([X,Y|[]],[], A),
    write(Len),
    complete([A | Partial], Finished).

show(Soln) :-
    reverse(Soln, Forwards),
    write('\n'),
    member(Row, [1,2,3]),
    write('\n'),
    member(Col, [1,2,3]),
    nth1(Value, Forwards, [Row, Col]),
    write(Value),
    write('\t'),
    fail.