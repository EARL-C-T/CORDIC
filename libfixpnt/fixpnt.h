#ifndef FIXPNT_H_
#define FIXPNT_H_

#include <bits/stdint-intn.h>
#include <math.h>

#define FIX_SHIFT 20

//im gonna have to get back to this but real quick limits check
#define MAX_FLOAT 0x44ffffae //2047.98999
#define MIN_FLOAT 0xc4ffffae //-2047.98999
typedef int32_t  fix ;

float float_bitshift( float F, int S ) ;//negitive S shifts >> positive <<

fix fix_bitshift( fix F, int S ) ;//same

//seems like done  this way .999 is always rounded need  to test more
#define FIX_ONE 1048576



int flt_limit( float flt_pnt ) ;

fix to_fix( float flt_pnt ) ; 

float to_float( fix fix_pnt ) ;

#define FIX_MAX to_fix( MAX_FLOAT )
#define FIX_MIN to_fix( MIN_FLOAT )

fix add_check( fix A, fix B ) ;

fix sub_check( fix A, fix B ) ;
//fix fix_div( fix dividen, fix divisor ) ;

fix fix_mult(fix A,fix B);

#endif /*FIXPNT_H_*/
