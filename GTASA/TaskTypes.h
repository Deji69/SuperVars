#ifndef __TASKTYPES
#define __TASKTYPES

enum eTaskType
{
    //player tasks
    TASK_SIMPLE_PLAYER_ON_FOOT = 0,

    TASK_SIMPLE_PLAYER_IN_CAR,

    //emergency services tasks
    TASK_COMPLEX_MEDIC_TREAT_INJURED_PED = 100,
    TASK_COMPLEX_TREAT_ACCIDENT,
    TASK_SIMPLE_GIVE_CPR,
    TASK_COMPLEX_COP_ARREST_PED,
    TASK_COMPLEX_COP_HASSLE_PED,
    TASK_COMPLEX_HASSLED_BY_COP,
    TASK_COMPLEX_PRESENT_ID_TO_COP,
    TASK_COMPLEX_DRIVE_FIRE_TRUCK,
    TASK_COMPLEX_USE_SWAT_ROPE,
    TASK_COMPLEX_USE_WATER_CANNON,
    TASK_COMPLEX_EXTINGUISH_FIRE_ON_FOOT,
    //SCRIPT_DECISION

    //basic tasks
    TASK_NONE = 200,
    //SCRIPT_DECISION
    TASK_SIMPLE_UNINTERRUPTABLE,
    TASK_SIMPLE_PAUSE,
    //SCRIPT_DECISION
    TASK_SIMPLE_STAND_STILL,
    //SCRIPT_DECISION
    TASK_SIMPLE_SET_STAY_IN_SAME_PLACE,
    TASK_SIMPLE_GET_UP,                                 
    TASK_COMPLEX_GET_UP_AND_STAND_STILL,
    TASK_SIMPLE_FALL,
    TASK_COMPLEX_FALL_AND_GET_UP,
    //SCRIPT_DECISION
    TASK_COMPLEX_FALL_AND_STAY_DOWN,
    //SCRIPT_DECISION
    TASK_SIMPLE_JUMP,
    TASK_COMPLEX_JUMP,
    //SCRIPT_DECISION
    TASK_SIMPLE_DIE,
    TASK_SIMPLE_DROWN,
    TASK_SIMPLE_DIE_IN_CAR,
    TASK_COMPLEX_DIE_IN_CAR,
    TASK_SIMPLE_DROWN_IN_CAR,
    TASK_COMPLEX_DIE,
    //SCRIPT_DECISION
    TASK_SIMPLE_DEAD,
    TASK_SIMPLE_TIRED,
    TASK_SIMPLE_SIT_DOWN,
    TASK_SIMPLE_SIT_IDLE,
    TASK_SIMPLE_STAND_UP,
    TASK_COMPLEX_SIT_DOWN_THEN_IDLE_THEN_STAND_UP,
    TASK_COMPLEX_OBSERVE_TRAFFIC_LIGHTS,
    TASK_COMPLEX_OBSERVE_TRAFFIC_LIGHTS_AND_ACHIEVE_HEADING,
    TASK_NOT_USED,              
    TASK_COMPLEX_CROSS_ROAD_LOOK_AND_ACHIEVE_HEADING,
    TASK_SIMPLE_TURN_180,   
    TASK_SIMPLE_HAIL_TAXI,
    TASK_COMPLEX_HIT_RESPONSE,
    TASK_COMPLEX_HIT_BY_GUN_RESPONSE,
    TASK_UNUSED_SLOT,
    TASK_COMPLEX_USE_EFFECT,
    //SCRIPT_DECISION                       
    TASK_COMPLEX_WAIT_AT_ATTRACTOR,
    TASK_COMPLEX_USE_ATTRACTOR,
    TASK_COMPLEX_WAIT_FOR_DRY_WEATHER,
    TASK_COMPLEX_WAIT_FOR_BUS,
    TASK_SIMPLE_WAIT_FOR_BUS,
    TASK_SIMPLE_WAIT_FOR_PIZZA,
    TASK_COMPLEX_IN_AIR_AND_LAND,
    TASK_SIMPLE_IN_AIR,
    TASK_SIMPLE_LAND,
    TASK_COMPLEX_BE_IN_GROUP,
    TASK_COMPLEX_SEQUENCE,
    //SCRIPT_DECISION
    TASK_SIMPLE_CALL_FOR_BACKUP,

