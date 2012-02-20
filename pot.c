#include<msp430.h>
#define VAL_ADC ADC10MEM
#define LED0_ON (P1OUT=1)
#define LED4_ON (P1OUT=0x40)
#define LEDS_ON (P1OUT=0X41)
#define LEDS_OFF (P1OUT=0)
 void delay(int n)
 {
  while(n--);
 }
 void adc_init()
  {
   ADC10CTL0 = ADC10ON | ADC10SHT_2 | SREF_0;
   ADC10CTL1 = INCH_4 | SHS_0 | ADC10DIV_0 | ADC10SSEL_0 | CONSEQ_0 ;
   ADC10AE0 = BIT4;
   ADC10CTL0 |= ENC ;
  } 

 void start_conversion()
  {
   ADC10CTL0 |= ADC10SC;
  }

 unsigned int converting()
  {
   return ADC10CTL1 & ADC10BUSY;
  }


 	main()
 	{
	 adc_init();
	 P1DIR=0x41;
	while(1){

	 start_conversion();
	 while(converting());
  
	 if(VAL_ADC<256)
	 LEDS_OFF; 
	 else if(VAL_ADC<512)
  	 LED0_ON;
	 else if(VAL_ADC<767)
	 LED4_ON;
	 else if(VAL_ADC<1023)
	 LEDS_ON;
	 delay(20000);
        	}
 	}




























