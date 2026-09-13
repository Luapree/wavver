#ifndef DISPLAY_H
#define DISPLAY_H

extern int icons();
extern int display_init();

extern int IconsSetToPlay();

extern int IconsSetToPause();

// all under this referenced https://github.com/khalladay/GBA-By-Example/blob/master/4-SpriteAnimation/code/gba.h, licensed under MIT license
typedef unsigned short     uint16;

typedef uint16 Tile[32];
typedef Tile TileBlock[256];

typedef struct ObjectAttributes {
	uint16 attr0;
	uint16 attr1;
	uint16 attr2;
	uint16 pad;
} __attribute__((packed, aligned(4))) ObjectAttributes;

// putting self_ on oam and vcount so it dosent conflict with libtonc
#define MEM_TILE		        ((TileBlock*)0x6000000)
#define MEM_PALETTE             ((uint16*)(0x05000200))
#define SELF_MEM_OAM            ((volatile ObjectAttributes *)0x07000000)
#define VIDEOMODE_0    0x0000
#define ENABLE_OBJECTS 0x1000
#define MAPPINGMODE_1D 0x0040
#define BACKGROUND_0   0x0100
#define BACKGROUND_1   0x0200
#define REG_DISPLAYCONTROL     *((volatile uint16*)(0x04000000))
#define SELF_REG_VCOUNT             *((volatile uint16*)(0x04000006))

inline void vsync()
{
    while (SELF_REG_VCOUNT >= 160);
    while (SELF_REG_VCOUNT < 160);
}

#endif // DISPLAY_H