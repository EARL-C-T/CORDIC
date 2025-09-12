#ifndef CORDIC_H_
#define CORDIC_H_

#include <stdio.h>
#include <stdlib.h>

#include "fixpnt.h"


struct fix_sine_cosine{
	int Q ;
	fix sin_aprox ;
	fix cos_aprox ;
	fix angle_aprox ;
	fix angle_true ;
	fix angle_dif ;
	float angle_rad ;
};

typedef struct fix_sine_cosine fsc ;


#define HAV_PI 1647313 
#define FULL_PI 3294626 
 
 
 
int CORDIC_Q( fix ang ) ;

fsc* CORDIC_fsc( float angle_rad );

//prints the sin cos and angle etc in float form this also frees the struct
void print_rsc( fsc* sc );e

extern fix le_k[11] ;
extern int le_shift[11] ;
#endif /*CORDIC_H_*/
