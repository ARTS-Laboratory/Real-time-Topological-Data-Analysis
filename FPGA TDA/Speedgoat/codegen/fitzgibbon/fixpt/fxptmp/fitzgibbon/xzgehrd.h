#pragma once

#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xzgehrd(const emlrtStack *sp, real_T a[9], int32_T ilo, int32_T ihi,
             real_T tau[2]);