    TASK_COMPLEX_USE_PAIRED_ATTRACTOR,
    TASK_COMPLEX_USE_ATTRACTOR_PARTNER,
    TASK_COMPLEX_ATTRACTOR_PARTNER_WAIT,
    TASK_COMPLEX_USE_SCRIPTED_ATTRACTOR, 
    TASK_COMPLEX_ON_FIRE,   
    TASK_SIMPLE_BE_DAMAGED,
    //SCRIPT_DECISION
    TASK_SIMPLE_TRIGGER_EVENT,
    TASK_SIMPLE_RAGDOLL,
    TASK_SIMPLE_CLIMB,
    TASK_SIMPLE_PLAYER_ON_FIRE,         
        TASK_COMPLEX_PARTNER,   
        TASK_COMPLEX_STARE_AT_PED,
    TASK_COMPLEX_USE_CLOSEST_FREE_SCRIPTED_ATTRACTOR,
    //SCRIPT_DECISION
    TASK_COMPLEX_USE_EFFECT_RUNNING,
    //SCRIPT_DECISION
    TASK_COMPLEX_USE_EFFECT_SPRINTING,
    //SCRIPT_DECISION
    TASK_COMPLEX_USE_CLOSEST_FREE_SCRIPTED_ATTRACTOR_RUN,
    //SCRIPT_DECISION
    TASK_COMPLEX_USE_CLOSEST_FREE_SCRIPTED_ATTRACTOR_SPRINT,
    //SCRIPT_DECISION
    TASK_SIMPLE_CHOKING,
    TASK_SIMPLE_IK_CHAIN,
    TASK_SIMPLE_IK_MANAGER, 
    TASK_SIMPLE_IK_LOOK_AT,     
    TASK_COMPLEX_CLIMB,
    TASK_COMPLEX_IN_WATER,
    TASK_SIMPLE_TRIGGER_LOOK_AT,
    //SCRIPT_DECISION
    TASK_SIMPLE_CLEAR_LOOK_AT,
    TASK_SIMPLE_SET_CHAR_DECISION_MAKER,
    TASK_SIMPLE_IK_POINT_R_ARM,
    TASK_SIMPLE_IK_POINT_L_ARM,
    TASK_COMPLEX_BE_STILL,
    TASK_COMPLEX_USE_SEQUENCE,
    TASK_SIMPLE_SET_KINDA_STAY_IN_SAME_PLACE,
    TASK_COMPLEX_FALL_TO_DEATH,
    TASK_WAIT_FOR_MATCHING_LEADER_AREA_CODES,
                
    //secondary tasks
    TASK_SIMPLE_LOOK_AT_ENTITY_OR_COORD = 300,
    //SCRIPT_DECISION
    TASK_SIMPLE_SAY,
    //SCRIPT_DECISION
    TASK_SIMPLE_SHAKE_FIST,
    //SCRIPT_DECISION
    TASK_SIMPLE_FACIAL,
    //SCRIPT_DECISION
        TASK_COMPLEX_CHAINED_FACIAL,
        TASK_COMPLEX_FACIAL,                    
        TASK_SIMPLE_AFFECT_SECONDARY_BEHAVIOUR,
        TASK_SIMPLE_HOLD_ENTITY,
        TASK_SIMPLE_PICKUP_ENTITY,      // these three aren't really secondary tasks
        TASK_SIMPLE_PUTDOWN_ENTITY,     // but they exist around the secondary hold entity
        TASK_COMPLEX_GO_PICKUP_ENTITY,      // task at the start and finish
    TASK_SIMPLE_DUCK_WHILE_SHOTS_WHIZZING,
    //SCRIPT_DECISION

