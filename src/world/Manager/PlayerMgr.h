#include "ForwardsZone.h"

namespace Sapphire::World::Manager
{
  class PlayerMgr
  {
  public:
    void movePlayerToLandDestination( Sapphire::Entity::Player& player, uint32_t landId, uint16_t param = 0 );
  };
}