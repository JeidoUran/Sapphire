
#include <Common.h>
#include <Logging/Logger.h>
#include <Util/Util.h>
#include <Util/UtilMath.h>
#include <Exd/ExdDataGenerated.h>
#include <Network/CommonActorControl.h>

#include "Event/Director.h"
#include "Event/EventDefs.h"
#include "Script/ScriptMgr.h"

#include "Actor/Player.h"
#include "Actor/EventObject.h"

#include "Network/PacketWrappers/ActorControlPacket142.h"
#include "Network/PacketWrappers/ActorControlPacket143.h"


#include "Event/EventHandler.h"

#include "PublicContent.h"
#include "Framework.h"

using namespace Sapphire::Common;
using namespace Sapphire::Network::Packets;
using namespace Sapphire::Network::Packets::Server;
using namespace Sapphire::Network::ActorControl;

Sapphire::PublicContent::PublicContent( std::shared_ptr< Sapphire::Data::PublicContent > pZoneConfiguration,
                                            uint16_t territoryType,
                                            uint32_t guId,
                                            const std::string& internalName,
                                            const std::string& contentName,
                                            uint32_t publicContentId,
                                            FrameworkPtr pFw ) :
  Zone( static_cast< uint16_t >( territoryType ), guId, internalName, contentName, pFw ),
  Director( Event::Director::PublicContent, publicContentId ),
  m_zoneConfiguration( pZoneConfiguration ),
  m_publicContentId( publicContentId ),
  m_state( Created ),
  m_instanceCommenceTime( 0 )
  // m_currentBgm( pZoneConfiguration->bGM )
{

}

bool Sapphire::PublicContent::init()
{
  auto pScriptMgr = m_pFw->get< Scripting::ScriptMgr >();
  pScriptMgr->onInstanceInit( getAsPublicContent() );

  return true;
}


Sapphire::PublicContent::~PublicContent()
{

}

uint32_t Sapphire::PublicContent::getPublicContentId() const
{
  return m_publicContentId;
}

Sapphire::Data::ExdDataGenerated::PublicContentPtr Sapphire::PublicContent::getZoneConfiguration() const
{
  return m_zoneConfiguration;
}

void Sapphire::PublicContent::onPlayerZoneIn( Entity::Player& player )
{
  Logger::debug( "PublicContent::onPlayerZoneIn: Zone#{0}|{1}, Entity#{2}",
                 getGuId(), getTerritoryTypeId(), player.getId() );

  // mark player as "bound by duty"
  player.setStateFlag( PlayerStateFlag::BoundByDuty );

  // if the instance was not started yet, director init is sent on enter event.
  // else it will be sent on finish loading.
  if( m_state == Created )
    sendDirectorInit( player );

}

void Sapphire::PublicContent::onLeaveTerritory( Entity::Player& player )
{
  Logger::debug( "PublicContent::onLeaveTerritory: Zone#{0}|{1}, Entity#{2}",
                 getGuId(), getTerritoryTypeId(), player.getId() );

  clearDirector( player );
}

void Sapphire::PublicContent::onUpdate( uint32_t currTime )
{
  switch( m_state )
  {
    case Created:
    {
      if( m_boundPlayerIds.size() == 0 )
        return;

      for( auto playerId : m_boundPlayerIds )
      {
        auto it = m_playerMap.find( playerId );
        if( it == m_playerMap.end() )
          return;

        auto player = it->second;
        if( !player->isLoadingComplete() ||
            !player->isDirectorInitialized() ||
            !player->isOnEnterEventDone() ||
            player->hasStateFlag( PlayerStateFlag::WatchingCutscene ) )
          return;
      }

      if( m_instanceCommenceTime == 0 )
      {
        m_instanceCommenceTime = Util::getTimeMs() + instanceStartDelay;
        return;
      }
      else if( Util::getTimeMs() < m_instanceCommenceTime )
        return;

      for( const auto& playerIt : m_playerMap )
      {
        auto pPlayer = playerIt.second;
        pPlayer->queuePacket( makeActorControl143( pPlayer->getId(), DirectorUpdate,
                                                   getDirectorId(), 0x40000001,
                                                   m_zoneConfiguration->timeLimitmin * 60u ) );
      }

      if( m_pEntranceEObj )
        m_pEntranceEObj->setState( 7 );
      m_state = DutyInProgress;
      m_instanceExpireTime = Util::getTimeSeconds() + ( m_zoneConfiguration->timeLimitmin * 60u );
      break;
    }


    case DutyReset:
      break;

    case DutyInProgress:
    {
      break;
    }


    case DutyFinished:
      break;
  }

  auto pScriptMgr = m_pFw->get< Scripting::ScriptMgr >();
  pScriptMgr->onInstanceUpdate( getAsPublicContent(), currTime );
}

