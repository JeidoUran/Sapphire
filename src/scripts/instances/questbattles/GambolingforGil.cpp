#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;

class GambolingforGil : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto P_BNPC_NASHMEIRA = 7962976;
  static constexpr auto BNPC_VIKING_WARRIOR_01 = 7962330;
  static constexpr auto BNPC_VIKING_WARRIOR_02 = 7962331;
  static constexpr auto ACTION_PC_PARTNER_CHOISE = 16006;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_01 = 7968311;
  static constexpr auto ACTION_PC_FINISH_TWO_STEPS = 16192;
  static constexpr auto ACTION_PC_FINISH_ZERO_STEPS = 16003;
  static constexpr auto STATUS_PARAM_EVENT = 2918;
  static constexpr auto ACTION_P_BNPC_RANAAMIHGO_FINISH = 17077;
  static constexpr auto ACTION_ANKI_ACTION_01 = 16007;
  static constexpr auto ACTION_ANKI_ACTION_02 = 16008;
  static constexpr auto BNPC_VIKING_WIZARD_01 = 7962333;
  static constexpr auto BNPC_VIKING_WIZARD_02 = 7962334;
  static constexpr auto BNPC_VIKING_WIZARD_03 = 7962335;
  static constexpr auto BNPC_VIKING_WIZARD_04 = 7962336;
  static constexpr auto POP_RANGE_PC_DANCE_POSITION = 7969700;
  static constexpr auto POP_RANGE_NPC_DANCE_POSITION = 7969701;
  static constexpr auto POP_RANGE_NPC_NASHMEIRA_WATCH_POSITION = 7969753;
  static constexpr auto POP_RANGE_FINAL_PHASE_PC_SET_POTISION = 7969924;
  static constexpr auto BNPC_RANAAMIHGO = 7969918;
  static constexpr auto ACTION_BNPC_RANAAMIHGO_ERUPTION_ACTING = 17205;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_02 = 7970398;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_03 = 7970399;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_04 = 7970400;
  static constexpr auto POP_RANGE_STORM_01 = 7970517;
  static constexpr auto POP_RANGE_STORM_02 = 7970519;
  static constexpr auto POP_RANGE_STORM_03 = 7970521;
  static constexpr auto POP_RANGE_STORM_04 = 7970522;
  static constexpr auto POP_RANGE_STORM_05 = 7970525;
  static constexpr auto POP_RANGE_STORM_06 = 7970526;
  static constexpr auto POP_RANGE_STORM_07 = 7970528;
  static constexpr auto POP_RANGE_STORM_08 = 7970529;
  static constexpr auto BNPC_STORM_01 = 7962386;
  static constexpr auto BNPC_STORM_02 = 7962387;
  static constexpr auto BNPC_STORM_03 = 7962389;
  static constexpr auto ACTION_BNPC_RANAAMIHGO_STORM_ACTING = 17208;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_WAVE_GIMMICK_01 = 7970693;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_WAVE_GIMMICK_02 = 7970695;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_WAVE_GIMMICK_03 = 7970696;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_WAVE_GIMMICK_04 = 7970697;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_WAVE_GIMMICK_05 = 7970700;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_WAVE_GIMMICK_06 = 7970701;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_WAVE_GIMMICK_07 = 7970702;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_WAVE_GIMMICK_08 = 7970704;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_WAVE_GIMMICK_09 = 7970705;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_WAVE_GIMMICK_10 = 7970706;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_WAVE_GIMMICK_11 = 7970707;
  static constexpr auto BNPC_TOUMEI_RANAAMIHGO_WAVE_GIMMICK_12 = 7970708;
  static constexpr auto POP_RANGE_NPC_GIMMICK_START_POSITION = 7983680;
  static constexpr auto ACTION_BNPC_RANAAMIHGO_LOOP_DANCE = 17288;
  static constexpr auto POP_RANGE_WARRIOR01_START_POSITION = 7984995;
  static constexpr auto POP_RANGE_WARRIOR02_START_POSITION = 7984996;
  static constexpr auto ACTION_RAGINGAX = 17172;
  static constexpr auto ACTION_PETITMETEOR = 17177;
  static constexpr auto ACTION_PC_FINISH_ONE_STEPS = 16191;
  static constexpr auto ENPC_KUIHLUD = 7990377;
  static constexpr auto ENPC_DANCE_MEMBER01 = 7990381;
  static constexpr auto ENPC_DANCE_MEMBER02 = 7990383;
  static constexpr auto ACTION_TRIGGER_ACTION = 3269;
  static constexpr auto BNPC_GEGERUJU = 7968530;
  static constexpr auto POP_RANGE_GEGERUJU_WATCH_POSITION = 8013197;
  static constexpr auto ACTION_NASHMEIRA_DANCETALK_LOOP_TRIGGER = 3269;
  static constexpr auto ACTIONTIMELINE_BOW = 694;
  static constexpr auto ACTIONTIMELINE_NOD = 739;
  static constexpr auto MODELSTATE_BATTLE_START = 11;
  static constexpr auto ACTIONTIMELINE_BATTLE_START = 1;
  static constexpr auto ACTIONTIMELINE_WELCOME = 738;
  static constexpr auto ACTION_FINISH_TWO_STEPS = 17076;
  static constexpr auto ACTION_NASHMEIRA_BATTLE_END_TRIGGER = 3269;
  static constexpr auto ACTIONTIMELINE_SLAP = 731;
  static constexpr auto ACTION_RANAAMIHGO_MOVE_END_TRIGGER = 3269;
  static constexpr auto ACTION_BNPC_RANAAMIHGO_GAZE_ATACK = 17198;
  static constexpr auto ACTION_BNPC_RANAAMIHGO_PBAE = 17197;
  static constexpr auto ACTION_BNPC_RANAAMIHGO_FINISH_2 = 15646;
  static constexpr auto BGM_FF2_BATTLE_THEME = 108;
  static constexpr auto BGM_DANCE_MUSIC = 656;
  static constexpr auto MODELSTATE_NORMAL = 0;
  static constexpr auto ACTION_FINISH_FOUR_STEPS = 17466;

public:
  GambolingforGil() : Sapphire::ScriptAPI::QuestBattleScript( 188 )
  { }

  void onInit( QuestBattle& instance ) override
  {
    instance.registerEObj( "unknown_0", 2009569, 0, 4, { 763.213318f, 9.000000f, 358.016998f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_1", 2009570, 0, 4, { 748.506775f, 9.000000f, 520.002930f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_2", 2010730, 0, 4, { 763.213318f, 9.000000f, 358.016998f }, 1.000000f, 0.000000f ); 

  }

  void onUpdate( QuestBattle& instance, uint64_t tickCount ) override
  {

  }

  void onEnterTerritory( QuestBattle& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {

  }

};

EXPOSE_SCRIPT( GambolingforGil );