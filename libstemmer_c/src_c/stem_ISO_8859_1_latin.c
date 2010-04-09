
/* This file was generated automatically by the Snowball to ANSI C compiler */

#include "../runtime/header.h"

#ifdef __cplusplus
extern "C" {
#endif
extern int latin_ISO_8859_1_stem(struct SN_env * z);
#ifdef __cplusplus
}
#endif
static int r_que_word(struct SN_env * z);
static int r_map_letters(struct SN_env * z);
#ifdef __cplusplus
extern "C" {
#endif


extern struct SN_env * latin_ISO_8859_1_create_env(void);
extern void latin_ISO_8859_1_close_env(struct SN_env * z);


#ifdef __cplusplus
}
#endif
static const symbol s_0_0[3] = { 'i', 't', 'a' };
static const symbol s_0_1[3] = { 'q', 'u', 'a' };
static const symbol s_0_2[4] = { 'a', 'd', 'a', 'e' };
static const symbol s_0_3[5] = { 'p', 'e', 'r', 'a', 'e' };
static const symbol s_0_4[4] = { 'q', 'u', 'a', 'e' };
static const symbol s_0_5[2] = { 'd', 'e' };
static const symbol s_0_6[2] = { 'n', 'e' };
static const symbol s_0_7[6] = { 'u', 't', 'r', 'i', 'b', 'i' };
static const symbol s_0_8[3] = { 'u', 'b', 'i' };
static const symbol s_0_9[4] = { 'u', 'n', 'd', 'i' };
static const symbol s_0_10[4] = { 'o', 'b', 'l', 'i' };
static const symbol s_0_11[4] = { 'd', 'e', 'n', 'i' };
static const symbol s_0_12[3] = { 'u', 't', 'i' };
static const symbol s_0_13[3] = { 'c', 'u', 'i' };
static const symbol s_0_14[3] = { 'q', 'u', 'i' };
static const symbol s_0_15[4] = { 'q', 'u', 'a', 'm' };
static const symbol s_0_16[4] = { 'q', 'u', 'e', 'm' };
static const symbol s_0_17[6] = { 'q', 'u', 'a', 'r', 'u', 'm' };
static const symbol s_0_18[6] = { 'q', 'u', 'o', 'r', 'u', 'm' };
static const symbol s_0_19[2] = { 'c', 'o' };
static const symbol s_0_20[4] = { 'd', 'e', 'c', 'o' };
static const symbol s_0_21[4] = { 'r', 'e', 'c', 'o' };
static const symbol s_0_22[4] = { 'i', 'n', 'c', 'o' };
static const symbol s_0_23[5] = { 'c', 'o', 'n', 'c', 'o' };
static const symbol s_0_24[4] = { 'e', 'x', 'c', 'o' };
static const symbol s_0_25[6] = { 'q', 'u', 'a', 'n', 'd', 'o' };
static const symbol s_0_26[4] = { 'u', 't', 'r', 'o' };
static const symbol s_0_27[3] = { 'q', 'u', 'o' };
static const symbol s_0_28[4] = { 'u', 't', 'e', 'r' };
static const symbol s_0_29[3] = { 't', 'o', 'r' };
static const symbol s_0_30[5] = { 'o', 'b', 't', 'o', 'r' };
static const symbol s_0_31[7] = { 'p', 'r', 'a', 'e', 't', 'o', 'r' };
static const symbol s_0_32[5] = { 'd', 'e', 't', 'o', 'r' };
static const symbol s_0_33[5] = { 'r', 'e', 't', 'o', 'r' };
static const symbol s_0_34[5] = { 'i', 'n', 't', 'o', 'r' };
static const symbol s_0_35[6] = { 'c', 'o', 'n', 't', 'o', 'r' };
static const symbol s_0_36[5] = { 'o', 'p', 't', 'o', 'r' };
static const symbol s_0_37[5] = { 'a', 't', 't', 'o', 'r' };
static const symbol s_0_38[5] = { 'e', 'x', 't', 'o', 'r' };
static const symbol s_0_39[4] = { 'q', 'u', 'a', 's' };
static const symbol s_0_40[3] = { 'a', 'b', 's' };
static const symbol s_0_41[6] = { 'p', 'l', 'e', 'n', 'i', 's' };
static const symbol s_0_42[4] = { 'q', 'u', 'i', 's' };
static const symbol s_0_43[10] = { 'q', 'u', 'o', 't', 'u', 's', 'q', 'u', 'i', 's' };
static const symbol s_0_44[4] = { 'q', 'u', 'o', 's' };
static const symbol s_0_45[3] = { 'a', 'p', 's' };
static const symbol s_0_46[2] = { 'u', 's' };
static const symbol s_0_47[4] = { 'a', 'b', 'u', 's' };
static const symbol s_0_48[6] = { 'q', 'u', 'i', 'b', 'u', 's' };
static const symbol s_0_49[4] = { 'a', 'd', 'u', 's' };
static const symbol s_0_50[5] = { 'c', 'u', 'i', 'u', 's' };
static const symbol s_0_51[5] = { 'q', 'u', 'o', 'u', 's' };
static const symbol s_0_52[3] = { 's', 'u', 's' };
static const symbol s_0_53[2] = { 'a', 't' };

