#include "audio.h"

static Uint32 audio_len;
static Uint8 *audio_pos;

void fill_audio(void *udata, Uint8 *stream, int len){

    if(audio_len == 0){
        return;
    }
    len = (len > audio_len ? audio_len : len);
    SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);
    audio_pos += len;
    audio_len -= len;

}
