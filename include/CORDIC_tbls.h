#ifndef CORDIC_TBLS_H_
#define CORDIC_TBLS_H_

#include "CORDIC.h"
#include "fixpnt.h"
/*header for the various lookup tables required by CORDIC algos
 * gonna try to keep it kinda orginized to the bestish of my
 * abilitys but it will probaly become a mess there is a CORDIC
 * tabls source file that has all of the defining of declared tables
 */
#define K_LEN 11

extern const  fix kz[11] ;

extern const int le_shift[11] ;

#define ATANZ_LEN 20

extern const fix atanz[20] ;

#endif/*CORDIC_TBLS_H_*/
