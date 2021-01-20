#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;

class WhenItRains : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto BNPC_P1_TRASH_01 = 7922741;
  static constexpr auto BNPC_P1_TRASH_02 = 7922742;
  static constexpr auto BNPC_P1_TRASH_03 = 7922796;
  static constexpr auto BNPC_P1_TRASH_04 = 7929110;
  static constexpr auto BNPC_P1_TRASH_05 = 7929112;
  static constexpr auto BNPC_P1_TRASH_06 = 7929120;
  static constexpr auto BNPC_P1_TRASH_07 = 7929122;
  static constexpr auto BNPC_P1_TRASH_08 = 7929123;
  static constexpr auto BNPC_P1_TRASH_09 = 7929125;
  static constexpr auto BNPC_P1_TRASH_10 = 7929126;
  static constexpr auto BNPC_P1_TRASH_11 = 7929127;
  static constexpr auto BNPC_P1_TRASH_12 = 7929128;
  static constexpr auto P_BNPC_ALPHINAUD = 7922726;
  static constexpr auto P_BNPC_CARBUNCLE = 7922728;
  static constexpr auto P_BNPC_ALISAIE = 7922729;
  static constexpr auto PR_P1_ALLY_MOVE_01 = 7931582;
  static constexpr auto PR_P1_ALLY_MOVE_02 = 7931584;
  static constexpr auto PR_P1_ALLY_MOVE_03 = 7931585;
  static constexpr auto PR_P1_ALLY_MOVE_04 = 7931586;
  static constexpr auto PR_P1_ALLY_MOVE_05 = 7931587;
  static constexpr auto PR_P1_ALLY_MOVE_06 = 7931588;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_001 = 7994962;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_002 = 7929116;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_003 = 7994963;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_004 = 7929129;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_005 = 7994964;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_006 = 7929131;
  static constexpr auto BNPC_P2_BOSS_MIDDLETUMIKUI_01 = 7935168;
  static constexpr auto BNPC_P2_TRASH_01 = 7935170;
  static constexpr auto BNPC_P2_TRASH_02 = 7935171;
  static constexpr auto BNPC_P2_TRASH_03 = 7935172;
  static constexpr auto BNPC_P2_TRASH_04 = 7935173;
  static constexpr auto BNPC_P2_TRASH_05 = 7935174;
  static constexpr auto BNPC_P2_TRASH_06 = 7935176;
  static constexpr auto P_BNPC_YASHTOLA = 7935181;
  static constexpr auto P_BNPC_URIANGER = 7935184;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_007 = 7935186;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_008 = 7935187;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_009 = 7935188;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_010 = 7935190;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_011 = 7935192;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_012 = 7935194;
  static constexpr auto BNPC_P3_TRASH_01 = 7935199;
  static constexpr auto BNPC_P3_TRASH_02 = 7935201;
  static constexpr auto BNPC_P3_TRASH_04 = 7935204;
  static constexpr auto P_BNPC_MINFILIA = 7935211;
  static constexpr auto P_BNPC_THANCRED = 7935212;
  static constexpr auto PR_P1_ALLY_MOVE_07 = 7935222;
  static constexpr auto PR_P1_ALLY_MOVE_08 = 7935227;
  static constexpr auto PR_P1_ALLY_MOVE_09 = 7935228;
  static constexpr auto PR_P1_ALLY_MOVE_10 = 7935231;
  static constexpr auto ER_P2_NEAR_MILITARYBASE_A = 7935305;
  static constexpr auto BNPC_P2_TRASH_07 = 7936035;
  static constexpr auto BNPC_P2_TRASH_08 = 7936036;
  static constexpr auto BNPC_P2_TRASH_09 = 7936037;
  static constexpr auto BNPC_P2_TRASH_10 = 7936039;
  static constexpr auto BNPC_P2_TRASH_11 = 7936040;
  static constexpr auto BNPC_P2_TRASH_12 = 7936042;
  static constexpr auto BNPC_P1_TRASH_13 = 7936275;
  static constexpr auto BNPC_P1_TRASH_14 = 7936277;
  static constexpr auto BNPC_P1_TRASH_15 = 7936278;
  static constexpr auto BNPC_P1_TRASH_16 = 7936279;
  static constexpr auto BNPC_P1_TRASH_17 = 7936295;
  static constexpr auto BNPC_P1_TRASH_18 = 7936296;
  static constexpr auto BNPC_P1_TRASH_19 = 7936298;
  static constexpr auto BNPC_P1_TRASH_20 = 7936299;
  static constexpr auto ER_P2_NEAR_RELAXATION_PLAZA = 7936323;
  static constexpr auto ER_P3_NEAR_THANCRED_JUNCTION = 7943295;
  static constexpr auto PR_P3_ALLY_MOVE_01 = 7943473;
  static constexpr auto PR_P3_ALLY_MOVE_02 = 7943474;
  static constexpr auto PR_P3_ALLY_MOVE_03 = 7943475;
  static constexpr auto PR_P3_ALLY_MOVE_04 = 7943476;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_01 = 7943477;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_02 = 7943478;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_03 = 7943479;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_04 = 7943492;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_05 = 7943493;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_06 = 7943494;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_07 = 7943495;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_08 = 7943498;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_09 = 7943499;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_10 = 7943500;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_11 = 7943507;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_12 = 7943508;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_13 = 7943509;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_14 = 7943510;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_16 = 7943515;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_17 = 7943516;
  static constexpr auto BNPC_P3_OBSERVATORY_TRASH_18 = 7943517;
  static constexpr auto BNPC_P3_BOSS_MIDDLETUMIKUI_01 = 7943519;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_FATAL_001 = 7943722;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_FATAL_002 = 7943723;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_FATAL_003 = 7943724;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_FATAL_004 = 7943725;
  static constexpr auto P_BNPC_CRYSTARIUMSOLDIER_FATAL_005 = 7943726;
  static constexpr auto PR_P1_ALLY_MOVE_12 = 7960004;
  static constexpr auto PR_P1_ALLY_MOVE_13 = 7960005;
  static constexpr auto PR_P1_ALLY_MOVE_14 = 7960006;
  static constexpr auto PR_P1_ALLY_MOVE_15 = 7960008;
  static constexpr auto PR_P1_ALLY_MOVE_16 = 7960009;
  static constexpr auto PR_P1_ALLY_MOVE_17 = 7960012;
  static constexpr auto PR_P1_ALLY_MOVE_18 = 7960013;
  static constexpr auto PR_P1_ALLY_MOVE_19 = 7960014;
  static constexpr auto PR_P1_ALLY_MOVE_20 = 7960015;
  static constexpr auto PR_P1_ALLY_MOVE_21 = 7960016;
  static constexpr auto PR_P3_BOSS_ACTION_01 = 7961238;
  static constexpr auto LINEVOICE_ALISAIE_016 = 8202034;
  static constexpr auto LINEVOICE_ALISAIE_012 = 8202030;
  static constexpr auto LINEVOICE_YASHTOLA_002 = 8202096;
  static constexpr auto LINEVOICE_YASHTOLA_019 = 8202113;
  static constexpr auto LINEVOICE_YASHTOLA_014 = 8202108;
  static constexpr auto LINEVOICE_URIANGER_016 = 8202091;
  static constexpr auto LINEVOICE_ALPHINAUD_009 = 8202008;
  static constexpr auto LINEVOICE_ALPHINAUD_018 = 8202017;
  static constexpr auto YELL_ALISAIE_BATTLESTART = 7623;
  static constexpr auto YELL_YASHTOLA_BATTLESTART = 7624;
  static constexpr auto YELL_YASHTOLA_BATTLEEND = 7625;
  static constexpr auto YELL_URIANGER_BARRIER = 7626;
  static constexpr auto YELL_ALPHINAUD_BARRIER = 7627;
  static constexpr auto CHANNELING_ALPHINAUD_ETHERSHARE = 56;
  static constexpr auto BGM_NORMAL = 651;
  static constexpr auto PR_P3_ALISAIE_ACTION_01 = 7962168;
  static constexpr auto PR_P3_ALPHINAUD_ACTION_01 = 7962170;
  static constexpr auto PR_P3_BOSSADD_LEFT = 7962224;
  static constexpr auto PR_P3_BOSSADD_CENTER = 7962225;
  static constexpr auto PR_P3_BOSSADD_RIGHT = 7962226;
  static constexpr auto BEHAVIOR_SOLDIER_RETIRED = 30281;
  static constexpr auto STATUS_PARAM_SOLDIER_KNOCKDOWN = 5059;
  static constexpr auto ACTION_BOSS_ENDRAIDDAMAGE_LONG = 16849;
  static constexpr auto ACTION_BOSS_ADDPOP = 17065;
  static constexpr auto ACTION_BOSS_DASHATTACK = 16850;
  static constexpr auto ACTION_ALPHINAUD_BARRIER = 16983;
  static constexpr auto ACTION_ALPHINAUD_ETHERSHARE = 16982;
  static constexpr auto ACTION_ALISAIE_ETHERICSABER = 17071;
  static constexpr auto STATUS_PARAM_BOSS_SAINTPOWER = 5085;
  static constexpr auto CHANNELING_BOSSADD_GUARD = 25;
  static constexpr auto BNPC_P1_MOVE_P2BOSS_001 = 7968919;
  static constexpr auto BNPC_P1_MOVE_P2TRASH_001 = 7968920;
  static constexpr auto BNPC_P1_MOVE_P2TRASH_002 = 7968923;
  static constexpr auto ACTION_URIANGER_BARRIER = 17062;
  static constexpr auto ACTION_YASHTOLA_METEOR = 16980;
  static constexpr auto BNPC_P3_BOSS_KILLSOLDIER_001 = 7969350;
  static constexpr auto BNPC_P3_DEAD_SOLDIER_001 = 7969352;
  static constexpr auto BNPC_P3_DEAD_SOLDIER_002 = 7969353;
  static constexpr auto BNPC_P3_DEAD_SOLDIER_003 = 7969354;
  static constexpr auto BNPC_P3_DEAD_SOLDIER_004 = 7969355;
  static constexpr auto BNPC_P3_DEAD_SOLDIER_005 = 7969356;
  static constexpr auto BNPC_P3_DEAD_SOLDIER_006 = 7969357;
  static constexpr auto BNPC_P3_DEAD_SOLDIER_007 = 7969358;

public:
  WhenItRains() : Sapphire::ScriptAPI::QuestBattleScript( 186 )
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

EXPOSE_SCRIPT( WhenItRains );