#include "xrot.h"
#include "eml_int_forloop_overflow_check.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"

static emlrtRSInfo je_emlrtRSI = {32, "xrot",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+blas\\xrot.m"};

static emlrtRSInfo ke_emlrtRSI = {24, "xrot",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+refblas\\xrot.m"};

void b_xrot(const emlrtStack *sp, int32_T n, real_T x[9], int32_T ix0,
            int32_T iy0, real_T c, real_T s)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_temp_tmp;
  real_T temp_tmp;
  int32_T b_temp_tmp_tmp;
  int32_T i;
  int32_T k;
  int32_T temp_tmp_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &je_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (n >= 1) {
    b_st.site = &ke_emlrtRSI;
    if (n > 2147483646) {
      c_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)n;
    for (k = 0; k < i; k++) {
      temp_tmp_tmp = (iy0 + k) - 1;
      temp_tmp = x[temp_tmp_tmp];
      b_temp_tmp_tmp = (ix0 + k) - 1;
      b_temp_tmp = x[b_temp_tmp_tmp];
      x[temp_tmp_tmp] = c * temp_tmp - s * b_temp_tmp;
      x[b_temp_tmp_tmp] = c * b_temp_tmp + s * temp_tmp;
    }
  }
}

void xrot(const emlrtStack *sp, int32_T n, real_T x[9], int32_T ix0,
          int32_T iy0, real_T c, real_T s)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_temp_tmp;
  real_T temp_tmp;
  int32_T b_temp_tmp_tmp;
  int32_T i;
  int32_T k;
  int32_T temp_tmp_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &je_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &ke_emlrtRSI;
  if (n > 2147483646) {
    c_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  i = (uint8_T)n;
  for (k = 0; k < i; k++) {
    temp_tmp_tmp = (iy0 + k * 3) - 1;
    temp_tmp = x[temp_tmp_tmp];
    b_temp_tmp_tmp = (ix0 + k * 3) - 1;
    b_temp_tmp = x[b_temp_tmp_tmp];
    x[temp_tmp_tmp] = c * temp_tmp - s * b_temp_tmp;
    x[b_temp_tmp_tmp] = c * b_temp_tmp + s * temp_tmp;
  }
}
