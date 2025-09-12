#include "CORDIC.h"
#include "CORDIC_tbls.h"
//use this for when quadrent 3 and 4 are repsented by negitive angles
int CORDIC_Q( fix ang ){

	if( ang > 0 & ang < HAV_PI ) {
		return 1 ;
	}else if( ang > HAV_PI  & ang < FULL_PI  ) {
		return 2 ;
	}else if( ang > -FULL_PI & ang < -HAV_PI ) {
		return 3 ;
	}else if( ang > -HAV_PI & ang < 0 ){
		return 4 ;
	};

}

fsc* CORDIC_fsc( float angle_rad ){

	
	fsc* sc = ( fsc* ) malloc(sizeof(fsc)) ;

	fix angle_fix = to_fix( angle_rad );
	int Q = CORDIC_Q(angle_fix) ;
	fix x, y, z, ax, ay ;
	x = 642253 ;
	y = 0 ;
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
	sc -> Q = Q ;
	if(Q == 3 | Q == 1 ){
	sc -> cos_aprox = x * ax ;
	sc -> sin_aprox = y * ay ;
	}else{
	sc -> cos_aprox = y * ax ;
	sc -> sin_aprox = x * ay ;
}
	sc -> angle_true = angle_fix ;
	sc -> angle_rad = angle_rad ;
	sc -> angle_dif =  z ;

	return sc ;
};

void print_rsc ( fsc* sc ){

	printf("sin %f \n cos %f  \n angle_in %f \n", to_float( sc -> sin_aprox ), to_float( sc -> cos_aprox ),\
		 to_float( sc -> angle_true ) );
	free( sc );
	return ;
};
