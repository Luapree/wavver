#include "keys.h"
#include "display.h"
#include "player.h"

#include <tonc.h>

#include <maxmod.h>
#include "soundbank.h"
#include "soundbank_bin.h"
#include <stdio.h>

int main () {
	player_init();
	display_init();

	while(1) {
		mmFrame();
		VBlankIntrWait();
		key_poll();
		icons();
		keys();
	}

	return 0;
} // when haces tus momos en el main.c: el futuro es hoy oiste viejo :vvv 
// pero te termina crasheando: ohh mi lente de contacto :vvv xdxdxddx