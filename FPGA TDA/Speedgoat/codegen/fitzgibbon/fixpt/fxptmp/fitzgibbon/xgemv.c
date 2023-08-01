#include "xgemv.h"
#include "eml_int_forloop_overflow_check.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"
#include <string.h>

static emlrtRSInfo ad_emlrtRSI = {58, "xgemv",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+refblas\\xgemv.m"};

static emlrtRSInfo og_emlrtRSI = {41, "xgemv",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+refblas\\xgemv.m"};

void b_xgemv(const emlrtStack *sp, int32_T n, const real_T x[9], real_T beta1,
             real_T y[9], int32_T iy0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  int32_T ia;
  int32_T iac;
  int32_T iy;
  int32_T iyend;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  iyend = iy0 + 2;
  if (beta1 != 1.0) {
    if (beta1 == 0.0) {
      b_st.site = &dc_emlrtRSI;
      if ((iy0 <= iy0 + 2) && (iy0 + 2 > 2147483646)) {
        c_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      if (iy0 <= iyend) {
        memset(&y[iy0 + -1], 0, (uint32_T)((iyend - iy0) + 1) * sizeof(real_T));
      }
    } else {
      b_st.site = &og_emlrtRSI;
      if ((iy0 <= iy0 + 2) && (iy0 + 2 > 2147483646)) {
        c_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (iy = iy0; iy <= iyend; iy++) {
        y[iy - 1] *= beta1;
      }
    }
  }
  iyend = 6;
  iy = 3 * (n - 1) + 1;
  for (iac = 1; iac <= iy; iac += 3) {
    b = iac + 2;
    b_st.site = &ad_emlrtRSI;
    if ((iac <= iac + 2) && (iac + 2 > 2147483646)) {
      c_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (ia = iac; ia <= b; ia++) {
      i = ((iy0 + ia) - iac) - 1;
      y[i] += y[ia - 1] * x[iyend];
    }
    iyend++;
  }
}

void xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[9],
           int32_T ia0, const real_T x[9], int32_T ix0, real_T y[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  int32_T i1;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (m != 0) {
    b_st.site = &dc_emlrtRSI;
    if (m > 2147483646) {
      c_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)m;
    memset(&y[0], 0, (uint32_T)i * sizeof(real_T));
    ix = ix0;
    i = ia0 + 3 * (n - 1);
    for (iac = ia0; iac <= i; iac += 3) {
      b = (iac + m) - 1;
      b_st.site = &ad_emlrtRSI;
      if ((iac <= b) && (b > 2147483646)) {
        c_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ia = iac; ia <= b; ia++) {
        i1 = ia - iac;
        y[i1] += A[ia - 1] * x[ix - 1];
      }
      ix++;
    }
  }
}
