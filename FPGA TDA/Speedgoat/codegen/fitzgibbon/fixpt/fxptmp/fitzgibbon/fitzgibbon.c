#include "fitzgibbon.h"
#include "custom_mex_logger.h"
#include "eig.h"
#include "fitzgibbon_float_mex_data.h"
#include "fitzgibbon_float_mex_emxutil.h"
#include "fitzgibbon_float_mex_mexutil.h"
#include "fitzgibbon_float_mex_types.h"
#include "inv.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

static emlrtRSInfo emlrtRSI = {
    3, "fitzgibbon", "C:\\Users\\dwamai\\Desktop\\linregellipse\\fitzgibbon.m"};

static emlrtRSInfo b_emlrtRSI = {
    4, "fitzgibbon", "C:\\Users\\dwamai\\Desktop\\linregellipse\\fitzgibbon.m"};

static emlrtRSInfo c_emlrtRSI = {
    6, "fitzgibbon", "C:\\Users\\dwamai\\Desktop\\linregellipse\\fitzgibbon.m"};

static emlrtRSInfo d_emlrtRSI = {
    7, "fitzgibbon", "C:\\Users\\dwamai\\Desktop\\linregellipse\\fitzgibbon.m"};

static emlrtRSInfo e_emlrtRSI = {
    8, "fitzgibbon", "C:\\Users\\dwamai\\Desktop\\linregellipse\\fitzgibbon.m"};

static emlrtRSInfo f_emlrtRSI = {
    10, "fitzgibbon",
    "C:\\Users\\dwamai\\Desktop\\linregellipse\\fitzgibbon.m"};

static emlrtRSInfo g_emlrtRSI = {
    15, "fitzgibbon",
    "C:\\Users\\dwamai\\Desktop\\linregellipse\\fitzgibbon.m"};

static emlrtRSInfo h_emlrtRSI = {
    22, "fitzgibbon",
    "C:\\Users\\dwamai\\Desktop\\linregellipse\\fitzgibbon.m"};

static emlrtRSInfo i_emlrtRSI = {
    1, "fitzgibbon", "C:\\Users\\dwamai\\Desktop\\linregellipse\\fitzgibbon.m"};

