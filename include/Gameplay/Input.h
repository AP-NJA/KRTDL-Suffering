#ifndef INPUT_H_
#define INPUT_H_

#include "Common/Common.h"

#define PAD_LEFT 0x0001
#define PAD_RIGHT 0x0002
#define PAD_DOWN 0x0004
#define PAD_UP 0x0008
#define PAD_TWO 0x0010
#define PAD_ONE 0x0020
#define PAD_A 0x00C0
#define PAD_SELECT 0x0100
#define PAD_B 0x0200
#define PAD_HOME 0x8000

struct Hero;

typedef struct Input
{
    Hero * mHeroData;
    u32 mControllerInput;
    u32 mInputReceived;
    u32 mInputParsed;

    u8 wasInputPressed(); // 804ee788

    // Custom functions
    u8 onComboPress(u32 value, u32 input);
} Input;

#endif
