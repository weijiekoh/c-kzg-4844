#pragma once

#include "common/ec.h"
#include "eip4844/eip4844.h"

void gen_scalar(blst_scalar *out, const byte a[32]);
void g1_gen_mul(blst_p1 *out_pk, const blst_scalar *SK);
void g1_double(blst_p1 *out_pk, const blst_p1 *a);

// Function to benchmark
C_KZG_RET do_kzg(g1_t *out, const g1_t *p, const fr_t *coeffs, size_t len);
