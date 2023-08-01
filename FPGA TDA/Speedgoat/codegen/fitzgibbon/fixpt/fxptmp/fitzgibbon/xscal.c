#include "xscal.h"
#include "eml_int_forloop_overflow_check.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"

static emlrtRSInfo qb_emlrtRSI = {31, "xscal",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+blas\\xscal.m"};

static emlrtRSInfo rb_emlrtRSI = {18, "xscal",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+refblas\\xscal.m"};

void b_xscal(const emlrtStack *sp, real_T a, real_T x[9], int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = ix0 + 2;
  b_st.site = &rb_emlrtRSI;
  if ((ix0 <= ix0 + 2) && (ix0 + 2 > 2147483646)) {
    c_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

void xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[9], int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = (ix0 + n) - 1;
  b_st.site = &rb_emlrtRSI;
  if ((ix0 <= b) && (b > 2147483646)) {
    c_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}
