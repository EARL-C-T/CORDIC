#ifndef CORDIC_H_
#define CORDIC_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "fixpnt.h"

// quick version of sin cos expects the input to be in fix format and to be in
// the first quadrent

typedef struct fix_sine_cosine {
  int Q;
  fix sin_aprox;
  fix cos_aprox;
  fix angle_true;
} fsc;

typedef struct float_point_sine_cosine {
  float ftrue_angle;
  float fsin_aprox;
  float fcos_aprox;
} fltsc;

#define HAV_PI 1647313
#define FULL_PI 3294626
#define LOG_OF_16 2907270

fltsc CORDIC_fsc(float ex);

fsc CORDIC_fscx(fix ang);

fsc CORDIC_nfsc(
    fix ang); // for navigational use third and forth quarter are negitive

fix CORDIC_logx(fix x);

float CORDIC_log(float ex);

fix CORDIC_expx(fix x);

float CORDIC_exp(float ex);

float CORDIC_sq(float ex);

fix CORDIC_sqx(fix x);

float CORDIC_sqrt(float ex);

fix CORDIC_sqrtx(fix x);

fix CORDIC_asinx(fix sin_ang);

float CORDIC_asin(float ex);

fix CORDIC_acosx(fix cos_ang);

float CORDIC_acos(float ex);

#endif /*CORDIC_H_*/
