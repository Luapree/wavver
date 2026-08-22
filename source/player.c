#include "player.h"
#include <maxmod.h>
#include "soundbank.h"
#include "soundbank_bin.h"
#include "playbackicons.h"
#include <stdio.h>
#include <tonc.h>

int play() { 
    mmStart(MOD_WAVE, MM_PLAY_LOOP);
    return 0;
}

