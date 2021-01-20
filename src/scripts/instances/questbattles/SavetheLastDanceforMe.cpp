#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;

class SavetheLastDanceforMe : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto P_BNPC_AUDIENCE_01 = 8006017;
  static constexpr auto P_BNPC_AUDIENCE_02 = 8010041;
  static constexpr auto P_BNPC_AUDIENCE_03 = 8010042;
  static constexpr auto P_BNPC_AUDIENCE_04 = 8006021;
  static constexpr auto P_BNPC_AUDIENCE_05 = 8005989;
  static constexpr auto P_BNPC_AUDIENCE_06 = 8005995;
  static constexpr auto P_BNPC_AUDIENCE_07 = 8006005;
  static constexpr auto BNPC_DARK_ELEMENTAL_BOSS = 8006135;
  static constexpr auto BNPC_TOUMEI_01 = 8006136;
  static constexpr auto BNPC_TOUMEI_02 = 8006138;
  static constexpr auto BNPC_TOUMEI_03 = 8006139;
  static constexpr auto BNPC_TOUMEI_04 = 8006140;
  static constexpr auto BNPC_TOUMEI_05 = 8006141;
  static constexpr auto BNPC_TOUMEI_06 = 8006142;
  static constexpr auto BNPC_TOUMEI_07 = 8006143;
  static constexpr auto BNPC_TOUMEI_08 = 8006144;
  static constexpr auto BNPC_TOUMEI_09 = 8006145;
  static constexpr auto BNPC_TOUMEI_10 = 8006146;
  static constexpr auto BNPC_ADD_DARKSPRIT_01 = 8006359;
  static constexpr auto BNPC_ADD_DARKSPRIT_02 = 8006361;
  static constexpr auto BNPC_ADD_DARKSPRIT_03 = 8006362;
  static constexpr auto STATUS_INVINCIBLE = 1496;
  static constexpr auto P_BNPC_RANAAMIHGO = 8006990;
  static constexpr auto BNPC_BLACKBALL_01 = 8007108;
  static constexpr auto BNPC_BLACKBALL_02 = 8007109;
  static constexpr auto POP_RANGE_BLACKBALL_ESCAPE_POSITION_01 = 8007118;
  static constexpr auto POP_RANGE_BLACKBALL_ESCAPE_POSITION_02 = 8007125;
  static constexpr auto ACTION_SUMMON_DARKBALL = 17478;
  static constexpr auto ACTION_SHARE_ATTACK_ACTING = 17550;
  static constexpr auto ACTION_TOUMEI_SHARE_ATTACK = 17487;
  static constexpr auto BNPC_ADD_DARKSPRIT_P2_01 = 8010064;
  static constexpr auto BNPC_ADD_DARKSPRIT_P2_02 = 8010065;
  static constexpr auto BNPC_ADD_DARKSPRIT_P2_03 = 8010066;
  static constexpr auto BNPC_ADD_DARKSPRIT_P2_04 = 8010067;
  static constexpr auto BNPC_ADD_DARKSPRIT_P2_05 = 8010068;
  static constexpr auto BNPC_ADD_DARKSPRIT_P2_06 = 8010069;
  static constexpr auto BNPC_ADD_DARKSPRIT_P2_07 = 8010070;
  static constexpr auto P_BNPC_NASHMEIRA = 8010078;
  static constexpr auto POP_RANGE_NPC_NASHMEIRA_MOVE_POSITION_CENTER = 8010079;
  static constexpr auto ACTION_FLAME_DANCE = 17584;
  static constexpr auto P_BNPC_TOUMEI_NASHMEIRA_01 = 8011313;
  static constexpr auto P_BNPC_TOUMEI_NASHMEIRA_02 = 8011314;
  static constexpr auto P_BNPC_TOUMEI_NASHMEIRA_03 = 8011315;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_NORTH_01 = 8012629;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_NORTH_02 = 8012630;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_NORTH_03 = 8012632;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_NORTH_04 = 8012633;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_NORTH_05 = 8012634;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_NORTH_06 = 8012635;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_NORTH_07 = 8012636;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_EAST_01 = 8012628;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_EAST_02 = 8012640;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_EAST_03 = 8012641;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_EAST_04 = 8012642;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_EAST_05 = 8012643;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_EAST_06 = 8012644;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_EAST_07 = 8012645;
  static constexpr auto ACTION_DARK_RUNWAY_ACTING = 16253;
  static constexpr auto BNPC_RAMIA = 8010072;
  static constexpr auto ACTION_DELTA_ATACK_ACTING = 17612;
  static constexpr auto POP_RANGE_DONUT_POSITION = 8013810;
  static constexpr auto POP_RANGE_CROSS_POSITION = 8013811;
  static constexpr auto ACTION_TARGETAE_DONUT = 17607;
  static constexpr auto ACTION_TARGETAE_CROSS = 17608;
  static constexpr auto BNPC_GHOST = 8010074;
  static constexpr auto CHANNELING_DARK = 1;
  static constexpr auto ACTION_ADD_POP_ACTING = 17500;
  static constexpr auto ACTION_BLIND_EFFECT = 17477;
  static constexpr auto ACTION_SHARE_ATTACK = 17487;
  static constexpr auto LOGMESSAGE_ADD_POP = 9510;
  static constexpr auto BNPCNAME_NASHMEIRA = 8488;
  static constexpr auto ACTION_BRIGHTNESS_PILLAR = 17585;
  static constexpr auto ACTION_TARGETAE_GRAVITON = 17609;
  static constexpr auto ACTION_TARGETAE_BIG = 17831;
  static constexpr auto POP_RANGE_AVOID_DARK_RUNWAY = 8025555;
  static constexpr auto POP_RANGE_RANAAMIHGO_NORMAL_POSITION = 8025557;
  static constexpr auto POP_RANGE_NASHMEIRA_NORMAL_POSITION = 8025556;
  static constexpr auto CHANNELING_GENERAL = 12;
  static constexpr auto ACTION_DANCE_FINISH2 = 17837;
  static constexpr auto BGM_SECONDHALF = 165;
  static constexpr auto POP_RANGE_RANAAMIHGO_STANDBY = 8025773;
  static constexpr auto YELL_RANAAMIHGO_NOTICE = 8569;
  static constexpr auto YELL_AUDIENCE_SHOUT_01 = 8570;
  static constexpr auto YELL_AUDIENCE_SHOUT_02 = 8571;
  static constexpr auto BNPCBASE_DARKBALL = 10955;
  static constexpr auto BNPCBASE_DARK_RUNWAY_FIRST = 10959;
  static constexpr auto BNPCBASE_DARK_RUNWAY_NEXT = 10987;
  static constexpr auto POP_RANGE_RANAAMIHGO_PULL_DARK_SPRITE = 8026217;
  static constexpr auto YELL_NASHMEIRA_FLAME_DANCE = 8559;
  static constexpr auto ACTION_TOUMEI_NASHMEIRA_TRIGGER_ACTION = 3269;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_NORTHEAST_01 = 8034301;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_NORTHEAST_02 = 8034304;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_NORTHEAST_03 = 8034305;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_NORTHEAST_04 = 8034306;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_NORTHEAST_05 = 8034307;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_NORTHEAST_06 = 8034308;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_NORTHEAST_07 = 8034309;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_WEST_01 = 8034312;
  static constexpr auto BNPC_TOUMEI_DARK_RUNWAY_WEST_07 = 8034314;
  static constexpr auto POP_RANGE_AVOID_DARK_RUNWAY_02 = 8034324;
  static constexpr auto BNPC_TOUMEI_11 = 8049676;
  static constexpr auto MODELSTATE_WEPON_IDLE = 11;

public:
  SavetheLastDanceforMe() : Sapphire::ScriptAPI::QuestBattleScript( 189 )
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

EXPOSE_SCRIPT( SavetheLastDanceforMe );