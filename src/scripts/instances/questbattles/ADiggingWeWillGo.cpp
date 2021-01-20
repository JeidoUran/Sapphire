#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;

class ADiggingWeWillGo : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto P_BNPC_DUKE_CRYSTAL = 7963169;
  static constexpr auto P_BNPC_DWARF_KOLT = 7963167;
  static constexpr auto BNPC_ENEMY_GARGOYLE_1 = 7963189;
  static constexpr auto BNPC_ENEMY_GARGOYLE_2 = 7963190;
  static constexpr auto BNPC_ENEMY_DEATHGAZE_1 = 7963193;
  static constexpr auto BNPC_ENEMY_WOLF_1 = 7963194;
  static constexpr auto BNPC_ENEMY_WOLF_2 = 7963195;
  static constexpr auto BNPC_ENEMY_DEATHGAZE_2 = 7963196;
  static constexpr auto BNPC_ENEMY_BLOODKNIGHT_1 = 7963217;
  static constexpr auto BNPC_ENEMY_BLOODKNIGHT_2 = 7963218;
  static constexpr auto BNPC_ENEMY_GARGOYLE_3 = 7963219;
  static constexpr auto BNPC_ENEMY_GARGOYLE_4 = 7963220;
  static constexpr auto BNPC_ENEMY_WOLF_3 = 7963221;
  static constexpr auto BNPC_ENEMY_WOLF_4 = 7963222;
  static constexpr auto BNPC_ENEMY_BLOODKNIGHT_3 = 7963239;
  static constexpr auto BNPC_ENEMY_BLOODKNIGHT_4 = 7963240;
  static constexpr auto BNPC_ENEMY_BLOODKNIGHT_5 = 7963241;
  static constexpr auto BNPC_ENEMY_GARGOYLE_5 = 7963242;
  static constexpr auto BNPC_ENEMY_GARGOYLE_6 = 7963243;
  static constexpr auto BNPC_ENEMY_GARGOYLE_7 = 7963244;
  static constexpr auto BNPC_ENEMY_DEATHGAZE_3 = 7963254;
  static constexpr auto BNPC_ENEMY_DEATHGAZE_4 = 7963255;
  static constexpr auto BNPC_ENEMY_BLOODKNIGHT_6 = 7963253;
  static constexpr auto BNPC_ENEMY_WOLF_5 = 7963256;
  static constexpr auto BNPC_ENEMY_WOLF_6 = 7963257;
  static constexpr auto BNPC_ENEMY_WOLF_7 = 7963258;
  static constexpr auto BNPC_ENEMY_KENTAUROS = 7963259;
  static constexpr auto BNPC_ENEMY_BOSS_MANTICORE = 7963261;
  static constexpr auto BNPC_ENEMY_GARGOYLE_8 = 7963262;
  static constexpr auto BNPC_ENEMY_GARGOYLE_9 = 7963264;
  static constexpr auto BNPC_ENEMY_GARGOYLE_10 = 7963266;
  static constexpr auto BNPC_ENEMY_GARGOYLE_11 = 7963265;
  static constexpr auto BNPC_ENEMY_GARGOYLE_12 = 7963267;
  static constexpr auto BNPC_ENEMY_GARGOYLE_13 = 7963263;
  static constexpr auto BNPC_ENEMY_GARGOYLE_14 = 7963324;
  static constexpr auto BNPC_ENEMY_GARGOYLE_15 = 7963325;
  static constexpr auto POP_RANGE_PHASE01_POSITION_DWARF_KOLT = 7964048;
  static constexpr auto POP_RANGE_PHASE01_POSITION_DUKE_CRYSTAL = 7964049;
  static constexpr auto POP_RANGE_PHASE02_POSITION_DWARF_KOLT = 7964057;
  static constexpr auto POP_RANGE_PHASE02_POSITION_DUKE_CRYSTAL = 7964065;
  static constexpr auto POP_RANGE_PHASE03_POSITION_DWARF_KOLT = 7964083;
  static constexpr auto POP_RANGE_PHASE03_POSITION_DUKE_CRYSTAL = 7964084;
  static constexpr auto POP_RANGE_PHASE04_POSITION_DWARF_KOLT = 7964148;
  static constexpr auto POP_RANGE_PHASE04_POSITION_DUKE_CRYSTAL = 7964155;
  static constexpr auto POP_RANGE_PHASE05_POSITION_DWARF_KOLT = 7964163;
  static constexpr auto POP_RANGE_PHASE05_POSITION_DUKE_CRYSTAL = 7964169;
  static constexpr auto POP_RANGE_PHASE05_POSITION_PLAYER = 7964191;
  static constexpr auto EVENT_RANGE_PHASE01 = 7964052;
  static constexpr auto EVENT_RANGE_PHASE02 = 7964066;
  static constexpr auto EVENT_RANGE_PHASE03 = 7964073;
  static constexpr auto EVENT_RANGE_PHASE04 = 7964129;
  static constexpr auto EVENT_RANGE_PHASE05 = 7964160;
  static constexpr auto ACTION_ENEMY_GARGOYLE_GTAE = 17017;
  static constexpr auto ACTION_ENEMY_DEATHGAZE_BREATH = 17018;
  static constexpr auto POP_RANGE_PHASE01TO2_HALFWAY_POSITION1_DWARF_KOLT = 7966359;
  static constexpr auto POP_RANGE_PHASE01TO2_HALFWAY_POSITION1_DUKE_CRYSTAL = 7966360;
  static constexpr auto POP_RANGE_PHASE01TO2_HALFWAY_POSITION2_DWARF_KOLT = 7966363;
  static constexpr auto POP_RANGE_PHASE01TO2_HALFWAY_POSITION2_DUKE_CRYSTAL = 7966364;
  static constexpr auto STATUSPARAM_COVER = 5086;
  static constexpr auto STATUSPARAM_COVERED = 5087;
  static constexpr auto POP_RANGE_PHASE03TO4_HALFWAY_POSITION1_DWARF_KOLT = 7967632;
  static constexpr auto POP_RANGE_PHASE03TO4_HALFWAY_POSITION1_DUKE_CRYSTAL = 7967633;
  static constexpr auto POP_RANGE_PHASE03TO4_HALFWAY_POSITION2_DWARF_KOLT = 7967882;
  static constexpr auto POP_RANGE_PHASE03TO4_HALFWAY_POSITION2_DUKE_CRYSTAL = 7967903;
  static constexpr auto EVENT_RANGE_BEFOREPHASE02_POSITION_CHECK_PLAYER = 7967928;
  static constexpr auto EVENT_RANGE_BEFOREPHASE04_POSITION_CHECK_PLAYER = 7967933;
  static constexpr auto ACTION_DUKE_CRYSTAL_RESCUE = 17104;
  static constexpr auto BEHAVIOR_SHAKEHAND = 30307;
  static constexpr auto BEHAVIOR_NORMALSTAND = 30417;
  static constexpr auto POP_RANGE_PHASE02TO3_HALFWAY_POSITION1_DWARF_KOLT = 7968693;
  static constexpr auto POP_RANGE_PHASE02TO3_HALFWAY_POSITION1_DUKE_CRYSTAL = 7968694;
  static constexpr auto EVENT_RANGE_BEFOREPHASE03_POSITION_CHECK_PLAYER = 7968695;
  static constexpr auto YELL_QIBSTART_DWARF_KOLT = 7657;
  static constexpr auto YELL_PHASE01_DWARF_KOLT_01 = 7658;
  static constexpr auto YELL_PHASE01_DUKE_CRYSTAL_01 = 7659;
  static constexpr auto YELL_PHASE01_DWARF_KOLT_02 = 7660;
  static constexpr auto YELL_PHASE01_DWARF_KOLT_03 = 7661;
  static constexpr auto YELL_PHASE01_DUKE_CRYSTAL_02 = 7662;
  static constexpr auto YELL_PHASE02_DUKE_CRYSTAL_01 = 7663;
  static constexpr auto YELL_PHASE04_DUKE_CRYSTAL_01 = 7664;
  static constexpr auto YELL_PHASE04_DUKE_CRYSTAL_02 = 7665;
  static constexpr auto YELL_PHASE05_DWARF_KOLT_01 = 7666;
  static constexpr auto YELL_PHASE05_DWARF_KOLT_02 = 7667;
  static constexpr auto YELL_PHASE05_DWARF_KOLT_03 = 7668;
  static constexpr auto YELL_PHASE05_DWARF_KOLT_04 = 7669;
  static constexpr auto YELL_PHASE05_BOSSREACTION_DWARF_KOLT_01 = 7670;
  static constexpr auto YELL_PHASE05_DUKE_CRYSTAL_01 = 7671;
  static constexpr auto BEHAVIOR_LOOK_AROUND = 30525;
  static constexpr auto SHARED_GROUP_PHASE01_SHIELD = 7967975;
  static constexpr auto EOBJ_PHASE01_SHIELD_CONTROLLER = 7967977;
  static constexpr auto SHARED_GROUP_PHASE02_SHIELD = 7983702;
  static constexpr auto EOBJ_PHASE02_SHIELD_CONTROLLER = 7983701;
  static constexpr auto SHARED_GROUP_PHASE03_SHIELD = 7970625;
  static constexpr auto EOBJ_PHASE03_SHIELD_CONTROLLER = 7970626;
  static constexpr auto BNPC_LIMPID_DUKE_CRYSTAL_GTAE_TARGET = 7972940;
  static constexpr auto ACTION_DUKE_CRYSTAL_LIMITBREAK = 17221;
  static constexpr auto POP_RANGE_PHASE05_DUKE_CRYSTAL_MOVE01 = 7979227;
  static constexpr auto ACTION_ENEMY_BOSS_MANTICORE_CLEAVE = 17025;
  static constexpr auto TIMELINE_ACTION_BOW = 694;
  static constexpr auto TIMELINE_ACTION_SHOCKED = 729;
  static constexpr auto TIMELINE_ACTION_PANIC = 719;
  static constexpr auto TIMELINE_ACTION_POINT = 720;
  static constexpr auto TIMELINE_ACTION_TALK_FOREFINGER = 933;
  static constexpr auto TIMELINE_ACTION_TALK_JOY = 708;
  static constexpr auto TIMELINE_ACTION_TALK_LAUGH = 711;
  static constexpr auto TIMELINE_ACTION_JOY_STRONG = 709;
  static constexpr auto TIMELINE_ACTION_PRAISE = 723;
  static constexpr auto BNPC_LIMPID_KENTAUROS_TARGETAE_01 = 7979657;
  static constexpr auto BNPC_LIMPID_KENTAUROS_TARGETAE_02 = 7984367;
  static constexpr auto BNPC_LIMPID_KENTAUROS_TARGETAE_03 = 7984368;
  static constexpr auto BNPC_LIMPID_KENTAUROS_SHAREAE = 7984477;
  static constexpr auto ACTION_ENEMY_KENTAUROS_TARGETAE = 17023;
  static constexpr auto ACTION_ENEMY_KENTAUROS_SHAREAE = 17227;
  static constexpr auto ACTION_DUKE_CRYSTAL_COVER = 17103;
  static constexpr auto POP_RANGE_PHASE05_TargetAE_POSITION_DUKE_CRYSTAL = 7980271;
  static constexpr auto ACTION_ENEMY_BOSS_MANTICORE_CHARGE = 17224;
  static constexpr auto TIMELINE_ACTION_CHEER = 695;
  static constexpr auto ACTION_ENEMY_BOSS_MANTICORE_KNOCKDOWNROAR = 17237;
  static constexpr auto STATUSPARAM_KNOCKDOWN = 3000;
  static constexpr auto ACTION_DUKE_CRYSTAL_HEALERLB = 17259;
  static constexpr auto ACTION_ENEMY_BOSS_MANTICORE_RAID = 17026;
  static constexpr auto ACTION_ENEMY_BOSS_MANTICORE_BREATH = 17261;
  static constexpr auto ACTION_ENEMY_BOSS_MANTICORE_BIGBREATH = 17264;
  static constexpr auto BGM_PHASE05_BATTLE = 343;
  static constexpr auto ACTION_DUKE_CRYSTAL_REGEN = 17471;
  static constexpr auto TIMELINE_ACTION_YES_STRONG = 740;
  static constexpr auto BGM_PHASE05_BATTLE_BOSS = 344;
  static constexpr auto BGM_NO_MUSIC = 1;
  static constexpr auto ACTION_ENEMY_BOSS_MANTICORE_HP1 = 17027;
  static constexpr auto CHANNELING_TARGETING = 17;
  static constexpr auto CHANNELING_BETAKEN = 84;
  static constexpr auto ACTION_ENEMY_LIMPID_KENTAUROS_SHAREAE = 17212;
  static constexpr auto ACTION_DUKE_CRYSTAL_TANKLB = 17627;
  static constexpr auto ACTION_ENEMY_LIMPID_KENTAUROS_TARGETAE = 17024;
  static constexpr auto YELL_PHASE05_DUKE_CRYSTAL_03 = 8399;
  static constexpr auto ACTION_ENEMY_BOSS_MANTICORE_PBAE = 17029;
  static constexpr auto YELL_PHASE05_DWARF_KOLT_05 = 8402;
  static constexpr auto YELL_PHASE05_DWARF_KOLT_06 = 8403;
  static constexpr auto LCUT_POP_MARKER_01 = 8030895;
  static constexpr auto LCUT_ENPC_01 = 1028108;
  static constexpr auto LCUT_ENPC_02 = 1029406;
  static constexpr auto LCUT_MONSTER_01 = 1029409;
  static constexpr auto LCUT_MONSTER_02 = 1029410;
  static constexpr auto LCUT_MONSTER_03 = 1029411;
  static constexpr auto LCUT_ACTION_01 = 1;
  static constexpr auto ACTION_DUKE_CRYSTAL_BENEDICTION = 17276;
  static constexpr auto POP_RANGE_PHASE05_DWARF_KOLT_REFUGE = 8032137;
  static constexpr auto MODELSTATE_SCARE2 = 3;
  static constexpr auto MODELSTATE_NORMAL = 0;

public:
  ADiggingWeWillGo() : Sapphire::ScriptAPI::QuestBattleScript( 192 )
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

EXPOSE_SCRIPT( ADiggingWeWillGo );