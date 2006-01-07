
composed set000000;
composed *init000000(int n_rel_id, const composed* q) {
	return init_R(&set000000, "mainLR_0", "r[mainLR_0,r(s(r(s(q))))]",0,r(s(r(s(q)))));
}
const composed* F000000(int n_rel_id, const composed * q) {
	return R(&set000000, 0, n_rel_id, r(s(r(s(q)))));
}

composed set00000;
composed *init00000(int n_rel_id, const composed* q) {
	return init_neg(&set00000, "-", init000000(n_rel_id, q));
}
const composed* F00000(int n_rel_id, const composed * q) {
	return neg(&set00000, F000000(n_rel_id, q));
}

composed set00001;
composed *init00001(int n_rel_id, const composed* q) {
	return init_R(&set00001, "mainLR_1", "r[mainLR_1,r(s(r(s(q))))]",1,r(s(r(s(q)))));
}
const composed* F00001(int n_rel_id, const composed * q) {
	return R(&set00001, 1, n_rel_id, r(s(r(s(q)))));
}

composed set0000;
composed *init0000(int n_rel_id, const composed* q) {
	return init_v(&set0000, "v", init00000(n_rel_id, q), init00001(n_rel_id, q));
}
const composed* F0000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set00000.relations) ?
 F00000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set00001.relations) ?
 F00001(n_rel_id, q) :
 global__zero);
	return v(&set0000, x,y);
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

composed set010000000;
composed *init010000000(int n_rel_id, const composed* q) {
	return init_R(&set010000000, "mainLR_1", "r[mainLR_1,r(s(r(s(q))))]",1,r(s(r(s(q)))));
}
const composed* F010000000(int n_rel_id, const composed * q) {
	return R(&set010000000, 1, n_rel_id, r(s(r(s(q)))));
}

composed set01000000;
composed *init01000000(int n_rel_id, const composed* q) {
	return init_neg(&set01000000, "-", init010000000(n_rel_id, q));
}
const composed* F01000000(int n_rel_id, const composed * q) {
	return neg(&set01000000, F010000000(n_rel_id, q));
}

composed set01000001;
composed *init01000001(int n_rel_id, const composed* q) {
	return init_R(&set01000001, "mainLR_2", "r[mainLR_2,r(s(r(s(q))))]",2,r(s(r(s(q)))));
}
const composed* F01000001(int n_rel_id, const composed * q) {
	return R(&set01000001, 2, n_rel_id, r(s(r(s(q)))));
}

composed set0100000;
composed *init0100000(int n_rel_id, const composed* q) {
	return init_v(&set0100000, "v", init01000000(n_rel_id, q), init01000001(n_rel_id, q));
}
const composed* F0100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01000000.relations) ?
 F01000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01000001.relations) ?
 F01000001(n_rel_id, q) :
 global__zero);
	return v(&set0100000, x,y);
}

composed set010000;
composed *init010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010000, "aaa", init0100000(n_rel_id, q));
}
const composed* F010000(int n_rel_id, const composed * q) {
	return axyz(&set010000, F0100000(n_rel_id, q));
}

composed set01000;
composed *init01000(int n_rel_id, const composed* q) {
	return init_neg(&set01000, "-", init010000(n_rel_id, q));
}
const composed* F01000(int n_rel_id, const composed * q) {
	return neg(&set01000, F010000(n_rel_id, q));
}

composed set010010000000000;
composed *init010010000000000(int n_rel_id, const composed* q) {
	return init_R(&set010010000000000, "mainLR_2", "r[mainLR_2,r(s(r(s(q))))]",2,r(s(r(s(q)))));
}
const composed* F010010000000000(int n_rel_id, const composed * q) {
	return R(&set010010000000000, 2, n_rel_id, r(s(r(s(q)))));
}

composed set01001000000000;
composed *init01001000000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001000000000, "-", init010010000000000(n_rel_id, q));
}
const composed* F01001000000000(int n_rel_id, const composed * q) {
	return neg(&set01001000000000, F010010000000000(n_rel_id, q));
}

composed set010010000000010000;
composed *init010010000000010000(int n_rel_id, const composed* q) {
	return init_R(&set010010000000010000, "succ", "r[succ,p(r(s(r(q))))]",3,p(r(s(r(q)))));
}
const composed* F010010000000010000(int n_rel_id, const composed * q) {
	return R(&set010010000000010000, 3, n_rel_id, p(r(s(r(q)))));
}

composed set01001000000001000;
composed *init01001000000001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001000000001000, "-", init010010000000010000(n_rel_id, q));
}
const composed* F01001000000001000(int n_rel_id, const composed * q) {
	return neg(&set01001000000001000, F010010000000010000(n_rel_id, q));
}

composed set010010000000010010;
composed *init010010000000010010(int n_rel_id, const composed* q) {
	return init_R(&set010010000000010010, "store_b", "r[store_b,r(r(s(r(q))))]",4,r(r(s(r(q)))));
}
const composed* F010010000000010010(int n_rel_id, const composed * q) {
	return R(&set010010000000010010, 4, n_rel_id, r(r(s(r(q)))));
}

composed set01001000000001001;
composed *init01001000000001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001000000001001, "-", init010010000000010010(n_rel_id, q));
}
const composed* F01001000000001001(int n_rel_id, const composed * q) {
	return neg(&set01001000000001001, F010010000000010010(n_rel_id, q));
}

composed set0100100000000100;
composed *init0100100000000100(int n_rel_id, const composed* q) {
	return init_v(&set0100100000000100, "v", init01001000000001000(n_rel_id, q), init01001000000001001(n_rel_id, q));
}
const composed* F0100100000000100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001000000001000.relations) ?
 F01001000000001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001000000001001.relations) ?
 F01001000000001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100000000100, x,y);
}

composed set010010000000010;
composed *init010010000000010(int n_rel_id, const composed* q) {
	return init_neg(&set010010000000010, "-", init0100100000000100(n_rel_id, q));
}
const composed* F010010000000010(int n_rel_id, const composed * q) {
	return neg(&set010010000000010, F0100100000000100(n_rel_id, q));
}

composed set01001000000001;
composed *init01001000000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001000000001, "-", init010010000000010(n_rel_id, q));
}
const composed* F01001000000001(int n_rel_id, const composed * q) {
	return neg(&set01001000000001, F010010000000010(n_rel_id, q));
}

composed set0100100000000;
composed *init0100100000000(int n_rel_id, const composed* q) {
	return init_v(&set0100100000000, "v", init01001000000000(n_rel_id, q), init01001000000001(n_rel_id, q));
}
const composed* F0100100000000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001000000000.relations) ?
 F01001000000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001000000001.relations) ?
 F01001000000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100000000, x,y);
}

composed set010010000000;
composed *init010010000000(int n_rel_id, const composed* q) {
	return init_neg(&set010010000000, "-", init0100100000000(n_rel_id, q));
}
const composed* F010010000000(int n_rel_id, const composed * q) {
	return neg(&set010010000000, F0100100000000(n_rel_id, q));
}

composed set01001000000;
composed *init01001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001000000, "-", init010010000000(n_rel_id, q));
}
const composed* F01001000000(int n_rel_id, const composed * q) {
	return neg(&set01001000000, F010010000000(n_rel_id, q));
}

composed set01001000001000;
composed *init01001000001000(int n_rel_id, const composed* q) {
	return init_R(&set01001000001000, "inc_b", "r[inc_b,r(p(s(r(q))))]",5,r(p(s(r(q)))));
}
const composed* F01001000001000(int n_rel_id, const composed * q) {
	return R(&set01001000001000, 5, n_rel_id, r(p(s(r(q)))));
}

composed set0100100000100;
composed *init0100100000100(int n_rel_id, const composed* q) {
	return init_neg(&set0100100000100, "-", init01001000001000(n_rel_id, q));
}
const composed* F0100100000100(int n_rel_id, const composed * q) {
	return neg(&set0100100000100, F01001000001000(n_rel_id, q));
}

composed set01001000001010000;
composed *init01001000001010000(int n_rel_id, const composed* q) {
	return init_R(&set01001000001010000, "copy_other_than_b", "r[copy_other_than_b,p(r(s(r(q))))]",6,p(r(s(r(q)))));
}
const composed* F01001000001010000(int n_rel_id, const composed * q) {
	return R(&set01001000001010000, 6, n_rel_id, p(r(s(r(q)))));
}

composed set0100100000101000;
composed *init0100100000101000(int n_rel_id, const composed* q) {
	return init_neg(&set0100100000101000, "-", init01001000001010000(n_rel_id, q));
}
const composed* F0100100000101000(int n_rel_id, const composed * q) {
	return neg(&set0100100000101000, F01001000001010000(n_rel_id, q));
}

composed set01001000001010010;
composed *init01001000001010010(int n_rel_id, const composed* q) {
	return init_R(&set01001000001010010, "mainLR_3", "r[mainLR_3,s(r(s(q)))]",7,s(r(s(q))));
}
const composed* F01001000001010010(int n_rel_id, const composed * q) {
	return R(&set01001000001010010, 7, n_rel_id, s(r(s(q))));
}

composed set0100100000101001;
composed *init0100100000101001(int n_rel_id, const composed* q) {
	return init_neg(&set0100100000101001, "-", init01001000001010010(n_rel_id, q));
}
const composed* F0100100000101001(int n_rel_id, const composed * q) {
	return neg(&set0100100000101001, F01001000001010010(n_rel_id, q));
}

composed set010010000010100;
composed *init010010000010100(int n_rel_id, const composed* q) {
	return init_v(&set010010000010100, "v", init0100100000101000(n_rel_id, q), init0100100000101001(n_rel_id, q));
}
const composed* F010010000010100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set0100100000101000.relations) ?
 F0100100000101000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set0100100000101001.relations) ?
 F0100100000101001(n_rel_id, q) :
 global__zero);
	return v(&set010010000010100, x,y);
}

composed set01001000001010;
composed *init01001000001010(int n_rel_id, const composed* q) {
	return init_neg(&set01001000001010, "-", init010010000010100(n_rel_id, q));
}
const composed* F01001000001010(int n_rel_id, const composed * q) {
	return neg(&set01001000001010, F010010000010100(n_rel_id, q));
}

composed set0100100000101;
composed *init0100100000101(int n_rel_id, const composed* q) {
	return init_neg(&set0100100000101, "-", init01001000001010(n_rel_id, q));
}
const composed* F0100100000101(int n_rel_id, const composed * q) {
	return neg(&set0100100000101, F01001000001010(n_rel_id, q));
}

composed set010010000010;
composed *init010010000010(int n_rel_id, const composed* q) {
	return init_v(&set010010000010, "v", init0100100000100(n_rel_id, q), init0100100000101(n_rel_id, q));
}
const composed* F010010000010(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set0100100000100.relations) ?
 F0100100000100(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set0100100000101.relations) ?
 F0100100000101(n_rel_id, q) :
 global__zero);
	return v(&set010010000010, x,y);
}

