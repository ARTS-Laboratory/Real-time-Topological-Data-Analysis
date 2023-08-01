#pragma once

#include "fitzgibbon_float_mex_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void b_custom_mex_logger(const emlrtStack *sp, uint32_T idx_in,
                         const creal_T val_in_data[],
                         const int32_T val_in_size[2]);

void buffers_free(const emlrtStack *sp);

void buffers_init(const emlrtStack *sp);

void c_custom_mex_logger(const emlrtStack *sp, emxArray_struct0_T *data,
                         struct1_T bufferInfo_data[],
                         int32_T bufferInfo_size[2]);

void customCoderEnableLog_free(const emlrtStack *sp);

void customCoderEnableLog_init(const emlrtStack *sp);

void custom_mex_logger(const emlrtStack *sp, uint32_T idx_in,
                       const emxArray_real_T *val_in);

void indexMapper_init(void);

void pInit_not_empty_init(void);
