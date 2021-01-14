#include <Common.h>
#include <Network/CommonNetwork.h>
#include <Network/GamePacket.h>
#include <Logging/Logger.h>
#include <Network/PacketContainer.h>
#include <Network/CommonActorControl.h>
#include <Network/PacketDef/Zone/ClientZoneDef.h>
#include <Exd/ExdDataGenerated.h>

#include <unordered_map>
#include <Service.h>

#include "Network/GameConnection.h"

#include "Session.h"

#include "Manager/TerritoryMgr.h"
#include "Territory/Territory.h"
#include "Territory/InstanceContent.h"

#include "Network/PacketWrappers/PlayerSetupPacket.h"
#include "Network/PacketWrappers/PingPacket.h"
#include "Network/PacketWrappers/MoveActorPacket.h"
#include "Network/PacketWrappers/ChatPacket.h"
#include "Network/PacketWrappers/ServerNoticePacket.h"
#include "Network/PacketWrappers/ActorControlPacket.h"
#include "Network/PacketWrappers/ActorControlSelfPacket.h"
#include "Network/PacketWrappers/ActorControlTargetPacket.h"
#include "Network/PacketWrappers/EventStartPacket.h"
#include "Network/PacketWrappers/EventFinishPacket.h"
#include "Network/PacketWrappers/PlayerStateFlagsPacket.h"

#include "ServerMgr.h"

using namespace Sapphire::Common;
using namespace Sapphire::Network::Packets;
using namespace Sapphire::Network::Packets::Server;
using namespace Sapphire::Network::ActorControl;
using namespace Sapphire::World::Manager;

enum GmCommand
{
  Pos = 0x0000,
  Lv = 0x0001,
  Race = 0x0002,
  Tribe = 0x0003,
  Sex = 0x0004,
  Time = 0x0005,
  Weather = 0x0006,
  Call = 0x0007,
  Inspect = 0x0008,
  Speed = 0x0009,
  Invis = 0x000D,

  Raise = 0x0010,
  Kill = 0x000E,
  Icon = 0x0012,

  Hp = 0x0064,
  Mp = 0x0065,
  Tp = 0x0066,
  Gp = 0x0067,
  Exp = 0x0068,
  Inv = 0x006A,

  Orchestrion = 0x0074,

  Item = 0x00C8,
  Gil = 0x00C9,
  Collect = 0x00CA,
  ItemList = 0x00CB,

  QuestAccept = 0x012C,
  QuestCancel = 0x012D,
  QuestComplete = 0x012E,
  QuestIncomplete = 0x012F,
  QuestSequence = 0x0130,
  QuestInspect = 0x0131,
  GC = 0x0154,
  GCRank = 0x0155,
  Aetheryte = 0x015E,
  Wireframe = 0x0226,
  Teri = 0x0258,
  Kick = 0x025C,
  TeriInfo = 0x025D,
  Jump = 0x025E,
  JumpNpc = 0x025F,
  Jail = 0x025A,
  Unjail = 0x025B,
  SafetyPoint = 0x0274,
  Eureka_Step = 0x09C4,
};

