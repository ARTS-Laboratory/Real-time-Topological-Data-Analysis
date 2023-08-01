#include "_coder_fitzgibbon_float_mex_api.h"
#include "customFetchLoggedData.h"
#include "fitzgibbon.h"
#include "fitzgibbon_float_mex_data.h"
#include "fitzgibbon_float_mex_emxutil.h"
#include "fitzgibbon_float_mex_mexutil.h"
#include "fitzgibbon_float_mex_types.h"
#include "forcePushIntoCloud.h"
#include "logStmts.h"
#include "rt_nonfinite.h"

static emlrtRTEInfo o_emlrtRTEI = {1, 1, "_coder_fitzgibbon_float_mex_api", ""};

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const creal_T u_data[],
                                          const int32_T u_size[2]);

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp,
                                          const emxArray_struct0_T *u);

static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp,
                                          const struct1_T u_data[],
                                          const int32_T u_size[2]);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                               const char_T *identifier, emxArray_real_T *y);

static const mxArray *e_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[97]);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const creal_T u_data[],
                                          const int32_T u_size[2])
{
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  y = NULL;
  iv[0] = u_size[0];
  iv[1] = u_size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b((emlrtConstCTX)sp, m, (const void *)&u_data[0],
                                8);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp,
                                          const emxArray_struct0_T *u)
{
  static const char_T *sv[7] = {"Class",  "Dims", "Varsize", "NumericType",
                                "Fimath", "Data", "DataSize"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *m;
  const mxArray *y;
  const struct0_T *u_data;
  real_T *pData;
  int32_T iv[2];
  int32_T b_i;
  int32_T b_j1;
  int32_T c_i;
  int32_T i;
  uint8_T *b_pData;
  u_data = u->data;
  y = NULL;
  iv[0] = 1;
  iv[1] = u->size[1];
  emlrtAssign(&y,
              emlrtCreateStructArray(2, &iv[0], 7, (const char_T **)&sv[0]));
  emlrtCreateField(y, "Class");
  emlrtCreateField(y, "Dims");
  emlrtCreateField(y, "Varsize");
  emlrtCreateField(y, "NumericType");
  emlrtCreateField(y, "Fimath");
  emlrtCreateField(y, "Data");
  emlrtCreateField(y, "DataSize");
  i = 0;
  for (b_j1 = 0; b_j1 < u->size[1U]; b_j1++) {
    b_y = NULL;
    iv[0] = 1;
    iv[1] = u_data[b_j1].Class.size[1];
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, u_data[b_j1].Class.size[1], m,
                             &u_data[b_j1].Class.data[0]);
    emlrtAssign(&b_y, m);
    emlrtSetFieldR2017b(y, i, "Class", b_y, 0);
    c_y = NULL;
    iv[0] = 1;
    iv[1] = 2;
    m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    pData[0] = u_data[b_j1].Dims.data[0];
    pData[1] = u_data[b_j1].Dims.data[1];
    emlrtAssign(&c_y, m);
    emlrtSetFieldR2017b(y, i, "Dims", c_y, 1);
    d_y = NULL;
    m = emlrtCreateLogicalScalar(u_data[b_j1].Varsize);
    emlrtAssign(&d_y, m);
    emlrtSetFieldR2017b(y, i, "Varsize", d_y, 2);
    e_y = NULL;
    iv[0] = 1;
    iv[1] = 0;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 0, m, NULL);
    emlrtAssign(&e_y, m);
    emlrtSetFieldR2017b(y, i, "NumericType", e_y, 3);
    f_y = NULL;
    iv[0] = 1;
    iv[1] = 0;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 0, m, NULL);
    emlrtAssign(&f_y, m);
    emlrtSetFieldR2017b(y, i, "Fimath", f_y, 4);
    g_y = NULL;
    iv[0] = 1;
    iv[1] = u_data[b_j1].Data->size[1];
    m = emlrtCreateNumericArray(2, &iv[0], mxUINT8_CLASS, mxREAL);
    b_pData = (uint8_T *)emlrtMxGetData(m);
    b_i = 0;
    for (c_i = 0; c_i < u_data[b_j1].Data->size[1]; c_i++) {
      b_pData[b_i] = u_data[b_j1].Data->data[c_i];
      b_i++;
    }
    emlrtAssign(&g_y, m);
    emlrtSetFieldR2017b(y, i, "Data", g_y, 5);
    h_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)emlrtMxGetData(m) = u_data[b_j1].DataSize;
    emlrtAssign(&h_y, m);
    emlrtSetFieldR2017b(y, i, "DataSize", h_y, 6);
    i++;
  }
  return y;
}

