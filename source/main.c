#include "display.h"
#include "keys.h"
#include "player.h"

#include <tonc.h>

#include "soundbank.h"
#include "soundbank_bin.h"
#include <maxmod.h>
#include <stdio.h>

int main() {
  player_init();
  display_init();
  play();

  while (1) {
    mmFrame();
    VBlankIntrWait();
    key_poll();
    icons();
    keys();
  }

  return 0;
} // when haces tus momos en el main.c: el futuro es hoy oiste viejo :vvv
// pero te termina crasheando: ohh mi lente de contacto :vvv xdxdxddx