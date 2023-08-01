#include "xdlanv2.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

real_T xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T *rt1i,
               real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn)
{
  real_T bcmax;
  real_T bcmis;
  real_T p;
  real_T rt1r;
  real_T scale;
  real_T tau;
  real_T temp;
  real_T z;
  int32_T count;
  int32_T i;
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    *cs = 0.0;
    *sn = 1.0;
    temp = *d;
    *d = *a;
    *a = temp;
    *b = -*c;
    *c = 0.0;
  } else {
    temp = *a - *d;
    if ((temp == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
      *cs = 1.0;
      *sn = 0.0;
    } else {
      p = 0.5 * temp;
      bcmis = muDoubleScalarAbs(*b);
      scale = muDoubleScalarAbs(*c);
      bcmax = muDoubleScalarMax(bcmis, scale);
      if (!(*b < 0.0)) {
        count = 1;
      } else {
        count = -1;
      }
      if (!(*c < 0.0)) {
        i = 1;
      } else {
        i = -1;
      }
      bcmis = muDoubleScalarMin(bcmis, scale) * (real_T)count * (real_T)i;
      scale = muDoubleScalarMax(muDoubleScalarAbs(p), bcmax);
      z = p / scale * p + bcmax / scale * bcmis;
      if (z >= 8.8817841970012523E-16) {
        *a = muDoubleScalarSqrt(scale) * muDoubleScalarSqrt(z);
        if (p < 0.0) {
          *a = -*a;
        }
        z = p + *a;
        *a = *d + z;
        *d -= bcmax / z * bcmis;
        tau = muDoubleScalarHypot(*c, z);
        *cs = z / tau;
        *sn = *c / tau;
        *b -= *c;
        *c = 0.0;
      } else {
        bcmis = *b + *c;
        scale = muDoubleScalarMax(muDoubleScalarAbs(temp),
                                  muDoubleScalarAbs(bcmis));
        count = 0;
        while ((scale >= 7.4428285367870146E+137) && (count <= 20)) {
          bcmis *= 1.3435752215134178E-138;
          temp *= 1.3435752215134178E-138;
          scale = muDoubleScalarMax(muDoubleScalarAbs(temp),
                                    muDoubleScalarAbs(bcmis));
          count++;
        }
        while ((scale <= 1.3435752215134178E-138) && (count <= 20)) {
          bcmis *= 7.4428285367870146E+137;
          temp *= 7.4428285367870146E+137;
          scale = muDoubleScalarMax(muDoubleScalarAbs(temp),
                                    muDoubleScalarAbs(bcmis));
          count++;
        }
        tau = muDoubleScalarHypot(bcmis, temp);
        *cs = muDoubleScalarSqrt(0.5 * (muDoubleScalarAbs(bcmis) / tau + 1.0));
        if (!(bcmis < 0.0)) {
          count = 1;
        } else {
          count = -1;
        }
        *sn = -(0.5 * temp / (tau * *cs)) * (real_T)count;
        bcmax = *a * *cs + *b * *sn;
        scale = -*a * *sn + *b * *cs;
        z = *c * *cs + *d * *sn;
        bcmis = -*c * *sn + *d * *cs;
        *b = scale * *cs + bcmis * *sn;
        *c = -bcmax * *sn + z * *cs;
        temp = 0.5 * ((bcmax * *cs + z * *sn) + (-scale * *sn + bcmis * *cs));
        *a = temp;
        *d = temp;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              bcmis = muDoubleScalarSqrt(muDoubleScalarAbs(*b));
              scale = muDoubleScalarSqrt(muDoubleScalarAbs(*c));
              *a = bcmis * scale;
              if (!(*c < 0.0)) {
                p = *a;
              } else {
                p = -*a;
              }
              tau = 1.0 / muDoubleScalarSqrt(muDoubleScalarAbs(*b + *c));
              *a = temp + p;
              *d = temp - p;
              *b -= *c;
              *c = 0.0;
              bcmax = bcmis * tau;
              bcmis = scale * tau;
              temp = *cs * bcmax - *sn * bcmis;
              *sn = *cs * bcmis + *sn * bcmax;
              *cs = temp;
            }
          } else {
            *b = -*c;
            *c = 0.0;
            temp = *cs;
            *cs = -*sn;
            *sn = temp;
          }
        }
      }
    }
  }
  rt1r = *a;
  *rt2r = *d;
  if (*c == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    *rt1i = muDoubleScalarSqrt(muDoubleScalarAbs(*b)) *
            muDoubleScalarSqrt(muDoubleScalarAbs(*c));
    *rt2i = -*rt1i;
  }
  return rt1r;
}
