#include "custom_mex_logger.h"
#include "fitzgibbon_float_mex_data.h"
#include "fitzgibbon_float_mex_emxutil.h"
#include "fitzgibbon_float_mex_types.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include <string.h>

#ifndef typedef_emxArray_struct1_T_1x3
#define typedef_emxArray_struct1_T_1x3
typedef struct {
  struct1_T data[3];
  int32_T size[2];
} emxArray_struct1_T_1x3;
#endif

static emxArray_struct1_T_1x6 pIndexMap;

static boolean_T pIndexMap_not_empty;

static uint32_T pBufferLen;

static emxArray_struct0_T *pBuffers;

static boolean_T pBuffers_not_empty;

static boolean_T pInit_not_empty;

static emxArray_boolean_T *pEnabled;

static emlrtRSInfo sg_emlrtRSI = {1, "generic_logger_complex",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\coder\\float"
                                  "2fixed\\custom_logger\\custom_mex_logger.p"};

static emlrtRSInfo tg_emlrtRSI = {1, "generic_logger_complex_impl",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\coder\\float"
                                  "2fixed\\custom_logger\\custom_mex_logger.p"};

static emlrtRSInfo ug_emlrtRSI = {13, "nullAssignment",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\nullAssignment.m"};

static emlrtRSInfo vg_emlrtRSI = {17, "nullAssignment",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                  "coder\\+internal\\nullAssignment.m"};

static emlrtRSInfo xg_emlrtRSI = {1, "indexMapper",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\coder\\float"
                                  "2fixed\\custom_logger\\custom_mex_logger.p"};

static emlrtRSInfo ah_emlrtRSI = {1, "buffers",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\coder\\float"
                                  "2fixed\\custom_logger\\custom_mex_logger.p"};

static emlrtRSInfo bh_emlrtRSI = {1, "custom_mex_logger",
                                  "C:\\Program "
                                  "Files\\MATLAB\\R2023a\\toolbox\\coder\\float"
                                  "2fixed\\custom_logger\\custom_mex_logger.p"};

static emlrtMCInfo d_emlrtMCI = {1, 1, "generic_logger_complex",
                                 "C:\\Program "
                                 "Files\\MATLAB\\R2023a\\toolbox\\coder\\float2"
                                 "fixed\\custom_logger\\custom_mex_logger.p"};

static emlrtMCInfo e_emlrtMCI = {1, 1, "generic_logger_complex_impl",
                                 "C:\\Program "
                                 "Files\\MATLAB\\R2023a\\toolbox\\coder\\float2"
                                 "fixed\\custom_logger\\custom_mex_logger.p"};

static emlrtBCInfo emlrtBCI = {-1,
                               -1,
                               1,
                               1,
                               "",
                               "indexMapper",
                               "C:\\Program "
                               "Files\\MATLAB\\R2023a\\toolbox\\coder\\float2fi"
                               "xed\\custom_logger\\custom_mex_logger.p",
                               0};

static emlrtRTEInfo e_emlrtRTEI = {85, 27, "validate_inputs",
                                   "C:\\Program "
                                   "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                   "coder\\+internal\\nullAssignment.m"};

static emlrtBCInfo b_emlrtBCI = {-1,
                                 -1,
                                 1,
                                 1,
                                 "",
                                 "generic_logger_complex",
                                 "C:\\Program "
                                 "Files\\MATLAB\\R2023a\\toolbox\\coder\\float2"
                                 "fixed\\custom_logger\\custom_mex_logger.p",
                                 0};

static emlrtBCInfo c_emlrtBCI = {-1,
                                 -1,
                                 1,
                                 1,
                                 "",
                                 "buffers",
                                 "C:\\Program "
                                 "Files\\MATLAB\\R2023a\\toolbox\\coder\\float2"
                                 "fixed\\custom_logger\\custom_mex_logger.p",
                                 0};

static emlrtRTEInfo g_emlrtRTEI = {
    53, 9, "typecast",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datatypes\\typecast.m"};

static emlrtECInfo b_emlrtECI = {-1, 1, 1, "buffers",
                                 "C:\\Program "
                                 "Files\\MATLAB\\R2023a\\toolbox\\coder\\float2"
                                 "fixed\\custom_logger\\custom_mex_logger.p"};

static emlrtDCInfo emlrtDCI = {1, 1, "buffers",
                               "C:\\Program "
                               "Files\\MATLAB\\R2023a\\toolbox\\coder\\float2fi"
                               "xed\\custom_logger\\custom_mex_logger.p",
                               1};

static emlrtRTEInfo i_emlrtRTEI = {
    1, 1, "custom_mex_logger",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\coder\\float2fixed\\custom_logger\\custom_"
    "mex_logger.p"};

static emlrtRTEInfo m_emlrtRTEI = {17, 9, "nullAssignment",
                                   "C:\\Program "
                                   "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                                   "coder\\+internal\\nullAssignment.m"};

static emlrtRTEInfo n_emlrtRTEI = {
    68, 24, "typecast",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datatypes\\typecast.m"};

static void b_buffers(const emlrtStack *sp, uint32_T idx,
                      const emxArray_uint8_T *arg);

static boolean_T buffers(const emlrtStack *sp, uint32_T idx);

static void c_buffers(const emlrtStack *sp, uint32_T idx,
                      const char_T arg_Class_data[],
                      const int32_T arg_Class_size[2],
                      const real_T arg_Dims_data[],
                      const emxArray_uint8_T *arg_Data);

static void c_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_horzcat_,
                               const char_T *identifier, emxArray_boolean_T *y);

static boolean_T customCoderEnableLog(const emlrtStack *sp, uint32_T buffId);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_boolean_T *y);

static const mxArray *f2fCustomCoderEnableLogState(const emlrtStack *sp,
                                                   emlrtMCInfo *location);

static void generic_logger_impl_val(const emlrtStack *sp, uint32_T idx_in,
                                    const real_T val_in_data[],
                                    const int32_T val_in_size[2]);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_boolean_T *ret);

static const mxArray *horzcat(const emlrtStack *sp, const mxArray *m1,
                              const mxArray *m2, emlrtMCInfo *location);

static boolean_T indexMapper(const emlrtStack *sp, uint32_T staticIdx);

static void tobytes(const emlrtStack *sp, const emxArray_real_T *val_in,
                    emxArray_uint8_T *bytes);

static void b_buffers(const emlrtStack *sp, uint32_T idx,
                      const emxArray_uint8_T *arg)
{
  static const char_T valClass[5] = {'u', 'i', 'n', 't', '8'};
  emxArray_uint8_T *r;
  struct0_T S;
  struct0_T *pBuffers_data;
  real_T d;
  int32_T i;
  int32_T loop_ub;
  int32_T unnamed_idx_1;
  uint32_T qY;
  uint32_T x;
  uint32_T y;
  const uint8_T *arg_data;
  uint8_T *r1;
  boolean_T b;
  pBuffers_data = pBuffers->data;
  arg_data = arg->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (!pBuffers_not_empty) {
    emxInitStruct_struct0_T(sp, &S, &i_emlrtRTEI, true);
    S.Class.size[0] = 1;
    S.Class.size[1] = 5;
    for (i = 0; i < 5; i++) {
      S.Class.data[i] = valClass[i];
    }
    S.Dims.size[0] = 1;
    S.Dims.size[1] = 2;
    S.Dims.data[0] = 1.0;
    S.Dims.data[1] = 1.0;
    S.Varsize = false;
    S.NumericType.size[0] = 1;
    S.NumericType.size[1] = 0;
    S.Fimath.size[0] = 1;
    S.Fimath.size[1] = 0;
    i = S.Data->size[0] * S.Data->size[1];
    S.Data->size[0] = 1;
    S.Data->size[1] = 1;
    emxEnsureCapacity_uint8_T(sp, S.Data, i, &i_emlrtRTEI);
    S.Data->data[0] = 0U;
    S.DataSize = 1U;
    i = pBuffers->size[0] * pBuffers->size[1];
    pBuffers->size[0] = 1;
    pBuffers->size[1] = 1;
    emxEnsureCapacity_struct0_T(sp, pBuffers, i, &i_emlrtRTEI);
    pBuffers_data = pBuffers->data;
    emxCopyStruct_struct0_T(sp, &pBuffers_data[0], &S, &i_emlrtRTEI);
    emxFreeStruct_struct0_T(sp, &S);
    pBuffers_not_empty = true;
  }
  i = pBuffers->size[1];
  b = (((int32_T)idx < 1) || ((int32_T)idx > pBuffers->size[1]));
  if (b) {
    emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i, &c_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  i = pBuffers->size[1];
  if (((int32_T)idx < 1) || ((int32_T)idx > pBuffers->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i, &c_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  d = (real_T)pBuffers_data[(int32_T)idx - 1].DataSize + (real_T)arg->size[1];
  if (d < 4.294967296E+9) {
    x = (uint32_T)d;
  } else {
    x = MAX_uint32_T;
  }
  if (x > (uint32_T)pBuffers_data[(int32_T)idx - 1].Data->size[1]) {
    x = (uint32_T)pBuffers_data[(int32_T)idx - 1].Data->size[1] << 1;
    if (d < 4.294967296E+9) {
      y = (uint32_T)d;
    } else {
      y = MAX_uint32_T;
    }
    if (x < y) {
      x = y;
    }
    d = (real_T)x - (real_T)pBuffers_data[(int32_T)idx - 1].Data->size[1];
    if (d >= 0.0) {
      x = (uint32_T)d;
    } else {
      x = 0U;
    }
    if ((real_T)x != (int32_T)x) {
      emlrtIntegerCheckR2012b(x, &emlrtDCI, (emlrtConstCTX)sp);
    }
    unnamed_idx_1 = (int32_T)x;
    emxInit_uint8_T(sp, &r, &i_emlrtRTEI, true);
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    emxEnsureCapacity_uint8_T(sp, r, i, &i_emlrtRTEI);
    i = r->size[0] * r->size[1];
    r->size[1] = pBuffers_data[(int32_T)idx - 1].Data->size[1] + (int32_T)x;
    emxEnsureCapacity_uint8_T(sp, r, i, &i_emlrtRTEI);
    r1 = r->data;
    loop_ub = pBuffers_data[(int32_T)idx - 1].Data->size[1];
    for (i = 0; i < loop_ub; i++) {
      r1[i] = pBuffers_data[(int32_T)idx - 1].Data->data[i];
    }
    for (i = 0; i < unnamed_idx_1; i++) {
      r1[i + pBuffers_data[(int32_T)idx - 1].Data->size[1]] = 0U;
    }
    i = pBuffers_data[(int32_T)idx - 1].Data->size[0] *
        pBuffers_data[(int32_T)idx - 1].Data->size[1];
    pBuffers_data[(int32_T)idx - 1].Data->size[0] = 1;
    emxEnsureCapacity_uint8_T(sp, pBuffers_data[(int32_T)idx - 1].Data, i,
                              &i_emlrtRTEI);
    i = pBuffers_data[(int32_T)idx - 1].Data->size[0] *
        pBuffers_data[(int32_T)idx - 1].Data->size[1];
    pBuffers_data[(int32_T)idx - 1].Data->size[1] = r->size[1];
    emxEnsureCapacity_uint8_T(sp, pBuffers_data[(int32_T)idx - 1].Data, i,
                              &i_emlrtRTEI);
    i = pBuffers->size[1];
    if (((int32_T)idx < 1) || ((int32_T)idx > pBuffers->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i, &c_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = r->size[1];
    for (i = 0; i < loop_ub; i++) {
      pBuffers_data[(int32_T)idx - 1].Data->data[i] = r1[i];
    }
    emxFree_uint8_T(sp, &r);
  }
  x = pBuffers_data[(int32_T)idx - 1].DataSize;
  d = (real_T)x + (real_T)arg->size[1];
  if (d < 4.294967296E+9) {
    y = (uint32_T)d;
  } else {
    y = MAX_uint32_T;
  }
  qY = y - 1U;
  if (y - 1U > y) {
    qY = 0U;
  }
  if (pBuffers_data[(int32_T)idx - 1].DataSize > qY) {
    i = 0;
    unnamed_idx_1 = 0;
  } else {
    i = pBuffers_data[(int32_T)idx - 1].Data->size[1];
    if (((int32_T)x < 1) || ((int32_T)x > i)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)x, 1, i, &c_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i = (int32_T)x - 1;
    unnamed_idx_1 = pBuffers_data[(int32_T)idx - 1].Data->size[1];
    if (((int32_T)qY < 1) || ((int32_T)qY > unnamed_idx_1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)qY, 1, unnamed_idx_1, &c_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    unnamed_idx_1 = (int32_T)qY;
  }
  loop_ub = unnamed_idx_1 - i;
  if (loop_ub != arg->size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(loop_ub, arg->size[1], &b_emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  for (unnamed_idx_1 = 0; unnamed_idx_1 < loop_ub; unnamed_idx_1++) {
    pBuffers_data[(int32_T)idx - 1].Data->data[i + unnamed_idx_1] =
        arg_data[unnamed_idx_1];
  }
  d = (real_T)pBuffers_data[(int32_T)idx - 1].DataSize + (real_T)arg->size[1];
  if (d < 4.294967296E+9) {
    x = (uint32_T)d;
  } else {
    x = MAX_uint32_T;
  }
  pBuffers_data[(int32_T)idx - 1].DataSize = x;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static boolean_T buffers(const emlrtStack *sp, uint32_T idx)
{
  static const char_T valClass[5] = {'u', 'i', 'n', 't', '8'};
  struct0_T S;
  struct0_T *pBuffers_data;
  int32_T i;
  boolean_T out;
  pBuffers_data = pBuffers->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (!pBuffers_not_empty) {
    emxInitStruct_struct0_T(sp, &S, &i_emlrtRTEI, true);
    S.Class.size[0] = 1;
    S.Class.size[1] = 5;
    for (i = 0; i < 5; i++) {
      S.Class.data[i] = valClass[i];
    }
    S.Dims.size[0] = 1;
    S.Dims.size[1] = 2;
    S.Dims.data[0] = 1.0;
    S.Dims.data[1] = 1.0;
    S.Varsize = false;
    S.NumericType.size[0] = 1;
    S.NumericType.size[1] = 0;
    S.Fimath.size[0] = 1;
    S.Fimath.size[1] = 0;
    i = S.Data->size[0] * S.Data->size[1];
    S.Data->size[0] = 1;
    S.Data->size[1] = 1;
    emxEnsureCapacity_uint8_T(sp, S.Data, i, &i_emlrtRTEI);
    S.Data->data[0] = 0U;
    S.DataSize = 1U;
    i = pBuffers->size[0] * pBuffers->size[1];
    pBuffers->size[0] = 1;
    pBuffers->size[1] = 1;
    emxEnsureCapacity_struct0_T(sp, pBuffers, i, &i_emlrtRTEI);
    pBuffers_data = pBuffers->data;
    emxCopyStruct_struct0_T(sp, &pBuffers_data[0], &S, &i_emlrtRTEI);
    emxFreeStruct_struct0_T(sp, &S);
    pBuffers_not_empty = true;
  }
  if (idx <= (uint32_T)pBuffers->size[1]) {
    i = pBuffers->size[1];
    if (((int32_T)idx < 1) || ((int32_T)idx > pBuffers->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i, &b_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (pBuffers_data[(int32_T)idx - 1].DataSize > 1U) {
      out = true;
    } else {
      out = false;
    }
  } else {
    out = false;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return out;
}

static void c_buffers(const emlrtStack *sp, uint32_T idx,
                      const char_T arg_Class_data[],
                      const int32_T arg_Class_size[2],
                      const real_T arg_Dims_data[],
                      const emxArray_uint8_T *arg_Data)
{
  static const char_T valClass[5] = {'u', 'i', 'n', 't', '8'};
  emlrtStack b_st;
  emlrtStack st;
  struct0_T S;
  struct0_T expl_temp;
  struct0_T *pBuffers_data;
  real_T d;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  uint32_T varargin_2;
  const uint8_T *arg_Data_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  pBuffers_data = pBuffers->data;
  arg_Data_data = arg_Data->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInitStruct_struct0_T(sp, &S, &i_emlrtRTEI, true);
  if (!pBuffers_not_empty) {
    S.Class.size[0] = 1;
    S.Class.size[1] = 5;
    for (i = 0; i < 5; i++) {
      S.Class.data[i] = valClass[i];
    }
    S.Dims.size[0] = 1;
    S.Dims.size[1] = 2;
    S.Dims.data[0] = 1.0;
    S.Dims.data[1] = 1.0;
    S.Varsize = false;
    S.NumericType.size[0] = 1;
    S.NumericType.size[1] = 0;
    S.Fimath.size[0] = 1;
    S.Fimath.size[1] = 0;
    i = S.Data->size[0] * S.Data->size[1];
    S.Data->size[0] = 1;
    S.Data->size[1] = 1;
    emxEnsureCapacity_uint8_T(sp, S.Data, i, &i_emlrtRTEI);
    S.Data->data[0] = 0U;
    S.DataSize = 1U;
    i = pBuffers->size[0] * pBuffers->size[1];
    pBuffers->size[0] = 1;
    pBuffers->size[1] = 1;
    emxEnsureCapacity_struct0_T(sp, pBuffers, i, &i_emlrtRTEI);
    pBuffers_data = pBuffers->data;
    emxCopyStruct_struct0_T(sp, &pBuffers_data[0], &S, &i_emlrtRTEI);
    pBuffers_not_empty = true;
  }
  if (idx > (uint32_T)pBuffers->size[1]) {
    st.site = &ah_emlrtRSI;
    d = (real_T)idx - (real_T)pBuffers->size[1];
    if (d >= 0.0) {
      varargin_2 = (uint32_T)d;
    } else {
      varargin_2 = 0U;
    }
    b_st.site = &yg_emlrtRSI;
    if (varargin_2 > 2147483647U) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &f_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
          "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
    }
    emxCopyStruct_struct0_T(sp, &S, &pBuffers_data[0], &i_emlrtRTEI);
    i = pBuffers->size[1];
    i1 = pBuffers->size[0] * pBuffers->size[1];
    pBuffers->size[0] = 1;
    pBuffers->size[1] += (int32_T)varargin_2;
    emxEnsureCapacity_struct0_T(sp, pBuffers, i1, &i_emlrtRTEI);
    pBuffers_data = pBuffers->data;
    loop_ub = (int32_T)varargin_2;
    for (i1 = 0; i1 < loop_ub; i1++) {
      emxCopyStruct_struct0_T(sp, &pBuffers_data[i1 + i], &S, &i_emlrtRTEI);
    }
  }
  emxFreeStruct_struct0_T(sp, &S);
  emxInitStruct_struct0_T(sp, &expl_temp, &i_emlrtRTEI, true);
  expl_temp.Class.size[0] = 1;
  expl_temp.Class.size[1] = arg_Class_size[1];
  loop_ub = arg_Class_size[1];
  if (loop_ub - 1 >= 0) {
    memcpy(&expl_temp.Class.data[0], &arg_Class_data[0],
           (uint32_T)loop_ub * sizeof(char_T));
  }
  expl_temp.Dims.size[0] = 1;
  expl_temp.Dims.size[1] = 2;
  expl_temp.Dims.data[0] = arg_Dims_data[0];
  expl_temp.Dims.data[1] = arg_Dims_data[1];
  expl_temp.Varsize = true;
  expl_temp.NumericType.size[0] = 1;
  expl_temp.NumericType.size[1] = 0;
  expl_temp.Fimath.size[0] = 1;
  expl_temp.Fimath.size[1] = 0;
  i = expl_temp.Data->size[0] * expl_temp.Data->size[1];
  expl_temp.Data->size[0] = 1;
  expl_temp.Data->size[1] = arg_Data->size[1];
  emxEnsureCapacity_uint8_T(sp, expl_temp.Data, i, &i_emlrtRTEI);
  loop_ub = arg_Data->size[1];
  for (i = 0; i < loop_ub; i++) {
    expl_temp.Data->data[i] = arg_Data_data[i];
  }
  expl_temp.DataSize = 1U;
  i = pBuffers->size[1];
  if (((int32_T)idx < 1) || ((int32_T)idx > pBuffers->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, i, &c_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  emxCopyStruct_struct0_T(sp, &pBuffers_data[(int32_T)idx - 1], &expl_temp,
                          &i_emlrtRTEI);
  emxFreeStruct_struct0_T(sp, &expl_temp);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void c_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_horzcat_,
                               const char_T *identifier, emxArray_boolean_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(a__output_of_horzcat_), &thisId, y);
  emlrtDestroyArray(&a__output_of_horzcat_);
}

static boolean_T customCoderEnableLog(const emlrtStack *sp, uint32_T buffId)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *r;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  int32_T k;
  int32_T nxout;
  boolean_T out;
  boolean_T *pEnabled_data;
  boolean_T *r1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  c_st.prev = &st;
  c_st.tls = st.tls;
  pEnabled_data = pEnabled->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (!pInit_not_empty) {
    pInit_not_empty = true;
    k = pEnabled->size[0] * pEnabled->size[1];
    pEnabled->size[0] = 1;
    pEnabled->size[1] = 1;
    emxEnsureCapacity_boolean_T(sp, pEnabled, k, &i_emlrtRTEI);
    pEnabled_data = pEnabled->data;
    pEnabled_data[0] = false;
    y = NULL;
    iv[0] = 1;
    iv[1] = pEnabled->size[1];
    m = emlrtCreateLogicalArray(2, &iv[0]);
    emlrtInitLogicalArray(pEnabled->size[1], m, &pEnabled_data[0]);
    emlrtAssign(&y, m);
    emxInit_boolean_T(sp, &r, &i_emlrtRTEI, true);
    st.site = &tg_emlrtRSI;
    b_st.site = &sg_emlrtRSI;
    c_emlrt_marshallIn(&st,
                       horzcat(&st, y,
                               f2fCustomCoderEnableLogState(&b_st, &d_emlrtMCI),
                               &e_emlrtMCI),
                       "<output of horzcat>", r);
    r1 = r->data;
    k = pEnabled->size[0] * pEnabled->size[1];
    pEnabled->size[0] = 1;
    pEnabled->size[1] = r->size[1];
    emxEnsureCapacity_boolean_T(sp, pEnabled, k, &i_emlrtRTEI);
    pEnabled_data = pEnabled->data;
    nxout = r->size[0] * r->size[1] - 1;
    for (k = 0; k <= nxout; k++) {
      pEnabled_data[k] = r1[k];
    }
    emxFree_boolean_T(sp, &r);
    st.site = &tg_emlrtRSI;
    c_st.site = &ug_emlrtRSI;
    if (pEnabled->size[1] < 1) {
      emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI,
                                    "MATLAB:subsdeldimmismatch",
                                    "MATLAB:subsdeldimmismatch", 0);
    }
    c_st.site = &vg_emlrtRSI;
    nxout = pEnabled->size[1];
    for (k = 0; k <= nxout - 2; k++) {
      pEnabled_data[k] = pEnabled_data[k + 1];
    }
    k = pEnabled->size[0] * pEnabled->size[1];
    if (pEnabled->size[1] - 1 < 1) {
      pEnabled->size[1] = 0;
    } else {
      pEnabled->size[1]--;
    }
    emxEnsureCapacity_boolean_T(&c_st, pEnabled, k, &m_emlrtRTEI);
    pEnabled_data = pEnabled->data;
  }
  if (buffId > (uint32_T)pEnabled->size[1]) {
    out = false;
  } else {
    k = pEnabled->size[1];
    if (((int32_T)buffId < 1) || ((int32_T)buffId > pEnabled->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)buffId, 1, k, &b_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    out = pEnabled_data[(int32_T)buffId - 1];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return out;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_boolean_T *y)
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *f2fCustomCoderEnableLogState(const emlrtStack *sp,
                                                   emlrtMCInfo *location)
{
  const mxArray *m;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 0, NULL,
                               "f2fCustomCoderEnableLogState", true, location);
}

static void generic_logger_impl_val(const emlrtStack *sp, uint32_T idx_in,
                                    const real_T val_in_data[],
                                    const int32_T val_in_size[2])
{
  static const char_T valClass[6] = {'d', 'o', 'u', 'b', 'l', 'e'};
  emlrtStack st;
  emxArray_real_T c_val_in_data;
  emxArray_uint8_T *S_Data;
  real_T b_val_in_data[18];
  real_T S_Dims_data[2];
  int32_T S_Class_size[2];
  int32_T b_val_in_size[2];
  int32_T val_in;
  char_T S_Class_data[6];
  uint8_T *S_Data_data;
  boolean_T b;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_uint8_T(sp, &S_Data, &i_emlrtRTEI, true);
  if ((idx_in > 1U) && ((val_in_size[0] != 0) && (val_in_size[1] != 0))) {
    st.site = &sg_emlrtRSI;
    b = !buffers(&st, idx_in);
    if (b) {
      S_Class_size[0] = 1;
      S_Class_size[1] = 6;
      for (val_in = 0; val_in < 6; val_in++) {
        S_Class_data[val_in] = valClass[val_in];
      }
      S_Dims_data[0] = val_in_size[0];
      S_Dims_data[1] = val_in_size[1];
      val_in = S_Data->size[0] * S_Data->size[1];
      S_Data->size[0] = 1;
      S_Data->size[1] = 1;
      emxEnsureCapacity_uint8_T(sp, S_Data, val_in, &i_emlrtRTEI);
      S_Data_data = S_Data->data;
      S_Data_data[0] = 0U;
      st.site = &sg_emlrtRSI;
      c_buffers(&st, idx_in, S_Class_data, S_Class_size, S_Dims_data, S_Data);
    }
    val_in = val_in_size[0] * val_in_size[1];
    b_val_in_size[0] = 1;
    b_val_in_size[1] = val_in;
    memcpy(&b_val_in_data[0], &val_in_data[0],
           (uint32_T)val_in * sizeof(real_T));
    c_val_in_data.data = &b_val_in_data[0];
    c_val_in_data.size = &b_val_in_size[0];
    c_val_in_data.allocatedSize = 18;
    c_val_in_data.numDimensions = 2;
    c_val_in_data.canFreeData = false;
    st.site = &sg_emlrtRSI;
    tobytes(&st, &c_val_in_data, S_Data);
    st.site = &sg_emlrtRSI;
    b_buffers(&st, idx_in, S_Data);
  }
  emxFree_uint8_T(sp, &S_Data);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_boolean_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {false, true};
  boolean_T *ret_data;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "logical", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_boolean_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtConstCTX)sp, src, &ret_data[0], 1, false);
  emlrtDestroyArray(&src);
}

static const mxArray *horzcat(const emlrtStack *sp, const mxArray *m1,
                              const mxArray *m2, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 2, &pArrays[0],
                               "horzcat", true, location);
}

static boolean_T indexMapper(const emlrtStack *sp, uint32_T staticIdx)
{
  struct1_T S;
  int32_T i;
  boolean_T actualIdx;
  if (!pIndexMap_not_empty) {
    S.ActualIndex = 0U;
    S.FieldNames.size[0] = 1;
    S.FieldNames.size[1] = 0;
    pIndexMap.size[0] = 1;
    pIndexMap.size[1] = 1;
    pIndexMap.data[0] = S;
    pIndexMap_not_empty = true;
    pBufferLen = 1U;
  }
  if (staticIdx > (uint32_T)pIndexMap.size[1]) {
    actualIdx = false;
  } else {
    i = pIndexMap.size[1];
    if (((int32_T)staticIdx < 1) || ((int32_T)staticIdx > pIndexMap.size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)staticIdx, 1, i, &b_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    actualIdx = (pIndexMap.data[(int32_T)staticIdx - 1].ActualIndex != 0U);
  }
  return actualIdx;
}

static void tobytes(const emlrtStack *sp, const emxArray_real_T *val_in,
                    emxArray_uint8_T *bytes)
{
  emlrtStack st;
  const real_T *val_in_data;
  int32_T i;
  int32_T ny;
  uint8_T *bytes_data;
  st.prev = sp;
  st.tls = sp->tls;
  val_in_data = val_in->data;
  st.site = &sg_emlrtRSI;
  if (val_in->size[1] == 0) {
    ny = 0;
  } else {
    ny = val_in->size[1] << 3;
    if (ny >> 3 != val_in->size[1]) {
      emlrtErrorWithMessageIdR2018a(
          &st, &g_emlrtRTEI, "Coder:toolbox:TooManyElementsToIndex",
          "Coder:toolbox:TooManyElementsToIndex", 2, 12, MAX_int32_T);
    }
  }
  i = bytes->size[0] * bytes->size[1];
  bytes->size[0] = 1;
  bytes->size[1] = ny;
  emxEnsureCapacity_uint8_T(&st, bytes, i, &n_emlrtRTEI);
  bytes_data = bytes->data;
  memcpy((void *)&bytes_data[0], (void *)&val_in_data[0],
         (uint32_T)((size_t)ny * sizeof(uint8_T)));
}

void b_custom_mex_logger(const emlrtStack *sp, uint32_T idx_in,
                         const creal_T val_in_data[],
                         const int32_T val_in_size[2])
{
  static const char_T fieldNames[7] = {'_', 'r', 'e', ':', '_', 'i', 'm'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_struct1_T_1x3 r;
  struct1_T S;
  real_T b_val_in_data[18];
  int32_T b_val_in_size[2];
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  uint32_T b_qY;
  uint32_T qY;
  boolean_T b;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bh_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = customCoderEnableLog(&st, idx_in);
  if (b) {
    st.site = &bh_emlrtRSI;
    b_st.site = &sg_emlrtRSI;
    if (!indexMapper(&b_st, idx_in)) {
      b_st.site = &sg_emlrtRSI;
      if (!pIndexMap_not_empty) {
        S.ActualIndex = 0U;
        S.FieldNames.size[0] = 1;
        S.FieldNames.size[1] = 0;
        pIndexMap.size[0] = 1;
        pIndexMap.size[1] = 1;
        pIndexMap.data[0] = S;
        pIndexMap_not_empty = true;
        pBufferLen = 1U;
      }
      qY = pBufferLen + 1U;
      if (pBufferLen + 1U < pBufferLen) {
        qY = MAX_uint32_T;
      }
      if (idx_in > (uint32_T)pIndexMap.size[1]) {
        if (4.0 - (real_T)pIndexMap.size[1] >= 0.0) {
          b_qY = (uint32_T)(4.0 - (real_T)pIndexMap.size[1]);
        } else {
          b_qY = 0U;
        }
        c_st.site = &xg_emlrtRSI;
        repmat(&c_st, pIndexMap.data[0], b_qY, r.data, r.size);
        i = pIndexMap.size[1];
        loop_ub = r.size[1];
        pIndexMap.size[1] += r.size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          pIndexMap.data[i + i1] = r.data[i1];
        }
      }
      i = pIndexMap.size[1];
      if (((int32_T)idx_in < 1) || ((int32_T)idx_in > pIndexMap.size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)idx_in, 1, i, &emlrtBCI, &b_st);
      }
      pIndexMap.data[3].ActualIndex = qY;
      pIndexMap.data[3].FieldNames.size[0] = 1;
      pIndexMap.data[3].FieldNames.size[1] = 7;
      for (i = 0; i < 7; i++) {
        pIndexMap.data[3].FieldNames.data[i] = fieldNames[i];
      }
      b_qY = pBufferLen + 2U;
      if (pBufferLen + 2U < pBufferLen) {
        b_qY = MAX_uint32_T;
      }
      pBufferLen = b_qY;
    } else {
      b_st.site = &sg_emlrtRSI;
      if (!pIndexMap_not_empty) {
        S.ActualIndex = 0U;
        S.FieldNames.size[0] = 1;
        S.FieldNames.size[1] = 0;
        pIndexMap.size[0] = 1;
        pIndexMap.size[1] = 1;
        pIndexMap.data[0] = S;
        pIndexMap_not_empty = true;
        pBufferLen = 1U;
      }
      i = pIndexMap.size[1];
      if (((int32_T)idx_in < 1) || ((int32_T)idx_in > pIndexMap.size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)idx_in, 1, i, &emlrtBCI, &b_st);
      }
      qY = pIndexMap.data[(int32_T)idx_in - 1].ActualIndex;
    }
    b_st.site = &sg_emlrtRSI;
    b_val_in_size[0] = val_in_size[0];
    b_val_in_size[1] = val_in_size[1];
    loop_ub = val_in_size[0] * val_in_size[1];
    for (i = 0; i < loop_ub; i++) {
      b_val_in_data[i] = val_in_data[i].re;
    }
    c_st.site = &sg_emlrtRSI;
    generic_logger_impl_val(&c_st, qY, b_val_in_data, b_val_in_size);
    b_val_in_size[0] = val_in_size[0];
    b_val_in_size[1] = val_in_size[1];
    for (i = 0; i < loop_ub; i++) {
      b_val_in_data[i] = val_in_data[i].im;
    }
    b_qY = qY + 1U;
    if (qY + 1U < qY) {
      b_qY = MAX_uint32_T;
    }
    c_st.site = &sg_emlrtRSI;
    generic_logger_impl_val(&c_st, b_qY, b_val_in_data, b_val_in_size);
  }
}

void buffers_free(const emlrtStack *sp)
{
  emxFree_struct0_T(sp, &pBuffers);
}

void buffers_init(const emlrtStack *sp)
{
  emxInit_struct0_T(sp, &pBuffers, &i_emlrtRTEI, false);
  pBuffers_not_empty = false;
}

void c_custom_mex_logger(const emlrtStack *sp, emxArray_struct0_T *data,
                         struct1_T bufferInfo_data[],
                         int32_T bufferInfo_size[2])
{
  static const char_T valClass[5] = {'u', 'i', 'n', 't', '8'};
  emlrtStack st;
  struct0_T S;
  struct0_T *data_data;
  struct0_T *pBuffers_data;
  struct1_T b_S;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  pBuffers_data = pBuffers->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &bh_emlrtRSI;
  emxInitStruct_struct0_T(&st, &S, &i_emlrtRTEI, true);
  if (!pBuffers_not_empty) {
    S.Class.size[0] = 1;
    S.Class.size[1] = 5;
    for (i = 0; i < 5; i++) {
      S.Class.data[i] = valClass[i];
    }
    S.Dims.size[0] = 1;
    S.Dims.size[1] = 2;
    S.Dims.data[0] = 1.0;
    S.Dims.data[1] = 1.0;
    S.Varsize = false;
    S.NumericType.size[0] = 1;
    S.NumericType.size[1] = 0;
    S.Fimath.size[0] = 1;
    S.Fimath.size[1] = 0;
    i = S.Data->size[0] * S.Data->size[1];
    S.Data->size[0] = 1;
    S.Data->size[1] = 1;
    emxEnsureCapacity_uint8_T(&st, S.Data, i, &i_emlrtRTEI);
    S.Data->data[0] = 0U;
    S.DataSize = 1U;
    i = pBuffers->size[0] * pBuffers->size[1];
    pBuffers->size[0] = 1;
    pBuffers->size[1] = 1;
    emxEnsureCapacity_struct0_T(&st, pBuffers, i, &i_emlrtRTEI);
    pBuffers_data = pBuffers->data;
    emxCopyStruct_struct0_T(&st, &pBuffers_data[0], &S, &i_emlrtRTEI);
  }
  i = data->size[0] * data->size[1];
  data->size[0] = 1;
  data->size[1] = pBuffers->size[1];
  emxEnsureCapacity_struct0_T(&st, data, i, &i_emlrtRTEI);
  data_data = data->data;
  loop_ub = pBuffers->size[1];
  for (i = 0; i < loop_ub; i++) {
    emxCopyStruct_struct0_T(&st, &data_data[i], &pBuffers_data[i],
                            &i_emlrtRTEI);
  }
  emxCopyStruct_struct0_T(&st, &S, &pBuffers_data[0], &i_emlrtRTEI);
  i = pBuffers->size[0] * pBuffers->size[1];
  pBuffers->size[0] = 1;
  pBuffers->size[1] = 1;
  emxEnsureCapacity_struct0_T(&st, pBuffers, i, &i_emlrtRTEI);
  pBuffers_data = pBuffers->data;
  emxCopyStruct_struct0_T(&st, &pBuffers_data[0], &S, &i_emlrtRTEI);
  emxFreeStruct_struct0_T(&st, &S);
  pBuffers_not_empty = true;
  if (!pIndexMap_not_empty) {
    b_S.ActualIndex = 0U;
    b_S.FieldNames.size[0] = 1;
    b_S.FieldNames.size[1] = 0;
    pIndexMap.size[0] = 1;
    pIndexMap.size[1] = 1;
    pIndexMap.data[0] = b_S;
    pIndexMap_not_empty = true;
    pBufferLen = 1U;
  }
  bufferInfo_size[0] = 1;
  bufferInfo_size[1] = pIndexMap.size[1];
  loop_ub = pIndexMap.size[1];
  if (loop_ub - 1 >= 0) {
    memcpy(&bufferInfo_data[0], &pIndexMap.data[0],
           (uint32_T)loop_ub * sizeof(struct1_T));
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void customCoderEnableLog_free(const emlrtStack *sp)
{
  emxFree_boolean_T(sp, &pEnabled);
}

void customCoderEnableLog_init(const emlrtStack *sp)
{
  emxInit_boolean_T(sp, &pEnabled, &i_emlrtRTEI, false);
}

void custom_mex_logger(const emlrtStack *sp, uint32_T idx_in,
                       const emxArray_real_T *val_in)
{
  static const char_T valClass[6] = {'d', 'o', 'u', 'b', 'l', 'e'};
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *b_val_in;
  emxArray_struct1_T_1x3 r;
  emxArray_uint8_T *bytes;
  struct1_T S;
  real_T S_Dims_data[2];
  const real_T *val_in_data;
  real_T d;
  real_T *b_val_in_data;
  int32_T S_Class_size[2];
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  uint32_T actualIdx;
  uint32_T qY;
  char_T S_Class_data[6];
  uint8_T *bytes_data;
  boolean_T b;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  val_in_data = val_in->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &sg_emlrtRSI;
  b = customCoderEnableLog(&st, idx_in);
  if (b) {
    st.site = &sg_emlrtRSI;
    if (!indexMapper(&st, idx_in)) {
      st.site = &sg_emlrtRSI;
      if (!pIndexMap_not_empty) {
        S.ActualIndex = 0U;
        S.FieldNames.size[0] = 1;
        S.FieldNames.size[1] = 0;
        pIndexMap.size[0] = 1;
        pIndexMap.size[1] = 1;
        pIndexMap.data[0] = S;
        pIndexMap_not_empty = true;
        pBufferLen = 1U;
      }
      actualIdx = pBufferLen + 1U;
      if (pBufferLen + 1U < pBufferLen) {
        actualIdx = MAX_uint32_T;
      }
      if (idx_in > (uint32_T)pIndexMap.size[1]) {
        d = (real_T)idx_in - (real_T)pIndexMap.size[1];
        if (d >= 0.0) {
          qY = (uint32_T)d;
        } else {
          qY = 0U;
        }
        b_st.site = &xg_emlrtRSI;
        repmat(&b_st, pIndexMap.data[0], qY, r.data, r.size);
        i = pIndexMap.size[1];
        loop_ub = r.size[1];
        pIndexMap.size[1] += r.size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          pIndexMap.data[i + i1] = r.data[i1];
        }
      }
      i = pIndexMap.size[1];
      if (((int32_T)idx_in < 1) || ((int32_T)idx_in > pIndexMap.size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)idx_in, 1, i, &emlrtBCI, &st);
      }
      pIndexMap.data[(int32_T)idx_in - 1].ActualIndex = actualIdx;
      qY = pBufferLen + 1U;
      if (pBufferLen + 1U < pBufferLen) {
        qY = MAX_uint32_T;
      }
      pBufferLen = qY;
    } else {
      st.site = &sg_emlrtRSI;
      if (!pIndexMap_not_empty) {
        S.ActualIndex = 0U;
        S.FieldNames.size[0] = 1;
        S.FieldNames.size[1] = 0;
        pIndexMap.size[0] = 1;
        pIndexMap.size[1] = 1;
        pIndexMap.data[0] = S;
        pIndexMap_not_empty = true;
        pBufferLen = 1U;
      }
      i = pIndexMap.size[1];
      if (((int32_T)idx_in < 1) || ((int32_T)idx_in > pIndexMap.size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)idx_in, 1, i, &emlrtBCI, &st);
      }
      actualIdx = pIndexMap.data[(int32_T)idx_in - 1].ActualIndex;
    }
    emxInit_uint8_T(sp, &bytes, &i_emlrtRTEI, true);
    st.site = &sg_emlrtRSI;
    b = !buffers(&st, actualIdx);
    if (b) {
      S_Class_size[0] = 1;
      S_Class_size[1] = 6;
      for (i = 0; i < 6; i++) {
        S_Class_data[i] = valClass[i];
      }
      S_Dims_data[0] = val_in->size[0];
      S_Dims_data[1] = 1.0;
      i = bytes->size[0] * bytes->size[1];
      bytes->size[0] = 1;
      bytes->size[1] = 1;
      emxEnsureCapacity_uint8_T(sp, bytes, i, &i_emlrtRTEI);
      bytes_data = bytes->data;
      bytes_data[0] = 0U;
      st.site = &sg_emlrtRSI;
      c_buffers(&st, actualIdx, S_Class_data, S_Class_size, S_Dims_data, bytes);
    }
    emxInit_real_T(sp, &b_val_in, 2, &i_emlrtRTEI);
    i = b_val_in->size[0] * b_val_in->size[1];
    b_val_in->size[0] = 1;
    b_val_in->size[1] = val_in->size[0];
    emxEnsureCapacity_real_T(sp, b_val_in, i, &i_emlrtRTEI);
    b_val_in_data = b_val_in->data;
    loop_ub = val_in->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_val_in_data[i] = val_in_data[i];
    }
    st.site = &sg_emlrtRSI;
    tobytes(&st, b_val_in, bytes);
    emxFree_real_T(sp, &b_val_in);
    st.site = &sg_emlrtRSI;
    if ((actualIdx > 1U) && (bytes->size[1] != 0)) {
      b_st.site = &sg_emlrtRSI;
      b_buffers(&b_st, actualIdx, bytes);
    }
    emxFree_uint8_T(&st, &bytes);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void indexMapper_init(void)
{
  emxInit_struct1_T_1x6(&pIndexMap);
  pIndexMap_not_empty = false;
}

void pInit_not_empty_init(void)
{
  pInit_not_empty = false;
}
