#ifndef _TDFILTER_H
#define _TDFILTER_H

#include <stdint.h>

void echo(uint16_t *samples, uint32_t nSamples, uint16_t delaySamples, double p);
void bitcrusher(uint16_t *samples, uint32_t nSamples);
void distortion(uint16_t *samples, uint32_t nSamples, uint32_t cutoff);

#endif