composed set01001000001;
composed *init01001000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001000001, "-", init010010000010(n_rel_id, q));
}
const composed* F01001000001(int n_rel_id, const composed * q) {
	return neg(&set01001000001, F010010000010(n_rel_id, q));
}

composed set0100100000;
composed *init0100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100000, "v", init01001000000(n_rel_id, q), init01001000001(n_rel_id, q));
}
const composed* F0100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001000000.relations) ?
 F01001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001000001.relations) ?
 F01001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100000, x,y);
}

composed set010010000;
composed *init010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010000, "aaa", init0100100000(n_rel_id, q));
}
const composed* F010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010000, F0100100000(n_rel_id, q));
}

composed set01001000;
composed *init01001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001000, "-", init010010000(n_rel_id, q));
}
const composed* F01001000(int n_rel_id, const composed * q) {
	return neg(&set01001000, F010010000(n_rel_id, q));
}

composed set010010010000000000;
composed *init010010010000000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010000000000, "mainLR_3", "r[mainLR_3,r(s(r(s(q))))]",7,r(s(r(s(q)))));
}
const composed* F010010010000000000(int n_rel_id, const composed * q) {
	return R(&set010010010000000000, 7, n_rel_id, r(s(r(s(q)))));
}

composed set01001001000000000;
composed *init01001001000000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001000000000, "-", init010010010000000000(n_rel_id, q));
}
const composed* F01001001000000000(int n_rel_id, const composed * q) {
	return neg(&set01001001000000000, F010010010000000000(n_rel_id, q));
}

composed set010010010000000010000;
composed *init010010010000000010000(int n_rel_id, const composed* q) {
	return init_R(&set010010010000000010000, "succ", "r[succ,p(r(s(r(q))))]",3,p(r(s(r(q)))));
}
const composed* F010010010000000010000(int n_rel_id, const composed * q) {
	return R(&set010010010000000010000, 3, n_rel_id, p(r(s(r(q)))));
}

composed set01001001000000001000;
composed *init01001001000000001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001000000001000, "-", init010010010000000010000(n_rel_id, q));
}
const composed* F01001001000000001000(int n_rel_id, const composed * q) {
	return neg(&set01001001000000001000, F010010010000000010000(n_rel_id, q));
}

composed set010010010000000010010;
composed *init010010010000000010010(int n_rel_id, const composed* q) {
	return init_R(&set010010010000000010010, "store_b", "r[store_b,r(r(s(r(q))))]",4,r(r(s(r(q)))));
}
const composed* F010010010000000010010(int n_rel_id, const composed * q) {
	return R(&set010010010000000010010, 4, n_rel_id, r(r(s(r(q)))));
}

composed set01001001000000001001;
composed *init01001001000000001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001000000001001, "-", init010010010000000010010(n_rel_id, q));
}
const composed* F01001001000000001001(int n_rel_id, const composed * q) {
	return neg(&set01001001000000001001, F010010010000000010010(n_rel_id, q));
}

composed set0100100100000000100;
composed *init0100100100000000100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100000000100, "v", init01001001000000001000(n_rel_id, q), init01001001000000001001(n_rel_id, q));
}
const composed* F0100100100000000100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001000000001000.relations) ?
 F01001001000000001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001000000001001.relations) ?
 F01001001000000001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100000000100, x,y);
}

composed set010010010000000010;
composed *init010010010000000010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010000000010, "-", init0100100100000000100(n_rel_id, q));
}
const composed* F010010010000000010(int n_rel_id, const composed * q) {
	return neg(&set010010010000000010, F0100100100000000100(n_rel_id, q));
}

composed set01001001000000001;
composed *init01001001000000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001000000001, "-", init010010010000000010(n_rel_id, q));
}
const composed* F01001001000000001(int n_rel_id, const composed * q) {
	return neg(&set01001001000000001, F010010010000000010(n_rel_id, q));
}

composed set0100100100000000;
composed *init0100100100000000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100000000, "v", init01001001000000000(n_rel_id, q), init01001001000000001(n_rel_id, q));
}
const composed* F0100100100000000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001000000000.relations) ?
 F01001001000000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001000000001.relations) ?
 F01001001000000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100000000, x,y);
}

composed set010010010000000;
composed *init010010010000000(int n_rel_id, const composed* q) {
	return init_neg(&set010010010000000, "-", init0100100100000000(n_rel_id, q));
}
const composed* F010010010000000(int n_rel_id, const composed * q) {
	return neg(&set010010010000000, F0100100100000000(n_rel_id, q));
}

composed set01001001000000;
composed *init01001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001000000, "-", init010010010000000(n_rel_id, q));
}
const composed* F01001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001000000, F010010010000000(n_rel_id, q));
}

composed set01001001000001000;
composed *init01001001000001000(int n_rel_id, const composed* q) {
	return init_R(&set01001001000001000, "dec_b", "r[dec_b,r(p(s(r(q))))]",8,r(p(s(r(q)))));
}
const composed* F01001001000001000(int n_rel_id, const composed * q) {
	return R(&set01001001000001000, 8, n_rel_id, r(p(s(r(q)))));
}

composed set0100100100000100;
composed *init0100100100000100(int n_rel_id, const composed* q) {
	return init_neg(&set0100100100000100, "-", init01001001000001000(n_rel_id, q));
}
const composed* F0100100100000100(int n_rel_id, const composed * q) {
	return neg(&set0100100100000100, F01001001000001000(n_rel_id, q));
}

composed set01001001000001010000;
composed *init01001001000001010000(int n_rel_id, const composed* q) {
	return init_R(&set01001001000001010000, "copy_other_than_b", "r[copy_other_than_b,p(r(s(r(q))))]",6,p(r(s(r(q)))));
}
const composed* F01001001000001010000(int n_rel_id, const composed * q) {
	return R(&set01001001000001010000, 6, n_rel_id, p(r(s(r(q)))));
}

composed set0100100100000101000;
composed *init0100100100000101000(int n_rel_id, const composed* q) {
	return init_neg(&set0100100100000101000, "-", init01001001000001010000(n_rel_id, q));
}
const composed* F0100100100000101000(int n_rel_id, const composed * q) {
	return neg(&set0100100100000101000, F01001001000001010000(n_rel_id, q));
}

composed set01001001000001010010;
composed *init01001001000001010010(int n_rel_id, const composed* q) {
	return init_R(&set01001001000001010010, "mainLR_4", "r[mainLR_4,s(r(s(q)))]",9,s(r(s(q))));
}
const composed* F01001001000001010010(int n_rel_id, const composed * q) {
	return R(&set01001001000001010010, 9, n_rel_id, s(r(s(q))));
}

composed set0100100100000101001;
composed *init0100100100000101001(int n_rel_id, const composed* q) {
	return init_neg(&set0100100100000101001, "-", init01001001000001010010(n_rel_id, q));
}
const composed* F0100100100000101001(int n_rel_id, const composed * q) {
	return neg(&set0100100100000101001, F01001001000001010010(n_rel_id, q));
}

composed set010010010000010100;
composed *init010010010000010100(int n_rel_id, const composed* q) {
	return init_v(&set010010010000010100, "v", init0100100100000101000(n_rel_id, q), init0100100100000101001(n_rel_id, q));
}
const composed* F010010010000010100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set0100100100000101000.relations) ?
 F0100100100000101000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set0100100100000101001.relations) ?
 F0100100100000101001(n_rel_id, q) :
 global__zero);
	return v(&set010010010000010100, x,y);
}

composed set01001001000001010;
composed *init01001001000001010(int n_rel_id, const composed* q) {
	return init_neg(&set01001001000001010, "-", init010010010000010100(n_rel_id, q));
}
const composed* F01001001000001010(int n_rel_id, const composed * q) {
	return neg(&set01001001000001010, F010010010000010100(n_rel_id, q));
}

composed set0100100100000101;
composed *init0100100100000101(int n_rel_id, const composed* q) {
	return init_neg(&set0100100100000101, "-", init01001001000001010(n_rel_id, q));
}
const composed* F0100100100000101(int n_rel_id, const composed * q) {
	return neg(&set0100100100000101, F01001001000001010(n_rel_id, q));
}

composed set010010010000010;
composed *init010010010000010(int n_rel_id, const composed* q) {
	return init_v(&set010010010000010, "v", init0100100100000100(n_rel_id, q), init0100100100000101(n_rel_id, q));
}
const composed* F010010010000010(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set0100100100000100.relations) ?
 F0100100100000100(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set0100100100000101.relations) ?
 F0100100100000101(n_rel_id, q) :
 global__zero);
	return v(&set010010010000010, x,y);
}

composed set01001001000001;
composed *init01001001000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001000001, "-", init010010010000010(n_rel_id, q));
}
const composed* F01001001000001(int n_rel_id, const composed * q) {
	return neg(&set01001001000001, F010010010000010(n_rel_id, q));
}

composed set0100100100000;
composed *init0100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100000, "v", init01001001000000(n_rel_id, q), init01001001000001(n_rel_id, q));
}
const composed* F0100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001000000.relations) ?
 F01001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001000001.relations) ?
 F01001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100000, x,y);
}

composed set010010010000;
composed *init010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010000, "aaa", init0100100100000(n_rel_id, q));
}
const composed* F010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010000, F0100100100000(n_rel_id, q));
}

composed set01001001000;
composed *init01001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001000, "-", init010010010000(n_rel_id, q));
}
const composed* F01001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001000, F010010010000(n_rel_id, q));
}

composed set010010010010000000000000;
composed *init010010010010000000000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010000000000000, "mainLR_4", "r[mainLR_4,r(s(r(s(q))))]",9,r(s(r(s(q)))));
}
const composed* F010010010010000000000000(int n_rel_id, const composed * q) {
	return R(&set010010010010000000000000, 9, n_rel_id, r(s(r(s(q)))));
}

composed set01001001001000000000000;
composed *init01001001001000000000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001000000000000, "-", init010010010010000000000000(n_rel_id, q));
}
const composed* F01001001001000000000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001000000000000, F010010010010000000000000(n_rel_id, q));
}

composed set010010010010000000000010;
composed *init010010010010000000000010(int n_rel_id, const composed* q) {
	return init_R(&set010010010010000000000010, "store_b", "r[store_b,r(r(s(r(q))))]",4,r(r(s(r(q)))));
}
const composed* F010010010010000000000010(int n_rel_id, const composed * q) {
	return R(&set010010010010000000000010, 4, n_rel_id, r(r(s(r(q)))));
}

composed set01001001001000000000001;
composed *init01001001001000000000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001000000000001, "-", init010010010010000000000010(n_rel_id, q));
}
const composed* F01001001001000000000001(int n_rel_id, const composed * q) {
	return neg(&set01001001001000000000001, F010010010010000000000010(n_rel_id, q));
}

composed set0100100100100000000000;
composed *init0100100100100000000000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100000000000, "v", init01001001001000000000000(n_rel_id, q), init01001001001000000000001(n_rel_id, q));
}
const composed* F0100100100100000000000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001000000000000.relations) ?
 F01001001001000000000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001000000000001.relations) ?
 F01001001001000000000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100000000000, x,y);
}