static emlrtRSInfo k_emlrtRSI = {
    39, "cat",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"};

static emlrtRSInfo l_emlrtRSI = {
    113, "cat_impl",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"};

static emlrtRSInfo m_emlrtRSI = {94, "eml_mtimes_helper",
                                 "C:\\Program "
                                 "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\mat"
                                 "lab\\ops\\eml_mtimes_helper.m"};

static emlrtRSInfo n_emlrtRSI = {69, "eml_mtimes_helper",
                                 "C:\\Program "
                                 "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\mat"
                                 "lab\\ops\\eml_mtimes_helper.m"};

static emlrtRSInfo qg_emlrtRSI = {
    41, "cat",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"};

static emlrtECInfo emlrtECI = {
    1, 3, 15, "fitzgibbon",
    "C:\\Users\\dwamai\\Desktop\\linregellipse\\fitzgibbon.m"};

static emlrtRTEInfo emlrtRTEI = {
    288, 27, "check_non_axis_size",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"};

static emlrtRTEInfo b_emlrtRTEI = {138, 23, "dynamic_size_checks",
                                   "C:\\Program "
                                   "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\m"
                                   "atlab\\ops\\eml_mtimes_helper.m"};

static emlrtRTEInfo j_emlrtRTEI = {
    1, 14, "fitzgibbon",
    "C:\\Users\\dwamai\\Desktop\\linregellipse\\fitzgibbon.m"};

static emlrtRTEInfo k_emlrtRTEI = {
    3, 1, "fitzgibbon",
    "C:\\Users\\dwamai\\Desktop\\linregellipse\\fitzgibbon.m"};

static emlrtRTEInfo l_emlrtRTEI = {
    4, 1, "fitzgibbon",
    "C:\\Users\\dwamai\\Desktop\\linregellipse\\fitzgibbon.m"};

static void emlrt_update_log_1(const emxArray_real_T *in,
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static void emlrt_update_log_2(const emxArray_real_T *in,
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static void emlrt_update_log_3(const real_T in[9],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static void emlrt_update_log_4(const real_T in[3],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static void emlrt_update_log_5(const creal_T in[3],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static void emlrt_update_log_6(const creal_T in_data[],
                               const int32_T in_size[2],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static void emlrt_update_log_7(const creal_T in_data[],
                               const int32_T in_size[2],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static void emlrt_update_log_8(const creal_T in[9],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index);

static void times(const emlrtStack *sp, emxArray_real_T *in1,
                  const emxArray_real_T *in2, const emxArray_real_T *in3);

static void emlrt_update_log_1(const emxArray_real_T *in,
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  const real_T *in_data;
  real_T localMax;
  real_T localMin;
  int32_T i;
  in_data = in->data;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;
    for (i = 0; i < in->size[0]; i++) {

      if (in_data[i] < localMin) {
        localMin = in_data[i];
      }
      if (in_data[i] > localMax) {
        localMax = in_data[i];
      }
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < in->size[0])) {
      if (in_data[i] != muDoubleScalarFloor(in_data[i])) {
        b_table[0U].IsAlwaysInteger = false;
      }
      i++;
    }
  }
}

static void emlrt_update_log_2(const emxArray_real_T *in,
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  const real_T *in_data;
  real_T localMax;
  real_T localMin;
  int32_T i;
  in_data = in->data;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;
    for (i = 0; i < in->size[0] * 3; i++) {

      if (in_data[i] < localMin) {
        localMin = in_data[i];
      }
      if (in_data[i] > localMax) {
        localMax = in_data[i];
      }
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < in->size[0] * 3)) {
      if (in_data[i] != muDoubleScalarFloor(in_data[i])) {
        b_table[0U].IsAlwaysInteger = false;
      }
      i++;
    }
  }
}

static void emlrt_update_log_3(const real_T in[9],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  real_T d;
  real_T localMax;
  real_T localMin;
  int32_T i;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;
    for (i = 0; i < 9; i++) {

      d = in[i];
      if (d < localMin) {
        localMin = d;
      }
      if (d > localMax) {
        localMax = d;
      }
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < 9)) {
      if (in[i] != muDoubleScalarFloor(in[i])) {
        b_table[0U].IsAlwaysInteger = false;
      }
      i++;
    }
  }
}

static void emlrt_update_log_4(const real_T in[3],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  real_T d;
  real_T localMax;
  real_T localMin;
  int32_T i;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;

    d = in[0];
    if (d < localMin) {
      localMin = d;
    }
    if (d > localMax) {
      localMax = d;
    }

    d = in[1];
    if (d < localMin) {
      localMin = d;
    }
    if (d > localMax) {
      localMax = d;
    }

    d = in[2];
    if (d < localMin) {
      localMin = d;
    }
    if (d > localMax) {
      localMax = d;
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < 3)) {
      if (in[i] != muDoubleScalarFloor(in[i])) {
        b_table[0U].IsAlwaysInteger = false;
      }
      i++;
    }
  }
}

static void emlrt_update_log_5(const creal_T in[3],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  real_T im;
  real_T localMax;
  real_T localMin;
  real_T re;
  int32_T i;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;

    re = in[0].re;
    im = in[0].im;
    if (re < localMin) {
      localMin = re;
    }
    if (re > localMax) {
      localMax = re;
    }
    if (im < localMin) {
      localMin = im;
    }
    if (im > localMax) {
      localMax = im;
    }

    re = in[1].re;
    im = in[1].im;
    if (re < localMin) {
      localMin = re;
    }
    if (re > localMax) {
      localMax = re;
    }
    if (im < localMin) {
      localMin = im;
    }
    if (im > localMax) {
      localMax = im;
    }

    re = in[2].re;
    im = in[2].im;
    if (re < localMin) {
      localMin = re;
    }
    if (re > localMax) {
      localMax = re;
    }
    if (im < localMin) {
      localMin = im;
    }
    if (im > localMax) {
      localMax = im;
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < 3)) {
      if ((in[i].re != muDoubleScalarFloor(in[i].re)) ||
          (in[i].im != muDoubleScalarFloor(in[i].im))) {
        b_table[0U].IsAlwaysInteger = false;
      }
      i++;
    }
  }
}

static void emlrt_update_log_6(const creal_T in_data[],
                               const int32_T in_size[2],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  real_T localMax;
  real_T localMin;
  int32_T i;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;
    for (i = 0; i < 3 * in_size[1]; i++) {

      if (in_data[i].re < localMin) {
        localMin = in_data[i].re;
      }
      if (in_data[i].re > localMax) {
        localMax = in_data[i].re;
      }
      if (in_data[i].im < localMin) {
        localMin = in_data[i].im;
      }
      if (in_data[i].im > localMax) {
        localMax = in_data[i].im;
      }
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < 3 * in_size[1])) {
      if ((in_data[i].re != muDoubleScalarFloor(in_data[i].re)) ||
          (in_data[i].im != muDoubleScalarFloor(in_data[i].im))) {
        b_table[0U].IsAlwaysInteger = false;
      }
      i++;
    }
  }
}