void Sapphire::Network::GameConnection::gm1Handler( const Packets::FFXIVARR_PACKET_RAW& inPacket,
                                                    Entity::Player& player )
{
  if( player.getGmRank() <= 0 )
    return;

  const auto packet = ZoneChannelPacket< Client::FFXIVIpcGmCommand1 >( inPacket );
  const auto commandId = packet.data().commandId;
  const auto param1 = packet.data().param1;
  const auto param2 = packet.data().param2;
  const auto param3 = packet.data().param3;
  const auto param4 = packet.data().param4;
  const auto target = packet.data().target;
  auto& exdData = Common::Service< Data::ExdDataGenerated >::ref();

  Logger::info( "{0} used GM1 commandId: {1}, params: {2}, {3}, {4}, {5}, target: {6}",
                player.getName(), commandId,
                param1, param2, param3, param4, target );

  Sapphire::Entity::ActorPtr targetActor;


  if( player.getId() == target )
  {
    targetActor = player.getAsPlayer();
  }
  else
  {
    auto inRange = player.getInRangeActors();
    for( auto& actor : inRange )
    {
      if( actor->getId() == target )
        targetActor = actor;
    }
  }

  if( !targetActor )
    return;
  auto targetPlayer = targetActor->getAsPlayer();

  switch( commandId )
  {
    case GmCommand::Lv:
    {
      targetPlayer->setLevel( static_cast< uint8_t >( param1 ) );
      player.sendNotice( 0, "Level for {0} was set to {1}", targetPlayer->getName(), param1 );
      break;
    }
    case GmCommand::Race:
    {
      targetPlayer->setLookAt( CharaLook::Race, static_cast< uint8_t >( param1 ) );
      player.sendNotice( 0, "Race for {0} was set to {1}", targetPlayer->getName(), param1 );
      targetPlayer->spawn( targetPlayer );
      auto inRange = targetPlayer->getInRangeActors();
      for( auto actor : inRange )
      {
        if( actor->isPlayer() )
        {
          targetPlayer->despawn( actor->getAsPlayer() );
          targetPlayer->spawn( actor->getAsPlayer() );
        }
      }
      break;
    }
    case GmCommand::Tribe:
    {
      targetPlayer->setLookAt( CharaLook::Tribe, static_cast< uint8_t >( param1 ) );
      player.sendNotice( 0, "Tribe for {0} was set to {1}", targetPlayer->getName(), param1 );
      targetPlayer->spawn( targetPlayer );
      auto inRange = targetPlayer->getInRangeActors();
      for( auto actor : inRange )
      {
        if( actor->isPlayer() )
        {
          targetPlayer->despawn( actor->getAsPlayer() );
          targetPlayer->spawn( actor->getAsPlayer() );
        }
      }
      break;
    }
    case GmCommand::Sex:
    {
      targetPlayer->setLookAt( CharaLook::Gender, static_cast< uint8_t >( param1 ) );
      player.sendNotice( 0, "Sex for {0} was set to {1}", targetPlayer->getName(), param1 );
      targetPlayer->spawn( targetPlayer );
      auto inRange = targetActor->getInRangeActors();
      for( auto actor : inRange )
      {
        if( actor->isPlayer() )
        {
          targetPlayer->despawn( actor->getAsPlayer() );
          targetPlayer->spawn( actor->getAsPlayer() );
        }
      }
      break;
    }
    case GmCommand::Time:
    {
      auto inRange = player.getInRangeActors( true );
      for( auto actor : inRange )
      {
        if( actor->isPlayer() )
        {
          actor->getAsPlayer()->setEorzeaTimeOffset( param2 );
        }
    }
      player.sendNotice( 0, "Eorzea time offset: {0}", param2 );
      break;
    }
    case GmCommand::Weather:
    {
      targetPlayer->getCurrentTerritory()->setWeatherOverride( static_cast< Common::Weather >( param1 ) );
      player.sendNotice( 0, "Weather in Territory \"{0}\" of {1} set in range.",
                         targetPlayer->getCurrentTerritory()->getName(), targetPlayer->getName() );
      break;
    }
    case GmCommand::Call:
    {
      if( targetPlayer->getZoneId() != player.getZoneId() )
        targetPlayer->setZone( player.getZoneId() );

      targetPlayer->changePosition( player.getPos().x, player.getPos().y, player.getPos().z, player.getRot() );
      player.sendNotice( 0, "Calling {0}", targetPlayer->getName() );
      break;
    }
    case GmCommand::Speed:
    {
      targetPlayer->queuePacket( makeActorControlSelf( player.getId(), Flee, param1 ) );
      player.sendNotice( 0, "Speed for {0} was set to {1}", targetPlayer->getName(), param1 );
      break;
    }
    case GmCommand::Invis:
    {
      player.setGmInvis( !player.getGmInvis() );
      player.sendNotice( 0, "Invisibility flag for {0} was toggled to {1}", player.getName(), player.getGmInvis() );

      for( auto actor : player.getInRangeActors() )
      {
        if( actor->isPlayer() )
        {
          targetPlayer->despawn( actor->getAsPlayer() );
          targetPlayer->spawn( actor->getAsPlayer() );
        }
      }
      break;
    }
    case GmCommand::Kill:
    {
      targetActor->getAsChara()->takeDamage( 9999999 );
      player.sendNotice( 0, "Killed {0}", targetActor->getId() );
      break;
    }
    case GmCommand::Icon:
    {
      targetPlayer->setOnlineStatusMask( param1 );

      auto searchInfoPacket = makeZonePacket< FFXIVIpcSetSearchInfo >( player.getId() );
      searchInfoPacket->data().onlineStatusFlags = param1;
      searchInfoPacket->data().selectRegion = targetPlayer->getSearchSelectRegion();
      strcpy( searchInfoPacket->data().searchMessage, targetPlayer->getSearchMessage() );
      targetPlayer->queuePacket( searchInfoPacket );

      player.sendNotice( 0, "Icon for {0} was set to {1}", targetPlayer->getName(), param1 );
      break;
    }
    case GmCommand::Hp:
    {
      auto chara = targetActor->getAsChara();
      if( chara )
      {
        chara->setHp( param1 );
        player.sendNotice( 0, "Hp for {0} was set to {1}", chara->getName(), param1 );
      }

      break;
    }
    case GmCommand::Mp:
    {
      targetPlayer->setMp( param1 );
      player.sendNotice( 0, "Mp for {0} was set to {1}", targetPlayer->getName(), param1 );
      break;
    }
    case GmCommand::Gp:
    {
      targetPlayer->setHp( param1 );
      player.sendNotice( 0, "Gp for {0} was set to {1}", targetPlayer->getName(), param1 );
      break;
    }
    case GmCommand::Exp:
    {
      targetPlayer->gainExp( param1 );
      player.sendNotice( 0, "{0} Exp was added to {1}", param1, targetPlayer->getName() );
      break;
    }
    case GmCommand::Inv:
    {
      if( targetActor->getAsChara()->getInvincibilityType() == Common::InvincibilityType::InvincibilityRefill )
        targetActor->getAsChara()->setInvincibilityType( Common::InvincibilityType::InvincibilityNone );
      else
        targetActor->getAsChara()->setInvincibilityType( Common::InvincibilityType::InvincibilityRefill );

      player.sendNotice( 0, "Invincibility for {0} was switched.", targetPlayer->getName() );
      break;
    }
    case GmCommand::Orchestrion:
    {
      if( param1 == 1 )
      {
        if( param2 == 0 )
        {
          for( uint8_t i = 0; i < 255; i++ )
            targetActor->getAsPlayer()->learnSong( i, 0 );

          player.sendNotice( 0, "All Songs for {0} were turned on.", targetPlayer->getName() );
        }
        else
        {
          targetActor->getAsPlayer()->learnSong( static_cast< uint8_t >( param2 ), 0 );
          player.sendNotice( 0, "Song {0} for {1} was turned on.", param2, targetPlayer->getName() );
        }
      }

      break;
    }
    case GmCommand::Item:
    {
      auto quantity = param2;

      if( quantity < 1 || quantity > 999 )
      {
        quantity = 1;
      }

      if ( !exdData.get< Sapphire::Data::Item > ( param1 ) )
    {
      player.sendUrgent ( "{0} is not a valid item ID.", param1 );
      return;
    }

      if( ( param1 == 0xcccccccc ) )
      {
        player.sendUrgent( "Syntaxerror." );
        return;
      }
      if( param1 <= 0x12 ) // crystal
      {
        targetPlayer->addCrystal( static_cast< Common::CrystalType >( param1 ), quantity, true );
      }
      else // item
      {
        // decode using the epic SE style HQ item id
        bool isHq = param1 > 1000000;

        if( !targetPlayer->addItem( isHq ? param1 - 1000000 : param1, quantity, isHq, false, true, true ) )
          player.sendUrgent( "Item #{0} could not be added to inventory.", isHq ? param1 - 1000000 : param1 );
      }
      break;
    }
    case GmCommand::Gil:
    {
      targetPlayer->addCurrency( CurrencyType::Gil, param1, true );
      player.sendNotice( 0, "Added {0} Gil for {1}", param1, targetPlayer->getName() );
      break;
    }
    case GmCommand::Collect:
    {
      uint32_t gil = targetPlayer->getCurrency( CurrencyType::Gil );

      if( gil < param1 )
      {
        player.sendUrgent( "Player does not have enough Gil({0})", gil );
      }
      else
      {
        targetPlayer->removeCurrency( CurrencyType::Gil, param1 );
        player.sendNotice( 0, "Removed {0} Gil from {1} ({2} before)", param1, targetPlayer->getName(), gil );
      }
      break;
    }
    case GmCommand::QuestAccept:
    {
      targetPlayer->updateQuest( static_cast< uint16_t >( param1 ), 1 );
      break;
    }
    case GmCommand::QuestCancel:
    {
      targetPlayer->removeQuest( static_cast< uint16_t >( param1 ) );
      break;
    }
    case GmCommand::QuestComplete:
    {
      targetPlayer->finishQuest( static_cast< uint16_t >( param1 ) );
      break;
    }
    case GmCommand::QuestIncomplete:
    {
      targetPlayer->unfinishQuest( static_cast< uint16_t >( param1 ) );
      break;
    }
    case GmCommand::QuestSequence:
    {
      targetPlayer->updateQuest( static_cast< uint16_t >( param1 ), static_cast< uint8_t >( param2 ) );
      break;
    }
    case GmCommand::GC:
    {
      if( param1 > 3 )
      {
        player.sendUrgent( "Invalid Grand Company ID: {0}", param1 );
        return;
      }

      targetPlayer->setGc( static_cast< uint8_t >( param1 ) );

      // if we're changing them to a GC, check if they have a rank and if not, set it to the lowest rank
      if( param1 > 0 )
      {
        auto gcRankIdx = static_cast< uint8_t >( param1 ) - 1;
        if( targetPlayer->getGcRankArray()[ gcRankIdx ] == 0 )
        {
          player.setGcRankAt( static_cast< uint8_t >( gcRankIdx ), 1 );
        }
      }

      player.sendNotice( 0, "GC for {0} was set to {1}", targetPlayer->getName(), targetPlayer->getGc() );
      break;
    }
    case GmCommand::GCRank:
    {
      auto gcId = targetPlayer->getGc() - 1;

      if( gcId > 2 )
      {
        player.sendUrgent( "{0} has an invalid Grand Company ID: {0}", targetPlayer->getName(), gcId );
        return;
      }

      targetPlayer->setGcRankAt( static_cast< uint8_t >( gcId ), static_cast< uint8_t >( param1 ) );
      player.sendNotice( 0, "GC Rank for {0} for GC {1} was set to {2}", targetPlayer->getName(), targetPlayer->getGc(),
                         targetPlayer->getGcRankArray()[ targetPlayer->getGc() - 1 ] );
      break;
    }
    case GmCommand::Aetheryte:
    {
      if( param1 == 0 )
      {
        if( param2 == 0 )
        {
          for( uint8_t i = 0; i < 255; i++ )
            targetActor->getAsPlayer()->registerAetheryte( i );

          player.sendNotice( 0, "All Aetherytes for {0} were turned on.", targetPlayer->getName() );
        }
        else
        {
          targetActor->getAsPlayer()->registerAetheryte( static_cast< uint8_t >( param2 ) );
          player.sendNotice( 0, "Aetheryte {0} for {1} was turned on.", param2, targetPlayer->getName() );
        }
      }

      break;
    }
    case GmCommand::Wireframe:
    {
      player.queuePacket(
        std::make_shared< ActorControlSelfPacket >( player.getId(), ActorControlType::ToggleWireframeRendering ) );
      player.sendNotice( 0, "Wireframe Rendering for {0} was toggled", player.getName() );
      break;
    }
    case GmCommand::Teri:
    {
      auto& teriMgr = Common::Service< TerritoryMgr >::ref();
      if( auto instance = teriMgr.getTerritoryByGuId( param1 ) )
      {
        player.sendDebug( "Found instance: {0}, id#{1}", instance->getName(), param1 );

        // if the zone is an instanceContent instance, make sure the player is actually bound to it
        auto pInstance = instance->getAsInstanceContent();

        // pInstance will be nullptr if you're accessing a normal zone via its allocated instance id rather than its zoneid
        if( pInstance && !pInstance->isPlayerBound( player.getId() ) )
        {
          player.sendDebug( "Binding to instance..." );
          pInstance->bindPlayer( targetPlayer->getId() );
          // player.sendUrgent( "Not able to join instance#{0}", param1 );
          // player.sendUrgent( "Player not bound! ( run !instance bind <instanceId> first ) {0}", param1 );
          // break;
        }

        player.setInstance( instance );
      }
      else if( !teriMgr.isValidTerritory( param1 ) )
      {
        player.sendUrgent( "Invalid zone {0}", param1 );
      }
      else
      {
        auto pZone = teriMgr.getZoneByTerritoryTypeId( param1 );
        if( !pZone )
        {
          player.sendUrgent( "No zone instance found for {0}", param1 );
          break;
        }

        if( !teriMgr.isDefaultTerritory( param1 ) )
        {
          player.sendUrgent( "{0} is an instanced area - instance ID required to zone in.", pZone->getName() );
          break;
        }

        bool doTeleport = false;
        uint16_t teleport;

        auto& exdData = Common::Service< Data::ExdDataGenerated >::ref();
        auto idList = exdData.getAetheryteIdList();

        for( auto i : idList )
        {
          auto data = exdData.get< Sapphire::Data::Aetheryte >( i );

          if( !data )
          {
            continue;
          }

          if( data->territory == param1 )
          {
            if( data->isAetheryte )
            {
              doTeleport = true;
              teleport = static_cast< uint16_t >( i );
              break;
            }
          }
        }
        if( doTeleport )
        {
          targetPlayer->teleport( teleport );
        }
        else
        {
          targetPlayer->setPos( targetPlayer->getPos() );
          targetPlayer->performZoning( static_cast< uint16_t >( param1 ), targetPlayer->getPos(), 0 );
        }

        player.sendNotice( 0, "{0} was warped to zone {1}", targetPlayer->getName(), param1, pZone->getName() );
      }
      break;
    }
    case GmCommand::Kick:
    {
      // todo: this doesn't kill their session straight away, should do this properly but its good for when you get stuck for now
      targetPlayer->setMarkedForRemoval();

      player.sendNotice( 0, "Kicked {0}", targetPlayer->getName() );

      break;
    }
    case GmCommand::TeriInfo:
    {
      auto pCurrentZone = player.getCurrentTerritory();
      auto& exdData = Common::Service< Data::ExdDataGenerated >::ref();
      player.sendNotice( 0, "ZoneId: {0}"
                         "\nName: {1}"
                         "\nInternalName: {2}"
                         "\nGuId: {3}"
                         "\nPopCount: {4}"
                         "\nCurrentWeather: {5} (ID: {6})"
                         "\nNextWeather: {7} (ID: {8})"
                         "\nFestival: {9} (ID: {10})"
                         "\nAdditionalFestival: {11} (ID: {12})"
                         ,
                         player.getZoneId(),
                         pCurrentZone->getName(),
                         pCurrentZone->getInternalName(),
                         pCurrentZone->getGuId(),
                         pCurrentZone->getPopCount(),
                         exdData.get< Sapphire::Data::Weather >( static_cast< uint8_t >( pCurrentZone->getCurrentWeather() ) )->name,
                         static_cast< uint8_t >( pCurrentZone->getCurrentWeather() ),
                         exdData.get< Sapphire::Data::Weather >( static_cast< uint8_t >( pCurrentZone->getNextWeather() ) )->name,
                         static_cast< uint8_t >( pCurrentZone->getNextWeather() ),
                         exdData.get< Sapphire::Data::Festival >( player.getCurrentTerritory()->getCurrentFestival().first )->name,
                         pCurrentZone->getCurrentFestival().first,
                         exdData.get< Sapphire::Data::Festival >( player.getCurrentTerritory()->getCurrentFestival().second )->name,
                         pCurrentZone->getCurrentFestival().second );
      break;
    }
    case GmCommand::Jump:
    {

      auto inRange = player.getInRangeActors();

      player.changePosition( targetActor->getPos().x, targetActor->getPos().y, targetActor->getPos().z,
                             targetActor->getRot() );

      player.sendNotice( 0, "Jumping to {0} in range.", targetPlayer->getName() );
      break;
    }

    case GmCommand::Unjail:
    {
      targetPlayer->returnToHomepoint();
      break;
    }

    case GmCommand::Eureka_Step:
    {
    targetPlayer->sendToInRangeSet( makeActorControlSelf( player.getId(), EurekaStep, param1, 0x3C, 0xFFFFE3, 0, 0 ), true );
    player.sendNotice( 0, "Eureka progress of {0} is set to {1}.", targetPlayer->getName(), param1 );
    break;
    }

    default:
      player.sendUrgent( "GM1 Command not implemented: {0}", commandId );
      break;
  }

}