composed set010010010010000000000;
composed *init010010010010000000000(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010000000000, "-", init0100100100100000000000(n_rel_id, q));
}
const composed* F010010010010000000000(int n_rel_id, const composed * q) {
	return neg(&set010010010010000000000, F0100100100100000000000(n_rel_id, q));
}

composed set01001001001000000000;
composed *init01001001001000000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001000000000, "-", init010010010010000000000(n_rel_id, q));
}
const composed* F01001001001000000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001000000000, F010010010010000000000(n_rel_id, q));
}

composed set010010010010000000010;
composed *init010010010010000000010(int n_rel_id, const composed* q) {
	return init_R(&set010010010010000000010, "succ", "r[succ,p(r(s(r(q))))]",3,p(r(s(r(q)))));
}
const composed* F010010010010000000010(int n_rel_id, const composed * q) {
	return R(&set010010010010000000010, 3, n_rel_id, p(r(s(r(q)))));
}

composed set01001001001000000001;
composed *init01001001001000000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001000000001, "-", init010010010010000000010(n_rel_id, q));
}
const composed* F01001001001000000001(int n_rel_id, const composed * q) {
	return neg(&set01001001001000000001, F010010010010000000010(n_rel_id, q));
}

composed set0100100100100000000;
composed *init0100100100100000000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100000000, "v", init01001001001000000000(n_rel_id, q), init01001001001000000001(n_rel_id, q));
}
const composed* F0100100100100000000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001000000000.relations) ?
 F01001001001000000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001000000001.relations) ?
 F01001001001000000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100000000, x,y);
}

composed set010010010010000000;
composed *init010010010010000000(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010000000, "-", init0100100100100000000(n_rel_id, q));
}
const composed* F010010010010000000(int n_rel_id, const composed * q) {
	return neg(&set010010010010000000, F0100100100100000000(n_rel_id, q));
}

composed set01001001001000000;
composed *init01001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001000000, "-", init010010010010000000(n_rel_id, q));
}
const composed* F01001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001000000, F010010010010000000(n_rel_id, q));
}

composed set01001001001000001000;
composed *init01001001001000001000(int n_rel_id, const composed* q) {
	return init_R(&set01001001001000001000, "store_a", "r[store_a,r(p(s(r(q))))]",10,r(p(s(r(q)))));
}
const composed* F01001001001000001000(int n_rel_id, const composed * q) {
	return R(&set01001001001000001000, 10, n_rel_id, r(p(s(r(q)))));
}

composed set0100100100100000100;
composed *init0100100100100000100(int n_rel_id, const composed* q) {
	return init_neg(&set0100100100100000100, "-", init01001001001000001000(n_rel_id, q));
}
const composed* F0100100100100000100(int n_rel_id, const composed * q) {
	return neg(&set0100100100100000100, F01001001001000001000(n_rel_id, q));
}

composed set01001001001000001010000;
composed *init01001001001000001010000(int n_rel_id, const composed* q) {
	return init_R(&set01001001001000001010000, "copy_other_than_a", "r[copy_other_than_a,p(r(s(r(q))))]",11,p(r(s(r(q)))));
}
const composed* F01001001001000001010000(int n_rel_id, const composed * q) {
	return R(&set01001001001000001010000, 11, n_rel_id, p(r(s(r(q)))));
}

composed set0100100100100000101000;
composed *init0100100100100000101000(int n_rel_id, const composed* q) {
	return init_neg(&set0100100100100000101000, "-", init01001001001000001010000(n_rel_id, q));
}
const composed* F0100100100100000101000(int n_rel_id, const composed * q) {
	return neg(&set0100100100100000101000, F01001001001000001010000(n_rel_id, q));
}

composed set01001001001000001010010;
composed *init01001001001000001010010(int n_rel_id, const composed* q) {
	return init_R(&set01001001001000001010010, "mainLR_5", "r[mainLR_5,s(r(s(q)))]",12,s(r(s(q))));
}
const composed* F01001001001000001010010(int n_rel_id, const composed * q) {
	return R(&set01001001001000001010010, 12, n_rel_id, s(r(s(q))));
}

composed set0100100100100000101001;
composed *init0100100100100000101001(int n_rel_id, const composed* q) {
	return init_neg(&set0100100100100000101001, "-", init01001001001000001010010(n_rel_id, q));
}
const composed* F0100100100100000101001(int n_rel_id, const composed * q) {
	return neg(&set0100100100100000101001, F01001001001000001010010(n_rel_id, q));
}

composed set010010010010000010100;
composed *init010010010010000010100(int n_rel_id, const composed* q) {
	return init_v(&set010010010010000010100, "v", init0100100100100000101000(n_rel_id, q), init0100100100100000101001(n_rel_id, q));
}
const composed* F010010010010000010100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set0100100100100000101000.relations) ?
 F0100100100100000101000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set0100100100100000101001.relations) ?
 F0100100100100000101001(n_rel_id, q) :
 global__zero);
	return v(&set010010010010000010100, x,y);
}

composed set01001001001000001010;
composed *init01001001001000001010(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001000001010, "-", init010010010010000010100(n_rel_id, q));
}
const composed* F01001001001000001010(int n_rel_id, const composed * q) {
	return neg(&set01001001001000001010, F010010010010000010100(n_rel_id, q));
}

composed set0100100100100000101;
composed *init0100100100100000101(int n_rel_id, const composed* q) {
	return init_neg(&set0100100100100000101, "-", init01001001001000001010(n_rel_id, q));
}
const composed* F0100100100100000101(int n_rel_id, const composed * q) {
	return neg(&set0100100100100000101, F01001001001000001010(n_rel_id, q));
}

composed set010010010010000010;
composed *init010010010010000010(int n_rel_id, const composed* q) {
	return init_v(&set010010010010000010, "v", init0100100100100000100(n_rel_id, q), init0100100100100000101(n_rel_id, q));
}
const composed* F010010010010000010(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set0100100100100000100.relations) ?
 F0100100100100000100(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set0100100100100000101.relations) ?
 F0100100100100000101(n_rel_id, q) :
 global__zero);
	return v(&set010010010010000010, x,y);
}

composed set01001001001000001;
composed *init01001001001000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001000001, "-", init010010010010000010(n_rel_id, q));
}
const composed* F01001001001000001(int n_rel_id, const composed * q) {
	return neg(&set01001001001000001, F010010010010000010(n_rel_id, q));
}

composed set0100100100100000;
composed *init0100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100000, "v", init01001001001000000(n_rel_id, q), init01001001001000001(n_rel_id, q));
}
const composed* F0100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001000000.relations) ?
 F01001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001000001.relations) ?
 F01001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100000, x,y);
}

composed set010010010010000;
composed *init010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010000, "aaa", init0100100100100000(n_rel_id, q));
}
const composed* F010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010000, F0100100100100000(n_rel_id, q));
}

composed set01001001001000;
composed *init01001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001000, "-", init010010010010000(n_rel_id, q));
}
const composed* F01001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001000, F010010010010000(n_rel_id, q));
}

composed set010010010010010000000000;
composed *init010010010010010000000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010000000000, "mainLR_5", "r[mainLR_5,r(s(r(s(q))))]",12,r(s(r(s(q)))));
}
const composed* F010010010010010000000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010000000000, 12, n_rel_id, r(s(r(s(q)))));
}

composed set01001001001001000000000;
composed *init01001001001001000000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001000000000, "-", init010010010010010000000000(n_rel_id, q));
}
const composed* F01001001001001000000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001000000000, F010010010010010000000000(n_rel_id, q));
}

composed set010010010010010000000010000;
composed *init010010010010010000000010000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010000000010000, "store_a", "r[store_a,p(r(s(r(q))))]",10,p(r(s(r(q)))));
}
const composed* F010010010010010000000010000(int n_rel_id, const composed * q) {
	return R(&set010010010010010000000010000, 10, n_rel_id, p(r(s(r(q)))));
}

composed set01001001001001000000001000;
composed *init01001001001001000000001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001000000001000, "-", init010010010010010000000010000(n_rel_id, q));
}
const composed* F01001001001001000000001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001000000001000, F010010010010010000000010000(n_rel_id, q));
}

composed set010010010010010000000010010;
composed *init010010010010010000000010010(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010000000010010, "zero", "r[zero,s(r(s(q)))]",13,s(r(s(q))));
}
const composed* F010010010010010000000010010(int n_rel_id, const composed * q) {
	return R(&set010010010010010000000010010, 13, n_rel_id, s(r(s(q))));
}

composed set01001001001001000000001001;
composed *init01001001001001000000001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001000000001001, "-", init010010010010010000000010010(n_rel_id, q));
}
const composed* F01001001001001000000001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001000000001001, F010010010010010000000010010(n_rel_id, q));
}

composed set0100100100100100000000100;
composed *init0100100100100100000000100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100000000100, "v", init01001001001001000000001000(n_rel_id, q), init01001001001001000000001001(n_rel_id, q));
}
const composed* F0100100100100100000000100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001000000001000.relations) ?
 F01001001001001000000001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001000000001001.relations) ?
 F01001001001001000000001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100000000100, x,y);
}

composed set010010010010010000000010;
composed *init010010010010010000000010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010000000010, "-", init0100100100100100000000100(n_rel_id, q));
}
const composed* F010010010010010000000010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010000000010, F0100100100100100000000100(n_rel_id, q));
}

composed set01001001001001000000001;
composed *init01001001001001000000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001000000001, "-", init010010010010010000000010(n_rel_id, q));
}
const composed* F01001001001001000000001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001000000001, F010010010010010000000010(n_rel_id, q));
}

composed set0100100100100100000000;
composed *init0100100100100100000000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100000000, "v", init01001001001001000000000(n_rel_id, q), init01001001001001000000001(n_rel_id, q));
}
const composed* F0100100100100100000000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001000000000.relations) ?
 F01001001001001000000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001000000001.relations) ?
 F01001001001001000000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100000000, x,y);
}

composed set010010010010010000000;
composed *init010010010010010000000(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010000000, "-", init0100100100100100000000(n_rel_id, q));
}
const composed* F010010010010010000000(int n_rel_id, const composed * q) {
	return neg(&set010010010010010000000, F0100100100100100000000(n_rel_id, q));
}

composed set01001001001001000000;
composed *init01001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001000000, "-", init010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001000000, F010010010010010000000(n_rel_id, q));
}

composed set01001001001001000001;
composed *init01001001001001000001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001000001, "halt_0", "r[halt_0,r(s(r(s(q))))]",14,r(s(r(s(q)))));
}
const composed* F01001001001001000001(int n_rel_id, const composed * q) {
	return R(&set01001001001001000001, 14, n_rel_id, r(s(r(s(q)))));
}

composed set0100100100100100000;
composed *init0100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100000, "v", init01001001001001000000(n_rel_id, q), init01001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001000000.relations) ?
 F01001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001000001.relations) ?
 F01001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100000, x,y);
}