    //anims (tasks that are sub-classes of CTaskSimpleRunUnloopedAnim)    
    TASK_SIMPLE_ANIM = 400,
    TASK_SIMPLE_NAMED_ANIM,
    TASK_SIMPLE_TIMED_ANIM,
    TASK_SIMPLE_HIT_BACK,
    TASK_SIMPLE_HIT_FRONT,
    TASK_SIMPLE_HIT_LEFT,
    TASK_SIMPLE_HIT_RIGHT,
    TASK_SIMPLE_HIT_BY_GUN_BACK,
    TASK_SIMPLE_HIT_BY_GUN_FRONT,
    TASK_SIMPLE_HIT_BY_GUN_LEFT,
    TASK_SIMPLE_HIT_BY_GUN_RIGHT,
    TASK_SIMPLE_HIT_WALL,
    TASK_SIMPLE_COWER,
    //SCRIPT_DECISION
    TASK_SIMPLE_HANDS_UP,
    //SCRIPT_DECISION
    TASK_SIMPLE_HIT_BEHIND,
    TASK_SIMPLE_DUCK,
    //SCRIPT_DECISION
    TASK_SIMPLE_CHAT,
    TASK_COMPLEX_SUNBATHE,
    TASK_SIMPLE_SUNBATHE,
    TASK_SIMPLE_DETONATE,
    TASK_SIMPLE_USE_ATM,
    TASK_SIMPLE_SCRATCH_HEAD,
    TASK_SIMPLE_LOOK_ABOUT,
    TASK_SIMPLE_ABSEIL,
    TASK_SIMPLE_ANIM_LOOPED_MIDDLE,
    TASK_SIMPLE_HANDSIGNAL_ANIM,
    TASK_COMPLEX_HANDSIGNAL_ANIM,
    TASK_SIMPLE_DUCK_FOREVER,
    //SCRIPT_DECISION
    TASK_SIMPLE_START_SUNBATHING,
    TASK_SIMPLE_IDLE_SUNBATHING,
    TASK_SIMPLE_STOP_SUNBATHING,
        
    //collision response tasks
    TASK_SIMPLE_HIT_HEAD = 500,
    TASK_SIMPLE_EVASIVE_STEP,          
    TASK_COMPLEX_EVASIVE_STEP,                                
    TASK_SIMPLE_EVASIVE_DIVE,   
    TASK_COMPLEX_EVASIVE_DIVE_AND_GET_UP,
    TASK_COMPLEX_HIT_PED_WITH_CAR,
    TASK_SIMPLE_KILL_PED_WITH_CAR,
    TASK_SIMPLE_HURT_PED_WITH_CAR,   
    TASK_COMPLEX_WALK_ROUND_CAR,
    //SCRIPT_DECISION
    TASK_COMPLEX_WALK_ROUND_BUILDING_ATTEMPT,
    TASK_COMPLEX_WALK_ROUND_OBJECT,
    //SCRIPT_DECISION
    TASK_COMPLEX_MOVE_BACK_AND_JUMP,
    TASK_COMPLEX_EVASIVE_COWER,
    TASK_COMPLEX_DIVE_FROM_ATTACHED_ENTITY_AND_GET_UP,
    //SCRIPT_DECISION
    TASK_COMPLEX_WALK_ROUND_FIRE,
    //SCRIPT_DECISION
    TASK_COMPLEX_STUCK_IN_AIR,

    //threat response tasks
        TASK_COMPLEX_INVESTIGATE_DEAD_PED = 600,
    //SCRIPT_DECISION
    TASK_COMPLEX_REACT_TO_GUN_AIMED_AT,
    //SCRIPT_DECISION
        TASK_COMPLEX_WAIT_FOR_BACKUP,
    TASK_COMPLEX_GET_OUT_OF_WAY_OF_CAR,
    //SCRIPT_DECISION
    TASK_COMPLEX_EXTINGUISH_FIRES,
    //SCRIPT_DECISION

    //car tasks

