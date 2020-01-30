#ifndef LEDTAPE_H
#define LEDTAPE_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "config.h"
#include "pio.h"

    
void ledtape_init (void);


void ledtape_write (uint8_t *buffer, uint16_t size);    

#ifdef __cplusplus
}
#endif    
#endif

