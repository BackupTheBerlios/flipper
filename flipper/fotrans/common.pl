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




error(A) :-
	write(A),
	write('.'),
	nl,
	halt(1).

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

matrix(succ(X)) :-
	vars(X).
matrix(r(_R,X)) :-
	vars(X).
matrix(':'(X,_R)) :-
	vars(X).
matrix(-(A)) :-
	matrix(A).
matrix(v(A,B)) :-
	matrix(A),
	matrix(B).
matrix(&(A,B)) :-
	matrix(A),
	matrix(B).
matrix('=>'(A,B)) :-
	matrix(A),
	matrix(B).
matrix('<=>'(A,B)) :-
	matrix(A),
	matrix(B).
matrix(A) :-
	A =.. [_R,X],
	vars(X).

