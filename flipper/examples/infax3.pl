aaa(eq(xx)) &
aaa(eq(xy) => eq(yx)) &
aaa((eq(xy) & eq(yz)) => eq(xz)) &
aaa((f(xy) & eq(xz)) => f(zy)) & %substitution
aaa((f(xy) & eq(yz)) => f(xz)) & %substitution
aae(f(xz)) &                        %f is a function
aaa((f(xy) & f(xz)) => eq(yz)) & %f is a function
aaa((f(xy) & f(zy)) => eq(xz)) & %f is injective
aea(-f(zy)).
