#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;

class ToHaveLovedandLost : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto BNPC_DHIKAI_BOSS = 7941213;
  static constexpr auto BNPC_BLACKHOLE = 7941285;
  static constexpr auto P_BNPC_GRANSON = 7941253;
  static constexpr auto POP_RANGE_CENTER = 7941205;
  static constexpr auto POP_RANGE_NORTH = 7941302;
  static constexpr auto POP_RANGE_NORTHEAST = 7941396;
  static constexpr auto POP_RANGE_SOUTHEAST = 7941397;
  static constexpr auto POP_RANGE_SOUTH = 7941398;
  static constexpr auto POP_RANGE_SOUTHWEST = 7941399;
  static constexpr auto POP_RANGE_NORTHWEST = 7941400;
  static constexpr auto BNPC_BATTLE_FIELD_EDGE_01 = 7941466;
  static constexpr auto BNPC_BATTLE_FIELD_EDGE_02 = 7941472;
  static constexpr auto BNPC_BATTLE_FIELD_EDGE_03 = 7941488;
  static constexpr auto BNPC_BATTLE_FIELD_EDGE_04 = 7941489;
  static constexpr auto BNPC_BATTLE_FIELD_EDGE_05 = 7941490;
  static constexpr auto BNPC_BATTLE_FIELD_EDGE_06 = 7941491;
  static constexpr auto BNPC_BATTLE_FIELD_EDGE_07 = 7941492;
  static constexpr auto BNPC_BATTLE_FIELD_EDGE_08 = 7941493;
  static constexpr auto BNPC_BATTLE_FIELD_EDGE_09 = 7941494;
  static constexpr auto BNPC_BATTLE_FIELD_EDGE_10 = 7941495;
  static constexpr auto BNPC_BATTLE_FIELD_EDGE_11 = 7941496;
  static constexpr auto BNPC_BATTLE_FIELD_EDGE_12 = 7941497;
  static constexpr auto BNPC_BATTLE_FIELD_CENTER = 7944491;
  static constexpr auto BNPC_BATTLE_FIELD_NORTH = 7944480;
  static constexpr auto BNPC_BATTLE_FIELD_EAST = 7944482;
  static constexpr auto BNPC_BATTLE_FIELD_SOUTH = 7944483;
  static constexpr auto BNPC_BATTLE_FIELD_WEST = 7944484;
  static constexpr auto BNPC_TOUMEI_TOWERGIMMICK_A01 = 7944709;
  static constexpr auto BNPC_TOUMEI_TOWERGIMMICK_A02 = 7944710;
  static constexpr auto BNPC_TOUMEI_TOWERGIMMICK_A03 = 7944711;
  static constexpr auto BNPC_TOUMEI_TOWERGIMMICK_A04 = 7944712;
  static constexpr auto BNPC_TOUMEI_TOWERGIMMICK_A05 = 7944713;
  static constexpr auto BNPC_TOUMEI_TOWERGIMMICK_A06 = 7944714;
  static constexpr auto BNPC_TOUMEI_TOWERGIMMICK_B01 = 7944700;
  static constexpr auto BNPC_TOUMEI_TOWERGIMMICK_B02 = 7944701;
  static constexpr auto BNPC_TOUMEI_TOWERGIMMICK_B03 = 7944702;
  static constexpr auto BNPC_TOUMEI_TOWERGIMMICK_B04 = 7944703;
  static constexpr auto BNPC_TOUMEI_TOWERGIMMICK_B05 = 7944704;
  static constexpr auto BNPC_TOUMEI_TOWERGIMMICK_B06 = 7944705;
  static constexpr auto ACTION_TOWER_ATTACK_ACTING = 15548;
  static constexpr auto ACTION_TOWER_ATTACK_SMALL_A01 = 13207;
  static constexpr auto ACTION_TOWER_ATTACK_SMALL_A02 = 13208;
  static constexpr auto ACTION_TOWER_ATTACK_SMALL_A03 = 13209;
  static constexpr auto ACTION_TOWER_ATTACK_SMALL_A04 = 15374;
  static constexpr auto ACTION_TOWER_ATTACK_SMALL_A05 = 15576;
  static constexpr auto ACTION_TOWER_ATTACK_SMALL_A06 = 16612;
  static constexpr auto ACTION_TOWER_ATTACK_LARGE = 16613;
  static constexpr auto ACTION_DHIKAI_RAID_ATTACK_SMALL = 16132;
  static constexpr auto ACTION_DHIKAI_RAID_ATTACK_LARGE = 16133;
  static constexpr auto ACTION_DHIKAI_BLOODWEAPON_ACTING = 16135;
  static constexpr auto ACTION_DHIKAI_SHARE_ATTACK = 16134;
  static constexpr auto ACTION_BLACKHOLE_RESTRAINT = 16167;
  static constexpr auto BNPC_TOUMEI_PC_TARGET = 7994902;
  static constexpr auto BNPC_TOUMEI_NPC_TARGET = 7994928;
  static constexpr auto BNPC_BALL_01 = 7994878;
  static constexpr auto BNPC_BALL_02 = 7994880;
  static constexpr auto BNPC_BALL_03 = 7994881;
  static constexpr auto BNPC_BALL_04 = 7994882;
  static constexpr auto BNPC_BALL_05 = 7994883;
  static constexpr auto BNPC_BALL_06 = 7994884;
  static constexpr auto ACTION_DHIKAI_PBAE = 17427;
  static constexpr auto ACTION_DHIKAI_SUMMON_BALL = 17428;
  static constexpr auto ACTION_DHIKAI_TARGETAE = 17429;
  static constexpr auto BNPC_BALL_07 = 7995395;
  static constexpr auto BNPC_BALL_08 = 7995397;
  static constexpr auto BNPC_BALL_09 = 7995398;
  static constexpr auto BNPC_BALL_10 = 7995399;
  static constexpr auto ACTION_BALL_RAZER = 17432;
  static constexpr auto ACTION_BALL_DONUTS = 17470;
  static constexpr auto ACTION_BALL_CROSS = 17552;
  static constexpr auto BNPC_INV_ACTION_01 = 0;
  static constexpr auto BNPC_INV_ACTION_02 = 0;
  static constexpr auto BNPC_INV_ACTION_03 = 0;
  static constexpr auto BNPC_INV_ACTION_04 = 0;
  static constexpr auto BNPC_INV_ACTION_05 = 0;
  static constexpr auto BNPC_INV_ACTION_06 = 0;
  static constexpr auto ACTION_DHIKAI_CLEAVE = 16131;

public:
  ToHaveLovedandLost() : Sapphire::ScriptAPI::QuestBattleScript( 187 )
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

EXPOSE_SCRIPT( ToHaveLovedandLost );