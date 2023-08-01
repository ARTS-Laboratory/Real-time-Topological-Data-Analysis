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

void repmat(const emlrtStack *sp, const struct1_T a, uint32_T varargin_2,
            struct1_T b_data[], int32_T b_size[2]);
