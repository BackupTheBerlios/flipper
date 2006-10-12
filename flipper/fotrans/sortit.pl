%:- include('common.pl').

:- dynamic(sortit/1).

%note aaa(A) not atomish
%atomish(aaa(_)).
atomish(aae(_)).
atomish(aea(_)).
atomish(aee(_)).
%atomish(eee(_)).
atomish(eea(_)).
atomish(eae(_)).
atomish(eaa(_)).
atomish(A) :-
	A =.. [_F,X],
	vars(X).
atomish(r(_,X)) :-
	vars(X).

%subsumed(r(F,xx),r(F,yy)).
%subsumed(r(F,xx),r(F,zz)).


literalize([v(A,B)|Gamma],Pos,Neg) :-
	literalize([A,B|Gamma],Pos,Neg).
literalize([&(A,_B)|Gamma],Pos,Neg) :-
	literalize([A|Gamma],Pos,Neg).
literalize([&(_A,B)|Gamma],Pos,Neg) :-
	literalize([B|Gamma],Pos,Neg).
literalize([=>(A,B)|Gamma],Pos,Neg) :-
	literalize([-(A) v B|Gamma],Pos,Neg).
literalize([<=>(A,B)|Gamma],Pos,Neg) :-
	literalize([(A => B) & (B => A)|Gamma],Pos,Neg).
literalize([aaa(A)|Gamma],Pos,Neg) :-
	literalize([A|Gamma],Pos,Neg).
literalize([eee(A)|Gamma],Pos,Neg) :-
	literalize(Gamma,[eee(A)|Pos],Neg).
literalize([A|Gamma],Pos,Neg) :-
	atomish(A),
	\+(member(A,Neg)),
	(member(A,Pos) ->
	literalize(Gamma,Pos,Neg);
	literalize(Gamma,[A|Pos],Neg)).

literalize([-(-(A))|Gamma],Pos,Neg) :-
	literalize([A|Gamma],Pos,Neg).
literalize([-(v(A,B))|Gamma],Pos,Neg) :-
	literalize([&(-A,-B)|Gamma],Pos,Neg).
literalize([-(&(A,B))|Gamma],Pos,Neg) :-
	literalize([v(-A,-B)|Gamma],Pos,Neg).
literalize([-(A => B)|Gamma],Pos,Neg) :-
	literalize([B => A|Gamma],Pos,Neg).
literalize([-(A <=> B)|Gamma],Pos,Neg) :-
	literalize([-(B => A) v -(A => B)|Gamma],Pos,Neg).
literalize([-(aaa(A))|Gamma],Pos,Neg) :-
	literalize([eee(-(A))|Gamma],Pos,Neg).
literalize([-(eee(A))|Gamma],Pos,Neg) :-
	literalize([aaa(-(A))|Gamma],Pos,Neg).
literalize([-(A)|Gamma],Pos,Neg) :-
	atomish(A),
	\+(member(A,Pos)),
	(member(A,Neg) ->
	literalize(Gamma,Pos,Neg);
	literalize(Gamma,Pos,[A|Neg])).

literalize([],Pos,Neg) :-
	length(Pos,LPos),
	length(Neg,LNeg),
	L = LPos + LNeg,
	Score is min(LNeg,LPos) * L,  %measure how definite a clause is, close to zero is definite
	asserta(sortit([Score,Neg,Pos])).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


pos_disjoin([L],L).
pos_disjoin([L0,L1|Ls], L0 v D) :-
	pos_disjoin([L1|Ls],D).

neg_disjoin([L],-L).
neg_disjoin([L0,L1|Ls], -(L0) v D) :-
	neg_disjoin([L1|Ls],D).

clause_to_formula([_,[],[]]) :-
	error(empty_clause).
clause_to_formula([_,[],Pos],A) :-
	Pos \= [],
	pos_disjoin(Pos,Disj),
	(
	matrix(Disj) -> (
		A = aaa(Disj)
	) ; (
		[A] = Pos)).
clause_to_formula([_,Neg,[]],A) :-
	Neg \= [],
	neg_disjoin(Neg,Disj),
	(
	matrix(Disj) -> (
		A = aaa(Disj)
	) ; (
		[A] = Neg)).
clause_to_formula([_,Neg,Pos],aaa(NDisj v PDisj)) :-
	Pos \= [],
	Neg \= [],
	pos_disjoin(Pos,PDisj),
	neg_disjoin(Neg,NDisj).

to_formula([Clause],Formula) :-
	clause_to_formula(Clause,Formula).
to_formula([C0,C1|Cs],F & Fs) :-
	clause_to_formula(C0,F),
	to_formula([C1|Cs],Fs).

compute_normal_form(NF) :-
	setof([S,Neg,Pos],sortit([S,Neg,Pos]),List),
	%write(List),nl,
	retract(sortit(_)), %cleanup meory
	to_formula(List,NF).

%compute_normal_form(NF) :-
%	error(tautology_detected(NF)).

sortit_loop(Formula) :-
	literalize([Formula],[],[]),
	fail.
sortit_loop(_).


sortit(Formula,NF) :-
	sortit_loop(Formula),
	compute_normal_form(NF).


%sortit_main :-
%	read(Formula),
%	sortit_loop(Formula),
%	compute_normal_form(NF),
%	write(NF),nl.
%:- initialization((sortit_main,halt)).
