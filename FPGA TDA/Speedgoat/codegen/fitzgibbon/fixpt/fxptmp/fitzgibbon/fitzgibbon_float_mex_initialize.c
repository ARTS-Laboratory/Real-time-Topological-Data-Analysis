#include "fitzgibbon_float_mex_initialize.h"
#include "_coder_fitzgibbon_float_mex_mex.h"
#include "custom_mex_logger.h"
#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"

static void fitzgibbon_float_mex_once(const emlrtStack *sp);

static void fitzgibbon_float_mex_once(const emlrtStack *sp)
{
  emlrtStack st;
  mex_InitInfAndNan();
  st.prev = sp;
  st.tls = sp->tls;
  pInit_not_empty_init();

  covrtAllocateInstanceData(&emlrtCoverageInstance);

  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\dwamai\\Desktop\\linregellipse\\fitzgibbon.m", 0U,
                  1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "fitzgibbon", 0, -1, 449);

  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 30, -1, 444);

  covrtScriptStart(&emlrtCoverageInstance, 0U);
  indexMapper_init();
  st.site = NULL;
  buffers_init(&st);
  st.site = NULL;
  customCoderEnableLog_init(&st);
}

void fitzgibbon_float_mex_initialize(void)
{
  emlrtStack st = {NULL, NULL, NULL};
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    fitzgibbon_float_mex_once(&st);
  }
}
