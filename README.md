# CORDIC
========================================================================================
THIS IS MY TESTING AND LEARNING PROJECT THE COMMENTS ARE QUITE LEANGTHY  AT TIMES THEY ARE MENT 
AS HELP IN ALPPLYING THESE FUNCTIONS IN A MORE USEABLE FORM RIGHT NOW THEY WORK ND THIS WILL ALL 
COMPILE ON YOUR HOME COMPUTER OR ON LIKE A RASBERY PIE AND THATS FINE IF YOUR LEARNING ABOUT CORDIC
ALGORYTHMS OR YA WANT TO TEST SOMETHING OUT OR WHATEVER BUT IN REAL LIFE USE THEY ARE TO BE USED ON
A PLATFORM THAT LACKS AN FPU THIS IS A FIXED POINT SYSTEM AND WHILE I TEST IT AGAINST THE MATH LIB ITS 
NOT GONNA WIN ON ANY HOME COMPUTER MADE SINCE THE 80S EARLY 90'S FPU IS FLOAT POINT UNIT OR FLOATPOINT 
PROSSESING UNIT THATS WHAT ITS FOR COMPLEX MATH ON FLOAT POINT MEANING FLOAT AND DOUBLE AND QUAD LONGDOUBLE 
WHAT HAVE YOU I WANTED TO LEARN ABOUT CORDIC MATH AND TEST SOME THINGS I FOUND INFORMATION TO BE DIFFICULT 
TO COME BY AND CONFUSING SO I AM TRYING TO GIVE ANOTHER SOURCE I AM PLANING TO USE THIS INFORMATION 
IN FUTURE PROJECTS AND ALL THAT BUT REALLY I KINDA MADE IT MORE PUBLIC BECAUSE THOUGHT MAY BE OF USE 
AND TO BE HONEST I JUST LEARNED C I HAVE PROGREAMED IN OTHER LANGUAGES IN THE PAST BUT I REALLY JUST LEARNED
C AND AS FAR AS THE MATH WHILE I DO ENJOY THE SUBJECT I AM KINDA AN AMUTER AT THAT TO BUT FOR WHAT ITS WORTH 
HERE ARE SOME WORKING EXEMPLES OF CORDIC ALGORITHM AND OF LOGRTHMIC AND NO I DONT KNOW IF IM USEING THAT RIGHT
MATH FEEL FREE TO COPY AND USE THEM OR STUDY AND POKE THEM AS MUCH AS YOUD LIKE IF YA MAKE SOME IMPROVEMENTS OR 
EXPANSIONS FEEL FREE TO SHARE OR DONT ITS FINE I WILL TRY TO GO BACK AND IMPROVE AND SHINE UP THIS A BIT 
IVE GOT SOME LATEX EXPLAINING SOME OF THE MATH IN MORE DETAIL AND WITH NICE LOOKING EQUATIONS IM WORKING ON
JUST NOT ALWAYS TOP PRIORITY AND IM NOT THE BEST AT LATEX EITHER I HAD A HACKADAY PAGE THAT HAD THE SAME FUNCTIONS
AND MOST THE INFO THAT I PLAN ON PUTTING ON THIS DOCUMENTATION THEY TOOK IT DOWN BECAUSE I DIDNT SHOW MY ID .BUT TO BE HONEST THEY HAVE A GREAT INTERFACE FOR SHAREING PROJECTS AND INFORMATION VERY EASY TO USE AND INTUTIVE AND THERE ARE VARIUSE WAYS FOR YOU TO DISPLAY INFORMATION MY FAULT FOR NOT GETTING TO THE DMV AND GETTING A NEW COPY AFTER THE COPS DIDNT RETURN MINE IN MY PROPERTY FOR THE SECOND TIME F RICE ST ALL IM SAYING 

YOUR FREAND
	ET
	
PS I KNOW MY SPELLING AND GRAMMER SUCKS AND I USE A IDE FOR PROGRAMING TO TYPE ALL THIS AND WHILE IT MAY HAVE A 
SPELLCHECK I KEEP IT OFF BECAUSE YA KNOW HOW MUCH IS SPELT RIGHT IN YOUR AVRAGE PROGRAM SAME WITH THIS README I WILL 
TRY AND REMBER TO SPELLCHECK ANY OTHER DOCUMETATION BUT BESIDES THAT UNLESS YOUR GONNA FIX IT LEAVE MY SOPHTMORE YEAR 
DROP OUT  FROM A GARBAGE PUBLIC SCHOOL ASS ALONE CUS BITCH ALL YA WANT I AINT FIXING IT I DONT HAVE TIME IN MY LIFE FOR 
EVERYTHING I WANT TO DO AND LEARNING TO SPELL PROPERLY IS NOT EVEN ON THAT LIST IF YA WANT TO CORRECT IT GO AHEAD LOVE FOR
INFORMATION TO BE MORE ACSESSIBLE BUT I AINT DOING IT SO IF YA JUST WANNA COMPLAIN SAVE IT I WILL LISTEN AND MAY IMPLIMENT 
ANY ISUES WITH EITHER MY CODE STYLE OR ISSUES WITH THE MATH AND WILL GLADLY ACEPT IMPROVMENTS OR EXPATIONS BUT I SAID THAT ALREADY PEACE 


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
just the libary should compile on most things tests and ect on 
microcontroles issues whith time function
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