static const struct among a_0[54] =
{
/*  0 */ { 3, s_0_0, -1, -1, 0},
/*  1 */ { 3, s_0_1, -1, -1, 0},
/*  2 */ { 4, s_0_2, -1, -1, 0},
/*  3 */ { 5, s_0_3, -1, -1, 0},
/*  4 */ { 4, s_0_4, -1, -1, 0},
/*  5 */ { 2, s_0_5, -1, -1, 0},
/*  6 */ { 2, s_0_6, -1, -1, 0},
/*  7 */ { 6, s_0_7, -1, -1, 0},
/*  8 */ { 3, s_0_8, -1, -1, 0},
/*  9 */ { 4, s_0_9, -1, -1, 0},
/* 10 */ { 4, s_0_10, -1, -1, 0},
/* 11 */ { 4, s_0_11, -1, -1, 0},
/* 12 */ { 3, s_0_12, -1, -1, 0},
/* 13 */ { 3, s_0_13, -1, -1, 0},
/* 14 */ { 3, s_0_14, -1, -1, 0},
/* 15 */ { 4, s_0_15, -1, -1, 0},
/* 16 */ { 4, s_0_16, -1, -1, 0},
/* 17 */ { 6, s_0_17, -1, -1, 0},
/* 18 */ { 6, s_0_18, -1, -1, 0},
/* 19 */ { 2, s_0_19, -1, -1, 0},
/* 20 */ { 4, s_0_20, 19, -1, 0},
/* 21 */ { 4, s_0_21, 19, -1, 0},
/* 22 */ { 4, s_0_22, 19, -1, 0},
/* 23 */ { 5, s_0_23, 19, -1, 0},
/* 24 */ { 4, s_0_24, 19, -1, 0},
/* 25 */ { 6, s_0_25, -1, -1, 0},
/* 26 */ { 4, s_0_26, -1, -1, 0},
/* 27 */ { 3, s_0_27, -1, -1, 0},
/* 28 */ { 4, s_0_28, -1, -1, 0},
/* 29 */ { 3, s_0_29, -1, -1, 0},
/* 30 */ { 5, s_0_30, 29, -1, 0},
/* 31 */ { 7, s_0_31, 29, -1, 0},
/* 32 */ { 5, s_0_32, 29, -1, 0},
/* 33 */ { 5, s_0_33, 29, -1, 0},
/* 34 */ { 5, s_0_34, 29, -1, 0},
/* 35 */ { 6, s_0_35, 29, -1, 0},
/* 36 */ { 5, s_0_36, 29, -1, 0},
/* 37 */ { 5, s_0_37, 29, -1, 0},
/* 38 */ { 5, s_0_38, 29, -1, 0},
/* 39 */ { 4, s_0_39, -1, -1, 0},
/* 40 */ { 3, s_0_40, -1, -1, 0},
/* 41 */ { 6, s_0_41, -1, -1, 0},
/* 42 */ { 4, s_0_42, -1, -1, 0},
/* 43 */ { 10, s_0_43, 42, -1, 0},
/* 44 */ { 4, s_0_44, -1, -1, 0},
/* 45 */ { 3, s_0_45, -1, -1, 0},
/* 46 */ { 2, s_0_46, -1, -1, 0},
/* 47 */ { 4, s_0_47, 46, -1, 0},
/* 48 */ { 6, s_0_48, 46, -1, 0},
/* 49 */ { 4, s_0_49, 46, -1, 0},
/* 50 */ { 5, s_0_50, 46, -1, 0},
/* 51 */ { 5, s_0_51, 46, -1, 0},
/* 52 */ { 3, s_0_52, 46, -1, 0},
/* 53 */ { 2, s_0_53, -1, -1, 0}
};

