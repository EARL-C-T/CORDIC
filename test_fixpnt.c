#include "fixpnt.h"
#include <stdio.h>

int main(){
	FILE* f = fopen( "power.txt", "w" );
	int i = 0 ;
	for (i=0;i>-20;i--){
		float power =(float) pow(2,i) ;
		int fpower = to_fix(power) ;
		fprintf(f,"%d // %f \n", fpower, power ) ;
	};
	fclose(f);
	return 0  ;
}
