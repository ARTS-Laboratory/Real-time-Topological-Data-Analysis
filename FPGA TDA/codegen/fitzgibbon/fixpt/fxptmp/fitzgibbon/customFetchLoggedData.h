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

void customFetchLoggedData(const emlrtStack *sp, emxArray_struct0_T *data,
                           struct1_T dataInfo_data[], int32_T dataInfo_size[2],
                           char_T dataExprIdMapping[97], real_T *numLoggedExpr);
