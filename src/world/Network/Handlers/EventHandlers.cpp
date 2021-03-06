#include <Common.h>
#include <Logging/Logger.h>
#include <Exd/ExdDataGenerated.h>
#include <Network/CommonNetwork.h>
#include <Network/GamePacketNew.h>
#include <Network/PacketContainer.h>
#include <Network/PacketDef/Zone/ServerZoneDef.h>
#include <Network/PacketDef/Zone/ClientZoneDef.h>

#include "Network/GameConnection.h"
#include "Network/PacketWrappers/ServerNoticePacket.h"
#include "Network/PacketWrappers/EventStartPacket.h"
#include "Network/PacketWrappers/EventFinishPacket.h"
#include "Network/PacketWrappers/PlayerStateFlagsPacket.h"

#include "Script/ScriptMgr.h"

#include <Util/Util.h>

#include "Event/EventHandler.h"
#include "Event/EventHelper.h"

#include "Territory/InstanceContent.h"

#include "Session.h"

#include "Framework.h"

extern Sapphire::Framework g_fw;

using namespace Sapphire::Common;
using namespace Sapphire::Network::Packets;
using namespace Sapphire::Network::Packets::Server;

void Sapphire::Network::GameConnection::eventHandlerTalk( const Packets::FFXIVARR_PACKET_RAW& inPacket,
                                                          Entity::Player& player )
{
  auto pScriptMgr = g_fw.get< Scripting::ScriptMgr >();
  auto pExdData = g_fw.get< Data::ExdDataGenerated >();

  const auto packet = ZoneChannelPacket< Client::FFXIVIpcEventHandlerTalk >( inPacket );

  const auto actorId = packet.data().actorId;
  const auto eventId = packet.data().eventId;

  auto eventType = static_cast< uint16_t >( eventId >> 16 );

  std::string eventName = "onTalk";
  std::string objName = Event::getEventName( eventId );

  player.sendDebug( "Chara: " +
                    std::to_string( actorId ) + " -> " +
                    std::to_string( Event::mapEventActorToRealActor( static_cast< uint32_t >( actorId ) ) ) +
                    " \neventId: " +
                    std::to_string( eventId ) +
                    " (0x" + Util::intToHexString( static_cast< uint64_t >( eventId & 0xFFFFFFF ), 8 ) + ")" );


  player.sendDebug( "Calling: " + objName + "." + eventName );
  player.eventStart( actorId, eventId, Event::EventHandler::Talk, 0, 0 );

  if( auto instance = player.getCurrentInstance() )
  {
    instance->onTalk( player, eventId, actorId );
  }
  else if( !pScriptMgr->onTalk( player, actorId, eventId ) &&
           eventType == Event::EventHandler::EventHandlerType::Quest )
  {
    auto questInfo = pExdData->get< Sapphire::Data::Quest >( eventId );
    if( questInfo )
      player.sendUrgent( "Quest not implemented: " + questInfo->name + " (" + questInfo->id + ")" );
  }

  player.checkEvent( eventId );

}

void Sapphire::Network::GameConnection::eventHandlerEmote( const Packets::FFXIVARR_PACKET_RAW& inPacket,
                                                       Entity::Player& player )
{

  auto pScriptMgr = g_fw.get< Scripting::ScriptMgr >();
  auto pExdData = g_fw.get< Data::ExdDataGenerated >();

  const auto packet = ZoneChannelPacket< Client::FFXIVIpcEventHandlerEmote >( inPacket );

  const auto actorId = packet.data().actorId;
  const auto eventId = packet.data().eventId;
  const auto emoteId = packet.data().emoteId;
  const auto eventType = static_cast< uint16_t >( eventId >> 16 );

  std::string eventName = "onEmote";
  std::string objName = Event::getEventName( eventId );

  player.sendDebug( "Chara: " +
                    std::to_string( actorId ) + " -> " +
                    std::to_string( Event::mapEventActorToRealActor( static_cast< uint32_t >( actorId ) ) ) +
                    " \neventId: " +
                    std::to_string( eventId ) +
                    " (0x" + Util::intToHexString( static_cast< uint64_t >( eventId & 0xFFFFFFF ), 8 ) + ")" );

  player.sendDebug( "Calling: " + objName + "." + eventName );

  player.eventStart( actorId, eventId, Event::EventHandler::Emote, 0, emoteId );

  if( !pScriptMgr->onEmote( player, actorId, eventId, static_cast< uint8_t >( emoteId ) ) &&
      eventType == Event::EventHandler::EventHandlerType::Quest )
  {
    auto questInfo = pExdData->get< Sapphire::Data::Quest >( eventId );
    if( questInfo )
      player.sendUrgent( "Quest not implemented: " + questInfo->name );
  }

  player.checkEvent( eventId );
}

