#include "delay.h"
#include "pio.h"

#define LEDTAPE_PIO PA9_PIO


void ledtape_init (void)
{
    pio_config_set (LEDTAPE_PIO, PIO_OUTPUT_LOW);
}


__attribute__((optimize (3)))    
static void ledtape_write_byte (uint8_t byte)
{
    int j;
    
    for (j = 0; j < 8; j++)
    {
        pio_output_high (LEDTAPE_PIO);
        DELAY_US (0.15);
        if (! (byte & 0x1))
            pio_output_low (LEDTAPE_PIO);
        DELAY_US (0.15);
        pio_output_low (LEDTAPE_PIO);            
        DELAY_US (0.15);
        byte >>= 1;
    }
}


void ledtape_write (uint8_t *buffer, uint16_t size)
{
    int i;

    // Send start...

    for (i = 0; i < size; i++)
    {
        ledtape_write_byte (buffer[i]);
    }


}
