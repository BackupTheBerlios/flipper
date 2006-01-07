input_formula(the_formula,axiom,
( ! [X,Y] : ( ? [Z] : (
r(X,Z))) & ( ! [X,Y,Z] : (
( r(X,Y) => ~(r(Y,X)))) & ! [X,Y] : ( ? [Z] : (
( r(X,Y) => ( r(X,Z) & r(Z,Y)))))))).
