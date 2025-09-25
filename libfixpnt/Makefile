CFLAGS:= -Wall -Werror -O3
PREFIX:= /usr/lib/
INC:= /usr/include/

OUT:= ../x86_64/
.PHONY: all 
all:$(OUT) $(OUT)libfixpnt.a	
$(OUT)libfixpnt.a : fixpnt.o
	cp fixpnt.h $(OUT)
	ar rcs $(OUT)libfixpnt.a fixpnt.o
fixpnt.o : fixpnt.c	
	gcc $(CFLAGS) -c fixpnt.c  -o fixpnt.o 
$(OUT):
	mkdir -p $(OUT)
	