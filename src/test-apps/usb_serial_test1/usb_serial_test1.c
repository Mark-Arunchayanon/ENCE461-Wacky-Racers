#include <stdio.h>
#include "usb_serial.h"
#include "pio.h"
#include "sys.h"
#include "pacer.h"
#include "delay.h"


#define PACER_RATE 1000
#define LED_FLASH_RATE 2

static usb_serial_cfg_t usb_serial_cfg =
{
    .read_timeout_us = 1,
    .write_timeout_us = 1,
};


static void
process_command (void)
{
    char buffer[80];
    char *str;
    
    str = fgets (buffer, sizeof (buffer), stdin);

    switch (str[0])
    {
    case '0':
        pio_output_set (LED1_PIO, 0);
        break;
        
    case '1':
        pio_output_set (LED1_PIO, 1);
        break;

    case 'h':
        fprintf (stderr, "Hello world!\n");
        break;

    default:
       break;
    }
}


int main (void)
{
    usb_cdc_t usb_cdc;
    int flash_ticks = 0;

    pio_config_set (LED1_PIO, PIO_OUTPUT_LOW);                
    pio_config_set (LED2_PIO, PIO_OUTPUT_LOW);                

    usb_serial_init (&usb_serial_cfg, "/dev/usb_serial");
    freopen ("/dev/usb_serial", "a+", stdout);

    pacer_init (PACER_RATE);

    while (1)
    {
        pacer_wait ();

	flash_ticks++;
	if (flash_ticks >= PACER_RATE / (LED_FLASH_RATE * 2))
	{
	    flash_ticks = 0;

	    /* Toggle LED2.  */
	    pio_output_toggle (LED2_PIO);

            process_command ();
	}
    }
}
