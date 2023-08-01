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

void mtimes(const emxArray_real_T *A, const emxArray_real_T *B, real_T C[9]);