    //public car tasks 
    TASK_COMPLEX_ENTER_CAR_AS_PASSENGER = 700,
    //SCRIPT_DECISION
    TASK_COMPLEX_ENTER_CAR_AS_DRIVER,
    //SCRIPT_DECISION
    TASK_COMPLEX_STEAL_CAR,
    //SCRIPT_DECISION
    TASK_COMPLEX_DRAG_PED_FROM_CAR,
    //SCRIPT_DECISION
    TASK_COMPLEX_LEAVE_CAR,
    //SCRIPT_DECISION
    TASK_COMPLEX_LEAVE_CAR_AND_DIE,
    //SCRIPT_DECISION
    TASK_COMPLEX_LEAVE_CAR_AND_FLEE,
    //SCRIPT_DECISION
    TASK_COMPLEX_LEAVE_CAR_AND_WANDER,
    //SCRIPT_DECISION
    TASK_COMPLEX_SCREAM_IN_CAR_THEN_LEAVE,
    //SCRIPT_DECISION
    TASK_SIMPLE_CAR_DRIVE,
    //SCRIPT_DECISION
    TASK_COMPLEX_CAR_DRIVE_TO_POINT,
    //SCRIPT_DECISION
    TASK_COMPLEX_CAR_DRIVE_WANDER,
    //SCRIPT_DECISION
    TASK_COMPLEX_ENTER_CAR_AS_PASSENGER_TIMED,
    //SCRIPT_DECISION
    TASK_COMPLEX_ENTER_CAR_AS_DRIVER_TIMED,
    //SCRIPT_DECISION
    TASK_COMPLEX_LEAVE_ANY_CAR,
    //SCRIPT_DECISION
    TASK_COMPLEX_ENTER_BOAT_AS_DRIVER,

    TASK_COMPLEX_LEAVE_BOAT,
        TASK_COMPLEX_ENTER_ANY_CAR_AS_DRIVER,
        TASK_COMPLEX_ENTER_CAR_AS_PASSENGER_WAIT,
        TASK_SIMPLE_CAR_DRIVE_TIMED,
    TASK_COMPLEX_SHUFFLE_SEATS,

    TASK_COMPLEX_CAR_DRIVE_POINT_ROUTE,  
    TASK_COMPLEX_CAR_OPEN_DRIVER_DOOR,   
    TASK_SIMPLE_CAR_SET_TEMP_ACTION,  
    TASK_COMPLEX_CAR_DRIVE_MISSION,
    TASK_COMPLEX_CAR_DRIVE,
    TASK_COMPLEX_CAR_DRIVE_MISSION_FLEE_SCENE,
    //SCRIPT_DECISION   
    TASK_COMPLEX_ENTER_LEADER_CAR_AS_PASSENGER,     
    TASK_COMPLEX_CAR_OPEN_PASSENGER_DOOR,
    TASK_COMPLEX_CAR_DRIVE_MISSION_KILL_PED,
    //SCRIPT_DECISION   
    TASK_COMPLEX_LEAVE_CAR_AS_PASSENGER_WAIT,
               
    //private car tasks (used only by public car tasks)
    TASK_COMPLEX_GO_TO_CAR_DOOR_AND_STAND_STILL = 800,
    TASK_SIMPLE_CAR_ALIGN, 
    TASK_SIMPLE_CAR_OPEN_DOOR_FROM_OUTSIDE,
    TASK_SIMPLE_CAR_OPEN_LOCKED_DOOR_FROM_OUTSIDE,
    TASK_SIMPLE_BIKE_PICK_UP,
    TASK_SIMPLE_CAR_CLOSE_DOOR_FROM_INSIDE,
    TASK_SIMPLE_CAR_CLOSE_DOOR_FROM_OUTSIDE,
    TASK_SIMPLE_CAR_GET_IN,

