#pragma once

#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void b_warning(const emlrtStack *sp, const char_T varargin_1[14]);

void c_warning(const emlrtStack *sp);

void d_warning(const emlrtStack *sp);

void warning(const emlrtStack *sp);