void Sapphire::Network::GameConnection::gm2Handler( const Packets::FFXIVARR_PACKET_RAW& inPacket,
                                                    Entity::Player& player )
{
  if( player.getGmRank() <= 0 )
    return;

  auto& serverMgr = Common::Service< World::ServerMgr >::ref();

  const auto packet = ZoneChannelPacket< Client::FFXIVIpcGmCommand2 >( inPacket );

  const auto commandId = packet.data().commandId;
  const auto param1 = packet.data().param1;
  const auto param2 = packet.data().param2;
  const auto param3 = packet.data().param3;
  const auto param4 = packet.data().param4;
  const auto target = std::string( packet.data().target );

  Logger::info( "{0} used GM2 commandId: {1}, params: {2}, {3}, {4}, {5}, target: {6}",
                 player.getName(), commandId, param1, param2, param3, param4, target );

  auto targetSession = serverMgr.getSession( target );
  Sapphire::Entity::CharaPtr targetActor;

  if( targetSession != nullptr )
  {
    targetActor = targetSession->getPlayer();
  }
  else
  {
    if( target == "self" )
    {
      targetActor = player.getAsPlayer();
    }
    else
    {
      player.sendUrgent( "Player {0} not found on this server.", target );
      return;
    }
  }

  if( !targetActor )
    return;

  auto targetPlayer = targetActor->getAsPlayer();

  switch( commandId )
  {
    case GmCommand::Raise:
    {
      targetPlayer->resetHp();
      targetPlayer->resetMp();
      targetPlayer->setStatus( Common::ActorStatus::Idle );
      targetPlayer->sendZoneInPackets( 0x01, 0x01, 0, 113, true );


      //targetPlayer->sendToInRangeSet( makeActorControlSelf( player.getId(), ZoneIn, 0x01, 0x01, 0, 113 ), true );
      targetPlayer->sendToInRangeSet( makeActorControl( player.getId(), SetStatus,
                                                        static_cast< uint8_t >( Common::ActorStatus::Idle ) ),
                                      true );
      player.sendNotice( 0, "Raised {0}", targetPlayer->getName() );
      break;
    }
    case GmCommand::Jump:
    {
      player.prepareZoning( targetPlayer->getZoneId(), true, 1, 0 );
      if( player.getCurrentInstance() )
      {
        player.exitInstance();
      }
      if( targetPlayer->getCurrentTerritory()->getGuId() != player.getCurrentTerritory()->getGuId() )
      {
        // Checks if the target player is in an InstanceContent to avoid binding to a Territory or PublicContent
        if( targetPlayer->getCurrentInstance() )
        {
          auto pInstanceContent = targetPlayer->getCurrentInstance()->getAsInstanceContent();
          // Not sure if GMs actually get bound to an instance they jump to on retail. It's mostly here to avoid a crash for now
          pInstanceContent->bindPlayer( player.getId() );
        }
        player.setInstance( targetPlayer->getCurrentTerritory()->getGuId() );
      }
      player.changePosition( targetActor->getPos().x, targetActor->getPos().y, targetActor->getPos().z,
                             targetActor->getRot() );
      player.sendZoneInPackets( 0x00, 0x00, 0, 0, false );
      player.sendNotice( 0, "Jumping to {0}", targetPlayer->getName() );
      break;
    }
    case GmCommand::Call:
    {
      targetPlayer->prepareZoning( player.getZoneId(), true, 1, 0 );
      if( targetPlayer->getCurrentInstance() )
      {
        targetPlayer->exitInstance();
      }
      if( targetPlayer->getCurrentTerritory()->getGuId() != player.getCurrentTerritory()->getGuId() )
      {
        // Checks if the player is in an InstanceContent to avoid binding to a Zone or PublicContent
        if( player.getCurrentInstance() )
        {
          auto pInstanceContent = player.getCurrentInstance()->getAsInstanceContent();
          // Not sure if GMs actually get bound to an instance they jump to on retail. It's mostly here to avoid a crash for now
          pInstanceContent->bindPlayer( targetPlayer->getId() );
        }
        targetPlayer->setInstance( player.getCurrentTerritory()->getGuId() );
      }
      targetPlayer->changePosition( player.getPos().x, player.getPos().y, player.getPos().z, player.getRot() );
      targetPlayer->sendZoneInPackets( 0x00, 0x00, 0, 0, false );
      player.sendNotice( 0, "Calling {0}", targetPlayer->getName() );
      break;
    }
    case GmCommand::Inspect:
    {
      auto& exdData = Common::Service< Data::ExdDataGenerated >::ref();
      player.sendNotice( 0, "\nName: {0} (ID: {1})"
                         "\nHomeWorld: Memiroa" // ToDo: Get correct name automagically
                         "\nHP: {2}/{3}, MP: {4}/{5}, TP: {6}/1000"
                         "\nClass: {7} (ID: {8})"
                         "\nLevel: {9}"
                         "\nExp: {10}"
                         "\nGC: {11} (ID: {12})"
                         "\nGil: {13}"
                         "\n"
                         "\nCurrentWorld: Memiroa" // ToDo: Get correct name automagically
                         "\nZone: {14} (ID: {15})"
                         "\nGuId: {16}"
                         "\nPos: \nX: {17} \nY: {18} \nZ: {19} \nR: {20}"
                         "\n"
                         "\nGMRank: {21}"
                         "\nisActingAsGM: {22}"
                         "\nInvisibilityFlag: {23}"
                         "\n"
                         "\nSearchMessage: {24}"
                         "\nPlayTime: {25}"
                         "\nModelChara: {26}"
                         "\nCurrentMount: {27} (ID: {28})"
                         "\nCurrentCompanion: {29} (ID: {30})"
                         "\n"
                         "\nTarget: {31}",
                         // "\nRPMode: {32}"
                         // "\nisActingAsEnemy: {33}"
                         // "\nbNPCBase: {34}"
                         // "\nbNPCName: {35} (ID: {36})"
                         // "\nEnemyType: {35} (Subtype: {36})",
                         targetPlayer->getName(), targetPlayer->getId(),
                         targetPlayer->getHp(), targetPlayer->getMaxHp(), targetPlayer->getMp(), targetPlayer->getMaxMp(), targetPlayer->getTp(),
                         exdData.get< Sapphire::Data::ClassJob >( static_cast< uint8_t >( targetPlayer->getClass() ))->name, static_cast< uint8_t >( targetPlayer->getClass() ),
                         targetPlayer->getLevel(),
                         targetPlayer->getExp(),
                         exdData.get< Sapphire::Data::GrandCompany >( targetPlayer->getGc() )->name, targetPlayer->getGc(),
                         targetPlayer->getCurrency( CurrencyType::Gil ),
                         targetPlayer->getCurrentTerritory()->getName(), targetPlayer->getZoneId(),
                         targetPlayer->getCurrentTerritory()->getGuId(),
                         targetPlayer->getPos().x, targetPlayer->getPos().y, targetPlayer->getPos().z, targetPlayer->getRot(),
                         targetPlayer->getGmRank(),
                         targetPlayer->isActingAsGm(),
                         targetPlayer->getGmInvis(),
                         targetPlayer->getSearchMessage(),
                         targetPlayer->getPlayTime(),
                         targetPlayer->getModelChara(),
                         exdData.get< Sapphire::Data::Mount >( targetPlayer->getCurrentMount() )->singular, targetPlayer->getCurrentMount(),
                         exdData.get< Sapphire::Data::Companion >( static_cast< uint8_t >( targetPlayer->getCurrentCompanion() ))->singular, static_cast< uint8_t >( targetPlayer->getCurrentCompanion() ),
                         targetPlayer->getTargetId() );
                         // targetPlayer->getRPMode(),
                         // targetPlayer->isActingAsEnemy(),
                         // targetPlayer->getbNPCBase(),
                         // exdData.get< Sapphire::Data::BNpcName >( targetPlayer->getbNPCName() )->singular, targetPlayer->getbNPCName(),
                         // targetPlayer->getEnemyType(), targetPlayer->getSubType() );
      break;
    }

    case GmCommand::Jail:
    {
      targetPlayer->prepareZoning( 176, true, 1, 0 );
      if( targetPlayer->getCurrentInstance() )
      {
        targetPlayer->exitInstance();
      }
      targetPlayer->setZone( 176 );
      targetPlayer->changePosition( 0, 0, 0, 0 );
      targetPlayer->sendZoneInPackets( 0x00, 0x00, 0, 0, false );
      player.sendNotice( 0, "Jailed {0}.", targetPlayer->getName() );
      break;
    }

    case GmCommand::SafetyPoint:
    {
      targetPlayer->sendToInRangeSet( makeActorControlSelf( player.getId(), ZoneIn, 0x01, 0x01, 0, 113 ), true );
      targetPlayer->returnToHomepoint();
    }

  }
}
