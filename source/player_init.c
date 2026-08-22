#include "player_init.h"

#include "player.h"
#include <tonc.h>
#include <maxmod.h>
#include "soundbank.h"
#include "soundbank_bin.h"

int player_init() {
    // required to maxmod to work
    irq_init(nullptr); 
	irq_set( II_VBLANK, mmVBlank, 0);
	irq_enable(II_VBLANK);

    mmInitDefault( (mm_addr)soundbank_bin, 8 );
	play();
    return 0;
}