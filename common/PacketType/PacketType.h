/**
 *
 *   ██████╗   ██╗ ███████╗ ███╗   ███╗ ██╗   ██╗
 *   ██╔══██╗ ███║ ██╔════╝ ████╗ ████║ ██║   ██║
 *   ██████╔╝ ╚██║ █████╗   ██╔████╔██║ ██║   ██║
 *   ██╔══██╗  ██║ ██╔══╝   ██║╚██╔╝██║ ██║   ██║
 *   ██║  ██║  ██║ ███████╗ ██║ ╚═╝ ██║ ╚██████╔╝
 *   ╚═╝  ╚═╝  ╚═╝ ╚══════╝ ╚═╝     ╚═╝  ╚═════╝
 *
 * @file PacketType.h
 * @brief PacketType enumerates all the packets used in the game between the client and the server
 *
 * @license GNU GENERAL PUBLIC LICENSE - Version 2, June 1991
 *          See LICENSE file for further information
 */

#pragma once

// ---------- Includes ------------
#include <stdint.h>

// ---------- Defines -------------
#define PACKET_TYPES_MAX_INDEX      (PACKET_TYPE_COUNT + 1)

#define GENERATE_PACKET_TYPE_ENUM(name, id, size) \
	name = id,
#define GENERATE_PACKET_TYPE_ENTRY(_name, _id, _size) \
	{_id, _size, #_name},

// Generic packet types
#pragma pack(push, 1)
typedef struct ServerPacketHeader {
    uint16_t type;
    uint32_t reserved;
} ServerPacketHeader;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct VariableSizePacketHeader {
    ServerPacketHeader serverHeader;
    uint16_t packetSize;
} VariableSizePacketHeader;
#pragma pack(pop)

// ------ Structure declaration -------
#define FOREACH_PACKET_TYPE(GENERATOR) \
    GENERATOR(CB_LOGIN, 3, 66) \
    GENERATOR(CB_LOGIN_BY_PASSPORT, 4, 1068) \
    GENERATOR(CB_LOGOUT, 5, 10) \
    GENERATOR(CB_START_GAME, 11, 13) \
    GENERATOR(CB_START_BARRACK, 6, 11) \
    GENERATOR(CB_COMMANDER_CREATE, 7, 96) \
    GENERATOR(CB_COMMANDER_DESTROY, 8, 11) \
    GENERATOR(CB_CHECK_CLIENT_INTEGRITY, 9, 74) \
    GENERATOR(CB_CLIENT_INTEGRITY_FAIL, 10, 1035) \
    GENERATOR(CB_ECHO, 14, 30) \
    GENERATOR(CB_BARRACKNAME_CHANGE, 12, 74) \
    GENERATOR(CB_COMMANDER_MOVE, 13, 31) \
    GENERATOR(BC_LOGINOK, 15, 121) \
    GENERATOR(BC_LOGIN_PACKET_RECEIVED, 16, 6) \
    GENERATOR(BC_LOGOUTOK, 17, 6) \
    GENERATOR(BC_START_GAMEOK, 21, 33) \
    GENERATOR(BC_SINGLE_INFO, 22, 325) \
    GENERATOR(BC_COMMANDER_LIST, 18, 0) \
    GENERATOR(BC_COMMANDER_CREATE, 19, 334) \
    GENERATOR(BC_COMMANDER_DESTROY, 20, 7) \
    GENERATOR(BC_MESSAGE, 23, 0) \
    GENERATOR(BC_ECHO, 24, 26) \
    GENERATOR(CB_IES_MODIFY_INFO, 70, 0) \
    GENERATOR(BC_IES_MODIFY_INFO, 71, 0) \
    GENERATOR(BC_IES_MODIFY_LIST, 72, 0) \
    GENERATOR(CB_IES_REVISION_DELETE, 73, 0) \
    GENERATOR(BC_IES_REVISION_DELETE, 74, 0) \
    GENERATOR(BC_MYPAGE_MAP, 25, 0) \
    GENERATOR(BC_BARRACKNAME_CHANGE, 26, 75) \
    GENERATOR(CB_VISIT, 75, 74) \
    GENERATOR(CB_BUY_THEMA, 76, 22) \
    GENERATOR(BC_ACCOUNT_PROP, 77, 0) \
    GENERATOR(CB_CURRENT_BARRACK, 78, 39) \
    GENERATOR(BC_NORMAL, 79, 0) \
    GENERATOR(CB_POSE, 80, 15) \
    GENERATOR(CB_PLACE_CMD, 81, 46) \
    GENERATOR(CB_NGS, 96, 10254) \
    GENERATOR(CB_CHAT, 82, 0) \
    GENERATOR(BC_CHAT, 83, 0) \
    GENERATOR(CB_ECHO_NORMAL, 84, 0) \
    GENERATOR(CB_JUMP, 87, 19) \
    GENERATOR(BC_JUMP, 88, 19) \
    GENERATOR(BC_SERVER_ENTRY, 89, 18) \
    GENERATOR(CB_PET_PC, 90, 26) \
    GENERATOR(CB_PET_COMMAND, 91, 27) \
    GENERATOR(CB_REQ_SLOT_PRICE, 85, 10) \
    GENERATOR(BC_REQ_SLOT_PRICE, 86, 10) \
    GENERATOR(CB_REQ_CHANGE_POSTBOX_STATE, 92, 22) \
    GENERATOR(CB_REQ_GET_POSTBOX_ITEM, 93, 30) \
    GENERATOR(BC_WAIT_QUEUE_ORDER, 94, 10) \
    GENERATOR(CB_CANCEL_SERVER_WAIT_QUEUE, 95, 10) \
    GENERATOR(CS_LOGIN, 2901, 64) \
    GENERATOR(SC_NORMAL, 2902, 0) \
    GENERATOR(SC_FROM_INTEGRATE, 2903, 0) \
    GENERATOR(CS_REGISTER_SNS_ID, 2904, 16) \
    GENERATOR(CS_REQ_SNS_PC_INFO, 2905, 0) \
    GENERATOR(CS_REQ_ADD_FRIEND, 2906, 70) \
    GENERATOR(CS_REQ_BLOCK_FRIEND, 2907, 70) \
    GENERATOR(CS_FRIEND_CMD, 2908, 24) \
    GENERATOR(CS_FRIEND_SET_ADDINFO, 2909, 160) \
    GENERATOR(CS_CHAT, 2910, 0) \
    GENERATOR(CS_CREATE_GROUP_CHAT, 2911, 6) \
    GENERATOR(CS_GROUP_CHAT_INVITE, 2912, 78) \
    GENERATOR(CS_REFRESH_GROUP_CHAT, 2913, 6) \
    GENERATOR(CS_CHAT_HISTORY, 2914, 22) \
    GENERATOR(CS_CHAT_READ, 2915, 30) \
    GENERATOR(CS_REMOVE_GROUP_MEMBER, 2916, 14) \
    GENERATOR(CS_ADD_RELATION_SCORE, 2928, 88) \
    GENERATOR(CS_GET_LIKE_COUNT, 2929, 16) \
    GENERATOR(CS_LIKE_IT, 2925, 88) \
    GENERATOR(CS_UNLIKE_IT, 2926, 24) \
    GENERATOR(CS_LIKE_IT_CONFIRM, 2927, 16) \
    GENERATOR(CS_REQ_RELATED_PC_SESSION, 2917, 16) \
    GENERATOR(CS_REDIS_SKILLPOINT, 2918, 22) \
    GENERATOR(CS_PARTY_CLIENT_INFO_SEND, 2919, 0) \
    GENERATOR(CS_NORMAL_GAME_START, 2920, 6) \
    GENERATOR(CS_PVP_COMMAND, 2921, 18) \
    GENERATOR(CS_REQUEST_PVP_RANKING, 2922, 83) \
    GENERATOR(CS_INVITE_PARTY_PVP, 2923, 10) \
    GENERATOR(CS_ACCEPT_PARTY_PVP, 2924, 19) \
    GENERATOR(CZ_CONNECT, 3001, 1200) \
    GENERATOR(CZ_GAME_READY, 3006, 10) \
    GENERATOR(CZ_KEYBOARD_MOVE, 3166, 41) \
    GENERATOR(CZ_EXPECTED_STOP_POS, 3167, 31) \
    GENERATOR(CZ_MOVE_PATH, 3171, 27) \
    GENERATOR(CZ_MOVE_STOP, 3172, 35) \
    GENERATOR(CZ_JUMP, 3168, 11) \
    GENERATOR(CZ_DASHRUN, 3169, 11) \
    GENERATOR(CZ_REST_SIT, 3173, 10) \
    GENERATOR(CZ_REQ_CHAR_SLOT, 3174, 11) \
    GENERATOR(CZ_ON_AIR, 3175, 10) \
    GENERATOR(CZ_ON_GROUND, 3176, 10) \
    GENERATOR(CZ_SKILL_JUMP_REQ, 3170, 30) \
    GENERATOR(CZ_LOGOUT, 3008, 11) \
    GENERATOR(CZ_MOVE_BARRACK, 3009, 11) \
    GENERATOR(CZ_MOVE_ZONE_OK, 3004, 10) \
    GENERATOR(CZ_MOVEMENT_INFO, 3177, 23) \
    GENERATOR(CZ_NGS, 3613, 0) \
    GENERATOR(CZ_SKILL_TARGET, 3178, 19) \
    GENERATOR(CZ_SKILL_TARGET_ANI, 3179, 23) \
    GENERATOR(CZ_SKILL_GROUND, 3180, 61) \
    GENERATOR(CZ_SKILL_SELF, 3181, 35) \
    GENERATOR(CZ_SKILL_CANCEL, 3182, 11) \
    GENERATOR(CZ_HOLD, 3183, 11) \
    GENERATOR(CZ_SHOUT, 3190, 0) \
    GENERATOR(CZ_CHAT, 3188, 0) \
    GENERATOR(CZ_CHAT_LOG, 3189, 0) \
    GENERATOR(CZ_ITEM_USE, 3193, 22) \
    GENERATOR(CZ_ITEM_USE_TO_ITEM, 3194, 30) \
    GENERATOR(CZ_ITEM_USE_TO_GROUND, 3195, 30) \
    GENERATOR(CZ_ITEM_DROP, 3191, 22) \
    GENERATOR(CZ_ITEM_EQUIP, 3198, 19) \
    GENERATOR(CZ_ITEM_UNEQUIP, 3199, 11) \
    GENERATOR(CZ_REQ_OPEN_ITEM_DUNGEON, 3214, 19) \
    GENERATOR(CZ_ANSWER_OPEN_ITEM_DUNGEON, 3215, 19) \
    GENERATOR(CZ_SEND_ITEM_PROP_TO_ALCHMIST, 3216, 28) \
    GENERATOR(CZ_EXCUTE_ITEM_DUNGEON, 3217, 34) \
    GENERATOR(ZC_RECIVE_ITEM_PROP_TO_TARGET, 3218, 0) \
    GENERATOR(ZC_CHECK_INVINDEX, 3200, 30) \
    GENERATOR(CZ_ITEM_DELETE, 3192, 0) \
    GENERATOR(CZ_ITEM_BUY, 3196, 0) \
    GENERATOR(CZ_ITEM_SELL, 3197, 0) \
    GENERATOR(CZ_DIALOG_ACK, 3230, 14) \
    GENERATOR(CZ_DIALOG_SELECT, 3231, 11) \
    GENERATOR(CZ_DIALOG_STRINGINPUT, 3232, 138) \
    GENERATOR(CZ_LEAVE_TO_DUNGEON, 3121, 10) \
    GENERATOR(CZ_MOVE_CAMP, 3251, 18) \
    GENERATOR(CZ_CAMPINFO, 3252, 18) \
    GENERATOR(ZC_CAMPINFO, 3253, 18) \
    GENERATOR(CZ_TARGET_JOB_INFO, 3255, 18) \
    GENERATOR(ZC_TARGET_JOB_INFO, 3256, 14) \
    GENERATOR(CZ_CLICK_TRIGGER, 3165, 15) \
    GENERATOR(CZ_ROTATE, 3184, 18) \
    GENERATOR(CZ_HEAD_ROTATE, 3185, 18) \
    GENERATOR(CZ_TARGET_ROTATE, 3186, 18) \
    GENERATOR(CZ_POSE, 3187, 34) \
    GENERATOR(CZ_SYSTEM_LOG_TO_SERVER, 3616, 1099) \
    GENERATOR(ZC_ENTER_PC, 3101, 341) \
    GENERATOR(ZC_ENTER_MONSTER, 3102, 0) \
    GENERATOR(ZC_ENTER_DUMMYPC, 3103, 308) \
    GENERATOR(ZC_UPDATED_DUMMYPC, 3104, 266) \
    GENERATOR(ZC_ENTER_ITEM, 3105, 103) \
    GENERATOR(ZC_LEAVE, 3106, 12) \
    GENERATOR(ZC_MOVE_PATH, 3107, 42) \
    GENERATOR(ZC_MOVE_POS, 3108, 43) \
    GENERATOR(ZC_MSPD, 3111, 14) \
    GENERATOR(ZC_MOVE_SPEED, 3112, 18) \
    GENERATOR(ZC_MOVE_DIR, 3109, 40) \
    GENERATOR(ZC_EXPECTED_STOPPOS, 3110, 35) \
    GENERATOR(ZC_MOVE_STOP, 3113, 23) \
    GENERATOR(ZC_REST_SIT, 3114, 11) \
    GENERATOR(ZC_JUMP, 3115, 19) \
    GENERATOR(ZC_JUMP_DIR, 3116, 34) \
    GENERATOR(ZC_ORDER_SKILL_JUMP, 3117, 10) \
    GENERATOR(ZC_SKILL_JUMP, 3118, 38) \
    GENERATOR(ZC_SET_POS, 3119, 22) \
    GENERATOR(ZC_FILE_MOVE, 3120, 46) \
    GENERATOR(ZC_MESSAGE, 3012, 0) \
    GENERATOR(ZC_CONNECT_OK, 3002, 0) \
    GENERATOR(ZC_CONNECT_FAILED, 3005, 0) \
    GENERATOR(ZC_START_GAME, 3014, 26) \
    GENERATOR(ZC_MOVE_ZONE, 3003, 7) \
    GENERATOR(ZC_MOVE_BARRACK, 3010, 6) \
    GENERATOR(ZC_MOVE_ZONE_OK, 3007, 57) \
    GENERATOR(ZC_DEAD, 3151, 0) \
    GENERATOR(ZC_RESURRECT, 3152, 18) \
    GENERATOR(ZC_RESURRECT_DIALOG, 3154, 7) \
    GENERATOR(CZ_RESURRECT, 3162, 11) \
    GENERATOR(ZC_RESURRECT_SAVE_POINT_ACK, 3163, 7) \
    GENERATOR(ZC_RESURRECT_HERE_ACK, 3164, 7) \
    GENERATOR(ZC_UPDATED_PCAPPEARANCE, 3122, 266) \
    GENERATOR(ZC_UPDATED_MONSTERAPPEARANCE, 3123, 0) \
    GENERATOR(ZC_ADD_HP, 3127, 22) \
    GENERATOR(ZC_UPDATE_SP, 3227, 15) \
    GENERATOR(ZC_UPDATE_MHP, 3229, 14) \
    GENERATOR(ZC_EXP_UP, 3221, 14) \
    GENERATOR(ZC_EXP_UP_BY_MONSTER, 3222, 18) \
    GENERATOR(ZC_PC_LEVELUP, 3223, 14) \
    GENERATOR(ZC_PC_STAT_AVG, 3224, 30) \
    GENERATOR(ZC_MAX_EXP_CHANGED, 3225, 18) \
    GENERATOR(ZC_UPDATE_ALL_STATUS, 3264, 26) \
    GENERATOR(ZC_CHANGE_RELATION, 3153, 11) \
    GENERATOR(ZC_QUICK_SLOT_LIST, 3208, 0) \
    GENERATOR(ZC_SKILL_LIST, 3209, 0) \
    GENERATOR(ZC_SKILL_ADD, 3210, 0) \
    GENERATOR(ZC_SKILL_CAST_CANCEL, 3128, 10) \
    GENERATOR(ZC_SKILL_CAST, 3129, 38) \
    GENERATOR(ZC_SKILL_READY, 3130, 50) \
    GENERATOR(ZC_SKILL_USE_CANCEL, 3132, 10) \
    GENERATOR(ZC_SKILL_DISABLE, 3131, 15) \
    GENERATOR(ZC_SKILL_MELEE_TARGET, 3133, 0) \
    GENERATOR(ZC_SKILL_FORCE_TARGET, 3135, 0) \
    GENERATOR(ZC_SKILL_MELEE_GROUND, 3134, 0) \
    GENERATOR(ZC_SKILL_FORCE_GROUND, 3136, 0) \
    GENERATOR(ZC_SKILL_HIT_INFO, 3137, 0) \
    GENERATOR(ZC_ABILITY_LIST, 3211, 0) \
    GENERATOR(CZ_ACTIVE_ABILITY, 3212, 15) \
    GENERATOR(ZC_ACTIVE_ABILITY, 3213, 11) \
    GENERATOR(CZ_DISPEL_DEBUFF_TOGGLE, 3219, 14) \
    GENERATOR(CZ_JUNGTAN_TOGGLE, 3220, 16) \
    GENERATOR(ZC_BUFF_LIST, 3138, 0) \
    GENERATOR(ZC_BUFF_ADD, 3139, 0) \
    GENERATOR(ZC_BUFF_UPDATE, 3140, 0) \
    GENERATOR(ZC_BUFF_REMOVE, 3141, 19) \
    GENERATOR(ZC_BUFF_CLEAR, 3142, 11) \
    GENERATOR(CZ_BUFF_REMOVE, 3143, 14) \
    GENERATOR(CZ_INTE_WARP, 3144, 14) \
    GENERATOR(ZC_HIT_INFO, 3155, 64) \
    GENERATOR(ZC_HEAL_INFO, 3156, 30) \
    GENERATOR(ZC_CAUTION_DAMAGE_INFO, 3158, 15) \
    GENERATOR(ZC_CAUTION_DAMAGE_RELEASE, 3159, 10) \
    GENERATOR(ZC_KNOCKBACK_INFO, 3160, 70) \
    GENERATOR(ZC_KNOCKDOWN_INFO, 3161, 71) \
    GENERATOR(ZC_CHAT, 3124, 0) \
    GENERATOR(ZC_CHAT_WITH_TEXTCODE, 3125, 14) \
    GENERATOR(ZC_SHOUT, 3267, 0) \
    GENERATOR(ZC_SHOUT_FAILED, 3268, 7) \
    GENERATOR(ZC_TEXT, 3226, 0) \
    GENERATOR(ZC_QUIET, 3015, 7) \
    GENERATOR(ZC_DIALOG_CLOSE, 3238, 6) \
    GENERATOR(ZC_DIALOG_OK, 3234, 0) \
    GENERATOR(ZC_DIALOG_NEXT, 3235, 0) \
    GENERATOR(ZC_DIALOG_SELECT, 3236, 0) \
    GENERATOR(ZC_DIALOG_TRADE, 3239, 39) \
    GENERATOR(ZC_DIALOG_COMMON_TRADE, 3240, 39) \
    GENERATOR(ZC_DIALOG_ITEM_SELECT, 3237, 0) \
    GENERATOR(ZC_DIALOG_NUMBERRANGE, 3241, 0) \
    GENERATOR(ZC_DIALOG_STRINGINPUT, 3242, 0) \
    GENERATOR(ZC_STANCE_CHANGE, 3126, 14) \
    GENERATOR(ZC_ITEM_ADD, 3204, 0) \
    GENERATOR(ZC_ITEM_INVENTORY_LIST, 3201, 0) \
    GENERATOR(ZC_ITEM_INVENTORY_INDEX_LIST, 3202, 0) \
    GENERATOR(ZC_ITEM_EQUIP_LIST, 3203, 0) \
    GENERATOR(ZC_ITEM_REMOVE, 3205, 20) \
    GENERATOR(ZC_ITEM_USE, 3206, 14) \
    GENERATOR(ZC_ITEM_USE_TO_GROUND, 3207, 22) \
    GENERATOR(ZC_RESET_VIEW, 3013, 6) \
    GENERATOR(ZC_RESTORATION, 3228, 12) \
    GENERATOR(ZC_ROTATE, 3145, 20) \
    GENERATOR(ZC_ROTATE_RESERVED, 3146, 18) \
    GENERATOR(ZC_HEAD_ROTATE, 3147, 18) \
    GENERATOR(ZC_TARGET_ROTATE, 3148, 18) \
    GENERATOR(ZC_QUICK_ROTATE, 3149, 18) \
    GENERATOR(ZC_POSE, 3150, 34) \
    GENERATOR(ZC_DUMP_PROPERTY, 3266, 0) \
    GENERATOR(ZC_OBJECT_PROPERTY, 3265, 0) \
    GENERATOR(ZC_ADDON_MSG, 3243, 0) \
    GENERATOR(CZ_UI_EVENT, 3244, 0) \
    GENERATOR(ZC_LOGOUT_OK, 3011, 6) \
    GENERATOR(ZC_PLAY_SOUND, 3245, 15) \
    GENERATOR(ZC_STOP_SOUND, 3246, 14) \
    GENERATOR(ZC_PLAY_MUSICQUEUE, 3247, 14) \
    GENERATOR(ZC_STOP_MUSICQUEUE, 3248, 14) \
    GENERATOR(ZC_PLAY_ANI, 3249, 24) \
    GENERATOR(ZC_CHANGE_ANI, 3250, 44) \
    GENERATOR(ZC_PLAY_ALARMSOUND, 3260, 83) \
    GENERATOR(ZC_STOP_ALARMSOUND, 3261, 10) \
    GENERATOR(ZC_PLAY_EXP_TEXT, 3262, 14) \
    GENERATOR(ZC_PLAY_NAVI_EFFECT, 3263, 150) \
    GENERATOR(CZ_EXCHANGE_REQUEST, 3269, 14) \
    GENERATOR(ZC_EXCHANGE_REQUEST_ACK, 3270, 72) \
    GENERATOR(ZC_EXCHANGE_REQUEST_RECEIVED, 3271, 71) \
    GENERATOR(CZ_EXCHANGE_ACCEPT, 3272, 10) \
    GENERATOR(CZ_EXCHANGE_DECLINE, 3273, 10) \
    GENERATOR(ZC_EXCHANGE_DECLINE_ACK, 3274, 6) \
    GENERATOR(ZC_EXCHANGE_START, 3275, 71) \
    GENERATOR(CZ_EXCHANGE_OFFER, 3276, 30) \
    GENERATOR(ZC_EXCHANGE_OFFER_ACK, 3277, 0) \
    GENERATOR(CZ_EXCHANGE_AGREE, 3278, 10) \
    GENERATOR(ZC_EXCHANGE_AGREE_ACK, 3279, 7) \
    GENERATOR(CZ_EXCHANGE_FINALAGREE, 3280, 10) \
    GENERATOR(ZC_EXCHANGE_FINALAGREE_ACK, 3281, 7) \
    GENERATOR(CZ_EXCHANGE_CANCEL, 3282, 10) \
    GENERATOR(ZC_EXCHANGE_CANCEL_ACK, 3283, 6) \
    GENERATOR(ZC_EXCHANGE_SUCCESS, 3284, 6) \
    GENERATOR(ZC_COOLDOWN_LIST, 3285, 0) \
    GENERATOR(ZC_COOLDOWN_CHANGED, 3286, 22) \
    GENERATOR(ZC_OVERHEAT_CHANGED, 3287, 26) \
    GENERATOR(ZC_TEST_AGENT, 3288, 18) \
    GENERATOR(CZ_COMMON_SHOP_LIST, 3289, 10) \
    GENERATOR(ZC_COMMON_SHOP_LIST, 3290, 8) \
    GENERATOR(ZC_TIME_FACTOR, 3291, 10) \
    GENERATOR(ZC_PARTY_ENTER, 3294, 0) \
    GENERATOR(ZC_PARTY_OUT, 3295, 24) \
    GENERATOR(ZC_PARTY_DESTROY, 3296, 15) \
    GENERATOR(ZC_PARTY_INFO, 3297, 0) \
    GENERATOR(ZC_PARTY_LIST, 3298, 0) \
    GENERATOR(ZC_PARTY_CHAT, 3299, 0) \
    GENERATOR(ZC_PARTY_INST_INFO, 3300, 0) \
    GENERATOR(ZC_CHANGE_EQUIP_DURABILITY, 3301, 11) \
    GENERATOR(CZ_DIALOG_TX, 3302, 0) \
    GENERATOR(CZ_REQ_RECIPE, 3303, 0) \
    GENERATOR(ZC_CUSTOM_DIALOG, 3304, 75) \
    GENERATOR(ZC_SESSION_OBJECTS, 3305, 0) \
    GENERATOR(ZC_SESSION_OBJ_ADD, 3306, 0) \
    GENERATOR(ZC_SESSION_OBJ_REMOVE, 3307, 10) \
    GENERATOR(ZC_SESSION_OBJ_TIME, 3308, 14) \
    GENERATOR(CZ_S_OBJ_VALUE_C, 3309, 24) \
    GENERATOR(CZ_REQ_NORMAL_TX, 3310, 45) \
    GENERATOR(ZC_COMMANDER_LOADER_INFO, 3311, 0) \
    GENERATOR(ZC_MOVE_SINGLE_ZONE, 3312, 18) \
    GENERATOR(ZC_BACKTO_ORIGINAL_SERVER, 3313, 8) \
    GENERATOR(CZ_BACKTO_ORIGINAL_SERVER, 3314, 12) \
    GENERATOR(CZ_REQ_NORMAL_TX_NUMARG, 3315, 0) \
    GENERATOR(ZC_WIKI_LIST, 3316, 0) \
    GENERATOR(ZC_WIKI_ADD, 3317, 22) \
    GENERATOR(CZ_WIKI_GET, 3318, 14) \
    GENERATOR(CZ_WIKI_RECIPE_UPDATE, 3319, 10) \
    GENERATOR(ZC_UI_OPEN, 3320, 39) \
    GENERATOR(ZC_ENABLE_CONTROL, 3321, 11) \
    GENERATOR(ZC_CHANGE_CAMERA, 3322, 31) \
    GENERATOR(ZC_MONSTER_SDR_CHANGED, 3323, 11) \
    GENERATOR(ZC_MOVE_IGNORE_COLLISION, 3324, 30) \
    GENERATOR(ZC_CHANGE_CAMERA_ZOOM, 3325, 34) \
    GENERATOR(ZC_PLAY_SKILL_ANI, 3326, 82) \
    GENERATOR(ZC_PLAY_SKILL_CAST_ANI, 3327, 30) \
    GENERATOR(CZ_REQ_ITEM_GET, 3328, 14) \
    GENERATOR(ZC_ITEM_GET, 3329, 18) \
    GENERATOR(CZ_GUARD, 3330, 19) \
    GENERATOR(ZC_GUARD, 3331, 19) \
    GENERATOR(ZC_STAMINA, 3332, 10) \
    GENERATOR(ZC_ADD_STAMINA, 3333, 10) \
    GENERATOR(ZC_GM_ORDER, 3334, 10) \
    GENERATOR(ZC_MYPC_ENTER, 3335, 18) \
    GENERATOR(ZC_LOCK_KEY, 3336, 75) \
    GENERATOR(ZC_SAVE_INFO, 3337, 6) \
    GENERATOR(CZ_SAVE_INFO, 3338, 0) \
    GENERATOR(ZC_OPTION_LIST, 3339, 0) \
    GENERATOR(ZC_SKILLMAP_LIST, 3340, 0) \
    GENERATOR(CZ_FOOD_TABLE_TITLE, 3342, 79) \
    GENERATOR(CZ_USE_TP_AND_ENTER_INDUN, 3343, 522) \
    GENERATOR(CZ_GIVEITEM_TO_DUMMYPC, 3341, 22) \
    GENERATOR(ZC_SET_LAYER, 3344, 10) \
    GENERATOR(ZC_CREATE_LAYERBOX, 3345, 38) \
    GENERATOR(ZC_RESET_BOX, 3346, 11) \
    GENERATOR(ZC_CREATE_SCROLLLOCKBOX, 3347, 38) \
    GENERATOR(ZC_REMOVE_SCROLLLOCKBOX, 3348, 10) \
    GENERATOR(CZ_DYNAMIC_CASTING_START, 3349, 23) \
    GENERATOR(CZ_DYNAMIC_CASTING_END, 3350, 19) \
    GENERATOR(CZ_SKILL_CANCEL_SCRIPT, 3351, 10) \
    GENERATOR(ZC_LEAVE_TRIGGER, 3352, 6) \
    GENERATOR(ZC_BORN, 3353, 10) \
    GENERATOR(ZC_ACHIEVE_POINT_LIST, 3354, 0) \
    GENERATOR(ZC_ACHIEVE_POINT, 3355, 18) \
    GENERATOR(CZ_ACHIEVE_EQUIP, 3356, 18) \
    GENERATOR(ZC_ACHIEVE_EQUIP, 3357, 22) \
    GENERATOR(CZ_CHANGE_CONFIG, 3358, 18) \
    GENERATOR(CZ_CHANGE_CONFIG_STR, 3359, 34) \
    GENERATOR(ZC_WORLD_MSG, 3360, 43) \
    GENERATOR(ZC_ENABLE_SHOW_ITEM_GET, 3361, 8) \
    GENERATOR(ZC_LOGIN_TIME, 3362, 14) \
    GENERATOR(ZC_GIVE_EXP_TO_PC, 3363, 42) \
    GENERATOR(ZC_LAYER_PC_LIST, 3364, 0) \
    GENERATOR(ZC_LAYER_PC_SOBJ_PROP, 3365, 0) \
    GENERATOR(CZ_CUSTOM_COMMAND, 3366, 26) \
    GENERATOR(CZ_ADD_HELP, 3521, 14) \
    GENERATOR(ZC_LAYER_INFO, 3367, 10) \
    GENERATOR(CZ_CHAT_MACRO, 3368, 146) \
    GENERATOR(ZC_CHAT_MACRO_LIST, 3369, 0) \
    GENERATOR(ZC_RULLET_LIST, 3370, 0) \
    GENERATOR(ZC_QUICKSLOT_REGISTER, 3371, 46) \
    GENERATOR(CZ_QUICKSLOT_LIST, 3372, 0) \
    GENERATOR(CZ_DOUBLE_ITEM_EQUIP, 3373, 28) \
    GENERATOR(ZC_TRICK_PACKET, 3374, 0) \
    GENERATOR(ZC_COOLDOWN_RATE, 3375, 22) \
    GENERATOR(ZC_MAP_REVEAL_LIST, 3376, 0) \
    GENERATOR(CZ_MAP_REVEAL_INFO, 3377, 146) \
    GENERATOR(CZ_MAP_SEARCH_INFO, 3378, 55) \
    GENERATOR(ZC_UI_INFO_LIST, 3379, 0) \
    GENERATOR(ZC_EXEC_CLIENT_SCP, 3380, 0) \
    GENERATOR(ZC_SET_NPC_STATE, 3381, 18) \
    GENERATOR(ZC_NPC_STATE_LIST, 3382, 0) \
    GENERATOR(CZ_QUEST_NPC_STATE_CHECK, 3383, 14) \
    GENERATOR(ZC_RANK_ACHIEVE_ADD, 3384, 14) \
    GENERATOR(CZ_GET_MAP_REVEAL_ACHIEVE, 3385, 10) \
    GENERATOR(CZ_IES_MODIFY_INFO, 3386, 0) \
    GENERATOR(ZC_IES_MODIFY_INFO, 3387, 0) \
    GENERATOR(ZC_IES_MODIFY_LIST, 3388, 0) \
    GENERATOR(CZ_IES_REVISION_DELETE, 3389, 0) \
    GENERATOR(ZC_IES_REVISION_DELETE, 3390, 0) \
    GENERATOR(ZC_EQUIP_ITEM_REMOVE, 3391, 18) \
    GENERATOR(ZC_SOLD_ITEM_LIST, 3392, 0) \
    GENERATOR(CZ_SOLD_ITEM, 3393, 19) \
    GENERATOR(CZ_WAREHOUSE_CMD, 3394, 31) \
    GENERATOR(CZ_SWAP_ETC_INV_CHANGE_INDEX, 3395, 35) \
    GENERATOR(CZ_SORT_INV, 3396, 12) \
    GENERATOR(CZ_EXTEND_WAREHOUSE, 3397, 10) \
    GENERATOR(CZ_CAST_CONTROL_SHOT, 3398, 10) \
    GENERATOR(ZC_PC_PROP_UPDATE, 3399, 9) \
    GENERATOR(CZ_CLIENT_DAMAGE, 3400, 14) \
    GENERATOR(CZ_CLIENT_ATTACK, 3401, 15) \
    GENERATOR(ZC_SYSTEM_MSG, 3402, 0) \
    GENERATOR(ZC_FSM_MOVE, 3403, 0) \
    GENERATOR(CZ_QUEST_CHECK_SAVE, 3404, 50) \
    GENERATOR(CZ_SPRAY_REQ_INFO, 3405, 14) \
    GENERATOR(CZ_SPRAY_DRAW_INFO, 3406, 0) \
    GENERATOR(ZC_SPRAY_ID, 3407, 18) \
    GENERATOR(ZC_SPRAY_DRAW_INFO, 3408, 0) \
    GENERATOR(ZC_MONSTER_LIFETIME, 3409, 14) \
    GENERATOR(ZC_SPRAY_LIKE_LIST, 3410, 0) \
    GENERATOR(ZC_WIKI_COUNT_UPDATE, 3411, 19) \
    GENERATOR(ZC_WIKI_INT_PROP_UPDATE, 3412, 15) \
    GENERATOR(ZC_WIKI_BOOL_PROP_UPDATE, 3413, 12) \
    GENERATOR(CZ_REQ_WIKI_RANK, 3414, 15) \
    GENERATOR(ZC_WIKI_RANK_LIST, 3415, 0) \
    GENERATOR(ZC_SHARED_MSG, 3416, 10) \
    GENERATOR(CZ_REQ_WIKI_PROP_RANK, 3417, 16) \
    GENERATOR(CZ_REQ_TX_ITEM, 3419, 0) \
    GENERATOR(ZC_TEST_DBG, 3420, 0) \
    GENERATOR(ZC_MONSTER_DIST, 3421, 0) \
    GENERATOR(ZC_RESET_SKILL_FORCEID, 3422, 10) \
    GENERATOR(ZC_EMOTICON, 3423, 18) \
    GENERATOR(ZC_SHOW_EMOTICON, 3424, 18) \
    GENERATOR(ZC_TREASUREMARK_BY_MAP, 3425, 0) \
    GENERATOR(ZC_SHOW_MAP, 3426, 0) \
    GENERATOR(ZC_TREASUREMARK_LIST_MAP, 208, 0) \
    GENERATOR(ZC_FIX_ANIM, 3254, 14) \
    GENERATOR(ZC_MOVE_ANIM, 3257, 12) \
    GENERATOR(CZ_FLEE_OBSTACLE, 3427, 26) \
    GENERATOR(ZC_HOLD_MOVE_PATH, 3428, 11) \
    GENERATOR(ZC_ENTER_HOOK, 3429, 10) \
    GENERATOR(ZC_LEAVE_HOOK, 3430, 10) \
    GENERATOR(ZC_MONSTER_PROPERTY, 3431, 0) \
    GENERATOR(ZC_GROUND_EFFECT, 3432, 50) \
    GENERATOR(ZC_FLY, 3433, 18) \
    GENERATOR(ZC_FLY_MATH, 3434, 22) \
    GENERATOR(ZC_FLY_HEIGHT, 3435, 14) \
    GENERATOR(ZC_UPDATE_SHIELD, 3436, 14) \
    GENERATOR(ZC_SHOW_MODEL, 3437, 15) \
    GENERATOR(ZC_SKILL_RANGE_DBG, 3438, 58) \
    GENERATOR(ZC_SKILL_RANGE_FAN, 3439, 40) \
    GENERATOR(ZC_SKILL_RANGE_SQUARE, 3440, 40) \
    GENERATOR(ZC_SKILL_RANGE_CIRCLE, 3441, 28) \
    GENERATOR(ZC_SKILL_RANGE_DONUTS, 3442, 32) \
    GENERATOR(ZC_TEAMID, 3443, 11) \
    GENERATOR(ZC_PC, 3444, 0) \
    GENERATOR(CZ_LOG, 3445, 0) \
    GENERATOR(ZC_MOTIONBLUR, 3446, 11) \
    GENERATOR(ZC_PLAY_FORCE, 3447, 78) \
    GENERATOR(ZC_CAST_TARGET, 3448, 14) \
    GENERATOR(ZC_START_INFO, 3449, 0) \
    GENERATOR(ZC_JOB_EXP_UP, 3450, 10) \
    GENERATOR(ZC_JOB_PTS, 3451, 10) \
    GENERATOR(ZC_MON_STAMINA, 3452, 22) \
    GENERATOR(CZ_CUSTOM_SCP, 3453, 14) \
    GENERATOR(ZC_VIEW_FOCUS, 3454, 24) \
    GENERATOR(ZC_HARDCODED_SKILL, 3455, 26) \
    GENERATOR(CZ_HARDCODED_SKILL, 3456, 34) \
    GENERATOR(ZC_FORCE_MOVE, 3457, 30) \
    GENERATOR(ZC_HSKILL_CONTROL, 3458, 22) \
    GENERATOR(ZC_CANCEL_DEADEVENT, 3459, 10) \
    GENERATOR(ZC_ACTION_PKS, 3460, 35) \
    GENERATOR(CZ_HARDCODED_ITEM, 3461, 22) \
    GENERATOR(CZ_BRIQUET, 3463, 30) \
    GENERATOR(CZ_CANCEL_TRANSFORM_SKILL, 3462, 10) \
    GENERATOR(ZC_VIBRATE, 3464, 30) \
    GENERATOR(ZC_COUNTER_MOVE, 3465, 10) \
    GENERATOR(CZ_COUNTER_ATTACK, 3466, 14) \
    GENERATOR(CZ_CLIENT_DIRECT, 3467, 30) \
    GENERATOR(ZC_CLIENT_DIRECT, 3468, 30) \
    GENERATOR(ZC_OWNER, 3469, 14) \
    GENERATOR(ZC_GD_RANK, 3470, 10) \
    GENERATOR(CZ_RUN_BGEVENT, 3471, 74) \
    GENERATOR(ZC_ADD_SKILL_EFFECT, 3472, 18) \
    GENERATOR(ZC_ITEM_DROPABLE, 3473, 10) \
    GENERATOR(CZ_ITEM_DROP_TO_OBJECT, 3474, 26) \
    GENERATOR(ZC_NORMAL, 3475, 0) \
    GENERATOR(CZ_G_QUEST_CHECK, 3476, 14) \
    GENERATOR(ZC_MOVE_PATH_MATH, 3477, 30) \
    GENERATOR(ZC_SHOW_GROUND_ITEM_MARK, 3494, 30) \
    GENERATOR(ZC_HELP_LIST, 3495, 0) \
    GENERATOR(ZC_HELP_ADD, 3496, 11) \
    GENERATOR(ZC_STD_ANIM, 3258, 11) \
    GENERATOR(CZ_CLIENT_HIT_LIST, 3497, 0) \
    GENERATOR(ZC_PC_ATKSTATE, 3498, 11) \
    GENERATOR(ZC_SEND_PREMIUM_STATE, 3499, 8) \
    GENERATOR(CZ_HELP_READ_TYPE, 3500, 18) \
    GENERATOR(CZ_MOVE_PATH_END, 3501, 10) \
    GENERATOR(ZC_COLL_DAMAGE, 3502, 11) \
    GENERATOR(CZ_KEYBOARD_BEAT, 3503, 10) \
    GENERATOR(CZ_MOVEHIT_SCP, 3504, 22) \
    GENERATOR(ZC_SYNC_START, 3505, 10) \
    GENERATOR(ZC_SYNC_END, 3506, 14) \
    GENERATOR(ZC_SYNC_EXEC, 3507, 10) \
    GENERATOR(ZC_SYNC_EXEC_BY_SKILL_TIME, 3508, 18) \
    GENERATOR(CZ_STOP_TIMEACTION, 3509, 11) \
    GENERATOR(CZ_REQ_DUMMYPC_INFO, 3510, 18) \
    GENERATOR(CZ_VISIT_BARRACK, 3511, 74) \
    GENERATOR(CZ_SPC_SKILL_POS, 3512, 22) \
    GENERATOR(CZ_REQ_CHANGEJOB, 3513, 14) \
    GENERATOR(CZ_REQ_MINITEXT, 3516, 266) \
    GENERATOR(ZC_PC_MOVE_STOP, 3517, 35) \
    GENERATOR(CZ_SKILL_TOOL_GROUND_POS, 3527, 26) \
    GENERATOR(CZ_CHANGE_HEAD, 3514, 74) \
    GENERATOR(CZ_CREATE_ARROW_CRAFT, 3515, 14) \
    GENERATOR(CZ_PLAY_HISTORY, 3292, 19) \
    GENERATOR(CZ_HISTORY_ROLL_BACK, 3293, 271) \
    GENERATOR(CZ_MYPAGE_COMMENT_ADD, 3478, 278) \
    GENERATOR(CZ_MYPAGE_COMMENT_DELETE, 3479, 18) \
    GENERATOR(CZ_GET_TARGET_MYPAGE, 3481, 14) \
    GENERATOR(CZ_ON_MYPAGE_MODE, 3482, 14) \
    GENERATOR(CZ_RESET_SOCIAL_MODE, 3483, 10) \
    GENERATOR(CZ_GUESTPAGE_COMMENT_ADD, 3480, 278) \
    GENERATOR(CZ_GET_TARGET_GUESTPAGE, 3484, 14) \
    GENERATOR(CZ_ADD_SELLMODE_ITEM, 3485, 30) \
    GENERATOR(CZ_DELETE_SELLMODE_ITEM, 3486, 18) \
    GENERATOR(CZ_ON_SELLITEM_MODE, 3487, 14) \
    GENERATOR(CZ_ON_ITEMBUY_MODE, 3492, 0) \
    GENERATOR(ZC_MYPAGE_MAP, 3488, 0) \
    GENERATOR(ZC_GUESTPAGE_MAP, 3489, 0) \
    GENERATOR(ZC_ON_MYPAGE_MODE, 3490, 0) \
    GENERATOR(ZC_RESET_SOCIAL_MODE, 3491, 10) \
    GENERATOR(ZC_ON_BUYITEM_MODE, 3493, 0) \
    GENERATOR(CZ_STOP_ALLPC, 3518, 10) \
    GENERATOR(CZ_COMPLETE_PRELOAD, 3519, 14) \
    GENERATOR(CZ_MGAME_JOIN_CMD, 3520, 46) \
    GENERATOR(ZC_ATTACH_TO_OBJ, 3522, 49) \
    GENERATOR(ZC_DETACH_FROM_OBJ, 3523, 14) \
    GENERATOR(ZC_RUN_FROM, 3524, 14) \
    GENERATOR(ZC_LOOKAT_OBJ, 3525, 14) \
    GENERATOR(CZ_SKILL_CELL_LIST, 3526, 0) \
    GENERATOR(CZ_DIRECTION_PROCESS, 3528, 18) \
    GENERATOR(CZ_DIRECTION_MOVE_STATE, 3529, 0) \
    GENERATOR(ZC_TO_ALL_CLIENT, 3530, 0) \
    GENERATOR(ZC_TO_CLIENT, 3531, 0) \
    GENERATOR(CZ_REWARD_CMD, 3532, 14) \
    GENERATOR(CZ_PROPERTY_COMPARE, 3533, 16) \
    GENERATOR(ZC_PROPERTY_COMPARE, 3534, 0) \
    GENERATOR(ZC_SEND_CASH_VALUE, 3536, 0) \
    GENERATOR(ZC_RECOMMEND_PARTYMEMBER_INFO, 3603, 0) \
    GENERATOR(ZC_FACTION, 3535, 14) \
    GENERATOR(ZC_BEGIN_KILL_LOG, 3537, 6) \
    GENERATOR(ZC_END_KILL_LOG, 3538, 6) \
    GENERATOR(ZC_CLEAR_KILL_LOG, 3539, 6) \
    GENERATOR(CZ_NPC_AUCTION_CMD, 3540, 30) \
    GENERATOR(ZC_DIRECTION_APC, 3541, 26) \
    GENERATOR(ZC_BGMODEL_ANIM_INFO, 3542, 15) \
    GENERATOR(ZC_ATTACH_BY_KNOCKBACK, 3543, 38) \
    GENERATOR(CZ_OBJECT_MOVE, 3544, 30) \
    GENERATOR(CZ_CONTROL_OBJECT_ROTATE, 3545, 22) \
    GENERATOR(CZ_SUMMON_COMMAND, 3546, 18) \
    GENERATOR(CZ_VEHICLE_RIDE, 3547, 15) \
    GENERATOR(CZ_REQ_WIKI_CATEGORY_RANK_PAGE_INFO, 3548, 78) \
    GENERATOR(CZ_REQ_ACHIEVE_RANK_PAGE_INFO, 3549, 78) \
    GENERATOR(CZ_REQ_MONSTER_RANK_INFO, 3550, 74) \
    GENERATOR(ZC_SPC_TRIGGER_EXEC, 3551, 30) \
    GENERATOR(CZ_REQ_MGAME_VIEW, 3552, 18) \
    GENERATOR(CZ_REQ_MGAME_CHAT, 3553, 0) \
    GENERATOR(CZ_TOURNAMENT_GIFT, 3554, 18) \
    GENERATOR(CZ_PARTY_INVITE_ACCEPT, 3555, 79) \
    GENERATOR(CZ_PARTY_INVITE_CANCEL, 3556, 83) \
    GENERATOR(CZ_PARTY_PROP_CHANGE, 3557, 145) \
    GENERATOR(CZ_REQ_MARKET_REGISTER, 3558, 40) \
    GENERATOR(CZ_REQ_MARKET_MINMAX_INFO, 3559, 18) \
    GENERATOR(CZ_REQ_MARKET_BUY, 3560, 0) \
    GENERATOR(CZ_REQ_MARKET_LIST, 3561, 162) \
    GENERATOR(CZ_REQ_MY_SELL_LIST, 3562, 14) \
    GENERATOR(CZ_REQ_CABINET_LIST, 3563, 10) \
    GENERATOR(CZ_REQ_GET_CABINET_ITEM, 3564, 26) \
    GENERATOR(CZ_REQ_CANCEL_MARKET_ITEM, 3565, 18) \
    GENERATOR(CZ_OBJ_RECORD_POS, 3567, 0) \
    GENERATOR(CZ_FORMATION_CMD, 3568, 32) \
    GENERATOR(CZ_REGISTER_AUTOSELLER, 3569, 0) \
    GENERATOR(CZ_INV_ITEM_LOCK, 3566, 19) \
    GENERATOR(CZ_OPEN_AUTOSELLER, 3570, 34) \
    GENERATOR(CZ_BUY_AUTOSELLER_ITEMS, 3571, 0) \
    GENERATOR(CZ_SELL_MY_AUTOSELLER_ITEMS, 3572, 0) \
    GENERATOR(CZ_PUZZLE_CRAFT, 3573, 0) \
    GENERATOR(CZ_GET_WIKI_REWARD, 3418, 11) \
    GENERATOR(CZ_PET_EQUIP, 3574, 30) \
    GENERATOR(ZC_FOUND_PARTY_LIST, 3575, 0) \
    GENERATOR(ZC_NEAR_PARTY_LIST, 3576, 0) \
    GENERATOR(ZC_RECOMMEND_PARTY_INFO, 3577, 0) \
    GENERATOR(CZ_REQUEST_SOME_PARTY, 3578, 90) \
    GENERATOR(CZ_REFRESH_MEMBERRECOMMEND_LIST, 3579, 10) \
    GENERATOR(ZC_TO_SOMEWHERE_CLIENT, 3580, 0) \
    GENERATOR(CZ_REVEAL_NPC_STATE, 3581, 14) \
    GENERATOR(CZ_CHANGE_CHANNEL, 3582, 12) \
    GENERATOR(CZ_REQ_CHANNEL_TRAFFICS, 3583, 12) \
    GENERATOR(CZ_BUY_PROPERTYSHOP_ITEM, 3584, 0) \
    GENERATOR(CZ_SKILL_USE_HEIGHT, 3585, 14) \
    GENERATOR(CZ_ACCEPT_PARTY_QUEST, 3586, 20) \
    GENERATOR(CZ_ACCEPT_GUILD_EVENT, 3587, 20) \
    GENERATOR(CZ_ACCEPT_GUILD_EVENT_RAID, 3588, 20) \
    GENERATOR(CZ_ACCEPT_PARTY_EVENT, 3589, 20) \
    GENERATOR(CZ_DELETE_PARTY_EVENT, 3590, 20) \
    GENERATOR(CZ_PING, 3591, 10) \
    GENERATOR(ZC_PING, 3592, 10) \
    GENERATOR(ZC_XIGNCODE_BUFFER, 3593, 524) \
    GENERATOR(CZ_XIGNCODE_BUFFER, 3594, 524) \
    GENERATOR(CZ_SYSTEM_LOG_SAVE_TO_MONGODB, 3595, 280) \
    GENERATOR(CZ_CHANGE_TITLE, 3596, 74) \
    GENERATOR(CZ_PC_COMMENT_CHANGE, 3597, 0) \
    GENERATOR(CZ_AUTTOSELLER_BUYER_CLOSE, 3598, 18) \
    GENERATOR(CZ_REQ_ITEM_LIST, 3599, 11) \
    GENERATOR(CZ_HIT_MISSILE, 3600, 14) \
    GENERATOR(CZ_I_NEED_PARTY, 3601, 23) \
    GENERATOR(CZ_PARTY_JOIN_BY_LINK, 3602, 19) \
    GENERATOR(CZ_PVP_ZONE_CMD, 3604, 22) \
    GENERATOR(CZ_PVP_CHAT, 3605, 0) \
    GENERATOR(CZ_CARDBATTLE_CMD, 3606, 26) \
    GENERATOR(CZ_REQ_UPDATE_CONTENTS_SESSION, 3607, 10) \
    GENERATOR(CZ_REQ_FRIENDLY_FIGHT, 3608, 15) \
    GENERATOR(CZ_HARDSKILL_POS_LIST, 3609, 0) \
    GENERATOR(CZ_CART_POSITION, 3610, 26) \
    GENERATOR(CZ_REQ_RIDE_CART, 3611, 18) \
    GENERATOR(CZ_DUMMYPC_SKILL_POS, 3612, 26) \
    GENERATOR(CZ_PARTY_MEMBER_SKILL_USE, 3614, 0) \
    GENERATOR(CZ_PARTY_MEMBER_SKILL_ACCEPT, 3615, 22) \
    GENERATOR(CZ_CHECK_PING, 3617, 10) \


/**
 * @brief PacketType enumerates all the packets used in the game between the client and the server
 */
typedef enum PacketType {
	FOREACH_PACKET_TYPE(GENERATE_PACKET_TYPE_ENUM)
	PACKET_TYPE_COUNT
}	PacketType;

typedef uint16_t PacketType_t;


typedef struct PacketTypeEntry {
    int id;
    int size;
	char *name;
}   PacketTypeEntry;

// ----------- Functions ------------
char *PacketType_to_string (PacketType type);
int   PacketType_get_size (PacketType type);

void packetTypeInit();