static void emlrt_update_log_7(const creal_T in_data[],
                               const int32_T in_size[2],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  real_T localMax;
  real_T localMin;
  int32_T b_i;
  int32_T exitg1;
  int32_T i;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;
    i = 0;
    do {
      exitg1 = 0;
      b_i = in_size[0] * in_size[1];
      if (i < b_i) {

        if (in_data[i].re < localMin) {
          localMin = in_data[i].re;
        }
        if (in_data[i].re > localMax) {
          localMax = in_data[i].re;
        }
        if (in_data[i].im < localMin) {
          localMin = in_data[i].im;
        }
        if (in_data[i].im > localMax) {
          localMax = in_data[i].im;
        }
        i++;
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < b_i)) {
      if ((in_data[i].re != muDoubleScalarFloor(in_data[i].re)) ||
          (in_data[i].im != muDoubleScalarFloor(in_data[i].im))) {
        b_table[0U].IsAlwaysInteger = false;
      }
      i++;
    }
  }
}

static void emlrt_update_log_8(const creal_T in[9],
                               emlrtLocationLoggingDataType table[],
                               int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  real_T d;
  real_T localMax;
  real_T localMin;
  int32_T i;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;
    for (i = 0; i < 9; i++) {

      d = in[i].re;
      if (d < localMin) {
        localMin = d;
      }
      if (d > localMax) {
        localMax = d;
      }
      d = in[i].im;
      if (d < localMin) {
        localMin = d;
      }
      if (d > localMax) {
        localMax = d;
      }
    }
    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < 9)) {
      if ((in[i].re != muDoubleScalarFloor(in[i].re)) ||
          (in[i].im != muDoubleScalarFloor(in[i].im))) {
        b_table[0U].IsAlwaysInteger = false;
      }
      i++;
    }
  }
}

static void times(const emlrtStack *sp, emxArray_real_T *in1,
                  const emxArray_real_T *in2, const emxArray_real_T *in3)
{
  const real_T *in2_data;
  const real_T *in3_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, (emlrtRTEInfo *)NULL);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = in2_data[i * stride_0_0] * in3_data[i * stride_1_0];
  }
}

