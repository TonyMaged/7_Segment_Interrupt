#include <MKL25Z4.h>
#include "PORTD_IRQHandler.h"
#include "init.h"
#define sw_pos_2 (1)
#define sw_pos (5)

unsigned char Global_counter ;


void PORTD_IRQHandler(void)
{
NVIC_ClearPendingIRQ(PORTD_IRQn);
	if (PORTD->PCR[sw_pos] & (1U<<24))
	{
	
	Global_counter ++ ;
	
	} 
	
	else if (PORTD->PCR[sw_pos_2] & (1U<<24))
	{
	
			Global_counter -- ;
	
	}
PORTD->ISFR = 0xffffffff;

}