static const symbol s_1_0[1] = { 'a' };
static const symbol s_1_1[2] = { 'i', 'a' };
static const symbol s_1_2[2] = { 'u', 'd' };
static const symbol s_1_3[1] = { 'e' };
static const symbol s_1_4[2] = { 'a', 'e' };
static const symbol s_1_5[1] = { 'i' };
static const symbol s_1_6[2] = { 'a', 'm' };
static const symbol s_1_7[2] = { 'e', 'm' };
static const symbol s_1_8[2] = { 'u', 'm' };
static const symbol s_1_9[1] = { 'o' };
static const symbol s_1_10[2] = { 'a', 's' };
static const symbol s_1_11[2] = { 'e', 's' };
static const symbol s_1_12[2] = { 'i', 's' };
static const symbol s_1_13[2] = { 'o', 's' };
static const symbol s_1_14[2] = { 'u', 's' };
static const symbol s_1_15[4] = { 'i', 'b', 'u', 's' };
static const symbol s_1_16[3] = { 'i', 'u', 's' };
static const symbol s_1_17[2] = { 'n', 't' };
static const symbol s_1_18[1] = { 'u' };

static const struct among a_1[19] =
{
/*  0 */ { 1, s_1_0, -1, 1, 0},
/*  1 */ { 2, s_1_1, 0, 1, 0},
/*  2 */ { 2, s_1_2, -1, 1, 0},
/*  3 */ { 1, s_1_3, -1, 1, 0},
/*  4 */ { 2, s_1_4, 3, 1, 0},
/*  5 */ { 1, s_1_5, -1, 1, 0},
/*  6 */ { 2, s_1_6, -1, 1, 0},
/*  7 */ { 2, s_1_7, -1, 1, 0},
/*  8 */ { 2, s_1_8, -1, 1, 0},
/*  9 */ { 1, s_1_9, -1, 1, 0},
/* 10 */ { 2, s_1_10, -1, 1, 0},
/* 11 */ { 2, s_1_11, -1, 1, 0},
/* 12 */ { 2, s_1_12, -1, 1, 0},
/* 13 */ { 2, s_1_13, -1, 1, 0},
/* 14 */ { 2, s_1_14, -1, 1, 0},
/* 15 */ { 4, s_1_15, 14, 1, 0},
/* 16 */ { 3, s_1_16, 14, 1, 0},
/* 17 */ { 2, s_1_17, -1, 1, 0},
/* 18 */ { 1, s_1_18, -1, 1, 0}
};

static const symbol s_2_0[4] = { 'm', 'i', 'n', 'i' };
static const symbol s_2_1[2] = { 'r', 'i' };
static const symbol s_2_2[3] = { 's', 't', 'i' };
static const symbol s_2_3[1] = { 'm' };
static const symbol s_2_4[2] = { 'b', 'o' };
static const symbol s_2_5[3] = { 'e', 'r', 'o' };
static const symbol s_2_6[1] = { 'r' };
static const symbol s_2_7[3] = { 'b', 'o', 'r' };
static const symbol s_2_8[3] = { 'm', 'u', 'r' };
static const symbol s_2_9[3] = { 't', 'u', 'r' };
static const symbol s_2_10[4] = { 'n', 't', 'u', 'r' };
static const symbol s_2_11[5] = { 'u', 'n', 't', 'u', 'r' };
static const symbol s_2_12[6] = { 'i', 'u', 'n', 't', 'u', 'r' };
static const symbol s_2_13[1] = { 's' };
static const symbol s_2_14[3] = { 'r', 'i', 's' };
static const symbol s_2_15[5] = { 'b', 'e', 'r', 'i', 's' };
static const symbol s_2_16[3] = { 't', 'i', 's' };
static const symbol s_2_17[4] = { 's', 't', 'i', 's' };
static const symbol s_2_18[2] = { 'n', 's' };
static const symbol s_2_19[3] = { 'm', 'u', 's' };
static const symbol s_2_20[1] = { 't' };
static const symbol s_2_21[2] = { 'n', 't' };
static const symbol s_2_22[3] = { 'u', 'n', 't' };
static const symbol s_2_23[4] = { 'i', 'u', 'n', 't' };
static const symbol s_2_24[5] = { 'e', 'r', 'u', 'n', 't' };

