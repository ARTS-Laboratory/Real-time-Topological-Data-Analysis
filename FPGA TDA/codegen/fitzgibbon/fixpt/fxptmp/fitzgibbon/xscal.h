#pragma once

#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void b_xscal(const emlrtStack *sp, real_T a, real_T x[9], int32_T ix0);

void xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[9], int32_T ix0);