void Sapphire::PublicContent::onFinishLoading( Entity::Player& player )
{
  sendDirectorInit( player );
}

void Sapphire::PublicContent::onInitDirector( Entity::Player& player )
{
  sendDirectorVars( player );
  player.setDirectorInitialized( true );
}

void Sapphire::PublicContent::onDirectorSync( Entity::Player& player )
{
  player.queuePacket( makeActorControl143( player.getId(), DirectorUpdate, 0x00110001, 0x80000000, 1 ) );
}


void Sapphire::PublicContent::setVar( uint8_t index, uint8_t value )
{
  if( index > 19 )
    return;

  switch( index )
  {
    case 0:
      setDirectorUI8AL( value );
      break;
    case 1:
      setDirectorUI8AH( value );
      break;
    case 2:
      setDirectorUI8BL( value );
      break;
    case 3:
      setDirectorUI8BH( value );
      break;
    case 4:
      setDirectorUI8CL( value );
      break;
    case 5:
      setDirectorUI8CH( value );
      break;
    case 6:
      setDirectorUI8DL( value );
      break;
    case 7:
      setDirectorUI8DH( value );
      break;
    case 8:
      setDirectorUI8EL( value );
      break;
    case 9:
      setDirectorUI8EH( value );
      break;
    case 10:
      setDirectorUI8FL( value );
      break;
    case 11:
      setDirectorUI8FH( value );
      break;
    case 12:
      setDirectorUI8GL( value );
      break;
    case 13:
      setDirectorUI8GH( value );
      break;
    case 14:
      setDirectorUI8HL( value );
      break;
    case 15:
      setDirectorUI8HH( value );
      break;
    case 16:
      setDirectorUI8IL( value );
      break;
    case 17:
      setDirectorUI8IH( value );
      break;
    case 18:
      setDirectorUI8JL( value );
      break;
    case 19:
      setDirectorUI8JH( value );
      break;

  }

  // todo: genericise this?
  for( const auto& playerIt : m_playerMap )
  {
    sendDirectorVars( *playerIt.second );
  }
}

void Sapphire::PublicContent::setSequence( uint8_t value )
{
  setDirectorSequence( value );

  for( const auto& playerIt : m_playerMap )
  {
    sendDirectorVars( *playerIt.second );
  }
}

void Sapphire::PublicContent::setBranch( uint8_t value )
{
  setDirectorBranch( value );

  for( const auto& playerIt : m_playerMap )
  {
    sendDirectorVars( *playerIt.second );
  }
}

void Sapphire::PublicContent::startQte()
{
  for( const auto& playerIt : m_playerMap )
  {
    auto player = playerIt.second;
    player->queuePacket( makeActorControl143( player->getId(), DirectorUpdate, getDirectorId(), 0x8000000A ) );
  }
}

void Sapphire::PublicContent::startEventCutscene()
{
  // TODO: lock player movement
  for( const auto& playerIt : m_playerMap )
  {
    auto player = playerIt.second;
    player->queuePacket( makeActorControl143( player->getId(), DirectorUpdate, getDirectorId(), 0x80000008 ) );
  }
}

void Sapphire::PublicContent::endEventCutscene()
{
  for( const auto& playerIt : m_playerMap )
  {
    auto player = playerIt.second;
    player->queuePacket( makeActorControl143( player->getId(), DirectorUpdate, getDirectorId(), 0x80000009 ) );
  }
}

