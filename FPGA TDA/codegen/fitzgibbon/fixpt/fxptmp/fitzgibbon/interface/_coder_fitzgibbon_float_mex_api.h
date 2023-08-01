#pragma once

#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void customFetchLoggedData_api(int32_T nlhs, const mxArray *plhs[4]);

void fitzgibbon_api(const mxArray *const prhs[2], const mxArray **plhs);

void forcePushIntoCloud_api(void);

void logStmts_api(void);
