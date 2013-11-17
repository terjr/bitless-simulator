#include "tdfilter.h"

void echo(uint16_t *samples, uint32_t nSamples, uint16_t delaySamples, double coff) {
    for (uint32_t i = delaySamples; i < nSamples; ++i) {
        samples[i] *= (1 - coff);
        samples[i] += coff * samples[i - delaySamples];
        if (samples[i] > 255) samples[i] = 255;
    }

}
