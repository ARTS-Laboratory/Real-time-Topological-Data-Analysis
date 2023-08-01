#include "xdtrevc3.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"
#include "xdlaln2.h"
#include "xgemv.h"
#include "xscal.h"
#include "mwmathutil.h"
#include <string.h>

static emlrtRSInfo wf_emlrtRSI = {235, "xdtrevc3",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdtrevc3.m"};

static emlrtRSInfo xf_emlrtRSI = {234, "xdtrevc3",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdtrevc3.m"};

static emlrtRSInfo yf_emlrtRSI = {225, "xdtrevc3",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdtrevc3.m"};

static emlrtRSInfo ag_emlrtRSI = {223, "xdtrevc3",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdtrevc3.m"};

static emlrtRSInfo bg_emlrtRSI = {220, "xdtrevc3",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdtrevc3.m"};

static emlrtRSInfo fg_emlrtRSI = {127, "xdtrevc3",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdtrevc3.m"};

static emlrtRSInfo gg_emlrtRSI = {122, "xdtrevc3",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\+reflapack\\xdtrevc3.m"};

void xdtrevc3(const emlrtStack *sp, const real_T T[9], real_T vr[9])
{
  emlrtStack st;
  real_T work[9];
  real_T x[4];
  real_T remax;
  real_T scale;
  real_T smin;
  real_T wi;
  real_T wr_tmp;
  int32_T i;
  int32_T ii;
  int32_T ip;
  int32_T j;
  int32_T k;
  int32_T ki;
  st.prev = sp;
  st.tls = sp->tls;
  memset(&work[0], 0, 9U * sizeof(real_T));
  x[0] = 0.0;
  x[1] = 0.0;
  x[2] = 0.0;
  x[3] = 0.0;
  work[0] = 0.0;
  for (j = 0; j < 2; j++) {
    work[j + 1] = 0.0;
    for (i = 0; i <= j; i++) {
      work[j + 1] += muDoubleScalarAbs(T[i + 3 * (j + 1)]);
    }
  }
  ip = 0;
  for (ki = 2; ki >= 0; ki--) {
    if (ip == -1) {
      ip = 1;
    } else {
      if ((ki + 1 == 1) || (T[ki + 3 * (ki - 1)] == 0.0)) {
        ip = 0;
      } else {
        ip = -1;
      }
      i = ki + 3 * ki;
      wr_tmp = T[i];
      wi = 0.0;
      if (ip != 0) {
        wi = muDoubleScalarSqrt(muDoubleScalarAbs(T[ki + 3 * (ki - 1)])) *
             muDoubleScalarSqrt(muDoubleScalarAbs(T[i - 1]));
      }
      smin = muDoubleScalarMax(2.2204460492503131E-16 *
                                   (muDoubleScalarAbs(wr_tmp) + wi),
                               3.0062525400134592E-292);
      if (ip == 0) {
        work[ki + 6] = 1.0;
        for (k = 0; k < ki; k++) {
          work[k + 6] = -T[k + 3 * ki];
        }
        j = ki - 1;
        while (j + 1 >= 1) {
          if ((j + 1 == 1) || (T[1] == 0.0)) {
            scale = xdlaln2(1, 1, smin, T, (j * 3 + j) + 1, work, j + 7, wr_tmp,
                            0.0, x, &remax);
            if ((remax > 1.0) && (work[j] > 3.3264005158911989E+291 / remax)) {
              x[0] /= remax;
              scale /= remax;
            }
            if (scale != 1.0) {
              ii = ki + 7;
              for (k = 7; k <= ii; k++) {
                work[k - 1] *= scale;
              }
            }
            work[j + 6] = x[0];
            if ((j >= 1) && (!(-x[0] == 0.0))) {
              work[6] += -x[0] * T[j * 3];
            }
            j--;
          } else {
            scale = xdlaln2(2, 1, smin, T, 1, work, 7, wr_tmp, 0.0, x, &remax);
            if ((remax > 1.0) && (muDoubleScalarMax(work[0], work[1]) >
                                  3.3264005158911989E+291 / remax)) {
              x[0] /= remax;
              x[1] /= remax;
              scale /= remax;
            }
            if (scale != 1.0) {
              ii = ki + 7;
              for (k = 7; k <= ii; k++) {
                work[k - 1] *= scale;
              }
            }
            work[6] = x[0];
            work[7] = x[1];
            j = -1;
          }
        }
        if (ki + 1 > 1) {
          st.site = &gg_emlrtRSI;
          b_xgemv(&st, ki, work, work[ki + 6], vr, ki * 3 + 1);
        }
        i = ki * 3;
        ii = -1;
        remax = muDoubleScalarAbs(vr[i]);
        scale = muDoubleScalarAbs(vr[i + 1]);
        if (scale > remax) {
          ii = 0;
          remax = scale;
        }
        if (muDoubleScalarAbs(vr[i + 2]) > remax) {
          ii = 1;
        }
        st.site = &fg_emlrtRSI;
        b_xscal(&st, 1.0 / muDoubleScalarAbs(vr[(ii + 3 * ki) + 1]), vr,
                ki * 3 + 1);
      } else {
        remax = T[i - 1];
        ii = 3 * (ki - 1);
        scale = T[ki + ii];
        if (muDoubleScalarAbs(remax) >= muDoubleScalarAbs(scale)) {
          work[ki + 2] = 1.0;
          work[ki + 6] = wi / remax;
        } else {
          work[ki + 2] = -wi / scale;
          work[ki + 6] = 1.0;
        }
        work[ki + 3] = 0.0;
        work[ki + 5] = 0.0;
        for (k = 0; k <= ki - 2; k++) {
          work[3] = -work[ki + 2] * T[ii];
          work[6] = -work[ki + 6] * T[3 * ki];
        }
        j = ki - 1;
        while (j >= 1) {
          scale = xdlaln2(1, 2, smin, T, 1, work, 4, wr_tmp, wi, x, &remax);
          if ((remax > 1.0) && (work[0] > 3.3264005158911989E+291 / remax)) {
            x[0] /= remax;
            x[2] /= remax;
            scale /= remax;
          }
          if (scale != 1.0) {
            i = ki + 4;
            for (k = 4; k <= i; k++) {
              work[k - 1] *= scale;
            }
            i = ki + 7;
            for (k = 7; k <= i; k++) {
              work[k - 1] *= scale;
            }
          }
          work[3] = x[0];
          work[6] = x[2];
          j = 0;
        }
        if (ki + 1 > 2) {
          if (work[4] != 1.0) {
            if (work[4] == 0.0) {
              vr[3] = 0.0;
              vr[4] = 0.0;
              vr[5] = 0.0;
            } else {
              vr[3] *= work[4];
              vr[4] *= work[4];
              vr[5] *= work[4];
            }
          }
          vr[3] += vr[0] * work[3];
          vr[4] += vr[1] * work[3];
          vr[5] += vr[2] * work[3];
          st.site = &bg_emlrtRSI;
          b_xgemv(&st, 1, work, work[8], vr, 7);
        } else {
          st.site = &ag_emlrtRSI;
          b_xscal(&st, work[3], vr, ii + 1);
          st.site = &yf_emlrtRSI;
          b_xscal(&st, work[ki + 6], vr, ki * 3 + 1);
        }
        i = 3 * ki + 1;
        remax =
            1.0 /
            muDoubleScalarMax(
                muDoubleScalarMax(
                    muDoubleScalarMax(0.0, muDoubleScalarAbs(vr[ii]) +
                                               muDoubleScalarAbs(vr[3 * ki])),
                    muDoubleScalarAbs(vr[ii + 1]) + muDoubleScalarAbs(vr[i])),
                muDoubleScalarAbs(vr[ii + 2]) +
                    muDoubleScalarAbs(vr[3 * ki + 2]));
        st.site = &xf_emlrtRSI;
        b_xscal(&st, remax, vr, ii + 1);
        st.site = &wf_emlrtRSI;
        b_xscal(&st, remax, vr, i);
      }
    }
  }
}
