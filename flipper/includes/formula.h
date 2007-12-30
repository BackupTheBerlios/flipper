
composed set000000000;
composed *init000000000(int n_rel_id, DIFF_CONST composed* q) {
	return init_R(&set000000000, "r", "r[r(s(r(s(q)))),r]",0,r(s(r(s(q)))));
}
static DIFF_CONST composed* F000000000(int n_rel_id, DIFF_CONST composed * q) {
	return R(&set000000000, 0, n_rel_id, r(s(r(s(q)))));
}

composed set00000000;
composed *init00000000(int n_rel_id, DIFF_CONST composed* q) {
	return init_neg(&set00000000, "-", init000000000(n_rel_id, q));
}
static DIFF_CONST composed* F00000000(int n_rel_id, DIFF_CONST composed * q) {
	return neg(&set00000000, F000000000(n_rel_id, q));
}

composed set0000000;
composed *init0000000(int n_rel_id, DIFF_CONST composed* q) {
	return init_neg(&set0000000, "-", init00000000(n_rel_id, q));
}
static DIFF_CONST composed* F0000000(int n_rel_id, DIFF_CONST composed * q) {
	return neg(&set0000000, F00000000(n_rel_id, q));
}

composed set00000010000;
composed *init00000010000(int n_rel_id, DIFF_CONST composed* q) {
	return init_R(&set00000010000, "r", "r[p(r(s(r(q)))),r]",0,p(r(s(r(q)))));
}
static DIFF_CONST composed* F00000010000(int n_rel_id, DIFF_CONST composed * q) {
	return R(&set00000010000, 0, n_rel_id, p(r(s(r(q)))));
}

composed set0000001000;
composed *init0000001000(int n_rel_id, DIFF_CONST composed* q) {
	return init_neg(&set0000001000, "-", init00000010000(n_rel_id, q));
}
static DIFF_CONST composed* F0000001000(int n_rel_id, DIFF_CONST composed * q) {
	return neg(&set0000001000, F00000010000(n_rel_id, q));
}

composed set0000001001000;
composed *init0000001001000(int n_rel_id, DIFF_CONST composed* q) {
	return init_R(&set0000001001000, "r", "r[p(r(s(r(q)))),r]",0,p(r(s(r(q)))));
}
static DIFF_CONST composed* F0000001001000(int n_rel_id, DIFF_CONST composed * q) {
	return R(&set0000001001000, 0, n_rel_id, p(r(s(r(q)))));
}

composed set000000100100;
composed *init000000100100(int n_rel_id, DIFF_CONST composed* q) {
	return init_neg(&set000000100100, "-", init0000001001000(n_rel_id, q));
}
static DIFF_CONST composed* F000000100100(int n_rel_id, DIFF_CONST composed * q) {
	return neg(&set000000100100, F0000001001000(n_rel_id, q));
}

composed set00000010010100;
composed *init00000010010100(int n_rel_id, DIFF_CONST composed* q) {
	return init_R(&set00000010010100, "r", "r[r(p(s(r(q)))),r]",0,r(p(s(r(q)))));
}
static DIFF_CONST composed* F00000010010100(int n_rel_id, DIFF_CONST composed * q) {
	return R(&set00000010010100, 0, n_rel_id, r(p(s(r(q)))));
}

composed set0000001001010;
composed *init0000001001010(int n_rel_id, DIFF_CONST composed* q) {
	return init_neg(&set0000001001010, "-", init00000010010100(n_rel_id, q));
}
static DIFF_CONST composed* F0000001001010(int n_rel_id, DIFF_CONST composed * q) {
	return neg(&set0000001001010, F00000010010100(n_rel_id, q));
}

composed set0000001001011;
composed *init0000001001011(int n_rel_id, DIFF_CONST composed* q) {
	return init_R(&set0000001001011, "r", "r[r(r(s(r(q)))),r]",0,r(r(s(r(q)))));
}
static DIFF_CONST composed* F0000001001011(int n_rel_id, DIFF_CONST composed * q) {
	return R(&set0000001001011, 0, n_rel_id, r(r(s(r(q)))));
}

composed set000000100101;
composed *init000000100101(int n_rel_id, DIFF_CONST composed* q) {
	return init_v(&set000000100101, "v", init0000001001010(n_rel_id, q), init0000001001011(n_rel_id, q));
}
static DIFF_CONST composed* F000000100101(int n_rel_id, DIFF_CONST composed * q) {
DIFF_CONST composed *x =
(intset__member(n_rel_id,set0000001001010.relations) ?
 F0000001001010(n_rel_id, q) :
 global__zero);
DIFF_CONST composed *y = (intset__member(n_rel_id,set0000001001011.relations) ?
 F0000001001011(n_rel_id, q) :
 global__zero);
	return v(&set000000100101, x,y);
}

