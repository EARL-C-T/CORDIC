CFLAGS = -Wall -Werror -O3


libCORDIC.a :  CORDIC_sin_cos.o CORDIC_log_exp.o
	ar rcs libCORDIC.a $^ 
CORDIC_log_exp.o: CORDIC_log_exp.c
	gcc -c CORDIC_log_exp.c $(CFLAGS) -o CORDIC_log_exp.o  
CORDIC_sin_cos.o: CORDIC_sin_cos.c
	gcc  -c CORDIC_sin_cos.c $(CFLAGS) -o CORDIC_sin_cos.o  