    TASK_SIMPLE_CAR_SHUFFLE,
    TASK_SIMPLE_CAR_WAIT_TO_SLOW_DOWN,
    TASK_SIMPLE_CAR_WAIT_FOR_DOOR_NOT_TO_BE_IN_USE,
    TASK_SIMPLE_CAR_SET_PED_IN_AS_PASSENGER,  
    TASK_SIMPLE_CAR_SET_PED_IN_AS_DRIVER, 
    TASK_SIMPLE_CAR_GET_OUT,
    TASK_SIMPLE_CAR_JUMP_OUT,
    TASK_SIMPLE_CAR_FORCE_PED_OUT,
    TASK_SIMPLE_CAR_SET_PED_OUT,

    TASK_SIMPLE_CAR_QUICK_DRAG_PED_OUT,
    TASK_SIMPLE_CAR_QUICK_BE_DRAGGED_OUT, 
    TASK_SIMPLE_CAR_SET_PED_QUICK_DRAGGED_OUT,
    TASK_SIMPLE_CAR_SLOW_DRAG_PED_OUT,  
    TASK_SIMPLE_CAR_SLOW_BE_DRAGGED_OUT,     
    TASK_SIMPLE_CAR_SET_PED_SLOW_DRAGGED_OUT,
    TASK_COMPLEX_CAR_SLOW_BE_DRAGGED_OUT,
    TASK_COMPLEX_CAR_SLOW_BE_DRAGGED_OUT_AND_STAND_UP,
    TASK_COMPLEX_CAR_QUICK_BE_DRAGGED_OUT,
    TASK_SIMPLE_BIKE_JACKED,
    TASK_SIMPLE_SET_PED_AS_AUTO_DRIVER,
    TASK_SIMPLE_GO_TO_POINT_NEAR_CAR_DOOR_UNTIL_DOOR_NOT_IN_USE,
    TASK_SIMPLE_WAIT_UNTIL_PED_OUT_CAR,
    TASK_COMPLEX_GO_TO_BOAT_STEERING_WHEEL,
    TASK_COMPLEX_GET_ON_BOAT_SEAT,
        TASK_SIMPLE_CREATE_CAR_AND_GET_IN,
        TASK_SIMPLE_WAIT_UNTIL_PED_IN_CAR,
        TASK_SIMPLE_CAR_FALL_OUT,

    //goto tasks
    TASK_SIMPLE_GO_TO_POINT = 900,
    //SCRIPT_DECISION
    TASK_COMPLEX_GO_TO_POINT_SHOOTING,
    TASK_SIMPLE_ACHIEVE_HEADING,
    TASK_COMPLEX_GO_TO_POINT_AND_STAND_STILL,
    TASK_COMPLEX_GO_TO_POINT_AND_STAND_STILL_AND_ACHIEVE_HEADING,
    TASK_COMPLEX_FOLLOW_POINT_ROUTE,
    TASK_COMPLEX_FOLLOW_NODE_ROUTE,
    TASK_COMPLEX_SEEK_ENTITY,
    //SCRIPT_DECISION
    TASK_COMPLEX_FLEE_POINT,
    //SCRIPT_DECISION                                          
    TASK_COMPLEX_FLEE_ENTITY,
    //SCRIPT_DECISION             
    TASK_COMPLEX_SMART_FLEE_POINT,
    //SCRIPT_DECISION             
    TASK_COMPLEX_SMART_FLEE_ENTITY,
    //SCRIPT_DECISION
    TASK_COMPLEX_WANDER,
    TASK_COMPLEX_FOLLOW_LEADER_IN_FORMATION,
    TASK_COMPLEX_FOLLOW_SEXY_PED,
    //SCRIPT_DECISION
    TASK_COMPLEX_GO_TO_ATTRACTOR,
    TASK_COMPLEX_LEAVE_ATTRACTOR,
    TASK_COMPLEX_AVOID_OTHER_PED_WHILE_WANDERING,
    //SCRIPT_DECISION
    TASK_COMPLEX_GO_TO_POINT_ANY_MEANS,
    TASK_COMPLEX_WALK_ROUND_SHOP,
    TASK_COMPLEX_TURN_TO_FACE_ENTITY,
    //SCRIPT_DECISION
    TASK_COMPLEX_AVOID_BUILDING,
        TASK_COMPLEX_SEEK_ENTITY_ANY_MEANS,   
        TASK_COMPLEX_FOLLOW_LEADER_ANY_MEANS,
        TASK_COMPLEX_GO_TO_POINT_AIMING,    
        TASK_COMPLEX_TRACK_ENTITY,
        TASK_SIMPLE_GO_TO_POINT_FINE,
    TASK_COMPLEX_FLEE_ANY_MEANS,
    //SCRIPT_DECISION
    TASK_COMPLEX_FLEE_SHOOTING,
    TASK_COMPLEX_SEEK_ENTITY_SHOOTING,
    TASK_UNUSED1,
    TASK_COMPLEX_FOLLOW_PATROL_ROUTE,
    TASK_COMPLEX_GOTO_DOOR_AND_OPEN,
    TASK_COMPLEX_SEEK_ENTITY_AIMING,
    //SCRIPT_DECISION
    TASK_SIMPLE_SLIDE_TO_COORD,
    TASK_COMPLEX_INVESTIGATE_DISTURBANCE,
    //SCRIPT_DECISION
    TASK_COMPLEX_FOLLOW_PED_FOOTSTEPS,
        TASK_COMPLEX_FOLLOW_NODE_ROUTE_SHOOTING,   
    TASK_COMPLEX_USE_ENTRYEXIT,
    TASK_COMPLEX_AVOID_ENTITY,
        TASK_SMART_FLEE_ENTITY_WALKING,              