void Sapphire::PublicContent::onRegisterEObj( Entity::EventObjectPtr object )
{
  if( object->getName() != "none" )
    m_eventObjectMap[ object->getName() ] = object;
  if( object->getObjectId() == 2000182 ) // start
    m_pEntranceEObj = object;

  auto pExdData = m_pFw->get< Data::ExdDataGenerated >();
  auto objData = pExdData->get< Sapphire::Data::EObj >( object->getObjectId() );
  if( objData )
    // todo: data should be renamed to eventId
    m_eventIdToObjectMap[ objData->data ] = object;
  else
    Logger::error( "PublicContent::onRegisterEObj Zone " +
                   m_internalName + ": No EObj data found for EObj with ID: " +
                   std::to_string( object->getObjectId() ) );
}

bool Sapphire::PublicContent::hasPlayerPreviouslySpawned( Entity::Player& player ) const
{
  auto it = m_spawnedPlayers.find( player.getId() );
  return it != m_spawnedPlayers.end();
}

Sapphire::PublicContent::PublicContentState Sapphire::PublicContent::getState() const
{
  return m_state;
}

void Sapphire::PublicContent::onBeforePlayerZoneIn( Sapphire::Entity::Player& player )
{
  // remove any players from the instance who aren't bound on zone in
  if( !isPlayerBound( player.getId() ) )
    player.exitInstance();

  // if a player has already spawned once inside this instance, don't move them if they happen to zone in again
  if( !hasPlayerPreviouslySpawned( player ) )
  {
    if( m_pEntranceEObj != nullptr )
    {
      player.setRot( PI );
      player.setPos( m_pEntranceEObj->getPos() );
    }
    else
    {
      player.setRot( PI );
      player.setPos( { 0.f, 0.f, 0.f } );
    }
  }

  player.resetObjSpawnIndex();
}

Sapphire::Entity::EventObjectPtr Sapphire::PublicContent::getEObjByName( const std::string& name )
{
  auto it = m_eventObjectMap.find( name );
  if( it == m_eventObjectMap.end() )
    return nullptr;

  return it->second;
}

void Sapphire::PublicContent::onTalk( Sapphire::Entity::Player& player, uint32_t eventId, uint64_t actorId )
{
  // todo: handle exit (and maybe shortcut?) behaviour here

  auto it = m_eventIdToObjectMap.find( eventId );
  if( it == m_eventIdToObjectMap.end() )
    return;

  if( auto onTalk = it->second->getOnTalkHandler() )
    onTalk( player, it->second, getAsPublicContent(), actorId );
  else
    player.sendDebug( "No onTalk handler found for interactable eobj with EObjID#{0}, eventId#{1}  ",
                      it->second->getObjectId(), eventId );
}

void
Sapphire::PublicContent::onEnterTerritory( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2 )
{
  auto pScriptMgr = m_pFw->get< Scripting::ScriptMgr >();
  pScriptMgr->onInstanceEnterTerritory( getAsPublicContent(), player, eventId, param1, param2 );

  if( !hasPlayerPreviouslySpawned( player ) && player.getRPMode() == false )
  {
    m_spawnedPlayers.insert( player.getId() );
    player.directorPlayScene( getDirectorId(), 1, NO_DEFAULT_CAMERA | CONDITION_CUTSCENE | SILENT_ENTER_TERRI_ENV |
                                                  HIDE_HOTBAR | SILENT_ENTER_TERRI_BGM | SILENT_ENTER_TERRI_SE |
                                                  DISABLE_STEALTH | 0x00100000 | LOCK_HUD | LOCK_HOTBAR |
                                                  // todo: wtf is 0x00100000
                                                  DISABLE_CANCEL_EMOTE, 0, 0x9, getCurrentBGM() );
  }
  else
    player.directorPlayScene( getDirectorId(), 2, NO_DEFAULT_CAMERA | HIDE_HOTBAR, 0, 0x9, getCurrentBGM() );
}

void Sapphire::PublicContent::clearDirector( Entity::Player& player )
{
  sendDirectorClear( player );

  player.setDirectorInitialized( false );
  // remove "bound by duty" state
  player.unsetStateFlag( PlayerStateFlag::BoundByDuty );
}