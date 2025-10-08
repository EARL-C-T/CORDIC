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
**sin_&_cos** working +/- 0.01 acuracy
=================================================================================================
**asin_&_acos** The inverse to the sine and cosine asin arcsine seems to work well from 1 to -1 wich is its range now acos -1-0 actualy uses the asin function and that works fine acos works +/- 0.2 which is not aceptable at all to be honest and Is the next thing i really need to tweek all input for either function beyond -1 - 1 is undefined and may give you god only knows for resaults so theres that
================================================================================================
**exp_&_log**  +/- 0.01 accuracy works now
=================================================================================================
**sq_&_sqrt** working 
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
**test fixpoint functions**
**acos**
**optimize sin cos function**
##### Work On Chaining Functions In CORDIC_CAL**
##### Also Add Fixpnt Functions To **CORDIC_CAL**
##### add config script should compile for most things ##### 
##### looking into using complex numbers  or just having anything to catch over /under flow

