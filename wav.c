#include <limits.h>
#include <stdlib.h>
#include <stdint.h>
#include <sndfile.h>

uint32_t readWav(char *filename, SF_INFO *info, uint16_t **buffer) {
    SNDFILE *file = sf_open(filename, SFM_READ, info);

    uint32_t nFrames = info->frames;

    if (!file) fprintf(stderr, "Unable to read wav file: %s\n", filename);

    *buffer = malloc(sizeof(uint16_t) * nFrames);
    double *imm_buffer = malloc(sizeof(double) * nFrames);

    uint32_t bytesRead = sf_read_double(file, imm_buffer, nFrames);

    for (uint32_t i = 0; i < bytesRead; ++i) {
        (*buffer)[i] = (uint8_t) ((1.0 + imm_buffer[i]) * (UCHAR_MAX / 2));
    }

    return bytesRead;
}

uint32_t writeWav(char *filename, SF_INFO *info, uint16_t *buffer, uint32_t nSamples) {
    info->format = (SF_FORMAT_WAV | SF_FORMAT_PCM_U8);
    info->channels = 1;

    SNDFILE *outfile = sf_open(filename, SFM_WRITE, info);

    // Write all samples.
    for (uint32_t i = 0; i < nSamples; ++i) {
        double sample = ((double) buffer[i] / ((UCHAR_MAX / 2.0)) - 1.0);
        sf_writef_double(outfile, &sample, 1);
    }
    return sf_close(outfile);
}
