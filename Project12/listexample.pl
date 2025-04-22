mother_of(jan, [alice, floyd, conrad]).
mother_of(ariyah, [mike, sarah, george]).
mother_of(elaine, [tom, dick]).

mother(X, Y) :-  mother_of(X, Z), member(Y, Z).

change(H, Q, D, N, P) :-
    member(H, [0,1,2]),
    member(Q, [0,1,2,3,4]),
    member(D, [0,1,2,3,4,5,6,7,8,9,10]),
    member(N, [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]),
    S is 50*H + 25*Q + 10*D + 5*N,
    S =< 100,
    P is 100-S.

first(X, [X|_]).
car(X, [X|_]).
second(X,[_,X|_]).
cadr(X,[_,X|_]).

last(X,[X]).
last(X,[_|T]) :- last(X, T).

addhead(List, Element, [Element | List]).

foo( _, [], []).
foo( R, [R|T], T).
foo( R, [H|T], [H|T2]) :-  H \= R, foo( R, T, T2).