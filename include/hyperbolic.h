/* hyperbolic.c
 *
 * EARL T [ET]
 *
 * these are the hyperbolic functions cosh, sinh, tanh, coth, sech, and csch
 * from log exp this ones going to also be a header only libary
 */
#ifndef HYPERBOLIC_H_
#define HYPERBOLIC_H_

#include "CORDIC.h"
#include "logarithm.h"

#ifndef EXPX
#define EXPX(X) ((fix)CORDIC_expx(X))
#endif /*EXPX*/

#ifndef LOGX
#define LOGX(X) ((lfix)CORDIC_logx(X))
#endif /*LOGX*/

#define LOG_OF_TWO 726817
// if im going to use the same                                      \
  known number multiple times might as well hard code it

inline fix hyper_sinhx(fix A) {
  return EXPX(LOGX(EXPX(A) - EXPX(-A)) - LOG_OF_TWO);
}

inline lfix hyper_log_sinhx(fix A) {
  return LOGX(EXPX(A) - EXPX(-A)) - LOG_OF_TWO;
}

inline fix hyper_coshx(fix A) {
  return EXPX(LOGX(EXPX(A) + EXPX(-A)) - LOG_OF_TWO);
}

inline lfix hyper_log_coshx(fix A) {
  return LOGX(EXPX(A) + EXPX(-A)) - LOG_OF_TWO;
}

inline fix hyper_tanhx(fix A) {
  return EXPX(LOGX(EXPX(A) - EXPX(-A)) - LOGX(EXPX(A) + EXPX(-A)));
}

inline lfix hyper_log_tanhx(fix A) {
  return LOGX(EXPX(A) - EXPX(-A)) - LOGX(EXPX(A) + EXPX(-A));
}

inline fix hyper_cothx(fix A) {
  return EXPX(LOGX(EXPX(A) + EXPX(-A)) - LOGX(EXPX(A) - EXPX(-A)));
}

inline lfix hyper_log_cothx(fix A) {
  return LOGX(EXPX(A) + EXPX(-A)) - LOGX(EXPX(A) - EXPX(-A));
}

inline fix hyper_sechx(fix A) {
  return EXPX(LOG_OF_TWO - LOGX(EXPX(A) + EXPX(-A)));
}

inline lfix hyper_log_sechx(fix A) {
  return LOG_OF_TWO - LOGX(EXPX(A) + EXPX(-A));
}

inline fix hyper_cschx(fix A) {
  return EXPX(LOG_OF_TWO - LOGX(EXPX(A) + EXPX(-A)));
}

inline lfix hyper_log_cschx(fix A) {
  return LOG_OF_TWO - LOGX(EXPX(A) + EXPX(-A));
}

#endif /*HYPERBOLIC_H_*/
