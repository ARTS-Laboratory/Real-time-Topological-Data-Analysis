#include "_coder_fitzgibbon_float_mex_mex.h"
#include "_coder_fitzgibbon_float_mex_api.h"
#include "fitzgibbon_float_mex_data.h"
#include "fitzgibbon_float_mex_initialize.h"
#include "fitzgibbon_float_mex_terminate.h"
#include "rt_nonfinite.h"

void customFetchLoggedData_mexFunction(int32_T nlhs, mxArray *plhs[4],
                                       int32_T nrhs)
{
  emlrtStack st = {NULL, NULL, NULL};
  const mxArray *outputs[4];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        21, "customFetchLoggedData");
  }
  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 21,
                        "customFetchLoggedData");
  }

  customFetchLoggedData_api(nlhs, outputs);

  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void fitzgibbon_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                            const mxArray *prhs[2])
{
  emlrtStack st = {NULL, NULL, NULL};
  const mxArray *b_prhs[2];
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        10, "fitzgibbon");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "fitzgibbon");
  }

  b_prhs[0] = prhs[0];
  b_prhs[1] = prhs[1];
  fitzgibbon_api(b_prhs, &outputs);

  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void forcePushIntoCloud_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = {NULL, NULL, NULL};
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        18, "forcePushIntoCloud");
  }
  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "forcePushIntoCloud");
  }

  forcePushIntoCloud_api();
}

void logStmts_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = {NULL, NULL, NULL};
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        8, "logStmts");
  }
  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 8,
                        "logStmts");
  }

  logStmts_api();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  static const char_T *emlrtEntryPoints[4] = {
      "fitzgibbon", "logStmts", "customFetchLoggedData", "forcePushIntoCloud"};
  emlrtStack st = {NULL, NULL, NULL};
  mexAtExit(&fitzgibbon_float_mex_atexit);

  fitzgibbon_float_mex_initialize();
  st.tls = emlrtRootTLSGlobal;

  switch (emlrtGetEntryPointIndexR2016a(
      &st, nrhs, &prhs[0], (const char_T **)&emlrtEntryPoints[0], 4)) {
  case 0:
    fitzgibbon_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;
  case 1:
    logStmts_mexFunction(nlhs, nrhs - 1);
    break;
  case 2:
    customFetchLoggedData_mexFunction(nlhs, plhs, nrhs - 1);
    break;
  case 3:
    forcePushIntoCloud_mexFunction(nlhs, nrhs - 1);
    break;
  }

  fitzgibbon_float_mex_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1252", true);
  return emlrtRootTLSGlobal;
}
