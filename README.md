# CORDIC
fix point CORDIC lib in c that  I am for reasons that IDK I'm coding from scratch as part of my greater navigation goals
both a rough actualy I  think it will be fairly complete fixed point lib libfixpnt , and libCORDIC . I have a side goal 
of makeing them both compile to either static or dynamic libary by make argument also Id like to put some cross compile 
suport in there as while for convince I . The amount i gotta fiddle whith the stuff I do if it didnt compile on x86_64 I'd
go insane but alot of it is rlly targeted for use in some stripe of arm or other RISC style arcutecture. aka resone 3 why 
c is awsome code can be very platform indepent I dont know what that came from in  my brain I might need some sleep.

So since I think I am going to get away with the fix point lib being just the header and one sorce so I'm not going to like make another repo 
or anything . I never rlly take any actual courses and kinda skip around random parts of them and I really gotta say one reson I kinda
go over board on some of the what I'm doing and why in some cases is I have no idea If doing some of this the way I am is fudomently wrong or
something so.If so message me in some way and as long as there is some resone and tradition or convention ect dose count. any way shift is set to 20 
from float to int32 may add some other options later double 64int a unsined version would be of little to no use to me but relly i feel like a float to 16int may have a limited use currently to_fix to_float seem to work fine im adding some min max and checks may add some check function as well going to compile to a sepret lib and have its own test that will also genrate arctanz for cordic if you wanna adjust some stuff.

CORDIC it will be source per operation i belive and I may store the tabelse seprate not sure once again advice please cos sin goin first 
