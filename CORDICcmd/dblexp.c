
#include "../libCORDIC/CORDIC.h"
#include <fixpnt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	float x =strtod(argv[1],NULL);
	dblfix r = CORDIC_dblexp( x );
	printf("EXP: %f \n", to_dbl(r) );
	return 0;
};
