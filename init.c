
#include <MKL25Z4.h>
#include "init.h"
#define Segment_a (0)
#define Segment_b (1)
#define Segment_c (2)
#define Segment_d (3)
#define Segment_e (4)
#define Segment_f (5)
#define Segment_g (6)
#define Segment_dot (7)
#define MASK(x) (1UL << (x)) 
#define sw_pos (5)
#define sw_pos_2 (1)

void init(void)
	
{
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTB_MASK;
	PORTC->PCR[Segment_a] &= ~PORT_PCR_MUX_MASK;
			PORTC->PCR[Segment_a] |= PORT_PCR_MUX(1);
			PORTC->PCR[Segment_b] &= ~PORT_PCR_MUX_MASK;
			PORTC->PCR[Segment_b] |= PORT_PCR_MUX(1);
			PORTC->PCR[Segment_c] &= ~PORT_PCR_MUX_MASK;
			PORTC->PCR[Segment_c] |= PORT_PCR_MUX(1);
			PORTC->PCR[Segment_d] &= ~PORT_PCR_MUX_MASK;
			PORTC->PCR[Segment_d] |= PORT_PCR_MUX(1);
			PORTC->PCR[Segment_e] &= ~PORT_PCR_MUX_MASK;
			PORTC->PCR[Segment_e] |= PORT_PCR_MUX(1);
			PORTC->PCR[Segment_f] &= ~PORT_PCR_MUX_MASK;
			PORTC->PCR[Segment_f] |= PORT_PCR_MUX(1);
			PORTC->PCR[Segment_g] &= ~PORT_PCR_MUX_MASK;
			PORTC->PCR[Segment_g] |= PORT_PCR_MUX(1);
			PORTC->PCR[Segment_dot] &= ~PORT_PCR_MUX_MASK;
			PORTC->PCR[Segment_dot] |= PORT_PCR_MUX(1);
			// set LEDs bits to outputs
			PTC->PDDR |= MASK(Segment_a) | MASK(Segment_b)| MASK(Segment_c)| MASK(Segment_d)| MASK(Segment_e)| MASK(Segment_f)| MASK(Segment_g)| MASK(Segment_dot);
	
	
	
	
	
 ///global enable of interrupts
 __enable_irq();
 /// enable clock to port D 
 SIM->SCGC5 |=  SIM_SCGC5_PORTD_MASK ;
 // set pin as GPIO and interrupt on rising edge
 		PORTD->PCR[sw_pos] |= PORT_PCR_MUX(1) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_IRQC(9);
		PORTD->PCR[sw_pos_2] |= PORT_PCR_MUX(1) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_IRQC(9);


 // set data direction reg
 PTD->PDDR &= ~MASK(sw_pos);
PTD->PDDR &= ~MASK(sw_pos_2);
 //enable interrupts
 NVIC_SetPriority(PORTD_IRQn, 128); // 0, 64, 128 or 192
 NVIC_ClearPendingIRQ(PORTD_IRQn);
 NVIC_EnableIRQ(PORTD_IRQn);



}

