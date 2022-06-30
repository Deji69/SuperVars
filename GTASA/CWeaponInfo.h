#ifndef __CWEAPONINFO
#define __CWEAPONINFO

enum eWeaponSkill
{
    WEAPONSKILL_POOR = 0,
    WEAPONSKILL_STD,
    WEAPONSKILL_PRO,
    WEAPONSKILL_SPECIAL,    // for cops using pistols differently for example
    WEAPONSKILL_MAX_NUMBER
};

enum eFireType
{
    FIRETYPE_MELEE,
    FIRETYPE_INSTANT_HIT,
    FIRETYPE_PROJECTILE,
    FIRETYPE_AREA_EFFECT,
    FIRETYPE_CAMERA,
    FIRETYPE_USE,

    FIRETYPE_LAST_FIRETYPE
};

enum eWeaponSlot
{
    WEAPONSLOT_TYPE_UNARMED = 0,
    WEAPONSLOT_TYPE_MELEE,
    WEAPONSLOT_TYPE_HANDGUN,
    WEAPONSLOT_TYPE_SHOTGUN,
    WEAPONSLOT_TYPE_SMG,        //4
    WEAPONSLOT_TYPE_MG, 
    WEAPONSLOT_TYPE_RIFLE,
    WEAPONSLOT_TYPE_HEAVY,
    WEAPONSLOT_TYPE_THROWN,
    WEAPONSLOT_TYPE_SPECIAL,    //9
    WEAPONSLOT_TYPE_GIFT,       //10
    WEAPONSLOT_TYPE_PARACHUTE,  //11
    WEAPONSLOT_TYPE_DETONATOR,  //12

    WEAPONSLOT_MAX
};

enum eWeaponState
{
    WEAPONSTATE_READY,
    WEAPONSTATE_FIRING,
    WEAPONSTATE_RELOADING,
    WEAPONSTATE_OUT_OF_AMMO,
    WEAPONSTATE_MELEE_MADECONTACT
};

/**
 * Contains the weapon types/models
 */
enum eWeaponType
{
    WEAPONTYPE_UNARMED=0,
    WEAPONTYPE_BRASSKNUCKLE, 
    WEAPONTYPE_GOLFCLUB,
    WEAPONTYPE_NIGHTSTICK,
    WEAPONTYPE_KNIFE,
    WEAPONTYPE_BASEBALLBAT,
    WEAPONTYPE_SHOVEL,
    WEAPONTYPE_POOL_CUE,
    WEAPONTYPE_KATANA,
    WEAPONTYPE_CHAINSAW,
    
    // gifts
    WEAPONTYPE_DILDO1, // 10
    WEAPONTYPE_DILDO2,
    WEAPONTYPE_VIBE1,
    WEAPONTYPE_VIBE2,
    WEAPONTYPE_FLOWERS,
    WEAPONTYPE_CANE,

    WEAPONTYPE_GRENADE,
    WEAPONTYPE_TEARGAS,
    WEAPONTYPE_MOLOTOV,
    WEAPONTYPE_ROCKET,
    WEAPONTYPE_ROCKET_HS, // 20
    WEAPONTYPE_FREEFALL_BOMB,

    // FIRST SKILL WEAPON
    WEAPONTYPE_PISTOL,          // handguns
    WEAPONTYPE_PISTOL_SILENCED,
    WEAPONTYPE_DESERT_EAGLE,
    WEAPONTYPE_SHOTGUN,         // shotguns
    WEAPONTYPE_SAWNOFF_SHOTGUN, // one handed
    WEAPONTYPE_SPAS12_SHOTGUN,
    WEAPONTYPE_MICRO_UZI,       // submachine guns
    WEAPONTYPE_MP5,
    WEAPONTYPE_AK47, // 30      // machine guns 
    WEAPONTYPE_M4,          
    WEAPONTYPE_TEC9,            // this uses stat from the micro_uzi
    // END SKILL WEAPONS
    
    WEAPONTYPE_COUNTRYRIFLE,    // rifles
    WEAPONTYPE_SNIPERRIFLE, 
    WEAPONTYPE_ROCKETLAUNCHER,  // specials
    WEAPONTYPE_ROCKETLAUNCHER_HS,
    WEAPONTYPE_FLAMETHROWER,
    WEAPONTYPE_MINIGUN,
    WEAPONTYPE_REMOTE_SATCHEL_CHARGE,
    WEAPONTYPE_DETONATOR, // 40 // plastic explosive
    WEAPONTYPE_SPRAYCAN,
    WEAPONTYPE_EXTINGUISHER,
    WEAPONTYPE_CAMERA,
    WEAPONTYPE_NIGHTVISION,
    WEAPONTYPE_INFRARED,
    WEAPONTYPE_PARACHUTE,
    WEAPONTYPE_LAST_WEAPONTYPE,

    WEAPONTYPE_ARMOUR,
    // these are possible ways to die
    WEAPONTYPE_RAMMEDBYCAR,
    WEAPONTYPE_RUNOVERBYCAR, // 50
    WEAPONTYPE_EXPLOSION,
    WEAPONTYPE_UZI_DRIVEBY,
    WEAPONTYPE_DROWNING,
    WEAPONTYPE_FALL,
    WEAPONTYPE_UNIDENTIFIED,    // Used for damage being done
    WEAPONTYPE_ANYMELEE,
    WEAPONTYPE_ANYWEAPON,
    WEAPONTYPE_FLARE,

    // Added by us
    WEAPONTYPE_TANK_GRENADE,
};

//////////////////////////////////////////////
// flags used to define weapon characteristics

// aiming options
#define WEAPONTYPE_CANAIM           (0x000001)  // can auto target to aim
#define WEAPONTYPE_CANAIMWITHARM    (0x000002)  // only needs arm to aim
#define WEAPONTYPE_FIRSTPERSON      (0x000004)  // uses 1st person aim
#define WEAPONTYPE_CANFREEAIM       (0x000008)  // can only use free aiming

// movement options
#define WEAPONTYPE_MOVEAIM          (0x000010)  // can move and aim at same time
#define WEAPONTYPE_MOVEFIRE         (0x000020)  // can move and fire at same time

// basic characteristics
#define WEAPONTYPE_THROW            (0x000100)  // is a throwing weapon
#define WEAPONTYPE_HEAVY            (0x000200)  // heavy weapon - can't jump
#define WEAPONTYPE_CONTINUOUS_FIRE  (0x000400)  // fires every frame within loop (ie paint spray)
#define WEAPONTYPE_TWIN_PISTOLS     (0x000800)  // can use 2x guns at same time

// these are gun anim options
#define WEAPONTYPE_ANIM_RELOAD      (0x001000)  // weapon has reload anims
#define WEAPONTYPE_ANIM_CROUCHFIRE  (0x002000)  // weapon has crouching anims
#define WEAPONTYPE_RELOAD2LOOPSTART (0x004000)  // loop from end of reload to fire loop start
#define WEAPONTYPE_LONG_RELOAD_TIME (0x008000)  // force a longer reload time!

// these are area effect/shot options
#define WEAPONTYPE_SLOWS_DOWN       (0x010000)  // 
#define WEAPONTYPE_RANDOM_SPEED     (0x020000)  // 
#define WEAPONTYPE_FORCE_FINISH_ANIM (0x040000)  // force the anim to finish player after aim/fire rather than blending out
#define WEAPONTYPE_EXPANDS          (0x080000)  // 

#endif