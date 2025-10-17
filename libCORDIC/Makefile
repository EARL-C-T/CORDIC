CFLAGS:= -Wall -Werror -O3
OUT:= ../x86_64/
OBJ:= ../obj/
all:$(OUT) $(OBJ) $(OUT)libCORDIC.a 
$(OUT)libCORDIC.a : $(OUT)  $(OBJ)CORDIC_sin_cos.o $(OBJ)CORDIC_log_exp.o $(OBJ)CORDIC_asin_acos.o $(OBJ)CORDIC_sqrt_sq.o 
	ar rcs $(OUT)libCORDIC.a $(OBJ)CORDIC_sin_cos.o $(OBJ)CORDIC_log_exp.o $(OBJ)CORDIC_asin_acos.o $(OBJ)CORDIC_sqrt_sq.o
$(OBJ)CORDIC_asin_acos.o: CORDIC_asin_acos.c
	gcc $(CFLAGS) -c CORDIC_asin_acos.c -o $@
$(OBJ)CORDIC_sqrt_sq.o: CORDIC_sqrt_sq.c
	gcc $(CFLAGS) -c CORDIC_sqrt_sq.c -o $@
$(OBJ)CORDIC_sin_cos.o: CORDIC_sin_cos.c
	gcc $(CFLAGS) -c CORDIC_sin_cos.c -o $@
$(OBJ)CORDIC_log_exp.o: CORDIC_log_exp.c
	gcc $(CFLAGS) -c CORDIC_log_exp.c -o $@  
    
$(OUT):
	mkdir -p $(OUT)  
$(OBJ):
	mkdir -p $(OBJ)
