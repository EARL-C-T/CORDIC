#ifndef FIXPNT_H_
#define FIXPNT_H_

#include <stdint.h>


#define FIX_SHIFT 20

//im gonna have to get back to this but real quick limits check


typedef int32_t  fix ;
typedef int64_t  dblfix; // for over flows keep bishift the same for more decimal persition increesed
// bitshift should be used 40  or maybe 50 55 could even work for some use idk but figured id add it 

//seems like done  this way .999 is always rounded need  to test more
#define FIX_ONE 1048576
#define MAX_FLOAT 2047.9899999 //2047.98999
#define MIN_FLOAT -2047.9899999 //-2047.98999
#define FIX_MAX 2147473057
#define FIX_MIN -2147473057

//inline int flt_limit( float flt_pnt ) ;

inline fix to_fix( float flt_pnt ){ 
	return  (fix)(flt_pnt * ( 1 << FIX_SHIFT )) ;
}
inline float to_float( fix fix_pnt ) {
	return (float)fix_pnt / (float) (1 << FIX_SHIFT) ;
}
//checks to see if the resault is over or under flowed
inline fix add_check( fix A, fix B ){
	fix R = A + B ;
	if ( FIX_MAX < R && FIX_MIN > R  ){
		return R ;
	}else{
		return -0 ;
	}
}

inline fix sub_check( fix A, fix B ) {
fix R = A - B ;
	if ( FIX_MAX < R && FIX_MIN > R ){
		return R ;
	}else{
		return -0 ;
	}
}
inline fix fix_mult(fix A,fix B){
	return (A<<10)*(B<<10) ;
}
//order of operations will be A times B times C
inline fix fix_tri_mult(fix A, fix B, fix C ){
		return ((A<<10)*(B<<10)<<10)*(C<<10) ;
}
//A will be divded by B
inline fix fix_div(fix A, fix B ){
	 return to_fix( A / B);
}
#endif /*FIXPNT_H_*/
