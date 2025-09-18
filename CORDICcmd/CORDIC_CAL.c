#include "../libCORDIC/CORDIC.h"
#include <fixpnt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int callog(float x ){
	fix r = CORDIC_log( x ) ;
	printf( "LOG: %f \n", to_float(r) ) ;
	return 0 ;
}
int calexp(float x){
	fix r = CORDIC_exp( x );
	printf("EXP: %f \n", to_float(r) );
	return 0;
}
int calsct(float x ){
	fsc* r =  CORDIC_fsc(x);
	float sin, cos, tan;
	sin = to_float( r -> sin_aprox );
	cos = to_float( r -> cos_aprox );
	tan = sin/cos ;
	printf("SIN: %f \n COS: %f \n TAN: %f \n ",sin ,cos,tan  );
	return 0;

}
int caldexp(float x){
	dblfix r = CORDIC_dblexp( x );
	printf("EXP: %f \n", to_dbl(r) );
	return 0;
};




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
		}else if(strcmp(cmd,"exp")==0 && x >= 8.2){
			caldexp(x);
		}else if(strcmp(cmd,"sct")==0){
			calsct(x);	
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
	

		

	
