CORDIC_test : CORDIC_sc_test.c libCORDIC.a libfixpnt.a
	gcc CORDIC_sc_test.c -L. -l:libCORDIC.a -l:libfixpnt.a -o CORDIC_test -lm
libCORDIC.a : CORDIC_sin_cos.o
	ar -rc libCORDIC.a CORDIC_sin_cos.o
CORDIC_sin_cos.o : CORDIC_sin_cos.c
	gcc -c CORDIC_sin_cos.c -o CORDIC_sin_cos.o
	
test : libfixpnt.a test_fixpnt.c
	gcc test_fixpnt.c -L. -l:libfixpnt.a -o test_fixpnt -lm 
libfixpnt.a : fixpnt.o
	ar -rc libfixpnt.a fixpnt.o
fixpnt.o : fixpnt.c
	gcc -c fixpnt.c -o fixpnt.o 

