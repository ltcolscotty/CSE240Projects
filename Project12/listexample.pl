mother_of(jan, [alice, floyd, conrad]).
mother_of(ariyah, [mike, sarah, george]).
mother_of(elaine, [tom, dick]).

mother(X, Y) :-  mother_of(X, Z), member(Y, Z).