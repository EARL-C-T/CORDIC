CFLAGS:= -Wall -Werror -O3
PREFIX:= /usr/lib/
INC:= /usr/include/
LD:= -lm
OUT:= ../x86_64/
.PHONY: all 
all:$(OUT) $(OUT)libfixpnt.so	
$(OUT)libfixpnt.so : fixpnt.o
	cp fixpnt.h $(OUT)
	gcc -shared fixpnt.o $(CFLAGS) -o $(OUT)libfixpnt.so  $(LD)
fixpnt.o : fixpnt.c	
	gcc  -fPIC -c fixpnt.c $(CFLAGS) -o fixpnt.o 
$(OUT):
	mkdir -p $(OUT)
	