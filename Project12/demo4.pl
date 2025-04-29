check(_, []).
check((X,Y),[(X1, Y1)|R]) :-
    Y =\= Y1,
    Y1-Y =\= X1-X,
    Y1-Y =\= X-X1,
    check((X,Y),R).

equeens(Q) :-
    member(Q,[1,2,3,4]).

equeens([]).
equeens([(X,Y)|T]) :-
    equeens(T),
    member(Y,[1,2,3,4]),
    check((X,Y),T).
