#include "player.h"
#include <maxmod.h>
#include "soundbank.h"
#include "soundbank_bin.h"
#include "playbackicons.h"
#include <stdio.h>
#include <tonc.h>

int player_init() {
    // required to maxmod to work
    irq_init(nullptr); 
	irq_set( II_VBLANK, mmVBlank, 0);
	irq_enable(II_VBLANK);

    mmInitDefault( (mm_addr)soundbank_bin, 8 );
    return 0;
}

int play() { 
    mmStart(MOD_WAVE, MM_PLAY_LOOP);
    return 0;
}

