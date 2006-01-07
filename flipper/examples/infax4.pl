aaa(eq(xx)) &
aaa(eq(xy) => eq(yx)) &
aaa((eq(xy) & eq(yz)) => eq(xz)) &
aaa((dom(x) & eq(xy)) => dom(y)) & %substitution
aaa((dom(x) & eq(xy)) => dom(y)) & %substitution
aae(dom(z)) &
aaa((dom(x) & dom(y) & f(xy) & eq(xz)) => f(zy)) & %substitution
aaa((dom(x) & dom(y) & f(xy) & eq(yz)) => f(xz)) & %substitution
aae(dom(x) => (f(xz) & dom(z))) &           %dom is closed under f
aaa((dom(x) & dom(y) & f(xy) & f(xz)) => eq(yz)) & %f is a function
aaa((dom(x) & dom(y) & f(xy) & f(zy)) => eq(xz)) & %f is injective
aea(dom(z) & dom(y) & -f(zy)).
