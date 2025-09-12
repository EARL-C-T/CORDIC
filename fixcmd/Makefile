to_float : to_float.c  libCORDIC.a libfixpnt.a 
	gcc to_float.c -L. -I.. -o to_float -l:libCORDIC.a -l:libfixpnt.a -lm

to_fix : to_fix.c libCORDIC.a libfixpnt.a
	gcc to_fix.c -L. -I.. -o to_fix -l:libCORDIC.a -l:libfixpnt.a -lm
	
libCORDIC.a : ../libCORDIC.a
	cp ../libCORDIC.a . 
libfixpnt.a : ../libfixpnt.a
	cp ../libfixpnt.a .