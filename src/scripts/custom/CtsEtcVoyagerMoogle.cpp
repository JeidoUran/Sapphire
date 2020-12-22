#include <ScriptObject.h>
#include <Actor/Player.h>

#include <Exd/ExdDataGenerated.h>
#include <Service.h>


using namespace Sapphire;

class CtsEtcVoyagerMoogle :
  public Sapphire::ScriptAPI::EventScript
{
private:
  constexpr static auto ACTION_ATTUNE = 0x13;
  constexpr static auto ACTION_TELEPORT = 0x4;

  constexpr static auto AETHERYTE_MENU_AETHERNET = 1;
  constexpr static auto AETHERYTE_MENU_HOUSING = 2;
  constexpr static auto AETHERYTE_MENU_HOME_POINT = 3;
  constexpr static auto AETHERYTE_MENU_FAVORITE_POINT = 4;
  constexpr static auto AETHERYTE_MENU_FAVORITE_POINT_SECURITY_TOKEN = 5;

public:
  CtsEtcVoyagerMoogle() :
    Sapphire::ScriptAPI::EventScript( 0xB0236 )
  {
  }

void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
	// for( uint32_t i = 5728; i < 5813; i++ )
	  // player.addItem( i, 5, false, false, true, true );
	player.finishQuest( 69190 );
	player.finishQuest( 69314 );
  }
};
EXPOSE_SCRIPT( CtsEtcVoyagerMoogle );