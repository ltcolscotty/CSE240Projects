fibonacci(0,0).
fibonacci(1,1).

fibonacci(N, Result) :- 
    N1 is N-1, 
    N2 is N-2, 
    fibonacci(N1, R1), 
    fibonacci(N2, R2), 
    Result is R1 + R2.

fibonacci() :- 
    write('Which Fibonacci number would you like? \n'),
    read(N),
    fibonacci(N, Result), 
    write(Result).