void Sapphire::Network::GameConnection::eventHandlerWithinRange( const Packets::FFXIVARR_PACKET_RAW& inPacket,
                                                             Entity::Player& player )
{
  auto pScriptMgr = g_fw.get< Scripting::ScriptMgr >();

  const auto packet = ZoneChannelPacket< Client::FFXIVIpcEventHandlerWithinRange >( inPacket );

  const auto eventId = packet.data().eventId;
  const auto param1 = packet.data().param1;
  const auto& pos = packet.data().position;

  std::string eventName = "onWithinRange";
  std::string objName = Event::getEventName( eventId );
  player.sendDebug( "Calling: " + objName + "." + eventName + " - " + std::to_string( eventId ) +
                    " p1: " + std::to_string( param1 ) );

  player.eventStart( player.getId(), eventId, Event::EventHandler::WithinRange, 1, param1 );

  pScriptMgr->onWithinRange( player, eventId, param1, pos.x, pos.y, pos.z );

  player.checkEvent( eventId );
}

void Sapphire::Network::GameConnection::eventHandlerOutsideRange( const Packets::FFXIVARR_PACKET_RAW& inPacket,
                                                              Entity::Player& player )
{
  auto pScriptMgr = g_fw.get< Scripting::ScriptMgr >();

  const auto packet = ZoneChannelPacket< Client::FFXIVIpcEventHandlerOutsideRange >( inPacket );
  const auto eventId = packet.data().eventId;
  const auto param1 = packet.data().param1;
  const auto& pos = packet.data().position;

  std::string eventName = "onOutsideRange";
  std::string objName = Event::getEventName( eventId );
  player.sendDebug( "Calling: " + objName + "." + eventName + " - " + std::to_string( eventId ) +
                    " p1: " + std::to_string( param1 ) );

  player.eventStart( player.getId(), eventId, Event::EventHandler::WithinRange, 1, param1 );

  pScriptMgr->onOutsideRange( player, eventId, param1, pos.x, pos.y, pos.z );

  player.checkEvent( eventId );
}

void Sapphire::Network::GameConnection::eventHandlerEnterTerritory( const Packets::FFXIVARR_PACKET_RAW& inPacket,
                                                                Entity::Player& player )
{
  auto pScriptMgr = g_fw.get< Scripting::ScriptMgr >();

  const auto packet = ZoneChannelPacket< Client::FFXIVIpcEnterTerritoryHandler >( inPacket );

  const auto eventId = packet.data().eventId;
  const auto param1 = packet.data().param1;
  const auto param2 = packet.data().param2;

  std::string eventName = "onEnterTerritory";

  std::string objName = Event::getEventName( eventId );

  player.sendDebug( "Calling: " + objName + "." + eventName + " - " + std::to_string( eventId ) );

  if( auto instance = player.getCurrentInstance() )
  {
    player.eventStart( player.getId(), eventId, Event::EventHandler::EnterTerritory, 1, player.getZoneId() );
    instance->onEnterTerritory( player, eventId, param1, param2 );
  }
  else
  {
    player.eventStart( player.getId(), eventId, Event::EventHandler::EnterTerritory, 0, player.getZoneId() );
    pScriptMgr->onEnterTerritory( player, eventId, param1, param2 );
  }

  player.checkEvent( eventId );
}