composed set010010010010010000;
composed *init010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010000, "aaa", init0100100100100100000(n_rel_id, q));
}
const composed* F010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010000, F0100100100100100000(n_rel_id, q));
}

composed set01001001001001000;
composed *init01001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001000, "-", init010010010010010000(n_rel_id, q));
}
const composed* F01001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001000, F010010010010010000(n_rel_id, q));
}

composed set010010010010010010000000000;
composed *init010010010010010010000000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010000000000, "mainLR_5", "r[mainLR_5,r(s(r(s(q))))]",12,r(s(r(s(q)))));
}
const composed* F010010010010010010000000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010000000000, 12, n_rel_id, r(s(r(s(q)))));
}

composed set01001001001001001000000000;
composed *init01001001001001001000000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001000000000, "-", init010010010010010010000000000(n_rel_id, q));
}
const composed* F01001001001001001000000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001000000000, F010010010010010010000000000(n_rel_id, q));
}

composed set010010010010010010000000010000;
composed *init010010010010010010000000010000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010000000010000, "store_a", "r[store_a,p(r(s(r(q))))]",10,p(r(s(r(q)))));
}
const composed* F010010010010010010000000010000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010000000010000, 10, n_rel_id, p(r(s(r(q)))));
}

composed set01001001001001001000000001000;
composed *init01001001001001001000000001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001000000001000, "-", init010010010010010010000000010000(n_rel_id, q));
}
const composed* F01001001001001001000000001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001000000001000, F010010010010010010000000010000(n_rel_id, q));
}

composed set010010010010010010000000010010;
composed *init010010010010010010000000010010(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010000000010010, "nonzero", "r[nonzero,s(r(s(q)))]",15,s(r(s(q))));
}
const composed* F010010010010010010000000010010(int n_rel_id, const composed * q) {
	return R(&set010010010010010010000000010010, 15, n_rel_id, s(r(s(q))));
}

composed set01001001001001001000000001001;
composed *init01001001001001001000000001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001000000001001, "-", init010010010010010010000000010010(n_rel_id, q));
}
const composed* F01001001001001001000000001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001000000001001, F010010010010010010000000010010(n_rel_id, q));
}

composed set0100100100100100100000000100;
composed *init0100100100100100100000000100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100000000100, "v", init01001001001001001000000001000(n_rel_id, q), init01001001001001001000000001001(n_rel_id, q));
}
const composed* F0100100100100100100000000100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001000000001000.relations) ?
 F01001001001001001000000001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001000000001001.relations) ?
 F01001001001001001000000001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100000000100, x,y);
}

composed set010010010010010010000000010;
composed *init010010010010010010000000010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010000000010, "-", init0100100100100100100000000100(n_rel_id, q));
}
const composed* F010010010010010010000000010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010000000010, F0100100100100100100000000100(n_rel_id, q));
}

composed set01001001001001001000000001;
composed *init01001001001001001000000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001000000001, "-", init010010010010010010000000010(n_rel_id, q));
}
const composed* F01001001001001001000000001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001000000001, F010010010010010010000000010(n_rel_id, q));
}

composed set0100100100100100100000000;
composed *init0100100100100100100000000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100000000, "v", init01001001001001001000000000(n_rel_id, q), init01001001001001001000000001(n_rel_id, q));
}
const composed* F0100100100100100100000000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001000000000.relations) ?
 F01001001001001001000000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001000000001.relations) ?
 F01001001001001001000000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100000000, x,y);
}

composed set010010010010010010000000;
composed *init010010010010010010000000(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010000000, "-", init0100100100100100100000000(n_rel_id, q));
}
const composed* F010010010010010010000000(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010000000, F0100100100100100100000000(n_rel_id, q));
}

composed set01001001001001001000000;
composed *init01001001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001000000, "-", init010010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001000000, F010010010010010010000000(n_rel_id, q));
}

composed set01001001001001001000001;
composed *init01001001001001001000001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001000001, "mainLR_0", "r[mainLR_0,r(s(r(s(q))))]",0,r(s(r(s(q)))));
}
const composed* F01001001001001001000001(int n_rel_id, const composed * q) {
	return R(&set01001001001001001000001, 0, n_rel_id, r(s(r(s(q)))));
}

composed set0100100100100100100000;
composed *init0100100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100000, "v", init01001001001001001000000(n_rel_id, q), init01001001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001000000.relations) ?
 F01001001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001000001.relations) ?
 F01001001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100000, x,y);
}

composed set010010010010010010000;
composed *init010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010000, "aaa", init0100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010000, F0100100100100100100000(n_rel_id, q));
}

composed set01001001001001001000;
composed *init01001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001000, "-", init010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001000, F010010010010010010000(n_rel_id, q));
}

composed set010010010010010010010000000;
composed *init010010010010010010010000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010000000, "zero", "r[zero,r(s(r(s(q))))]",13,r(s(r(s(q)))));
}
const composed* F010010010010010010010000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010000000, 13, n_rel_id, r(s(r(s(q)))));
}

composed set01001001001001001001000000;
composed *init01001001001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001000000, "-", init010010010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001000000, F010010010010010010010000000(n_rel_id, q));
}

composed set01001001001001001001000001;
composed *init01001001001001001001000001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001000001, "store_a", "r[store_a,r(s(r(s(q))))]",10,r(s(r(s(q)))));
}
const composed* F01001001001001001001000001(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001000001, 10, n_rel_id, r(s(r(s(q)))));
}

composed set0100100100100100100100000;
composed *init0100100100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100000, "v", init01001001001001001001000000(n_rel_id, q), init01001001001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001000000.relations) ?
 F01001001001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001000001.relations) ?
 F01001001001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100000, x,y);
}

composed set010010010010010010010000;
composed *init010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010000, "aaa", init0100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010000, F0100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001000;
composed *init01001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001000, "-", init010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001000, F010010010010010010010000(n_rel_id, q));
}

composed set010010010010010010010010000000000;
composed *init010010010010010010010010000000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010000000000, "copy_a", "r[copy_a,p(r(s(r(q))))]",16,p(r(s(r(q)))));
}
const composed* F010010010010010010010010000000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010000000000, 16, n_rel_id, p(r(s(r(q)))));
}

composed set01001001001001001001001000000000;
composed *init01001001001001001001001000000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001000000000, "-", init010010010010010010010010000000000(n_rel_id, q));
}
const composed* F01001001001001001001001000000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001000000000, F010010010010010010010010000000000(n_rel_id, q));
}

composed set010010010010010010010010000000010;
composed *init010010010010010010010010000000010(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010000000010, "store_a", "r[store_a,r(r(s(r(q))))]",10,r(r(s(r(q)))));
}
const composed* F010010010010010010010010000000010(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010000000010, 10, n_rel_id, r(r(s(r(q)))));
}

composed set01001001001001001001001000000001;
composed *init01001001001001001001001000000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001000000001, "-", init010010010010010010010010000000010(n_rel_id, q));
}
const composed* F01001001001001001001001000000001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001000000001, F010010010010010010010010000000010(n_rel_id, q));
}

composed set0100100100100100100100100000000;
composed *init0100100100100100100100100000000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100000000, "v", init01001001001001001001001000000000(n_rel_id, q), init01001001001001001001001000000001(n_rel_id, q));
}
const composed* F0100100100100100100100100000000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001000000000.relations) ?
 F01001001001001001001001000000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001000000001.relations) ?
 F01001001001001001001001000000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100000000, x,y);
}

composed set010010010010010010010010000000;
composed *init010010010010010010010010000000(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010000000, "-", init0100100100100100100100100000000(n_rel_id, q));
}
const composed* F010010010010010010010010000000(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010000000, F0100100100100100100100100000000(n_rel_id, q));
}

composed set01001001001001001001001000000;
composed *init01001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001000000, "-", init010010010010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001000000, F010010010010010010010010000000(n_rel_id, q));
}

composed set01001001001001001001001000001;
composed *init01001001001001001001001000001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001000001, "store_a", "r[store_a,r(p(s(r(q))))]",10,r(p(s(r(q)))));
}
const composed* F01001001001001001001001000001(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001000001, 10, n_rel_id, r(p(s(r(q)))));
}

composed set0100100100100100100100100000;
composed *init0100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100000, "v", init01001001001001001001001000000(n_rel_id, q), init01001001001001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001000000.relations) ?
 F01001001001001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001000001.relations) ?
 F01001001001001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100000, x,y);
}

composed set010010010010010010010010000;
composed *init010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010000, "aaa", init0100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010000, F0100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001000;
composed *init01001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001000, "-", init010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001000, F010010010010010010010010000(n_rel_id, q));
}

composed set010010010010010010010010010000000;
composed *init010010010010010010010010010000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010000000, "copy_other_than_a", "r[copy_other_than_a,p(r(s(r(q))))]",11,p(r(s(r(q)))));
}
const composed* F010010010010010010010010010000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010000000, 11, n_rel_id, p(r(s(r(q)))));
}

composed set01001001001001001001001001000000;
composed *init01001001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001000000, "-", init010010010010010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001000000, F010010010010010010010010010000000(n_rel_id, q));
}

composed set01001001001001001001001001000001;
composed *init01001001001001001001001001000001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001001000001, "copy_b", "r[copy_b,p(r(s(r(q))))]",17,p(r(s(r(q)))));
}
const composed* F01001001001001001001001001000001(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001001000001, 17, n_rel_id, p(r(s(r(q)))));
}

composed set0100100100100100100100100100000;
composed *init0100100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100000, "v", init01001001001001001001001001000000(n_rel_id, q), init01001001001001001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001000000.relations) ?
 F01001001001001001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001000001.relations) ?
 F01001001001001001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100000, x,y);
}

composed set010010010010010010010010010000;
composed *init010010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010010000, "aaa", init0100100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010010000, F0100100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001001000;
composed *init01001001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001000, "-", init010010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001000, F010010010010010010010010010000(n_rel_id, q));
}

composed set010010010010010010010010010010000000000;
composed *init010010010010010010010010010010000000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010000000000, "inc_a", "r[inc_a,r(r(s(r(q))))]",18,r(r(s(r(q)))));
}
const composed* F010010010010010010010010010010000000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010000000000, 18, n_rel_id, r(r(s(r(q)))));
}

composed set01001001001001001001001001001000000000;
composed *init01001001001001001001001001001000000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001000000000, "-", init010010010010010010010010010010000000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001000000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001000000000, F010010010010010010010010010010000000000(n_rel_id, q));
}

composed set010010010010010010010010010010000000010;
composed *init010010010010010010010010010010000000010(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010000000010, "succ", "r[succ,s(r(q))]",3,s(r(q)));
}
const composed* F010010010010010010010010010010000000010(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010000000010, 3, n_rel_id, s(r(q)));
}

