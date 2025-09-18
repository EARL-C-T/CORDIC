#ifndef CORDIC_H_
#define CORDIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "fixpnt.h"

struct quick_fix_sine_cosine{
	fix ang ;
	fix sin_aprox ;
	fix cos_aprox ;
	fix tan_aprox ;
};
typedef struct quick_fix_sine_cosine quiksc ;

//quick version of sin cos expects the input to be in fix format and to be in the first quadrent
quiksc* quicksc(fix ang);

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


#define HAV_PI 0x1922d1
#define FULL_PI 0x3245a2
 
 
 
int CORDIC_Q( fix ang ) ;

fsc* CORDIC_fsc( float angle_rad);

//prints the sin cos and angle etc in float form this also frees the struct
void print_rsc( fsc* sc );

fix CORDIC_log( float ex ) ;

typedef int64_t dblfix ;//trying this out

double to_dbl( dblfix fx );

dblfix to_dfix(float fl);

dblfix CORDIC_dblexp(float ex); //see if i can get a larger range since 8.3 is bullshit

fix CORDIC_exp( float ex ) ;

#endif /*CORDIC_H_*/

