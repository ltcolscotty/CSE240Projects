child_of(harry, charlie).
child_of(willy, charlie).
child_of(charlie, liz).

loves(N1, N2) :- child_of(N2, N1).

descendant_of(N1, N2) :- child_of(N1, N2).
descendant_of(N1, N2) :- child_of(N1, Nmid),descendant_of(Nmid, N2).
