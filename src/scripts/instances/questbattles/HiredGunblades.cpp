#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;

class HiredGunblades : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto P_BNPC_RADOVAN = 7967537;
  static constexpr auto P_BNPC_YAMITRA = 7967543;
  static constexpr auto P_BNPC_HODDYN = 7967544;
  static constexpr auto P_BNPC_EDITHA = 7967545;
  static constexpr auto BNPC_P1_TRASH_001 = 7967547;
  static constexpr auto BNPC_P1_TRASH_002 = 7967548;
  static constexpr auto BNPC_P1_TRASH_003 = 7967560;
  static constexpr auto BNPC_P1_TRASH_004 = 7967561;
  static constexpr auto BNPC_P1_TRASH_005 = 7967672;
  static constexpr auto BNPC_P1_TRASH_006 = 7967551;
  static constexpr auto BNPC_P1_TRASH_007 = 7967552;
  static constexpr auto BNPC_P2_TRASH_001 = 7967563;
  static constexpr auto BNPC_P2_TRASH_002 = 7967570;
  static constexpr auto BNPC_P2_TRASH_003 = 7967573;
  static constexpr auto BNPC_P2_TRASH_004 = 7967577;
  static constexpr auto BNPC_P2_TRASH_005 = 7967598;
  static constexpr auto BNPC_P2_BOSS_ASSASSINLEADER_001 = 7967587;
  static constexpr auto BNPC_P3_TRASH_001 = 7967602;
  static constexpr auto BNPC_P3_TRASH_002 = 7967603;
  static constexpr auto BNPC_P3_TRASH_003 = 7967604;
  static constexpr auto BNPC_P3_TRASH_004 = 7967606;
  static constexpr auto BNPC_P3_TRASH_005 = 7967924;
  static constexpr auto BNPC_P3_TRASH_006 = 7967927;
  static constexpr auto BNPC_P3_TRASH_007 = 7967929;
  static constexpr auto BNPC_P3_TRASH_008 = 7967926;
  static constexpr auto BNPC_P3_TRASH_009 = 7967923;
  static constexpr auto BNPC_P3_TRASH_010 = 7967930;
  static constexpr auto BNPC_P3_TRASH_011 = 7967925;
  static constexpr auto BNPC_P3_TRASH_012 = 7967931;
  static constexpr auto BNPC_P3_BOSS_COEURL_001 = 7967525;
  static constexpr auto ER_P1_FIRST_BATTLEFLAG = 7970857;
  static constexpr auto PR_P1_TRASH_MOVE_01 = 7970867;
  static constexpr auto PR_P1_TRASH_MOVE_02 = 7970871;
  static constexpr auto PR_P1_EDITHA_MOVE_01 = 7970872;
  static constexpr auto PR_P1_RADOVAN_MOVE_01 = 7970881;
  static constexpr auto P_BNPC_MILLITH = 7971016;
  static constexpr auto P_BNPC_SAETHRYDA = 7974097;
  static constexpr auto P_BNPC_YSHUWAHE = 7974096;
  static constexpr auto P_BNPC_JONATHAS = 7974095;
  static constexpr auto PR_P1_MILLITH_MOVE_01 = 7971017;
  static constexpr auto PR_P1_SAETHRYDA_MOVE_01 = 7974091;
  static constexpr auto PR_P1_YMHITRA_MOVE_01 = 7974092;
  static constexpr auto PR_P1_YSHUWAHE_MOVE_01 = 7974093;
  static constexpr auto PR_P1_JONATHAS_MOVE_01 = 7974094;
  static constexpr auto EOBJ_TALK_MILLITH = 8024752;
  static constexpr auto EOBJ_TALK_SAETHRYDA = 8024753;
  static constexpr auto EOBJ_TALK_YMHITRA = 8024754;
  static constexpr auto EOBJ_TALK_YSHUWAHE = 8024755;
  static constexpr auto EOBJ_TALK_JONATHAS = 8024756;
  static constexpr auto ER_P1_NEAR_APKALLUFALLS = 7971027;
  static constexpr auto BEHAVIOR_EDITHA_PANIC = 30303;
  static constexpr auto BEHAVIOR_NPC_TALK = 30562;
  static constexpr auto EVENT_ACTION_TALK = 64;
  static constexpr auto BGM_BATTLE = 13;
  static constexpr auto BGM_BOSS = 37;
  static constexpr auto PR_P1_TRASH_MOVE_03 = 7978858;
  static constexpr auto PR_P1_TRASH_MOVE_04 = 7978861;
  static constexpr auto PR_P1_TRASH_MOVE_05 = 7978860;
  static constexpr auto PR_P2_RADOVAN_MOVE_01 = 7978876;
  static constexpr auto PR_P2_EDITHA_MOVE_01 = 7978877;
  static constexpr auto PR_P2_RADOVAN_MOVE_02 = 7978881;
  static constexpr auto PR_P2_RADOVAN_MOVE_03 = 7978882;
  static constexpr auto PR_P2_RADOVAN_MOVE_04 = 7978884;
  static constexpr auto ACTION_PLAYER_GUNBREAKER_COMBO3 = 16145;
  static constexpr auto ACTION_PLAYER_GUNBREAKER_MAGICBULLET = 16146;
  static constexpr auto EOBJ_BOSS_ROOM_CONTROL = 7980743;
  static constexpr auto EOBJ_SHARED_CONTROL_3 = 7980758;
  static constexpr auto EOBJ_SHARED_CONTROL_2 = 7980764;
  static constexpr auto EOBJ_SHARED_CONTROL_1 = 7980767;
  static constexpr auto PR_P1_EDITHA_MOVE_02 = 7980831;
  static constexpr auto PR_P1_RADOVAN_MOVE_02 = 7980832;
  static constexpr auto BNPC_P3_THUNDERBOLT_LEFT = 7981191;
  static constexpr auto BNPC_P3_THUNDERBOLT_CENTER = 7981218;
  static constexpr auto BNPC_P3_THUNDERBOLT_RIGHT = 7981219;
  static constexpr auto PR_P3_RADOVAN_MOVE_LEFT = 7981220;
  static constexpr auto PR_P3_RADOVAN_MOVE_CENTER = 7981221;
  static constexpr auto PR_P3_RADOVAN_MOVE_RIGHT = 7981222;
  static constexpr auto PR_P3_EDITHA_MOVE_LEFT = 7981227;
  static constexpr auto PR_P3_EDITHA_MOVE_CENTER = 7981230;
  static constexpr auto PR_P3_EDITHA_MOVE_RIGHT = 7981231;
  static constexpr auto ACTION_BOSS_COEURL_THUNDERBOLT = 17239;
  static constexpr auto ACTION_TOMEI_THUNDERBOLT = 17240;
  static constexpr auto BNPC_P3_THUNDERBALL_LEFT = 7984227;
  static constexpr auto BNPC_P3_THUNDERBALL_CENTER = 7984233;
  static constexpr auto BNPC_P3_THUNDERBALL_RIGHT = 7984234;
  static constexpr auto ACTION_SCRIPT_TRIGGER_01 = 4777;
  static constexpr auto ACTION_TRASH_OVERPOWER = 17245;
  static constexpr auto ACTION_RADOVAN_PROVOKE = 17425;
  static constexpr auto ACTION_RADOVAN_SHIRK = 17426;
  static constexpr auto BEHAVIOR_NPC_CHEERTALK = 30516;
  static constexpr auto BEHAVIOR_NPC_CHEER = 30961;
  static constexpr auto BEHAVIOR_NPC_AWKWARD = 30560;
  static constexpr auto BEHAVIOR_NPC_VERYGLAD = 30712;
  static constexpr auto STATUS_PARAM_KNOCKDOWN = 5059;
  static constexpr auto BEHAVIOR_NPC_OFF = 30417;
  static constexpr auto BEHAVIOR_HODDYN_SCOLD = 31471;
  static constexpr auto ACTION_THUNDERBALL_BURST = 17244;
  static constexpr auto P_ENPC_ONDINE = 8034329;
  static constexpr auto YELL_HODDYN_002 = 8135;
  static constexpr auto YELL_HODDYN_003 = 8136;
  static constexpr auto YELL_HODDYN_004 = 8137;
  static constexpr auto YELL_ASSASSIN_003 = 8138;
  static constexpr auto BGM_NO_MUSIC = 1;
  static constexpr auto ACTION_TIMELINE_FASTBLADE = 310;
  static constexpr auto ACTION_TIMELINE_BATTLE_START = 3778;
  static constexpr auto BNPC_NAME_ONDINE = 598;
  static constexpr auto BNPC_NAME_RADVAN = 826;
  static constexpr auto YELL_YMHITRA_002 = 8555;
  //static constexpr auto ACTION_TIMELINE_BATTLE_START = 4259;
  static constexpr auto ACTION_TIMELINE_WELCOME = 738;
  static constexpr auto YELL_RADVAN_005 = 8573;
  static constexpr auto YELL_RADVAN_006 = 8574;
  static constexpr auto YELL_EDITHA_003 = 8575;
  static constexpr auto ACTION_TIMELINE_ANGRY = 691;
  static constexpr auto ACTION_TIMELINE_PANIC = 719;
  static constexpr auto ACTION_TIMELINE_POINT = 720;
  static constexpr auto ACTION_TIMELINE_LOOK = 713;
  static constexpr auto YELL_RADVAN_007 = 8653;
  static constexpr auto YELL_RADVAN_008 = 8654;
  static constexpr auto YELL_RADVAN_009 = 8655;
  static constexpr auto YELL_RADVAN_010 = 8656;
  static constexpr auto YELL_EDITHA_004 = 8657;
  static constexpr auto ACTION_TIMELINE_TOUCH_LOOP = 4194;
  static constexpr auto ACTION_TIMELINE_SHOCKED = 707;
  static constexpr auto YELL_MILLITH_002 = 8658;
  static constexpr auto YELL_SAETHRYDA_002 = 8659;
  static constexpr auto YELL_YSHUWAHE_002 = 8660;
  static constexpr auto YELL_JONATHAS_002 = 8661;
  static constexpr auto YELL_RADVAN_011 = 8662;
  static constexpr auto YELL_EDITHA_005 = 8663;
  static constexpr auto YELL_RADVAN_012 = 8664;
  static constexpr auto YELL_EDITHA_006 = 8665;
  static constexpr auto YELL_EDITHA_007 = 8666;
  static constexpr auto YELL_RADVAN_013 = 8667;
  static constexpr auto YELL_EDITHA_008 = 8668;
  static constexpr auto YELL_RADVAN_014 = 8669;
  static constexpr auto ACTION_TIMELINE_SOOTHE = 732;
  static constexpr auto ACTION_TIMELINE_WORRY = 737;
  static constexpr auto ACTION_TIMELINE_REQUEST = 694;
  static constexpr auto ACTION_TIMELINE_HYSTERIC = 724;
  static constexpr auto BGM_NOMAL = 6;
  static constexpr auto STATUS_PARAM_TERROR_NOLIMIT = 3331;
  static constexpr auto STATUS_TERROR_NOLIMIT = 1400;
  static constexpr auto LOC_ACTOR0 = 1029048;
  static constexpr auto LOC_ACTOR1 = 1031417;
  static constexpr auto LOC_MARKER_00 = 8032721;
  static constexpr auto ACTION_TIMELINE_HUMMING = 6271;
  static constexpr auto PR_P2_RADOVAN_MOVE_05 = 8035499;
  static constexpr auto PR_P2_RADOVAN_MOVE_06 = 8035501;

public:
  HiredGunblades() : Sapphire::ScriptAPI::QuestBattleScript( 193 )
  { }

  void onInit( QuestBattle& instance ) override
  {
    instance.registerEObj( "Companychest", 2000470, 4255829, 4, { 135.732803f, 14.529310f, -87.463547f }, 0.991760f, 0.298639f ); 

  }

  void onUpdate( QuestBattle& instance, uint64_t tickCount ) override
  {

  }

  void onEnterTerritory( QuestBattle& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {

  }

};

EXPOSE_SCRIPT( HiredGunblades );