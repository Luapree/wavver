#include "display.h"

#include "playbackicons.h"
#include <maxmod.h>
#include <string.h>
#include <tonc.h>

ObjectAttributes oam_object_backbuffer[128];

int display_init() {
  memcpy(&MEM_TILE[4][0], playbackiconsTiles, playbackiconsTilesLen);
  memcpy(MEM_PALETTE, playbackiconsPal, playbackiconsPalLen);

  REG_DISPLAYCONTROL =
      VIDEOMODE_0 | BACKGROUND_0 | ENABLE_OBJECTS | MAPPINGMODE_1D;

  return 0;
}

int icons() {
  if (mmActive()) {
    IconsSetToPlay();
  } else {
    IconsSetToPause();
  }
}

int IconsSetToPlay() {
  ObjectAttributes *spriteAttribs = &oam_object_backbuffer[0];
  spriteAttribs->attr0 = 0x2080;
  spriteAttribs->attr1 = 0x0070;
  spriteAttribs->attr2 = 0x0002;
  SELF_MEM_OAM[0] = oam_object_backbuffer[0];
}

int IconsSetToPause() {
  ObjectAttributes *spriteAttribs = &oam_object_backbuffer[0];
  spriteAttribs->attr0 = 0x2080;
  spriteAttribs->attr1 = 0x2070;
  spriteAttribs->attr2 = 0x0006;

  SELF_MEM_OAM[0] = oam_object_backbuffer[0];
}