    //fight tasks

        TASK_COMPLEX_KILL_PED_ON_FOOT = 1000,
    //SCRIPT_DECISION
        TASK_COMPLEX_KILL_PED_ON_FOOT_MELEE,
        TASK_COMPLEX_KILL_PED_ON_FOOT_ARMED,
    TASK_COMPLEX_DESTROY_CAR,
    //SCRIPT_DECISION
        TASK_COMPLEX_DESTROY_CAR_MELEE,             
        TASK_COMPLEX_DESTROY_CAR_ARMED,             
    //      TASK_COMPLEX_FIGHT,
    //      TASK_SIMPLE_FIRE_RANGED,
    //      TASK_SIMPLE_FIRE_RANGED_CROUCHED,
    //      TASK_SIMPLE_FIRE_RELOAD,
    //      TASK_SIMPLE_FIRE_SNIPER,

    //      TASK_COMPLEX_ATTACK_RANGED,
    //      TASK_SIMPLE_AIM_GUN,
    //      TASK_SIMPLE_FIGHT_IDLE,
    //      TASK_SIMPLE_FIGHT_SHUFFLE,
    //      TASK_SIMPLE_ATTACK_MELEE,
    //      TASK_SIMPLE_FIRE_PROJECTILE,
    //      TASK_SIMPLE_ATTACK_UNARMED,
    //      TASK_COMPLEX_THROW_PROJECTILE,
    //      TASK_SIMPLE_THROW_WEAPON,
        TASK_COMPLEX_REACT_TO_ATTACK,
        TASK_SIMPLE_BE_KICKED_ON_GROUND,
        TASK_SIMPLE_BE_HIT,
        TASK_SIMPLE_BE_HIT_WHILE_MOVING,
        TASK_COMPLEX_SIDE_STEP_AND_SHOOT,
        TASK_SIMPLE_DRIVEBY_SHOOT,
        TASK_SIMPLE_DRIVEBY_WATCH_FOR_TARGET,
        TASK_COMPLEX_DO_DRIVEBY,
        TASK_KILL_ALL_THREATS,
        TASK_KILL_PED_GROUP_ON_FOOT,

    // new weapon/fight tasks
    TASK_SIMPLE_FIGHT,
    TASK_SIMPLE_USE_GUN,
    TASK_SIMPLE_THROW,
    TASK_SIMPLE_FIGHT_CTRL,
    TASK_SIMPLE_GUN_CTRL,
    //SCRIPT_DECISION
    TASK_SIMPLE_THROW_CTRL,
    TASK_SIMPLE_GANG_DRIVEBY,
    //SCRIPT_DECISION

