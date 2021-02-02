#include <ScriptObject.h>
#include <Actor/Player.h>

#include <Exd/ExdDataGenerated.h>
#include <Service.h>


using namespace Sapphire;

class CtsEtcVoyagerMoogle :
  public Sapphire::ScriptAPI::EventScript
{
private:

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
    player.sendDebug( "Quest \"Shadowbringers\" completed." );
    player.finishQuest( 69314 );
    player.sendDebug( "Quest \"Hope's Confluence\" completed." );
  }
};
EXPOSE_SCRIPT( CtsEtcVoyagerMoogle );