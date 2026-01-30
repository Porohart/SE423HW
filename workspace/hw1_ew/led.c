#pragma once

// Included Files
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include "F28x_Project.h"
#include "driverlib.h"
#include "device.h"
#include "F28379dSerial.h"
#include "LEDPatterns.h"
#include "song.h"
#include "dsp.h"
#include "fpu32/fpu_rfft.h"

typedef enum {
    DAT,
    SET,
    CLEAR,
    TOGGLE
} Command

int16_t led1(Command);
int16_t led2(Command);
int16_t led3(Command);
int16_t led4(Command);
int16_t led5(Command);
int16_t led6(Command);
int16_t led7(Command);
int16_t led8(Command);
int16_t led9(Command);
int16_t led10(Command);
int16_t led11(Command);
int16_t led12(Command);
int16_t led13(Command);
int16_t led14(Command);
int16_t led15(Command);
int16_t led16(Command);
int16_t led(int index, Command cmd);

int16_t (*led_func_array[])(Command) = { led1, led2, led3, led4, led5, led6, led7, led8, led9, led10, led11, led12, led13, led14, led15, led16 };

int16_t ledctl(int index, Command cmd) {
    if(index < 0 || index >= 16) return -1;
    return (*led_func_array[index])(cmd);
}

int16_t led1(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPADAT.bit.GPIO22;
    case SET:
        GpioDataRegs.GPASET.bit.GPIO22 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPACLEAR.bit.GPIO22 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPATOGGLE.bit.GPIO22 = 1;
        return 0;
    default:
        return -1;
    }
}

int16_t led2(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPCDAT.bit.GPIO94;
    case SET:
        GpioDataRegs.GPCSET.bit.GPIO94 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPCCLEAR.bit.GPIO94 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPCTOGGLE.bit.GPIO94 = 1;
        return 0;
    default:
        return -1;
    }
}

int16_t led3(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPCDAT.bit.GPIO95;
    case SET:
        GpioDataRegs.GPCSET.bit.GPIO95 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPCCLEAR.bit.GPIO95 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPCTOGGLE.bit.GPIO95 = 1;
        return 0;
    default:
        return -1;
    }
}

int16_t led4(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPDDAT.bit.GPIO97;
    case SET:
        GpioDataRegs.GPDSET.bit.GPIO97 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPDCLEAR.bit.GPIO97 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPDTOGGLE.bit.GPIO97 = 1;
        return 0;
    default:
        return -1;
    }
}


int16_t led5(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPDDAT.bit.GPIO111;
    case SET:
        GpioDataRegs.GPDSET.bit.GPIO111 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPDCLEAR.bit.GPIO111 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPDTOGGLE.bit.GPIO111 = 1;
        return 0;
    default:
        return -1;
    }
}

int16_t led6(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPEDAT.bit.GPIO130;
    case SET:
        GpioDataRegs.GPESET.bit.GPIO130 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPECLEAR.bit.GPIO130 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPETOGGLE.bit.GPIO130 = 1;
        return 0;
    default:
        return -1;
    }
}

int16_t led7(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPEDAT.bit.GPIO131;
    case SET:
        GpioDataRegs.GPESET.bit.GPIO131 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPECLEAR.bit.GPIO131 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPETOGGLE.bit.GPIO131 = 1;
        return 0;
    default:
        return -1;
    }
}

int16_t led8(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPADAT.bit.GPIO25;
    case SET:
        GpioDataRegs.GPASET.bit.GPIO25 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPACLEAR.bit.GPIO25 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPATOGGLE.bit.GPIO25 = 1;
        return 0;
    default:
        return -1;
    }
}

int16_t led9(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPADAT.bit.GPIO26;
    case SET:
        GpioDataRegs.GPASET.bit.GPIO26 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPATOGGLE.bit.GPIO26 = 1;
        return 0;
    default:
        return -1;
    }
}

int16_t led10(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPADAT.bit.GPIO27;
    case SET:
        GpioDataRegs.GPASET.bit.GPIO27 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPATOGGLE.bit.GPIO27 = 1;
        return 0;
    default:
        return -1;
    }
}

int16_t led11(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPBDAT.bit.GPIO60;
    case SET:
        GpioDataRegs.GPBSET.bit.GPIO60 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPBCLEAR.bit.GPIO60 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPBTOGGLE.bit.GPIO60 = 1;
        return 0;
    default:
        return -1;
    }
}

int16_t led12(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPBDAT.bit.GPIO61;
    case SET:
        GpioDataRegs.GPBSET.bit.GPIO61 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPBCLEAR.bit.GPIO61 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPBTOGGLE.bit.GPIO61 = 1;
        return 0;
    default:
        return -1;
    }
}

int16_t led13(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPEDAT.bit.GPIO157;
    case SET:
        GpioDataRegs.GPESET.bit.GPIO157 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPECLEAR.bit.GPIO157 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPETOGGLE.bit.GPIO157 = 1;
        return 0;
    default:
        return -1;
    }
}

int16_t led14(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPEDAT.bit.GPIO158;
    case SET:
        GpioDataRegs.GPESET.bit.GPIO158 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPECLEAR.bit.GPIO158 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPETOGGLE.bit.GPIO158 = 1;
        return 0;
    default:
        return -1;
    }
}

int16_t led15(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPEDAT.bit.GPIO159;
    case SET:
        GpioDataRegs.GPESET.bit.GPIO159 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPECLEAR.bit.GPIO159 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPETOGGLE.bit.GPIO159 = 1;
        return 0;
    default:
        return -1;
    }
}

int16_t led16(Command cmd) {
    switch(cmd) {
    case DAT:
        return GpioDataRegs.GPFDAT.bit.GPIO160;
    case SET:
        GpioDataRegs.GPFSET.bit.GPIO160 = 1;
        return 0;
    case CLEAR:
        GpioDataRegs.GPFCLEAR.bit.GPIO160 = 1;
        return 0;
    case TOGGLE:
        GpioDataRegs.GPFTOGGLE.bit.GPIO160 = 1;
        return 0;
    default:
        return -1;
    }
}