static const struct among a_2[25] =
{
/*  0 */ { 4, s_2_0, -1, 4, 0},
/*  1 */ { 2, s_2_1, -1, 4, 0},
/*  2 */ { 3, s_2_2, -1, 4, 0},
/*  3 */ { 1, s_2_3, -1, 4, 0},
/*  4 */ { 2, s_2_4, -1, 2, 0},
/*  5 */ { 3, s_2_5, -1, 3, 0},
/*  6 */ { 1, s_2_6, -1, 4, 0},
/*  7 */ { 3, s_2_7, 6, 2, 0},
/*  8 */ { 3, s_2_8, 6, 4, 0},
/*  9 */ { 3, s_2_9, 6, 4, 0},
/* 10 */ { 4, s_2_10, 9, 4, 0},
/* 11 */ { 5, s_2_11, 10, 1, 0},
/* 12 */ { 6, s_2_12, 11, 1, 0},
/* 13 */ { 1, s_2_13, -1, 4, 0},
/* 14 */ { 3, s_2_14, 13, 4, 0},
/* 15 */ { 5, s_2_15, 14, 2, 0},
/* 16 */ { 3, s_2_16, 13, 4, 0},
/* 17 */ { 4, s_2_17, 16, 4, 0},
/* 18 */ { 2, s_2_18, 13, 4, 0},
/* 19 */ { 3, s_2_19, 13, 4, 0},
/* 20 */ { 1, s_2_20, -1, 4, 0},
/* 21 */ { 2, s_2_21, 20, 4, 0},
/* 22 */ { 3, s_2_22, 21, 1, 0},
/* 23 */ { 4, s_2_23, 22, 1, 0},
/* 24 */ { 5, s_2_24, 22, 1, 0}
};

static const symbol s_0[] = { 'j' };
static const symbol s_1[] = { 'i' };
static const symbol s_2[] = { 'v' };
static const symbol s_3[] = { 'u' };
static const symbol s_4[] = { 'q', 'u', 'e' };
static const symbol s_5[] = { 'i' };
static const symbol s_6[] = { 'b', 'i' };
static const symbol s_7[] = { 'e', 'r', 'i' };

static int r_map_letters(struct SN_env * z) {
    {   int c1 = z->c; /* do, line 14 */
        while(1) { /* repeat, line 14 */
            int c2 = z->c;
            while(1) { /* goto, line 14 */
                int c3 = z->c;
                z->bra = z->c; /* [, line 14 */
                if (!(eq_s(z, 1, s_0))) goto lab2;
                z->ket = z->c; /* ], line 14 */
                z->c = c3;
                break;
            lab2:
                z->c = c3;
                if (z->c >= z->l) goto lab1;
                z->c++; /* goto, line 14 */
            }
            {   int ret = slice_from_s(z, 1, s_1); /* <-, line 14 */
                if (ret < 0) return ret;
            }
            continue;
        lab1:
            z->c = c2;
            break;
        }
        z->c = c1;
    }
    {   int c4 = z->c; /* do, line 15 */
        while(1) { /* repeat, line 15 */
            int c5 = z->c;
            while(1) { /* goto, line 15 */
                int c6 = z->c;
                z->bra = z->c; /* [, line 15 */
                if (!(eq_s(z, 1, s_2))) goto lab5;
                z->ket = z->c; /* ], line 15 */
                z->c = c6;
                break;
            lab5:
                z->c = c6;
                if (z->c >= z->l) goto lab4;
                z->c++; /* goto, line 15 */
            }
            {   int ret = slice_from_s(z, 1, s_3); /* <-, line 15 */
                if (ret < 0) return ret;
            }
            continue;
        lab4:
            z->c = c5;
            break;
        }
        z->c = c4;
    }
    return 1;
}

static int r_que_word(struct SN_env * z) {
    z->ket = z->c; /* [, line 22 */
    if (!(eq_s_b(z, 3, s_4))) return 0;
    z->bra = z->c; /* ], line 22 */
    {   int m1 = z->l - z->c; (void)m1; /* or, line 35 */
        if (z->c - 1 <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((1876514 >> (z->p[z->c - 1] & 0x1f)) & 1)) goto lab1;
        if (!(find_among_b(z, a_0, 54))) goto lab1; /* among, line 23 */
        if (z->c > z->lb) goto lab1; /* atlimit, line 32 */
        z->bra = z->c; /* ], line 32 */
        z->S[0] = assign_to(z, z->S[0]); /* => noun_form, line 33 */
        if (z->S[0] == 0) return -1; /* => noun_form, line 33 */
        z->S[1] = assign_to(z, z->S[1]); /* => verb_form, line 34 */
        if (z->S[1] == 0) return -1; /* => verb_form, line 34 */
        goto lab0;
    lab1:
        z->c = z->l - m1;
        {   int ret = slice_del(z); /* delete, line 35 */
            if (ret < 0) return ret;
        }
        return 0; /* fail, line 35 */
    }
lab0:
    return 1;
}

