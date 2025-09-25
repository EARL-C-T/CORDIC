#include "../include/CORDIC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* CORDIC_CAL
*
* BY EARL T {ET}
* 
* THIS IS THE NOVELTY CALCULATOR IVE MADE TO HAVE A X86_64 BASED TEST/DEMO THING ALSO
* IT'S KINDA FUN I JUST ADDED THE FLOAT RETURN SO IN THE FUTURE I CAN CHAIN  COMMANDS 
* CURENTLY IT JUST DISPLAYS THE RESULT I'VE GOT TO ADD BASIC FUNCTIONS AND FIGURE OUT 
* HOW TO HANDLE OVERFLOW UNDERFLOW AND A FEW OTHER THINGS TO MAKE THIS OF ANY USE ALSO
* FOR REAL FOR EASE OF USE BOTH INPUT AND OUTPUT OF ALL COMMANDS ARE IN FLOAT SO ITS
* RELITVLY INEFFICANT I HAVENT BENCHMARKED IT ALSO MANY OF THESE COMMANDS CURRENTLY 
* AS IVE SAID HAVE UNDELT WITH RANGE ISSUES BOTH ACURACY AND OVER / UNDER FLOWS ALSO
* SOME LIKE ACTUAL RANGE CHECKS THAT I HAVEN'T EVEN KINDA DELT WITH AND IN SOME CASES
* MAY NEVER DEAL WITH BUT REGARDLESS HERE YA GO   
*/
float callog(float x ){
	float r = CORDIC_log(x);
	printf( "LOG: %f \n", r ) ;
	return r ;
}
float calexp(float x){
	float r = CORDIC_exp(x) ;
	printf("EXP: %f \n", r ) ;
	return r ;
}
int calsct(float x ){
	fsc r =  CORDIC_fsc(x);
	float sin, cos, tan;
	sin = to_float( r.sin_aprox );
	cos = to_float( r.cos_aprox );
	tan = sin/cos ;
	printf("SIN: %f \n COS: %f \n TAN: %f \n ",sin ,cos,tan  );
	return 0;

}

float calsq( float x ) {
	float r = CORDIC_sq(x) ;
	printf("SQ: %f \n" ,r) ;
	return r ;
}

float calsqrt( float x ){
	float r = CORDIC_sqrt(x);
	printf("SQRT: %f \n",r);
	return r ;

}
float calasin(float x){
	float r = CORDIC_asin(x);
	printf("ASIN: %f \n",r);
	return r ;
}
float calacos(float x){
	float r =CORDIC_acos(x);
	printf("ACOS: %f", r );
	return r ;
}

/*int caldexp(float x){
	dblfix r = CORDIC_dblexp( x );
	printf("EXP: %f \n", to_dbl(r) );
	return 0;
};
*/



int main(void){
	printf("CORDIC CALLCATOR NOVILTY CALCULATOR \n USES CORDIC APROXAMATIONS FOR FUNCTIONS:\n KINDA JUST PLAYING AROUND WITH THE LIB OF CORDIC FUNCTIONS IM WORKING ON\n  PROGRAMED BY: EARL T {ET}\n");
	int q=0;
	do{
		char* cmd=(char*)malloc(sizeof(char[20])) ;// the function you want to execute
		float x ;//the input ang ect in float format
		scanf("%s %f", cmd, &x );
		if(strcmp(cmd,"log")==0 ){
			callog(x);
		}else if(strcmp(cmd,"exp")==0 && x < 8.2 ){
			calexp(x);		
		}else if(strcmp(cmd,"sct")==0){
			calsct(x);
		}else if(strcmp(cmd,"sq")==0){
			calsq(x);
		}else if(strcmp(cmd,"sqrt")==0){
			calsqrt(x);
		}else if ( strcmp(cmd,"asin")==0){
			calasin(x);
		}else if(strcmp(cmd,"acos")==0){
			calacos(x);	
		}else if(strcmp(cmd,"help")==0){
			FILE* f= fopen("help.txt","r");
			if(f==NULL){
				printf("ERROR HELP FILE NOT FOUND \n");
			}else{
				char buff[100];
				while(fgets(buff, sizeof(buff), f)){
					printf("%s \n",buff);
					}
			}
		}else if(strcmp(cmd,"quit")==0){
			q=1;
		}else if(cmd){
			printf("NOT A KNOWN COMMAND TYPE \n HELP TO SEE LIST OF COMMANDS \n");	
		}		
			}while(q==0);
		return 0;
	}
	

		

	
