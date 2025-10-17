/*logarithm.h
 * EARL T [ET]
 * a method of fixpoint divison and multiplication that has no issue
 * scaling
 */
#ifndef LOGARITHM_H_
#define LOGARITHM_H_

#include "CORDIC.h"

#ifndef LOGX
#define LOGX(x) ((lfix)CORDIC_logx(x)) // you can change this to
// another log function but the end resault has to be log(x)<<SHIFT_VAL not
// log(x<<SHIFT_VAL)cast to lfix
#endif /*LOGX*/

#ifndef EXPX
#define EXPX(x) ((fix)CORDIC_exp(x)) // any exp function of the same base as the
// log can likewise be used but must work in a way that result is
// exp(x>>SHIFT_VAL)<<SHIFT_VAL the cordic method dose this natrualy basicly
// exp(logfix)=exp(log)<<fixed cast to fix
#endif /*EXPX*/

typedef fix lfix;
/*the format for nameing is as follows log_ then format letter l:
 * l:lfix input lfix output
 * f: fix input fix output
 * n: lfix input fix output
 * w: fix input lfix output
 * lfix is the log of x bit shifted by shift val whitch in this system
 * is 20 this can be acompished a couple of ways this system uses
 * hyperbolic cordic algorythm as of right now this implimetion has a
 * very limited range incressing it in any way apears to to be trival
 * althou it may decrease acuracy some for larger shifts but in the
 * range of log 0.1 - 255 the acurcy seems fairly good roughly +/-0.01
 * makeing the range larger however may detrmentaly affect this also
 * the modifications scale the number to the range adds complexity
 * there by slower excution i may bwrite a version with no scaleing im
 * going to check into it more lfnw are being used for prefixes because
 * they are very distingushable from each other the diffrent varitys
 * are a convince the l functions are the simplisest and have no log or
 * exp calls f have the most i may add addition ad subtraction
 * functions that work in the reverse manner also for convinonce
 */
inline lfix lto_lfix(fix x) { return LOGX(x); }
inline fix lto_fix(lfix x) { return EXPX(x); }

inline lfix log_ldiv(lfix A, lfix B) { return A - B; } // returns the log of A/B
inline fix log_fdiv(fix A, fix B) {
  return EXPX(LOGX(A) - LOGX(B));
} /*this may seem abtrary but i am useing macro instead of the
   * function because the overhead of the function call is justified by
   * the type check so lfix and fix are not confused but since the
   * surounding function is checking the type use of the macro should
   * be quicker if by fractions of nano seconds
   */
inline lfix log_wdiv(fix A, fix B) { return LOGX(A) - LOGX(B); }
inline fix log_ndiv(lfix A, lfix B) { return EXPX(A - B); }

inline lfix log_lmult(lfix A, lfix B) { return A + B; } // returns the log of
// A*B
inline fix log_fmult(fix A, fix B) { return EXPX(LOGX(A) + LOGX(B)); }
inline lfix log_wmult(fix A, fix B) { return LOGX(A) + LOGX(B); }
inline fix log_nmult(lfix A, lfix B) { return EXPX(A + B); }
// honestly I dont know if there is a good reson for the extra parenthises
// these take logfix return fix

inline lfix log_lsq(lfix A) { return A << 1; }
inline fix log_fsq(fix A) { return EXPX(LOGX(A) << 1); }
inline lfix log_wsq(fix A) { return LOGX(A) << 1; }
inline fix log_nsq(lfix A) { return EXPX(A + A); }

inline lfix log_lsqrt(lfix A) { return A >> 1; }
inline fix log_fsqrt(fix A) { return EXPX(LOGX(A) >> 1); }
inline lfix log_wsqrt(fix A) { return LOGX(A) >> 1; }
inline fix log_sqrt(lfix A) { return EXPX((A >> 1)); }

#endif /*LOGARITHM_H_*/
