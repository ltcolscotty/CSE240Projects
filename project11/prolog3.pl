male(john).
male(bob).
female(lilly).

parent(john,bob).
parent(lilly,bob).

father(X,Y) :- parent(X,Y),male(X).
mother(X,Y) :- parent(X,Y),female(X).

child_of(Y,X) :- father(X,Y);mother(X,Y).