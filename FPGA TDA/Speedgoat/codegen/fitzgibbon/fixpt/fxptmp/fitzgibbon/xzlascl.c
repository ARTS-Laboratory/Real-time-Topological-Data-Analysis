#include "xzlascl.h"
#include "eml_int_forloop_overflow_check.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

static emlrtRSInfo gb_emlrtRSI = {32, "xzlascl",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzlascl.m"};

static emlrtRSInfo hb_emlrtRSI = {34, "xzlascl",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzlascl.m"};

void b_xzlascl(const emlrtStack *sp, real_T cfrom, real_T cto, int32_T m,
               real_T A[3], int32_T iA0)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T cfrom1;
  real_T cfromc;
  real_T cto1;
  real_T ctoc;
  real_T mul;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  boolean_T notdone;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((muDoubleScalarAbs(cfrom1) > muDoubleScalarAbs(ctoc)) &&
        (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (muDoubleScalarAbs(cto1) > muDoubleScalarAbs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    st.site = &gb_emlrtRSI;
    i = (uint8_T)m;
    st.site = &hb_emlrtRSI;
    if (m > 2147483646) {
      b_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (b_i = 0; b_i < i; b_i++) {
      i1 = (iA0 + b_i) - 1;
      A[i1] *= mul;
    }
  }
}

void xzlascl(real_T cfrom, real_T cto, real_T A[9])
{
  real_T cfrom1;
  real_T cfromc;
  real_T cto1;
  real_T ctoc;
  real_T mul;
  int32_T j;
  int32_T offset;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((muDoubleScalarAbs(cfrom1) > muDoubleScalarAbs(ctoc)) &&
        (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (muDoubleScalarAbs(cto1) > muDoubleScalarAbs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    for (j = 0; j < 3; j++) {
      offset = j * 3 - 1;
      A[offset + 1] *= mul;
      A[offset + 2] *= mul;
      A[offset + 3] *= mul;
    }
  }
}
