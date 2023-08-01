#include "xzlarfg.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xscal.h"
#include "mwmathutil.h"

static emlrtRSInfo ib_emlrtRSI = {81, "xzlarfg",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzlarfg.m"};

static emlrtRSInfo kb_emlrtRSI = {68, "xzlarfg",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzlarfg.m"};

static emlrtRSInfo lb_emlrtRSI = {53, "xzlarfg",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzlarfg.m"};

static emlrtRSInfo mb_emlrtRSI = {41, "xzlarfg",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzlarfg.m"};

static emlrtRSInfo nb_emlrtRSI = {20, "xzlarfg",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xzlarfg.m"};

real_T b_xzlarfg(int32_T n, real_T *alpha1, real_T x[3])
{
  real_T beta1;
  real_T tau;
  real_T xnorm;
  int32_T k;
  int32_T knt;
  tau = 0.0;
  if (n > 0) {
    xnorm = b_xnrm2(n - 1, x);
    if (xnorm != 0.0) {
      beta1 = muDoubleScalarHypot(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        beta1 = -beta1;
      }
      if (muDoubleScalarAbs(beta1) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          for (k = 2; k <= n; k++) {
            x[k - 1] *= 9.9792015476736E+291;
          }
          beta1 *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((muDoubleScalarAbs(beta1) < 1.0020841800044864E-292) &&
                 (knt < 20));
        beta1 = muDoubleScalarHypot(*alpha1, b_xnrm2(n - 1, x));
        if (*alpha1 >= 0.0) {
          beta1 = -beta1;
        }
        tau = (beta1 - *alpha1) / beta1;
        xnorm = 1.0 / (*alpha1 - beta1);
        for (k = 2; k <= n; k++) {
          x[k - 1] *= xnorm;
        }
        for (k = 0; k < knt; k++) {
          beta1 *= 1.0020841800044864E-292;
        }
        *alpha1 = beta1;
      } else {
        tau = (beta1 - *alpha1) / beta1;
        xnorm = 1.0 / (*alpha1 - beta1);
        for (k = 2; k <= n; k++) {
          x[k - 1] *= xnorm;
        }
        *alpha1 = beta1;
      }
    }
  }
  return tau;
}

real_T xzlarfg(const emlrtStack *sp, int32_T n, real_T *alpha1, real_T x[9],
               int32_T ix0)
{
  emlrtStack st;
  real_T tau;
  real_T xnorm;
  int32_T k;
  int32_T knt;
  st.prev = sp;
  st.tls = sp->tls;
  tau = 0.0;
  if (n > 0) {
    st.site = &nb_emlrtRSI;
    xnorm = xnrm2(&st, n - 1, x, ix0);
    if (xnorm != 0.0) {
      xnorm = muDoubleScalarHypot(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }
      if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          st.site = &mb_emlrtRSI;
          xscal(&st, n - 1, 9.9792015476736E+291, x, ix0);
          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) &&
                 (knt < 20));
        st.site = &lb_emlrtRSI;
        xnorm = xnrm2(&st, n - 1, x, ix0);
        xnorm = muDoubleScalarHypot(*alpha1, xnorm);
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }
        tau = (xnorm - *alpha1) / xnorm;
        st.site = &kb_emlrtRSI;
        xscal(&st, n - 1, 1.0 / (*alpha1 - xnorm), x, ix0);
        for (k = 0; k < knt; k++) {
          xnorm *= 1.0020841800044864E-292;
        }
        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        st.site = &ib_emlrtRSI;
        xscal(&st, n - 1, 1.0 / (*alpha1 - xnorm), x, ix0);
        *alpha1 = xnorm;
      }
    }
  }
  return tau;
}