void Sapphire::Network::GameConnection::eventHandlerReturn( const Packets::FFXIVARR_PACKET_RAW& inPacket,
                                                        Entity::Player& player )
{
  const auto packet = ZoneChannelPacket< Client::FFXIVIpcEventHandlerReturn >( inPacket );
  const auto eventId = packet.data().eventId;
  const auto scene = packet.data().scene;
  const auto param1 = packet.data().param1;
  const auto param2 = packet.data().param2;
  const auto param3 = packet.data().param3;
  const auto param4 = packet.data().param4;

  std::string eventName = Event::getEventName( eventId );

  player.sendDebug( "eventId: " +
                    std::to_string( eventId ) +
                    " ( 0x" + Util::intToHexString( static_cast< uint64_t >( eventId & 0xFFFFFFF ), 8 ) + " ) " +
                    " scene: " + std::to_string( scene ) +
                    " p1: " + std::to_string( param1 ) +
                    " p2: " + std::to_string( param2 ) +
                    " p3: " + std::to_string( param3 ) );

  auto pEvent = player.getEvent( eventId );
  if( pEvent )
  {
    pEvent->setPlayedScene( false );
    // try to retrieve a stored callback
    auto eventCallback = pEvent->getEventReturnCallback();
    // if there is one, proceed to call it
    if( eventCallback )
    {
      Event::SceneResult result;
      result.actorId = pEvent->getActorId();
      result.eventId = eventId;
      result.param1 = param1;
      result.param2 = param2;
      result.param3 = param3;
      result.param4 = param4;
      eventCallback( player, result );
    }
      // we might have a scene chain callback instead so check for that too
    else if( auto chainCallback = pEvent->getSceneChainCallback() )
      chainCallback( player );

  }

  player.checkEvent( eventId );

}

void Sapphire::Network::GameConnection::eventHandlerLinkshell( const Packets::FFXIVARR_PACKET_RAW& inPacket,
                                                           Entity::Player& player )
{
  const auto packet = ZoneChannelPacket< Client::FFXIVIpcLinkshellEventHandler >( inPacket );

  auto linkshellEvent = makeZonePacket< Server::FFXIVIpcEventLinkshell >( player.getId() );
  linkshellEvent->data().eventId = packet.data().eventId;
  linkshellEvent->data().scene = static_cast< uint8_t >( packet.data().scene );
  linkshellEvent->data().param3 = 1;
  linkshellEvent->data().unknown1 = 0x15a;
  player.queuePacket( linkshellEvent );

}

void Sapphire::Network::GameConnection::eventHandlerShop( const Packets::FFXIVARR_PACKET_RAW& inPacket,
                                                         Entity::Player& player )
{
  const auto packet = ZoneChannelPacket< Client::FFXIVIpcShopEventHandler >( inPacket );

  auto pLog = g_fw.get< Logger >();
  auto pScriptMgr = g_fw.get< Scripting::ScriptMgr >();
  auto pExdData = g_fw.get< Data::ExdDataGenerated >();

  const auto eventId = packet.data().eventId;

  auto eventType = static_cast< uint16_t >( eventId >> 16 );

  std::string eventName = "onOpen";
  std::string objName = Event::getEventName( eventId );

  player.sendDebug( "EventId: " +
                    std::to_string( eventId ) +
                    " (0x" + Util::intToHexString( static_cast< uint64_t >( eventId & 0xFFFFFFF ), 8 ) + ")" );

  player.sendDebug( "Calling: " + objName + "." + eventName );
  player.eventStart( player.getId(), eventId, Event::EventHandler::UI, 0, packet.data().param );

  pScriptMgr->onTalk( player, player.getId(), eventId );
}



