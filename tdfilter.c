#include "tdfilter.h"

void echo(uint16_t *samples, uint32_t nSamples, uint16_t delaySamples, double coff) {
    for (uint32_t i = delaySamples; i < nSamples; ++i) {
        samples[i] *= (1 - coff);
        samples[i] += coff * samples[i - delaySamples];
        if (samples[i] > 255) samples[i] = 255;
    }
}

void bitcrusher(uint16_t *samples, uint32_t nSamples) {
    for (uint32_t i = 0; i < nSamples; ++i) {
        if (samples[i] > 192) samples[i] = 222;
        else if (samples[i] > 128) samples[i] = 192;
        else if (samples[i] > 96) samples[i] = 128;
        else if (samples[i] > 64) samples[i] = 96;
        else if (samples[i] > 48) samples[i] = 64;
        else if (samples[i] > 32) samples[i] = 48;
        else if (samples[i] > 16) samples[i] = 24;
    }

}
