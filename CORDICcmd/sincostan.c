#include "../libCORDIC/CORDIC.h"
#include <fixpnt.h>
#include <stdlib.h>
#include <stdio.h>

int main( int argc, char** argv ){
	fsc* r =  CORDIC_fsc(atof(argv[1]));
	float sin, cos, tan;
	sin = to_float( r -> sin_aprox );
	cos = to_float( r -> cos_aprox );
	tan = sin/cos ;
	printf("SIN: %f \n COS: %f \n TAN: %f \n ",sin ,cos,tan  );

}