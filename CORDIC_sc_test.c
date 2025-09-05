#include "CORDIC.h"

int main(){

	fsc* a = CORDIC_fsc( 0.681 ) ;


	fsc* b = CORDIC_fsc( 1.082 ) ;


	fsc* c = CORDIC_fsc( 0.384 ) ;

	printf("a sin 0.629 cos 0.777 \n") ;
	printf("sindiff %f \n cosdiff %f \n",0.629 - to_float(a -> sin_aprox), 0.777 - to_float(a ->cos_aprox));
	print_rsc( a ) ;

	printf(" b sin 0.883 cos 0.469 \n") ;
	printf("sindiff %f \n cosdiff %f \n",0.833 - to_float(b -> sin_aprox), 0.469 - to_float(b ->cos_aprox));
	print_rsc( b ) ;

	printf(" c sin 0.375  cos 0.927 \n") ;
	printf("sindiff %f \n cosdiff %f \n",0.374 - to_float(c -> sin_aprox), 0.927 - to_float(c ->cos_aprox));
	print_rsc( c ) ;
}
