#pragma once

#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_T ilazlc(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[9],
               int32_T ia0);

void xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0, real_T tau,
            real_T C[9], int32_T ic0, real_T work[3]);
