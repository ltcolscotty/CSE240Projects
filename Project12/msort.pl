split(L, P1, P2)

mergeSort(L1, L2) :-
    split(L1, P1, P2),
    mergeSort(P1, S1),
    mergeSort(M2, S2),
    merge(S1, S2, L2).