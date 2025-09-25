CFLAGS:= -Wall -Werror -O3

OUT:= ../x86_64/
LD:=  -L$(OUT) -l:libCORDIC.a -l:libfixpnt.a 

all: $(OUT) $(OUT)test.sh  $(OUT)CORDIC_CAL $(OUT)cordic_bm $(OUT)math_bm $(OUT)to_float $(OUT)to_fix
$(OUT)CORDIC_CAL: CORDIC_CAL.c
	gcc $(CFLAGS) CORDIC_CAL.c  -o $(OUT)CORDIC_CAL $(LD)
$(OUT)cordic_bm: sincos_cordic.c
	gcc $(CFLAGS) sincos_cordic.c -o $(OUT)cordic_bm $(LD)
$(OUT)math_bm: sincos_math.c
	gcc $(CFLAGS) sincos_math.c -o $(OUT)math_bm -lm
$(OUT)to_float : to_float.c
	gcc $(CFLAGS) to_float.c -o $(OUT)to_float $(LD)
$(OUT)to_fix  : to_fix.c
	gcc $(CFLAGS) to_fix.c -o $(OUT)to_fix $(LD)
$(OUT)test.sh : $(OUT) test.sh
	cp test.sh $(OUT)
	chmod +x $(OUT)test.sh
$(OUT):
	mkdir -p $(OUT)
	
