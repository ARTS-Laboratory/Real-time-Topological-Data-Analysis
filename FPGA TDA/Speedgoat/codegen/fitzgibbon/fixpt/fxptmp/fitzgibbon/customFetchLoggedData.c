#include "customFetchLoggedData.h"
#include "custom_mex_logger.h"
#include "fitzgibbon_float_mex_data.h"
#include "fitzgibbon_float_mex_types.h"
#include "rt_nonfinite.h"
#include <string.h>

static emlrtRSInfo ch_emlrtRSI = {
    1, "customFetchLoggedData",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\coder\\float2fixed\\custom_"
    "logger\\customFetchLoggedData.p"};

void customFetchLoggedData(const emlrtStack *sp, emxArray_struct0_T *data,
                           struct1_T dataInfo_data[], int32_T dataInfo_size[2],
                           char_T dataExprIdMapping[97], real_T *numLoggedExpr)
{
  static const char_T cv[97] = {
      'f', 'i', 't', 'z', 'g', 'i',  'b',  'b', 'o', 'n', ',', 'C', ':',  '\\',
      'U', 's', 'e', 'r', 's', '\\', 'd',  'w', 'a', 'm', 'a', 'i', '\\', 'D',
      'e', 's', 'k', 't', 'o', 'p',  '\\', 'l', 'i', 'n', 'r', 'e', 'g',  'e',
      'l', 'l', 'i', 'p', 's', 'e',  '\\', 'f', 'i', 't', 'z', 'g', 'i',  'b',
      'b', 'o', 'n', '.', 'm', '$',  '$',  'i', 'n', 'p', 'u', 't', 's',  '$',
      '$', '<', '>', 'x', ',', '2',  '<',  '>', 'y', ',', '3', '$', '$',  'o',
      'u', 't', 'p', 'u', 't', 's',  '$',  '$', '<', '>', 'a', ',', '4'};
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  memcpy(&dataExprIdMapping[0], &cv[0], 97U * sizeof(char_T));
  st.site = &ch_emlrtRSI;
  c_custom_mex_logger(&st, data, dataInfo_data, dataInfo_size);
  *numLoggedExpr = (real_T)dataInfo_size[1] - 1.0;
}
