#include <MKL25Z4.h>
#include "init.h"
#include "print.h"
#include "PORTD_IRQHandler.h"
#define MASK(x) (1UL << (x)) 
#define sw_pos (5)
#define sw_pos_2 (1)



void PORTD_IRQHandler(void);
void init(void);
void print(void);
int main ( void)
{
SystemCoreClockUpdate();    
init();

while (1)
{


//function to print to 7 segment display
print ();

}            




}

