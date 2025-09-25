CFLAGS = -Wall -Werror -O3
OUT:= ../x86_64
all:$(OUT) $(OUT)libCORDIC.a 
$(OUT)libCORDIC.a :  CORDIC_sin_cos.o CORDIC_log_exp.o CORDIC_asin_acos.o CORDIC_sqrt_sq.o 
	ar rcs libCORDIC.a $^ 
CORDIC_log_exp.o: CORDIC_log_exp.c
	gcc -c CORDIC_log_exp.c $(CFLAGS) -o CORDIC_log_exp.o  
CORDIC_sin_cos.o: CORDIC_sin_cos.c
	gcc  -c CORDIC_sin_cos.c $(CFLAGS) -o CORDIC_sin_cos.o  
CORDIC_asin_acos.o: CORDIC_asin_acos.c
	gcc  -c CORDIC_asin_acos.c $(CFLAGS) -o CORDIC_asin_acos.o
CORDIC_sqrt_sq.o: CORDIC_sqrt_sq.c
	gcc  -c CORDIC_sqrt_sq.c $(CFLAGS) -o CORDIC_sqrt_sq.o  
$(OUT):
	mkdir -p $(OUT)  
	