composed set01001001001001001001001001001000000001;
composed *init01001001001001001001001001001000000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001000000001, "-", init010010010010010010010010010010000000010(n_rel_id, q));
}
const composed* F01001001001001001001001001001000000001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001000000001, F010010010010010010010010010010000000010(n_rel_id, q));
}

composed set0100100100100100100100100100100000000;
composed *init0100100100100100100100100100100000000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100000000, "v", init01001001001001001001001001001000000000(n_rel_id, q), init01001001001001001001001001001000000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100000000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001000000000.relations) ?
 F01001001001001001001001001001000000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001000000001.relations) ?
 F01001001001001001001001001001000000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100000000, x,y);
}

composed set010010010010010010010010010010000000;
composed *init010010010010010010010010010010000000(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010000000, "-", init0100100100100100100100100100100000000(n_rel_id, q));
}
const composed* F010010010010010010010010010010000000(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010000000, F0100100100100100100100100100100000000(n_rel_id, q));
}

composed set01001001001001001001001001001000000;
composed *init01001001001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001000000, "-", init010010010010010010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001000000, F010010010010010010010010010010000000(n_rel_id, q));
}

composed set01001001001001001001001001001000001;
composed *init01001001001001001001001001001000001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001001001000001, "store_a", "r[store_a,p(r(s(r(q))))]",10,p(r(s(r(q)))));
}
const composed* F01001001001001001001001001001000001(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001001001000001, 10, n_rel_id, p(r(s(r(q)))));
}

composed set0100100100100100100100100100100000;
composed *init0100100100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100000, "v", init01001001001001001001001001001000000(n_rel_id, q), init01001001001001001001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001000000.relations) ?
 F01001001001001001001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001000001.relations) ?
 F01001001001001001001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100000, x,y);
}

composed set010010010010010010010010010010000;
composed *init010010010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010010010000, "aaa", init0100100100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010010010000, F0100100100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001001001000;
composed *init01001001001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001000, "-", init010010010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001000, F010010010010010010010010010010000(n_rel_id, q));
}

composed set010010010010010010010010010010010000000000;
composed *init010010010010010010010010010010010000000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010000000000, "dec_a", "r[dec_a,r(r(s(r(q))))]",19,r(r(s(r(q)))));
}
const composed* F010010010010010010010010010010010000000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010000000000, 19, n_rel_id, r(r(s(r(q)))));
}

composed set01001001001001001001001001001001000000000;
composed *init01001001001001001001001001001001000000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001000000000, "-", init010010010010010010010010010010010000000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001000000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001000000000, F010010010010010010010010010010010000000000(n_rel_id, q));
}

composed set010010010010010010010010010010010000000010;
composed *init010010010010010010010010010010010000000010(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010000000010, "succ", "r[succ,r(p(s(r(q))))]",3,r(p(s(r(q)))));
}
const composed* F010010010010010010010010010010010000000010(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010000000010, 3, n_rel_id, r(p(s(r(q)))));
}

composed set01001001001001001001001001001001000000001;
composed *init01001001001001001001001001001001000000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001000000001, "-", init010010010010010010010010010010010000000010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001000000001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001000000001, F010010010010010010010010010010010000000010(n_rel_id, q));
}

composed set0100100100100100100100100100100100000000;
composed *init0100100100100100100100100100100100000000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100000000, "v", init01001001001001001001001001001001000000000(n_rel_id, q), init01001001001001001001001001001001000000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100000000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001000000000.relations) ?
 F01001001001001001001001001001001000000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001000000001.relations) ?
 F01001001001001001001001001001001000000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100000000, x,y);
}

composed set010010010010010010010010010010010000000;
composed *init010010010010010010010010010010010000000(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010000000, "-", init0100100100100100100100100100100100000000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010000000(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010000000, F0100100100100100100100100100100100000000(n_rel_id, q));
}

composed set01001001001001001001001001001001000000;
composed *init01001001001001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001000000, "-", init010010010010010010010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001000000, F010010010010010010010010010010010000000(n_rel_id, q));
}

composed set01001001001001001001001001001001000001;
composed *init01001001001001001001001001001001000001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001001001001000001, "store_a", "r[store_a,p(r(s(r(q))))]",10,p(r(s(r(q)))));
}
const composed* F01001001001001001001001001001001000001(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001001001001000001, 10, n_rel_id, p(r(s(r(q)))));
}

composed set0100100100100100100100100100100100000;
composed *init0100100100100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100000, "v", init01001001001001001001001001001001000000(n_rel_id, q), init01001001001001001001001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001000000.relations) ?
 F01001001001001001001001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001000001.relations) ?
 F01001001001001001001001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100000, x,y);
}

composed set010010010010010010010010010010010000;
composed *init010010010010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010010010010000, "aaa", init0100100100100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010010010010000, F0100100100100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001001001001000;
composed *init01001001001001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001000, "-", init010010010010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001000, F010010010010010010010010010010010000(n_rel_id, q));
}

composed set010010010010010010010010010010010010000000;
composed *init010010010010010010010010010010010010000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010010000000, "zero", "r[zero,r(s(r(s(q))))]",13,r(s(r(s(q)))));
}
const composed* F010010010010010010010010010010010010000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010010000000, 13, n_rel_id, r(s(r(s(q)))));
}

composed set01001001001001001001001001001001001000000;
composed *init01001001001001001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001000000, "-", init010010010010010010010010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001000000, F010010010010010010010010010010010010000000(n_rel_id, q));
}

composed set01001001001001001001001001001001001000001;
composed *init01001001001001001001001001001001001000001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001001001001001000001, "store_b", "r[store_b,r(s(r(s(q))))]",4,r(s(r(s(q)))));
}
const composed* F01001001001001001001001001001001001000001(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001001001001001000001, 4, n_rel_id, r(s(r(s(q)))));
}

composed set0100100100100100100100100100100100100000;
composed *init0100100100100100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100000, "v", init01001001001001001001001001001001001000000(n_rel_id, q), init01001001001001001001001001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001000000.relations) ?
 F01001001001001001001001001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001000001.relations) ?
 F01001001001001001001001001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100000, x,y);
}

composed set010010010010010010010010010010010010000;
composed *init010010010010010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010010010010010000, "aaa", init0100100100100100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010010010010010000, F0100100100100100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001001001001001000;
composed *init01001001001001001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001000, "-", init010010010010010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001000, F010010010010010010010010010010010010000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010000000000;
composed *init010010010010010010010010010010010010010000000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010010010000000000, "copy_b", "r[copy_b,p(r(s(r(q))))]",17,p(r(s(r(q)))));
}
const composed* F010010010010010010010010010010010010010000000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010010010000000000, 17, n_rel_id, p(r(s(r(q)))));
}

composed set01001001001001001001001001001001001001000000000;
composed *init01001001001001001001001001001001001001000000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001000000000, "-", init010010010010010010010010010010010010010000000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001000000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001000000000, F010010010010010010010010010010010010010000000000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010000000010;
composed *init010010010010010010010010010010010010010000000010(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010010010000000010, "store_b", "r[store_b,r(r(s(r(q))))]",4,r(r(s(r(q)))));
}
const composed* F010010010010010010010010010010010010010000000010(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010010010000000010, 4, n_rel_id, r(r(s(r(q)))));
}

composed set01001001001001001001001001001001001001000000001;
composed *init01001001001001001001001001001001001001000000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001000000001, "-", init010010010010010010010010010010010010010000000010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001000000001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001000000001, F010010010010010010010010010010010010010000000010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100100000000;
composed *init0100100100100100100100100100100100100100000000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100000000, "v", init01001001001001001001001001001001001001000000000(n_rel_id, q), init01001001001001001001001001001001001001000000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100000000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001000000000.relations) ?
 F01001001001001001001001001001001001001000000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001000000001.relations) ?
 F01001001001001001001001001001001001001000000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100000000, x,y);
}

composed set010010010010010010010010010010010010010000000;
composed *init010010010010010010010010010010010010010000000(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010010000000, "-", init0100100100100100100100100100100100100100000000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010000000(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010010000000, F0100100100100100100100100100100100100100000000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001000000;
composed *init01001001001001001001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001000000, "-", init010010010010010010010010010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001000000, F010010010010010010010010010010010010010000000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001000001;
composed *init01001001001001001001001001001001001001000001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001001001001001001000001, "store_b", "r[store_b,r(p(s(r(q))))]",4,r(p(s(r(q)))));
}
const composed* F01001001001001001001001001001001001001000001(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001001001001001001000001, 4, n_rel_id, r(p(s(r(q)))));
}

composed set0100100100100100100100100100100100100100000;
composed *init0100100100100100100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100000, "v", init01001001001001001001001001001001001001000000(n_rel_id, q), init01001001001001001001001001001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001000000.relations) ?
 F01001001001001001001001001001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001000001.relations) ?
 F01001001001001001001001001001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100000, x,y);
}

composed set010010010010010010010010010010010010010000;
composed *init010010010010010010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010010010010010010000, "aaa", init0100100100100100100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010010010010010010000, F0100100100100100100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001000;
composed *init01001001001001001001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001000, "-", init010010010010010010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001000, F010010010010010010010010010010010010010000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010010000000;
composed *init010010010010010010010010010010010010010010000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010010010010000000, "copy_other_than_b", "r[copy_other_than_b,p(r(s(r(q))))]",6,p(r(s(r(q)))));
}
const composed* F010010010010010010010010010010010010010010000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010010010010000000, 6, n_rel_id, p(r(s(r(q)))));
}

composed set01001001001001001001001001001001001001001000000;
composed *init01001001001001001001001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001000000, "-", init010010010010010010010010010010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001000000, F010010010010010010010010010010010010010010000000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001000001;
composed *init01001001001001001001001001001001001001001000001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001001001001001001001000001, "copy_a", "r[copy_a,p(r(s(r(q))))]",16,p(r(s(r(q)))));
}
const composed* F01001001001001001001001001001001001001001000001(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001001001001001001001000001, 16, n_rel_id, p(r(s(r(q)))));
}

composed set0100100100100100100100100100100100100100100000;
composed *init0100100100100100100100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100000, "v", init01001001001001001001001001001001001001001000000(n_rel_id, q), init01001001001001001001001001001001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001000000.relations) ?
 F01001001001001001001001001001001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001000001.relations) ?
 F01001001001001001001001001001001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100000, x,y);
}

composed set010010010010010010010010010010010010010010000;
composed *init010010010010010010010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010010010010010010010000, "aaa", init0100100100100100100100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010010010010010010010000, F0100100100100100100100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001000;
composed *init01001001001001001001001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001000, "-", init010010010010010010010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001000, F010010010010010010010010010010010010010010000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010010010000000000;
composed *init010010010010010010010010010010010010010010010000000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010010010010010000000000, "inc_b", "r[inc_b,r(r(s(r(q))))]",5,r(r(s(r(q)))));
}
const composed* F010010010010010010010010010010010010010010010000000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010010010010010000000000, 5, n_rel_id, r(r(s(r(q)))));
}

