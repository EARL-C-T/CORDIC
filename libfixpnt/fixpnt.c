#include "fixpnt.h"


int flt_limit( float flt_pnt ){
	if (flt_pnt < MAX_FLOAT && flt_pnt > MIN_FLOAT) {
		return 0;
	} else {
		return 1;
	};
};

fix to_fix( float flt_pnt ) {

	fix fx = (fix)(flt_pnt * ( 1 << FIX_SHIFT )) ;

	return fx ;

};

float to_float( fix fix_pnt ) {

	float flt = (float)fix_pnt / (float) (1 << FIX_SHIFT) ;
	return flt ;

};

// this is gonna be slower the regular addition use only when overflow or underflow is likely in case of overflow 
//there is wrap around so over and under both are checked same for sub check 

fix add_check( fix A, fix B){
	fix R = A+B;
	if ( FIX_MAX < R && FIX_MIN > R  ){
		return R ;
	}else{
		return -0 ;
	}
}

//A - B
//this is add with overflow basicly ads to fix into a dbl fix bit shift stays the same shouldn,t be to
//much slower then just adding it is a function call and overhead with that 

dblfix ovr_add( fix A, fix B ){
	dblfix R =(dblfix) A + B ;	
	return R ;
}

fix sub_check( fix A, fix B){
	fix R = A - B ;
	if ( FIX_MAX < R && FIX_MIN > R ){
		return R ;
	}else{
		return -0 ;
	}
}

dblfix ovr_sub(fix A, fix B){
	dblfix R =(dblfix) A - B;
	return R ;
}

fix fix_mult(fix A, fix B){
	fix R = (A<<10)*(B<<10);
	return R;
}
//this shouldn't cause any over flow all thou i think there will be pecision loss in both mult functions 
fix fix_tri_mult( fix A, fix B, fix C ){
	fix R = ((A<<10)*(B<<10)<<10)*(C<<10);
	return R;

}

fix fix_div(fix A, fix B){
	float R =(float) A / B;
	return to_fix(R);
}