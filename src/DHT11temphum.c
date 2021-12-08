#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>
#include <stdio.h>

/**
 * File containing the functions related to the DHT11 temperature & humidity sensor
 * this sensor is being used to measure the ambient temperature of the air to control it.
 * given that this sensor is included as a sample in the zephyr sdk a large portion of this code is reused. Thanks to the team at Zephyr for helping me work & understand this system faster!
 */

static const char *timestream(void){

    static char buffer[16]; //time buffer of size 16 in format HH:MM:SS.MMM
    uint32_t current = k_uptime_get_32();
    unsigned int ms = current % MSEC_PER_SEC;
    unsigned int sec;
    unsigned int min;
    unsigned int hrs;

    current /= MSEC_PER_SEC;
    sec = current %60U;
    current /= 60U;
    min = current % 60U;
    current /= 60U;
    hrs = current % 60U;
    
}

void dhtgetval(void){

}
