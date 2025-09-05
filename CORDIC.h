#ifndef CORDIC_H_
#define CORDIC_H_

#include <stdio.h>
#include <stdlib.h>

#include "fixpnt.h"


struct fix_sine_cosine{
	fix sin_aprox ;
	fix cos_aprox ;
	fix angle_aprox ;
	fix angle_true ;
	fix angle_dif ;
	float angle_rad ;
};

typedef struct fix_sine_cosine fsc ;

fsc* CORDIC_fsc( float angle_rad );

//prints the sin cos and angle etc in float form this also frees the struct
void print_rsc( fsc* sc );

#endif /*CORDIC_H_*/
