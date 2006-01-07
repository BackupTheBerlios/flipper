:- op(350,xfy,':').    % negation
:- op(400,fy,-).    % negation
%:- op(450,fy,ex).    % quantifier
%:- op(450,fy,ey).    % quantifier
%:- op(450,fy,ez).    % quantifier
%:- op(450,fy,ax).    % quantifier
%:- op(450,fy,ay).    % quantifier
%:- op(450,fy,az).    % quantifier
:- op(450,fy,aaa).    % quantifier
:- op(450,fy,aae).    % quantifier
:- op(450,fy,aea).    % quantifier
:- op(450,fy,aee).    % quantifier
:- op(450,fy,eaa).    % quantifier
:- op(450,fy,eae).    % quantifier
:- op(450,fy,eea).    % quantifier
:- op(450,fy,eee).    % quantifier
:- op(500,xfy,&).   % conjunction
:- op(600,xfy,v).   % disjunction
:- op(650,xfy,=>).  % implication
:- op(700,xfy,<=>). % equivalence


:- dynamic(rel_id_store/2).
:- dynamic(max_rel_id/1).


%check to see if something is a formula
vars(x).
vars(y).
vars(z).
vars(xx).
vars(xy).
vars(xz).
vars(yx).
vars(yy).
vars(yz).
vars(zx).
vars(zy).
vars(zz).
vars(xxx).
vars(xxy).
vars(xxz).
vars(xyx).
vars(xyy).
vars(xyz).
vars(xzx).
vars(xzy).
vars(xzz).
vars(yxx).
vars(yxy).
vars(yxz).
vars(yyx).
vars(yyy).
vars(yyz).
vars(yzx).
vars(yzy).
vars(yzz).
vars(zxx).
vars(zxy).
vars(zxz).
vars(zyx).
vars(zyy).
vars(zyz).
vars(zzx).
vars(zzy).
vars(zzz).


xyz_formula(succ(X)) :-
	vars(X).
xyz_formula(r(_R,X)) :-
	vars(X).
xyz_formula(':'(X,_R)) :-
	vars(X).
xyz_formula(-(A)) :-
	xyz_formula(A).
xyz_formula(v(A,B)) :-
	xyz_formula(A),
	xyz_formula(B).
xyz_formula(&(A,B)) :-
	xyz_formula(A),
	xyz_formula(B).
xyz_formula('=>'(A,B)) :-
	xyz_formula(A),
	xyz_formula(B).
xyz_formula('<=>'(A,B)) :-
	xyz_formula(A),
	xyz_formula(B).
xyz_formula(A) :-
	A =.. [_R,X],
	vars(X).
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

action(x,r(s(r(s(q))))).
action(y,s(r(s(q)))).
action(z,r(r(s(r(s(q)))))).

action(xx,r(s(r(s(q))))).
action(xy,p(r(s(r(q))))).
action(xz,r(r(s(r(q))))).
action(yx,r(s(r(q)))).
action(yy,s(r(s(q)))).
action(yz,r(p(s(r(q))))).
action(zx,p(s(r(q)))).
action(zy,s(r(q))).
action(zz,r(r(s(r(s(q)))))).

action(xxx, r(s(r(s(q))))).
action(xxy, r(s(q))).
action(xxz, r(s(q))).
action(xyx, r(s(r(p(q))))).
action(xyy, p(r(s(r(q))))).
action(xyz, q).
action(xzx, r(s(r(p(q))))).
action(xzy, q).
action(xzz, p(r(s(r(q))))).
action(yxx, p(r(s(r(q))))).
action(yxy, r(s(r(p(q))))).
action(yxz, q).
action(yyx, r(s(q))).
action(yyy, r(s(r(s(q))))).
action(yyz, r(s(q))).
action(yzx, q).
action(yzy, r(s(r(p(q))))).
action(yzz, p(r(s(r(q))))).
action(zxx, p(r(s(r(q))))).
action(zxy, q).
action(zxz, r(s(r(p(q))))).
action(zyx, q).
action(zyy, p(r(s(r(q))))).
action(zyz, r(s(r(p(q))))).
action(zzx, r(s(q))).
action(zzy, r(s(q))).
action(zzz, r(s(r(s(q))))).


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

error(A) :-
	write(A),
	write('.'),
	nl,
	halt(1).

main :-
	assertz(max_rel_id(-1)),
	read_term(A,[syntax_error(fail)]),
	formula(A),
	fo_2_adequate(A,B),
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
