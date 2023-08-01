#include "mtimes.h"
#include "fitzgibbon_float_mex_data.h"
#include "fitzgibbon_float_mex_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

void mtimes(const emxArray_real_T *A, const emxArray_real_T *B, real_T C[9])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  const real_T *A_data;
  const real_T *B_data;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  B_data = B->data;
  A_data = A->data;
  if ((A->size[0] == 0) || (B->size[0] == 0)) {
    memset(&C[0], 0, 9U * sizeof(real_T));
  } else {
    TRANSB1 = 'N';
    TRANSA1 = 'T';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)3;
    n_t = (ptrdiff_t)3;
    k_t = (ptrdiff_t)A->size[0];
    lda_t = (ptrdiff_t)A->size[0];
    ldb_t = (ptrdiff_t)B->size[0];
    ldc_t = (ptrdiff_t)3;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A_data[0],
          &lda_t, (real_T *)&B_data[0], &ldb_t, &beta1, &C[0], &ldc_t);
  }
}
