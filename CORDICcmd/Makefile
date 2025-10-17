CFLAGS:= -Wall -Werror -O3

OUT:= ../x86_64/
LD:=  -L../x86_64/ -l:libCORDIC.a 

all: $(OUT) $(OUT)sincos_bm  $(OUT)CORDIC_CAL $(OUT)to_float $(OUT)to_fix
$(OUT)CORDIC_CAL: CORDIC_CAL.c
	gcc $(CFLAGS) CORDIC_CAL.c  -o $(OUT)CORDIC_CAL $(LD)
$(OUT)sincos_bm: sincos_bm.c
	gcc $(CFLAGS) sincos_bm.c -o $(OUT)sincos_bm $(LD) -lm
$(OUT)to_float : to_float.c
	gcc $(CFLAGS) to_float.c -o $(OUT)to_float 
$(OUT)to_fix  : to_fix.c
	gcc $(CFLAGS) to_fix.c -o $(OUT)to_fix 
$(OUT):
	mkdir -p $(OUT)
	
