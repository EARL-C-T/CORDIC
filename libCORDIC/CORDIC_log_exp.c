#include "CORDIC.h"
#include "fixpnt.h"

float k_shift(float target, int shift ){
	if (0< shift){
		target = target<< shift ;
	}else{
		target  = target +( target >> shift ) ;
	} ;
	return target ;
}

float CORDIC_exp( float ex ){
	float y = 1 ;
	fix x ;
	int i = 0 ;
	x = to_fix(ex);
	while(x > 0){
		if ( x > kz[i] ){
			x = x - kz[i];
			y = k_shift(y,le_shift[i]);
		}else{
			if (i < K_LEN - 1){
				i++
			}else{
				x=0 ;

			}
	}
		printf("x %d y %f \n" ,x ,y );
			};
		return y ;
}
