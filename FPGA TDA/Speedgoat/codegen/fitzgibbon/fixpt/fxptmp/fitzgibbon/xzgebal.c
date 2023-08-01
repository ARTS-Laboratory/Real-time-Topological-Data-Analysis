#include "xzgebal.h"
#include "eml_int_forloop_overflow_check.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xswap.h"
#include "mwmathutil.h"

static emlrtRSInfo lf_emlrtRSI = {170, "xzgebal",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzgebal.m"};

static emlrtRSInfo mf_emlrtRSI = {120, "xzgebal",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzgebal.m"};

static emlrtRSInfo nf_emlrtRSI = {119, "xzgebal",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzgebal.m"};

static emlrtRSInfo of_emlrtRSI = {95, "xzgebal",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzgebal.m"};

static emlrtRSInfo pf_emlrtRSI = {92, "xzgebal",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzgebal.m"};

static emlrtRSInfo qf_emlrtRSI = {76, "xzgebal",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzgebal.m"};

static emlrtRSInfo rf_emlrtRSI = {74, "xzgebal",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzgebal.m"};

static emlrtRSInfo sf_emlrtRSI = {55, "xzgebal",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzgebal.m"};

static emlrtRSInfo tf_emlrtRSI = {39, "xzgebal",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzgebal.m"};

int32_T xzgebal(const emlrtStack *sp, real_T A[9], int32_T *ihi,
                real_T scale[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T absxk;
  real_T b_scale;
  real_T c;
  real_T ca;
  real_T f;
  real_T r;
  real_T t;
  int32_T b_i;
  int32_T exitg1;
  int32_T exitg2;
  int32_T exitg4;
  int32_T exitg5;
  int32_T i;
  int32_T ilo;
  int32_T ira;
  int32_T ix0_tmp;
  int32_T k;
  int32_T kend;
  boolean_T converged;
  boolean_T exitg3;
  boolean_T exitg6;
  boolean_T exitg7;
  boolean_T notdone;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  scale[0] = 1.0;
  scale[1] = 1.0;
  scale[2] = 1.0;
  ilo = 1;
  *ihi = 3;
  notdone = true;
  do {
    exitg5 = 0;
    if (notdone) {
      notdone = false;
      kend = *ihi;
      do {
        exitg4 = 0;
        if (kend > 0) {
          converged = false;
          st.site = &tf_emlrtRSI;
          i = 0;
          exitg6 = false;
          while ((!exitg6) && (i <= *ihi - 1)) {
            if ((i + 1 == kend) || (!(A[(kend + 3 * i) - 1] != 0.0))) {
              i++;
            } else {
              converged = true;
              exitg6 = true;
            }
          }
          if (converged) {
            kend--;
          } else {
            scale[*ihi - 1] = kend;
            if (kend != *ihi) {
              st.site = &sf_emlrtRSI;
              xswap(&st, *ihi, A, (kend - 1) * 3 + 1, (*ihi - 1) * 3 + 1);
              b_scale = A[kend - 1];
              A[kend - 1] = A[*ihi - 1];
              A[*ihi - 1] = b_scale;
              b_scale = A[kend + 2];
              A[kend + 2] = A[*ihi + 2];
              A[*ihi + 2] = b_scale;
              b_scale = A[kend + 5];
              A[kend + 5] = A[*ihi + 5];
              A[*ihi + 5] = b_scale;
            }
            exitg4 = 1;
          }
        } else {
          exitg4 = 2;
        }
      } while (exitg4 == 0);
      if (exitg4 == 1) {
        if (*ihi == 1) {
          ilo = 1;
          *ihi = 1;
          exitg5 = 1;
        } else {
          (*ihi)--;
          notdone = true;
        }
      }
    } else {
      notdone = true;
      while (notdone) {
        notdone = false;
        st.site = &rf_emlrtRSI;
        kend = ilo;
        exitg6 = false;
        while ((!exitg6) && (kend <= *ihi)) {
          converged = false;
          st.site = &qf_emlrtRSI;
          i = ilo;
          exitg7 = false;
          while ((!exitg7) && (i <= *ihi)) {
            if ((i == kend) || (!(A[(i + 3 * (kend - 1)) - 1] != 0.0))) {
              i++;
            } else {
              converged = true;
              exitg7 = true;
            }
          }
          if (converged) {
            kend++;
          } else {
            scale[ilo - 1] = kend;
            if (kend != ilo) {
              b_i = (ilo - 1) * 3;
              st.site = &pf_emlrtRSI;
              xswap(&st, *ihi, A, (kend - 1) * 3 + 1, b_i + 1);
              kend = (b_i + kend) - 1;
              ira = (b_i + ilo) - 1;
              st.site = &of_emlrtRSI;
              b_st.site = &uf_emlrtRSI;
              c_st.site = &vf_emlrtRSI;
              if (4 - ilo > 2147483646) {
                d_st.site = &p_emlrtRSI;
                check_forloop_overflow_error(&d_st);
              }
              b_i = (uint8_T)(4 - ilo);
              for (k = 0; k < b_i; k++) {
                ix0_tmp = kend + k * 3;
                b_scale = A[ix0_tmp];
                i = ira + k * 3;
                A[ix0_tmp] = A[i];
                A[i] = b_scale;
              }
            }
            ilo++;
            notdone = true;
            exitg6 = true;
          }
        }
      }
      converged = false;
      exitg5 = 2;
    }
  } while (exitg5 == 0);
  if (exitg5 != 1) {
    exitg3 = false;
    while ((!exitg3) && (!converged)) {
      converged = true;
      st.site = &nf_emlrtRSI;
      i = ilo - 1;
      do {
        exitg2 = 0;
        if (i + 1 <= *ihi) {
          kend = (*ihi - ilo) + 1;
          st.site = &mf_emlrtRSI;
          c = xnrm2(&st, kend, A, i * 3 + ilo);
          ix0_tmp = (ilo - 1) * 3 + i;
          r = 0.0;
          if (kend >= 1) {
            if (kend == 1) {
              r = muDoubleScalarAbs(A[ix0_tmp]);
            } else {
              b_scale = 3.3121686421112381E-170;
              kend = (ix0_tmp + (kend - 1) * 3) + 1;
              for (k = ix0_tmp + 1; k <= kend; k += 3) {
                absxk = muDoubleScalarAbs(A[k - 1]);
                if (absxk > b_scale) {
                  t = b_scale / absxk;
                  r = r * t * t + 1.0;
                  b_scale = absxk;
                } else {
                  t = absxk / b_scale;
                  r += t * t;
                }
              }
              r = b_scale * muDoubleScalarSqrt(r);
            }
          }
          ira = i * 3;
          kend = 1;
          if (*ihi > 1) {
            b_scale = muDoubleScalarAbs(A[ira]);
            for (k = 2; k <= *ihi; k++) {
              t = muDoubleScalarAbs(A[(ira + k) - 1]);
              if (t > b_scale) {
                kend = k;
                b_scale = t;
              }
            }
          }
          ca = muDoubleScalarAbs(A[(kend + 3 * i) - 1]);
          kend = 4 - ilo;
          if (4 - ilo < 1) {
            ira = 0;
          } else {
            ira = 1;
            if (4 - ilo > 1) {
              b_scale = muDoubleScalarAbs(A[ix0_tmp]);
              for (k = 2; k <= kend; k++) {
                t = muDoubleScalarAbs(A[ix0_tmp + (k - 1) * 3]);
                if (t > b_scale) {
                  ira = k;
                  b_scale = t;
                }
              }
            }
          }
          b_scale = muDoubleScalarAbs(A[i + 3 * ((ira + ilo) - 2)]);
          if ((c == 0.0) || (r == 0.0)) {
            i++;
          } else {
            absxk = r / 2.0;
            f = 1.0;
            t = c + r;
            do {
              exitg1 = 0;
              if ((c < absxk) &&
                  (muDoubleScalarMax(f, muDoubleScalarMax(c, ca)) <
                   4.9896007738368E+291) &&
                  (muDoubleScalarMin(r, muDoubleScalarMin(absxk, b_scale)) >
                   2.0041683600089728E-292)) {
                if (muDoubleScalarIsNaN(((((c + f) + ca) + r) + absxk) +
                                        b_scale)) {
                  exitg1 = 1;
                } else {
                  f *= 2.0;
                  c *= 2.0;
                  ca *= 2.0;
                  r /= 2.0;
                  absxk /= 2.0;
                  b_scale /= 2.0;
                }
              } else {
                absxk = c / 2.0;
                while ((absxk >= r) &&
                       (muDoubleScalarMax(r, b_scale) < 4.9896007738368E+291) &&
                       (muDoubleScalarMin(muDoubleScalarMin(f, c),
                                          muDoubleScalarMin(absxk, ca)) >
                        2.0041683600089728E-292)) {
                  f /= 2.0;
                  c /= 2.0;
                  absxk /= 2.0;
                  ca /= 2.0;
                  r *= 2.0;
                  b_scale *= 2.0;
                }
                if ((!(c + r >= 0.95 * t)) &&
                    ((!(f < 1.0)) || (!(scale[i] < 1.0)) ||
                     (!(f * scale[i] <= 1.0020841800044864E-292))) &&
                    ((!(f > 1.0)) || (!(scale[i] > 1.0)) ||
                     (!(scale[i] >= 9.9792015476736E+291 / f)))) {
                  b_scale = 1.0 / f;
                  scale[i] *= f;
                  ira = ix0_tmp + 1;
                  b_i = (ix0_tmp + 3 * (3 - ilo)) + 1;
                  for (k = ira; k <= b_i; k += 3) {
                    A[k - 1] *= b_scale;
                  }
                  st.site = &lf_emlrtRSI;
                  xscal(&st, *ihi, f, A, i * 3 + 1);
                  converged = false;
                }
                exitg1 = 2;
              }
            } while (exitg1 == 0);
            if (exitg1 == 1) {
              exitg2 = 2;
            } else {
              i++;
            }
          }
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);
      if (exitg2 != 1) {
        exitg3 = true;
      }
    }
  }
  return ilo;
}
