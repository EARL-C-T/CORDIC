
#include <stdio.h>
#include <stdlib.h>

#include <fixpnt.h>

int main( int argc, char* argv[] ){
	fix fx = atoi( argv[1] ) ;
	printf( "%f \n", to_float( fx ) ) ;
	return 0 ;
}
