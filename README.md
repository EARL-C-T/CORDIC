# CORDIC
========================================================================================
### LINKS
HACKADAY.IO <a href="https://hackaday.io/project/204058-libcordic" > PROJECT PAGE </a>

============================================================================================
fix point CORDIC lib in c that  I am for reasons that IDK I'm coding from scratch as part of my greater navigation goals both a rough actualy I  think it will be fairly complete fixed point lib libfixpnt , and libCORDIC .Ok that is all I'm keeping from my origonal README ok so this repo Contains libfixpnt.a a fixpoint libary I wrote for this 32 bit Q20  for greater acuracy Q15 being standered but since I wrote this whith navigation in  mind and since the numbers involved in the calculations such as the haversine formula are all in radians about pi or maybe twice that is about as high as numbers go even in formula so for its intended use I think Q20 is fine even thou that means -/+2047.9899999 is the upper / lower limit I think thats plenty of space other quirks beause of this well radians are usally mesured 0 - 2pi for my use however there pi - -pi as that is how logitude and latitude are messured in radians actually longitude is latitude is only 90 - -90 and distences ya can resonably get pi would be half way around the earth 180 degress so my sine cosine looks at the quarters of a circle as 0 - 1.571 1Q, 1.572 - 3.142 2Q, 0 - -1.571 3Q , -1.572 - -3.142 4Q . For the remainder of this document for now since these are aproxomations +/- 0.01 is good meaning thats the degree of acruccy that is acceptable and while later I may shoot for improvement on this thats pass for now.
================================================================================================
## CONTAINS 
=================================================================================================
**libfixpnt**  
**libCORDIC**
**fixpntcmd**
**CORDICcmd**
===============================================================================================
### COMING SOON
==================================================================================================
**CORDICbench**

================================================================================================
## CURRENT PROJECT STATUS
================================================================================================
**libfixpnt**
================================================================================================
fix point lib made for this it uses signed 32 bit int shifted Q20 the lib has to_float to_fix as well as a limit check check_add check_subtract regular multiply that shifts both input args back 10 so that the resault is Q 20 finx point number. I may add another version that at least temporarlly makes it a 64 bit then scales down for added acuracy but as yet I havent used any of these functions so I just haven't yet oh also a divide that divides and then scales the resault to fixpoint since division gets you a float point resault most of this hasnt been tested as this was all kinda wrote just for the CORDIC lib and i haven't yet used any of these functions because all CORDIC needs are add subtract that I dont use the check on as it would slow it down and bitshifts so havent had the need all thou i will have to figure out how to do the scalling in functions like square squareroot as i may run into these problems in scalling.
============================================================================================
**libCORDIC** 
===========================================================================================
**sin_&_cos** The actual point of this whole thing sine cosine works just fine as I said before it uses Pi - -Pi as a range that is intentional and it will reject input above Pi the nature of CORDIC sine cosine algorythm is such that it computes both sine and cosine at once the nature of the trig ratios is such that tan = cos/sin sec=1/cos csc=1/sin cot=1/tan so all the reciprocal ratios and tan can be calculated from sin and cos. to add to this my bench mark testing as of now puts this sin cos pretty close to neck and neck whith math.h sin and cos and there is still alot of tweaking and optimizing to do as the current version is rough to say the least. Oh and acurccy seems to fall in the +/-.01 when compared to gp/pari for the entire range which isn't bad .
=================================================================================================
**asin_&_acos** The inverse to the sine and cosine asin arcsine seems to work well from 1 to -1 wich is its range now acos -1-0 actualy uses the asin function and that works fine acos works +/- 0.2 which is not aceptable at all to be honest and Is the next thing i really need to tweek all input for either function beyond -1 - 1 is undefined and may give you god only knows for resaults so theres that
================================================================================================
**exp_&_log** these are computed diffrently and I'm having some issues with them and that is a very big problem log actually seems to be working up to 8 where looks like im hitting over flow or scalling issue at 8 but i just tested it and im getting good once again for now +/- 0.01 . exp is a bit off im getting range of +/- 0.1 from 1 - 7 below one is in range above 7 is compleatly outa wack starting + 0.6 and getting worse further you go up
=================================================================================================
**sq_&_sqrt** the way im calculating these for now at least is sq(x) exp(log(x)<<1) might change that to exp(log(x)+log(x)) which works but the issues from the log exp are multiplyed but the range from 1 - 7 seems to work for square root and 1-4 for square neither works at all below 1 and square 4-8 it kinda works then hits a wall sq of 4 16.125 8 being 63.75 as is any thing higher sqrt works about the same 7 2.63  gp/pari 2.34 8 2.81 gp/pari 2.82 past that it stays 2.81 so scalling over flow issues really an issue id like to address in all cases without going to 64 bits and maintianing the current leval of acurccy wich will only take me so far I relize and to be aceptably accuret for a range that would suit the intended i'm getting close  I think but not quite since haver sine needs to square the sin(dlng/2 ) dlng being the difrance in longitude  need to do latitude as well but the point is sin is a ratio 0 -1 and sq stops working at 1 this may be an issue for sqrt as well since havdlat + coslat1 * coslat2 * havdlng  also seems to fall in the sub 1 range so that shall be the next thing I try to address
==============================================================================================================
**CORDICcmd**
===============================================================================================================
contains a few excutables soon to be just **CORDIC_CAL** and probaly the benchmark programs I'm gonna put them here screw makeing a whole new folder also for ease i may migrate fixpntcmd to_fix to_float to here since I kinda use those quite a bit I actually have them installed on my computer as well as CORDIC_CAL in my PATH so all i gotta do is CORDIC_CAL all thou that version is old need to update and add version numbers .
===========================================================================================================================
**fixpntcmd**
=============================================================================================================
soon to be defunct see above 
==================================================================================================================
## COMPILE
==========================================================================================================
If you are using an x86_64 linux system with gcc and make your in luck just run make on the top level should do it but maybe not my Makefiles lack any kind of config only have the one target and work on my hunk of junk even thou **aarch64 cortex A53** is the intended target of a **Libre computer potato** also windows would be nice I have nothing to test it on windows I mean. Other arm targets STM THUMB  AVR arm 32 and maybe RISCV nothing to really test those on qemu which my computer can handle for some of those but not windows maybe windows 32 is that still a thing. Any way run **make** or **make all** will hopefully make a dir **build** copy the libfixpnt libCORDIC and CORDICcmd dirs to it also should create another dir **build/x86_64** that will containe the libCORDIC.a libfixpnt.a a copy of the headerfiles the executable **./CORDIC_CAL** which is a novelty calculator that uses the libCORDIC fsc sq sqrt log exp soon to_float and to_fix and soon as U figure it out chaining commands and other libfixpnt commands and help when I have time also **./to_float ./to_fix**  which I use regurly the other executables are already part of **CORDIC_CAL**      
===============================================================================================================
## TODO FUNCTIONS
================================================================================================================
### get hyperbolic functions to work on values of less then 1 number 1 issue
For great circle navigation ang trig in genral functions I need to do are :
**atan**
**atan2**
**mod** no idea how im gonna do this one but rest assured it will work for its intended use unlike mod modf in c as they do not work for spherical geometry
**work on log exp range and precicion**
**sq and sqrt ditto and get them working under 1**
**test fixpoint functions**
**optimize sin cos function**
##### Work On Chaining Functions In CORDIC_CAL**
##### Also Add Fixpnt Functions To **CORDIC_CAL**
##### Make Have **aarch64** target ##### since thats what this is really for
##### looking into using complex numbers  or just having anything to catch over /under flow
**possibly other make targets** windows maybe ?
