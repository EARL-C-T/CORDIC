#include "fixpnt.h"


int flt_limit( float flt_pnt ){
	if(flt_pnt < MAX_FLOAT && flt_pnt > MIN_FLOAT ){
		return 0;
	}else{
		return 1;
	};
};

fix to_fix( float flt_pnt ) {

	fix fx = (int) round(flt_pnt * ( 1 << FIX_SHIFT )) ;

	return fx ;

};

float to_float( fix fix_pnt ) {

	float flt = (float)fix_pnt / (float) (1 << FIX_SHIFT) ;

	return flt ;

};



fix add_check( fix A, fix B){
	if ( FIX_MAX < A + B && FIX_MIN > A + B  ){
		return A + B ;
	}else{
		return -0 ;
	}
};

fix sub_check( fix A, fix B){
	if ( FIX_MAX < A - B && FIX_MIN > A - B){
		return A-B ;
	}else{
		return -0 ;
	}
}
fix fix_mult(fix A,fix B){
	A=A/1<<10;
	B=B/1<<10;
	return A*B;
}
