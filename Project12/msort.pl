split(L, P1, P2) :-
    length(L, Len),
    Half is Len // 2,
    length(P1, Half),
    append(P1, P2, L).
/*
merge listA, empty
merge empty listB
merge LA head less than LB head
merge LA head greater than LB head
*/
merge(A,[],A).
merge([],B,B).
merge([A|As], [B|Bs], [A|Merged]) :-
    A =< B,
    merge(As, [B|Bs], Merged).

merge([A|As], [B|Bs], [B|Merged]) :-
    A > B,
    merge([A|As], Bs, Merged).

/*base cases*/
mergeSort([], []).
mergeSort([A], [A]).

/*Thinking stuff
L1 - input
L2 - output

P1 - part 1
P2 - part 2

S1 - sorted 1
S2 - sorted 2
*/
mergeSort(L1, L2) :-
    split(L1, P1, P2),
    mergeSort(P1, S1),
    mergeSort(P2, S2),
    merge(S1, S2, L2).