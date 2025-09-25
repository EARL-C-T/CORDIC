/*
 * sincos_cordic.c
 *
 *  Created on: Sep 24, 2025
 *      Author: et
 * BENCHMARK TEST FOR SIN COS FUNCTION OF CORDIC LIB
 */

#include "../include/CORDIC.h"
#include <stdio.h>

int main(void){
fsc x=CORDIC_fscx(1363149 );
printf("%d    %d \n", x.sin_aprox, x.cos_aprox);
fsc y=CORDIC_fscx(1887437 );
printf("%d    %d \n", y.sin_aprox, y.cos_aprox);
fsc v=CORDIC_fscx(-1153434 );
printf("%d    %d \n", v.sin_aprox, v.cos_aprox);
fsc n=CORDIC_fscx(-3040871 );
printf("%d    %d \n", n.sin_aprox, n.cos_aprox);
return 0 ;
}