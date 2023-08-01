#include "xdladiv.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

real_T xdladiv(real_T a, real_T b, real_T c, real_T d, real_T *q)
{
  real_T aa;
  real_T ab;
  real_T bb;
  real_T cc;
  real_T cd;
  real_T cd_tmp;
  real_T dd;
  real_T p;
  real_T r;
  real_T s;
  aa = a;
  bb = b;
  cc = c;
  dd = d;
  ab = muDoubleScalarMax(muDoubleScalarAbs(a), muDoubleScalarAbs(b));
  cd_tmp = muDoubleScalarAbs(d);
  r = muDoubleScalarAbs(c);
  cd = muDoubleScalarMax(r, cd_tmp);
  s = 1.0;
  if (ab >= 8.9884656743115785E+307) {
    aa = 0.5 * a;
    bb = 0.5 * b;
    s = 2.0;
  }
  if (cd >= 8.9884656743115785E+307) {
    cc = 0.5 * c;
    dd = 0.5 * d;
    s *= 0.5;
  }
  if (ab <= 2.0041683600089728E-292) {
    aa *= 4.0564819207303341E+31;
    bb *= 4.0564819207303341E+31;
    s /= 4.0564819207303341E+31;
  }
  if (cd <= 2.0041683600089728E-292) {
    cc *= 4.0564819207303341E+31;
    dd *= 4.0564819207303341E+31;
    s *= 4.0564819207303341E+31;
  }
  if (cd_tmp <= r) {
    r = dd / cc;
    cd = 1.0 / (cc + dd * r);
    if (r != 0.0) {
      ab = bb * r;
      cd_tmp = bb * cd;
      if (ab != 0.0) {
        p = (aa + ab) * cd;
      } else {
        p = aa * cd + cd_tmp * r;
      }
      ab = -aa * r;
      if (ab != 0.0) {
        *q = (bb + ab) * cd;
      } else {
        *q = cd_tmp + -aa * cd * r;
      }
    } else {
      p = (aa + dd * (bb / cc)) * cd;
      *q = (bb + dd * (-aa / cc)) * cd;
    }
  } else {
    r = cc / dd;
    cd = 1.0 / (dd + cc * r);
    if (r != 0.0) {
      ab = aa * r;
      cd_tmp = aa * cd;
      if (ab != 0.0) {
        p = (bb + ab) * cd;
      } else {
        p = bb * cd + cd_tmp * r;
      }
      ab = -bb * r;
      if (ab != 0.0) {
        *q = (aa + ab) * cd;
      } else {
        *q = cd_tmp + -bb * cd * r;
      }
    } else {
      p = (bb + cc * (aa / dd)) * cd;
      *q = (aa + cc * (-bb / dd)) * cd;
    }
    *q = -*q;
  }
  p *= s;
  *q *= s;
  return p;
}
