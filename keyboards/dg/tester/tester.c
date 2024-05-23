#include "tester.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    // Key Matrix to LED Index
    { 0, 1, 2 },
    { 4, 5, 6 },
    { 8, 9, 10 }
}, {
    // LED Index to Physical Position
    {   4,  2 }, {  76,  2 }, { 148,  2 }, { 220,  2 },
    { 220, 22 }, { 148, 22 }, {  76, 22 }, {   4, 22 },
    {   4, 42 }, {  76, 42 }, { 148, 42 }, { 220, 42 },
    { 220, 62 }, { 148, 62 }, {  76, 62 }, {   4, 62 }
}, {
    // LED Index to Flag
    2, 2, 2, 4,
    2, 2, 2, 4,
    2, 2, 2, 4,
    4, 4, 4, 4
} };
#endif
