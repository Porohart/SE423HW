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
#include "dsp.h"
#include "fpu32/fpu_rfft.h"

typedef enum {
    DAT,
    SET,
    CLEAR,
    TOGGLE
} Command;

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
int16_t ledctl(int index, Command cmd);

