#ifndef     TEP70_SIGNALS_H
#define     TEP70_SIGNALS_H

enum
{
    KM_SHTURVAL = 0,
    KM_REVERSOR = 1,

    KRM_395 = 2,
    KVT_254_ROTATE = 3,
    KVT_254_TRANSLATE = 4,

    BRAKE_FORCE = 5,

    AZV_COMMON_CONTROL = 6,
    AZV_UPR_TEPL = 7,
    AZV_FUEL_PUMP = 8,
    AZV_PANEL_LIGHT = 9,
    AZV_CABINE_LIGHT = 10,
    AZV_EDT_ON = 11,
    AZV_EDT_POWER = 12,
    AZV_EPT_ON = 13,
    AZV_SPOTLIGHT_LOW = 14,
    AZV_SPOTLIGHT_HIGH = 15,

    TUMBLER_FIELD_WEAK1 = 16,
    TUMBLER_FIELD_WEAK2 = 17,
    TUMBLER_WATER_ZALUZI = 18,
    TUMBLER_OIL_ZALUZI = 65,

    BUTTON_DISEL_START = 19,
    BUTTON_BRAKE_RELEASE = 20,
    BUTTON_SVISTOK = 21,
    BUTTON_TIFON = 22,

    SIGLIGHT_EPT_O = 23,
    SIGLIGHT_EPT_P = 24,
    SIGLIGHT_EPT_T = 25,

    SIGLIGHT_EDT1 = 26,
    SIGLIGHT_EDT2 = 27,

    SIGLIGHT_RESET_POWER = 28,
    SIGLIGHT_OIL_TEMP = 29,
    SIGLIGHT_OIL_PRESS = 30,
    SIGLIGHT_ZHAL_ET1 = 31,
    SIGLIGHT_ZHAL_ET2 = 32,
    SIGLIGHT_ZB = 33,

    SIGLIGHT_RES_FUELPUMP = 34,
    SIGLIGHT_FIRE_L = 35,
    SIGLIGHT_FIRE_R = 36,
    SIGLIGHT_BRAKE_RESISTORS = 37,
    SIGLIGHT_KALORIPHER = 38,

    SIGLIGHT_PROP = 39,
    SIGLIGHT_PSS = 40,

    STRELKA_UR = 41,
    STRELKA_TM = 42,
    STRELKA_PM = 43,
    STRELKA_TC1 = 44,
    STRELKA_TC2 = 45,

    STRELKA_REF_SPEED = 46,
    STRELKA_REOSTATE_CURRENT = 47,
    STRELKA_GEN_CURRENT = 48,

    STRELKA_WATER_TEMP = 49,
    STRELKA_OIL_TEMP = 50,
    STRELKA_OIL_PRESS = 51,
    STRELKA_FUEL_PRESS = 64,

    STRELKA_BAT_VOLTAGE = 52,
    STRELKA_BAT_CURRENT = 53,
    STRELKA_GEN_VOLTAGE = 54,
    STRELKA_FAILS_INDICATOR = 55,

    STRELKA_SPEED = 56,


    LS_G = 57,
    LS_Y = 58,
    LS_YR = 59,
    LS_R = 60,
    LS_W = 61,

    TUMBLER_VOLTMETER = 62,
    TUMBLER_DISEL_STOP = 63,

    RUK_367 = 66,
    COMB_KRAN = 67,
    KRAN_395_RUK = 68,
    KRAN_254_POD = 69,
    KRAN_254_RUK = 70,

    KLUCH_EPK = 71,
    RB1 = 72,

    VAL_PRSKOR1 = 73,
    VAL_PRSKOR2 = 74,

    WHEEL_1 = 194,
    WHEEL_2 = 195,
    WHEEL_3 = 196,
    WHEEL_4 = 197,
    WHEEL_5 = 198,
    WHEEL_6 = 199,

    SOUND_TUMBLER_OP1 = 200,
    SOUND_TUMBLER_OP2 = 201,
    SOUND_TUMBLER_BLINDS_WATER = 202,
    SOUND_TUMBLER_BLINDS_OIL = 203,
    SOUND_AZV_COMMON_CONTROL = 204,
    SOUND_AZV_LOCO_CONTROL = 205,
    SOUND_AZV_FUIL_PUMP = 206,
    SOUND_AZV_EPT = 207,
    SOUND_AZV_EDT = 208,
    SOUND_TUMBLER_VOLTAGE = 209,
    SOUND_TUMBLER_DISEL_STOP = 210,

    SOUND_BRAKE_LOCK_CHANGE_LOCK_POS = 211,
    SOUND_BRAKE_LOCK_CHANGE_COMB_POS = 212,
    SOUND_BRAKE_LOCK_BP_DRAIN_FLOW = 213,
    SOUND_BRAKE_CRANE_CHANGE_POS = 214,
    SOUND_BRAKE_CRANE_ER_STAB_FLOW = 215,
    SOUND_BRAKE_CRANE_ER_FILL_FLOW = 216,
    SOUND_BRAKE_CRANE_ER_DRAIN_FLOW = 217,
    SOUND_BRAKE_CRANE_BP_FILL_FLOW = 218,
    SOUND_BRAKE_CRANE_BP_DRAIN_FLOW = 219,
    SOUND_LOCO_CRANE_CHANGE_POS = 220,
    SOUND_LOCO_CRANE_BC_FILL_FLOW = 221,
    SOUND_LOCO_CRANE_BC_DRAIN_FLOW = 222,

    SOUND_SVISTOK = 223,
    SOUND_TIFON = 224,

    SOUND_FUEL_PUMP = 225,
    SOUND_OIL_PUMP = 226,
    SOUND_STARTER_GENERATOR = 227,

    SOUND_DISEL_X0 = 228,
    SOUND_DISEL_X1 = 229,
    SOUND_DISEL_X2 = 230,
    SOUND_DISEL_X3 = 231,
    SOUND_DISEL_X4 = 232,
    SOUND_DISEL_X5 = 233,
    SOUND_DISEL_X6 = 234,
    SOUND_DISEL_X7 = 235,
    SOUND_DISEL_X8 = 236,
    SOUND_DISEL_X9 = 237,
    SOUND_DISEL_X10 = 238,
    SOUND_DISEL_X11 = 239,
    SOUND_DISEL_X12 = 240,
    SOUND_DISEL_X13 = 241,
    SOUND_DISEL_X14 = 242,
    SOUND_DISEL_X15 = 243
};

#endif // TEP70_SIGNALS_H
