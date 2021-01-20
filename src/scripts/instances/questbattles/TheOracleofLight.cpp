#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;

class TheOracleofLight : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto EOBJ_SHARED_CONTROL_A = 7995220;
  static constexpr auto EOBJ_SHARED_CONTROL_B = 7995221;
  static constexpr auto EOBJ_SHARED_CONTROL_C = 7995223;
  static constexpr auto EOBJ_SHARED_CONTROL_D = 7995224;
  static constexpr auto EOBJ_SHARED_CONTROL_E = 7995225;
  static constexpr auto EOBJ_SHARED_CONTROL_BOSS = 7995229;
  static constexpr auto EOBJ_EVENT_ACTION_1 = 8005164;
  static constexpr auto ER_RECT_A = 7995230;
  static constexpr auto ER_RECT_B = 7995231;
  static constexpr auto ER_RECT_C = 7995232;
  static constexpr auto ER_RECT_D = 7995233;
  static constexpr auto ER_RECT_E = 7995234;
  static constexpr auto ER_RECT_F = 7995235;
  static constexpr auto ER_RECT_G = 7995236;
  static constexpr auto ER_RECT_H = 8046907;
  static constexpr auto PR_BOSS_BATTLE_CENTER = 8015736;
  static constexpr auto PR_BOSS_BATTLE_OUTSIDE_01 = 8015746;
  static constexpr auto PR_BOSS_BATTLE_OUTSIDE_02 = 8015749;
  static constexpr auto PR_BOSS_BATTLE_OUTSIDE_03 = 8015756;
  static constexpr auto PR_BOSS_BATTLE_OUTSIDE_04 = 8015761;
  static constexpr auto PR_BOSS_BATTLE_OUTSIDE_05 = 8015771;
  static constexpr auto PR_BOSS_BATTLE_OUTSIDE_06 = 8015772;
  static constexpr auto PR_BOSS_BATTLE_OUTSIDE_07 = 8015778;
  static constexpr auto PR_BOSS_BATTLE_OUTSIDE_08 = 8015779;
  static constexpr auto PR_BOSS_BATTLE_INSIDE_01 = 8016473;
  static constexpr auto PR_BOSS_BATTLE_INSIDE_02 = 8016475;
  static constexpr auto PR_BOSS_BATTLE_INSIDE_03 = 8016477;
  static constexpr auto PR_BOSS_BATTLE_INSIDE_04 = 8016479;
  static constexpr auto PR_BOSS_BATTLE_INSIDE_05 = 8016480;
  static constexpr auto PR_BOSS_BATTLE_INSIDE_06 = 8016481;
  static constexpr auto PR_BOSS_BATTLE_INSIDE_07 = 8016482;
  static constexpr auto PR_BOSS_BATTLE_INSIDE_08 = 8016484;
  static constexpr auto PR_BOSS_BATTLE_INSIDE_09 = 8016487;
  static constexpr auto PR_BOSS_BATTLE_INSIDE_10 = 8016490;
  static constexpr auto PR_BOSS_BATTLE_INSIDE_11 = 8016506;
  static constexpr auto PR_BOSS_BATTLE_INSIDE_12 = 8016507;
  static constexpr auto PR_LYNA_BATTLE1_01 = 7996369;
  static constexpr auto PR_LYNA_BATTLE1_02 = 7996370;
  static constexpr auto PR_LYNA_BATTLE2_01 = 7996371;
  static constexpr auto PR_LYNA_BATTLE2_02 = 7996373;
  static constexpr auto PR_ALPHINAUD_BATTLE2_01 = 8010020;
  static constexpr auto PR_ALPHINAUD_BATTLE2_02 = 8010021;
  static constexpr auto PR_ALISAIE_BATTLE2_02 = 8010022;
  static constexpr auto PR_ALPHINAUD_BATTLE3_01 = 8010023;
  static constexpr auto PR_ALISAIE_BATTLE3_01 = 8010024;
  static constexpr auto PR_LYNA_BATTLE3_01 = 7996375;
  static constexpr auto PR_LYNA_CASTLE = 7996377;
  static constexpr auto PR_RYNE_CASTLE = 8010025;
  static constexpr auto PR_LYNA_STAIRS_01 = 7996379;
  static constexpr auto PR_LYNA_STAIRS_02 = 8010018;
  static constexpr auto PR_LYNA_STAIRS_03 = 7996380;
  static constexpr auto PR_LYNA_AFTER_LCUT = 7996381;
  static constexpr auto PR_PC_AFTER_LCUT = 8005186;
  static constexpr auto PR_LYNA_BEFORE_BOSS = 7996382;
  static constexpr auto PR_RYNE_BEFORE_BOSS = 8010038;
  static constexpr auto PR_PC_BOSS = 7996383;
  static constexpr auto PR_ALPHINAUD_BOSS = 7996388;
  static constexpr auto PR_ALISAIE_BOSS = 7996391;
  static constexpr auto PR_CARBUNCLE_BOSS = 7996392;
  static constexpr auto PR_LYNA_BOSS = 7996393;
  static constexpr auto PR_RYNE_BOSS = 7996395;
  static constexpr auto PR_BATTLE01_ACTOR_MOVE_ROUTE = 8035430;
  static constexpr auto PR_BATTLE01_ACTOR_MOVE_01 = 8035483;
  static constexpr auto PR_BATTLE01_ACTOR_MOVE_02 = 8035487;
  static constexpr auto PR_BATTLE01_ACTOR_MOVE_03 = 8035488;
  static constexpr auto PR_BATTLE01_ACTOR_MOVE_04 = 8035490;
  static constexpr auto PR_BATTLE_BOSS_CIRCLE_OUTSIDE = 8042740;
  static constexpr auto PR_BATTLE_BOSS_CIRCLE_OUTSIDE2 = 8037590;
  static constexpr auto P_BNPC_LYNA = 7995237;
  static constexpr auto P_BNPC_ALPHINAUD = 7995384;
  static constexpr auto P_BNPC_CARBUNCLE = 7995385;
  static constexpr auto P_BNPC_ALISAIE = 7995386;
  static constexpr auto P_BNPC_RYNE_RESTRAINT = 7995387;
  static constexpr auto P_BNPC_RYNE_FREE = 7995388;
  static constexpr auto BNPC_ENEMY_RANJIT = 7995432;
  static constexpr auto BNPC_ENEMY_RANJIT_PET = 7995433;
  static constexpr auto BNPC_BATTLE1_TRASH_01 = 7996339;
  static constexpr auto BNPC_BATTLE1_TRASH_02 = 7996340;
  static constexpr auto BNPC_BATTLE1_TRASH_03 = 7996341;
  static constexpr auto BNPC_BATTLE2A_TRASH_01 = 7996342;
  static constexpr auto BNPC_BATTLE2B_TRASH_02 = 7996343;
  static constexpr auto BNPC_BATTLE2B_TRASH_03 = 7996344;
  static constexpr auto BNPC_BATTLE2B_TRASH_04 = 7996345;
  static constexpr auto BNPC_BATTLE2B_TRASH_05 = 7996346;
  static constexpr auto BNPC_BATTLE3A_TRASH_01 = 7996348;
  static constexpr auto BNPC_BATTLE3A_TRASH_02 = 7996349;
  static constexpr auto BNPC_BATTLE3A_TRASH_03 = 7996350;
  static constexpr auto BNPC_BATTLE3B_TRASH_01 = 7996352;
  static constexpr auto BNPC_BATTLE3B_TRASH_02 = 7996353;
  static constexpr auto BNPC_BATTLE3B_TRASH_03 = 7996354;
  static constexpr auto BNPC_BATTLE3B_TRASH_04 = 7996355;
  static constexpr auto BNPC_BATTLE3C_TRASH_01 = 7996358;
  static constexpr auto BNPC_BATTLE3C_TRASH_02 = 7996359;
  static constexpr auto BNPC_BATTLE3C_TRASH_03 = 7996360;
  static constexpr auto BNPC_BATTLE3C_TRASH_04 = 7996361;
  static constexpr auto BNPC_BATTLE3C_TRASH_05 = 7996362;
  static constexpr auto BNPC_BATTLE4_TRASH_01 = 7996363;
  static constexpr auto BNPC_BATTLE4_TRASH_02 = 7996364;
  static constexpr auto BNPC_BATTLE5_TRASH_01 = 7996366;
  static constexpr auto BNPC_BATTLE5_TRASH_02 = 7996367;
  static constexpr auto BNPC_ACTOR_BOSS_CRYSTARIUM_01 = 8007080;
  static constexpr auto BNPC_ACTOR_BOSS_CRYSTARIUM_02 = 8007081;
  static constexpr auto BNPC_ACTOR_BOSS_CRYSTARIUM_03 = 8007105;
  static constexpr auto BNPC_TOUMEI_THUNDER_01 = 8014774;
  static constexpr auto BNPC_TOUMEI_THUNDER_02 = 8014775;
  static constexpr auto BNPC_TOUMEI_THUNDER_03 = 8014776;
  static constexpr auto BNPC_TOUMEI_THUNDER_04 = 8014777;
  static constexpr auto BNPC_TOUMEI_THUNDER_05 = 8014778;
  static constexpr auto BNPC_TOUMEI_THUNDER_06 = 8014779;
  static constexpr auto BNPC_TOUMEI_THUNDER_07 = 8014780;
  static constexpr auto BNPC_TOUMEI_THUNDER_08 = 8014781;
  static constexpr auto BNPC_TOUMEI_FLAME_01 = 8014794;
  static constexpr auto BNPC_TOUMEI_FLAME_02 = 8014797;
  static constexpr auto BNPC_TOUMEI_FLAME_03 = 8014798;
  static constexpr auto BNPC_TOUMEI_FLAME_04 = 8014799;
  static constexpr auto BNPC_TOUMEI_FLAME_05 = 8014800;
  static constexpr auto BNPC_ACTOR_01_CRYSTARIUM_01 = 8035443;
  static constexpr auto BNPC_ACTOR_01_CRYSTARIUM_02 = 8035444;
  static constexpr auto BNPC_ACTOR_01_CRYSTARIUM_03 = 8035445;
  static constexpr auto BNPC_ACTOR_01_CRYSTARIUM_04 = 8035446;
  static constexpr auto BNPC_ACTOR_01_EULMORE_01 = 8035474;
  static constexpr auto BNPC_ACTOR_01_EULMORE_02 = 8035475;
  static constexpr auto BNPC_ACTOR_01_EULMORE_03 = 8035476;
  static constexpr auto BNPC_ACTOR_01_EULMORE_04 = 8035477;
  static constexpr auto BNPC_ACTOR_03_CRYSTARIUM_01 = 8035508;
  static constexpr auto BNPC_ACTOR_03_CRYSTARIUM_02 = 8035509;
  static constexpr auto BNPC_ACTOR_03_CRYSTARIUM_03 = 8035510;
  static constexpr auto BNPC_ACTOR_03_CRYSTARIUM_04 = 8035511;
  static constexpr auto BNPC_ACTOR_03_CRYSTARIUM_05 = 8035517;
  static constexpr auto BNPC_ACTOR_03_EULMORE_01 = 8035512;
  static constexpr auto BNPC_ACTOR_03_EULMORE_02 = 8035513;
  static constexpr auto BNPC_ACTOR_03_EULMORE_03 = 8035514;
  static constexpr auto BNPC_ACTOR_03_EULMORE_04 = 8035516;
  static constexpr auto BNPC_ACTOR_03_EULMORE_05 = 8035515;
  static constexpr auto BNPC_FIREBALL_01 = 8037081;
  static constexpr auto BNPC_FIREBALL_02 = 8037082;
  static constexpr auto BNPC_FIREBALL_03 = 8037083;
  static constexpr auto BNPC_FIREBALL_04 = 8037084;
  static constexpr auto BNPC_FIREBALL_05 = 8037086;
  static constexpr auto BNPC_FIREBALL_06 = 8037088;
  static constexpr auto BNPC_FIREBALL_07 = 8037096;
  static constexpr auto BNPC_FIREBALL_08 = 8037097;
  static constexpr auto BNPC_FIREBALL_09 = 8037098;
  static constexpr auto BNPC_FIREBALL_10 = 8037100;
  static constexpr auto BNPC_FIREBALL_11 = 8037101;
  static constexpr auto BNPC_FIREBALL_12 = 8037102;
  static constexpr auto ACTION_RANJIT_THUNDER_RAID = 17618;
  static constexpr auto ACTION_RANJIT_FLAME_GT = 17619;
  static constexpr auto ACTION_RANJIT_MOVE = 17620;

public:
  TheOracleofLight() : Sapphire::ScriptAPI::QuestBattleScript( 185 )
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

EXPOSE_SCRIPT( TheOracleofLight );