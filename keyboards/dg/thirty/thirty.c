#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    {
        /* Key Matrix to LED Index */
        {  0,  1,  2,  3,  4 },
        {  9,  8,  7,  6,  5 },
        { 10, 11, 12, 13, 14 },
        { 29, 28, 27, 26, 25 },
        { 20, 21, 22, 23, 24 },
        { 19, 18, 17, 16, 15 },
    },
    {
        /* LED Index to Physical Position */
        // Switch LEDs
        {4,4},    {28,4},   {52,4},   {76,4},   {100,4},
        {100,32}, {76,32},  {52,32},  {28,32},  {4,32},
        {4,60},   {28,60},  {52,60},  {76,60},  {100,60},
        {124,60}, {148,60}, {172,60}, {196,60}, {220,60},
        {220,32}, {196,32}, {172,32}, {148,32}, {124,32},
        {124,4},  {148,4},  {172,4},  {196,4},  {220,4},
        // Underglow LEDs
    },
    {
        /* LED Index to Flag */
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4
    }
};
#endif
