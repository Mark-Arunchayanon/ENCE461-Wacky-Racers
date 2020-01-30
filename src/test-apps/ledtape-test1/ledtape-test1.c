/* File:   ledtape-test11.c
   Author: M. P. Hayes, UCECE
   Date:   30 Jan 2020
   Descr:  Test ledtape
*/
#include <pio.h>
#include "target.h"
#include "pacer.h"
#include "ledtape.h"

/* Define how fast ticks occur.  This must be faster than
   TICK_RATE_MIN.  */
enum {LOOP_POLL_RATE = 200};


#define NUM_LEDS 100

int
main (void)
{
    uint8_t leds[NUM_LEDS * 3];
    int i;

    for (i = 0; i < NUM_LEDS; i++)
    {
        // Set full green
        leds[i * 3] = 255;
        leds[i * 3 + 1] = 0;
        leds[i * 3 + 2] = 0;        
    }
        
    
    ledtape_init ();

    while (1)
    {
        ledtape_write (leds, NUM_LEDS * 3);
    }
}
