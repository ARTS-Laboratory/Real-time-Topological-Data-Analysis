#include "eml_int_forloop_overflow_check.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"

static emlrtRTEInfo h_emlrtRTEI = {
    87, 33, "check_forloop_overflow_error",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m"};

void check_forloop_overflow_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2018a(
      sp, &h_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
      "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
}
