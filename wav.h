#ifndef _WAV_H
#define _WAV_H

#include <stdint.h>

uint32_t readWav(char *filename, SF_INFO *info, uint16_t **buffer);
uint32_t writeWav(char *filename, SF_INFO *info, uint16_t *buffer, uint32_t nSamples);

#endif
