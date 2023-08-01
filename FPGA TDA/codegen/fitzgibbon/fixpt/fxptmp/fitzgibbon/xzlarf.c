#include "xzlarf.h"
#include "eml_int_forloop_overflow_check.h"
#include "fitzgibbon_float_mex_data.h"
#include "fitzgibbon_float_mex_mexutil.h"
#include "rt_nonfinite.h"
#include "xgerc.h"
#include <string.h>

static emlrtRSInfo ac_emlrtRSI = {103, "ilazlc",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzlarf.m"};

int32_T ilazlc(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[9],
               int32_T ia0)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T colbottom;
  int32_T coltop;
  int32_T exitg1;
  int32_T j;
  boolean_T exitg2;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  j = n;
  exitg2 = false;
  while ((!exitg2) && (j > 0)) {
    coltop = ia0 + (j - 1) * 3;
    colbottom = (coltop + m) - 1;
    st.site = &ac_emlrtRSI;
    if ((coltop <= colbottom) && (colbottom > 2147483646)) {
      b_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    do {
      exitg1 = 0;
      if (coltop <= colbottom) {
        if (A[coltop - 1] != 0.0) {
          exitg1 = 1;
        } else {
          coltop++;
        }
      } else {
        j--;
        exitg1 = 2;
      }
    } while (exitg1 == 0);
    if (exitg1 == 1) {
      exitg2 = true;
    }
  }
  return j;
}

void xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0, real_T tau,
            real_T C[9], int32_T ic0, real_T work[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T c;
  int32_T b_i;
  int32_T i;
  int32_T ia;
  int32_T iac;
  int32_T lastc;
  int32_T lastv;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (tau != 0.0) {
    lastv = m;
    i = iv0 + m;
    while ((lastv > 0) && (C[i - 2] == 0.0)) {
      lastv--;
      i--;
    }
    st.site = &yb_emlrtRSI;
    lastc = ilazlc(&st, lastv, n, C, ic0);
  } else {
    lastv = 0;
    lastc = 0;
  }
  if (lastv > 0) {
    st.site = &xb_emlrtRSI;
    b_st.site = &bc_emlrtRSI;
    if (lastc != 0) {
      c_st.site = &dc_emlrtRSI;
      if (lastc > 2147483646) {
        d_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      b_i = (uint8_T)lastc;
      memset(&work[0], 0, (uint32_T)b_i * sizeof(real_T));
      b_i = ic0 + 3 * (lastc - 1);
      for (iac = ic0; iac <= b_i; iac += 3) {
        c = 0.0;
        i = (iac + lastv) - 1;
        c_st.site = &cc_emlrtRSI;
        if ((iac <= i) && (i > 2147483646)) {
          d_st.site = &p_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (ia = iac; ia <= i; ia++) {
          c += C[ia - 1] * C[((iv0 + ia) - iac) - 1];
        }
        i = div_nde_s32_floor(iac - ic0);
        work[i] += c;
      }
    }
    st.site = &wb_emlrtRSI;
    xgerc(&st, lastv, lastc, -tau, iv0, work, C, ic0);
  }
}
