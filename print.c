#include <MKL25Z4.h>
#include "print.h"
#include "PORTD_IRQHandler.h"
#include "init.h"

#define Segment_a (0)
#define Segment_b (1)
#define Segment_c (2)
#define Segment_d (3)
#define Segment_e (4)
#define Segment_f (5)
#define Segment_g (6)
#define Segment_dot (7)
#define MASK(x)  (1UL << (x))

void PORTD_IRQHandler(void);


void print (void) 
{
 switch ( Global_counter )
      {
         case 0:
        	 PTC->PDOR = 0x3F; 		//0 in for h,g,f,e,d,c,b,a Cathode configuration
         break;

         case 1:
        	 PTC->PDOR = 0x06;		//1 in for h,g,f,e,d,c,b,a Cathode configuration
         break;

         case 2:
         	 PTC->PDOR = 0x5B;		//2 in for h,g,f,e,d,c,b,a Cathode configuration
         break;

         case 3:
        	 PTC->PDOR = 0x4F;		//3 in for h,g,f,e,d,c,b,a Cathode configuration
         break;

         case 4:
        	 PTC->PDOR = 0x66;		//4 in for h,g,f,e,d,c,b,a Cathode configuration
         break;

         case 5:
        	 PTC->PDOR = 0x6D;		//5 in for h,g,f,e,d,c,b,a Cathode configuration
         break;

         case 6:
        	 PTC->PDOR = 0x7D;		//6 in for h,g,f,e,d,c,b,a Cathode configuration
         break;

         case 7:
        	 PTC->PDOR = 0x07;		//7 in for h,g,f,e,d,c,b,a Cathode configuration
         break;

         case 8:
        	 PTC->PDOR = 0x7F;		//8 in for h,g,f,e,d,c,b,a Cathode configuration
         break;
				 
				 case 9:
        	 Global_counter =0	;
         break;
				 
				 default:
					  Global_counter =8	;//0 in for h,g,f,e,d,c,b,a Cathode configuration
				 break;

      
      }

}

 