#include "CORDIC.h"
#include "fixpnt.h"
#include "CORDIC_tbls.h"

const int le_shift[11]={
	8,//<<8
	4,//<<4
	2,//<<2
	1,//<<1
	-1,//y+y>>1
	-2,//y+y>>2
	-3,//y+y>>3
	-4,//y+y>>4
	-5,//y+y>>5
	-6,//y+y>>6
	-7,//y+y>>7
	} ;

const fix kz[11]={
	5814564 ,//5.5452
	2907282 ,//2.7726
	1453641 ,//1.3863
	726768 ,//0.6931
	425198 ,//0.4055
	233937 ,//0.2231
	123522 ,//0.1178
	63544 ,//0.0606
	32296 ,//0.0308
	16253 ,//0.0155
	8179 //0.0078
   };

fix k_shift(fix target, int shift ){
	fix t1, t2 ;
	t1 = target ;
	t2 = target ;
	if ( 0 < shift ){
		target = t1 << shift ;
	}else{
		target  = t2 + ( t1 >> -shift ) ;
	} ;
	return target ;
}

fix CORDIC_exp( float ex ) {
	fix y = FIX_ONE ;
	fix x ;
	x = to_fix(ex);
	for(int i=0 ; i<K_LEN; i++) {
		if ( x > kz[i] ) {
			x = x - kz[i];
			y = k_shift(y,le_shift[i]);
		}
			};
		return y ;
}

fix CORDIC_log( float ex ) {
	fix y = 0x58b924; //tmp float 246
	fix x = to_fix(ex)>>8 ; //this is tmp i belive but should work floats to 264
	for(int i=0;i<K_LEN;i++){
		fix xx ;
		 xx = k_shift( x, le_shift[i]);
		if( xx < FIX_ONE ){
			x=xx ;
			y -=kz[i] ;
		}
}
	 y-=x>>15;
	return y;
}
double to_dbl(dblfix fx){
	double dbl =(double)fx/(1<<20);
	return dbl;
}
dblfix to_dfix(float fl){
	dblfix dfx=(dblfix)fl*(1<<20);
	return dfx;
}

dblfix CORDIC_dblexp(float ex){
	dblfix y = FIX_ONE ;
	dblfix x ;
	x = to_dfix(ex);
		for(int i=0 ; i<K_LEN; i++) {
			if ( x > kz[i] ) {
				x = x - kz[i];
				y = k_shift(y,le_shift[i]);
		}
															
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																			
			printf("x %ld y %ld  %d  %d \n" ,x ,y,kz[i],le_shift[i] );
		}
			return y ;
	}

