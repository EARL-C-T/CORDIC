CFLAGS:= -Wall -Werror -O3
OUT:= ../x86_64/

all:$(OUT) $(OUT)libCORDIC.a 
$(OUT)libCORDIC.a : $(OUT)  CORDIC_sin_cos.o CORDIC_log_exp.o CORDIC_asin_acos.o CORDIC_sqrt_sq.o 
	ar rcs $(OUT)libCORDIC.a CORDIC_sin_cos.o CORDIC_log_exp.o CORDIC_asin_acos.o CORDIC_sqrt_sq.o  
CORDIC_log_exp.o: CORDIC_log_exp.c
	gcc $(CFLAGS) -c CORDIC_log_exp.c -o CORDIC_log_exp.o  
CORDIC_sin_cos.o: CORDIC_sin_cos.c
	gcc $(CFLAGS) -c CORDIC_sin_cos.c -o CORDIC_sin_cos.o  
CORDIC_asin_acos.o: CORDIC_asin_acos.c
	gcc $(CFLAGS) -c CORDIC_asin_acos.c -o CORDIC_asin_acos.o
CORDIC_sqrt_sq.o: CORDIC_sqrt_sq.c
	gcc $(CFLAGS) -c CORDIC_sqrt_sq.c -o CORDIC_sqrt_sq.o  
$(OUT):
	mkdir -p $(OUT)  
	