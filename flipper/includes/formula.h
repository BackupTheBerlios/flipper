
composed set0000;
composed *init0000(int n_rel_id, const composed* q) {
	return init_R(&set0000, "a", "r[a,p(r(s(r(q))))]",0,p(r(s(r(q)))));
}
const composed* F0000(int n_rel_id, const composed * q) {
	return R(&set0000, 0, n_rel_id, p(r(s(r(q)))));
}

composed set000;
composed *init000(int n_rel_id, const composed* q) {
	return init_axyz(&set000, "aaa", init0000(n_rel_id, q));
}
const composed* F000(int n_rel_id, const composed * q) {
	return axyz(&set000, F0000(n_rel_id, q));
}

composed set00;
composed *init00(int n_rel_id, const composed* q) {
	return init_neg(&set00, "-", init000(n_rel_id, q));
}
const composed* F00(int n_rel_id, const composed * q) {
	return neg(&set00, F000(n_rel_id, q));
}

composed set010000;
composed *init010000(int n_rel_id, const composed* q) {
	return init_R(&set010000, "a", "r[a,r(r(s(r(q))))]",0,r(r(s(r(q)))));
}
const composed* F010000(int n_rel_id, const composed * q) {
	return R(&set010000, 0, n_rel_id, r(r(s(r(q)))));
}

composed set01000;
composed *init01000(int n_rel_id, const composed* q) {
	return init_neg(&set01000, "-", init010000(n_rel_id, q));
}
const composed* F01000(int n_rel_id, const composed * q) {
	return neg(&set01000, F010000(n_rel_id, q));
}

composed set0100;
composed *init0100(int n_rel_id, const composed* q) {
	return init_c(&set0100, 2, "c2", init01000(n_rel_id, q));
}
const composed* F0100(int n_rel_id, const composed * q) {
	return c(&set0100, 2, F01000(n_rel_id, q));
}

composed set010;
composed *init010(int n_rel_id, const composed* q) {
	return init_axyz(&set010, "aaa", init0100(n_rel_id, q));
}
const composed* F010(int n_rel_id, const composed * q) {
	return axyz(&set010, F0100(n_rel_id, q));
}

composed set01;
composed *init01(int n_rel_id, const composed* q) {
	return init_neg(&set01, "-", init010(n_rel_id, q));
}
const composed* F01(int n_rel_id, const composed * q) {
	return neg(&set01, F010(n_rel_id, q));
}

composed set0;
composed *init0(int n_rel_id, const composed* q) {
	return init_v(&set0, "v", init00(n_rel_id, q), init01(n_rel_id, q));
}
const composed* F0(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set00.relations) ?
 F00(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01.relations) ?
 F01(n_rel_id, q) :
 global__zero);
	return v(&set0, x,y);
}

composed set;
composed *init(int n_rel_id, const composed* q) {
	return init_neg(&set, "-", init0(n_rel_id, q));
}
const composed* F(int n_rel_id, const composed * q) {
	return neg(&set, F0(n_rel_id, q));
}
