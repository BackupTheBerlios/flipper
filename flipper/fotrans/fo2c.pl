:- include('common.pl').
:- include('sortit.pl').
:- dynamic(rel_id_store/2).
:- dynamic(max_rel_id/1).


xyz_formula(X) :-
	matrix(X).
xyz_formula(A) :-
	error(not_an_open_formula(A)).

formula(v(A,B)) :-
	formula(A),
	formula(B).
formula(&(A,B)) :-
	formula(A),
	formula(B).
formula('=>'(A,B)) :-
	formula(A),
	formula(B).
formula('<=>'(A,B)) :-
	formula(A),
	formula(B).

formula(aaa(A)) :-
	xyz_formula(A).
formula(aae(A)) :-
	xyz_formula(A).
formula(aea(A)) :-
	xyz_formula(A).
formula(aee(A)) :-
	xyz_formula(A).

formula(eaa(A)) :-
	xyz_formula(A).
formula(eae(A)) :-
	xyz_formula(A).
formula(eea(A)) :-
	xyz_formula(A).
formula(eee(A)) :-
	xyz_formula(A).

formula(ex(ey(ez(A)))) :-
	xyz_formula(A).
formula(ex(ey(az(A)))) :-
	xyz_formula(A).
formula(ex(ay(ez(A)))) :-
	xyz_formula(A).
formula(ex(ay(az(A)))) :-
	xyz_formula(A).
formula(ax(ey(ez(A)))) :-
	xyz_formula(A).
formula(ax(ey(az(A)))) :-
	xyz_formula(A).
formula(ax(ay(ez(A)))) :-
	xyz_formula(A).
formula(ax(ay(az(A)))) :-
	xyz_formula(A).



formula(A) :-
	error(not_a_sentence(A)).

rel_id(R,RelId) :-
	rel_id_store(R,RelId).
rel_id(R,NextRelId) :-
	\+(rel_id_store(R,NextRelId)),
	max_rel_id(MaxRelId),
	NextRelId is MaxRelId + 1,
	assertz(rel_id_store(R,NextRelId)),
	retract(max_rel_id(MaxRelId)),
	assertz(max_rel_id(NextRelId)).


action(x,Q) :- action(xxx,Q).
action(y,Q) :- action(yyy,Q).
action(z,Q) :- action(zzz,Q).

action(xx,Q) :- action(xxx,Q).
action(xy,Q) :- action(xyy,Q).
action(xz,Q) :- action(xzz,Q).
action(yx,Q) :- action(yxx,Q).
action(yy,Q) :- action(yyy,Q).
action(yz,Q) :- action(yzz,Q).
action(zx,Q) :- action(zxx,Q).
action(zy,Q) :- action(zyy,Q).
action(zz,Q) :- action(zzz,Q).

action(xyz, q).
action(yyz, s(q)).
action(zxy, r(q)).
action(yxz, p(q)).
action(xxy, r(s(q))).
action(xxz, p(s(q))).
action(zyy, s(r(q))).
action(yzx, r(r(q))).
action(zyx, p(r(q))).
action(xzy, r(p(q))).
action(yyy, s(r(s(q)))).
action(zzx, r(r(s(q)))).
action(yyx, p(r(s(q)))).
action(zzy, r(p(s(q)))).
action(yxx, r(s(r(q)))).
action(zxx, p(s(r(q)))).
action(yzy, s(r(r(q)))).
action(xxx, r(s(r(s(q))))).
action(xzz, r(r(s(r(q))))).
action(xyy, p(r(s(r(q))))).
action(yzz, r(p(s(r(q))))).
action(xyx, r(s(r(r(q))))).
action(xzx, p(s(r(r(q))))).
action(zzz, r(r(s(r(s(q)))))).
action(zxz, r(r(s(r(r(q)))))).
action(yxy, p(r(s(r(r(q)))))).
action(zyz, r(p(s(r(r(q)))))).


write_id([]).
write_id([X|Xs]) :-
	write_id(Xs),
	write(X).

adequate_to_c(Id,v(A,B)) :-
	adequate_to_c([0|Id],A),
	adequate_to_c([1|Id],B),
	
	nl,write('composed set'), write_id(Id), write(';'),nl,
	
	write('composed *init'), write_id(Id), write('(int n_rel_id, const composed* q) {'), nl,
	write('\treturn init_v(&set'), write_id(Id), write(', "v", init'),
	write_id([0|Id]), write('(n_rel_id, q), init'),
	write_id([1|Id]), write('(n_rel_id, q));'), nl,
	write('}'),nl,
	
	write('const composed* F'), write_id(Id), write('(int n_rel_id, const composed * q) {'), nl,
	
	write('const composed *x ='),nl,
	write('(intset__member(n_rel_id,set'), write_id([0|Id]), write('.relations) ?'),nl,
	write(' F'), write_id([0|Id]), write('(n_rel_id, q) :'),nl,
	write(' global__zero);'),nl,
	
	write('const composed *y = (intset__member(n_rel_id,set'), write_id([1|Id]), write('.relations) ?'),nl,
	write(' F'), write_id([1|Id]), write('(n_rel_id, q) :'),nl,
	write(' global__zero);'),nl,
	
	write('\treturn v(&set'), write_id(Id), write(', x,y);'),nl,
	write('}'),nl.
	

