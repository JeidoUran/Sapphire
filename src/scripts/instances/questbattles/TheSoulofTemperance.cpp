#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;

class TheSoulofTemperance : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto P_BNPC_GIOTT = 7978408;
  static constexpr auto BNPC_SOPHROSYNE = 7978410;
  static constexpr auto BNPC_INV_ACTION_01 = 7978411;
  static constexpr auto POP_RANGE_CENTER = 7978529;
  static constexpr auto BNPC_GARGOYLE_01 = 8006319;
  static constexpr auto BNPC_GARGOYLE_02 = 8006358;
  static constexpr auto BNPC_GARGOYLE_03 = 8007294;
  static constexpr auto BNPC_GARGOYLE_04 = 8006373;
  static constexpr auto BNPC_GARGOYLE_05 = 8007301;
  static constexpr auto ACTION_SOPHROSYNE_REVIVE = 16865;
  static constexpr auto ACTION_DUMMY_SEQUENCE_PROGRESS_01 = 3269;
  static constexpr auto BNPC_DUMMY_BOSS_TARGET = 8006875;
  static constexpr auto ACTION_COVER_MET = 17549;
  static constexpr auto ACTION_TRIGGER_A = 3269;
  static constexpr auto ACTION_TRIGGER_B = 4777;
  static constexpr auto ACTION_TRIGGER_C = 17293;
  static constexpr auto ACTION_TRIGGER_D = 17294;
  static constexpr auto ACTION_SOPHROSYNE_ANCIENT_AERO = 16910;
  static constexpr auto ACTION_TOUMEI_ANCIENT_AERO = 16911;
  static constexpr auto ACTION_SOPHROSYNE_ANCIENT_STONE = 17322;
  static constexpr auto ACTION_TOUMEI_ANCIENT_STONE = 17329;
  static constexpr auto ACTION_SOPHROSYNE_HOLY = 16909;
  static constexpr auto ACTION_TOUMEI_HOLY = 17604;
  static constexpr auto ACTION_SOPHROSYNE_SUMMON_ROD = 15928;
  static constexpr auto ACTION_ROD_RAZER = 15603;
  static constexpr auto ACTION_ROD_DONUTS = 15604;
  static constexpr auto ACTION_GARGOYLE_DISPEL_STATUS = 17581;
  static constexpr auto ACTION_SOPHROSYNE_REVIVE_02 = 17910;
  static constexpr auto ACTION_SOPHROSYNE_REVIVE_03 = 17911;
  static constexpr auto ACTION_SOPHROSYNE_REVIVE_04 = 17912;
  static constexpr auto P_BNPC_GIOTT_NOMET = 8034362;
  static constexpr auto BNPC_SOPHROSYNE_MET = 8034361;
  static constexpr auto BNPC_INV_ACTION_02 = 8034363;
  static constexpr auto BNPC_INV_ACTION_03 = 8034364;
  static constexpr auto BNPC_INV_ACTION_04 = 8034365;
  static constexpr auto BNPC_INV_ACTION_05 = 8034366;
  static constexpr auto BNPC_INV_ACTION_06 = 8034367;
  static constexpr auto BNPC_INV_ACTION_07 = 8034368;
  static constexpr auto BNPC_INV_ACTION_08 = 8034369;
  static constexpr auto BNPC_INV_ACTION_09 = 8034370;
  static constexpr auto BNPC_INV_ACTION_10 = 8034371;
  static constexpr auto BNPC_INV_ACTION_11 = 8034372;
  static constexpr auto BNPC_INV_ACTION_12 = 8034373;
  static constexpr auto BNPC_INV_ACTION_13 = 8034374;
  static constexpr auto BNPC_INV_ACTION_14 = 8034375;
  static constexpr auto BNPC_INV_ACTION_15 = 8034376;
  static constexpr auto BNPC_INV_ACTION_16 = 8034377;
  static constexpr auto BNPC_INV_ACTION_17 = 8034378;
  static constexpr auto BNPC_INV_ACTION_18 = 8034379;
  static constexpr auto PR_HOLY_02_01 = 8034419;
  static constexpr auto PR_HOLY_02_02 = 8034420;
  static constexpr auto PR_HOLY_02_03 = 8034421;
  static constexpr auto PR_HOLY_02_04 = 8034422;
  static constexpr auto PR_HOLY_02_05 = 8034423;
  static constexpr auto PR_HOLY_02_06 = 8034424;
  static constexpr auto PR_HOLY_03_01 = 8034425;
  static constexpr auto PR_HOLY_03_02 = 8034426;
  static constexpr auto PR_HOLY_03_03 = 8034427;
  static constexpr auto PR_HOLY_03_04 = 8034428;
  static constexpr auto PR_HOLY_03_05 = 8034429;
  static constexpr auto PR_HOLY_03_06 = 8034430;
  static constexpr auto PR_HOLY_04_01 = 8034431;
  static constexpr auto PR_HOLY_04_02 = 8034432;
  static constexpr auto PR_HOLY_04_03 = 8034433;
  static constexpr auto PR_HOLY_04_04 = 8034434;
  static constexpr auto PR_HOLY_04_05 = 8034435;
  static constexpr auto PR_HOLY_04_06 = 8034436;
  static constexpr auto BNPC_ROD_01 = 8034503;
  static constexpr auto BNPC_ROD_02 = 8034504;
  static constexpr auto BNPC_ROD_03 = 8034505;
  static constexpr auto BNPC_ROD_04 = 8034506;
  static constexpr auto BNPC_ROD_05 = 8034507;
  static constexpr auto BNPC_ROD_06 = 8034508;
  static constexpr auto BNPC_ROD_07 = 8034509;
  static constexpr auto BNPC_ROD_08 = 8034510;
  static constexpr auto P_BNPC_INV_ACTION_01 = 8034610;
  static constexpr auto P_BNPC_INV_ACTION_02 = 8034611;
  static constexpr auto P_BNPC_INV_ACTION_03 = 8034618;
  static constexpr auto P_BNPC_INV_ACTION_04 = 8034656;
  static constexpr auto P_BNPC_INV_ACTION_05 = 8034684;
  static constexpr auto PR_START_POSITION = 8048892;
  static constexpr auto YELL_GIOTT_01 = 8211;
  static constexpr auto ACTION_GIOTT_EXECUTION = 17484;
  static constexpr auto CUT_SCENE_00 = 2100;
  static constexpr auto BGM_LATTER_HALF = 91;

public:
  TheSoulofTemperance() : Sapphire::ScriptAPI::QuestBattleScript( 195 )
  { }

  void onInit( QuestBattle& instance ) override
  {

  }

  void onUpdate( QuestBattle& instance, uint64_t tickCount ) override
  {

  }

  void onEnterTerritory( QuestBattle& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {

  }

};

EXPOSE_SCRIPT( TheSoulofTemperance );