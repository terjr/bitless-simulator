#include <stdlib.h>
#include <sndfile.h>
#include <stdio.h>

#include "main.h"
#include "wav.h"
#include "tdfilter.h"


#define SECONDS 9

int32_t main() {
    uint16_t *samples;

    SF_INFO in, out;
    uint32_t read = readWav("mordi.wav", &in, &samples);
    printf("Read %d samples\n", read);

    //echo(samples, read, 4000, 0.5);
    distortion(samples, read, 120);

    out.samplerate = in.samplerate;
    uint32_t written = writeWav("output.wav", &out, samples, in.samplerate * SECONDS);

    return written;
}
