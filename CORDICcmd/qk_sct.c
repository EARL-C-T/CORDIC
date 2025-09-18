#include "CORDIC.h"
#include "fixpnt.h"
#include "CORDIC_tbls.h"
1
	quiksc* q ;
	q = quicksn(ang);
	printf("sin:  %f cos: %f tan: %f \n",to_float(q->sin_aprox), to_float(q->cos_aprox), to_float(q->tan_aprox));
	free(q);
}
