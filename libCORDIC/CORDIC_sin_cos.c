#include "../include/CORDIC.h"
#include "../include/CORDIC_tbls.h"


//use this for when quadrent 3 and 4 are repsented by negitive angles
const fix atanz[20] ={
			823550, // 0.785398
			486170, // 0.463648
			256879, // 0.244979
			130396, // 0.124355
			65451, // 0.062419
			32757, // 0.031240
			16383, // 0.015624
			8192, // 0.007812
			4096, // 0.003906
			2048, // 0.001953
			1024, // 0.000977
			512, // 0.000488
			256, // 0.000244
			128, // 0.000122
			64, // 0.000061
			32, // 0.000031
			16, // 0.000015
			8, // 0.000008
			4, // 0.000004
			2
	};
int CORDIC_Q( fix ang ){

	if( ang >= 0 && ang < HAV_PI ) {
		return 1 ;
	}else if( ang >= HAV_PI  && ang <= FULL_PI  ) {
		return 2 ;
	}else if( ang < 0 && ang >= -HAV_PI ) {
		return 3 ;
	}else if( ang < -HAV_PI && ang >= -FULL_PI ){
		return 4 ;
	};
	printf("ERROR Q NOT FOUND\n ANGLE %d \n", ang);
	return -0;

}
fsc CORDIC_fsc( float fang ){
	fsc sc;
	fix ang = to_fix(fang );
	sc.angle_true = ang ;
	fix z;
	fix x = 642253 ;
	fix y = 0;
	int ac,as ;
	if( ang >= 0 && ang < HAV_PI ) {
		sc.Q = 1 ;
		z = ang ;
		as = 1 ;
		ac = 1 ;
	}else if( ang >= HAV_PI  && ang <= FULL_PI  ) {
		sc.Q = 2 ;
		z =ang - HAV_PI ;
		ac = -1 ;
		as = 1 ;

	}else if( ang < 0 && ang >= -HAV_PI ) {
		sc.Q = 4 ;
		z = ang + HAV_PI ;
		ac = 1 ;
		as = -1 ;
	}else if( ang < -HAV_PI && ang >= -FULL_PI ){
		sc.Q = 3 ;
		z = ang + FULL_PI ;
		ac = -1 ;
		as = -1 ;
	}else{
		printf("ERROR Q NOT FOUND\n ANGLE %d \n", ang);
		return sc;
	}
	for( int i = 0; i < 20 ; i++ ){
		fix new_x, new_y ;
		if( z < 0 ) {
			new_x = x + (y>>i) ;
			new_y = y - (x>>i) ;
			z += atanz[i] ;
		}else{

			new_x = x - (y>>i) ;
			new_y = y + (x>>i) ;
			z -= atanz[i] ;
		};

		x = new_x ;
		y = new_y ;

	};
	if(sc.Q == 3 || sc.Q == 1 ){
	sc.cos_aprox = x * ac ;
	sc.sin_aprox = y * as ;
	}else{
	sc.cos_aprox = y * ac ;
	sc.sin_aprox = x * as ;
}

	return sc ;
};
//if the error prints and sc is returned mostly un initilized then ang was outa range 
fsc CORDIC_fscx( fix ang ){
	fsc sc;
	sc.angle_true = ang ;
	fix z;
	fix x = 642253 ;
	fix y = 0;
	int ac,as ;
	if( ang >= 0 && ang < HAV_PI ) {
		sc.Q = 1 ;
		z = ang ;
		as = 1 ;
		ac = 1 ;
	}else if( ang >= HAV_PI  && ang <= FULL_PI  ) {
		sc.Q = 2 ;
		z =ang - HAV_PI ;
		ac = -1 ;
		as = 1 ;

	}else if( ang < 0 && ang >= -HAV_PI ) {
		sc.Q = 4 ;
		z = ang + HAV_PI ;
		ac = 1 ;
		as = -1 ;
	}else if( ang < -HAV_PI && ang >= -FULL_PI ){
		sc.Q = 3 ;
		z = ang + FULL_PI ;
		ac = -1 ;
		as = -1 ;
	}else{
		printf("ERROR Q NOT FOUND\n ANGLE %d \n", ang);
		return sc;
	}
	for( int i = 0; i < 20 ; i++ ){
		fix new_x, new_y ;
		if( z < 0 ) {
			new_x = x + (y>>i) ;
			new_y = y - (x>>i) ;
			z += atanz[i] ;
		}else{

			new_x = x - (y>>i) ;
			new_y = y + (x>>i) ;
			z -= atanz[i] ;
		};

		x = new_x ;
		y = new_y ;

	};
	if(sc.Q == 3 || sc.Q == 1 ){
	sc.cos_aprox = x * ac ;
	sc.sin_aprox = y * as ;
	}else{
	sc.cos_aprox = y * ac ;
	sc.sin_aprox = x * as ;
}

	return sc ;
};

