
#include <stdio.h>
#include <stdlib.h>

#include "../include/fixpnt.h"

int main( int argc, char* argv[] ){
	float fl = atof( argv[1] ) ;
	printf( "%d \n", to_fix( fl ) ) ;
	return 0 ;
}
