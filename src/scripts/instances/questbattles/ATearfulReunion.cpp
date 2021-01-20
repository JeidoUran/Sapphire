#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;

class ATearfulReunion : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto BNPC_PRO = 7968275;
  static constexpr auto P_BNPC_TAYNOR = 7968317;
  static constexpr auto P_BNPC_CERIGG = 7968318;
  static constexpr auto BNPC_TOUMEI_1 = 7969943;
  static constexpr auto BNPC_TOUMEI_2 = 7969944;
  static constexpr auto BNPC_TOUMEI_3 = 8024744;
  static constexpr auto BNPC_UTURO_P1_1 = 7969884;
  static constexpr auto BNPC_UTURO_P1_2 = 7969889;
  static constexpr auto BNPC_UTURO_P1_3 = 7969891;
  static constexpr auto BNPC_UTURO_P1_4 = 7969906;
  static constexpr auto BNPC_UTURO_P2_1 = 7969896;
  static constexpr auto BNPC_UTURO_P2_2 = 7969887;
  static constexpr auto BNPC_UTURO_P2_3 = 7969888;
  static constexpr auto BNPC_UTURO_P2_4 = 7969890;
  static constexpr auto BNPC_UTURO_P3_1 = 7969892;
  static constexpr auto BNPC_UTURO_P3_2 = 7969884;
  static constexpr auto BNPC_UTURO_P3_3 = 7969886;
  static constexpr auto BNPC_UTURO_P3_4 = 7969898;
  static constexpr auto BNPC_UTURO_P3_5 = 7969904;
  static constexpr auto BNPC_UTURO_P5_A_1 = 7969905;
  static constexpr auto BNPC_UTURO_P5_A_2 = 7969885;
  static constexpr auto BNPC_UTURO_P5_A_3 = 7969897;
  static constexpr auto BNPC_UTURO_P5_A_4 = 7969889;
  static constexpr auto BNPC_UTURO_P5_B_1 = 7969907;
  static constexpr auto BNPC_UTURO_P5_B_2 = 7969886;
  static constexpr auto BNPC_UTURO_P5_B_3 = 7969899;
  static constexpr auto BNPC_UTURO_P5_B_4 = 7969890;
  static constexpr auto BNPC_UTURO_P5_C_1 = 7969893;
  static constexpr auto BNPC_UTURO_P5_C_2 = 7969887;
  static constexpr auto BNPC_UTURO_P5_C_3 = 7969901;
  static constexpr auto BNPC_UTURO_P5_C_4 = 7969891;
  static constexpr auto BNPC_UTURO_P5_D_1 = 7969895;
  static constexpr auto BNPC_UTURO_P5_D_2 = 7969888;
  static constexpr auto BNPC_UTURO_P5_D_3 = 7969903;
  static constexpr auto BNPC_UTURO_P5_D_4 = 7969892;
  static constexpr auto BNPC_LIGHTNING_1 = 7968913;
  static constexpr auto BNPC_LIGHTNING_2 = 7968918;
  static constexpr auto BNPC_LIGHTNING_3 = 8010184;
  static constexpr auto BNPC_LIGHTNING_4 = 8010189;
  static constexpr auto BNPC_TARGET_P1_1 = 7978043;
  static constexpr auto BNPC_TARGET_P1_2 = 7978061;
  static constexpr auto BNPC_TARGET_P1_3 = 7978062;
  static constexpr auto BNPC_TARGET_P1_4 = 7978063;
  static constexpr auto BNPC_TARGET_P2_1 = 7978113;
  static constexpr auto BNPC_TARGET_P2_2 = 7978114;
  static constexpr auto BNPC_TARGET_P2_3 = 7978117;
  static constexpr auto BNPC_TARGET_P2_4 = 7978119;
  static constexpr auto BNPC_TARGET_P3_2 = 7978122;
  static constexpr auto BNPC_TARGET_P3_3 = 7978123;
  static constexpr auto BNPC_TARGET_P3_4 = 7978124;
  static constexpr auto BNPC_TARGET_P3_5 = 7978125;
  static constexpr auto BNPC_TARGET_P5_A1 = 7978166;
  static constexpr auto BNPC_TARGET_P5_A3 = 7978173;
  static constexpr auto BNPC_TARGET_P5_A4 = 7978179;
  static constexpr auto BNPC_TARGET_P5_B1 = 7978187;
  static constexpr auto BNPC_TARGET_P5_B2 = 7978206;
  static constexpr auto BNPC_TARGET_P5_C1 = 7978212;
  static constexpr auto BNPC_TARGET_P5_C4 = 7978214;
  static constexpr auto BNPC_TARGET_P5_D1 = 7978223;
  static constexpr auto BNPC_TARGET_P5_D4 = 7978298;
  static constexpr auto BNPC_TARGET_STEP_CENTER = 8004467;
  static constexpr auto BNPC_TARGET_STEP_P2 = 8004067;
  static constexpr auto BNPC_TARGET_STEP_P3 = 8004071;
  static constexpr auto BNPC_TARGET_STEP_P5 = 8004458;
  static constexpr auto ACTION_GTAE = 17035;
  static constexpr auto ACTION_TARGET_AE = 17037;
  static constexpr auto ACTION_DONUT = 17046;
  static constexpr auto ACTION_UTURO_1 = 17033;
  static constexpr auto ACTION_UTURO_2 = 17034;
  static constexpr auto ACTION_UTURO_3 = 17218;
  static constexpr auto ACTION_UTURO_4 = 17219;
  static constexpr auto ACTION_UTURO_5 = 17220;
  static constexpr auto ACTION_LIGHTNING = 17040;
  static constexpr auto ACTION_STEP = 17041;
  static constexpr auto ACTION_SHARE = 17039;
  static constexpr auto ACTION_KNOCKDOWN = 17233;
  static constexpr auto ACTION_CHANNELING_ON = 17455;
  static constexpr auto ACTION_CHANNELING_OFF = 17456;
  static constexpr auto ACTION_LIGHTNING_DEPOP = 17050;
  static constexpr auto ACTION_BLIZZARD = 17044;
  static constexpr auto CHANNELING_DARK = 1;
  static constexpr auto CHANNELING_LIGHTNING = 6;
  static constexpr auto POP_RANGE_BATTLE_START = 8010445;
  static constexpr auto POP_RANGE_CENTER = 7968321;
  static constexpr auto POP_RANGE_IN_N = 7968324;
  static constexpr auto POP_RANGE_IN_NE = 7968346;
  static constexpr auto POP_RANGE_IN_E = 7968422;
  static constexpr auto POP_RANGE_IN_SE = 7968429;
  static constexpr auto POP_RANGE_IN_S = 7968438;
  static constexpr auto POP_RANGE_IN_SW = 7968439;
  static constexpr auto POP_RANGE_IN_W = 7968714;
  static constexpr auto POP_RANGE_IN_NW = 7968717;
  static constexpr auto POP_RANGE_OUT_N = 7968721;
  static constexpr auto POP_RANGE_OUT_NNE = 7968737;
  static constexpr auto POP_RANGE_OUT_NE = 7968760;
  static constexpr auto POP_RANGE_OUT_ENE = 7968763;
  static constexpr auto POP_RANGE_OUT_E = 7968783;
  static constexpr auto POP_RANGE_OUT_ESE = 7968805;
  static constexpr auto POP_RANGE_OUT_SE = 7968806;
  static constexpr auto POP_RANGE_OUT_SSE = 7968807;
  static constexpr auto POP_RANGE_OUT_S = 7968808;
  static constexpr auto POP_RANGE_OUT_SSW = 7968812;
  static constexpr auto POP_RANGE_OUT_SW = 7968821;
  static constexpr auto POP_RANGE_OUT_WSW = 7968869;
  static constexpr auto POP_RANGE_OUT_W = 7968871;
  static constexpr auto POP_RANGE_OUT_WNW = 7968886;
  static constexpr auto POP_RANGE_OUT_NW = 7968889;
  static constexpr auto POP_RANGE_OUT_NNW = 7968896;
  static constexpr auto LOGMESSAGE_LIGHTNING = 9499;
  static constexpr auto STATUS_MP_REGEN = 5342;

public:
  ATearfulReunion() : Sapphire::ScriptAPI::QuestBattleScript( 190 )
  { }

  void onInit( QuestBattle& instance ) override
  {
    instance.registerEObj( "sgbg_w_qic_004_03a", 2007457, 7956971, 4, { -440.024414f, -121.674301f, -671.656372f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "sgbg_w_qic_004_03a_1", 2007457, 7956821, 4, { -498.694794f, -104.267403f, -537.145081f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgbg_w_qic_004_03a_2", 2007457, 7956827, 4, { -422.907196f, -110.815804f, -569.684204f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgbg_w_qic_004_03a_3", 2007457, 7956832, 4, { -443.747589f, -120.455002f, -646.967285f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_0", 2010663, 0, 4, { -213.749603f, -63.715099f, 371.758301f }, 1.000000f, -0.872665f ); 

  }

  void onUpdate( QuestBattle& instance, uint64_t tickCount ) override
  {

  }

  void onEnterTerritory( QuestBattle& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {

  }

};

EXPOSE_SCRIPT( ATearfulReunion );