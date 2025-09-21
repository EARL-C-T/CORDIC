#include "CORDIC.h"
#include "CORDIC_tbls.h"

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
	}else if( ang < 0 && ang <= -HAV_PI ) {
		return 3 ;
	}else if( ang < -HAV_PI && ang >= -FULL_PI ){
		return 4 ;
	};
	printf("ERROR Q NOT FOUND\n");
	return -0;

}

fsc CORDIC_fsc( float angle_rad ){



	fix angle_fix = to_fix( angle_rad );
	int Q = CORDIC_Q(angle_fix) ;
	fix x, y, z, ax, ay ;
	x = 0x9cccd ;
	y = 0 ;
	z = 0 ;
	ax = 1 ;
	ay = 1 ;
	switch( Q ) {
	case 1:
		ax = 1 ;
		ay = 1 ;
		z = angle_fix ;
		break ;
	case 2:
		ax =-1 ;
		ay =1 ;
		z = angle_fix - HAV_PI ;
		break ;
	case 3:
		ax = -1 ;
		ay = -1 ;
		z = angle_fix + FULL_PI ;
		break ;
	case 4:
		ax = 1 ;
		ay = -1 ;
		z = angle_fix + HAV_PI ;
		break ;
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
 fsc  sc ;
	sc.Q = Q ;
	if(Q == 3 || Q == 1 ){
	sc.cos_aprox = x * ax ;
	sc.sin_aprox = y * ay ;
	}else{
	sc.cos_aprox = y * ax ;
	sc.sin_aprox = x * ay ;
}
	sc.angle_true = angle_fix ;
	sc.angle_rad = angle_rad ;
	sc.angle_dif =  z ;

	return sc ;
};
//this expects that the angle be in the fisrt quadrent so 0 to Pi it also
//the angle to be entered in fix format
quiksc  quicksc( fix ang ){


	fix x, y, z;

	x = 0x9cccd ;
	y = 0 ;
	z = ang;

	for( int i = 0; i < 21 ; i++ ){
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
	quiksc sc;
	sc.ang = ang;
	sc.sin_aprox = y ;
	sc.cos_aprox = x ;
	sc.tan_aprox = y/x ;
	return sc ;
}


void print_rsc ( fsc* sc ){

	printf("sin %f \n cos %f  \n angle_in %f \n", to_float( sc -> sin_aprox ), to_float( sc -> cos_aprox ),\
		 to_float( sc -> angle_true ) );
	free( sc );
	return ;
};
