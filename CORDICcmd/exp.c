
#include "../libCORDIC/CORDIC.h"
#include <fixpnt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	float ex =strtod(argv[1],NULL);
	printf("EXP: %f \n", CORDIC_exp(ex) );
	return 0;
};
