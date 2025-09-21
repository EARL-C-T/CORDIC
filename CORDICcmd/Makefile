LD:= -L../libCORDIC/ -l:libCORDIC.a -l:libfixpnt.so -lm
CFLAGS:= -Wall -Werror -o3

OUT:= ../x86_64/

all: $(OUT) $(OUT)exp $(OUT)log $(OUT)sincostan $(OUT)CORDIC_CAL
$(OUT)CORDIC_CAL: CORDIC_CAL.c
	gcc CORDIC_CAL.c $(CFLAGS) -o $(OUT)CORDIC_CAL $(LD)
$(OUT)exp: exp.c
	gcc exp.c $(CFLAGS) -o $(OUT)exp $(LD)
$(OUT)log: log.c
	gcc log.c $(CFLAGS) -o $(OUT)log $(LD)
$(OUT)sincostan: sincostan.c
	gcc sincostan.c $(CFLAGS) -o $(OUT)sincostan $(LD)
$(OUT):
	mkdir -p $(OUT)
	
