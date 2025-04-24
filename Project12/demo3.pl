female(elaine).
female(jane).
male(conrad).
male(joe).
married(luke).
married(mike).
father_of(andrew, contrad).
father_of(luke, mike).
mother_of(elaine, sarah).

not(X) :- X, !, fail.
not(_).

is_male(X) :- father_of(X, _); male(X).
is_female(X) :- mother_of(X, _); female(X).
bachelor(X) :- is_male(X), not(married(X)).

get_forever :-
    repeat,
    get(X),
    write(X),
    X > 50,
    nl,
    !.


get_digit(X) :-
    repeat,
    write('please enter a digit'), nl,
    get0(X1),
    X1 > 47,
    X1 < 58,
    X is X1 - 48,
    !.