adequate_to_c(Id,-(A)) :-
	adequate_to_c([0|Id],A),
	
	nl,write('composed set'), write_id(Id), write(';'),nl,
	
	write('composed *init'), write_id(Id), write('(int n_rel_id, const composed* q) {'), nl,
	write('\treturn init_neg(&set'), write_id(Id), write(', "-", init'),
	write_id([0|Id]), write('(n_rel_id, q));'), nl,
	write('}'),nl,
	
	write('const composed* F'), write_id(Id), write('(int n_rel_id, const composed * q) {'), nl,
	%write('if (!intset__member(n_rel_id,set'), write_id(Id),write('.relations)) return global__zero0;'),nl,
	write('\treturn neg(&set'), write_id(Id), write(', F'),
	write_id([0|Id]), write('(n_rel_id, q));'), nl,
	write('}'), nl.

adequate_to_c(Id,ex(A)) :-
	adequate_to_c([0|Id],A),
	
	nl,write('composed set'), write_id(Id), write(';'),nl,
	
	write('composed *init'), write_id(Id), write('(int n_rel_id, const composed* q) {'), nl,
	write('\treturn init_c(&set'), write_id(Id), write(', 0, "c0", init'),
	write_id([0|Id]), write('(n_rel_id, q));'), nl,
	write('}'),nl,
	
	write('const composed* F'), write_id(Id), write('(int n_rel_id, const composed * q) {'), nl,
	%write('if (!intset__member(n_rel_id,set'), write_id(Id),write('.relations)) return global__zero0;'),nl,
	write('\treturn c(&set'), write_id(Id), write(', 0, F'),
	write_id([0|Id]), write('(n_rel_id, q));'), nl,
	write('}'), nl.

adequate_to_c(Id,ey(A)) :-
	adequate_to_c([0|Id],A),
	
	nl,write('composed set'), write_id(Id), write(';'),nl,
	
	write('composed *init'), write_id(Id), write('(int n_rel_id, const composed* q) {'), nl,
	write('\treturn init_c(&set'), write_id(Id), write(', 1, "c1", init'),
	write_id([0|Id]), write('(n_rel_id, q));'), nl,
	write('}'),nl,
	
	write('const composed* F'), write_id(Id), write('(int n_rel_id, const composed * q) {'), nl,
	%write('if (!intset__member(n_rel_id,set'), write_id(Id),write('.relations)) return global__zero0;'),nl,
	write('\treturn c(&set'), write_id(Id), write(', 1, F'),
	write_id([0|Id]), write('(n_rel_id, q));'), nl,
	write('}'), nl.

adequate_to_c(Id,ez(A)) :-
	adequate_to_c([0|Id],A),
	
	nl,write('composed set'), write_id(Id), write(';'),nl,
	
	write('composed *init'), write_id(Id), write('(int n_rel_id, const composed* q) {'), nl,
	write('\treturn init_c(&set'), write_id(Id), write(', 2, "c2", init'),
	write_id([0|Id]), write('(n_rel_id, q));'), nl,
	write('}'),nl,
	
	write('const composed* F'), write_id(Id), write('(int n_rel_id, const composed * q) {'), nl,
	%write('if (!intset__member(n_rel_id,set'), write_id(Id),write('.relations)) return global__zero0;'),nl,
	write('\treturn c(&set'), write_id(Id), write(', 2, F'),
	write_id([0|Id]), write('(n_rel_id, q));'), nl,
	write('}'), nl.


adequate_to_c(Id,r(R,Vars)) :-
	action(Vars,Action),
	rel_id(R,RelId),
	
	nl,write('composed set'), write_id(Id), write(';'),nl,
	
	write('composed *init'), write_id(Id), write('(int n_rel_id, const composed* q) {'), nl,
	write('\treturn init_R(&set'), write_id(Id), write(', "'), write(R), write('"'),
	write(', "r['), write(R), write(','), write(Action), write(']",'),
	write(RelId), write(','), write(Action), write(');'), nl,
	write('}'),nl,
	
	write('const composed* F'), write_id(Id), write('(int n_rel_id, const composed * q) {'), nl,
	write('\treturn R(&set'), write_id(Id), write(', '), write(RelId), write(', n_rel_id, '),
	write(Action), write(');'), nl,
	write('}'), nl.

adequate_to_c(Id,succ(Vars)) :-
	action(Vars,Action),
	
	nl,write('composed set'), write_id(Id), write(';'),nl,
	
	write('composed *init'), write_id(Id), write('(int n_unused, const composed* q) {'), nl,
	write('\treturn init_succ(&set'), write_id(Id), write(', "'), write('succ'), write('"'),
	write(', "'), write('succ'), write('['), write(Action), write(']",'),
	write(Action), write(');'), nl,
	write('}'),nl,
	
	write('const composed* F'), write_id(Id), write('(int n_unused,const composed * q) {'), nl,
	write('\treturn succ(&set'), write_id(Id), write(', '),
	write(Action), write(');'), nl,
	write('}'), nl.

