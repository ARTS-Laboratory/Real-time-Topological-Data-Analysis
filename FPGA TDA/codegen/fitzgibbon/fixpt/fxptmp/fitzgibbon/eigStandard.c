#include "eigStandard.h"
#include "eml_int_forloop_overflow_check.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xdlahqr.h"
#include "xdtrevc3.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xzgebal.h"
#include "xzgehrd.h"
#include "xzlascl.h"
#include "xzunghr.h"
#include "mwmathutil.h"
#include <string.h>

static emlrtRSInfo jc_emlrtRSI = {
    44, "mpower",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"};

static emlrtRSInfo kc_emlrtRSI = {143, "xzlartg",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzlartg.m"};

static emlrtRSInfo lc_emlrtRSI = {159, "xzlartg",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzlartg.m"};

static emlrtRSInfo ne_emlrtRSI = {26, "eigStandard",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\ma"
                                  "tlab\\matfun\\private\\eigStandard.m"};

static emlrtRSInfo oe_emlrtRSI = {45, "eigStandard",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\ma"
                                  "tlab\\matfun\\private\\eigStandard.m"};

static emlrtRSInfo pe_emlrtRSI = {52, "xgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+lapack\\xgeev.m"};

static emlrtRSInfo qe_emlrtRSI = {139, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo re_emlrtRSI = {134, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo se_emlrtRSI = {133, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo te_emlrtRSI = {131, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo ue_emlrtRSI = {130, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo ve_emlrtRSI = {102, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo we_emlrtRSI = {101, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo xe_emlrtRSI = {97, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo ye_emlrtRSI = {94, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo af_emlrtRSI = {91, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo bf_emlrtRSI = {90, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo cf_emlrtRSI = {88, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo df_emlrtRSI = {87, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo ef_emlrtRSI = {81, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo ff_emlrtRSI = {79, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo gf_emlrtRSI = {62, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo hf_emlrtRSI = {58, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo if_emlrtRSI = {53, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo jf_emlrtRSI = {49, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo kf_emlrtRSI = {46, "xdgeev",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdgeev.m"};

static emlrtRSInfo pg_emlrtRSI = {18, "xzgebak",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzgebak.m"};

void eigStandard(const emlrtStack *sp, const real_T A[9], creal_T V[9],
                 creal_T D[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  creal_T W[3];
  real_T b_A[9];
  real_T vr[9];
  real_T scale[3];
  real_T wi[3];
  real_T wr[3];
  real_T tau[2];
  real_T absxk;
  real_T anrm;
  real_T b_scale_tmp;
  real_T cs;
  real_T cscale;
  real_T s;
  real_T scale_tmp;
  real_T smax;
  int32_T b_i;
  int32_T b_tmp_tmp;
  int32_T count;
  int32_T i;
  int32_T ilo;
  int32_T info;
  int32_T ix;
  boolean_T exitg1;
  boolean_T scalea;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ne_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &pe_emlrtRSI;
  memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
  info = 0;
  anrm = 0.0;
  count = 0;
  exitg1 = false;
  while ((!exitg1) && (count < 9)) {
    absxk = muDoubleScalarAbs(A[count]);
    if (muDoubleScalarIsNaN(absxk)) {
      anrm = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }
      count++;
    }
  }
  if (muDoubleScalarIsInf(anrm) || muDoubleScalarIsNaN(anrm)) {
    W[0].re = rtNaN;
    W[0].im = 0.0;
    W[1].re = rtNaN;
    W[1].im = 0.0;
    W[2].re = rtNaN;
    W[2].im = 0.0;
    for (i = 0; i < 9; i++) {
      V[i].re = rtNaN;
      V[i].im = 0.0;
    }
  } else {
    cscale = anrm;
    scalea = false;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      scalea = true;
      cscale = 6.7178761075670888E-139;
      c_st.site = &kf_emlrtRSI;
      xzlascl(anrm, cscale, b_A);
    } else if (anrm > 1.4885657073574029E+138) {
      scalea = true;
      cscale = 1.4885657073574029E+138;
      c_st.site = &kf_emlrtRSI;
      xzlascl(anrm, cscale, b_A);
    }
    c_st.site = &jf_emlrtRSI;
    ilo = xzgebal(&c_st, b_A, &ix, scale);
    c_st.site = &if_emlrtRSI;
    xzgehrd(&c_st, b_A, ilo, ix, tau);
    memcpy(&vr[0], &b_A[0], 9U * sizeof(real_T));
    c_st.site = &hf_emlrtRSI;
    xzunghr(&c_st, ilo, ix, vr, tau);
    c_st.site = &gf_emlrtRSI;
    info = xdlahqr(&c_st, ilo, ix, b_A, ilo, ix, vr, wr, wi);
    if (info == 0) {
      c_st.site = &ff_emlrtRSI;
      xdtrevc3(&c_st, b_A, vr);
      c_st.site = &ef_emlrtRSI;
      if (ilo != ix) {
        d_st.site = &pg_emlrtRSI;
        if ((ilo <= ix) && (ix > 2147483646)) {
          e_st.site = &p_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }
        for (b_i = ilo; b_i <= ix; b_i++) {
          i = b_i + 6;
          for (count = b_i; count <= i; count += 3) {
            vr[count - 1] *= scale[b_i - 1];
          }
        }
      }
      i = ilo - 1;
      for (b_i = i; b_i >= 1; b_i--) {
        scale_tmp = scale[b_i - 1];
        if ((int32_T)scale_tmp != b_i) {
          absxk = vr[b_i - 1];
          vr[b_i - 1] = vr[(int32_T)scale_tmp - 1];
          vr[(int32_T)scale_tmp - 1] = absxk;
          absxk = vr[b_i + 2];
          vr[b_i + 2] = vr[(int32_T)scale_tmp + 2];
          vr[(int32_T)scale_tmp + 2] = absxk;
          absxk = vr[b_i + 5];
          vr[b_i + 5] = vr[(int32_T)scale_tmp + 5];
          vr[(int32_T)scale_tmp + 5] = absxk;
        }
      }
      i = ix + 1;
      for (b_i = i; b_i < 4; b_i++) {
        scale_tmp = scale[b_i - 1];
        if ((int32_T)scale_tmp != b_i) {
          absxk = vr[b_i - 1];
          vr[b_i - 1] = vr[(int32_T)scale_tmp - 1];
          vr[(int32_T)scale_tmp - 1] = absxk;
          absxk = vr[b_i + 2];
          vr[b_i + 2] = vr[(int32_T)scale_tmp + 2];
          vr[(int32_T)scale_tmp + 2] = absxk;
          absxk = vr[b_i + 5];
          vr[b_i + 5] = vr[(int32_T)scale_tmp + 5];
          vr[(int32_T)scale_tmp + 5] = absxk;
        }
      }
      for (b_i = 0; b_i < 3; b_i++) {
        scale_tmp = wi[b_i];
        if (!(scale_tmp < 0.0)) {
          if ((b_i + 1 != 3) && (scale_tmp > 0.0)) {
            ix = b_i * 3 + 1;
            c_st.site = &df_emlrtRSI;
            absxk = xnrm2(&c_st, 3, vr, ix);
            b_tmp_tmp = (b_i + 1) * 3;
            c_st.site = &cf_emlrtRSI;
            smax = xnrm2(&c_st, 3, vr, b_tmp_tmp + 1);
            absxk = 1.0 / muDoubleScalarHypot(absxk, smax);
            c_st.site = &bf_emlrtRSI;
            b_xscal(&c_st, absxk, vr, ix);
            c_st.site = &af_emlrtRSI;
            b_xscal(&c_st, absxk, vr, b_tmp_tmp + 1);
            c_st.site = &ye_emlrtRSI;
            d_st.site = &jc_emlrtRSI;
            c_st.site = &ye_emlrtRSI;
            d_st.site = &jc_emlrtRSI;
            scale_tmp = vr[3 * b_i];
            absxk = vr[b_tmp_tmp];
            scale[0] = scale_tmp * scale_tmp + absxk * absxk;
            c_st.site = &ye_emlrtRSI;
            d_st.site = &jc_emlrtRSI;
            c_st.site = &ye_emlrtRSI;
            d_st.site = &jc_emlrtRSI;
            scale_tmp = vr[ix];
            absxk = vr[b_tmp_tmp + 1];
            scale[1] = scale_tmp * scale_tmp + absxk * absxk;
            c_st.site = &ye_emlrtRSI;
            d_st.site = &jc_emlrtRSI;
            c_st.site = &ye_emlrtRSI;
            d_st.site = &jc_emlrtRSI;
            scale_tmp = vr[3 * b_i + 2];
            absxk = vr[b_tmp_tmp + 2];
            count = 0;
            smax = muDoubleScalarAbs(scale[0]);
            s = muDoubleScalarAbs(scale[1]);
            if (s > smax) {
              count = 1;
              smax = s;
            }
            if (muDoubleScalarAbs(scale_tmp * scale_tmp + absxk * absxk) >
                smax) {
              count = 2;
            }
            c_st.site = &xe_emlrtRSI;
            i = count + b_tmp_tmp;
            s = vr[i];
            if (s == 0.0) {
              cs = 1.0;
              s = 0.0;
            } else {
              smax = vr[count + 3 * b_i];
              if (smax == 0.0) {
                cs = 0.0;
                s = 1.0;
              } else {
                scale_tmp = muDoubleScalarAbs(smax);
                b_scale_tmp = muDoubleScalarAbs(s);
                absxk = muDoubleScalarMax(scale_tmp, b_scale_tmp);
                count = 0;
                if (absxk >= 7.4428285367870146E+137) {
                  do {
                    count++;
                    smax *= 1.3435752215134178E-138;
                    s *= 1.3435752215134178E-138;
                  } while ((muDoubleScalarMax(muDoubleScalarAbs(smax),
                                              muDoubleScalarAbs(s)) >=
                            7.4428285367870146E+137) &&
                           (count < 20));
                  absxk = muDoubleScalarHypot(smax, s);
                  cs = smax / absxk;
                  s /= absxk;
                  d_st.site = &kc_emlrtRSI;
                } else if (absxk <= 1.3435752215134178E-138) {
                  do {
                    count++;
                    smax *= 7.4428285367870146E+137;
                    s *= 7.4428285367870146E+137;
                  } while (!!(muDoubleScalarMax(muDoubleScalarAbs(smax),
                                                muDoubleScalarAbs(s)) <=
                              1.3435752215134178E-138));
                  absxk = muDoubleScalarHypot(smax, s);
                  cs = smax / absxk;
                  s /= absxk;
                  d_st.site = &lc_emlrtRSI;
                  if (count > 2147483646) {
                    e_st.site = &p_emlrtRSI;
                    check_forloop_overflow_error(&e_st);
                  }
                } else {
                  absxk = muDoubleScalarHypot(smax, s);
                  cs = smax / absxk;
                  s /= absxk;
                }
                if ((scale_tmp > b_scale_tmp) && (cs < 0.0)) {
                  cs = -cs;
                  s = -s;
                }
              }
            }
            ix = b_i * 3;
            absxk = cs * vr[ix] + s * vr[b_tmp_tmp];
            vr[b_tmp_tmp] = cs * vr[b_tmp_tmp] - s * vr[ix];
            vr[ix] = absxk;
            absxk = vr[b_tmp_tmp + 1];
            smax = vr[ix + 1];
            vr[b_tmp_tmp + 1] = cs * absxk - s * smax;
            vr[ix + 1] = cs * smax + s * absxk;
            absxk = vr[b_tmp_tmp + 2];
            smax = vr[ix + 2];
            vr[b_tmp_tmp + 2] = cs * absxk - s * smax;
            vr[ix + 2] = cs * smax + s * absxk;
            vr[i] = 0.0;
          } else {
            ix = b_i * 3 + 1;
            c_st.site = &we_emlrtRSI;
            absxk = 1.0 / xnrm2(&c_st, 3, vr, ix);
            c_st.site = &ve_emlrtRSI;
            b_xscal(&c_st, absxk, vr, ix);
          }
        }
      }
      for (i = 0; i < 9; i++) {
        V[i].re = vr[i];
        V[i].im = 0.0;
      }
      for (b_tmp_tmp = 0; b_tmp_tmp < 2; b_tmp_tmp++) {
        if ((wi[b_tmp_tmp] > 0.0) && (wi[b_tmp_tmp + 1] < 0.0)) {
          absxk = V[3 * b_tmp_tmp].re;
          ix = 3 * (b_tmp_tmp + 1);
          smax = V[ix].re;
          V[3 * b_tmp_tmp].re = absxk;
          V[3 * b_tmp_tmp].im = smax;
          V[ix].re = absxk;
          V[ix].im = -smax;
          count = 3 * b_tmp_tmp + 1;
          absxk = V[count].re;
          smax = V[ix + 1].re;
          V[count].re = absxk;
          V[count].im = smax;
          V[ix + 1].re = absxk;
          V[ix + 1].im = -smax;
          count = 3 * b_tmp_tmp + 2;
          absxk = V[count].re;
          smax = V[ix + 2].re;
          V[count].re = absxk;
          V[count].im = smax;
          V[ix + 2].re = absxk;
          V[ix + 2].im = -smax;
        }
      }
    } else {
      for (i = 0; i < 9; i++) {
        V[i].re = rtNaN;
        V[i].im = 0.0;
      }
    }
    if (scalea) {
      c_st.site = &ue_emlrtRSI;
      b_xzlascl(&c_st, cscale, anrm, 3 - info, wr, info + 1);
      c_st.site = &te_emlrtRSI;
      b_xzlascl(&c_st, cscale, anrm, 3 - info, wi, info + 1);
      if (info != 0) {
        c_st.site = &se_emlrtRSI;
        b_xzlascl(&c_st, cscale, anrm, ilo - 1, wr, 1);
        c_st.site = &re_emlrtRSI;
        b_xzlascl(&c_st, cscale, anrm, ilo - 1, wi, 1);
      }
    }
    if (info != 0) {
      c_st.site = &qe_emlrtRSI;
      if ((ilo <= info) && (info > 2147483646)) {
        d_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (b_i = ilo; b_i <= info; b_i++) {
        wr[b_i - 1] = rtNaN;
        wi[b_i - 1] = 0.0;
      }
    }
    W[0].re = wr[0];
    W[0].im = wi[0];
    W[1].re = wr[1];
    W[1].im = wi[1];
    W[2].re = wr[2];
    W[2].im = wi[2];
  }
  memset(&D[0], 0, 9U * sizeof(creal_T));
  D[0] = W[0];
  D[4] = W[1];
  D[8] = W[2];
  if (info != 0) {
    st.site = &oe_emlrtRSI;
    c_warning(&st);
  }
}
