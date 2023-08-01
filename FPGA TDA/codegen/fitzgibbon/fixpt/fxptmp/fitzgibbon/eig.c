#include "eig.h"
#include "anyNonFinite.h"
#include "eigStandard.h"
#include "eml_int_forloop_overflow_check.h"
#include "fitzgibbon_float_mex_data.h"
#include "fitzgibbon_float_mex_mexutil.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xgemv.h"
#include "xgerc.h"
#include "xhseqr.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

static emlrtRSInfo u_emlrtRSI = {
    81, "eig",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"};

static emlrtRSInfo v_emlrtRSI = {
    125, "eig",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"};

static emlrtRSInfo w_emlrtRSI = {
    133, "eig",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"};

static emlrtRSInfo x_emlrtRSI = {
    141, "eig",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"};

static emlrtRSInfo cb_emlrtRSI = {
    27, "eigHermitianStandard",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigHerm"
    "itianStandard.m"};

static emlrtRSInfo db_emlrtRSI = {
    40, "eigHermitianStandard",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigHerm"
    "itianStandard.m"};

static emlrtRSInfo eb_emlrtRSI = {10, "xsyheev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+lapack\\xsyheev.m"};

static emlrtRSInfo fb_emlrtRSI = {61, "ceval_xsyheev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+lapack\\xsyheev.m"};

static emlrtRSInfo mc_emlrtRSI = {
    12, "eigSkewHermitianStandard",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigSkew"
    "HermitianStandard.m"};

static emlrtRSInfo nc_emlrtRSI = {
    22, "eigRealSkewSymmetricStandard",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigReal"
    "SkewSymmetricStandard.m"};

static emlrtRSInfo oc_emlrtRSI = {
    35, "schur",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"};

static emlrtRSInfo pc_emlrtRSI = {
    66, "schur",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"};

static emlrtRSInfo qc_emlrtRSI = {
    69, "schur",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"};

static emlrtRSInfo rc_emlrtRSI = {
    70, "schur",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"};

static emlrtRSInfo sc_emlrtRSI = {
    83, "schur",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"};

static emlrtRSInfo tc_emlrtRSI = {18, "xgehrd",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+lapack\\xgehrd.m"};

static emlrtRSInfo bd_emlrtRSI = {11, "xungorghr",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+lapack\\xungorghr.m"};

static emlrtRSInfo cd_emlrtRSI = {69, "ceval_xungorghr",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+lapack\\xungorghr.m"};

static emlrtRTEInfo c_emlrtRTEI = {44, 13, "infocheck",
                                   "C:\\Program "
                                   "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                   "coder\\+internal\\+lapack\\infocheck.m"};

static emlrtRTEInfo d_emlrtRTEI = {47, 13, "infocheck",
                                   "C:\\Program "
                                   "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                   "coder\\+internal\\+lapack\\infocheck.m"};

void eig(const emlrtStack *sp, const real_T A[9], creal_T V[9], creal_T D[9])
{
  static const char_T b_fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                     '_', 'd', 'o', 'r', 'g', 'h', 'r'};
  static const char_T fname[13] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 's', 'y', 'e', 'v'};
  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack st;
  real_T U[9];
  real_T b_A[9];
  real_T work[3];
  real_T tau[2];
  real_T alpha1;
  real_T c;
  int32_T alpha1_tmp;
  int32_T b_i;
  int32_T c_i;
  int32_T exitg1;
  int32_T i;
  int32_T ia;
  int32_T in;
  int32_T iv0_tmp;
  int32_T lastc;
  int32_T lastv;
  int32_T rowleft;
  boolean_T b_p;
  boolean_T exitg2;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &u_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  if (anyNonFinite(A)) {
    for (i = 0; i < 9; i++) {
      V[i].re = rtNaN;
      V[i].im = 0.0;
      D[i].re = 0.0;
      D[i].im = 0.0;
    }
    D[0].re = rtNaN;
    D[0].im = 0.0;
    D[4].re = rtNaN;
    D[4].im = 0.0;
    D[8].re = rtNaN;
    D[8].im = 0.0;
  } else {
    p = true;
    in = 0;
    exitg2 = false;
    while ((!exitg2) && (in < 3)) {
      b_i = 0;
      do {
        exitg1 = 0;
        if (b_i <= in) {
          if (!(A[b_i + 3 * in] == A[in + 3 * b_i])) {
            p = false;
            exitg1 = 1;
          } else {
            b_i++;
          }
        } else {
          in++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);
      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
    if (p) {
      st.site = &v_emlrtRSI;
      b_st.site = &cb_emlrtRSI;
      memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
      c_st.site = &eb_emlrtRSI;
      info_t = (ptrdiff_t)3;
      info_t = LAPACKE_dsyev(102, 'V', 'L', info_t, &b_A[0], info_t, &work[0]);
      d_st.site = &fb_emlrtRSI;
      if ((int32_T)info_t < 0) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&d_st, &c_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&d_st, &d_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 13, &fname[0], 12, (int32_T)info_t);
        }
      }
      memset(&D[0], 0, 9U * sizeof(creal_T));
      D[0].re = work[0];
      D[0].im = 0.0;
      D[4].re = work[1];
      D[4].im = 0.0;
      D[8].re = work[2];
      D[8].im = 0.0;
      for (i = 0; i < 9; i++) {
        V[i].re = b_A[i];
        V[i].im = 0.0;
      }
      if ((int32_T)info_t != 0) {
        b_st.site = &db_emlrtRSI;
        c_warning(&b_st);
      }
    } else {
      p = true;
      in = 0;
      exitg2 = false;
      while ((!exitg2) && (in < 3)) {
        b_i = 0;
        do {
          exitg1 = 0;
          if (b_i <= in) {
            if (!(A[b_i + 3 * in] == -A[in + 3 * b_i])) {
              p = false;
              exitg1 = 1;
            } else {
              b_i++;
            }
          } else {
            in++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);
        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
      if (p) {
        st.site = &w_emlrtRSI;
        b_st.site = &mc_emlrtRSI;
        c_st.site = &nc_emlrtRSI;
        d_st.site = &oc_emlrtRSI;
        if (anyNonFinite(A)) {
          for (i = 0; i < 9; i++) {
            U[i] = rtNaN;
          }
          c_i = 2;
          for (in = 0; in < 2; in++) {
            if (c_i <= 3) {
              memset(&U[(in * 3 + c_i) + -1], 0,
                     (uint32_T)(-c_i + 4) * sizeof(real_T));
            }
            c_i++;
          }
          for (i = 0; i < 9; i++) {
            b_A[i] = rtNaN;
          }
        } else {
          d_st.site = &pc_emlrtRSI;
          memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
          e_st.site = &tc_emlrtRSI;
          work[0] = 0.0;
          work[1] = 0.0;
          work[2] = 0.0;
          for (b_i = 0; b_i < 2; b_i++) {
            c_i = b_i * 3 + 2;
            in = (b_i + 1) * 3;
            alpha1_tmp = (b_i + 3 * b_i) + 1;
            alpha1 = b_A[alpha1_tmp];
            f_st.site = &uc_emlrtRSI;
            c = xzlarfg(&f_st, 2 - b_i, &alpha1, b_A, c_i + 1);
            tau[b_i] = c;
            b_A[alpha1_tmp] = 1.0;
            iv0_tmp = b_i + c_i;
            f_st.site = &vc_emlrtRSI;
            if (c != 0.0) {
              lastv = 2 - b_i;
              c_i = iv0_tmp - b_i;
              while ((lastv > 0) && (b_A[c_i] == 0.0)) {
                lastv--;
                c_i--;
              }
              lastc = 3;
              exitg2 = false;
              while ((!exitg2) && (lastc > 0)) {
                rowleft = in + lastc;
                ia = rowleft;
                do {
                  exitg1 = 0;
                  if (ia <= rowleft + (lastv - 1) * 3) {
                    if (b_A[ia - 1] != 0.0) {
                      exitg1 = 1;
                    } else {
                      ia += 3;
                    }
                  } else {
                    lastc--;
                    exitg1 = 2;
                  }
                } while (exitg1 == 0);
                if (exitg1 == 1) {
                  exitg2 = true;
                }
              }
            } else {
              lastv = 0;
              lastc = 0;
            }
            if (lastv > 0) {
              g_st.site = &xc_emlrtRSI;
              xgemv(&g_st, lastc, lastv, b_A, in + 1, b_A, iv0_tmp, work);
              g_st.site = &yc_emlrtRSI;
              b_xgerc(&g_st, lastc, lastv, -tau[b_i], work, iv0_tmp, b_A,
                      in + 1);
            }
            rowleft = (b_i + in) + 2;
            f_st.site = &wc_emlrtRSI;
            if (tau[b_i] != 0.0) {
              lastv = 2 - b_i;
              c_i = iv0_tmp - b_i;
              while ((lastv > 0) && (b_A[c_i] == 0.0)) {
                lastv--;
                c_i--;
              }
              g_st.site = &yb_emlrtRSI;
              lastc = ilazlc(&g_st, lastv, 2 - b_i, b_A, rowleft);
            } else {
              lastv = 0;
              lastc = 0;
            }
            if (lastv > 0) {
              g_st.site = &xb_emlrtRSI;
              h_st.site = &bc_emlrtRSI;
              if (lastc != 0) {
                i_st.site = &dc_emlrtRSI;
                if (lastc > 2147483646) {
                  j_st.site = &p_emlrtRSI;
                  check_forloop_overflow_error(&j_st);
                }
                i = (uint8_T)lastc;
                memset(&work[0], 0, (uint32_T)i * sizeof(real_T));
                i = rowleft + 3 * (lastc - 1);
                for (in = rowleft; in <= i; in += 3) {
                  c = 0.0;
                  c_i = (in + lastv) - 1;
                  i_st.site = &cc_emlrtRSI;
                  if ((in <= c_i) && (c_i > 2147483646)) {
                    j_st.site = &p_emlrtRSI;
                    check_forloop_overflow_error(&j_st);
                  }
                  for (ia = in; ia <= c_i; ia++) {
                    c += b_A[ia - 1] * b_A[((iv0_tmp + ia) - in) - 1];
                  }
                  c_i = div_nde_s32_floor(in - rowleft);
                  work[c_i] += c;
                }
              }
              g_st.site = &wb_emlrtRSI;
              xgerc(&g_st, lastv, lastc, -tau[b_i], iv0_tmp, work, b_A,
                    rowleft);
            }
            b_A[alpha1_tmp] = alpha1;
          }
          d_st.site = &qc_emlrtRSI;
          memcpy(&U[0], &b_A[0], 9U * sizeof(real_T));
          e_st.site = &bd_emlrtRSI;
          info_t = LAPACKE_dorghr(102, (ptrdiff_t)3, (ptrdiff_t)1, (ptrdiff_t)3,
                                  &U[0], (ptrdiff_t)3, &tau[0]);
          f_st.site = &cd_emlrtRSI;
          if ((int32_T)info_t != 0) {
            p = true;
            b_p = false;
            if ((int32_T)info_t == -5) {
              b_p = true;
            } else if ((int32_T)info_t == -7) {
              b_p = true;
            }
            if (!b_p) {
              if ((int32_T)info_t == -1010) {
                emlrtErrorWithMessageIdR2018a(
                    &f_st, &c_emlrtRTEI, "MATLAB:nomem", "MATLAB:nomem", 0);
              } else {
                emlrtErrorWithMessageIdR2018a(
                    &f_st, &d_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
                    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &b_fname[0],
                    12, (int32_T)info_t);
              }
            }
          } else {
            p = false;
          }
          if (p) {
            for (i = 0; i < 9; i++) {
              U[i] = rtNaN;
            }
          }
          d_st.site = &rc_emlrtRSI;
          c_i = xhseqr(&d_st, b_A, U);
          if (c_i != 0) {
            d_st.site = &sc_emlrtRSI;
            d_warning(&d_st);
          }
        }
        memset(&D[0], 0, 9U * sizeof(creal_T));
        b_i = 1;
        do {
          exitg1 = 0;
          if (b_i <= 3) {
            if (b_i != 3) {
              i = b_i + 3 * (b_i - 1);
              c = b_A[i];
              if (c != 0.0) {
                c = muDoubleScalarAbs(c);
                D[i - 1].re = 0.0;
                D[i - 1].im = c;
                i = b_i + 3 * b_i;
                D[i].re = 0.0;
                D[i].im = -c;
                b_i += 2;
              } else {
                b_i++;
              }
            } else {
              b_i++;
            }
          } else {
            exitg1 = 1;
          }
        } while (exitg1 == 0);
        for (i = 0; i < 9; i++) {
          V[i].re = U[i];
          V[i].im = 0.0;
        }
        in = 1;
        do {
          exitg1 = 0;
          if (in <= 3) {
            if (in != 3) {
              i = 3 * (in - 1);
              c = b_A[in + i];
              if (c != 0.0) {
                if (c < 0.0) {
                  c_i = 1;
                } else {
                  c_i = -1;
                }
                c = V[i].re;
                alpha1 = (real_T)c_i * V[3 * in].re;
                if (alpha1 == 0.0) {
                  V[i].re = c / 1.4142135623730951;
                  V[i].im = 0.0;
                } else if (c == 0.0) {
                  V[i].re = 0.0;
                  V[i].im = alpha1 / 1.4142135623730951;
                } else {
                  V[i].re = c / 1.4142135623730951;
                  V[i].im = alpha1 / 1.4142135623730951;
                }
                V[3 * in].re = V[i].re;
                V[3 * in].im = -V[i].im;
                c = V[i + 1].re;
                rowleft = 3 * in + 1;
                alpha1 = (real_T)c_i * V[rowleft].re;
                if (alpha1 == 0.0) {
                  V[i + 1].re = c / 1.4142135623730951;
                  V[i + 1].im = 0.0;
                } else if (c == 0.0) {
                  V[i + 1].re = 0.0;
                  V[i + 1].im = alpha1 / 1.4142135623730951;
                } else {
                  V[i + 1].re = c / 1.4142135623730951;
                  V[i + 1].im = alpha1 / 1.4142135623730951;
                }
                V[rowleft].re = V[i + 1].re;
                V[rowleft].im = -V[i + 1].im;
                c = V[i + 2].re;
                rowleft = 3 * in + 2;
                alpha1 = (real_T)c_i * V[rowleft].re;
                if (alpha1 == 0.0) {
                  V[i + 2].re = c / 1.4142135623730951;
                  V[i + 2].im = 0.0;
                } else if (c == 0.0) {
                  V[i + 2].re = 0.0;
                  V[i + 2].im = alpha1 / 1.4142135623730951;
                } else {
                  V[i + 2].re = c / 1.4142135623730951;
                  V[i + 2].im = alpha1 / 1.4142135623730951;
                }
                V[rowleft].re = V[i + 2].re;
                V[rowleft].im = -V[i + 2].im;
                in += 2;
              } else {
                in++;
              }
            } else {
              in++;
            }
          } else {
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      } else {
        st.site = &x_emlrtRSI;
        eigStandard(&st, A, V, D);
      }
    }
  }
}
