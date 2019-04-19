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

  }

  void onInit( PublicContent& instance ) override
  {

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