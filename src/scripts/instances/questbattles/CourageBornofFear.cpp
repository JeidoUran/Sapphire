#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;

class CourageBornofFear : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto BNPC_ENEMY_ARC_ANDREIA = 7967468;
  static constexpr auto BNPC_ENEMY_EXC_LANBYRD = 7967473;
  static constexpr auto BNPC_ENEMY_CNJ = 7967487;
  static constexpr auto BNPC_ENEMY_GLA = 7967488;
  static constexpr auto BNPC_ENEMY_THM = 7967490;
  static constexpr auto P_BNPC_ALLY_ARC_LUEREEQ = 7967497;
  static constexpr auto POP_RANGE_DIR_N = 7967671;
  static constexpr auto POP_RANGE_DIR_NE = 7967686;
  static constexpr auto POP_RANGE_DIR_E = 7967674;
  static constexpr auto POP_RANGE_DIR_SE = 7967688;
  static constexpr auto POP_RANGE_DIR_S = 7967673;
  static constexpr auto POP_RANGE_DIR_SW = 7967687;
  static constexpr auto POP_RANGE_DIR_W = 7967675;
  static constexpr auto POP_RANGE_DIR_NW = 7967689;
  static constexpr auto POP_RANGE_DIR_OUT_N = 7967682;
  static constexpr auto POP_RANGE_DIR_OUT_NNE = 7967695;
  static constexpr auto POP_RANGE_DIR_OUT_ENE = 7967696;
  static constexpr auto POP_RANGE_DIR_OUT_E = 7967684;
  static constexpr auto POP_RANGE_DIR_OUT_ESE = 7967697;
  static constexpr auto POP_RANGE_DIR_OUT_SSE = 7967698;
  static constexpr auto POP_RANGE_DIR_OUT_S = 7967683;
  static constexpr auto POP_RANGE_DIR_OUT_SSW = 7967708;
  static constexpr auto POP_RANGE_DIR_OUT_WSW = 7967707;
  static constexpr auto POP_RANGE_DIR_OUT_W = 7967685;
  static constexpr auto POP_RANGE_DIR_OUT_WNW = 7967706;
  static constexpr auto POP_RANGE_DIR_OUT_NNW = 7967705;
  static constexpr auto POP_RANGE_SWORDACTION_DIR_N = 7967735;
  static constexpr auto POP_RANGE_SWORDACTION_DIR_E = 7967737;
  static constexpr auto POP_RANGE_SWORDACTION_DIR_S = 7967740;
  static constexpr auto POP_RANGE_SWORDACTION_DIR_W = 7967741;
  static constexpr auto POP_RANGE_COMMON_DIR_C = 7967885;
  static constexpr auto BNPC_ENEMY_TORNADO_01 = 7967886;
  static constexpr auto BNPC_ENEMY_TORNADO_02 = 7967892;
  static constexpr auto BNPC_ENEMY_TORNADO_03 = 7967893;
  static constexpr auto BNPC_ENEMY_TORNADO_04 = 7967894;
  static constexpr auto BNPC_ENEMY_TORNADO_05 = 7967895;
  static constexpr auto BNPC_ENEMY_TORNADO_06 = 7967896;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_01 = 7967901;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_02 = 7967911;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_03 = 7967912;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_04 = 7967913;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_05 = 7967914;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_06 = 7967915;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_07 = 7967916;
  static constexpr auto BNPC_ENEMY_TOUMEI_CYCLONE_01 = 7967917;
  static constexpr auto P_BNPC_ALLY_TOUMEI_STANARROW_01 = 7967919;
  static constexpr auto ACTION_STAN_ARROW = 17097;
  static constexpr auto ACTION_AERO_LASER_01 = 17093;
  static constexpr auto ACTION_AERO_LASER_02 = 17188;
  static constexpr auto ACTION_ANDREIA_WIDE_VOLLEY_02 = 17189;
  static constexpr auto ACTION_TOUMEI_STAN_ARROW = 17098;
  static constexpr auto STATUS_KNOCKDOWN_ETERNAL = 3000;
  static constexpr auto POP_RANGE_PHASE_01_GLA = 7969302;
  static constexpr auto POP_RANGE_PHASE_01_EXC = 7969305;
  static constexpr auto POP_RANGE_PHASE_01_CNJ = 7969306;
  static constexpr auto POP_RANGE_PHASE_01_THM = 7969307;
  static constexpr auto STATUS_PASSEAGE_OF_ARMS = 5111;
  static constexpr auto ACTION_SUPER_CYCLONE = 17086;
  static constexpr auto ACTION_PASSEAGE_OF_ARMS = 17171;
  static constexpr auto BNPC_MOVEACTION_01 = 7970895;
  static constexpr auto STATUS_PARAM_EVENT = 2918;
  static constexpr auto ACTION_LUEREEQ_START_ACTION = 17100;
  static constexpr auto BNPC_MOVEACTION_START_ARC_01 = 7978048;
  static constexpr auto BNPC_MOVEACTION_START_GRA_01 = 7978049;
  static constexpr auto ACTION_REIN_OF_HOLY_01 = 17081;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_08 = 7978137;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_09 = 7978138;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_10 = 7978139;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_11 = 7978150;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_12 = 7978140;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_13 = 7978141;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_14 = 7978142;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_15 = 7978143;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_16 = 7978144;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_17 = 7978145;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_18 = 7978146;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_19 = 7978147;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_20 = 7978148;
  static constexpr auto BNPC_ENEMY_TOUMEI_REINOFHOLY_21 = 7978149;
  static constexpr auto ACTION_GLA_GIMMICK_START_01 = 17095;
  static constexpr auto BNPC_MOVEACTION_N_01 = 7978732;
  static constexpr auto BNPC_MOVEACTION_E_01 = 7978734;
  static constexpr auto BNPC_MOVEACTION_S_01 = 7978735;
  static constexpr auto BNPC_MOVEACTION_W_01 = 7978736;
  static constexpr auto ACTION_GIMMICK_TRIGGER_01 = 3269;
  static constexpr auto ACTION_ANDREIA_WIDE_VOLLEY_01 = 17083;
  static constexpr auto ACTION_GLA_SHIELD_BASH_01 = 17096;
  static constexpr auto BNPC_ENEMY_WAVEOFLIGHT_01 = 7980244;
  static constexpr auto ACTION_GLA_WAVEOFLIGHT_01 = 17229;
  static constexpr auto ACTION_GLA_TOUMEI_WAVEOFLIGHT_01 = 17230;
  static constexpr auto ACTION_GLA_PROTECT_01 = 17228;
  static constexpr auto BNPC_ENEMY_POSITION_PASSE_01 = 8030462;
  static constexpr auto BNPC_ENEMY_POSITION_PASSE_02 = 8030463;
  static constexpr auto ACTION_ANDREIA_LB3 = 17211;
  static constexpr auto STATUS_RESTRAINT_ETERNAL = 5127;
  static constexpr auto ACTION_EXC_OVERPOWER = 17088;
  static constexpr auto ACTION_ONSLAUGHT2 = 0;
  static constexpr auto BNPC_ENEMY_TOUMEI_CYCLONEDONUT_01 = 7981765;
  static constexpr auto ACTION_GIMMICK_TRIGGER_02 = 4777;
  static constexpr auto ACTION_ARC_BIG_SHOT = 17084;
  static constexpr auto ACTION_GIMMICK_TRIGGER_03 = 17293;
  static constexpr auto ACTION_GIMMICK_TRIGGER_04 = 17294;
  static constexpr auto CHANNELING_KABAU = 25;
  static constexpr auto ACTION_POS_MOVE = 4743;
  static constexpr auto YELL_QIB_LUEREEQ_001 = 7919;
  static constexpr auto YELL_QIB_LUEREEQ_002 = 7920;
  static constexpr auto YELL_QIB_EXC_002 = 7923;
  static constexpr auto YELL_QIB_THM_001 = 7924;
  static constexpr auto YELL_QIB_CNJ_001 = 7925;
  static constexpr auto YELL_QIB_GLA_001 = 7926;
  static constexpr auto YELL_QIB_LUEREEQ_004 = 7927;
  static constexpr auto YELL_QIB_ANDREIA_001 = 7928;
  static constexpr auto YELL_QIB_LUEREEQ_006 = 7931;
  static constexpr auto YELL_QIB_LUEREEQ_007 = 7932;
  static constexpr auto YELL_QIB_LUEREEQ_008 = 7933;
  static constexpr auto YELL_QIB_GLA_002 = 7935;
  static constexpr auto YELL_QIB_ANDREIA_002 = 7936;
  static constexpr auto YELL_QIB_EXC_005 = 7937;
  static constexpr auto YELL_QIB_THM_002 = 7938;
  static constexpr auto YELL_QIB_CNJ_002 = 7939;
  static constexpr auto YELL_QIB_LUEREEQ_015 = 7940;
  static constexpr auto YELL_QIB_ANDREIA_004 = 7942;
  static constexpr auto YELL_QIB_LUEREEQ_009 = 7943;
  static constexpr auto YELL_QIB_LUEREEQ_010 = 7954;
  static constexpr auto YELL_QIB_LUEREEQ_011 = 7955;
  static constexpr auto YELL_QIB_GLA_004 = 7956;
  static constexpr auto YELL_QIB_ANDREIA_005 = 7957;
  static constexpr auto YELL_QIB_ANDREIA_006 = 7958;
  static constexpr auto YELL_QIB_EXC_006 = 7959;
  static constexpr auto YELL_QIB_EXC_007 = 7960;
  static constexpr auto YELL_QIB_GLA_005 = 7961;
  static constexpr auto YELL_QIB_GLA_006 = 7962;
  static constexpr auto YELL_QIB_LUEREEQ_012 = 7963;
  static constexpr auto YELL_QIB_LUEREEQ_013 = 7964;
  static constexpr auto YELL_QIB_LUEREEQ_014 = 7965;
  static constexpr auto YELL_QIB_EXC_008 = 7967;
  static constexpr auto YELL_QIB_EXC_009 = 7968;
  static constexpr auto YELL_QIB_LUEREEQ_016 = 7969;
  static constexpr auto YELL_QIB_LUEREEQ_017 = 7970;
  static constexpr auto BNPC_EXC_TOUMEI_THRIL = 7990173;
  static constexpr auto YELL_QIB_ANDREIA_007 = 7921;

public:
  CourageBornofFear() : Sapphire::ScriptAPI::QuestBattleScript( 196 )
  { }

  void onInit( QuestBattle& instance ) override
  {
    instance.registerEObj( "sgvf_w_lvd_b1199", 2007457, 7948501, 4, { 632.042480f, 24.299101f, 64.149353f }, 1.000000f, 0.000000f ); 
    // States -> circle_off (id: 3) circle_off (id: 4) circle_on (id: 5) circle_on (id: 6) 
    instance.registerEObj( "sgvf_w_lvd_b1199_1", 2007457, 7969476, 4, { -246.226196f, 10.024030f, 682.587524f }, 0.991760f, 0.000048f ); 
    // States -> circle_off (id: 3) circle_off (id: 4) circle_on (id: 5) circle_on (id: 6) 
    instance.registerEObj( "unknown_0", 2010533, 0, 4, { -278.803986f, 9.483806f, 681.410889f }, 1.000000f, 0.000000f ); 

  }

  void onUpdate( QuestBattle& instance, uint64_t tickCount ) override
  {

  }

  void onEnterTerritory( QuestBattle& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {

  }

};

EXPOSE_SCRIPT( CourageBornofFear );