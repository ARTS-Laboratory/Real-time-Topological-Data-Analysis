#include "forcePushIntoCloud.h"
#include "fitzgibbon_float_mex_data.h"
#include "fitzgibbon_float_mex_mexutil.h"
#include "rt_nonfinite.h"

void forcePushIntoCloud(const emlrtStack *sp)
{
  (void)sp;
  emlrtInitVarDataTables(emlrtLocationLoggingDataTables);
}