static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp,
                                          const struct1_T u_data[],
                                          const int32_T u_size[2])
{
  static const char_T *sv[2] = {"ActualIndex", "FieldNames"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  int32_T b_j1;
  int32_T i;
  y = NULL;
  iv[0] = 1;
  iv[1] = u_size[1];
  emlrtAssign(&y,
              emlrtCreateStructArray(2, &iv[0], 2, (const char_T **)&sv[0]));
  emlrtCreateField(y, "ActualIndex");
  emlrtCreateField(y, "FieldNames");
  i = 0;
  if (u_size[1U] > 0) {
    iv[0] = 1;
  }
  for (b_j1 = 0; b_j1 < u_size[1U]; b_j1++) {
    b_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)emlrtMxGetData(m) = u_data[b_j1].ActualIndex;
    emlrtAssign(&b_y, m);
    emlrtSetFieldR2017b(y, i, "ActualIndex", b_y, 0);
    c_y = NULL;
    iv[1] = u_data[b_j1].FieldNames.size[1];
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, u_data[b_j1].FieldNames.size[1],
                             m, &u_data[b_j1].FieldNames.data[0]);
    emlrtAssign(&c_y, m);
    emlrtSetFieldR2017b(y, i, "FieldNames", c_y, 1);
    i++;
  }
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(x), &thisId, y);
  emlrtDestroyArray(&x);
}

static const mxArray *e_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[97])
{
  static const int32_T iv[2] = {1, 97};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 97, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims = -1;
  int32_T i;
  int32_T i1;
  boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret->allocatedSize = i;
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_real_T(sp, ret, i1, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void customFetchLoggedData_api(int32_T nlhs, const mxArray *plhs[4])
{
  emlrtStack st = {NULL, NULL, NULL};
  emxArray_struct0_T *data;
  emxArray_struct1_T_1x6 dataInfo;
  real_T numLoggedExpr;
  char_T dataExprIdMapping[97];
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  emxInit_struct0_T(&st, &data, &o_emlrtRTEI, true);
  customFetchLoggedData(&st, data, dataInfo.data, dataInfo.size,
                        dataExprIdMapping, &numLoggedExpr);

  plhs[0] = c_emlrt_marshallOut(&st, data);
  emxFree_struct0_T(&st, &data);
  if (nlhs > 1) {
    plhs[1] = d_emlrt_marshallOut(&st, dataInfo.data, dataInfo.size);
  }
  if (nlhs > 2) {
    plhs[2] = e_emlrt_marshallOut(&st, dataExprIdMapping);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(numLoggedExpr);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void fitzgibbon_api(const mxArray *const prhs[2], const mxArray **plhs)
{
  emlrtStack st = {NULL, NULL, NULL};
  emxArray_real_T *x;
  emxArray_real_T *y;
  creal_T a_data[18];
  int32_T a_size[2];
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  emxInit_real_T(&st, &x, 1, &o_emlrtRTEI);
  x->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "x", x);
  emxInit_real_T(&st, &y, 1, &o_emlrtRTEI);
  y->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "y", y);

  fitzgibbon(&st, x, y, a_data, a_size);
  emxFree_real_T(&st, &y);
  emxFree_real_T(&st, &x);

  *plhs = b_emlrt_marshallOut(&st, a_data, a_size);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void forcePushIntoCloud_api(void)
{
  emlrtStack st = {NULL, NULL, NULL};
  st.tls = emlrtRootTLSGlobal;

  forcePushIntoCloud(&st);
}

void logStmts_api(void)
{
  emlrtStack st = {NULL, NULL, NULL};
  st.tls = emlrtRootTLSGlobal;

  logStmts(&st);
}
