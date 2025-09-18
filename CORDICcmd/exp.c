
#include "../libCORDIC/CORDIC.h"
#include <fixpnt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	float ang =strtod(argv[1],NULL);
	fix exp = CORDIC_exp( ang );
	printf("exp %f \n", to_float(exp) );
	return 0;
};
