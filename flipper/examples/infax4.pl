aaa(eq(xx)) &
aaa(eq(xy) v -eq(yx)) &
aaa(eq(xz) v -(eq(xy) & eq(yz))) &
aaa(dom(y) v -(dom(x) & eq(xy))) & %substitution
aaa(dom(y) v -(dom(x) & eq(xy))) & %substitution
aae(dom(z)) &
aaa(f(zy) v -(dom(x) & dom(y) & f(xy) & eq(xz))) & %substitution
aaa(f(xz) v -(dom(x) & dom(y) & f(xy) & eq(yz))) & %substitution
aae(dom(x) => (f(xz) & dom(z))) &           %dom is closed under f
aaa(eq(yz) v -(dom(x) & dom(y) & f(xy) & f(xz))) & %f is a function
aaa(eq(xz) v -(dom(x) & dom(y) & f(xy) & f(zy))) & %f is injective
aea(dom(z) & dom(y) & -f(zy)).