    TASK_COMPLEX_KILL_PED_ON_FOOT_TIMED,        //SCRIPT_DECISION 
    TASK_COMPLEX_KILL_PED_ON_FOOT_STAND_STILL,   //SCRIPT_DECISION 
    TASK_UNUSED2,
    TASK_KILL_PED_ON_FOOT_WHILE_DUCKING,
    //SCRIPT_DECISION 
    TASK_SIMPLE_STEALTH_KILL,
    TASK_COMPLEX_KILL_PED_ON_FOOT_STEALTH,
    //SCRIPT_DECISION 
    TASK_COMPLEX_KILL_PED_ON_FOOT_KINDA_STAND_STILL,
    //SCRIPT_DECISION 
    TASK_COMPLEX_KILL_PED_AND_REENTER_CAR,
    TASK_COMPLEX_ROAD_RAGE,
    //SCRIPT_DECISION       
    TASK_KILL_PED_FROM_BOAT,
        TASK_SIMPLE_SET_CHAR_IGNORE_WEAPON_RANGE_FLAG,
        
        TASK_SEEK_COVER_UNTIL_TARGET_DEAD,
        
    //police tasks

        TASK_SIMPLE_ARREST_PED = 1100,

    TASK_COMPLEX_ARREST_PED,
    //SCRIPT_DECISION
        TASK_SIMPLE_BE_ARRESTED,
        TASK_COMPLEX_POLICE_PURSUIT,
        TASK_COMPLEX_BE_COP,
    TASK_COMPLEX_KILL_CRIMINAL,
    //SCRIPT_DECISION
    TASK_COMPLEX_COP_IN_CAR,
        
    //gang/partner tasks

        TASK_SIMPLE_INFORM_GROUP = 1200,
    //SCRIPT_DECISION
        TASK_COMPLEX_GANG_LEADER, 
    TASK_COMPLEX_PARTNER_DEAL,
    //SCRIPT_DECISION
    TASK_COMPLEX_PARTNER_GREET,
    //SCRIPT_DECISION
    TASK_COMPLEX_PARTNER_CHAT,
    TASK_COMPLEX_GANG_HASSLE_VEHICLE,
    //SCRIPT_DECISION
        TASK_COMPLEX_WALK_WITH_PED,
        TASK_COMPLEX_GANG_FOLLOWER,
        TASK_COMPLEX_WALK_ALONGSIDE_PED,
        TASK_COMPLEX_PARTNER_SHOVE,
    //SCRIPT_DECISION       
        TASK_COMPLEX_SIGNAL_AT_PED,
    //SCRIPT_DECISION
        TASK_COMPLEX_PASS_OBJECT,
    TASK_COMPLEX_GANG_HASSLE_PED,
    //SCRIPT_DECISION
    TASK_COMPLEX_WAIT_FOR_PED,
    TASK_SIMPLE_DO_HAND_SIGNAL,
    //      TASK_COMPLEX_THROW_OBJECT_BEING_HELD,
        TASK_COMPLEX_BE_IN_COUPLE,
        TASK_COMPLEX_GOTO_VEHICLE_AND_LEAN,
        TASK_COMPLEX_LEAN_ON_VEHICLE,
    //SCRIPT_DECISION
    TASK_COMPLEX_CHAT,
    TASK_COMPLEX_GANG_JOIN_RESPOND,
        
    //misc
    TASK_ZONE_RESPONSE = 1300,
    //SCRIPT_DECISION
    TASK_SIMPLE_TOGGLE_PED_THREAT_SCANNER,
    TASK_FINISHED,
    TASK_SIMPLE_JETPACK,
        TASK_SIMPLE_SWIM,
    TASK_COMPLEX_SWIM_AND_CLIMB_OUT,
    TASK_SIMPLE_DUCK_TOGGLE,
    TASK_WAIT_FOR_MATCHING_AREA_CODES,  
    TASK_SIMPLE_ON_ESCALATOR,
    TASK_COMPLEX_PROSTITUTE_SOLICIT,

