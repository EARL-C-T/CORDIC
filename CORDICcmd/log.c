#include "../libCORDIC/CORDIC.h"
#include <fixpnt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv ){
	float ex = strtod( argv[1],NULL ) ;
	printf( "LOG: %f", CORDIC_log( ex ) ) ;
	return 0 ;
}
