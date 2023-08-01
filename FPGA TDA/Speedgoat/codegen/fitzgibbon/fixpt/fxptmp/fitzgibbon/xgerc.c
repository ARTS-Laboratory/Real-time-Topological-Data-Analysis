#include "xgerc.h"
#include "eml_int_forloop_overflow_check.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"

static emlrtRSInfo ec_emlrtRSI = {45, "xgerc",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+blas\\xgerc.m"};

static emlrtRSInfo fc_emlrtRSI = {45, "xger",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+blas\\xger.m"};

static emlrtRSInfo gc_emlrtRSI = {15, "xger",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+refblas\\xger.m"};

static emlrtRSInfo hc_emlrtRSI = {41, "xgerx",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+refblas\\xgerx.m"};

static emlrtRSInfo ic_emlrtRSI = {54, "xgerx",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+refblas\\xgerx.m"};

void b_xgerc(const emlrtStack *sp, int32_T m, int32_T n, real_T alpha1,
             const real_T x[3], int32_T iy0, real_T A[9], int32_T ia0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T temp;
  int32_T b;
  int32_T i;
  int32_T ijA;
  int32_T j;
  int32_T jA;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ec_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &fc_emlrtRSI;
  c_st.site = &gc_emlrtRSI;
  if (!(alpha1 == 0.0)) {
    jA = ia0;
    d_st.site = &hc_emlrtRSI;
    if (n > 2147483646) {
      e_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    i = (uint8_T)n;
    for (j = 0; j < i; j++) {
      temp = A[(iy0 + j) - 1];
      if (temp != 0.0) {
        temp *= alpha1;
        b = (m + jA) - 1;
        d_st.site = &ic_emlrtRSI;
        if ((jA <= b) && (b > 2147483646)) {
          e_st.site = &p_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }
        for (ijA = jA; ijA <= b; ijA++) {
          A[ijA - 1] += x[ijA - jA] * temp;
        }
      }
      jA += 3;
    }
  }
}

void xgerc(const emlrtStack *sp, int32_T m, int32_T n, real_T alpha1,
           int32_T ix0, const real_T y[3], real_T A[9], int32_T ia0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T temp;
  int32_T b;
  int32_T i;
  int32_T ijA;
  int32_T j;
  int32_T jA;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ec_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &fc_emlrtRSI;
  c_st.site = &gc_emlrtRSI;
  if (!(alpha1 == 0.0)) {
    jA = ia0;
    d_st.site = &hc_emlrtRSI;
    if (n > 2147483646) {
      e_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    i = (uint8_T)n;
    for (j = 0; j < i; j++) {
      temp = y[j];
      if (temp != 0.0) {
        temp *= alpha1;
        b = (m + jA) - 1;
        d_st.site = &ic_emlrtRSI;
        if ((jA <= b) && (b > 2147483646)) {
          e_st.site = &p_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }
        for (ijA = jA; ijA <= b; ijA++) {
          A[ijA - 1] += A[((ix0 + ijA) - jA) - 1] * temp;
        }
      }
      jA += 3;
    }
  }
}
