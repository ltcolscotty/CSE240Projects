factorial(0,X) :- X is 1.
factorial(N, X) :- N1 is N-1, factorial(N1,X1), X is X1 * N.
factorial(N) :- factorial(N,X), write(X).