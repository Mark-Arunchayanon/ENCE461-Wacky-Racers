#include "delay.h"
#include "pio.h"

#ifndef LEDTAPE_PIO
#define LEDTAPE_PIO PA19_PIO
#endif


void ledtape_init (void)
{
    pio_config_set (LEDTAPE_PIO, PIO_OUTPUT_LOW);
}


__attribute__((optimize (2)))
__always_inline__
static void ledtape_write_byte (uint8_t byte)
{
    int j;
    
    for (j = 0; j < 8; j++)
    {
        pio_output_high (LEDTAPE_PIO);
        DELAY_US (0.3);
        // MSB first
        if (! (byte & 0x80))
            pio_output_low (LEDTAPE_PIO);
        DELAY_US (0.3);
        pio_output_low (LEDTAPE_PIO);            
        DELAY_US (0.6);
        byte <<= 1;
    }
}


__attribute__((optimize (2)))
void ledtape_write (uint8_t *buffer, uint16_t size)
{
    int i;

    // The data order is R G B per LED
    for (i = 0; i < size; i++)
    {
        ledtape_write_byte (buffer[i]);
    }

    // Send reset code
    pio_output_high (LEDTAPE_PIO);                
    DELAY_US (50);
    pio_output_low (LEDTAPE_PIO);            
}
