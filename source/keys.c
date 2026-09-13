#include "keys.h"

#include <maxmod.h>
#include <soundbank.h>
#include <soundbank_bin.h>
#include <tonc.h>

int keys() {

  if (key_hit(KEY_A)) {

    if (mmActive()) {
      mmPause();
    } else {
      mmResume();
    }
    if (key_hit(KEY_START)) {
      SoftReset();
    }
  }

  return 0;
}