adequate_to_c(Id,axyz(A)) :-
	adequate_to_c([0|Id],A),
	
	nl,write('composed set'), write_id(Id), write(';'),nl,
	
	write('composed *init'), write_id(Id), write('(int n_rel_id, const composed* q) {'), nl,
	write('\treturn init_axyz(&set'), write_id(Id), write(', "aaa", init'),
	write_id([0|Id]), write('(n_rel_id, q));'), nl,
	write('}'),nl,
	
	write('const composed* F'), write_id(Id), write('(int n_rel_id, const composed * q) {'), nl,
	%write('if (!intset__member(n_rel_id,set'), write_id(Id),write('.relations)) return global__zero0;'),nl,
	write('\treturn axyz(&set'), write_id(Id), write(', F'),
	write_id([0|Id]), write('(n_rel_id, q));'), nl,
	write('}'), nl.

/*
adequate_to_c(Id,axyez(A)) :-
	adequate_to_c([0|Id],A),
	
	nl,write('composed set'), write_id(Id), write(';'),nl,
	
	write('composed *init'), write_id(Id), write('(int n_rel_id, const composed* q) {'), nl,
	write('\treturn init_axyez(&set'), write_id(Id), write(', "aae", init'),
	write_id([0|Id]), write('(n_rel_id, q));'), nl,
	write('}'),nl,
	
	write('const composed* F'), write_id(Id), write('(int n_rel_id, const composed * q) {'), nl,
	write('\treturn axyez(&set'), write_id(Id), write(', F'),
	write_id([0|Id]), write('(n_rel_id, q));'), nl,
	write('}'), nl.
*/

adequate_to_c(A,_) :-
	!,
	error(unknown_connective(A)).



fo_2_adequate(ax(A),-(ex(-(B)))) :-
	fo_2_adequate(A,B).
fo_2_adequate(ay(A),-(ey(-(B)))) :-
	fo_2_adequate(A,B).
fo_2_adequate(az(A),-(ez(-(B)))) :-
	fo_2_adequate(A,B).

/*
fo_2_adequate(-(ex(ey(-ez(A)))),axyez(B)) :-
	!,
	fo_2_adequate(A,B).
*/

fo_2_adequate(ex(A),ex(B)) :-
	fo_2_adequate(A,B).
fo_2_adequate(ey(A),ey(B)) :-
	fo_2_adequate(A,B).
fo_2_adequate(ez(A),ez(B)) :-
	fo_2_adequate(A,B).


fo_2_adequate(&(A,B),-(v(-(C),-(D)))) :-
	fo_2_adequate(A,C),
	fo_2_adequate(B,D).
fo_2_adequate(v(A,B),v(C,D)) :-
	fo_2_adequate(A,C),
	fo_2_adequate(B,D).
fo_2_adequate(-(A),-(B)) :-
	fo_2_adequate(A,B).

fo_2_adequate(aaa(A),axyz(B)) :-
	fo_2_adequate(A,B).
fo_2_adequate(aae(A),axyz(ez(B))) :-
	fo_2_adequate(A,B).
fo_2_adequate(aea(A),axyz(ey(-(ez(-(B)))))) :-
	fo_2_adequate(A,B).
fo_2_adequate(aee(A),axyz(ey(ez(B)))) :-
	fo_2_adequate(A,B).

fo_2_adequate(eaa(A),axyz(ex(-(ey(ez(-B)))))) :-
	fo_2_adequate(A,B).
fo_2_adequate(eae(A),axyz(ex(-(ey(-(ez(B))))))) :-
	fo_2_adequate(A,B).
fo_2_adequate(eea(A),axyz(ex(ey(-(ez(-(B))))))) :-
	fo_2_adequate(A,B).
fo_2_adequate(eee(A),axyz(ex(ey(ez(B))))) :-
	fo_2_adequate(A,B).

fo_2_adequate(=>(A,B), v(-(C),D)) :-
	fo_2_adequate(A,C),
	fo_2_adequate(B,D).
fo_2_adequate(<=>(A,B), C) :-
	fo_2_adequate(&(=>(A,B),=>(B,A)),C).
fo_2_adequate(':'(X,R),r(R,X)).
fo_2_adequate(r(R,X),r(R,X)).
fo_2_adequate(succ(X),succ(X)) :- !.
fo_2_adequate(A,r(R,X)) :-
	A =.. [R,X].
fo_2_adequate(A,A) :- 
	error(unknown_term(A)).


main :-
	assertz(max_rel_id(-1)),
	read_term(A,[syntax_error(fail)]),
	formula(A),
	
	Sorted = A,
	%sortit(A,Sorted),
	
	fo_2_adequate(Sorted,B),
	adequate_to_c([],B),!.
main :-
	%a syntax error has occured
	syntax_error_info(FileName,Line,Column,Error),
	write(FileName),
	write(':'),
	write(Line),
	write(':'),
	write(Column),
	write(': '),
	write(Error),
	nl,
	halt(1).

:- initialization((main,halt)).
