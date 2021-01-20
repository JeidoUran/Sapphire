#include <ScriptObject.h>
#include <Territory/InstanceContent.h>

using namespace Sapphire;

class TheEpicofAlexanderUltimate : public Sapphire::ScriptAPI::InstanceContentScript
{
public:
  TheEpicofAlexanderUltimate() : Sapphire::ScriptAPI::InstanceContentScript( 30086 )
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

EXPOSE_SCRIPT( TheEpicofAlexanderUltimate );