composed set00000010010;
composed *init00000010010(int n_rel_id, DIFF_CONST composed* q) {
	return init_v(&set00000010010, "v", init000000100100(n_rel_id, q), init000000100101(n_rel_id, q));
}
static DIFF_CONST composed* F00000010010(int n_rel_id, DIFF_CONST composed * q) {
DIFF_CONST composed *x =
(intset__member(n_rel_id,set000000100100.relations) ?
 F000000100100(n_rel_id, q) :
 global__zero);
DIFF_CONST composed *y = (intset__member(n_rel_id,set000000100101.relations) ?
 F000000100101(n_rel_id, q) :
 global__zero);
	return v(&set00000010010, x,y);
}

composed set0000001001;
composed *init0000001001(int n_rel_id, DIFF_CONST composed* q) {
	return init_neg(&set0000001001, "-", init00000010010(n_rel_id, q));
}
static DIFF_CONST composed* F0000001001(int n_rel_id, DIFF_CONST composed * q) {
	return neg(&set0000001001, F00000010010(n_rel_id, q));
}

composed set000000100;
composed *init000000100(int n_rel_id, DIFF_CONST composed* q) {
	return init_v(&set000000100, "v", init0000001000(n_rel_id, q), init0000001001(n_rel_id, q));
}
static DIFF_CONST composed* F000000100(int n_rel_id, DIFF_CONST composed * q) {
DIFF_CONST composed *x =
(intset__member(n_rel_id,set0000001000.relations) ?
 F0000001000(n_rel_id, q) :
 global__zero);
DIFF_CONST composed *y = (intset__member(n_rel_id,set0000001001.relations) ?
 F0000001001(n_rel_id, q) :
 global__zero);
	return v(&set000000100, x,y);
}

composed set00000010;
composed *init00000010(int n_rel_id, DIFF_CONST composed* q) {
	return init_neg(&set00000010, "-", init000000100(n_rel_id, q));
}
static DIFF_CONST composed* F00000010(int n_rel_id, DIFF_CONST composed * q) {
	return neg(&set00000010, F000000100(n_rel_id, q));
}

composed set0000001;
composed *init0000001(int n_rel_id, DIFF_CONST composed* q) {
	return init_neg(&set0000001, "-", init00000010(n_rel_id, q));
}
static DIFF_CONST composed* F0000001(int n_rel_id, DIFF_CONST composed * q) {
	return neg(&set0000001, F00000010(n_rel_id, q));
}

composed set000000;
composed *init000000(int n_rel_id, DIFF_CONST composed* q) {
	return init_v(&set000000, "v", init0000000(n_rel_id, q), init0000001(n_rel_id, q));
}
static DIFF_CONST composed* F000000(int n_rel_id, DIFF_CONST composed * q) {
DIFF_CONST composed *x =
(intset__member(n_rel_id,set0000000.relations) ?
 F0000000(n_rel_id, q) :
 global__zero);
DIFF_CONST composed *y = (intset__member(n_rel_id,set0000001.relations) ?
 F0000001(n_rel_id, q) :
 global__zero);
	return v(&set000000, x,y);
}

composed set00000;
composed *init00000(int n_rel_id, DIFF_CONST composed* q) {
	return init_neg(&set00000, "-", init000000(n_rel_id, q));
}
static DIFF_CONST composed* F00000(int n_rel_id, DIFF_CONST composed * q) {
	return neg(&set00000, F000000(n_rel_id, q));
}

composed set0000;
composed *init0000(int n_rel_id, DIFF_CONST composed* q) {
	return init_neg(&set0000, "-", init00000(n_rel_id, q));
}
static DIFF_CONST composed* F0000(int n_rel_id, DIFF_CONST composed * q) {
	return neg(&set0000, F00000(n_rel_id, q));
}

composed set000;
composed *init000(int n_rel_id, DIFF_CONST composed* q) {
	return init_c(&set000, 2, "c2", init0000(n_rel_id, q));
}
static DIFF_CONST composed* F000(int n_rel_id, DIFF_CONST composed * q) {
	return c(&set000, 2, F0000(n_rel_id, q));
}

composed set00;
composed *init00(int n_rel_id, DIFF_CONST composed* q) {
	return init_neg(&set00, "-", init000(n_rel_id, q));
}
static DIFF_CONST composed* F00(int n_rel_id, DIFF_CONST composed * q) {
	return neg(&set00, F000(n_rel_id, q));
}

composed set0;
composed *init0(int n_rel_id, DIFF_CONST composed* q) {
	return init_c(&set0, 1, "c1", init00(n_rel_id, q));
}
static DIFF_CONST composed* F0(int n_rel_id, DIFF_CONST composed * q) {
	return c(&set0, 1, F00(n_rel_id, q));
}

composed set;
composed *init(int n_rel_id, DIFF_CONST composed* q) {
	return init_axyz(&set, "aaa", init0(n_rel_id, q));
}
static DIFF_CONST composed* F(int n_rel_id, DIFF_CONST composed * q) {
	return axyz(&set, F0(n_rel_id, q));
}
