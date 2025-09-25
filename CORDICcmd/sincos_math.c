//THE MATH LIB BENCHMARK TO TEST SIN COS AGAINST

#include <math.h>
#include <stdio.h>
int main(void){
	float xs = sinf(1.3 );
	float xc = cosf(1.3 );
	printf("%f    %f \n", xs, xc);
	float ys = sinf(1.8 );
	float yc = cosf(1.8 );
	printf("%f    %f \n", ys, yc);
	float vs = sinf(-1.1 );
	float vc = cosf(-1.1 );
	printf("%f    %f \n", vs, vc);
	float ns = sinf( -2.9 );
	float nc = cosf(-2.9 );
	printf("%f    %f \n", ns, nc);
	return 0;
}