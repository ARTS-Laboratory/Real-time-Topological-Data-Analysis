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

void fitzgibbon(const emlrtStack *sp, const emxArray_real_T *x,
                const emxArray_real_T *y, creal_T a_data[], int32_T a_size[2]);
