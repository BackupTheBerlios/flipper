composed set;
composed *init(int n_rel_id, const composed* q) {
	return init_axyz(&set, "a", init0(n_rel_id, q));
}
const composed* F(int n_rel_id, const composed * q) {
	return axyz(&set, F0(n_rel_id, q));
}
composed set0;
composed *init0(int n_rel_id, const composed* q) {
	return init_R(&set0, "a", "a[p(r(s(r(q))))]",0,p(r(s(r(q)))));
}
const composed* F0(int n_rel_id, const composed * q) {
	return R(&set0, 0, n_rel_id, p(r(s(r(q)))));
}
