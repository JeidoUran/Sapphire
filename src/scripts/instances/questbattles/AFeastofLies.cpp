#include <ScriptObject.h>
#include <Territory/QuestBattle.h>

using namespace Sapphire;

class AFeastofLies : public Sapphire::ScriptAPI::QuestBattleScript
{
private:
  static constexpr auto P_BNPC_PHASE01_THANCRED = 7944555;
  static constexpr auto P_BNPC_PHASE01_YSHTOLA = 7944556;
  static constexpr auto P_BNPC_PHASE01_URIANGER = 7944557;
  static constexpr auto P_BNPC_PHASE01_RYNE = 7944558;
  static constexpr auto P_BNPC_PHASE01_ALPHINAUD = 7944560;
  static constexpr auto P_BNPC_PHASE01_ALISAIE = 7944559;
  static constexpr auto P_BNPC_PHASE01_ALPHINAUD_PET = 7955281;
  static constexpr auto BNPC_PHASE01_WAVE1_1_01 = 8005099;
  static constexpr auto BNPC_PHASE01_WAVE1_1_02 = 8005138;
  static constexpr auto BNPC_PHASE01_WAVE1_1_03 = 8005154;
  static constexpr auto BNPC_PHASE01_WAVE1_1_04 = 8005156;
  static constexpr auto BNPC_PHASE01_WAVE1_1_05 = 8005159;
  static constexpr auto BNPC_PHASE01_WAVE1_1_06 = 8005100;
  static constexpr auto BNPC_PHASE01_WAVE1_2_01 = 8005101;
  static constexpr auto BNPC_PHASE01_WAVE1_2_02 = 8005155;
  static constexpr auto BNPC_PHASE01_WAVE1_3_01 = 8005102;
  static constexpr auto BNPC_PHASE01_WAVE1_3_02 = 8005157;
  static constexpr auto BNPC_PHASE01_WAVE2_1_01 = 7945475;
  static constexpr auto BNPC_PHASE01_WAVE2_1_02 = 7945482;
  static constexpr auto BNPC_PHASE01_WAVE2_1_03 = 7945522;
  static constexpr auto BNPC_PHASE01_WAVE2_1_04 = 7945523;
  static constexpr auto BNPC_PHASE01_WAVE2_2_01 = 7945572;
  static constexpr auto BNPC_PHASE01_WAVE2_2_02 = 7945573;
  static constexpr auto BNPC_PHASE01_WAVE2_2_03 = 7945574;
  static constexpr auto BNPC_PHASE01_WAVE2_2_04 = 7945575;
  static constexpr auto BNPC_PHASE01_WAVE2_3_01 = 7945581;
  static constexpr auto BNPC_PHASE01_WAVE2_3_02 = 7945582;
  static constexpr auto BNPC_PHASE01_WAVE2_3_03 = 7945583;
  static constexpr auto BNPC_PHASE01_WAVE3_1_01 = 7978288;
  static constexpr auto BNPC_PHASE01_WAVE3_1_02 = 7945589;
  static constexpr auto BNPC_PHASE01_WAVE3_1_03 = 7978292;
  static constexpr auto BNPC_PHASE01_WAVE3_1_04 = 7945591;
  static constexpr auto BNPC_PHASE01_WAVE1_4_01 = 7945596;
  static constexpr auto BNPC_PHASE01_WAVE1_4_02 = 7945597;
  static constexpr auto BNPC_PHASE01_WAVE1_4_03 = 7945598;
  static constexpr auto BNPC_PHASE01_WAVE1_4_04 = 7945599;
  static constexpr auto BNPC_PHASE01_WAVE1_4_05 = 7945600;
  static constexpr auto BNPC_PHASE01_WAVE2_4_01 = 7945602;
  static constexpr auto BNPC_PHASE01_WAVE2_4_02 = 7945603;
  static constexpr auto BNPC_PHASE01_WAVE2_4_03 = 7945604;
  static constexpr auto BNPC_PHASE01_WAVE2_4_04 = 7945605;
  static constexpr auto BNPC_PHASE01_WAVE2_4_05 = 7945606;
  static constexpr auto BNPC_PHASE01_WAVE2_4_06 = 7945607;
  static constexpr auto BNPC_PHASE01_WAVE3_2_01 = 7945609;
  static constexpr auto BNPC_PHASE01_WAVE3_2_02 = 7945610;
  static constexpr auto BNPC_PHASE02_BRINA = 7943381;
  static constexpr auto BNPC_PHASE02_CALCO = 7943382;
  static constexpr auto BNPC_PHASE03_01 = 7950108;
  static constexpr auto BNPC_PHASE03_02 = 7950109;
  static constexpr auto BNPC_PHASE03_03 = 7950110;
  static constexpr auto BNPC_PHASE04_RANJIT = 7959962;
  static constexpr auto BNPC_PHASE04_RANJIT_TOMEI01 = 7966771;
  static constexpr auto BNPC_PHASE04_RANJIT_TOMEI02 = 7966773;
  static constexpr auto BNPC_PHASE04_RANJIT_TOMEI03 = 7966774;
  static constexpr auto BNPC_PHASE04_RANJIT_TOMEI04 = 7966775;
  static constexpr auto BNPC_PHASE04_RANJIT_TOMEI05 = 7967474;
  static constexpr auto BNPC_PHASE04_RANJIT_TOMEI06 = 7967476;
  static constexpr auto BNPC_PHASE04_RANJIT_TOMEI07 = 7967477;
  static constexpr auto BNPC_PHASE04_RANJIT_TOMEI08 = 7967478;
  static constexpr auto BNPC_PHASE04_RANJIT_TOMEI09 = 7969877;
  static constexpr auto BNPC_PHASE04_RANJIT_TOMEI_RIGHTFRONT = 7967776;
  static constexpr auto BNPC_PHASE04_RANJIT_TOMEI_LEFTFRONT = 7967777;
  static constexpr auto BNPC_PHASE04_RANJIT_TOMEI_RIGHTBACK = 7967778;
  static constexpr auto BNPC_PHASE04_RANJIT_TOMEI_LEFTBACK = 7967779;
  static constexpr auto BNPC_PHASE04_FIREBALL01 = 7964866;
  static constexpr auto BNPC_PHASE04_FIREBALL02 = 7964867;
  static constexpr auto BNPC_PHASE04_FIREBALL03 = 7964868;
  static constexpr auto BNPC_PHASE04_FIREBALL04 = 7964869;
  static constexpr auto BNPC_PHASE04_FIREBALL05 = 7964870;
  static constexpr auto BNPC_PHASE04_FIREBALL06 = 7964871;
  static constexpr auto BNPC_PHASE04_FIREBALL07 = 7964872;
  static constexpr auto BNPC_PHASE04_FIREBALL08 = 7964873;
  static constexpr auto BNPC_PHASE04_FIREBALL00 = 7969785;
  static constexpr auto BNPC_PHASE04_LIGHTNINBALL01 = 7960007;
  static constexpr auto BNPC_PHASE04_LIGHTNINBALL02 = 7964859;
  static constexpr auto BNPC_PHASE04_LIGHTNINBALL03 = 7964860;
  static constexpr auto BNPC_PHASE04_LIGHTNINBALL04 = 7964861;
  static constexpr auto BNPC_PHASE04_LIGHTNINBALL05 = 7964862;
  static constexpr auto BNPC_PHASE04_LIGHTNINBALL06 = 7964863;
  static constexpr auto BNPC_PHASE04_LIGHTNINBALL07 = 7964864;
  static constexpr auto BNPC_PHASE04_LIGHTNINBALL08 = 7964865;
  static constexpr auto BNPC_PHASE04_LIGHTNINBALL09 = 7964874;
  static constexpr auto BNPC_PHASE04_LIGHTNINBALL10 = 7964875;
  static constexpr auto BNPC_PHASE04_LIGHTNINBALL11 = 7964877;
  static constexpr auto BNPC_PHASE04_LIGHTNINBALL12 = 7964878;
  static constexpr auto BNPC_PHASE04_DRAGONHEAD01 = 7964855;
  static constexpr auto BNPC_PHASE04_DRAGONHEAD02 = 7964856;
  static constexpr auto BNPC_PHASE04_DRAGONHEAD03 = 7964857;
  static constexpr auto BNPC_PHASE04_DRAGONHEAD04 = 7964858;
  static constexpr auto EVENT_RANGE_PHASE01_PART02_START = 7943395;
  static constexpr auto EVENT_RANGE_PHASE01_PART03_START = 7943401;
  static constexpr auto EVENT_RANGE_PHASE02_BATTLE_AREA = 8035174;
  static constexpr auto EVENT_RANGE_PHASE03_ADDPOP = 7944562;
  static constexpr auto EVENT_RANGE_PHASE03_END = 7944563;
  static constexpr auto SHARED_GROUP_PHASE01_WAVE01_SCREEN = 7951967;
  static constexpr auto SHARED_GROUP_PHASE01_WAVE02_SCREEN = 7951976;
  static constexpr auto SHARED_GROUP_PHASE02_SCREEN = 7961200;
  static constexpr auto SHARED_GROUP_PHASE03_SCREEN = 7950437;
  static constexpr auto SHARED_GROUP_PHASE03_SCREEN_AFTER = 7961093;
  static constexpr auto SHARED_GROUP_PHASE04_BOSS_AREA = 7969349;
  static constexpr auto EOBJ_PHASE02_DOOR_CONTROLLER = 7960685;
  static constexpr auto EOBJ_PHASE01_WAVE01_SCREEN_CONTROLLER = 7952496;
  static constexpr auto EOBJ_PHASE01_WAVE02_SCREEN_CONTROLLER = 7952498;
  static constexpr auto EOBJ_PHASE02_BATTLESCREEN_CONTROLLER = 7960703;
  static constexpr auto EOBJ_PHASE03_CONTROLLER = 7950439;
  static constexpr auto EOBJ_PHASE03_CONTROLLER_AFTER = 7961091;
  static constexpr auto EOBJ_PHASE04_BOSSAREA_CONTROLLER = 7969709;
  static constexpr auto POP_RANGE_PHASE01_WAVE1_RYNE_POS = 7950146;
  static constexpr auto POP_RANGE_PHASE01_WAVE1_THANCRED_POS = 7950148;
  static constexpr auto POP_RANGE_PHASE01_WAVE2_URIANGER_POS = 7950160;
  static constexpr auto POP_RANGE_PHASE01_WAVE2_YSHTOLA_POS = 7950161;
  static constexpr auto POP_RANGE_PHASE01_WAVE2_ALISAIE_MIDPOINT01 = 7950175;
  static constexpr auto POP_RANGE_PHASE01_WAVE2_ALPHINAUD_MIDPOINT01 = 7950177;
  static constexpr auto POP_RANGE_PHASE01_WAVE2_YSHTOLA_MIDPOINT = 7950178;
  static constexpr auto POP_RANGE_PHASE01_WAVE2_URIANGER_MIDPOINT = 7950179;
  static constexpr auto POP_RANGE_PHASE01_WAVE3_ALPHINAUD_MIDPOINT02 = 7950185;
  static constexpr auto POP_RANGE_PHASE01_WAVE3_ALISAIE_MIDPOINT02 = 7950189;
  static constexpr auto POP_RANGE_PHASE01_WAVE3_ALISAIE_POS = 7950193;
  static constexpr auto POP_RANGE_PHASE02_ALPHINAUD_BATTLEPOS = 7950207;
  static constexpr auto POP_RANGE_PHASE03_ALPHINAUD_MIDPOINT03 = 7950197;
  static constexpr auto POP_RANGE_PHASE03_ALPHINAUD_POS = 7950201;
  static constexpr auto POP_RANGE_PHASE01_WAVE1_ALPHINAUD_PET_MIDPOINT01 = 7955270;
  static constexpr auto POP_RANGE_PHASE01_WAVE1_ALPHINAUD_PET_MIDPOINT02 = 7955271;
  static constexpr auto POP_RANGE_PHASE01_WAVE1_ALPHINAUD_PET_BATTLEPOS = 7955272;
  static constexpr auto POP_RANGE_PHASE01_WAVE1_ALPHINAUD_PET_MIDPOINT03 = 7955273;
  static constexpr auto POP_RANGE_PHASE01_WAVE1_ALPHINAUD_PET_POS = 7955275;
  static constexpr auto POP_RANGE_PHASE04_START_POS = 7959953;
  static constexpr auto POP_RANGE_PHASE04_RANJIT_POS00 = 7959994;
  static constexpr auto POP_RANGE_PHASE04_RANJIT_POS01 = 7959990;
  static constexpr auto POP_RANGE_PHASE04_RANJIT_POS02 = 7959991;
  static constexpr auto POP_RANGE_PHASE04_RANJIT_POS03 = 7959992;
  static constexpr auto POP_RANGE_PHASE04_RANJIT_POS04 = 7959993;
  static constexpr auto POP_RANGE_PHASE04_RANJIT_POS05 = 7960000;
  static constexpr auto POP_RANGE_PHASE04_RANJIT_POS06 = 7960001;
  static constexpr auto POP_RANGE_PHASE04_RANJIT_POS07 = 7960002;
  static constexpr auto POP_RANGE_PHASE04_RANJIT_POS08 = 7960003;
  static constexpr auto ACTION_BRINA_COMBO_ACTION = 17293;
  static constexpr auto ACTION_BRINA_COMBO2_ACTION = 17469;
  static constexpr auto ACTION_BRINA_GT_ACTION = 16272;
  static constexpr auto ACTION_BRINA_SHARE_ACTION = 16270;
  static constexpr auto ACTION_CALCO_STAN_ACTION = 16784;
  static constexpr auto ACTION_CALCO_KNOCKBACK_ACTION = 16267;
  static constexpr auto ACTION_CALCO_PBAE_ACTION = 16268;
  static constexpr auto ACTION_RANJIT_RIGHTFRONT_ACTION = 16278;
  static constexpr auto ACTION_RANJIT_LEFTFRONT_ACTION = 16279;
  static constexpr auto ACTION_RANJIT_TRACKINGFLAME_ACTION = 16291;
  static constexpr auto ACTION_RANJIT_LIGHTNINGLASER_ACTION = 16280;
  static constexpr auto ACTION_RANJIT_FRONTSLASH_ACTION = 16277;
  static constexpr auto ACTION_RANJIT_TRACKINGFLAME_TOMEI_ACTION = 16285;

public:
  AFeastofLies() : Sapphire::ScriptAPI::QuestBattleScript( 191 )
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

EXPOSE_SCRIPT( AFeastofLies );