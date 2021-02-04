#ifndef _GUARD_SPEEDCHOICE_H
#define _GUARD_SPEEDCHOICE_H

// global speedchoice config
#define CURRENT_OPTIONS_NUM 22 // be sure to count preset too and player name
#define MAX_CHOICES 6
#define OPTIONS_PER_PAGE 5
#define ALLOPTIONS_PER_PAGE OPTIONS_PER_PAGE + 2 // page + start game
#define MAX_PAGES 5

#define MENUOPTIONCOORDS(i) (5 + (2 * i))

#define SPINNER_HELL_TIMER 4 // once every 2 frames since the game runs at 60FPS.
#define MAX_VISION_RANGE 8
#define PURGE_SPINNER_TIMER 48
#define BATTLE_SPEED_FRACTION 4

// for a future version
#define GRASS_QUEUE_SIZE 20
#define WATER_QUEUE_SIZE 15
#define ROCKSMASH_QUEUE_SIZE 15
#define FISHING_QUEUE_SIZE 5

#define oldmin(a, b) (a < b ? a : b)
#define oldmax(a, b) (a > b ? a : b)

// options
enum
{
    PRESET,
    PLAYER_NAME_SET,
    EXPMATH,
    PLOTLESS,
    INSTANTTEXT,
    SPINNERS,
    MAXVISION,
    NERFROXANNE,
    SUPERBIKE,
    NEWWILDENC,
    EARLYFLY,
    RUN_EVERYWHERE,
    MEME_ISLAND,
    BETTER_MARTS,
    GOOD_EARLY_WILDS,
    EARLYSURF,
    NICE_MENU_ORDER,
    EASY_FALSE_SWIPE,
    FAST_CATCH,
    EARLY_BIKE,
    FAST_EGG_HATCH,
    GEN_7_X_ITEMS,

    // STATIC OPTIONS
    PAGE,
    START_GAME
};

enum
{
    FIRST,
    LAST
};

// We used to share the enums for options, but we don't anymore because it's confusing as fuck.
// Please define enums for each option and have them match the option config.

// EXP
enum
{
    EXP_KEEP,
    EXP_BW,
    EXP_NONE
};

// PLOTLESS
enum
{
    PLOT_SEMI,
    PLOT_KEEP,
    PLOT_FULL
};

// INSTANT TEXT
enum
{
    IT_ON,
    IT_OFF
};

// SPINNERS
enum
{
    SPIN_NERF,
    SPIN_KEEP,
    SPIN_HELL,
    SPIN_WHY
};

// MAX VISION
enum
{
    MAX_OFF,
    MAX_SANE,
    MAX_HELL
};

// NERF ROXANNE
enum
{
    NERF_YES,
    NERF_NO
};

// SUPER BIKE
enum
{
    BIKE_ON,
    BIKE_OFF
};

// NEW WILD ENC
enum
{
    NEW_ON,
    NEW_OFF
};

// EARLY FLY
enum
{
    FLY_YES,
    FLY_NO
};

// RUN EVERYWHERE
enum
{
    RUN_ON,
    RUN_OFF
};

// MEME ISLAND
enum
{
    MEME_BIG, // dot net
    MEME_SMALL // you're banned
};

// BETTER MARTS
enum
{
    MARTS_ON,
    MARTS_OFF
};

// GOOD EARLY WILDS
enum
{
    GOOD_OFF,
    GOOD_STATIC,
    GOOD_RAND
};

// EARLY SURF
enum
{
    SURF_ON,
    SURF_OFF
};

// PARTY MENU
enum
{
    NICE_MENU_ORDER_ON,
    NICE_MENU_ORDER_OFF
};

// EASY FALSE SWIPE
enum
{
    EASY_FALSE_SWIPE_OFF,
    EASY_FALSE_SWIPE_TUTOR,
    EASY_FALSE_SWIPE_HM05
};

// FAST CATCH
enum
{
    FAST_CATCH_ON,
    FAST_CATCH_OFF
};

// EARLY BIKE
enum
{
    EARLY_BIKE_YES,
    EARLY_BIKE_NO
};

//FAST EGG HATCHING
enum
{
    FAST_EGG_HATCH_YES,
    FAST_EGG_HATCH_NO
};

//GEN 7 X ITEMS
enum
{
    GEN_7_X_ITEMS_ON,
    GEN_7_X_ITEMS_OFF
};

// option types
enum
{
    NORMAL, // selectable
    ARROW,
    PLAYER_NAME
};

struct OptionChoiceConfig
{
    s16 x; // do not store the Y coordinate. Y is automatically calculated depending on the row the option is placed and therefore is not necessary.
    u8 *string; // can be null
};

// every 5 elements belongs to a page, page struct is unnecessary.
struct SpeedchoiceOption
{
    u8 optionCount; // needed for process general input, im sure there's a way to avoid using this
    u8 optionType;
    const u8 *string;
    const struct OptionChoiceConfig *options; // use a NULL for non existent ones, optional things in structs were introduced in C++ and this is limited.
    const u8 *tooltip;
    bool8 enabled;
}; 

struct SpeedchoiceConfigStruct
{
    u8 optionConfig[CURRENT_OPTIONS_NUM];
    u8 trueIndex;
    u8 pageIndex;
    u8 pageNum;
};

struct MapObjectTimerBackup
{
    bool8 backedUp;
    s16 spriteId;
    s16 timer;
};

// we need to extern the randomizer check value. If the ROM could see the value assigned (which is 0 by default), then it would be optimized out, but we need this location to be externally written to by the randomizer.
extern u32 gRandomizerCheckValue;

void CB2_InitSpeedchoiceMenu(void);
bool8 CheckSpeedchoiceOption(u8, u8);

#endif // _GUARD_SPEEDCHOICE_H