composed set01001001001001001001001001001001001001001001000000000;
composed *init01001001001001001001001001001001001001001001000000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001000000000, "-", init010010010010010010010010010010010010010010010000000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001000000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001000000000, F010010010010010010010010010010010010010010010000000000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010010010000000010;
composed *init010010010010010010010010010010010010010010010000000010(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010010010010010000000010, "succ", "r[succ,s(r(q))]",3,s(r(q)));
}
const composed* F010010010010010010010010010010010010010010010000000010(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010010010010010000000010, 3, n_rel_id, s(r(q)));
}

composed set01001001001001001001001001001001001001001001000000001;
composed *init01001001001001001001001001001001001001001001000000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001000000001, "-", init010010010010010010010010010010010010010010010000000010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001000000001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001000000001, F010010010010010010010010010010010010010010010000000010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100100100100000000;
composed *init0100100100100100100100100100100100100100100100000000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100000000, "v", init01001001001001001001001001001001001001001001000000000(n_rel_id, q), init01001001001001001001001001001001001001001001000000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100000000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001000000000.relations) ?
 F01001001001001001001001001001001001001001001000000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001000000001.relations) ?
 F01001001001001001001001001001001001001001001000000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100000000, x,y);
}

composed set010010010010010010010010010010010010010010010000000;
composed *init010010010010010010010010010010010010010010010000000(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010010010010000000, "-", init0100100100100100100100100100100100100100100100000000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010000000(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010010010010000000, F0100100100100100100100100100100100100100100100000000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001000000;
composed *init01001001001001001001001001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001000000, "-", init010010010010010010010010010010010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001000000, F010010010010010010010010010010010010010010010000000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001000001;
composed *init01001001001001001001001001001001001001001001000001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001001001001001001001001000001, "store_b", "r[store_b,p(r(s(r(q))))]",4,p(r(s(r(q)))));
}
const composed* F01001001001001001001001001001001001001001001000001(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001001001001001001001001000001, 4, n_rel_id, p(r(s(r(q)))));
}

composed set0100100100100100100100100100100100100100100100000;
composed *init0100100100100100100100100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100000, "v", init01001001001001001001001001001001001001001001000000(n_rel_id, q), init01001001001001001001001001001001001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001000000.relations) ?
 F01001001001001001001001001001001001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001000001.relations) ?
 F01001001001001001001001001001001001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100000, x,y);
}

composed set010010010010010010010010010010010010010010010000;
composed *init010010010010010010010010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010010010010010010010010000, "aaa", init0100100100100100100100100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010010010010010010010010000, F0100100100100100100100100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001000;
composed *init01001001001001001001001001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001000, "-", init010010010010010010010010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001000, F010010010010010010010010010010010010010010010000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010010010010000000000;
composed *init010010010010010010010010010010010010010010010010000000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010010010010010010000000000, "dec_b", "r[dec_b,r(r(s(r(q))))]",8,r(r(s(r(q)))));
}
const composed* F010010010010010010010010010010010010010010010010000000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010010010010010010000000000, 8, n_rel_id, r(r(s(r(q)))));
}

composed set01001001001001001001001001001001001001001001001000000000;
composed *init01001001001001001001001001001001001001001001001000000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001000000000, "-", init010010010010010010010010010010010010010010010010000000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001000000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001000000000, F010010010010010010010010010010010010010010010010000000000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010010010010000000010;
composed *init010010010010010010010010010010010010010010010010000000010(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010010010010010010000000010, "succ", "r[succ,r(p(s(r(q))))]",3,r(p(s(r(q)))));
}
const composed* F010010010010010010010010010010010010010010010010000000010(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010010010010010010000000010, 3, n_rel_id, r(p(s(r(q)))));
}

composed set01001001001001001001001001001001001001001001001000000001;
composed *init01001001001001001001001001001001001001001001001000000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001000000001, "-", init010010010010010010010010010010010010010010010010000000010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001000000001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001000000001, F010010010010010010010010010010010010010010010010000000010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100100100100100000000;
composed *init0100100100100100100100100100100100100100100100100000000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100100000000, "v", init01001001001001001001001001001001001001001001001000000000(n_rel_id, q), init01001001001001001001001001001001001001001001001000000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100000000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001001000000000.relations) ?
 F01001001001001001001001001001001001001001001001000000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001001000000001.relations) ?
 F01001001001001001001001001001001001001001001001000000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100100000000, x,y);
}

composed set010010010010010010010010010010010010010010010010000000;
composed *init010010010010010010010010010010010010010010010010000000(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010010010010010000000, "-", init0100100100100100100100100100100100100100100100100000000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010000000(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010010010010010000000, F0100100100100100100100100100100100100100100100100000000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001000000;
composed *init01001001001001001001001001001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001000000, "-", init010010010010010010010010010010010010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001000000, F010010010010010010010010010010010010010010010010000000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001000001;
composed *init01001001001001001001001001001001001001001001001000001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001001001001001001001001001000001, "store_b", "r[store_b,p(r(s(r(q))))]",4,p(r(s(r(q)))));
}
const composed* F01001001001001001001001001001001001001001001001000001(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001001001001001001001001001000001, 4, n_rel_id, p(r(s(r(q)))));
}

composed set0100100100100100100100100100100100100100100100100000;
composed *init0100100100100100100100100100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100100000, "v", init01001001001001001001001001001001001001001001001000000(n_rel_id, q), init01001001001001001001001001001001001001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001001000000.relations) ?
 F01001001001001001001001001001001001001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001001000001.relations) ?
 F01001001001001001001001001001001001001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100100000, x,y);
}

composed set010010010010010010010010010010010010010010010010000;
composed *init010010010010010010010010010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010010010010010010010010010000, "aaa", init0100100100100100100100100100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010010010010010010010010010000, F0100100100100100100100100100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001000;
composed *init01001001001001001001001001001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001000, "-", init010010010010010010010010010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001000, F010010010010010010010010010010010010010010010010000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001000000;
composed *init01001001001001001001001001001001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001001001001001001001001001001000000, "zero", "r[zero,r(r(s(r(s(q)))))]",13,r(r(s(r(s(q))))));
}
const composed* F01001001001001001001001001001001001001001001001001000000(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001001001001001001001001001001000000, 13, n_rel_id, r(r(s(r(s(q))))));
}

composed set0100100100100100100100100100100100100100100100100100000;
composed *init0100100100100100100100100100100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_c(&set0100100100100100100100100100100100100100100100100100000, 2, "c2", init01001001001001001001001001001001001001001001001001000000(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100100000(int n_rel_id, const composed * q) {
	return c(&set0100100100100100100100100100100100100100100100100100000, 2, F01001001001001001001001001001001001001001001001001000000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010010010010010000;
composed *init010010010010010010010010010010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010010010010010010010010010010000, "aaa", init0100100100100100100100100100100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010010010010010010010010010010000, F0100100100100100100100100100100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001000;
composed *init01001001001001001001001001001001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001000, "-", init010010010010010010010010010010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001000, F010010010010010010010010010010010010010010010010010000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010010010010010010000000;
composed *init010010010010010010010010010010010010010010010010010010000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010010010010010010010010000000, "zero", "r[zero,r(s(r(s(q))))]",13,r(s(r(s(q)))));
}
const composed* F010010010010010010010010010010010010010010010010010010000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010010010010010010010010000000, 13, n_rel_id, r(s(r(s(q)))));
}

composed set01001001001001001001001001001001001001001001001001001000000;
composed *init01001001001001001001001001001001001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001000000, "-", init010010010010010010010010010010010010010010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001000000, F010010010010010010010010010010010010010010010010010010000000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001000001;
composed *init01001001001001001001001001001001001001001001001001001000001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001001001001001001001001001001001000001, "mainLR_0", "r[mainLR_0,r(s(r(s(q))))]",0,r(s(r(s(q)))));
}
const composed* F01001001001001001001001001001001001001001001001001001000001(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001001001001001001001001001001001000001, 0, n_rel_id, r(s(r(s(q)))));
}

composed set0100100100100100100100100100100100100100100100100100100000;
composed *init0100100100100100100100100100100100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100100100100000, "v", init01001001001001001001001001001001001001001001001001001000000(n_rel_id, q), init01001001001001001001001001001001001001001001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001000000.relations) ?
 F01001001001001001001001001001001001001001001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001000001.relations) ?
 F01001001001001001001001001001001001001001001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100100100100000, x,y);
}

composed set010010010010010010010010010010010010010010010010010010000;
composed *init010010010010010010010010010010010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010010010010010010010010010010010000, "aaa", init0100100100100100100100100100100100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010010010010010010010010010010010000, F0100100100100100100100100100100100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001000;
composed *init01001001001001001001001001001001001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001000, "-", init010010010010010010010010010010010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001000, F010010010010010010010010010010010010010010010010010010000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001001000000;
composed *init01001001001001001001001001001001001001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001001001001001001001001001001001001000000, "halt_0", "r[halt_0,r(s(r(s(q))))]",14,r(s(r(s(q)))));
}
const composed* F01001001001001001001001001001001001001001001001001001001000000(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001001001001001001001001001001001001000000, 14, n_rel_id, r(s(r(s(q)))));
}

composed set0100100100100100100100100100100100100100100100100100100100000;
composed *init0100100100100100100100100100100100100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_neg(&set0100100100100100100100100100100100100100100100100100100100000, "-", init01001001001001001001001001001001001001001001001001001001000000(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100100100100000(int n_rel_id, const composed * q) {
	return neg(&set0100100100100100100100100100100100100100100100100100100100000, F01001001001001001001001001001001001001001001001001001001000000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010010010010010010010000;
composed *init010010010010010010010010010010010010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010010010010010010010010010010010010000, "aaa", init0100100100100100100100100100100100100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010010010010010010010010010010010010000, F0100100100100100100100100100100100100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001001000;
composed *init01001001001001001001001001001001001001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001001000, "-", init010010010010010010010010010010010010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001001000, F010010010010010010010010010010010010010010010010010010010000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001001001000000;
composed *init01001001001001001001001001001001001001001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001001001001001001001001001001001001001000000, "succ", "r[succ,r(r(s(r(q))))]",3,r(r(s(r(q)))));
}
const composed* F01001001001001001001001001001001001001001001001001001001001000000(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001001001001001001001001001001001001001000000, 3, n_rel_id, r(r(s(r(q)))));
}

composed set0100100100100100100100100100100100100100100100100100100100100000;
composed *init0100100100100100100100100100100100100100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_c(&set0100100100100100100100100100100100100100100100100100100100100000, 2, "c2", init01001001001001001001001001001001001001001001001001001001001000000(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100100100100100000(int n_rel_id, const composed * q) {
	return c(&set0100100100100100100100100100100100100100100100100100100100100000, 2, F01001001001001001001001001001001001001001001001001001001001000000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010010010010010010010010000;
composed *init010010010010010010010010010010010010010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010010010010010010010010010010010010010000, "aaa", init0100100100100100100100100100100100100100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010010010010010010010010010010010010010000, F0100100100100100100100100100100100100100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001001001000;
composed *init01001001001001001001001001001001001001001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001001001000, "-", init010010010010010010010010010010010010010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001001001000, F010010010010010010010010010010010010010010010010010010010010000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010010010010010010010010010000000000;
composed *init010010010010010010010010010010010010010010010010010010010010010000000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010010010010010010010010010010010000000000, "zero", "r[zero,r(s(r(s(q))))]",13,r(s(r(s(q)))));
}
const composed* F010010010010010010010010010010010010010010010010010010010010010000000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010010010010010010010010010010010000000000, 13, n_rel_id, r(s(r(s(q)))));
}

composed set01001001001001001001001001001001001001001001001001001001001001000000000;
composed *init01001001001001001001001001001001001001001001001001001001001001000000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001001001001000000000, "-", init010010010010010010010010010010010010010010010010010010010010010000000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001001001001000000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001001001001000000000, F010010010010010010010010010010010010010010010010010010010010010000000000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010010010010010010010010010000000010;
composed *init010010010010010010010010010010010010010010010010010010010010010000000010(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010010010010010010010010010010010000000010, "succ", "r[succ,p(r(s(r(q))))]",3,p(r(s(r(q)))));
}
const composed* F010010010010010010010010010010010010010010010010010010010010010000000010(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010010010010010010010010010010010000000010, 3, n_rel_id, p(r(s(r(q)))));
}

