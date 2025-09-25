CFLAGS:= -Wall -Werror -O3
PREFIX:= /usr/lib/
INC:= /usr/include/
LD:= -lm
OUT:= ../x86_64/
.PHONY: all 
all:$(OUT) $(OUT)libfixpnt.a	
$(OUT)libfixpnt.a : fixpnt.o
	cp fixpnt.h $(OUT)
	ar rcs libfixpnt.a fixpnt.o
fixpnt.o : fixpnt.c	
	gcc -O3 -c fixpnt.c $(CFLAGS) -o fixpnt.o 
$(OUT):
	mkdir -p $(OUT)
	