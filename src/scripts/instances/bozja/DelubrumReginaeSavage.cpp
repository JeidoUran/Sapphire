#include <ScriptObject.h>
#include <Territory/PublicContent.h>

using namespace Sapphire;

class DelubrumReginaeSavage : public Sapphire::ScriptAPI::PublicContentScript
{
public:
  DelubrumReginaeSavage() : Sapphire::ScriptAPI::PublicContentScript( 31 )
  { }

  void onInit( PublicContent& instance ) override
  {

  }

  void onUpdate( PublicContent& instance, uint64_t tickCount ) override
  {

  }

  void onEnterTerritory( PublicContent& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {

  }

};

EXPOSE_SCRIPT( DelubrumReginaeSavage );