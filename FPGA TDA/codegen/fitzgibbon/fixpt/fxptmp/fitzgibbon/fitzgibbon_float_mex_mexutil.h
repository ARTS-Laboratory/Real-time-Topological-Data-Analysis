#pragma once

#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_T div_nde_s32_floor(int32_T numerator);

void emlrtInitVarDataTables(emlrtLocationLoggingDataType dataTables[26]);

const mxArray *emlrt_marshallOut(const real_T u);
