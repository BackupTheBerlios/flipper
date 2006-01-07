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


output(aaa(A)) :-
	write('! [X,Y,Z] : ('),nl,
	output(A),
	write(')').
output(aae(A)) :-
	write('! [X,Y] : ( ? [Z] : ('),nl,
	output(A),
	write('))').
output(aea(A)) :-
	write('! [X] : ( ? [Y] : ( ! [Z] : ('),nl,
	output(A),
	write(')))').
output(aee(A)) :-
	write('! [X] : ( ? [Y,Z] : ('),nl,
	output(A),
	write('))').
output(v(A,B)) :-
	write('( '),
	output(A),
	write(' | '),
	output(B),
	write(')').
output(&(A,B)) :-
	write('( '),
	output(A),
	write(' & '),
	output(B),
	write(')').
output('=>'(A,B)) :-
	write('( '),
	output(A),
	write(' => '),
	output(B),
	write(')').
output('<=>'(A,B)) :-
	write('( '),
	output(A),
	write(' <=> '),
	output(B),
	write(')').
output(-(A)) :-
	write('~('),
	output(A),
	write(')').
output(r(R,X)) :-
	write(R),
	write('('),
	output_variable(X),
	write(')').
output(A) :-
	A =.. [R,X],
	write(R),
	write('('),
	output_variable(X),
	write(')').
output(A) :-
	!,
	write('error at subformula: '),
	write(A),
	nl.

output_variable(x) :-
	write('X').
output_variable(y) :-
	write('Y').
output_variable(z) :-
	write('Z').
output_variable(xx) :-
	write('X,X').
output_variable(xy) :-
	write('X,Y').
output_variable(xz) :-
	write('X,Z').
output_variable(yx) :-
	write('Y,X').
output_variable(yy) :-
	write('Y,Y').
output_variable(yz) :-
	write('Y,Z').
output_variable(zx) :-
	write('Z,X').
output_variable(zy) :-
	write('Z,Y').
output_variable(zz) :-
	write('Z,Z').

output_variable(xxx) :-
	write('X,X,X').
output_variable(xyx) :-
	write('X,Y,X').
output_variable(xzx) :-
	write('X,Z,X').
output_variable(yxx) :-
	write('Y,X,X').
output_variable(yyx) :-
	write('Y,Y,X').
output_variable(yzx) :-
	write('Y,Z,X').
output_variable(zxx) :-
	write('Z,X,X').
output_variable(zyx) :-
	write('Z,Y,X').
output_variable(zzx) :-
	write('Z,Z,X').

output_variable(xxy) :-
	write('X,X,Y').
output_variable(xyy) :-
	write('X,Y,Y').
output_variable(xzy) :-
	write('X,Z,Y').
output_variable(yxy) :-
	write('Y,X,Y').
output_variable(yyy) :-
	write('Y,Y,Y').
output_variable(yzy) :-
	write('Y,Z,Y').
output_variable(zxy) :-
	write('Z,X,Y').
output_variable(zyy) :-
	write('Z,Y,Y').
output_variable(zzy) :-
	write('Z,Z,Y').

output_variable(xxz) :-
	write('X,X,Z').
output_variable(xyz) :-
	write('X,Y,Z').
output_variable(xzz) :-
	write('X,Z,Z').
output_variable(yxz) :-
	write('Y,X,Z').
output_variable(yyz) :-
	write('Y,Y,Z').
output_variable(yzz) :-
	write('Y,Z,Z').
output_variable(zxz) :-
	write('Z,X,Z').
output_variable(zyz) :-
	write('Z,Y,Z').
output_variable(zzz) :-
	write('Z,Z,Z').


main :-
	read(A),
	write('input_formula(the_formula,axiom,'),nl,
	output(A),
	write(').'),nl.




:- initialization((main,halt)).
