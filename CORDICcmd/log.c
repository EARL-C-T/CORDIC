#include "../libCORDIC/CORDIC.h"
#include <fixpnt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv ){
	float ex = strtod( argv[1],NULL ) ;
	fix log = CORDIC_log( ex ) ;
	printf( "log %f", to_float(log) ) ;
	return 0 ;
}
