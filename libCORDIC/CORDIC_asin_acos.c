/*
 * CORDIC_asin_acos.c
 *
 *  Created on: Sep 17, 2025
 *      Author: et
 * while what i found on asin sugested a by loop application
 * of a scale factor to t i have found that I get more acuret
 * results from a stationary t and scaleing factor pre applied
 * to x basicly the same setup as regular sin cos and at least 
 * the test i checked x it was within .03 of the cos value of 
 * the origanal angle so i strongly belive that the scaleing 
 * factor applied to t as recomended by cited publication to
 * be unessary 
 * Paz, P., & Garrido, M. (2009, November 10). CORDIC-Based Computation of Arcsine and Arccosine Functions on FPGA. https://oa.upm.es/87123/3/CORDIC-Based_Computation_of_Arcsine_and_Arccosine_Functions_on_FPGA.pdf This article has been accepted for publication in IEEE Transactions on Circuits and Systems--II: Express Briefs. This is the author's version which has not been fully edited and
 * content may change prior to final publication. Citation information: DOI 10.1109/TCSII.2023.3262353 
 * NOTE CORDIC_acosx AND LIKEWISE acos  CHECKS THE INPUT BECAUSE IF NEGITIVE THEN
 * THE ANGLE FALLS IN THE SECOND QUARTER AND IS THE SAME AS RESULT AS ASIN(ABS(INPUT))+PI/2
 * THIS CHECK ALSO CAUSES 0 TO BE RETURNED IF INPUT GOSE OUT OF -1 - 1 RANGE NEGITIVE INPUT 
 * TO ASIN ONLY MEANS THIRD QUARTER SO OUTPUT IS THE SAME JUST NEGITIVE AND THERFORE THERE 
 * IS NOT CURENTLY A CHECK ON ITS INPUT
 */

#include "../include/CORDIC.h"
#include "../include/CORDIC_tbls.h"
// currently asin seems to work +-0.02 acos works up to
// somewhere round .6-.7 some kind of overflow I think at least
// output is -1.7432

fix CORDIC_asinx(fix sin_ang){
	fix x,nx, y, ny, z, t; 
		t =sin_ang ;
		x= 0x9cccd ;
		y = 0 ;
		z = 0 ;
	for(int i=0 ; i < 20 ;i++){
		if(y < t){
			ny = y + (x>>i);
			nx = x - (y>>i);
			z += atanz[i];
		}else {
			nx = x + (y>>i);
			ny = y - (x>>i);
			z -= atanz[i];
			}
		y=ny;
		x=nx;
		}
	return z;
}

float CORDIC_asin( float ex ){
	return to_float(CORDIC_asinx(to_fix(ex)));
}

fix CORDIC_acosx(fix cos_ang){
	fix x,nx, y, ny, z;
	if( cos_ang > 0 ){
		x = cos_ang;
		y = 0 ;
		z = 0 ;
		for(int i=0 ; i < 20 ;i++){
			if(x > 0){
				ny = y + (x>>i);
				nx = x -(y>>i);
				z += atanz[i];
			
			}else if(x<0){
				ny = y - (x>>i);
				nx = x + (y>>i);
				z -= atanz[i];
				
			}else if(x==0){
				return HAV_PI-z;
			}
					
				
			printf("x %d y %d z %d \n",nx,ny,z);
			y=ny;
			x=nx;
			}
		return HAV_PI -z;
	}else if( cos_ang < 0 && cos_ang > -FIX_ONE ){
		return HAV_PI + CORDIC_asinx(cos_ang);

}else{
	return 000000000000 ;}

	}
	
float CORDIC_acos( float ex ){
	return to_float(CORDIC_acosx(to_fix(ex)));

	}
