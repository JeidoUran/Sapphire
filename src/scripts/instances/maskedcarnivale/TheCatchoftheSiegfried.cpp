#include <ScriptObject.h>
#include <Territory/InstanceContent.h>

using namespace Sapphire;

class TheCatchoftheSiegfried : public Sapphire::ScriptAPI::InstanceContentScript
{
public:
  TheCatchoftheSiegfried() : Sapphire::ScriptAPI::InstanceContentScript( 35030 )
  { }

  void onInit( InstanceContent& instance ) override
  {

  }

  void onUpdate( InstanceContent& instance, uint64_t tickCount ) override
  {

  }

  void onEnterTerritory( InstanceContent& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {

  }

};

EXPOSE_SCRIPT( TheCatchoftheSiegfried );