composed set01001001001001001001001001001001001001001001001001001001001001000000001;
composed *init01001001001001001001001001001001001001001001001001001001001001000000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001001001001000000001, "-", init010010010010010010010010010010010010010010010010010010010010010000000010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001001001001000000001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001001001001000000001, F010010010010010010010010010010010010010010010010010010010010010000000010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100100100100100100100100100100000000;
composed *init0100100100100100100100100100100100100100100100100100100100100100000000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100100100100100100100000000, "v", init01001001001001001001001001001001001001001001001001001001001001000000000(n_rel_id, q), init01001001001001001001001001001001001001001001001001001001001001000000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100100100100100100000000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001001001000000000.relations) ?
 F01001001001001001001001001001001001001001001001001001001001001000000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001001001000000001.relations) ?
 F01001001001001001001001001001001001001001001001001001001001001000000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100100100100100100100000000, x,y);
}

composed set010010010010010010010010010010010010010010010010010010010010010000000;
composed *init010010010010010010010010010010010010010010010010010010010010010000000(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010010010010010010010010010010000000, "-", init0100100100100100100100100100100100100100100100100100100100100100000000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010010010010010010000000(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010010010010010010010010010010000000, F0100100100100100100100100100100100100100100100100100100100100100000000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001001001001000000;
composed *init01001001001001001001001001001001001001001001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001001001001000000, "-", init010010010010010010010010010010010010010010010010010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001001001001000000, F010010010010010010010010010010010010010010010010010010010010010000000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001001001001000001;
composed *init01001001001001001001001001001001001001001001001001001001001001000001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001001001001001001001001001001001001001001000001, "nonzero", "r[nonzero,s(r(s(q)))]",15,s(r(s(q))));
}
const composed* F01001001001001001001001001001001001001001001001001001001001001000001(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001001001001001001001001001001001001001001000001, 15, n_rel_id, s(r(s(q))));
}

composed set0100100100100100100100100100100100100100100100100100100100100100000;
composed *init0100100100100100100100100100100100100100100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100100100100100100100000, "v", init01001001001001001001001001001001001001001001001001001001001001000000(n_rel_id, q), init01001001001001001001001001001001001001001001001001001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001001001000000.relations) ?
 F01001001001001001001001001001001001001001001001001001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001001001000001.relations) ?
 F01001001001001001001001001001001001001001001001001001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100100100100100100100000, x,y);
}

composed set010010010010010010010010010010010010010010010010010010010010010000;
composed *init010010010010010010010010010010010010010010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010010010010010010010010010010010010010010000, "aaa", init0100100100100100100100100100100100100100100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010010010010010010000(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010010010010010010010010010010010010010010000, F0100100100100100100100100100100100100100100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001001001001000;
composed *init01001001001001001001001001001001001001001001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001001001001000, "-", init010010010010010010010010010010010010010010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001001001001000, F010010010010010010010010010010010010010010010010010010010010010000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010010010010010010010010010010000000;
composed *init010010010010010010010010010010010010010010010010010010010010010010000000(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010010010010010010010010010010010010000000, "nonzero", "r[nonzero,r(s(r(s(q))))]",15,r(s(r(s(q)))));
}
const composed* F010010010010010010010010010010010010010010010010010010010010010010000000(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010010010010010010010010010010010010000000, 15, n_rel_id, r(s(r(s(q)))));
}

composed set01001001001001001001001001001001001001001001001001001001001001001000000;
composed *init01001001001001001001001001001001001001001001001001001001001001001000000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001001001001001000000, "-", init010010010010010010010010010010010010010010010010010010010010010010000000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001001001001001000000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001001001001001000000, F010010010010010010010010010010010010010010010010010010010010010010000000(n_rel_id, q));
}

composed set010010010010010010010010010010010010010010010010010010010010010010000010;
composed *init010010010010010010010010010010010010010010010010010010010010010010000010(int n_rel_id, const composed* q) {
	return init_R(&set010010010010010010010010010010010010010010010010010010010010010010000010, "succ", "r[succ,p(r(s(r(q))))]",3,p(r(s(r(q)))));
}
const composed* F010010010010010010010010010010010010010010010010010010010010010010000010(int n_rel_id, const composed * q) {
	return R(&set010010010010010010010010010010010010010010010010010010010010010010000010, 3, n_rel_id, p(r(s(r(q)))));
}

composed set01001001001001001001001001001001001001001001001001001001001001001000001;
composed *init01001001001001001001001001001001001001001001001001001001001001001000001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001001001001001000001, "-", init010010010010010010010010010010010010010010010010010010010010010010000010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001001001001001000001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001001001001001000001, F010010010010010010010010010010010010010010010010010010010010010010000010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100100100100100100100100100100100000;
composed *init0100100100100100100100100100100100100100100100100100100100100100100000(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100100100100100100100100000, "v", init01001001001001001001001001001001001001001001001001001001001001001000000(n_rel_id, q), init01001001001001001001001001001001001001001001001001001001001001001000001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100100100100100100100000(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001001001001000000.relations) ?
 F01001001001001001001001001001001001001001001001001001001001001001000000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001001001001000001.relations) ?
 F01001001001001001001001001001001001001001001001001001001001001001000001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100100100100100100100100000, x,y);
}

composed set010010010010010010010010010010010010010010010010010010010010010010000;
composed *init010010010010010010010010010010010010010010010010010010010010010010000(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010010010010010010010010010010010000, "-", init0100100100100100100100100100100100100100100100100100100100100100100000(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010010010010010010010000(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010010010010010010010010010010010000, F0100100100100100100100100100100100100100100100100100100100100100100000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001001001001001000;
composed *init01001001001001001001001001001001001001001001001001001001001001001000(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001001001001001000, "-", init010010010010010010010010010010010010010010010010010010010010010010000(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001001001001001000(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001001001001001000, F010010010010010010010010010010010010010010010010010010010010010010000(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001001001001001001;
composed *init01001001001001001001001001001001001001001001001001001001001001001001(int n_rel_id, const composed* q) {
	return init_R(&set01001001001001001001001001001001001001001001001001001001001001001001, "nonzero", "r[nonzero,s(r(s(q)))]",15,s(r(s(q))));
}
const composed* F01001001001001001001001001001001001001001001001001001001001001001001(int n_rel_id, const composed * q) {
	return R(&set01001001001001001001001001001001001001001001001001001001001001001001, 15, n_rel_id, s(r(s(q))));
}

composed set0100100100100100100100100100100100100100100100100100100100100100100;
composed *init0100100100100100100100100100100100100100100100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100100100100100100100100, "v", init01001001001001001001001001001001001001001001001001001001001001001000(n_rel_id, q), init01001001001001001001001001001001001001001001001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001001001001000.relations) ?
 F01001001001001001001001001001001001001001001001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001001001001001.relations) ?
 F01001001001001001001001001001001001001001001001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100100100100100100100100, x,y);
}

composed set010010010010010010010010010010010010010010010010010010010010010010;
composed *init010010010010010010010010010010010010010010010010010010010010010010(int n_rel_id, const composed* q) {
	return init_axyz(&set010010010010010010010010010010010010010010010010010010010010010010, "aaa", init0100100100100100100100100100100100100100100100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010010010010010010010(int n_rel_id, const composed * q) {
	return axyz(&set010010010010010010010010010010010010010010010010010010010010010010, F0100100100100100100100100100100100100100100100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001001001001001;
composed *init01001001001001001001001001001001001001001001001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001001001001001, "-", init010010010010010010010010010010010010010010010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001001001001001, F010010010010010010010010010010010010010010010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100100100100100100100100100100;
composed *init0100100100100100100100100100100100100100100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100100100100100100100, "v", init01001001001001001001001001001001001001001001001001001001001001000(n_rel_id, q), init01001001001001001001001001001001001001001001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001001001000.relations) ?
 F01001001001001001001001001001001001001001001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001001001001.relations) ?
 F01001001001001001001001001001001001001001001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100100100100100100100, x,y);
}

composed set010010010010010010010010010010010010010010010010010010010010010;
composed *init010010010010010010010010010010010010010010010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010010010010010010010010010010, "-", init0100100100100100100100100100100100100100100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010010010010010010010010010010, F0100100100100100100100100100100100100100100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001001001001;
composed *init01001001001001001001001001001001001001001001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001001001001, "-", init010010010010010010010010010010010010010010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001001001001, F010010010010010010010010010010010010010010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100100100100100100100100100;
composed *init0100100100100100100100100100100100100100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100100100100100100, "v", init01001001001001001001001001001001001001001001001001001001001000(n_rel_id, q), init01001001001001001001001001001001001001001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001001000.relations) ?
 F01001001001001001001001001001001001001001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001001001.relations) ?
 F01001001001001001001001001001001001001001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100100100100100100, x,y);
}

composed set010010010010010010010010010010010010010010010010010010010010;
composed *init010010010010010010010010010010010010010010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010010010010010010010010010, "-", init0100100100100100100100100100100100100100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010010010010010010010010010, F0100100100100100100100100100100100100100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001001001;
composed *init01001001001001001001001001001001001001001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001001001, "-", init010010010010010010010010010010010010010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001001001, F010010010010010010010010010010010010010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100100100100100100100100;
composed *init0100100100100100100100100100100100100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100100100100100, "v", init01001001001001001001001001001001001001001001001001001001000(n_rel_id, q), init01001001001001001001001001001001001001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001000.relations) ?
 F01001001001001001001001001001001001001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001001.relations) ?
 F01001001001001001001001001001001001001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100100100100100, x,y);
}

