#ifndef CORDIC_H_
#define CORDIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "fixpnt.h"

//quick version of sin cos expects the input to be in fix format and to be in the first quadrent


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

fsc CORDIC_fsc( float fang);

fsc CORDIC_fscx( fix ang );

fix CORDIC_logx( fix x );

float CORDIC_log( float ex ) ;

fix CORDIC_expx( fix x ) ;

float CORDIC_exp( float ex ) ;

float CORDIC_sq( float ex ) ;

fix CORDIC_sqx( fix x ) ;

float CORDIC_sqrt( float ex ) ;

fix CORDIC_sqrtx( fix x ) ;

fix  CORDIC_asinx( fix sin_ang ) ;

float CORDIC_asin( float ex ) ;

fix CORDIC_acosx( fix cos_ang ) ;

float CORDIC_acos( float ex ) ;

#endif /*CORDIC_H_*/

