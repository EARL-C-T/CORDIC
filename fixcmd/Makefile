LD:= -l:libfixpnt.so 
CFLAGS:= -Wall -Werror -o3

OUT:= ../x86_64/
all:$(OUT) $(OUT)to_float  $(OUT)to_fix 
$(OUT)to_float : to_float.c
	gcc to_float.c $(CFLAGS) -o $(OUT)to_float $(LD) 
$(OUT)to_fix : to_fix.c
	gcc to_fix.c $(CFLAGS) -o $(OUT)to_fix $(LD) 
$(OUT):
	mkdir -p $(OUT)``