    // interior tasks

        TASK_INTERIOR_USE_INFO = 1400,
        TASK_INTERIOR_GOTO_INFO,
        TASK_INTERIOR_BE_IN_HOUSE,
        TASK_INTERIOR_BE_IN_OFFICE,
        TASK_INTERIOR_BE_IN_SHOP,
        TASK_INTERIOR_SHOPKEEPER,
        TASK_INTERIOR_LIE_IN_BED,
        TASK_INTERIOR_SIT_ON_CHAIR,
        TASK_INTERIOR_SIT_AT_DESK,
        TASK_INTERIOR_LEAVE,
        TASK_INTERIOR_SIT_IN_RESTAURANT,
        TASK_INTERIOR_RESERVED2,
        TASK_INTERIOR_RESERVED3,
        TASK_INTERIOR_RESERVED4,
        TASK_INTERIOR_RESERVED5,
        TASK_INTERIOR_RESERVED6,
        TASK_INTERIOR_RESERVED7,
        TASK_INTERIOR_RESERVED8,
        
    // group tasks
    TASK_GROUP_FOLLOW_LEADER_ANY_MEANS = 1500,
    //SCRIPT_DECISION
    TASK_GROUP_FOLLOW_LEADER_WITH_LIMITS,
    //SCRIPT_DECISION
    TASK_GROUP_KILL_THREATS_BASIC,
    //SCRIPT_DECISION
    TASK_GROUP_KILL_PLAYER_BASIC,
    //SCRIPT_DECISION
    TASK_GROUP_STARE_AT_PED,
    //SCRIPT_DECISION
    TASK_GROUP_FLEE_THREAT,
    //SCRIPT_DECISION
    TASK_GROUP_PARTNER_DEAL,
    //SCRIPT_DECISION
    TASK_GROUP_PARTNER_GREET,
    //SCRIPT_DECISION
    TASK_GROUP_HASSLE_SEXY_PED,
    //SCRIPT_DECISION
    TASK_GROUP_HASSLE_THREAT,
    //SCRIPT_DECISION
    TASK_GROUP_USE_MEMBER_DECISION,
    //SCRIPT_DECISION
    TASK_GROUP_EXIT_CAR,
    //SCRIPT_DECISION
    TASK_GROUP_ENTER_CAR,
    //SCRIPT_DECISION
    TASK_GROUP_ENTER_CAR_AND_PERFORM_SEQUENCE,
    //SCRIPT_DECISION
    TASK_GROUP_RESPOND_TO_LEADER_COMMAND,
    //SCRIPT_DECISION
    TASK_GROUP_HAND_SIGNAL,
    //SCRIPT_DECISION
    TASK_GROUP_DRIVEBY,
    //SCRIPT_DECISION                   
    TASK_GROUP_HASSLE_THREAT_PASSIVE,
    //SCRIPT_DECISION
        
    // phone / goggles tasks
    TASK_COMPLEX_USE_MOBILE_PHONE = 1600,   
    TASK_SIMPLE_PHONE_TALK,
    TASK_SIMPLE_PHONE_IN,
    TASK_SIMPLE_PHONE_OUT,
    TASK_COMPLEX_USE_GOGGLES,   
    TASK_SIMPLE_GOGGLES_ON, 
    TASK_SIMPLE_GOGGLES_OFF,    

    // inform friends
    TASK_SIMPLE_INFORM_RESPECTED_FRIENDS = 1700,
    //SCRIPT_DECISION

    // brain tasks
    TASK_COMPLEX_USE_SCRIPTED_BRAIN = 1800,
    TASK_SIMPLE_FINISH_BRAIN,
    /*
    // test tasks
        TASK_COMPLEX_A,
        TASK_COMPLEX_B, 
        TASK_COMPLEX_C,
        TASK_COMPLEX_D,
        TASK_COMPLEX_E,     
    */                                                             
    MAX_NUM_TASK_TYPES
};

#endif