composed set010010010010010010010010010010010010010010010010010010010;
composed *init010010010010010010010010010010010010010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010010010010010010010010, "-", init0100100100100100100100100100100100100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010010010010010010010010, F0100100100100100100100100100100100100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001001;
composed *init01001001001001001001001001001001001001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001001, "-", init010010010010010010010010010010010010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001001, F010010010010010010010010010010010010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100100100100100100100;
composed *init0100100100100100100100100100100100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100100100100, "v", init01001001001001001001001001001001001001001001001001001000(n_rel_id, q), init01001001001001001001001001001001001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001000.relations) ?
 F01001001001001001001001001001001001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001001.relations) ?
 F01001001001001001001001001001001001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100100100100, x,y);
}

composed set010010010010010010010010010010010010010010010010010010;
composed *init010010010010010010010010010010010010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010010010010010010010, "-", init0100100100100100100100100100100100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010010010010010010010, F0100100100100100100100100100100100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001001;
composed *init01001001001001001001001001001001001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001001, "-", init010010010010010010010010010010010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001001, F010010010010010010010010010010010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100100100100100100;
composed *init0100100100100100100100100100100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100100100, "v", init01001001001001001001001001001001001001001001001001000(n_rel_id, q), init01001001001001001001001001001001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001000.relations) ?
 F01001001001001001001001001001001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001001.relations) ?
 F01001001001001001001001001001001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100100100, x,y);
}

composed set010010010010010010010010010010010010010010010010010;
composed *init010010010010010010010010010010010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010010010010010010, "-", init0100100100100100100100100100100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010010010010010010, F0100100100100100100100100100100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001001;
composed *init01001001001001001001001001001001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001001, "-", init010010010010010010010010010010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001001, F010010010010010010010010010010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100100100100100;
composed *init0100100100100100100100100100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100100, "v", init01001001001001001001001001001001001001001001001000(n_rel_id, q), init01001001001001001001001001001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001001000.relations) ?
 F01001001001001001001001001001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001001001.relations) ?
 F01001001001001001001001001001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100100, x,y);
}

composed set010010010010010010010010010010010010010010010010;
composed *init010010010010010010010010010010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010010010010010, "-", init0100100100100100100100100100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010010010010010, F0100100100100100100100100100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001001;
composed *init01001001001001001001001001001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001001, "-", init010010010010010010010010010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001001, F010010010010010010010010010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100100100100;
composed *init0100100100100100100100100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100100, "v", init01001001001001001001001001001001001001001001000(n_rel_id, q), init01001001001001001001001001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001001000.relations) ?
 F01001001001001001001001001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001001.relations) ?
 F01001001001001001001001001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100100, x,y);
}

composed set010010010010010010010010010010010010010010010;
composed *init010010010010010010010010010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010010010010, "-", init0100100100100100100100100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010010010010, F0100100100100100100100100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001001;
composed *init01001001001001001001001001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001001, "-", init010010010010010010010010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001001, F010010010010010010010010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100100100;
composed *init0100100100100100100100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100100, "v", init01001001001001001001001001001001001001001000(n_rel_id, q), init01001001001001001001001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001001000.relations) ?
 F01001001001001001001001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001001.relations) ?
 F01001001001001001001001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100100, x,y);
}

composed set010010010010010010010010010010010010010010;
composed *init010010010010010010010010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010010010, "-", init0100100100100100100100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010010010, F0100100100100100100100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001001001001001001001;
composed *init01001001001001001001001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001001, "-", init010010010010010010010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001001, F010010010010010010010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100100;
composed *init0100100100100100100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100100, "v", init01001001001001001001001001001001001001000(n_rel_id, q), init01001001001001001001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001001000.relations) ?
 F01001001001001001001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001001.relations) ?
 F01001001001001001001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100100, x,y);
}

composed set010010010010010010010010010010010010010;
composed *init010010010010010010010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010010, "-", init0100100100100100100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010010, F0100100100100100100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001001001001001001;
composed *init01001001001001001001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001001, "-", init010010010010010010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001001, F010010010010010010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100100100100100100;
composed *init0100100100100100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100100, "v", init01001001001001001001001001001001001000(n_rel_id, q), init01001001001001001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001001000.relations) ?
 F01001001001001001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001001.relations) ?
 F01001001001001001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100100, x,y);
}

composed set010010010010010010010010010010010010;
composed *init010010010010010010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010010, "-", init0100100100100100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010010, F0100100100100100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001001001001001;
composed *init01001001001001001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001001, "-", init010010010010010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001001, F010010010010010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100100100100100;
composed *init0100100100100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100100, "v", init01001001001001001001001001001001000(n_rel_id, q), init01001001001001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001001000.relations) ?
 F01001001001001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001001.relations) ?
 F01001001001001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100100, x,y);
}

composed set010010010010010010010010010010010;
composed *init010010010010010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010010, "-", init0100100100100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010010, F0100100100100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001001001001;
composed *init01001001001001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001001, "-", init010010010010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001001, F010010010010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100100100100;
composed *init0100100100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100100, "v", init01001001001001001001001001001000(n_rel_id, q), init01001001001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001001000.relations) ?
 F01001001001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001001.relations) ?
 F01001001001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100100, x,y);
}

composed set010010010010010010010010010010;
composed *init010010010010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010010, "-", init0100100100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010010, F0100100100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001001001;
composed *init01001001001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001001, "-", init010010010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001001, F010010010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100100100;
composed *init0100100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100100, "v", init01001001001001001001001001000(n_rel_id, q), init01001001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001001000.relations) ?
 F01001001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001001.relations) ?
 F01001001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100100, x,y);
}

composed set010010010010010010010010010;
composed *init010010010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010010, "-", init0100100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010010, F0100100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001001;
composed *init01001001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001001, "-", init010010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001001, F010010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100100;
composed *init0100100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100100, "v", init01001001001001001001001000(n_rel_id, q), init01001001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001001000.relations) ?
 F01001001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001001.relations) ?
 F01001001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100100, x,y);
}

composed set010010010010010010010010;
composed *init010010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010010, "-", init0100100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010010, F0100100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001001;
composed *init01001001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001001, "-", init010010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001001, F010010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100100;
composed *init0100100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100100, "v", init01001001001001001001000(n_rel_id, q), init01001001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001001000.relations) ?
 F01001001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001001.relations) ?
 F01001001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100100, x,y);
}

composed set010010010010010010010;
composed *init010010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010010, "-", init0100100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010010, F0100100100100100100100(n_rel_id, q));
}

composed set01001001001001001001;
composed *init01001001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001001, "-", init010010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001001, F010010010010010010010(n_rel_id, q));
}

composed set0100100100100100100;
composed *init0100100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100100, "v", init01001001001001001000(n_rel_id, q), init01001001001001001001(n_rel_id, q));
}
const composed* F0100100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001001000.relations) ?
 F01001001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001001.relations) ?
 F01001001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100100, x,y);
}

composed set010010010010010010;
composed *init010010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010010, "-", init0100100100100100100(n_rel_id, q));
}
const composed* F010010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010010, F0100100100100100100(n_rel_id, q));
}

composed set01001001001001001;
composed *init01001001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001001, "-", init010010010010010010(n_rel_id, q));
}
const composed* F01001001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001001, F010010010010010010(n_rel_id, q));
}

composed set0100100100100100;
composed *init0100100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100100, "v", init01001001001001000(n_rel_id, q), init01001001001001001(n_rel_id, q));
}
const composed* F0100100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001001000.relations) ?
 F01001001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001001.relations) ?
 F01001001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100100, x,y);
}

composed set010010010010010;
composed *init010010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010010, "-", init0100100100100100(n_rel_id, q));
}
const composed* F010010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010010, F0100100100100100(n_rel_id, q));
}

composed set01001001001001;
composed *init01001001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001001, "-", init010010010010010(n_rel_id, q));
}
const composed* F01001001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001001, F010010010010010(n_rel_id, q));
}

composed set0100100100100;
composed *init0100100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100100, "v", init01001001001000(n_rel_id, q), init01001001001001(n_rel_id, q));
}
const composed* F0100100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001001000.relations) ?
 F01001001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001001.relations) ?
 F01001001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100100, x,y);
}

composed set010010010010;
composed *init010010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010010, "-", init0100100100100(n_rel_id, q));
}
const composed* F010010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010010, F0100100100100(n_rel_id, q));
}

composed set01001001001;
composed *init01001001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001001, "-", init010010010010(n_rel_id, q));
}
const composed* F01001001001(int n_rel_id, const composed * q) {
	return neg(&set01001001001, F010010010010(n_rel_id, q));
}

composed set0100100100;
composed *init0100100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100100, "v", init01001001000(n_rel_id, q), init01001001001(n_rel_id, q));
}
const composed* F0100100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001001000.relations) ?
 F01001001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001001.relations) ?
 F01001001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100100, x,y);
}

composed set010010010;
composed *init010010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010010, "-", init0100100100(n_rel_id, q));
}
const composed* F010010010(int n_rel_id, const composed * q) {
	return neg(&set010010010, F0100100100(n_rel_id, q));
}

composed set01001001;
composed *init01001001(int n_rel_id, const composed* q) {
	return init_neg(&set01001001, "-", init010010010(n_rel_id, q));
}
const composed* F01001001(int n_rel_id, const composed * q) {
	return neg(&set01001001, F010010010(n_rel_id, q));
}

composed set0100100;
composed *init0100100(int n_rel_id, const composed* q) {
	return init_v(&set0100100, "v", init01001000(n_rel_id, q), init01001001(n_rel_id, q));
}
const composed* F0100100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01001000.relations) ?
 F01001000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001001.relations) ?
 F01001001(n_rel_id, q) :
 global__zero);
	return v(&set0100100, x,y);
}

composed set010010;
composed *init010010(int n_rel_id, const composed* q) {
	return init_neg(&set010010, "-", init0100100(n_rel_id, q));
}
const composed* F010010(int n_rel_id, const composed * q) {
	return neg(&set010010, F0100100(n_rel_id, q));
}

composed set01001;
composed *init01001(int n_rel_id, const composed* q) {
	return init_neg(&set01001, "-", init010010(n_rel_id, q));
}
const composed* F01001(int n_rel_id, const composed * q) {
	return neg(&set01001, F010010(n_rel_id, q));
}

composed set0100;
composed *init0100(int n_rel_id, const composed* q) {
	return init_v(&set0100, "v", init01000(n_rel_id, q), init01001(n_rel_id, q));
}
const composed* F0100(int n_rel_id, const composed * q) {
const composed *x =
(intset__member(n_rel_id,set01000.relations) ?
 F01000(n_rel_id, q) :
 global__zero);
const composed *y = (intset__member(n_rel_id,set01001.relations) ?
 F01001(n_rel_id, q) :
 global__zero);
	return v(&set0100, x,y);
}

composed set010;
composed *init010(int n_rel_id, const composed* q) {
	return init_neg(&set010, "-", init0100(n_rel_id, q));
}
const composed* F010(int n_rel_id, const composed * q) {
	return neg(&set010, F0100(n_rel_id, q));
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
