/*trig_ext.c
 * THIS IS AM EXTENTION TO MY libCORDIC that derives the other 4 trig ratios
 * idenitys from sin and cos also the log of each and fltrig fllog a struct with
 * all six and one with all six logs that is tan csc sec cot this may not be the
 * best show of logmetrics rlly it would probay do better with a hardware
 * log and exp implemention as I belive that they would be much simpler
 * and more compact then an fpu. it may beat at least some implienetions of
 * I need to do some tests for legit hardware stm avr mips ect
 */
#ifndef TRIG_EXT_H_
#define TRIG_EXT_H_

#include "CORDIC.h"
#include "logarithm.h"

typedef struct fulltrig {
  fix true_angle;
  fix sin_aprox;
  fix cos_aprox;
  fix tan_aprox;
  fix sec_aprox;
  fix csc_aprox;
  fix cot_aprox;
} fltrg;

typedef struct fulllog {
  lfix sin_log;
  lfix cos_log;
  lfix tan_log;
  lfix sec_log;
  lfix csc_log;
  lfix cot_log;
} fllog;

/* these next functions just produce the log of ratio in use the fixed log
 * addition is multiplication exp(logA +logB) == A * B likewaise exp( logA -
 * logB ) == A / B also logA+logA == logA^2 and as there isnt a problem whith
 * scaling when done this way logA+logB-logC+logD=logE | to_float(exp(logE))==E
 * same as A*B-C+D=E but scaling makes the second aproch dificult as
 * fixA*fixB=doublefixC so both over flow and the nessesity to shift back cause
 * issues and fixA/fixB=rounded(C) there are ways around that but they are trade
 * offs while log method seems fairly solid you must exp then to float only
 * other issue is for regular addition and subtraction you must exp out of log
 * this bt should work whith log to any base and matching exp b^x if anyones
 * intrested I'm gonna eventualy make a nice latex paper explaining as much of
 * the math and methods I can as i found very little open information that wasnt
 * part of some old class or presentation or paperwork on hardware implimations
 * that I at times found dificult to follow I have one question on logmetrics
 * should I make a new type that is just fixpoint log more so theres no
 * mistaking like this function input is for fixlog and this is for fix I dont
 * know I feelthat as akward as it may be and possibly semi useless I feel like
 * fix point benifits from logametrics
 */

inline fix trig_tanx(fsc sc) {
  return EXPX(LOGX(sc.sin_aprox) - LOGX(sc.cos_aprox));
}

inline fix trig_secx(fix cos) { return EXPX(0 - LOGX(cos)); }
inline fix trig_cscx(fix sin) { return EXPX(0 - LOGX(sin)); }
inline fix trig_cotx(fsc sc) {
  return EXPX(LOGX(sc.cos_aprox) - LOGX(sc.sin_aprox));
}
inline fltrg trig_fullx(fsc sc) {
  fltrg T;
  T.true_angle = sc.angle_true;
  T.sin_aprox = sc.sin_aprox;
  T.cos_aprox = sc.cos_aprox;
  lfix cl = LOGX(sc.cos_aprox);
  lfix sl = LOGX(sc.sin_aprox);
  T.tan_aprox = EXPX(sl - cl);
  T.cot_aprox = EXPX(cl - sl);
  T.sec_aprox = EXPX(0 - cl);
  T.csc_aprox = EXPX(0 - sl);
  return T;
}
inline lfix trig_log_tanx(fsc sc) {
  return LOGX(sc.sin_aprox) - LOGX(sc.cos_aprox);
}
inline lfix trig_log_secx(fix cos) { return 0 - LOGX(cos); }
inline lfix trig_log_cscx(fix sin) { return 0 - LOGX(sin); }
inline lfix trig_log_cotx(fsc sc) {
  return LOGX(sc.cos_aprox) - LOGX(sc.sin_aprox);
}
inline lfix trig_log_sinx(fix sin) { return LOGX(sin); }
inline lfix trig_log_cosx(fix cos) { return LOGX(cos); }
inline fllog trig_full_log(fsc sc) {
  fllog T;
  T.cos_log = LOGX(sc.cos_aprox);
  T.sin_log = LOGX(sc.sin_aprox);
  T.tan_log = T.sin_log - T.cos_log;
  T.cot_log = T.cos_log - T.sin_log;
  T.sec_log = 0 - T.cos_log;
  T.csc_log = 0 - T.sin_log;
  return T;
}
// next section is the log_ratiox and ratiox requireing fixed rad input they are
// a convinionce
inline fix trig_ang_tanx(fix ang) { return trig_tanx(CORDIC_fscx(ang)); }
inline lfix trig_ang_log_tanx(fix ang) {
  return trig_log_tanx(CORDIC_fscx(ang));
}
inline fix trig_ang_sinx(fix ang) {
  fsc sc = CORDIC_fscx(ang);
  return sc.sin_aprox;
}
inline lfix trig_ang_log_sinx(fix ang) { return LOGX(trig_ang_sinx(ang)); }

inline fix trig_ang_cosx(fix ang) {
  fsc sc = CORDIC_fscx(ang);
  return sc.cos_aprox;
}
inline lfix trig_ang_log_cosx(fix ang) { return LOGX(trig_ang_cosx(ang)); }
inline fix trig_ang_cotx(fix ang) { return trig_cotx(CORDIC_fscx(ang)); }
inline lfix trig_ang_log_cotx(fix ang) { return LOGX(trig_ang_cotx(ang)); }
inline fix trig_ang_secx(fix ang) {
  fsc sc = CORDIC_fscx(ang);
  return trig_secx(sc.cos_aprox);
}
inline lfix trig_ang_log_secx(fix ang) { return LOGX(trig_ang_secx(ang)); }
inline lfix trig_ang_cscx(fix ang) {
  fsc sc = CORDIC_fscx(ang);
  return trig_cscx(sc.sin_aprox);
}
inline lfix trig_ang_log_cscx(fix ang) { return LOGX(trig_ang_cscx(ang)); }
#endif /*TRIG_EXT_H_*/
