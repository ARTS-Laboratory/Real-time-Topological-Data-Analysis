#include "repmat.h"
#include "fitzgibbon_float_mex_data.h"
#include "fitzgibbon_float_mex_types.h"
#include "rt_nonfinite.h"

void repmat(const emlrtStack *sp, const struct1_T a, uint32_T varargin_2,
            struct1_T b_data[], int32_T b_size[2])
{
  emlrtStack st;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yg_emlrtRSI;
  if (varargin_2 > 2147483647U) {
    emlrtErrorWithMessageIdR2018a(
        &st, &f_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  b_size[0] = 1;
  b_size[1] = (int32_T)varargin_2;
  loop_ub = (int32_T)varargin_2;
  for (i = 0; i < loop_ub; i++) {
    b_data[i] = a;
  }
}
