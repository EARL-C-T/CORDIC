#include "CORDIC.h"

int main(){

	fsc* a = CORDIC_fsc( 0.681 ) ;


	fsc* b = CORDIC_fsc( 1.082 ) ;


	fsc* c = CORDIC_fsc( 0.384 ) ;

	fsc* q_two = CORDIC_fsc(2.356 ) ;

	fsc* q_three = CORDIC_fsc(-0.569 ) ;

	fsc* q_four = CORDIC_fsc( -2.678 ) ;

	printf("a sin 0.629 cos 0.777 \n") ;
	printf("sindiff %f \n cosdiff %f \n",0.629 - to_float(a -> sin_aprox), 0.777 - to_float(a ->cos_aprox));
	print_rsc( a ) ;

	printf(" b sin 0.883 cos 0.469 \n") ;
	printf("sindiff %f \n cosdiff %f \n",0.833 - to_float(b -> sin_aprox), 0.469 - to_float(b ->cos_aprox));
	print_rsc( b ) ;

	printf(" c sin 0.375  cos 0.927 \n") ;
	printf("sindiff %f \n cosdiff %f \n",0.374 - to_float(c -> sin_aprox), 0.927 - to_float(c ->cos_aprox));
	print_rsc( c ) ;
	
	printf(" q_two sin 0.707  cos -0.707 \n") ;
	printf("sindiff %f \n cosdiff %f \n",0.707 - to_float(q_two -> sin_aprox), -0.707 - to_float(q_two ->cos_aprox));
	print_rsc( q_two ) ;

	printf(" q_three sin -0.539  cos 0.842 \n") ;
	printf("sindiff %f \n cosdiff %f \n",-0.539 - to_float(q_three -> sin_aprox), 0.842 - to_float(q_three ->cos_aprox));
	print_rsc( q_three ) ;	

	printf(" q_four sin -0.447  cos -0.894 \n") ;
	printf("sindiff %f \n cosdiff %f \n",-0.447 - to_float(q_four -> sin_aprox), -0.894 - to_float(q_four ->cos_aprox));
	print_rsc( q_four ) ;
return 0 ;
}