#include "xdlaln2.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"
#include "xdladiv.h"
#include "mwmathutil.h"

real_T xdlaln2(int32_T na, int32_T nw, real_T smin, const real_T A[9],
               int32_T ia0, const real_T B[9], int32_T ib0, real_T wr,
               real_T wi, real_T X[4], real_T *xnorm)
{
  static const int8_T ipivot[16] = {1, 2, 3, 4, 2, 1, 4, 3,
                                    3, 4, 1, 2, 4, 3, 2, 1};
  real_T ci[4];
  real_T cr[4];
  real_T bi1;
  real_T bi2;
  real_T br1;
  real_T br2;
  real_T cmax;
  real_T cr21;
  real_T cr22;
  real_T lr21;
  real_T scale;
  real_T temp;
  real_T ui11r;
  real_T ui12;
  real_T ui12s;
  real_T ur11r;
  real_T ur12;
  real_T ur12s;
  int32_T b_cr21_tmp;
  int32_T cr21_tmp;
  int32_T icmax;
  int32_T ur12_tmp;
  scale = 1.0;
  if (na == 1) {
    if (nw == 1) {
      cr21 = A[ia0 - 1] - wr;
      ui12 = muDoubleScalarAbs(cr21);
      if (ui12 < smin) {
        cr21 = smin;
        ui12 = smin;
      }
      cr22 = B[ib0 - 1];
      lr21 = muDoubleScalarAbs(cr22);
      if ((ui12 < 1.0) && (lr21 > 1.0) &&
          (lr21 > 2.2471164185778949E+307 * ui12)) {
        scale = 1.0 / lr21;
      }
      X[0] = cr22 * scale / cr21;
      *xnorm = muDoubleScalarAbs(X[0]);
    } else {
      cr21 = A[ia0 - 1] - wr;
      temp = -wi;
      ui12 = muDoubleScalarAbs(cr21) + muDoubleScalarAbs(-wi);
      if (ui12 < smin) {
        cr21 = smin;
        temp = 0.0;
        ui12 = smin;
      }
      cr22 = B[ib0 - 1];
      ur12 = B[ib0 + 2];
      lr21 = muDoubleScalarAbs(cr22) + muDoubleScalarAbs(ur12);
      if ((ui12 < 1.0) && (lr21 > 1.0) &&
          (lr21 > 2.2471164185778949E+307 * ui12)) {
        scale = 1.0 / lr21;
      }
      X[0] = xdladiv(scale * cr22, scale * ur12, cr21, temp, &X[2]);
      *xnorm = muDoubleScalarAbs(X[0]) + muDoubleScalarAbs(X[2]);
    }
  } else {
    cr[0] = A[ia0 - 1] - wr;
    cr[3] = A[ia0 + 3] - wr;
    cr[1] = A[ia0];
    cr[2] = A[ia0 + 2];
    if (nw == 1) {
      cmax = 0.0;
      icmax = -1;
      cr21 = muDoubleScalarAbs(cr[0]);
      if (cr21 > 0.0) {
        cmax = cr21;
        icmax = 0;
      }
      cr21 = muDoubleScalarAbs(cr[1]);
      if (cr21 > cmax) {
        cmax = cr21;
        icmax = 1;
      }
      cr21 = muDoubleScalarAbs(cr[2]);
      if (cr21 > cmax) {
        cmax = cr21;
        icmax = 2;
      }
      cr21 = muDoubleScalarAbs(cr[3]);
      if (cr21 > cmax) {
        cmax = cr21;
        icmax = 3;
      }
      if (cmax < smin) {
        cr22 = B[ib0 - 1];
        lr21 = muDoubleScalarMax(muDoubleScalarAbs(cr22),
                                 muDoubleScalarAbs(B[ib0]));
        if ((smin < 1.0) && (lr21 > 1.0) &&
            (lr21 > 2.2471164185778949E+307 * smin)) {
          scale = 1.0 / lr21;
        }
        temp = scale / smin;
        X[0] = temp * cr22;
        X[1] = temp * B[ib0];
        *xnorm = temp * lr21;
      } else {
        ur12_tmp = icmax << 2;
        ur12 = cr[ipivot[ur12_tmp + 2] - 1];
        ur11r = 1.0 / cr[icmax];
        lr21 = ur11r * cr[ipivot[ur12_tmp + 1] - 1];
        cr22 = cr[ipivot[ur12_tmp + 3] - 1] - ur12 * lr21;
        if (muDoubleScalarAbs(cr22) < smin) {
          cr22 = smin;
        }
        if ((icmax + 1 == 2) || (icmax + 1 == 4)) {
          br1 = B[ib0];
          br2 = B[ib0 - 1];
        } else {
          br1 = B[ib0 - 1];
          br2 = B[ib0];
        }
        br2 -= lr21 * br1;
        lr21 = muDoubleScalarMax(muDoubleScalarAbs(br1 * (cr22 * ur11r)),
                                 muDoubleScalarAbs(br2));
        if (lr21 > 1.0) {
          cr21 = muDoubleScalarAbs(cr22);
          if ((cr21 < 1.0) && (lr21 >= 2.2471164185778949E+307 * cr21)) {
            scale = 1.0 / lr21;
          }
        }
        cr22 = br2 * scale / cr22;
        temp = scale * br1 * ur11r - cr22 * (ur11r * ur12);
        if ((icmax + 1 == 3) || (icmax + 1 == 4)) {
          X[0] = cr22;
          X[1] = temp;
        } else {
          X[0] = temp;
          X[1] = cr22;
        }
        *xnorm =
            muDoubleScalarMax(muDoubleScalarAbs(temp), muDoubleScalarAbs(cr22));
        if ((*xnorm > 1.0) && (cmax > 1.0) &&
            (*xnorm > 2.2471164185778949E+307 / cmax)) {
          temp = cmax / 2.2471164185778949E+307;
          X[0] *= temp;
          X[1] *= temp;
          *xnorm *= temp;
          scale *= temp;
        }
      }
    } else {
      ci[0] = -wi;
      ci[1] = 0.0;
      ci[2] = 0.0;
      ci[3] = -wi;
      cmax = 0.0;
      icmax = -1;
      cr21 = muDoubleScalarAbs(-wi);
      temp = muDoubleScalarAbs(cr[0]) + cr21;
      if (temp > 0.0) {
        cmax = temp;
        icmax = 0;
      }
      temp = muDoubleScalarAbs(cr[1]);
      if (temp > cmax) {
        cmax = temp;
        icmax = 1;
      }
      temp = muDoubleScalarAbs(cr[2]);
      if (temp > cmax) {
        cmax = temp;
        icmax = 2;
      }
      temp = muDoubleScalarAbs(cr[3]) + cr21;
      if (temp > cmax) {
        cmax = temp;
        icmax = 3;
      }
      if (cmax < smin) {
        cr22 = B[ib0 - 1];
        ur12 = B[ib0 + 2];
        cr21 = B[ib0 + 3];
        lr21 = muDoubleScalarMax(
            muDoubleScalarAbs(cr22) + muDoubleScalarAbs(ur12),
            muDoubleScalarAbs(B[ib0]) + muDoubleScalarAbs(cr21));
        if ((smin < 1.0) && (lr21 > 1.0) &&
            (lr21 > 2.2471164185778949E+307 * smin)) {
          scale = 1.0 / lr21;
        }
        temp = scale / smin;
        X[0] = temp * cr22;
        X[1] = temp * B[ib0];
        X[2] = temp * ur12;
        X[3] = temp * cr21;
        *xnorm = temp * lr21;
      } else {
        cr21_tmp = icmax << 2;
        b_cr21_tmp = ipivot[cr21_tmp + 1] - 1;
        cr21 = cr[b_cr21_tmp];
        ur12_tmp = ipivot[cr21_tmp + 2] - 1;
        ur12 = cr[ur12_tmp];
        ui12 = ci[ur12_tmp];
        cr21_tmp = ipivot[cr21_tmp + 3] - 1;
        cr22 = cr[cr21_tmp];
        if ((icmax + 1 == 1) || (icmax + 1 == 4)) {
          if (muDoubleScalarAbs(cr[icmax]) > muDoubleScalarAbs(ci[icmax])) {
            temp = ci[icmax] / cr[icmax];
            ur11r = 1.0 / (cr[icmax] * (temp * temp + 1.0));
            ui11r = -temp * ur11r;
          } else {
            temp = cr[icmax] / ci[icmax];
            ui11r = -1.0 / (ci[icmax] * (temp * temp + 1.0));
            ur11r = -temp * ui11r;
          }
          lr21 = cr21 * ur11r;
          cr21 *= ui11r;
          ur12s = ur12 * ur11r;
          ui12s = ur12 * ui11r;
          cr22 -= ur12 * lr21;
          temp = ci[cr21_tmp] - ur12 * cr21;
        } else {
          ur11r = 1.0 / cr[icmax];
          ui11r = 0.0;
          lr21 = cr21 * ur11r;
          cr21 = ci[b_cr21_tmp] * ur11r;
          ur12s = ur12 * ur11r;
          ui12s = ui12 * ur11r;
          cr22 = (cr22 - ur12 * lr21) + ui12 * cr21;
          temp = -ur12 * cr21 - ui12 * lr21;
        }
        ur12 = muDoubleScalarAbs(cr22) + muDoubleScalarAbs(temp);
        if (ur12 < smin) {
          cr22 = smin;
          temp = 0.0;
        }
        if ((icmax + 1 == 2) || (icmax + 1 == 4)) {
          br2 = B[ib0 - 1];
          br1 = B[ib0];
          bi2 = B[ib0 + 2];
          bi1 = B[ib0 + 3];
        } else {
          br1 = B[ib0 - 1];
          br2 = B[ib0];
          bi1 = B[ib0 + 2];
          bi2 = B[ib0 + 3];
        }
        br2 = (br2 - lr21 * br1) + cr21 * bi1;
        bi2 = (bi2 - cr21 * br1) - lr21 * bi1;
        lr21 = muDoubleScalarMax(
            (muDoubleScalarAbs(br1) + muDoubleScalarAbs(bi1)) *
                (ur12 * (muDoubleScalarAbs(ur11r) + muDoubleScalarAbs(ui11r))),
            muDoubleScalarAbs(br2) + muDoubleScalarAbs(bi2));
        if ((lr21 > 1.0) && (ur12 < 1.0) &&
            (lr21 >= 2.2471164185778949E+307 * ur12)) {
          scale = 1.0 / lr21;
          br1 *= scale;
          bi1 *= scale;
          br2 *= scale;
          bi2 *= scale;
        }
        cr22 = xdladiv(br2, bi2, cr22, temp, &ui12);
        temp = ((ur11r * br1 - ui11r * bi1) - ur12s * cr22) + ui12s * ui12;
        cr21 = ((ui11r * br1 + ur11r * bi1) - ui12s * cr22) - ur12s * ui12;
        if ((icmax + 1 == 3) || (icmax + 1 == 4)) {
          X[0] = cr22;
          X[1] = temp;
          X[2] = ui12;
          X[3] = cr21;
        } else {
          X[0] = temp;
          X[1] = cr22;
          X[2] = cr21;
          X[3] = ui12;
        }
        *xnorm = muDoubleScalarMax(
            muDoubleScalarAbs(temp) + muDoubleScalarAbs(cr21),
            muDoubleScalarAbs(cr22) + muDoubleScalarAbs(ui12));
        if ((*xnorm > 1.0) && (cmax > 1.0) &&
            (*xnorm > 2.2471164185778949E+307 / cmax)) {
          temp = cmax / 2.2471164185778949E+307;
          X[0] *= temp;
          X[1] *= temp;
          X[2] *= temp;
          X[3] *= temp;
          *xnorm *= temp;
          scale *= temp;
        }
      }
    }
  }
  return scale;
}
