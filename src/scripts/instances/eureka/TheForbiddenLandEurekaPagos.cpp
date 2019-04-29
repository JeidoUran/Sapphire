#include <ScriptObject.h>
#include <Territory/PublicContent.h>
#include <Actor/Player.h>

using namespace Sapphire;

class TheForbiddenLandEurekaPagos : public Sapphire::ScriptAPI::PublicContentScript
{
public:
  TheForbiddenLandEurekaPagos() : Sapphire::ScriptAPI::PublicContentScript( 4 )
  { }

  void onPlayerSetup( Sapphire::PublicContent& instance, Entity::Player& player )
  {
    player.getCurrentZone()->setWeatherOverride( static_cast< Common::Weather >( 2 ) );
    player.setRot( -2.2499f );
    player.setPos( { 719.924f, -802.56f, 397.794f } );
  }

  void onInit( PublicContent& instance ) override
  {
    //!RP Added eobj
    instance.registerEObj( "chest", 2009530, 0, 4, { 586.147f, -692.278f, 59.6727f }, 1.000000f, 2.26487f ); 
    instance.registerEObj( "chest2", 2009530, 0, 4, { 32.1438f, -477.505f, -390.341f }, 1.000000f, 0.296631f ); 
    instance.registerEObj( "baportal", 2009726, 0, 4, { 213.954f, 757.882f, -937.514f }, 1.000000f, -0.00524855f ); 
    instance.registerEObj( "hook", 2009728, 0, 4, { 243.622f, 761.582f, -886.141f }, 1.000000f, -0.00524855f ); 
  }

  void onUpdate( PublicContent& instance, uint32_t currTime ) override
  {

  }

  void onEnterTerritory( PublicContent& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {

  }

};

EXPOSE_SCRIPT( TheForbiddenLandEurekaPagos );