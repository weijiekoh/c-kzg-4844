#include "eip4844/eip4844.h"
#include "common/alloc.h"
#include "common/ec.h"
#include "common/fr.h"
#include "common/lincomb.h"
#include "common/ret.h"
#include "common/utils.h"
#include "setup/settings.h"
#include "blst.h"

#include <assert.h> /* For assert */
#include <stdlib.h> /* For NULL */
#include <string.h> /* For memcpy & strlen */

void gen_scalar(blst_scalar *out, const byte a[32]) {
    blst_scalar_from_lendian(out, a);
}

void g1_gen_mul(blst_p1 *out_pk, const blst_scalar *SK) {
    blst_sk_to_pk_in_g1(out_pk, SK);
}

void g1_double(blst_p1 *out, const blst_p1 *a) {
    blst_p1_double(out, a);
}

// Function to benchmark
C_KZG_RET do_kzg(g1_t *out, const g1_t *points, const fr_t *coeffs, size_t len) {
    return g1_lincomb_fast(out, points, coeffs, len);
}

