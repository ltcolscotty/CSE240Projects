guess() :-
    write('Try to guess a number between 1 to 10.\n'),
    read(GuessN),
    random(1,10,Number),
    processguess(GuessN, Number).

processguess(GuessN, Number) :- GuessN == Number,
    write("Correct!\n").

processguess(GuessN, Number) :- GuessN < Number,
    write("Higher!\n"),
    read(GuessNew),
    processguess(GuessNew, Number).

processguess(GuessN, Number) :- GuessN > Number,
    write("Lower!\n"),
    read(GuessNew),
    processguess(GuessNew, Number).
