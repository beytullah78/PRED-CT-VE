/*
 * inverter_main.c
 *
 *  Created on: 19 Eyl 2020
 *      Author: ASUS
 */

#include "inverter_main.h"
#include "akim_kontrol.h"

/*
        GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, GPIO_PIN_5);
          adc_okuma();
         // kontrol_algoritma();
          gate_s�r�c�ler_pin_reset();
         gate_s�r�c�ler_vekt�rler_pinler();
       GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, GPIO_PIN_0);

*/

INT inverter_main(void)
{
    mcu_frekansi_ayarlama();
    sin_egrisi_olu�turma();
    gate_s�r�c�ler_pinler_init();
    adc_cevre_birimi_init();
    algoritma_init();
    gate_s�r�c�ler_enable();
    timer_cevre_birimi_init();
    gate_suruculer_pin_reset();


    while(1)
   {

        GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, GPIO_PIN_5);
          adc_okuma();
         // kontrol_algoritma();
          gate_suruculer_pin_reset();
         gate_suruculer_vektorler_pinler();
        GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, GPIO_PIN_0);

            if(GL.tasklar_t.HZ.KHZ_40 == 1)
            {
                GPIOPinWrite(GPIO_PORTC_BASE , GPIO_PIN_4, 0 ); // osiloskop i�in konuldu

                 adc_okuma();
                 kontrol_algoritma();
                 gate_suruculer_pin_reset();
                 gate_suruculer_vektorler_pinler();

                 GPIOPinWrite(GPIO_PORTC_BASE , GPIO_PIN_4, GPIO_PIN_4 ); // osiloskop i�in konuldu

                GL.tasklar_t.HZ.KHZ_40 = 0 ;
            }
    }
}

