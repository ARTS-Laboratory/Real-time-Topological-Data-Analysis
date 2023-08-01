#include "fitzgibbon_float_mex_mexutil.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"

int32_T div_nde_s32_floor(int32_T numerator)
{
  int32_T i;
  if ((numerator < 0) && (numerator % 3 != 0)) {
    i = -1;
  } else {
    i = 0;
  }
  return numerator / 3 + i;
}

void emlrtInitVarDataTables(emlrtLocationLoggingDataType dataTables[26])
{
  int32_T i;
  for (i = 0; i < 26; i++) {
    dataTables[i].SimMin = rtInf;
    dataTables[i].SimMax = rtMinusInf;
    dataTables[i].OverflowWraps = 0;
    dataTables[i].Saturations = 0;
    dataTables[i].IsAlwaysInteger = true;
    dataTables[i].HistogramTable = (emlrtLocationLoggingHistogramType *)NULL;
  }
}

const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}
