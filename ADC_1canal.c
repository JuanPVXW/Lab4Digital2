/*
 * File:   ADC_1canal.c
 * Author: acer
 *
 * Created on 5 de agosto de 2021, 12:27 AM
 */
define _XTAL_FREQ 4000000
#include <stdint.h>
#include <pic16f887.h>
#include "ADC_1canal.h"
int var1;
uint8_t var2;
void recibir_valoresADC(void)
{
    if (PIR1bits.ADIF == 1)
    {
            var1 = ADRESH;
            PIR1bits.ADIF = 0;
    }
}
void inicio_conversionADC(void)
{
    if(ADCON0bits.GO == 0)
    {
        /*f(ADCON0bits.CHS == 5)
        {
            ADCON0bits.CHS = 6;
        }
        else
        {
            ADCON0bits.CHS = 5;
        }
        //__delay_us(50);
    }*/
    __delay_us(50);
    ADCON0bits.GO = 1;  
}

