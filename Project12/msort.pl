split(L, P1, P2) :-

/*guh think about this later*/
merge(L1,[],L1).
merge([],L2,L2).

merge([A|As], [B|Bs], [A|Merged]) :-
    A =< B,
    merge(As, [B|Bs], Merged).

merge([A|As], [B|Bs], [B|Merged]) :-
    B < A,
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
    mergeSort(M2, S2),
    merge(S1, S2, L2).