#include "xzunghr.h"
#include "eml_int_forloop_overflow_check.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"
#include "xscal.h"
#include "xzlarf.h"
#include <string.h>

static emlrtRSInfo tb_emlrtRSI = {34, "xzungqr",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzungqr.m"};

static emlrtRSInfo ub_emlrtRSI = {41, "xzungqr",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzungqr.m"};

static emlrtRSInfo dd_emlrtRSI = {53, "xzunghr",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzunghr.m"};

static emlrtRSInfo ed_emlrtRSI = {40, "xzunghr",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzunghr.m"};

static emlrtRSInfo fd_emlrtRSI = {38, "xzunghr",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzunghr.m"};

static emlrtRSInfo gd_emlrtRSI = {31, "xzunghr",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzunghr.m"};

static emlrtRSInfo hd_emlrtRSI = {29, "xzunghr",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzunghr.m"};

static emlrtRSInfo id_emlrtRSI = {24, "xzunghr",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzunghr.m"};

static emlrtRSInfo jd_emlrtRSI = {20, "xzunghr",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzunghr.m"};

static emlrtRSInfo kd_emlrtRSI = {15, "xzunghr",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzunghr.m"};

void xzunghr(const emlrtStack *sp, int32_T ilo, int32_T ihi, real_T A[9],
             const real_T tau[2])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T work[3];
  int32_T b_i;
  int32_T i;
  int32_T ia;
  int32_T ia0;
  int32_T iaii;
  int32_T itau;
  int32_T j;
  int32_T nh;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nh = ihi - ilo;
  iaii = ilo + 1;
  for (j = ihi; j >= iaii; j--) {
    ia = (j - 1) * 3;
    st.site = &kd_emlrtRSI;
    if (j - 1 > 2147483646) {
      b_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    i = (uint8_T)(j - 1);
    memset(&A[ia], 0, (uint32_T)((i + ia) - ia) * sizeof(real_T));
    itau = j + 1;
    st.site = &jd_emlrtRSI;
    if ((j + 1 <= ihi) && (ihi > 2147483646)) {
      b_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (b_i = itau; b_i <= ihi; b_i++) {
      A[ia + 2] = A[ia - 1];
    }
    i = ihi + 1;
    st.site = &id_emlrtRSI;
    if (i <= 3) {
      memset(&A[(i + ia) + -1], 0,
             (uint32_T)(((ia - i) - ia) + 4) * sizeof(real_T));
    }
  }
  st.site = &hd_emlrtRSI;
  if (ilo > 2147483646) {
    b_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  i = (uint8_T)ilo;
  for (j = 0; j < i; j++) {
    ia = j * 3;
    st.site = &gd_emlrtRSI;
    A[ia] = 0.0;
    A[ia + 1] = 0.0;
    A[ia + 2] = 0.0;
    A[ia + j] = 1.0;
  }
  i = ihi + 1;
  st.site = &fd_emlrtRSI;
  for (j = i; j < 4; j++) {
    ia = (j - 1) * 3;
    st.site = &ed_emlrtRSI;
    A[ia] = 0.0;
    A[ia + 1] = 0.0;
    A[ia + 2] = 0.0;
    A[(ia + j) - 1] = 1.0;
  }
  ia0 = ilo + ilo * 3;
  st.site = &dd_emlrtRSI;
  if (nh >= 1) {
    i = nh - 1;
    for (j = nh; j <= i; j++) {
      ia = ia0 + j * 3;
      memset(&A[ia], 0, (uint32_T)(((i + ia) - ia) + 1) * sizeof(real_T));
      A[ia + j] = 1.0;
    }
    itau = (ilo + nh) - 2;
    work[0] = 0.0;
    work[1] = 0.0;
    work[2] = 0.0;
    for (b_i = nh; b_i >= 1; b_i--) {
      iaii = (ia0 + b_i) + (b_i - 1) * 3;
      if (b_i < nh) {
        A[iaii - 1] = 1.0;
        b_st.site = &tb_emlrtRSI;
        xzlarf(&b_st, nh, 1, iaii, tau[itau], A, iaii + 3, work);
        b_st.site = &ub_emlrtRSI;
        xscal(&b_st, 1, -tau[itau], A, iaii + 1);
      }
      A[iaii - 1] = 1.0 - tau[itau];
      i = (uint8_T)(b_i - 1);
      for (j = 0; j < i; j++) {
        A[iaii - 2] = 0.0;
      }
      itau--;
    }
  }
}
