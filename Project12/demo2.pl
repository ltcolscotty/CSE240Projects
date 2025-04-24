warm_blooded(cat).
warm_blooded(dog).
warm_blooded(chicken).
four_legs(cat).
four_legs(dog).
two_legs(chicken).

mammal(M) :- warm_blooded(M), four_legs(M), !.
mammal1(M) :- !, warm_blooded(M), four_legs(M).

factorial(0,1) :-!.
factorial(N, F) :- 
    N>0, N1 is N-1,
    factorial(N1, F1),
    F is N* F1.

not(X) :- X, !, fail.
not(_).