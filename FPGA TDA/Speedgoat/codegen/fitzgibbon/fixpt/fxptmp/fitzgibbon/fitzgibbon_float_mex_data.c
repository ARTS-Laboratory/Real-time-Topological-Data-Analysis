#include "fitzgibbon_float_mex_data.h"
#include "rt_nonfinite.h"

emlrtLocationLoggingDataType emlrtLocationLoggingDataTables[26];

emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,
    false,
    131642U,
    NULL,
    "fitzgibbon_float_mex",
    NULL,
    false,
    {2045744189U, 2170104910U, 2743257031U, 4284093946U},
    NULL};

emlrtRSInfo p_emlrtRSI = {20, "eml_int_forloop_overflow_check",
                          "C:\\Program "
                          "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\em"
                          "l\\eml_int_forloop_overflow_check.m"};

emlrtRSInfo wb_emlrtRSI = {75, "xzlarf",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+reflapack\\xzlarf.m"};

emlrtRSInfo xb_emlrtRSI = {68, "xzlarf",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+reflapack\\xzlarf.m"};

emlrtRSInfo yb_emlrtRSI = {50, "xzlarf",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+reflapack\\xzlarf.m"};

emlrtRSInfo bc_emlrtRSI = {64, "xgemv",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+blas\\xgemv.m"};

emlrtRSInfo cc_emlrtRSI = {74, "xgemv",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+refblas\\xgemv.m"};

emlrtRSInfo dc_emlrtRSI = {37, "xgemv",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+refblas\\xgemv.m"};

emlrtRSInfo uc_emlrtRSI = {46, "xzgehrd",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+reflapack\\xzgehrd.m"};

emlrtRSInfo vc_emlrtRSI = {50, "xzgehrd",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+reflapack\\xzgehrd.m"};

emlrtRSInfo wc_emlrtRSI = {58, "xzgehrd",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+reflapack\\xzgehrd.m"};

emlrtRSInfo xc_emlrtRSI = {84, "xzlarf",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+reflapack\\xzlarf.m"};

emlrtRSInfo yc_emlrtRSI = {91, "xzlarf",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+reflapack\\xzlarf.m"};

emlrtRSInfo nd_emlrtRSI = {349, "xdlahqr",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+reflapack\\xdlahqr.m"};

emlrtRSInfo od_emlrtRSI = {345, "xdlahqr",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+reflapack\\xdlahqr.m"};

emlrtRSInfo pd_emlrtRSI = {342, "xdlahqr",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+reflapack\\xdlahqr.m"};

emlrtRSInfo uf_emlrtRSI = {30, "xswap",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+blas\\xswap.m"};

emlrtRSInfo vf_emlrtRSI = {20, "xswap",
                           "C:\\Program "
                           "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
                           "internal\\+refblas\\xswap.m"};

emlrtRSInfo yg_emlrtRSI = {
    28, "repmat",
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"};

emlrtRTEInfo f_emlrtRTEI = {58, 23, "assertValidSizeArg",
                            "C:\\Program "
                            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+"
                            "coder\\+internal\\assertValidSizeArg.m"};

covrtInstance emlrtCoverageInstance;
