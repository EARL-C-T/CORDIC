#include "CORDIC.h"

fsc* CORDIC_fsc( float angle_rad ){

	fix atanz[20] ={
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


	fsc* sc = ( fsc* ) malloc(sizeof(fsc)) ;

	fix angle_fix = to_fix( angle_rad );
	fix x = to_fix(0.61);
	fix y = 0 ;
	fix z = angle_fix ;

	for( int i = 0; i < 21 ; i++ ){
		fix new_x, new_y ;
		if( z < 0 ) {
			new_x = x +(y>>i) ;
			new_y = y- (x>>i) ;
			z += atanz[i] ;
		}else{

			new_x = x - (y>>i) ;
			new_y = y + (x>>i) ;
			z -= atanz[i] ;
		};

		x = new_x ;
		y = new_y ;

	};

	sc -> cos_aprox = x ;
	sc -> sin_aprox = y ;
	sc -> angle_true = angle_fix ;
	sc -> angle_rad = angle_rad ;
	sc -> angle_dif =  z ;

	return sc ;
};

void print_rsc ( fsc* sc ){

	printf("sin %f \n cos %f  \n angle_in %f \n dif %f \n", to_float( sc -> sin_aprox ), to_float( sc -> cos_aprox ),\
		 to_float( sc -> angle_true ), to_float( sc ->angle_dif ));
	free( sc );
	return ;
};
