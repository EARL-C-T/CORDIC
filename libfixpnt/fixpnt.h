#ifndef FIXPNT_H_
#define FIXPNT_H_

#include <bits/stdint-intn.h>


#define FIX_SHIFT 20

//im gonna have to get back to this but real quick limits check
#define MAX_FLOAT 2047.9899999 //2047.98999
#define MIN_FLOAT -2047.9899999 //-2047.98999

typedef int32_t  fix ;
typedef int64_t  dblfix; // for over flows keep bishift the same for more decimal persition increesed
// bitshift should be used 40  or maybe 50 55 could even work for some use idk but figured id add it 

float float_bitshift( float F, int S ) ;//negitive S shifts >> positive <<

fix fix_bitshift( fix F, int S ) ;//same

//seems like done  this way .999 is always rounded need  to test more
#define FIX_ONE 1048576



int flt_limit( float flt_pnt ) ;

fix to_fix( float flt_pnt ) ; 

float to_float( fix fix_pnt ) ;

#define FIX_MAX 2147473057
#define FIX_MIN -2147473057

//checks to see if the resault is over or under flowed
fix add_check( fix A, fix B ) ;

fix sub_check( fix A, fix B ) ;

fix fix_mult(fix A,fix B);
//order of operations will be A times B times C
fix fix_tri_mult(fix A, fix B, fix C );
//A will be divded by B
fix fix_div(fix A, fix B );
#endif /*FIXPNT_H_*/
