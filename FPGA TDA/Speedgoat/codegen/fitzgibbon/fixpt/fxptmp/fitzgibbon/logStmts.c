#include "logStmts.h"
#include "custom_mex_logger.h"
#include "fitzgibbon_float_mex_data.h"
#include "fitzgibbon_float_mex_types.h"
#include "rt_nonfinite.h"

static emlrtRSInfo rg_emlrtRSI = {1, "logStmts",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\coder\\float"
                                  "2fixed\\custom_logger\\logStmts.p"};

static uint32_T b_varyingSize(creal_T t_data[], int32_T t_size[2]);

static uint32_T varyingSize(real_T t_data[], int32_T *t_size);

static uint32_T b_varyingSize(creal_T t_data[], int32_T t_size[2])
{
  t_size[0] = 1;
  t_size[1] = 1;
  t_data[0].re = 0.0;
  t_data[0].im = 0.0;
  return 0U;
}

static uint32_T varyingSize(real_T t_data[], int32_T *t_size)
{
  *t_size = 1;
  t_data[0] = 0.0;
  return 0U;
}

void logStmts(const emlrtStack *sp)
{
  emlrtStack st;
  emxArray_real_T b_t_data;
  creal_T c_t_data;
  real_T t_data;
  int32_T b_t_size[2];
  int32_T t_size;
  st.prev = sp;
  st.tls = sp->tls;
  varyingSize((real_T *)&t_data, &t_size);
  b_t_data.data = &t_data;
  b_t_data.size = &t_size;
  b_t_data.allocatedSize = 1;
  b_t_data.numDimensions = 1;
  b_t_data.canFreeData = false;
  st.site = &rg_emlrtRSI;
  custom_mex_logger(&st, 0U, &b_t_data);
  b_varyingSize((creal_T *)&c_t_data, b_t_size);
  st.site = &rg_emlrtRSI;
  b_custom_mex_logger(&st, 0U, (creal_T *)&c_t_data, b_t_size);
}
