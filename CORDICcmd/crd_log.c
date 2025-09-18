#include "CORDIC.h"
#include "CORDIC_tbls.h"
#include <fixpnt.h>


int main(int argc, char** argv ){
	float ex = atof( argv[1] ) ;
	float log = CORDIC_log( ex ) ;
	printf( "log %f", log ) ;
	return 0 ;e
}
