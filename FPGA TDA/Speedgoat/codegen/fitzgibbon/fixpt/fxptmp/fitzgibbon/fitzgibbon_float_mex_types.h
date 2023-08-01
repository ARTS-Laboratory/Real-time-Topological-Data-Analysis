#pragma once

#include "rtwtypes.h"
#include "emlrt.h"

#ifndef struct_emxArray_char_T_1x7
#define struct_emxArray_char_T_1x7
struct emxArray_char_T_1x7 {
  char_T data[7];
  int32_T size[2];
};
#endif
#ifndef typedef_emxArray_char_T_1x7
#define typedef_emxArray_char_T_1x7
typedef struct emxArray_char_T_1x7 emxArray_char_T_1x7;
#endif

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  uint32_T ActualIndex;
  emxArray_char_T_1x7 FieldNames;
} struct1_T;
#endif

#ifndef typedef_emxArray_struct1_T_1x6
#define typedef_emxArray_struct1_T_1x6
typedef struct {
  struct1_T data[6];
  int32_T size[2];
} emxArray_struct1_T_1x6;
#endif

#ifndef struct_emxArray_char_T_1x6
#define struct_emxArray_char_T_1x6
struct emxArray_char_T_1x6 {
  char_T data[6];
  int32_T size[2];
};
#endif
#ifndef typedef_emxArray_char_T_1x6
#define typedef_emxArray_char_T_1x6
typedef struct emxArray_char_T_1x6 emxArray_char_T_1x6;
#endif

#ifndef struct_emxArray_real_T_1x2
#define struct_emxArray_real_T_1x2
struct emxArray_real_T_1x2 {
  real_T data[2];
  int32_T size[2];
};
#endif
#ifndef typedef_emxArray_real_T_1x2
#define typedef_emxArray_real_T_1x2
typedef struct emxArray_real_T_1x2 emxArray_real_T_1x2;
#endif

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T
struct emxArray_uint8_T {
  uint8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif
#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T
typedef struct emxArray_uint8_T emxArray_uint8_T;
#endif

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T {
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif

#ifndef struct_emxArray_char_T_1x0
#define struct_emxArray_char_T_1x0
struct emxArray_char_T_1x0 {
  int32_T size[2];
};
#endif
#ifndef typedef_emxArray_char_T_1x0
#define typedef_emxArray_char_T_1x0
typedef struct emxArray_char_T_1x0 emxArray_char_T_1x0;
#endif

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  emxArray_char_T_1x6 Class;
  emxArray_real_T_1x2 Dims;
  boolean_T Varsize;
  emxArray_char_T_1x0 NumericType;
  emxArray_char_T_1x0 Fimath;
  emxArray_uint8_T *Data;
  uint32_T DataSize;
} struct0_T;
#endif

#ifndef typedef_emxArray_struct0_T
#define typedef_emxArray_struct0_T
typedef struct {
  struct0_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_struct0_T;
#endif