void fitzgibbon(const emlrtStack *sp, const emxArray_real_T *x,
                const emxArray_real_T *y, creal_T a_data[], int32_T a_size[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *D1;
  emxArray_real_T *D2;
  emxArray_real_T *varargin_1;
  emxArray_real_T *varargin_2;
  emxArray_real_T *varargin_3;
  creal_T a1_data[9];
  creal_T b_varargin_2_data[9];
  creal_T evec[9];
  creal_T b_y[3];
  creal_T cond[3];
  real_T S1[9];
  real_T S2[9];
  real_T S3[9];
  real_T T[9];
  real_T a[9];
  real_T dv[3];
  real_T dv1[3];
  const real_T *x_data;
  const real_T *y_data;
  real_T b_evec_re_tmp;
  real_T b_varargin_1;
  real_T c_evec_re_tmp;
  real_T d_evec_re_tmp;
  real_T e_evec_re_tmp;
  real_T evec_re_tmp;
  real_T f_evec_re_tmp;
  real_T g_evec_re_tmp;
  real_T h_evec_re_tmp;
  real_T i_evec_re_tmp;
  real_T j_evec_re_tmp;
  real_T re_tmp;
  real_T *D1_data;
  real_T *D2_data;
  real_T *varargin_2_data;
  real_T *varargin_3_data;
  int32_T a1_size[2];
  int32_T varargin_2_size[2];
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T result;
  int32_T trueCount;
  int8_T tmp_data[3];
  int8_T input_sizes_idx_0;
  int8_T sizes_idx_0;
  boolean_T empty_non_axis_sizes;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y_data = y->data;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);

  emlrtInitVarDataTables(emlrtLocationLoggingDataTables);

  emxInit_real_T(sp, &varargin_1, 1, &j_emlrtRTEI);
  i = varargin_1->size[0];
  varargin_1->size[0] = x->size[0];
  emxEnsureCapacity_real_T(sp, varargin_1, i, &j_emlrtRTEI);
  D2_data = varargin_1->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    D2_data[i] = x_data[i];
  }
  emlrt_update_log_1(varargin_1, emlrtLocationLoggingDataTables, 0);

  i = varargin_1->size[0];
  varargin_1->size[0] = y->size[0];
  emxEnsureCapacity_real_T(sp, varargin_1, i, &j_emlrtRTEI);
  D2_data = varargin_1->data;
  loop_ub = y->size[0];
  for (i = 0; i < loop_ub; i++) {
    D2_data[i] = y_data[i];
  }
  emlrt_update_log_1(varargin_1, emlrtLocationLoggingDataTables, 1);
  st.site = &i_emlrtRSI;
  custom_mex_logger(&st, 2U, x);
  st.site = &i_emlrtRSI;
  custom_mex_logger(&st, 3U, y);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
  if ((x->size[0] != y->size[0]) && ((x->size[0] != 1) && (y->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(x->size[0], y->size[0], &emlrtECI,
                                (emlrtConstCTX)sp);
  }
  st.site = &emlrtRSI;
  b_st.site = &emlrtRSI;
  i = varargin_1->size[0];
  varargin_1->size[0] = x->size[0];
  emxEnsureCapacity_real_T(&st, varargin_1, i, &j_emlrtRTEI);
  D2_data = varargin_1->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_1 = x_data[i];
    D2_data[i] = b_varargin_1 * b_varargin_1;
  }
  emlrt_update_log_1(varargin_1, emlrtLocationLoggingDataTables, 3);
  emxInit_real_T(&st, &varargin_2, 1, &j_emlrtRTEI);
  if (x->size[0] == y->size[0]) {
    i = varargin_2->size[0];
    varargin_2->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&st, varargin_2, i, &j_emlrtRTEI);
    varargin_2_data = varargin_2->data;
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      varargin_2_data[i] = x_data[i] * y_data[i];
    }
  } else {
    times(&st, varargin_2, x, y);
    varargin_2_data = varargin_2->data;
  }
  emlrt_update_log_1(varargin_2, emlrtLocationLoggingDataTables, 4);
  b_st.site = &emlrtRSI;
  emxInit_real_T(&st, &varargin_3, 1, &j_emlrtRTEI);
  i = varargin_3->size[0];
  varargin_3->size[0] = y->size[0];
  emxEnsureCapacity_real_T(&st, varargin_3, i, &j_emlrtRTEI);
  varargin_3_data = varargin_3->data;
  loop_ub = y->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_1 = y_data[i];
    varargin_3_data[i] = b_varargin_1 * b_varargin_1;
  }
  emlrt_update_log_1(varargin_3, emlrtLocationLoggingDataTables, 5);
  b_st.site = &k_emlrtRSI;
  c_st.site = &l_emlrtRSI;
  if (varargin_2->size[0] != varargin_1->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if (varargin_3->size[0] != varargin_1->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  emxInit_real_T(sp, &D1, 2, &k_emlrtRTEI);
  i = D1->size[0] * D1->size[1];
  D1->size[0] = varargin_1->size[0];
  D1->size[1] = 3;
  emxEnsureCapacity_real_T(sp, D1, i, &k_emlrtRTEI);
  D1_data = D1->data;
  loop_ub = varargin_1->size[0];
  for (i = 0; i < loop_ub; i++) {
    D1_data[i] = D2_data[i];
  }
  emxFree_real_T(sp, &varargin_1);
  loop_ub = varargin_2->size[0];
  for (i = 0; i < loop_ub; i++) {
    D1_data[i + D1->size[0]] = varargin_2_data[i];
  }
  emxFree_real_T(sp, &varargin_2);
  loop_ub = varargin_3->size[0];
  for (i = 0; i < loop_ub; i++) {
    D1_data[i + D1->size[0] * 2] = varargin_3_data[i];
  }
  emxFree_real_T(sp, &varargin_3);
  emlrt_update_log_2(D1, emlrtLocationLoggingDataTables, 2);
  st.site = &b_emlrtRSI;
  b_st.site = &k_emlrtRSI;
  c_st.site = &l_emlrtRSI;
  if (y->size[0] != x->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  emxInit_real_T(sp, &D2, 2, &l_emlrtRTEI);
  i = D2->size[0] * D2->size[1];
  D2->size[0] = x->size[0];
  D2->size[1] = 3;
  emxEnsureCapacity_real_T(sp, D2, i, &l_emlrtRTEI);
  D2_data = D2->data;
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    D2_data[i] = x_data[i];
  }
  loop_ub = y->size[0];
  for (i = 0; i < loop_ub; i++) {
    D2_data[i + D2->size[0]] = y_data[i];
  }
  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    D2_data[i + D2->size[0] * 2] = 1.0;
  }
  emlrt_update_log_2(D2, emlrtLocationLoggingDataTables, 6);
  st.site = &c_emlrtRSI;
  b_st.site = &n_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  mtimes(D1, D1, S1);
  emlrt_update_log_3(S1, emlrtLocationLoggingDataTables, 7);
  st.site = &d_emlrtRSI;
  b_st.site = &n_emlrtRSI;
  if (D1->size[0] != D2->size[0]) {
    emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
                                  "MATLAB:innerdim", 0);
  }
  b_st.site = &m_emlrtRSI;
  mtimes(D1, D2, S2);
  emxFree_real_T(&st, &D1);
  emlrt_update_log_3(S2, emlrtLocationLoggingDataTables, 8);
  st.site = &e_emlrtRSI;
  b_st.site = &n_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  mtimes(D2, D2, S3);
  emxFree_real_T(&st, &D2);
  emlrt_update_log_3(S3, emlrtLocationLoggingDataTables, 9);
  st.site = &f_emlrtRSI;
  inv(&st, S3, a);
  emlrt_update_log_3(a, emlrtLocationLoggingDataTables, 11);
  for (i = 0; i < 9; i++) {
    a[i] = -a[i];
  }
  for (i = 0; i < 3; i++) {
    b_varargin_1 = a[i];
    re_tmp = a[i + 3];
    evec_re_tmp = a[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      T[i + 3 * i1] = (b_varargin_1 * S2[i1] + re_tmp * S2[i1 + 3]) +
                      evec_re_tmp * S2[i1 + 6];
    }
  }
  emlrt_update_log_3(T, emlrtLocationLoggingDataTables, 10);
  for (i = 0; i < 3; i++) {
    b_varargin_1 = S2[i];
    re_tmp = S2[i + 3];
    evec_re_tmp = S2[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      S3[i + 3 * i1] = (b_varargin_1 * T[3 * i1] + re_tmp * T[3 * i1 + 1]) +
                       evec_re_tmp * T[3 * i1 + 2];
    }
  }
  emlrt_update_log_3(S3, emlrtLocationLoggingDataTables, 13);
  for (i = 0; i < 9; i++) {
    S1[i] += S3[i];
  }
  emlrt_update_log_3(S1, emlrtLocationLoggingDataTables, 12);
  dv[0] = S1[2] / 2.0;
  dv[1] = S1[5] / 2.0;
  dv[2] = S1[8] / 2.0;
  emlrt_update_log_4(dv, emlrtLocationLoggingDataTables, 15);
  dv1[0] = S1[0] / 2.0;
  dv1[1] = S1[3] / 2.0;
  dv1[2] = S1[6] / 2.0;
  emlrt_update_log_4(dv1, emlrtLocationLoggingDataTables, 16);
  S2[0] = dv[0];
  S2[1] = -S1[1];
  S2[2] = dv1[0];
  S2[3] = dv[1];
  S2[4] = -S1[4];
  S2[5] = dv1[1];
  S2[6] = dv[2];
  S2[7] = -S1[7];
  S2[8] = dv1[2];
  memcpy(&S1[0], &S2[0], 9U * sizeof(real_T));
  emlrt_update_log_3(S1, emlrtLocationLoggingDataTables, 14);
  st.site = &g_emlrtRSI;
  eig(&st, S1, evec, a1_data);
  emlrt_update_log_8(evec, emlrtLocationLoggingDataTables, 24);
  emlrt_update_log_8(a1_data, emlrtLocationLoggingDataTables, 25);
  b_y[0].re = evec[1].re * evec[1].re - evec[1].im * evec[1].im;
  b_varargin_1 = evec[1].re * evec[1].im;
  b_y[0].im = b_varargin_1 + b_varargin_1;
  cond[0].re = 4.0 * evec[0].re;
  cond[0].im = 4.0 * evec[0].im;
  b_y[1].re = evec[4].re * evec[4].re - evec[4].im * evec[4].im;
  b_varargin_1 = evec[4].re * evec[4].im;
  b_y[1].im = b_varargin_1 + b_varargin_1;
  cond[1].re = 4.0 * evec[3].re;
  cond[1].im = 4.0 * evec[3].im;
  b_y[2].re = evec[7].re * evec[7].re - evec[7].im * evec[7].im;
  b_varargin_1 = evec[7].re * evec[7].im;
  b_y[2].im = b_varargin_1 + b_varargin_1;
  cond[2].re = 4.0 * evec[6].re;
  cond[2].im = 4.0 * evec[6].im;
  emlrt_update_log_5(cond, emlrtLocationLoggingDataTables, 19);
  b_varargin_1 = cond[0].re * evec[2].im + cond[0].im * evec[2].re;
  cond[0].re = cond[0].re * evec[2].re - cond[0].im * evec[2].im;
  cond[0].im = b_varargin_1;
  b_varargin_1 = cond[1].re * evec[5].im + cond[1].im * evec[5].re;
  cond[1].re = cond[1].re * evec[5].re - cond[1].im * evec[5].im;
  cond[1].im = b_varargin_1;
  re_tmp = cond[2].re * evec[8].re - cond[2].im * evec[8].im;
  b_varargin_1 = cond[2].re * evec[8].im + cond[2].im * evec[8].re;
  cond[2].re = re_tmp;
  cond[2].im = b_varargin_1;
  emlrt_update_log_5(cond, emlrtLocationLoggingDataTables, 18);
  emlrt_update_log_5(b_y, emlrtLocationLoggingDataTables, 20);
  cond[0].re -= b_y[0].re;
  cond[0].im -= b_y[0].im;
  cond[1].re -= b_y[1].re;
  cond[1].im -= b_y[1].im;
  cond[2].re = re_tmp - b_y[2].re;
  cond[2].im = b_varargin_1 - b_y[2].im;
  emlrt_update_log_5(cond, emlrtLocationLoggingDataTables, 17);
  trueCount = 0;
  if (cond[0].re > 0.0) {
    trueCount = 1;
  }
  if (cond[1].re > 0.0) {
    trueCount++;
  }
  if (cond[2].re > 0.0) {
    trueCount++;
  }
  loop_ub = 0;
  if (cond[0].re > 0.0) {
    tmp_data[0] = 0;
    loop_ub = 1;
  }
  if (cond[1].re > 0.0) {
    tmp_data[loop_ub] = 1;
    loop_ub++;
  }
  if (cond[2].re > 0.0) {
    tmp_data[loop_ub] = 2;
  }
  a1_size[0] = 3;
  a1_size[1] = trueCount;
  for (i = 0; i < trueCount; i++) {
    loop_ub = 3 * tmp_data[i];
    a1_data[3 * i] = evec[loop_ub];
    a1_data[3 * i + 1] = evec[loop_ub + 1];
    a1_data[3 * i + 2] = evec[loop_ub + 2];
  }
  emlrt_update_log_6(a1_data, a1_size, emlrtLocationLoggingDataTables, 21);
  st.site = &h_emlrtRSI;
  for (i = 0; i < 9; i++) {
    evec[i].re = T[i];
    evec[i].im = 0.0;
  }
  varargin_2_size[0] = 3;
  varargin_2_size[1] = trueCount;
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < trueCount; i1++) {
      b_varargin_1 = evec[i].re;
      re_tmp = a1_data[3 * i1].im;
      evec_re_tmp = evec[i].im;
      b_evec_re_tmp = a1_data[3 * i1].re;
      c_evec_re_tmp = evec[i + 3].re;
      loop_ub = 3 * i1 + 1;
      d_evec_re_tmp = a1_data[loop_ub].im;
      e_evec_re_tmp = evec[i + 3].im;
      f_evec_re_tmp = a1_data[loop_ub].re;
      g_evec_re_tmp = evec[i + 6].re;
      loop_ub = 3 * i1 + 2;
      h_evec_re_tmp = a1_data[loop_ub].im;
      i_evec_re_tmp = evec[i + 6].im;
      j_evec_re_tmp = a1_data[loop_ub].re;
      loop_ub = i + 3 * i1;
      b_varargin_2_data[loop_ub].re =
          ((b_varargin_1 * b_evec_re_tmp - evec_re_tmp * re_tmp) +
           (c_evec_re_tmp * f_evec_re_tmp - e_evec_re_tmp * d_evec_re_tmp)) +
          (g_evec_re_tmp * j_evec_re_tmp - i_evec_re_tmp * h_evec_re_tmp);
      b_varargin_2_data[loop_ub].im =
          ((b_varargin_1 * re_tmp + evec_re_tmp * b_evec_re_tmp) +
           (c_evec_re_tmp * d_evec_re_tmp + e_evec_re_tmp * f_evec_re_tmp)) +
          (g_evec_re_tmp * h_evec_re_tmp + i_evec_re_tmp * j_evec_re_tmp);
    }
  }
  emlrt_update_log_6(b_varargin_2_data, varargin_2_size,
                     emlrtLocationLoggingDataTables, 23);
  b_st.site = &qg_emlrtRSI;
  if (trueCount != 0) {
    result = trueCount;
  } else if (trueCount != 0) {
    result = trueCount;
  } else {
    result = 0;
  }
  c_st.site = &l_emlrtRSI;
  if ((trueCount != result) && (trueCount != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if ((trueCount != result) && (trueCount != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  empty_non_axis_sizes = (result == 0);
  if (empty_non_axis_sizes || (trueCount != 0)) {
    input_sizes_idx_0 = 3;
  } else {
    input_sizes_idx_0 = 0;
  }
  if (empty_non_axis_sizes || (trueCount != 0)) {
    sizes_idx_0 = 3;
  } else {
    sizes_idx_0 = 0;
  }
  loop_ub = input_sizes_idx_0;
  trueCount = sizes_idx_0;
  a_size[0] = input_sizes_idx_0 + sizes_idx_0;
  a_size[1] = result;
  for (i = 0; i < result; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      a_data[i1 + a_size[0] * i] = a1_data[i1 + input_sizes_idx_0 * i];
    }
    for (i1 = 0; i1 < trueCount; i1++) {
      a_data[(i1 + input_sizes_idx_0) + a_size[0] * i] =
          b_varargin_2_data[i1 + sizes_idx_0 * i];
    }
  }
  emlrt_update_log_7(a_data, a_size, emlrtLocationLoggingDataTables, 22);
  st.site = &i_emlrtRSI;
  b_custom_mex_logger(&st, 4U, a_data, a_size);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}
