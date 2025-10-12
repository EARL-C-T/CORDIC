/*
 * sincos_cordic.c
 *
 *  Created on: Sep 24, 2025
 *      Author: et
 * BENCHMARK TEST FOR SIN COS FUNCTION OF CORDIC LIB
 */

#include "../include/CORDIC.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
int main(void){
	clock_t c_start=clock();
	fsc x=CORDIC_fscx(1363149 );
	fsc y=CORDIC_fscx(1887437 );
	fsc v=CORDIC_fscx(3460300 );
	fsc n=CORDIC_fscx(4718592 );
	clock_t c_end =clock(); 
	printf("TIME CORDIC: %f \n",(double)(c_end-c_start)/CLOCKS_PER_SEC);
	printf("%f    %f \n", to_float(x.sin_aprox),to_float(x.cos_aprox));
	printf("%f    %f \n", to_float(y.sin_aprox),to_float(y.cos_aprox));
	printf("%f    %f \n", to_float(v.sin_aprox), to_float(v.cos_aprox));
	printf("%f    %f \n", to_float(n.sin_aprox), to_float(n.cos_aprox));
	clock_t m_start=clock();
	float xs = sinf(1.3 );
	float xc = cosf(1.3 );
	float ys = sinf(1.8 );
	float yc = cosf(1.8 );
	float vs = sinf(3.3 );
	float vc = cosf(3.3 );
	float ns = sinf( 4.5 );
	float nc = cosf(4.5 );
	clock_t m_end=clock();
	printf("TIME MATH: %f \n",(double)(m_end - m_start)/CLOCKS_PER_SEC);
	printf("%f    %f \n", xs, xc);
	printf("%f    %f \n", ys, yc);
	printf("%f    %f \n", vs, vc);
	printf("%f    %f \n", ns, nc);
	clock_t start_c=clock();
	int c_count=0;
	fsc cordic;
	while(clock()<start_c+CLOCKS_PER_SEC){
		cordic =CORDIC_fscx(FIX_ONE);
		c_count++;
	}
	printf("CORDIC SIN: %f COS: %f \n 1 SEC EXCUTION COUNT: %d \n", to_float(cordic.sin_aprox), to_float(cordic.cos_aprox),c_count); 
	clock_t start_m=clock();
	int m_count=0;
	float sin_m,cos_m ;
	while(clock()<start_m+CLOCKS_PER_SEC){
		sin_m=sinf(1.0);
		cos_m=cosf(1.0);
		m_count++;
	}
	printf("MATH SIN: %f COS: %f \n 1 SEC EXCUTION COUNT: %d \n", sin_m, cos_m, m_count);
	return 0;
}
