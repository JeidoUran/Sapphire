#ifndef _SERVERNOTICEPACKET_H
#define _SERVERNOTICEPACKET_H

#include <Network/GamePacket.h>
#include <Network/PacketDef/Zone/ServerZoneDef.h>
#include "Forwards.h"

namespace Sapphire::Network::Packets::Server
{

  /**
  * @brief The Ping response packet.
  */
  class ServerNoticePacket :
    public ZoneChannelPacket< FFXIVIpcServerNotice >
  {
  public:
    ServerNoticePacket( uint32_t playerId, uint8_t padding, const std::string& message ) :
      ZoneChannelPacket< FFXIVIpcServerNotice >( playerId, playerId )
    {
      initialize( padding, message );
    };

  private:
    void initialize( uint8_t padding, const std::string& message )
    {
      m_data.padding = padding;
      strcpy( m_data.message, message.c_str() );
    };
  };

}

#endif /*_SERVERNOTICEPACKET_H*/
