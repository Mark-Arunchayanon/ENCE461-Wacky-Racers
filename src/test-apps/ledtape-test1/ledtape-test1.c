/* File:   ledtape-test11.c
   Author: M. P. Hayes, UCECE
   Date:   30 Jan 2020
   Descr:  Test ledtape
*/
#include <pio.h>
#include "target.h"
#include "pacer.h"
#include "ledtape.h"

#define NUM_LEDS 20


#define LEVEL_SHIFTER_PIO PA17_PIO

int
main (void)
{
    uint8_t leds[NUM_LEDS * 3];
    int i;

    for (i = 0; i < NUM_LEDS; i++)
    {
        // Set full green  GRB order
        leds[i * 3] = 255;
        leds[i * 3 + 1] = 0;
        leds[i * 3 + 2] = 0;
    }

    // Enable level-shifter
    pio_config_set (LEVEL_SHIFTER_PIO, PIO_OUTPUT_HIGH);
    
    ledtape_init ();

    while (1)
    {
        ledtape_write (leds, NUM_LEDS * 3);
    }
}
