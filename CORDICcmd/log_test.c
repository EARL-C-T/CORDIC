/*log_test.c
 *
 *EARL T [ET]
 *
 * test /demo for logarithm.c
 */
#include "../include/logarithm.h"
int main(void) {
  fix A = to_fix(1.2345);
  fix B = to_fix(2.5674);
  fix C = to_fix(5.2563);
  fix D = to_fix(10.245);

  fix DIV_AB = log_fdiv(A, B);
  fix MULT_CD = log_fmult(C, B);

  printf("A/B = %f real %f \n C/D = %f real %f \n", to_float(DIV_AB),
         to_float(A / B), to_float(MULT_CD), C / D);

  fix SQ_B = log_fsq(B);
  fix SQRT_D = log_fsqrt(D);

  printf("SQ_B = %f real %f \n SQRT_D = %f \n", to_float(SQ_B), to_float(B * B),
         to_float(SQRT_D));

  return 0;
}