extern int latin_ISO_8859_1_stem(struct SN_env * z) {
    int among_var;
    {   int ret = r_map_letters(z);
        if (ret == 0) return 0; /* call map_letters, line 41 */
        if (ret < 0) return ret;
    }
    z->lb = z->c; z->c = z->l; /* backwards, line 43 */

    {   int m1 = z->l - z->c; (void)m1; /* or, line 44 */
        {   int ret = r_que_word(z);
            if (ret == 0) goto lab1; /* call que_word, line 44 */
            if (ret < 0) return ret;
        }
        goto lab0;
    lab1:
        z->c = z->l - m1;
        z->S[0] = assign_to(z, z->S[0]); /* => noun_form, line 45 */
        if (z->S[0] == 0) return -1; /* => noun_form, line 45 */
        z->S[1] = assign_to(z, z->S[1]); /* => verb_form, line 46 */
        if (z->S[1] == 0) return -1; /* => verb_form, line 46 */
        {   struct SN_env env = * z; /* $ noun_form, line 48 */
            int failure = 1; /* assume failure */
            z->p = z->S[0];
            z->lb = z->c = 0;
            z->l = SIZE(z->p);
            z->lb = z->c; z->c = z->l; /* backwards, line 48 */

            {   int m_keep = z->l - z->c;/* (void) m_keep;*/ /* try, line 48 */
                z->ket = z->c; /* [, line 49 */
                if (z->c <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((3711538 >> (z->p[z->c - 1] & 0x1f)) & 1)) { z->c = z->l - m_keep; goto lab3; }
                among_var = find_among_b(z, a_1, 19); /* substring, line 49 */
                if (!(among_var)) { z->c = z->l - m_keep; goto lab3; }
                z->bra = z->c; /* ], line 49 */
                {   int ret = z->c - 2;
                    if (z->lb > ret || ret > z->l) { z->c = z->l - m_keep; goto lab3; }
                    z->c = ret; /* hop, line 49 */
                }
                switch(among_var) {
                    case 0: { z->c = z->l - m_keep; goto lab3; }
                    case 1:
                        {   int ret = slice_del(z); /* delete, line 53 */
                            if (ret < 0) return ret;
                        }
                        break;
                }
            lab3:
                ;
            }
            z->c = z->lb;
            failure = 0; /* mark success */
            z->S[0] = z->p;
            * z = env;
            if (failure) return 0;
        }
        {   struct SN_env env = * z; /* $ verb_form, line 57 */
            int failure = 1; /* assume failure */
            z->p = z->S[1];
            z->lb = z->c = 0;
            z->l = SIZE(z->p);
            z->lb = z->c; z->c = z->l; /* backwards, line 57 */

            {   int m_keep = z->l - z->c;/* (void) m_keep;*/ /* try, line 57 */
                z->ket = z->c; /* [, line 58 */
                if (z->c <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((1876480 >> (z->p[z->c - 1] & 0x1f)) & 1)) { z->c = z->l - m_keep; goto lab5; }
                among_var = find_among_b(z, a_2, 25); /* substring, line 58 */
                if (!(among_var)) { z->c = z->l - m_keep; goto lab5; }
                z->bra = z->c; /* ], line 58 */
                {   int ret = z->c - 2;
                    if (z->lb > ret || ret > z->l) { z->c = z->l - m_keep; goto lab5; }
                    z->c = ret; /* hop, line 58 */
                }
                switch(among_var) {
                    case 0: { z->c = z->l - m_keep; goto lab5; }
                    case 1:
                        {   int ret = slice_from_s(z, 1, s_5); /* <-, line 61 */
                            if (ret < 0) return ret;
                        }
                        break;
                    case 2:
                        {   int ret = slice_from_s(z, 2, s_6); /* <-, line 63 */
                            if (ret < 0) return ret;
                        }
                        break;
                    case 3:
                        {   int ret = slice_from_s(z, 3, s_7); /* <-, line 65 */
                            if (ret < 0) return ret;
                        }
                        break;
                    case 4:
                        {   int ret = slice_del(z); /* delete, line 68 */
                            if (ret < 0) return ret;
                        }
                        break;
                }
            lab5:
                ;
            }
            z->c = z->lb;
            failure = 0; /* mark success */
            z->S[1] = z->p;
            * z = env;
            if (failure) return 0;
        }
    }
lab0:
    z->c = z->lb;
    {   int c_keep = z->c;
        int ret = insert_v(z, z->c, z->l, z->S[0]); /* = noun_form, line 74 */
        z->c = c_keep;
        if (ret < 0) return ret;
    }
    return 1;
}

extern struct SN_env * latin_ISO_8859_1_create_env(void) { return SN_create_env(2, 0, 0); }

extern void latin_ISO_8859_1_close_env(struct SN_env * z) { SN_close_env(z, 2); }

