#include <cinttypes>

#include <Common.h>
#include <Version.h>
#include <Network/GamePacket.h>
#include <Util/Util.h>
#include <Util/UtilMath.h>
#include <Network/PacketContainer.h>
#include <Network/CommonActorControl.h>
#include <Logging/Logger.h>
#include <Exd/ExdDataGenerated.h>
#include <Database/DatabaseDef.h>
#include <cmath>
#include <random>

#include "DebugCommand/DebugCommand.h"
#include "DebugCommandMgr.h"

#include "Network/PacketWrappers/ServerNoticePacket.h"
#include "Network/PacketWrappers/ActorControlPacket142.h"
#include "Network/PacketWrappers/ActorControlPacket143.h"
#include "Network/PacketWrappers/InitUIPacket.h"
#include "Network/PacketWrappers/ModelEquipPacket.h"
#include "Network/PacketWrappers/PlayerSpawnPacket.h"
#include "Network/PacketWrappers/EffectPacket.h"
#include "Network/GameConnection.h"
#include "Script/ScriptMgr.h"
#include "Script/NativeScriptMgr.h"

#include "Actor/EventObject.h"
#include "Actor/BNpc.h"

#include "Territory/Zone.h"
#include "Territory/HousingZone.h"
#include "Territory/InstanceContent.h"
#include "Territory/QuestBattle.h"
#include "Territory/PublicContent.h"
#include "Manager/TerritoryMgr.h"
#include "Event/EventDefs.h"

#include "ServerMgr.h"

#include "Session.h"
#include "Framework.h"

using namespace Sapphire::Network;
using namespace Sapphire::Network::Packets;
using namespace Sapphire::Network::ActorControl;
using namespace Sapphire::Network::Packets::Server;
using namespace Sapphire::World::Manager;

// instanciate and initialize commands
Sapphire::World::Manager::DebugCommandMgr::DebugCommandMgr( FrameworkPtr pFw ) :
  BaseManager( pFw )
{
  // Push all commands onto the register map ( command name - function - description - required GM level )
  registerCommand( "set", &DebugCommandMgr::set, "Executes SET commands.", 1 );
  registerCommand( "get", &DebugCommandMgr::get, "Executes GET commands.", 1 );
  registerCommand( "add", &DebugCommandMgr::add, "Executes ADD commands.", 1 );
  registerCommand( "inject", &DebugCommandMgr::injectPacket, "Loads and injects a premade packet.", 1 );
  registerCommand( "injectc", &DebugCommandMgr::injectChatPacket, "Loads and injects a premade chat packet.", 1 );
  registerCommand( "replay", &DebugCommandMgr::replay, "Replays a saved capture folder.", 1 );
  registerCommand( "nudge", &DebugCommandMgr::nudge, "Nudges you forward/up/down.", 1 );
  registerCommand( "info", &DebugCommandMgr::serverInfo, "Show server info.", 0 );
  registerCommand( "help", &DebugCommandMgr::help, "Shows registered commands.", 0 );
  registerCommand( "script", &DebugCommandMgr::script, "Server script utilities.", 1 );
  registerCommand( "instance", &DebugCommandMgr::instance, "InstanceContent utilities", 1 );
  registerCommand( "publiccontent", &DebugCommandMgr::publicContent, "PublicContent utilities", 1 );
  registerCommand( "pc", &DebugCommandMgr::publicContent, "PublicContent utilities", 1 );
  registerCommand( "questbattle", &DebugCommandMgr::questBattle, "QuestBattle utilities", 1 );
  registerCommand( "qb", &DebugCommandMgr::questBattle, "QuestBattle utilities", 1 );
  registerCommand( "housing", &DebugCommandMgr::housing, "Housing utilities", 1 );
  registerCommand( "status", &DebugCommandMgr::status, "StatusEffect management.", 1 );
  registerCommand( "random", &DebugCommandMgr::random, "Rolls a random number.", 1 );
  registerCommand( "tell", &DebugCommandMgr::tell, "Allows in-instance private chatting.", 1 );
  registerCommand( "notice", &DebugCommandMgr::notice, "Allows the sending of server messages.", 1 );
  registerCommand( "action", &DebugCommandMgr::action, "Displays an action's animation.", 1 );
  registerCommand( "rp", &DebugCommandMgr::rp, "RP management.", 1 );
  registerCommand( "rpevent", &DebugCommandMgr::rpevent, "Commands for specific RP events.", 1 );
  registerCommand( "enemy", &DebugCommandMgr::enemy, "Commands to turn a player into an enemy.", 1 );
  registerCommand( "respawn", &DebugCommandMgr::respawn, "Command to respawn your character.", 1 );
  registerCommand( "ely", &DebugCommandMgr::ely, "Oui mais c'est parcequ'en fait cette commande sert à rien.", 1 );
}

// clear all loaded commands
Sapphire::World::Manager::DebugCommandMgr::~DebugCommandMgr()
{
  for( auto it = m_commandMap.begin(); it != m_commandMap.end(); ++it )
    ( *it ).second.reset();
}

// add a command set to the register map
void Sapphire::World::Manager::DebugCommandMgr::registerCommand( const std::string& n, DebugCommand::pFunc functionPtr,
                                                                 const std::string& hText, uint8_t uLevel )
{
  m_commandMap[ std::string( n ) ] = std::make_shared< DebugCommand >( n, functionPtr, hText, uLevel );
}

// try to retrieve the command in question, execute if found
void Sapphire::World::Manager::DebugCommandMgr::execCommand( char* data, Entity::Player& player )
{

  // define callback pointer
  void ( DebugCommandMgr::*pf )( char*, Entity::Player&, std::shared_ptr< DebugCommand > );

  std::string commandString;

  // check if the command has parameters
  std::string tmpCommand = std::string( data );
  std::size_t pos = tmpCommand.find_first_of( " " );

  if( pos != std::string::npos )
    // command has parameters, grab the first part
    commandString = tmpCommand.substr( 0, pos );
  else
    // no parameters, just get the command
    commandString = tmpCommand;

  // try to retrieve the command
  auto it = m_commandMap.find( commandString );

  if( it == m_commandMap.end() )
    // no command found, do something... or not
    player.sendUrgent( "Command not found." );
  else
  {
    if( player.getGmRank() < it->second->getRequiredGmLevel() )
    {
      player.sendUrgent( "You are not allowed to use this command." );
      return;
    }

    // command found, call the callback function and pass parameters if present.
    pf = ( *it ).second->m_pFunc;
    ( this->*pf )( data, player, ( *it ).second );
    return;
  }


}


///////////////////////////////////////////////////////////////////////////////////////
// Definition of the commands
///////////////////////////////////////////////////////////////////////////////////////

void Sapphire::World::Manager::DebugCommandMgr::help( char* data, Entity::Player& player,
                                                      std::shared_ptr< DebugCommand > command )
{
  player.sendDebug( "Registered debug commands:" );
  for( auto cmd : m_commandMap )
  {
    if( player.getGmRank() >= cmd.second->m_gmLevel )
    {
      player.sendDebug( " - {0} - {1}", cmd.first, cmd.second->getHelpText() );
    }
  }
}

void Sapphire::World::Manager::DebugCommandMgr::set( char* data, Entity::Player& player,
                                                     std::shared_ptr< DebugCommand > command )
{
  auto pTerriMgr = framework()->get< TerritoryMgr >();
  auto pDb = framework()->get< Db::DbWorkerPool< Db::ZoneDbConnection > >();
  std::string subCommand = "";
  std::string params = "";

  // check if the command has parameters
  std::string tmpCommand = std::string( data + command->getName().length() + 1 );

  std::size_t pos = tmpCommand.find_first_of( " " );

  if( pos != std::string::npos )
    // command has parameters, grab the first part
    subCommand = tmpCommand.substr( 0, pos );
  else
    // no subcommand given
    subCommand = tmpCommand;

  if( command->getName().length() + 1 + pos + 1 < strlen( data ) )
    params = std::string( data + command->getName().length() + 1 + pos + 1 );

  Logger::debug( "[{0}] Command: set subCommand: {1} params: {2}", player.getId(), subCommand, params );

  if( ( ( subCommand == "pos" ) || ( subCommand == "posr" ) ) && ( params != "" ) )
  {
    int32_t posX;
    int32_t posY;
    int32_t posZ;

    sscanf( params.c_str(), "%d %d %d", &posX, &posY, &posZ );

    if( ( posX == 0xcccccccc ) || ( posY == 0xcccccccc ) || ( posZ == 0xcccccccc ) )
    {
      player.sendUrgent( "Syntaxerror." );
      return;
    }

    if( subCommand == "pos" )
      player.setPos( static_cast< float >( posX ),
                     static_cast< float >( posY ),
                     static_cast< float >( posZ ) );
    else
      player.setPos( player.getPos().x + static_cast< float >( posX ),
                     player.getPos().y + static_cast< float >( posY ),
                     player.getPos().z + static_cast< float >( posZ ) );

    auto setActorPosPacket = makeZonePacket< FFXIVIpcActorSetPos >( player.getId() );
    setActorPosPacket->data().x = player.getPos().x;
    setActorPosPacket->data().y = player.getPos().y;
    setActorPosPacket->data().z = player.getPos().z;
    setActorPosPacket->data().r16 = Util::floatToUInt16Rot( player.getRot() );
    player.queuePacket( setActorPosPacket );

  }
  else if( ( subCommand == "tele" ) && ( params != "" ) )
  {
    int32_t aetheryteId;
    sscanf( params.c_str(), "%i", &aetheryteId );

    player.teleport( aetheryteId );
  }
  else if( ( subCommand == "discovery" ) && ( params != "" ) )
  {
    int32_t map_id;
    int32_t discover_id;
    sscanf( params.c_str(), "%i %i", &map_id, &discover_id );

    auto discoveryPacket = makeZonePacket< FFXIVIpcDiscovery >( player.getId() );
    discoveryPacket->data().map_id = map_id;
    discoveryPacket->data().map_part_id = discover_id;
    player.queuePacket( discoveryPacket );
  }

  else if( ( subCommand == "discovery_pos" ) && ( params != "" ) )
  {
    int32_t map_id;
    int32_t discover_id;
    int32_t pos_id;
    sscanf( params.c_str(), "%i %i %i", &pos_id, &map_id, &discover_id );

    std::string query2 = "UPDATE IGNORE `discoveryinfo` SET `discover_id` = '" + std::to_string( discover_id ) +
                         "' WHERE `discoveryinfo`.`id` = " + std::to_string( pos_id ) + ";";

    std::string query1 =
      "INSERT IGNORE INTO `discoveryinfo` (`id`, `map_id`, `discover_id`) VALUES ('" + std::to_string( pos_id ) +
      "', '" + std::to_string( map_id ) +
      "', '" + std::to_string( discover_id ) + "')";

    pDb->execute( query1 );
    pDb->execute( query2 );

  }

  else if( subCommand == "bgm" )
  {
    uint16_t bgmId;
    sscanf( params.c_str(), "%hd", &bgmId );
    player.sendToInRangeSet( makeActorControl143( player.getId(), SetBGM, bgmId, 0, 0, 0, 0 ), true );
  }

  else if( subCommand == "discovery_reset" )
  {
    player.resetDiscovery();
    player.queuePacket( std::make_shared< InitUIPacket >( player ) );
  }
  else if( subCommand == "classjob" )
  {
    auto pExdData = framework()->get< Data::ExdDataGenerated >();
    int32_t id;
    sscanf( params.c_str(), "%d", &id );
    if ( !pExdData->get< Sapphire::Data::ClassJob >( static_cast< uint8_t >( id ) ) )
    {
      player.sendUrgent ( "{0} is not a valid ClassJob ID.", id );
      return;
    }
    if( player.getLevelForClass( static_cast< Common::ClassJob > ( id ) ) == 0 )
    {
      player.setLevelForClass( 1, static_cast< Common::ClassJob > ( id ) );
      player.setClassJob( static_cast< Common::ClassJob > ( id ) );
    }
    else
      player.setClassJob( static_cast< Common::ClassJob > ( id ) );
    player.sendNotice( 0, "Class set to {0} ({1}).", id, pExdData->get< Sapphire::Data::ClassJob >( static_cast< uint8_t >( id ) )->name );
  }
  else if( subCommand == "cfpenalty" )
  {
    int32_t minutes;
    sscanf( params.c_str(), "%d", &minutes );
    player.setCFPenaltyMinutes( minutes );
    player.sendNotice( 0, "Duty Finder penalty set to {0}.", minutes );
  }
  else if( subCommand == "eorzeatime" )
  {
    uint64_t timestamp;
    sscanf( params.c_str(), "%" SCNu64, &timestamp );

    player.setEorzeaTimeOffset( timestamp );
    player.sendNotice( 0, "Eorzea time offset: {0}", timestamp );
  }
  else if( subCommand == "fly" )
  {
    // TODO: Less ghetto way, current implementation isn't ideal in multiplayer.
    auto initZonePacket = makeZonePacket< FFXIVIpcInitZone >( player.getId() );
    initZonePacket->data().zoneId = player.getCurrentZone()->getTerritoryTypeId();
    initZonePacket->data().weatherId = static_cast< uint8_t >( player.getCurrentZone()->getCurrentWeather() );
    initZonePacket->data().bitmask = 0x1;
    initZonePacket->data().bitmask1 = 16;
    initZonePacket->data().unknown5 = 0x2A;
    initZonePacket->data().festivalId = player.getCurrentZone()->getCurrentFestival().first;
    initZonePacket->data().additionalFestivalId = player.getCurrentZone()->getCurrentFestival().second;
    initZonePacket->data().pos.x = player.getPos().x;
    initZonePacket->data().pos.y = player.getPos().y;
    initZonePacket->data().pos.z = player.getPos().z;

    player.queuePacket( initZonePacket );
    player.sendNotice( 0, "Flight temporarily enabled." );
  }
  else if( subCommand == "gmrank" )
  {
    uint32_t rank;
    uint32_t prevrank;
    sscanf( params.c_str(), "%u", &rank );
    Sapphire::Entity::ActorPtr targetActor = player.getAsPlayer();
    if( player.getTargetId() != player.getId() )
    {
      targetActor = player.lookupTargetById( player.getTargetId() );
    }
    if( !targetActor || !targetActor->isPlayer() )
    {
      player.sendUrgent( "Invalid target." );
      return;
    }
    if ( targetActor->getId() == player.getId() )
    {
      player.sendUrgent( "You cannot use this command on yourself." );
      return;
    }
    else if ( rank > 255 )
    {
      player.sendUrgent( "Input a number between 0 and 255.");
      return;
    }
    else
    {
      prevrank = targetActor->getAsPlayer()->getGmRank();
      targetActor->getAsPlayer()->setGmRank( rank );
      player.sendNotice( 0, "The GMRank of {0} is now {1} (previously {2}).", targetActor->getAsPlayer()->getName(), rank, prevrank );
      Logger::info( "GMRank of {0} changed ({1} > {2}).", targetActor->getAsPlayer()->getName(), prevrank, rank );
    }
  }
  else if( subCommand == "model" )
  {
    auto pExdData = framework()->get< Data::ExdDataGenerated >();
    uint32_t modelId;
    sscanf( params.c_str(), "%u", &modelId );
    if ( !pExdData->get< Sapphire::Data::ModelChara > ( modelId ) )
    {
      player.sendUrgent ( "{0} is not a valid ModelChara ID.", modelId );
      return;
    }
    player.setModelChara( modelId );
    player.respawn();
    player.sendNotice( 0, "Player model set to {0}.", modelId );
  }
  // TODO: Better name
  else if( subCommand == "targetmodel" || subCommand == "tmodel" )
  {
    auto pExdData = framework()->get< Data::ExdDataGenerated >();
    uint32_t modelId;
    sscanf( params.c_str(), "%u", &modelId );
    if ( !pExdData->get< Sapphire::Data::ModelChara > ( modelId ) )
    {
      player.sendUrgent ( "{0} is not a valid ModelChara ID.", modelId );
      return;
    }
    Sapphire::Entity::ActorPtr targetActor = player.getAsPlayer();
    if( player.getTargetId() != player.getId() )
    {
      targetActor = player.lookupTargetById( player.getTargetId() );
    }
    if( !targetActor || !targetActor->isPlayer() )
    {
      player.sendUrgent( "Invalid target." );
      return;
    }
    targetActor->getAsPlayer()->setModelChara( modelId );
    auto inRange = player.getInRangeActors( true );
    for( auto actor : inRange )
    {
      if( actor->isPlayer() )
      {
        targetActor->getAsPlayer()->despawn( actor->getAsPlayer() );
        targetActor->getAsPlayer()->spawn( actor->getAsPlayer() );
      }
    }
    player.sendNotice( 0, "Target player model set to {0}.", modelId );
  }
  else if( subCommand == "name" )
  {
    char name[34];
    sscanf( params.c_str(), "%[^\n]%*c", &name );
    player.setName( name );
    player.respawn();
  }
  else if( subCommand == "sptp" )
  {
    if( params == "1" )
      player.sendToInRangeSet( makeActorControl142( player.getId(), 407, 140, 0, 0, 0, 32515 ), true );
    if( params == "2" )
      player.sendToInRangeSet( makeActorControl142( player.getId(), 407, 141, 0, 0, 0, 32515 ), true );
  }
  
  else if( subCommand == "mount" )
  {
    auto pExdData = framework()->get< Data::ExdDataGenerated >();
    int32_t id;
    sscanf( params.c_str(), "%d", &id );

    if ( !pExdData->get< Sapphire::Data::Mount >( id ) || pExdData->get< Sapphire::Data::Mount >( id )->modelChara == 0 )
    {
      player.sendUrgent ( "{0} is not a valid Mount ID.", id );
      return;
    }
    player.dismount();
    player.mount( id );
    player.sendNotice( 0, "Riding mount #{0} ({1}).", id, pExdData->get< Sapphire::Data::Mount >( id )->singular );
  }
  else if( subCommand == "msqguide" )
  {
    int32_t id;
    sscanf( params.c_str(), "%d", &id );

    auto msqPacket = makeZonePacket< FFXIVIpcMSQTrackerProgress >( player.getId() );
    msqPacket->data().id = id;
    player.queuePacket( msqPacket );

    player.sendDebug( "MSQ Guide updated " );
  }
  else if( subCommand == "msqdone" )
  {
    int32_t id;
    sscanf( params.c_str(), "%d", &id );

    auto msqPacket = makeZonePacket< FFXIVIpcMSQTrackerComplete >( player.getId() );
    msqPacket->data().id = id;
    player.queuePacket( msqPacket );

    player.sendDebug( "MSQ Guide updated " );
  }
  else if( subCommand == "weatheroverride" || subCommand == "wo" )
  {
    uint32_t weatherId;

    sscanf( params.c_str(), "%d", &weatherId );

    player.getCurrentZone()->setWeatherOverride( static_cast< Common::Weather >( weatherId ) );
  }
  else if( subCommand == "festival" )
  {
    auto pExdData = framework()->get< Data::ExdDataGenerated >();
    uint16_t festivalId;
    uint16_t additionalId;
    sscanf( params.c_str(), "%hu %hu", &festivalId, &additionalId );

    if ( !pExdData->get< Sapphire::Data::Festival >( festivalId ) )
    {
      player.sendUrgent ( "{0} is not a valid Festival ID.", festivalId );
      player.sendNotice( 0, "Additional festival set to {0} ({1}).", additionalId, pExdData->get< Sapphire::Data::Festival >( additionalId )->name );
      return;
    }
    else if ( !pExdData->get< Sapphire::Data::Festival >( additionalId ) )
    {
      player.sendUrgent ( "{0} is not a valid Festival ID.", additionalId );
      player.sendNotice( 0, "Festival set to {0} ({1}).", festivalId, pExdData->get< Sapphire::Data::Festival >( festivalId )->name );
      return;
    }
    else if ( !pExdData->get< Sapphire::Data::Festival >( festivalId ) || !pExdData->get< Sapphire::Data::Festival >( additionalId ) )
    {
      player.sendUrgent ( "{0} and {1} are not valid Festival IDs.", festivalId, additionalId );
      return;
    }

    player.sendNotice( 0, "Festival set to {0} ({1}). Additional festival set to {2} ({3}).", festivalId, pExdData->get< Sapphire::Data::Festival >( festivalId )->name,
    additionalId, pExdData->get< Sapphire::Data::Festival >( additionalId )->name );

    pTerriMgr->setCurrentFestival( festivalId, additionalId );
  }
  else if( subCommand == "festivaldisable" )
  {
    pTerriMgr->disableCurrentFestival();
  }
  else if( subCommand == "BitFlag" )
  {
    uint16_t questId;
    uint8_t questBit;
    int8_t BitFlag;
    sscanf( params.c_str(), "%hhu %hu %hhu", &BitFlag, &questId, &questBit );

    if( !player.hasQuest( questId ) )
    {
      player.sendDebug( "Player doesn't have the quest with ID#: {0}", questId );
      return;
    }
    if( questBit == 0 || questId == 0 )
    {
      player.sendDebug( "Params are not correct" );
      return;
    }

    switch( BitFlag )
    {
      case 8:
      {
        player.setQuestBitFlag8( questId, questBit, true );
        break;
      }
      case 16:
      {
        player.setQuestBitFlag16( questId, questBit, true );
        break;
      }
      case 24:
      {
        player.setQuestBitFlag24( questId, questBit, true );
        break;
      }
      case 32:
      {
        player.setQuestBitFlag32( questId, questBit, true );
        break;
      }
      case 40:
      {
        player.setQuestBitFlag40( questId, questBit, true );
        break;
      }
      case 48:
      {
        player.setQuestBitFlag48( questId, questBit, true );
        break;
      }
    }
  }
  else if( subCommand == "mobaggro" )
  {
    auto inRange = player.getInRangeActors();

    for( auto actor : inRange )
    {
      if( actor->getId() == player.getTargetId() && actor->getAsChara()->isAlive() )
      {
        actor->getAsBNpc()->onActionHostile( player.getAsChara() );
      }
    }
  }
  
  else if( subCommand == "eurekastep" )
  {
    int32_t step;
    sscanf( params.c_str(), "%d", &step );

    player.sendToInRangeSet( makeActorControl143( player.getId(), EurekaStep, step, 0x3C, 0xFFFFE3, 0, 0 ), true );
  }
  else
  {
    player.sendUrgent( "{0} is not a valid SET command.", subCommand );
  }

}

void Sapphire::World::Manager::DebugCommandMgr::add( char* data, Entity::Player& player,
                                                     std::shared_ptr< DebugCommand > command )
{
  std::string subCommand;
  std::string params = "";

  // check if the command has parameters
  std::string tmpCommand = std::string( data + command->getName().length() + 1 );

  std::size_t pos = tmpCommand.find_first_of( " " );

  if( pos != std::string::npos )
    // command has parameters, grab the first part
    subCommand = tmpCommand.substr( 0, pos );
  else
    // no subcommand given
    subCommand = tmpCommand;

  if( command->getName().length() + 1 + pos + 1 < strlen( data ) )
    params = std::string( data + command->getName().length() + 1 + pos + 1 );

  Logger::debug( "[{0}] Command: add subCommand: {1} params: {2}", player.getId(), subCommand, params );


  // if( subCommand == "status" )
  // {
    // auto pExdData = framework()->get< Data::ExdDataGenerated >();
    // int32_t id;
    // int32_t duration;
    // uint16_t param;
    // sscanf( params.c_str(), "%d %d %hu", &id, &duration, &param );

    // if ( !pExdData->get< Sapphire::Data::Status >( id ) )
    // {
      // player.sendUrgent ( "{0} is not a valid Status ID.", id );
      // return;
    // }
    // auto effect = StatusEffect::make_StatusEffect( id, player.getAsPlayer(), player.getAsPlayer(),
                                                   // duration, 3000, framework() );
    // effect->setParam( param );

    // player.addStatusEffect( effect );
  // }
  if( subCommand == "title" )
  {
    uint32_t titleId;
    sscanf( params.c_str(), "%u", &titleId );

    player.addTitle( titleId );
    player.sendNotice( 0, "Added title (id#{0})", titleId );
  }
  else if( subCommand == "bnpc" )
  {
    auto serverZone = framework()->get< World::ServerMgr >();

    auto bNpcTemplate = serverZone->getBNpcTemplate( params );

    if( !bNpcTemplate )
    {
      player.sendNotice( 0, "Template {0} not found in cache!", params );
      return;
    }
    auto playerZone = player.getCurrentZone();
    auto pBNpc = std::make_shared< Entity::BNpc >( playerZone->getNextActorId(),
                                                   bNpcTemplate,
                                                   player.getPos().x,
                                                   player.getPos().y,
                                                   player.getPos().z,
                                                   player.getRot(),
                                                   1, 1000, playerZone, framework() );



    //pBNpc->setCurrentZone( playerZone );
    //pBNpc->setPos( player.getPos().x, player.getPos().y, player.getPos().z );

    playerZone->pushActor( pBNpc );


  }
  else if( subCommand == "op" )
  {
    // temporary research packet
    int32_t opcode;
    sscanf( params.c_str(), "%x", &opcode );
    // TODO: fix for new setup
    //auto pPe = Network::Packets::make_GamePacket( opcode, 0x30, player.getId(), player.getId() );
    //player.queuePacket( pPe );
  }
  else if( subCommand == "actrl" )
  {

    // temporary research packet

    int32_t opcode;
    int32_t param1;
    int32_t param2;
    int32_t param3;
    int32_t param4;
    int32_t param5;
    int32_t param6;
    int32_t playerId;

    sscanf( params.c_str(), "%x %x %x %x %x %x %x %x", &opcode, &param1, &param2, &param3, &param4, &param5, &param6,
            &playerId );

    player.sendNotice( 0, "Injecting ACTOR_CONTROL {0}", opcode );

    auto actorControl = makeZonePacket< FFXIVIpcActorControl143 >( playerId, player.getId() );
    actorControl->data().category = opcode;
    actorControl->data().param1 = param1;
    actorControl->data().param2 = param2;
    actorControl->data().param3 = param3;
    actorControl->data().param4 = param4;
    actorControl->data().param5 = param5;
    actorControl->data().param6 = param6;
    player.queuePacket( actorControl );


    /*sscanf(params.c_str(), "%x %x %x %x %x %x %x", &opcode, &param1, &param2, &param3, &param4, &param5, &param6, &playerId);

    Network::Packets::Server::ServerNoticePacket noticePacket( player, "Injecting ACTOR_CONTROL " + std::to_string( opcode ) );

    player.queuePacket( noticePacket );

    Network::Packets::Server::ActorControlPacket143 controlPacket( player, opcode,
    param1, param2, param3, param4, param5, param6, playerId );
    player.queuePacket( controlPacket );*/

  }
  else if( subCommand == "unlock" )
  {
    uint32_t id;

    sscanf( params.c_str(), "%d", &id );
    player.learnAction( id );
  }
  else
  {
    player.sendUrgent( "{0} is not a valid ADD command.", subCommand );
  }


}

void Sapphire::World::Manager::DebugCommandMgr::get( char* data, Entity::Player& player,
                                                     std::shared_ptr< DebugCommand > command )
{
  auto pExdData = framework()->get< Data::ExdDataGenerated >();
  std::string subCommand;
  std::string params = "";

  // check if the command has parameters
  std::string tmpCommand = std::string( data + command->getName().length() + 1 );

  std::size_t pos = tmpCommand.find_first_of( " " );

  if( pos != std::string::npos )
    // command has parameters, grab the first part
    subCommand = tmpCommand.substr( 0, pos );
  else
    // no subcommand given
    subCommand = tmpCommand;

  if( command->getName().length() + 1 + pos + 1 < strlen( data ) )
    params = std::string( data + command->getName().length() + 1 + pos + 1 );

  Logger::debug( "[{0}] Command: get subCommand: {1} params: {2}", player.getId(), subCommand, params );

  if( ( subCommand == "pos" ) )
  {

    int16_t map_id = pExdData->get< Sapphire::Data::TerritoryType >( player.getCurrentZone()->getTerritoryTypeId() )->map;

    player.sendNotice( 0, "Pos:\n {0}\n {1}\n {2}\n {3}\n MapId: {4}\n ZoneId:{5}",
                       player.getPos().x, player.getPos().y, player.getPos().z,
                       player.getRot(), map_id, player.getCurrentZone()->getTerritoryTypeId() );
  }
  else
  {
    player.sendUrgent( "{0} is not a valid GET command.", subCommand );
  }

}

void Sapphire::World::Manager::DebugCommandMgr::injectPacket( char* data, Entity::Player& player,
                                                         std::shared_ptr< DebugCommand > command )
{
  auto pServerZone = framework()->get< World::ServerMgr >();
  auto inRange = player.getInRangeActors( true );
  for( auto actor : inRange )
  {
    if( actor->isPlayer() )
    {
      auto pSession = pServerZone->getSession( actor->getId() );
      if( pSession )
      pSession->getZoneConnection()->injectPacket( data + 7, player );
    }
  }
}

void Sapphire::World::Manager::DebugCommandMgr::injectChatPacket( char* data, Entity::Player& player,
                                                                  std::shared_ptr< DebugCommand > command )
{
  auto pServerZone = framework()->get< World::ServerMgr >();
  auto pSession = pServerZone->getSession( player.getId() );
  if( pSession )
    pSession->getChatConnection()->injectPacket( data + 8, player );
}

void Sapphire::World::Manager::DebugCommandMgr::replay( char* data, Entity::Player& player,
                                                        std::shared_ptr< DebugCommand > command )
{
  auto pServerZone = framework()->get< World::ServerMgr >();
  std::string subCommand;
  std::string params = "";

  // check if the command has parameters
  std::string tmpCommand = std::string( data + command->getName().length() + 1 );

  std::size_t pos = tmpCommand.find_first_of( " " );

  if( pos != std::string::npos )
    // command has parameters, grab the first part
    subCommand = tmpCommand.substr( 0, pos );
  else
    // no subcommand given
    subCommand = tmpCommand;

  if( command->getName().length() + 1 + pos + 1 < strlen( data ) )
    params = std::string( data + command->getName().length() + 1 + pos + 1 );

  Logger::debug( "[" + std::to_string( player.getId() ) + "] " +
                 "subCommand " + subCommand + " params: " + params );


  if( subCommand == "start" )
  {
    auto pSession = pServerZone->getSession( player.getId() );
    if( pSession )
      pSession->startReplay( params );
  }
  else if( subCommand == "stop" )
  {
    auto pSession = pServerZone->getSession( player.getId() );
    if( pSession )
      pSession->stopReplay();
  }
  else if( subCommand == "info" )
  {
    auto pSession = pServerZone->getSession( player.getId() );
    if( pSession )
      pSession->sendReplayInfo();
  }
  else
  {
    player.sendUrgent( "{0} is not a valid replay command.", subCommand );
  }


}

void Sapphire::World::Manager::DebugCommandMgr::nudge( char* data, Entity::Player& player,
                                                       std::shared_ptr< DebugCommand > command )
{
  std::string subCommand;

  // check if the command has parameters
  std::string tmpCommand = std::string( data + command->getName().length() + 1 );

  std::size_t spos = tmpCommand.find_first_of( " " );

  auto& pos = player.getPos();

  int32_t offset = 0;
  char direction[20];
  memset( direction, 0, 20 );

  sscanf( tmpCommand.c_str(), "%d %s", &offset, direction );

  if( direction[ 0 ] == 'u' || direction[ 0 ] == '+' )
  {
    pos.y += offset;
    player.sendNotice( 0, "nudge: Placing up {0} yalms", offset );
  }
  else if( direction[ 0 ] == 'd' || direction[ 0 ] == '-' )
  {
    pos.y -= offset;
    player.sendNotice( 0, "nudge: Placing down {0} yalms", offset );

  }
  else
  {
    float angle = player.getRot() + ( PI / 2 );
    pos.x -= offset * cos( angle );
    pos.z += offset * sin( angle );
    player.sendNotice( 0, "nudge: Placing forward {0} yalms", offset );
  }
  if( offset != 0 )
  {
    auto setActorPosPacket = makeZonePacket< FFXIVIpcActorSetPos >( player.getId() );
    setActorPosPacket->data().x = player.getPos().x;
    setActorPosPacket->data().y = player.getPos().y;
    setActorPosPacket->data().z = player.getPos().z;
    setActorPosPacket->data().r16 = Util::floatToUInt16Rot( player.getRot() );
    player.queuePacket( setActorPosPacket );
  }
}

void
Sapphire::World::Manager::DebugCommandMgr::serverInfo( char* data, Entity::Player& player,
                                                       std::shared_ptr< DebugCommand > command )
{
  auto pServerZone = framework()->get< World::ServerMgr >();
  player.sendDebug( "SapphireZone {0} \nRev: {1}", Version::VERSION, Version::GIT_HASH );
  player.sendDebug( "Compiled: " __DATE__ " " __TIME__ );
  player.sendDebug( "Sessions: {0}", pServerZone->getSessionCount() );
}

void Sapphire::World::Manager::DebugCommandMgr::script( char* data, Entity::Player& player,
                                                        std::shared_ptr< DebugCommand > command )
{
  auto pScriptMgr = framework()->get< Scripting::ScriptMgr >();
  std::string subCommand;
  std::string params = "";

  // check if the command has parameters
  std::string tmpCommand = std::string( data + command->getName().length() + 1 );

  std::size_t pos = tmpCommand.find_first_of( " " );

  if( pos != std::string::npos )
    // command has parameters, grab the first part
    subCommand = tmpCommand.substr( 0, pos );
  else
    // no subcommand given
    subCommand = tmpCommand;

  // todo: fix params so it's empty if there's no params
  if( command->getName().length() + 1 + pos + 1 < strlen( data ) )
    params = std::string( data + command->getName().length() + 1 + pos + 1 );

  Logger::debug( "[{0}] Command: script subCommand: {1} params: {2}", player.getId(), subCommand, params );

  if( subCommand == "unload" )
  {
    if( subCommand == params )
      player.sendDebug( "Command failed: requires name of script" );
    else if( pScriptMgr->getNativeScriptHandler().unloadScript( params ) )
      player.sendDebug( "Unloaded script successfully." );
    else
      player.sendDebug( "Failed to unload script: {0}", params );
  }
  else if( subCommand == "find" || subCommand == "f" )
  {
    if( subCommand == params )
      player.sendDebug( "Because reasons of filling chat with nonsense, please enter a search term" );
    else
    {
      std::set< Sapphire::Scripting::ScriptInfo* > scripts;
      pScriptMgr->getNativeScriptHandler().findScripts( scripts, params );

      if( !scripts.empty() )
      {
        player.sendDebug( "Found {0} scripts", scripts.size() );

        for( auto it = scripts.begin(); it != scripts.end(); ++it )
        {
          auto script = *it;
          player.sendDebug( " - '{0}', num scripts: {1}", script->library_name, script->scripts.size() );
        }
      }
      else
        player.sendDebug( "No scripts found with search term: {0}", params );
    }
  }
  else if( subCommand == "load" || subCommand == "l" )
  {
    if( subCommand == params )
      player.sendDebug( "Command failed: requires relative path to script" );
    else
    {
      if( pScriptMgr->getNativeScriptHandler().loadScript( params ) )
        player.sendDebug( "Loaded '{0}' successfully", params );
      else
        player.sendDebug( "Failed to load '{0}'", params );
    }

  }
  else if( subCommand == "queuereload" || subCommand == "qrl" )
  {
    if( subCommand == params )
      player.sendDebug( "Command failed: requires name of script to reload" );
    else
    {
      pScriptMgr->getNativeScriptHandler().queueScriptReload( params );
      player.sendDebug( "Queued script reload for script: {0}", params );
    }
  }
  else
  {
    player.sendDebug( "Unknown script subcommand: {0}", subCommand );
  }
}

void Sapphire::World::Manager::DebugCommandMgr::instance( char* data, Entity::Player& player,
                                                          std::shared_ptr< DebugCommand > command )
{
  auto pTeriMgr = framework()->get< TerritoryMgr >();
  std::string cmd( data ), params, subCommand;
  auto cmdPos = cmd.find_first_of( ' ' );

  if( cmdPos != std::string::npos )
  {
    params = cmd.substr( cmdPos + 1 );

    auto p = params.find_first_of( ' ' );

    if( p != std::string::npos )
    {
      subCommand = params.substr( 0, p );
      params = params.substr( subCommand.length() + 1 );
    }
    else
      subCommand = params;
  }

  Logger::debug( "[{0}] Command: instance subCommand: {1} params: {2}", player.getId(), subCommand, params );

  if( subCommand == "create" || subCommand == "cr" )
  {
    uint32_t contentFinderConditionId;
    sscanf( params.c_str(), "%d", &contentFinderConditionId );

    auto instance = pTeriMgr->createInstanceContent( contentFinderConditionId );
    if( instance )
      player.sendDebug( "Created instance with id#{0} -> {1}", instance->getGuId(), instance->getName() );
    else
      player.sendDebug( "Failed to create instance with id#{0}", contentFinderConditionId );
  }
  else if( subCommand == "bind" )
  {
    uint32_t instanceId;
    sscanf( params.c_str(), "%d", &instanceId );

    auto instance = pTeriMgr->getInstanceZonePtr( instanceId );
    if( instance && instance->getAsInstanceContent() )
    {
      auto pInstanceContent = instance->getAsInstanceContent();
      pInstanceContent->bindPlayer( player.getId() );
      player.sendDebug(
        "Now bound to instance with id: " + std::to_string( pInstanceContent->getGuId() ) +
        " -> " + pInstanceContent->getName() );
    }
    else if( instance )
      player.sendUrgent( instance->getName() + " is a Zone or a PublicContent and do not require binding." );
    else
      player.sendDebug( "Unknown instance with id#{0}", instanceId );
  }
  // TODO: Better name
  else if( subCommand == "rangebind" || subCommand == "rbind" )
  {
    uint32_t instanceId;
    sscanf( params.c_str(), "%d", &instanceId );

    auto instance = pTeriMgr->getInstanceZonePtr( instanceId );
    if( instance )
    {
      auto pInstanceContent = instance->getAsInstanceContent();
      auto inRange = player.getInRangeActors( true );
      for( auto actor : inRange )
      {
        if( actor->isPlayer() )
        {
          pInstanceContent->bindPlayer( actor->getId() );
          player.sendDebug( "{0} bound.", actor->getAsPlayer()->getName() );
        }
      }
       player.sendDebug(
      "All players in range are now bound to instance with id: " + std::to_string( pInstanceContent->getGuId() ) +
      " -> " + pInstanceContent->getName() );
    }
    else
      player.sendDebug( "Unknown instance with id: " + std::to_string( instanceId ) );
  }
  else if( subCommand == "unbind" )
  {
    uint32_t instanceId;
    sscanf( params.c_str(), "%d", &instanceId );

    auto instance = pTeriMgr->getInstanceZonePtr( instanceId );
    if( !instance )
    {
      player.sendDebug( "Unknown instance with id#{0} ", instanceId );
      return;
    }

    auto pInstanceContent = instance->getAsInstanceContent();
    if( pInstanceContent->isPlayerBound( player.getId() ) )
    {
      pInstanceContent->unbindPlayer( player.getId() );
      player.sendDebug( "Now unbound from instance with id#{0} -> {1}", pInstanceContent->getGuId(), pInstanceContent->getName() );
    }
    else
      player.sendDebug( "Player not bound to instance with id#{0}", instanceId );

  }
  else if( subCommand == "createzone" || subCommand == "crz" )
  {
    uint32_t zoneId;
    sscanf( params.c_str(), "%d", &zoneId );

    auto instance = pTeriMgr->createTerritoryInstance( zoneId );
    if( instance )
      player.sendDebug(
        "Created instance with id: " + std::to_string( instance->getGuId() ) + " -> " + instance->getName() );
    else
      player.sendDebug( "Failed to create instance with id#{0}", zoneId );
  }
  else if( subCommand == "createbind" || subCommand == "crb" )
  {
    uint32_t instanceContentId;
    sscanf( params.c_str(), "%d", &instanceContentId );

    auto instance = pTeriMgr->createInstanceContent( instanceContentId );
    if( instance )
    {
      auto pInstanceContent = instance->getAsInstanceContent();
      pInstanceContent->bindPlayer( player.getId() );
      player.sendDebug( "Created instance with id#{0} -> {1} and bound to it.", instance->getGuId(), instance->getName() );
    }
    else
      player.sendDebug( "Failed to create instance with id#{0}", instanceContentId );
  }
  else if( subCommand == "remove" || subCommand == "rm" )
  {
    uint32_t terriId;
    sscanf( params.c_str(), "%d", &terriId );

    if( pTeriMgr->removeTerritoryInstance( terriId ) )
      player.sendDebug( "Removed instance with id#{0}", terriId );
    else
      player.sendDebug( "Failed to remove instance with id#{0}", terriId );
  }
  else if( subCommand == "return" || subCommand == "ret" )
  {
    player.exitInstance();
  }
  else if( subCommand == "set" )
  {
    uint32_t index;
    uint32_t value;
    sscanf( params.c_str(), "%d %d", &index, &value );


    auto instance = std::dynamic_pointer_cast< InstanceContent >( player.getCurrentZone() );
    if( !instance )
      return;

    instance->setVar( static_cast< uint8_t >( index ), static_cast< uint8_t >( value ) );
  }
  else if( subCommand == "objstate" )
  {
    char objName[128];
    uint8_t state;

    sscanf( params.c_str(), "%s %hhu", objName, &state );

    auto instance = std::dynamic_pointer_cast< InstanceContent >( player.getCurrentZone() );
    if( !instance )
      return;

    auto obj = instance->getEObjByName( objName );
    if( !obj )
      return;

    obj->setState( state );
  }
  else if( subCommand == "objflag" )
  {
    char objName[256];
    uint32_t state1;
    uint32_t state2;

    sscanf( params.c_str(), "%s %i %i", objName, &state1, &state2 );

    auto instance = std::dynamic_pointer_cast< InstanceContent >( player.getCurrentZone() );
    if( !instance )
      return;

    auto obj = instance->getEObjByName( objName );
    if( !obj )
    {
      player.sendDebug( "No eobj found." );
      return;
    }

    obj->setAnimationFlag( state1, state2 );
  }
  else if( subCommand == "seq" )
  {
    uint8_t seq;

    sscanf( params.c_str(), "%hhu", &seq );

    auto instance = std::dynamic_pointer_cast< InstanceContent >( player.getCurrentZone() );
    if( !instance )
      return;

    instance->setSequence( seq );
  }
  else if( subCommand == "branch" )
  {
    uint8_t branch;

    sscanf( params.c_str(), "%hhu", &branch );

    auto instance = std::dynamic_pointer_cast< InstanceContent >( player.getCurrentZone() );
    if( !instance )
      return;

    instance->setBranch( branch );
  }
  else if( subCommand == "qte_start" )
  {
    auto instance = std::dynamic_pointer_cast< InstanceContent >( player.getCurrentZone() );
    if( !instance )
      return;

    player.sendDebug( "qte start" );
    instance->startQte();
  }
  else if( subCommand == "event_start" )
  {
    auto instance = std::dynamic_pointer_cast< InstanceContent >( player.getCurrentZone() );
    if( !instance )
      return;

    player.sendDebug( "evt start" );
    instance->startEventCutscene();
  }
  else if( subCommand == "event_end" )
  {
    auto instance = std::dynamic_pointer_cast< InstanceContent >( player.getCurrentZone() );
    if( !instance )
      return;

    player.sendDebug( "evt end" );
    instance->endEventCutscene();
  }
  else if( subCommand == "bgm" )
  {
    uint16_t bgmId;
    sscanf( params.c_str(), "%hd", &bgmId );

    if( auto instance = player.getCurrentInstance() )
      instance->setCurrentBGM( bgmId );
  }
  else
  {
    player.sendDebug( "Unknown sub command." );
  }
}

void Sapphire::World::Manager::DebugCommandMgr::publicContent( char* data, Entity::Player& player,
                                                             std::shared_ptr< DebugCommand > command )
{
  auto pTeriMgr = framework()->get< TerritoryMgr >();
  std::string cmd( data ), params, subCommand;
  auto cmdPos = cmd.find_first_of( ' ' );

  if( cmdPos != std::string::npos )
  {
    params = cmd.substr( cmdPos + 1 );

    auto p = params.find_first_of( ' ' );

    if( p != std::string::npos )
    {
      subCommand = params.substr( 0, p );
      params = params.substr( subCommand.length() + 1 );
    }
    else
      subCommand = params;
  }

  if( subCommand == "create" || subCommand == "cr" )
  {
    uint32_t contentFinderConditionId;
    sscanf( params.c_str(), "%d", &contentFinderConditionId );

    auto instance = pTeriMgr->createPublicContent( contentFinderConditionId );
    if( instance )
      player.sendDebug( "Created instance with id#{0} -> {1}", instance->getGuId(), instance->getName() );
    else
      player.sendDebug( "Failed to create instance with id#{0}", contentFinderConditionId );
  }
  else if( subCommand == "bind" )
  {
    uint32_t instanceId;
    sscanf( params.c_str(), "%d", &instanceId );

    auto instance = pTeriMgr->getInstanceZonePtr( instanceId );
    if( instance && instance->getAsPublicContent() )
    {
      auto pPublicContent = instance->getAsPublicContent();
      pPublicContent->bindPlayer( player.getId() );
      player.sendDebug(
        "Now bound to instance with id: " + std::to_string( pPublicContent->getGuId() ) +
        " -> " + pPublicContent->getName() );
    }
  }
  else if( subCommand == "remove" || subCommand == "rm" )
  {
    uint32_t terriId;
    sscanf( params.c_str(), "%d", &terriId );

    if( pTeriMgr->removeTerritoryInstance( terriId ) )
      player.sendDebug( "Removed instance with id#{0}", terriId );
    else
      player.sendDebug( "Failed to remove instance with id#{0}", terriId );
  }
  else if( subCommand == "return" || subCommand == "ret" )
  {
    player.exitInstance();
  }
  else if( subCommand == "set" )
  {
    uint32_t index;
    uint32_t value;
    sscanf( params.c_str(), "%d %d", &index, &value );


    auto instance = std::dynamic_pointer_cast< PublicContent >( player.getCurrentZone() );
    if( !instance )
      return;

    instance->setVar( static_cast< uint8_t >( index ), static_cast< uint8_t >( value ) );
  }
  else if( subCommand == "objstate" )
  {
    char objName[128];
    uint8_t state;

    sscanf( params.c_str(), "%s %hhu", objName, &state );

    auto instance = std::dynamic_pointer_cast< PublicContent >( player.getCurrentZone() );
    if( !instance )
      return;

    auto obj = instance->getEObjByName( objName );
    if( !obj )
      return;

    obj->setState( state );
  }
  else if( subCommand == "objflag" )
  {
    char objName[256];
    uint32_t state1;
    uint32_t state2;

    sscanf( params.c_str(), "%s %i %i", objName, &state1, &state2 );

    auto instance = std::dynamic_pointer_cast< PublicContent >( player.getCurrentZone() );
    if( !instance )
      return;

    auto obj = instance->getEObjByName( objName );
    if( !obj )
    {
      player.sendDebug( "No eobj found." );
      return;
    }

    obj->setAnimationFlag( state1, state2 );
  }
  else if( subCommand == "seq" )
  {
    uint8_t seq;

    sscanf( params.c_str(), "%hhu", &seq );

    auto instance = std::dynamic_pointer_cast< PublicContent >( player.getCurrentZone() );
    if( !instance )
      return;

    instance->setSequence( seq );
  }
  else if( subCommand == "branch" )
  {
    uint8_t branch;

    sscanf( params.c_str(), "%hhu", &branch );

    auto instance = std::dynamic_pointer_cast< PublicContent >( player.getCurrentZone() );
    if( !instance )
      return;

    instance->setBranch( branch );
  }
  else if( subCommand == "qte_start" )
  {
    auto instance = std::dynamic_pointer_cast< PublicContent >( player.getCurrentZone() );
    if( !instance )
      return;

    player.sendDebug( "qte start" );
    instance->startQte();
  }
  else if( subCommand == "event_start" )
  {
    auto instance = std::dynamic_pointer_cast< PublicContent >( player.getCurrentZone() );
    if( !instance )
      return;

    player.sendDebug( "evt start" );
    instance->startEventCutscene();
  }
  else if( subCommand == "event_end" )
  {
    auto instance = std::dynamic_pointer_cast< PublicContent >( player.getCurrentZone() );
    if( !instance )
      return;

    player.sendDebug( "evt end" );
    instance->endEventCutscene();
  }
  // else if( subCommand == "bgm" )
  // {
    // uint16_t bgmId;
    // sscanf( params.c_str(), "%hd", &bgmId );

    // if( auto instance = player.getCurrentInstance() )
      // instance->setCurrentBGM( bgmId );
  // }
  else
  {
    player.sendDebug( "Unknown sub command." );
  }
}

void Sapphire::World::Manager::DebugCommandMgr::questBattle( char* data, Entity::Player& player,
                                                             std::shared_ptr< DebugCommand > command )
{
  auto pTeriMgr = framework()->get< TerritoryMgr >();
  std::string cmd( data ), params, subCommand;
  auto cmdPos = cmd.find_first_of( ' ' );

  if( cmdPos != std::string::npos )
  {
    params = cmd.substr( cmdPos + 1 );

    auto p = params.find_first_of( ' ' );

    if( p != std::string::npos )
    {
      subCommand = params.substr( 0, p );
      params = params.substr( subCommand.length() + 1 );
    }
    else
      subCommand = params;
  }

  if( subCommand == "create" || subCommand == "cr" )
  {
    uint32_t contentFinderConditionId;
    sscanf( params.c_str(), "%d", &contentFinderConditionId );

    auto instance = pTeriMgr->createQuestBattle( contentFinderConditionId );
    if( instance )
      player.sendDebug( "Created instance with id#{0} -> {1}", instance->getGuId(), instance->getName() );
    else
      player.sendDebug( "Failed to create instance with id#{0}", contentFinderConditionId );
  }
  else if( subCommand == "complete" )
  {

    auto instance = std::dynamic_pointer_cast< QuestBattle >( player.getCurrentZone() );
    if( !instance )
      return;

    instance->success();

  }
  else if( subCommand == "fail" )
  {

    auto instance = std::dynamic_pointer_cast< QuestBattle >( player.getCurrentZone() );
    if( !instance )
      return;

    instance->fail();

  }
  else if( subCommand == "createzone" || subCommand == "crz" )
  {
    uint32_t zoneId;
    sscanf( params.c_str(), "%d", &zoneId );

    auto instance = pTeriMgr->createTerritoryInstance( zoneId );
    if( instance )
      player.sendDebug(
        "Created instance with id: " + std::to_string( instance->getGuId() ) + " -> " + instance->getName() );
    else
      player.sendDebug( "Failed to create instance with id#{0}", zoneId );
  }
  else if( subCommand == "remove" || subCommand == "rm" )
  {
    uint32_t terriId;
    sscanf( params.c_str(), "%d", &terriId );

    if( pTeriMgr->removeTerritoryInstance( terriId ) )
      player.sendDebug( "Removed instance with id#{0}", terriId );
    else
      player.sendDebug( "Failed to remove instance with id#{0}", terriId );
  }
  else if( subCommand == "return" || subCommand == "ret" )
  {
    player.exitInstance();
  }
  else if( subCommand == "set" )
  {
    uint32_t index;
    uint32_t value;
    sscanf( params.c_str(), "%d %d", &index, &value );


    auto instance = std::dynamic_pointer_cast< QuestBattle >( player.getCurrentZone() );
    if( !instance )
      return;

    instance->setVar( static_cast< uint8_t >( index ), static_cast< uint8_t >( value ) );
  }
  else if( subCommand == "objstate" )
  {
    char objName[128];
    uint8_t state;

    sscanf( params.c_str(), "%s %hhu", objName, &state );

    auto instance = std::dynamic_pointer_cast< QuestBattle >( player.getCurrentZone() );
    if( !instance )
      return;

    auto obj = instance->getEObjByName( objName );
    if( !obj )
      return;

    obj->setState( state );
  }
  else if( subCommand == "objflag" )
  {
    char objName[256];
    uint32_t state1;
    uint32_t state2;

    sscanf( params.c_str(), "%s %i %i", objName, &state1, &state2 );

    auto instance = std::dynamic_pointer_cast< QuestBattle >( player.getCurrentZone() );
    if( !instance )
      return;

    auto obj = instance->getEObjByName( objName );
    if( !obj )
    {
      player.sendDebug( "No eobj found." );
      return;
    }

    obj->setAnimationFlag( state1, state2 );
  }
  else if( subCommand == "seq" )
  {
    uint8_t seq;

    sscanf( params.c_str(), "%hhu", &seq );

    auto instance = std::dynamic_pointer_cast< QuestBattle >( player.getCurrentZone() );
    if( !instance )
      return;

    instance->setSequence( seq );
  }
  else if( subCommand == "branch" )
  {
    uint8_t branch;

    sscanf( params.c_str(), "%hhu", &branch );

    auto instance = std::dynamic_pointer_cast< QuestBattle >( player.getCurrentZone() );
    if( !instance )
      return;

    instance->setBranch( branch );
  }
  else if( subCommand == "qte_start" )
  {
    auto instance = std::dynamic_pointer_cast< QuestBattle >( player.getCurrentZone() );
    if( !instance )
      return;

    player.sendDebug( "qte start" );
    instance->startQte();
  }
  else if( subCommand == "event_start" )
  {
    auto instance = std::dynamic_pointer_cast< QuestBattle >( player.getCurrentZone() );
    if( !instance )
      return;

    player.sendDebug( "evt start" );
    instance->startEventCutscene();
  }
  else if( subCommand == "event_end" )
  {
    auto instance = std::dynamic_pointer_cast< QuestBattle >( player.getCurrentZone() );
    if( !instance )
      return;

    player.sendDebug( "evt end" );
    instance->endEventCutscene();
  }
  else if( subCommand == "bgm" )
  {
    uint16_t bgmId;
    sscanf( params.c_str(), "%hd", &bgmId );

    if( auto instance = player.getCurrentInstance() )
      instance->setCurrentBGM( bgmId );
  }
  else
  {
    player.sendDebug( "Unknown sub command." );
  }
}

void Sapphire::World::Manager::DebugCommandMgr::housing( char* data, Entity::Player& player,
                                                         std::shared_ptr< DebugCommand > command )
{
  auto pTeriMgr = framework()->get< TerritoryMgr >();
  std::string cmd( data ), params, subCommand;
  auto cmdPos = cmd.find_first_of( ' ' );

  if( cmdPos != std::string::npos )
  {
    params = cmd.substr( cmdPos + 1 );

    auto p = params.find_first_of( ' ' );

    if( p != std::string::npos )
    {
      subCommand = params.substr( 0, p );
      params = params.substr( subCommand.length() + 1 );
    }
    else
      subCommand = params;
  }

//  if( subCommand == "permission" || subCommand == "perm" )
//  {
//    uint8_t permissionSet;
//    sscanf( params.c_str(), "%hhu", &permissionSet );
//
//    if ( permissionSet < 5 )
//    {
//      auto pZone = player.getCurrentZone();
//      if( pTeriMgr->isHousingTerritory( pZone->getTerritoryTypeId() ) )
//      {
//        auto pHousing = std::dynamic_pointer_cast< HousingZone >( pZone );
//        if( pHousing )
//        {
//          // todo: wat?
//          Common::LandIdent ident {};
//          ident.wardNum = pHousing->getWardNum();
//          ident.territoryTypeId = pHousing->getTerritoryTypeId();
//
//          player.setLandFlags( permissionSet, 0, pHousing->getLandSetId(), ident );
//          player.sendLandFlags();
//        }
//        else
//          player.sendDebug( "You aren't in a housing Zone." );
//      }
//    }
//    else
//      player.sendDebug( "PermissionSet out of range." );
//  }
  else
  {
    player.sendDebug( "Unknown sub command." );
  }
}
void Sapphire::World::Manager::DebugCommandMgr::random( char* data, Entity::Player& player,
                                                       std::shared_ptr< DebugCommand > command )
  {
  std::string subCommand;

  // check if the command has parameters
  std::string tmpCommand = std::string( data + command->getName().length() + 1 );
  std::size_t spos = tmpCommand.find_first_of( " " );

  Logger::debug( "[{0}] Command random params: {1}", player.getId(), tmpCommand );

  uint32_t maxnumber( 100 );
  sscanf( tmpCommand.c_str(), "%u", &maxnumber );

  if( maxnumber > 1000000 )
  {
    player.sendUrgent( "Input a number between 0 and 1000000." );
    return;
  }
  std::random_device rd;     // only used once to initialise (seed) engine
  std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
  std::uniform_int_distribution<int> uni(0, ( maxnumber )); // guaranteed unbiased

  auto randomnumber = uni(rng);

  Logger::debug( "[Random] {1} rolled 1d{2}. Result: {3}", player.getId(), player.getName(), maxnumber, randomnumber );

  auto inRange = player.getInRangeActors( false );
    for( auto actor : inRange )
    {
      if( actor->isPlayer() )
      {
        actor->getAsPlayer()->sendNotice( 0, "{0} rolls 1d{1}. Result: {2}.", player.getName(), maxnumber, randomnumber  );
      }
    }
  player.sendNotice( 0, "You roll 1d{0}. Result: {1}.", maxnumber, randomnumber );
  }


void Sapphire::World::Manager::DebugCommandMgr::status( char* data, Entity::Player& player,
                                                       std::shared_ptr< DebugCommand > command )
{
  auto pExdData = framework()->get< Data::ExdDataGenerated >();
  auto pTerriMgr = framework()->get< TerritoryMgr >();
  auto pDb = framework()->get< Db::DbWorkerPool< Db::ZoneDbConnection > >();
  std::string subCommand = "";
  std::string params = "";

  // check if the command has parameters
  std::string tmpCommand = std::string( data + command->getName().length() + 1 );

  std::size_t pos = tmpCommand.find_first_of( " " );

  if( pos != std::string::npos )
    // command has parameters, grab the first part
    subCommand = tmpCommand.substr( 0, pos );
  else
    // no subcommand given
    subCommand = tmpCommand;

  if( command->getName().length() + 1 + pos + 1 < strlen( data ) )
    params = std::string( data + command->getName().length() + 1 + pos + 1 );

  Logger::debug( "[{0}] Command: status subCommand: {1} params: {2}", player.getId(), subCommand, params );

  if( subCommand == "self" || subCommand == "s" || subCommand == "add" )
  {
    int32_t id;
    int32_t duration;
    uint16_t param;
    sscanf( params.c_str(), "%d %d %hu", &id, &duration, &param );

    if ( !pExdData->get< Sapphire::Data::Status >( id ) )
    {
      player.sendUrgent ( "{0} is not a valid Status ID.", id );
      return;
    }
    else if ( pExdData->get< Sapphire::Data::Status >( id )->transfiguration == true && !pExdData->get< Sapphire::Data::Transformation >( param ) )
    {
      player.sendUrgent ( "Status {0} is a Transfiguration and requires a valid Transformation param.", id );
      return;
    }

    auto effect = StatusEffect::make_StatusEffect( id, player.getAsPlayer(), player.getAsPlayer(),
                                                   duration, 3000, framework() );
    effect->setParam( param );

    player.addStatusEffect( effect );
    player.sendNotice( 0, "Status {0} ({1}) added.", id, pExdData->get< Sapphire::Data::Status >( id )->name );
  }

  else if( subCommand == "target" || subCommand == "t" )
  {
    int32_t id;
    int32_t duration;
    uint16_t param;
    sscanf( params.c_str(), "%d %d %hu", &id, &duration, &param );

    if ( !pExdData->get< Sapphire::Data::Status >( id ) )
    {
      player.sendUrgent ( "{0} is not a valid Status ID.", id );
      return;
    }
    else if ( pExdData->get< Sapphire::Data::Status >( id )->transfiguration == true && !pExdData->get< Sapphire::Data::Transformation >( param ) )
    {
      player.sendUrgent ( "Status {0} is a Transfiguration and requires a valid Transformation param.", id );
      return;
    }

    Sapphire::Entity::ActorPtr targetActor = player.getAsPlayer();
    if( player.getTargetId() != player.getId() )
    {
      targetActor = player.lookupTargetById( player.getTargetId() );
    }
    if( !targetActor || !targetActor->isPlayer() )
    {
      player.sendUrgent( "Invalid target." );
      return;
    }

    auto effect = StatusEffect::make_StatusEffect( id, player.getAsPlayer(), targetActor->getAsPlayer(),
                                                   duration, 3000, framework() );
    effect->setParam( param );

    targetActor->getAsPlayer()->addStatusEffect( effect );
    player.sendNotice( 0, "Status {0} ({1}) added to {2}.", id, pExdData->get< Sapphire::Data::Status >( id )->name, targetActor->getAsPlayer()->getName() );
  }
  else if( subCommand == "remove" || subCommand == "rm" )
  {
    int32_t id;
    sscanf( params.c_str(), "%d", &id );

    if ( !pExdData->get< Sapphire::Data::Status >( id ) )
    {
      player.sendUrgent ( "{0} is not a valid Status ID.", id );
      return;
    }
/*     else if ( !player.hasStatusEffect( id ) )
    {
      player.sendUrgent ( "Player does not have Status {0}.", id );
      return;
    } */
    player.removeSingleStatusEffectById( id );
    player.sendNotice( 0, "Status {0} ({1}) removed.", id, pExdData->get< Sapphire::Data::Status >( id )->name );
  }
  // TODO: Better name
  else if( subCommand == "targetremove" || subCommand == "trm" )
  {
    int32_t id;
    sscanf( params.c_str(), "%d", &id );
    if ( !pExdData->get< Sapphire::Data::Status >( id ) )
    {
      player.sendUrgent ( "{0} is not a valid Status ID.", id );
      return;
    }

    Sapphire::Entity::ActorPtr targetActor = player.getAsPlayer();
    if( player.getTargetId() != player.getId() )
    {
      targetActor = player.lookupTargetById( player.getTargetId() );
    }
    if( !targetActor || !targetActor->isPlayer() )
    {
      player.sendUrgent( "Invalid target." );
      return;
    }
/*     if ( !targetActor->getAsPlayer()->hasStatusEffect( id ) )
    {
      player.sendUrgent ( "Target player does not have Status {0}.", id );
      return;
    } */
    targetActor->getAsPlayer()->removeSingleStatusEffectById( id );
    player.sendNotice( 0, "Status {0} ({1}) removed from {2}.", id, pExdData->get< Sapphire::Data::Status >( id )->name, targetActor->getAsPlayer()->getName() );
  }
  else
  {
    player.sendUrgent( "{0} is not a valid status command.", subCommand );
  }
}


void Sapphire::World::Manager::DebugCommandMgr::tell( char* data, Entity::Player& player,
                                                       std::shared_ptr< DebugCommand > command )
{
  std::string subCommand;

  // check if the command has parameters
  std::string tmpCommand = std::string( data + command->getName().length() + 1 );
  std::size_t spos = tmpCommand.find_first_of( " " );
  char tell [500] = "";
  sscanf( tmpCommand.c_str(), "%[^\n]%*c", &tell );

  Sapphire::Entity::ActorPtr targetActor = player.getAsPlayer();
  if( player.getTargetId() != player.getId() )
  {
    targetActor = player.lookupTargetById( player.getTargetId() );
  }
  if( !targetActor || !targetActor->isPlayer() )
  {
    player.sendUrgent( "Invalid target." );
    return;
  }
  player.sendDebug( "Sent to {0}: {1}", targetActor->getAsPlayer()->getName(), tell );
  targetActor->getAsPlayer()->sendNotice( 0, "Message from {0}: {1}", player.getName(), tell );
  Logger::debug( "[Chatlog] (DebugTell) {0} > {1}: {2}", player.getName(), targetActor->getAsPlayer()->getName(), tell );
  
}

void Sapphire::World::Manager::DebugCommandMgr::notice( char* data, Entity::Player& player,
                                                       std::shared_ptr< DebugCommand > command )
{
  std::string subCommand = "";
  std::string params = "";

  // check if the command has parameters
  std::string tmpCommand = std::string( data + command->getName().length() + 1 );

  std::size_t pos = tmpCommand.find_first_of( " " );

  if( pos != std::string::npos )
    // command has parameters, grab the first part
    subCommand = tmpCommand.substr( 0, pos );
  else
    // no subcommand given
    subCommand = tmpCommand;

  if( command->getName().length() + 1 + pos + 1 < strlen( data ) )
    params = std::string( data + command->getName().length() + 1 + pos + 1 );
  
  Logger::debug( "[{0}] Command: notice params: {1}", player.getId(), tmpCommand );
  if( subCommand == "4" )
  {
    char notice [775] = "";
    sscanf( params.c_str(), "%[^\n]%*c", &notice );

    auto inRange = player.getInRangeActors( true );
      for( auto actor : inRange )
      {
        if( actor->isPlayer() )
        {
          actor->getAsPlayer()->sendNotice( 4, "{0}", notice );
        }
      }
  }
  else if( subCommand == "5" )
  {
    char notice [775] = "";
    sscanf( params.c_str(), "%[^\n]%*c", &notice );

    auto inRange = player.getInRangeActors( true );
      for( auto actor : inRange )
      {
        if( actor->isPlayer() )
        {
          actor->getAsPlayer()->sendNotice( 5, "{0}", notice );
        }
      }
  }
  
}


void Sapphire::World::Manager::DebugCommandMgr::action( char* data, Entity::Player& player,
                                                       std::shared_ptr< DebugCommand > command )
{
  std::string subCommand;

  // check if the command has parameters
  auto pExdData = framework()->get< Data::ExdDataGenerated >();
  std::string tmpCommand = std::string( data + command->getName().length() + 1 );
  std::size_t spos = tmpCommand.find_first_of( " " );
  
  Logger::debug( "[{0}] Command: action params: {1}", player.getId(), tmpCommand );
  uint32_t actionId;
  sscanf( tmpCommand.c_str(), "%u", &actionId );

  if ( !pExdData->get< Sapphire::Data::Action >( actionId ) )
  {
    player.sendUrgent ( "{0} is not a valid Action ID.", actionId );
    return;
  }
  else
  {
    auto effectPacket = std::make_shared< Server::EffectPacket >( player.getId(), player.getTargetId(), actionId );
    effectPacket->setRotation( Util::floatToUInt16Rot( player.getRot() ) );
    Logger::debug( "[{0}] {1} uses {2}.", player.getId(), player.getName(), pExdData->get< Sapphire::Data::Action >( actionId )->name );
    // effectPacket->addEffect( effectEntry );

    player.sendToInRangeSet( effectPacket, true );
  }

  
}

void Sapphire::World::Manager::DebugCommandMgr::rp( char* data, Entity::Player& player,
                                                       std::shared_ptr< DebugCommand > command )
{
  auto pExdData = framework()->get< Data::ExdDataGenerated >();
  auto pTerriMgr = framework()->get< TerritoryMgr >();
  auto pDb = framework()->get< Db::DbWorkerPool< Db::ZoneDbConnection > >();
  std::string subCommand = "";
  std::string params = "";

  // check if the command has parameters
  std::string tmpCommand = std::string( data + command->getName().length() + 1 );

  std::size_t pos = tmpCommand.find_first_of( " " );

  if( pos != std::string::npos )
    // command has parameters, grab the first part
    subCommand = tmpCommand.substr( 0, pos );
  else
    // no subcommand given
    subCommand = tmpCommand;

  if( command->getName().length() + 1 + pos + 1 < strlen( data ) )
    params = std::string( data + command->getName().length() + 1 + pos + 1 );

  Logger::debug( "[{0}] Command: rp subCommand: {1} params: {2}", player.getId(), subCommand, params );

  if( subCommand == "prepare" )
  {
    if( !isRpPrepared == true && isRpStarted == false )
    {
      m_rpMembers.clear();
      player.sendNotice( 0, "A RP session is being prepared. The following commands can be used:"
                         "\n\n\"!rp add\": Adds the targetted player to the RP session."
                         "\n\"!rp zone Zone PosX PosY PosZ\": Adds a starting zone to the RP session."
                         "\n\"!rp theme Theme\": Adds a theme to the RP session."
                         "\n\"!rp test\": Returns a list of current members, theme and starting zone."
                         "\n\"!rp start\": Starts the RP session.");
      isRpPrepared = true;
    }
    else if ( isRpStarted == true )
      player.sendUrgent( "A RP session is already underway." );
    else
      player.sendUrgent( "A RP session is already being prepared." );
  }

  else if( subCommand == "add" )
  {
    if( !isRpPrepared == true )
    {
      player.sendUrgent( "You need to prepare a RP session before using this command. Use \"!rp prepare\".");
      return;
    }

    if( isRpPrepared == true )
    {
      Sapphire::Entity::ActorPtr targetActor = player.getAsPlayer();
      if( player.getTargetId() != player.getId() )
      {
        targetActor = player.lookupTargetById( player.getTargetId() );
      }
      if( !targetActor || !targetActor->isPlayer() )
      {
        player.sendUrgent( "Invalid target." );
        return;
      }
       if( m_rpMembers.count( targetActor->getAsPlayer() ) == 1 )
      {
        player.sendUrgent( "{0} is already registered to a RP session. Use \"!rp rm\" to remove them.", targetActor->getAsPlayer()->getName() );
        return;
      }
      m_rpMembers.insert ( targetActor->getAsPlayer() );
      if( isRpStarted == true )
        targetActor->getAsPlayer()->setRPMode( true );
      Logger::info( "{0} has been added to the RP session.", targetActor->getAsPlayer()->getName() );
      player.sendNotice( 0, "{0} has been added to the RP session.", targetActor->getAsPlayer()->getName() );
      targetActor->getAsPlayer()->sendNotice( 0, "You have been added to a RP session by {0}.", player.getName() );
    }
  }

  
  else if( subCommand == "addnpc" )
  {
    if( !isRpPrepared == true )
    {
      player.sendUrgent( "You need to prepare a RP session before using this command. Use \"!rp prepare\".");
      return;
    }

    if( isRpPrepared == true )
    {
      Sapphire::Entity::ActorPtr targetActor = player.getAsPlayer();
      if( player.getTargetId() != player.getId() )
      {
        targetActor = player.lookupTargetById( player.getTargetId() );
      }
      if( !targetActor || !targetActor->isPlayer() )
      {
        player.sendUrgent( "Invalid target." );
        return;
      }
       if( m_rpNPC.count( targetActor->getAsPlayer() ) == 1 )
      {
        player.sendUrgent( "{0} is already registered to a RP session. Use \"!rp rm\" to remove them.", targetActor->getAsPlayer()->getName() );
        return;
      }
      m_rpNPC.insert ( targetActor->getAsPlayer() );
      if( isRpStarted == true )
        targetActor->getAsPlayer()->setRPMode( true );
      Logger::info( "{0} has been added to the RP session as a NPC.", targetActor->getAsPlayer()->getName() );
      player.sendNotice( 0, "{0} has been added to the RP session as a NPC.", targetActor->getAsPlayer()->getName() );
      targetActor->getAsPlayer()->sendNotice( 0, "You have been added to a RP session as a NPC by {0}.", player.getName() );
    }
  }
  
  else if( subCommand == "addspectator" || subCommand == "addspec" )
  {
    if( !isRpPrepared == true )
    {
      player.sendUrgent( "You need to prepare a RP session before using this command. Use \"!rp prepare\".");
      return;
    }

    if( isRpPrepared == true )
    {
      Sapphire::Entity::ActorPtr targetActor = player.getAsPlayer();
      if( player.getTargetId() != player.getId() )
      {
        targetActor = player.lookupTargetById( player.getTargetId() );
      }
      if( !targetActor || !targetActor->isPlayer() )
      {
        player.sendUrgent( "Invalid target." );
        return;
      }
       if( m_rpSpectators.count( targetActor->getAsPlayer() ) == 1 )
      {
        player.sendUrgent( "{0} is already registered to a RP session. Use \"!rp rm\" to remove them.", targetActor->getAsPlayer()->getName() );
        return;
      }
      m_rpSpectators.insert ( targetActor->getAsPlayer() );
      if( isRpStarted == true )
        targetActor->getAsPlayer()->setRPMode( true );
      Logger::info( "{0} has been added to the RP session as a spectator.", targetActor->getAsPlayer()->getName() );
      player.sendNotice( 0, "{0} has been added to the RP session as a spectator.", targetActor->getAsPlayer()->getName() );
      targetActor->getAsPlayer()->sendNotice( 0, "You have been added to a RP session as a spectator by {0}. Please wait for the RP session to start.", player.getName() );
    }
  }
  
  else if( subCommand == "zone" )
  {
    if( isRpStarted == true )
    {
      player.sendUrgent( "A RP session is already underway." );
      return;
    }
    else if( !isRpPrepared == true )
    {
      player.sendUrgent( "You need to prepare a RP session before using this command. Use \"!rp prepare\".");
      return;
    }

    sscanf( params.c_str(), "%d %d %d %d", &startzone, &startposx, &startposy, &startposz );
    auto pZone = pTerriMgr->getZoneByTerritoryTypeId( startzone );
    player.sendNotice( 0, "The starting zone of the RP session has been set to {0} (ID: {1}), X: {2}, Y: {3}, Z: {4}.", pZone->getName(),
                       startzone, startposx, startposy, startposz );
  }

  else if( subCommand == "theme" )
  {
    if( isRpStarted == true )
    {
      player.sendUrgent( "A RP session is already underway." );
      return;
    }
    else if( !isRpPrepared == true )
    {
      player.sendUrgent( "You need to prepare a RP session before using this command. Use \"!rp prepare\".");
      return;
    }

    sscanf( params.c_str(), "%[^\n]%*c", &RpTheme );
    player.sendNotice( 0, "The theme of the RP session has been set to"
                       "\n\"{0}\".", RpTheme );
  }

  else if( subCommand == "test" )
  {
    if( isRpStarted == true )
    {
      player.sendUrgent( "A RP session is already underway." );
      return;
    }
    else if( !isRpPrepared == true )
    {
      player.sendUrgent( "You need to prepare a RP session before using this command. Use \"!rp prepare\".");
      return;
    }

    auto pExdData = framework()->get< Data::ExdDataGenerated >();
    auto pZone = pTerriMgr->getZoneByTerritoryTypeId( startzone );
    if ( !startzone == 0 )
      player.sendNotice( 0, "Starting Zone: {0}", pZone->getName() );
    else
      player.sendNotice( 0, "Starting Zone: None" );
    if( strcmp (RpTheme,"") != 0)
      player.sendNotice( 0, "Theme: {0}", RpTheme );
    else
        player.sendNotice( 0, "Theme: None" );
    player.sendNotice( 0, "Participants: {0}", m_rpMembers.size() );
    for( auto member : m_rpMembers )
        player.sendNotice( 0, "{0}", member->getAsPlayer()->getName() );
  }

  else if( subCommand == "start" )
  {
    if( isRpStarted == true )
    {
      player.sendUrgent( "A RP session is already underway." );
      return;
    }
    else if( !isRpPrepared == true )
    {
      player.sendUrgent( "You need to prepare a RP session before using this command. Use \"!rp prepare\".");
      return;
    }

    if( isRpPrepared == true )
    {
      m_rpMembers.insert ( player.getAsPlayer() );
      auto pZone = pTerriMgr->getZoneByTerritoryTypeId( startzone );
      Logger::info( "==========================RP START=========================" );
      Logger::info( "RP session started by {0}", player.getName() );
      if ( !startzone == 0 )
        Logger::info( "Starting Zone: {0}", pZone->getName() );
      else
        Logger::info( "Starting Zone: None" );
      if( strcmp ( RpTheme, "" ) != 0 )
        Logger::info( "Theme: {0}", RpTheme );
      else
        Logger::info( "Theme: None" );
      Logger::info( "Participants: {0}", m_rpMembers.size() );
      for( auto member : m_rpMembers )
      {
        Logger::info( "{0}", member->getAsPlayer()->getName() );
        member->getAsPlayer()->setRPMode( true );
        //member->getAsPlayer()->setGmRank( 1 );
        member->getAsPlayer()->setOnlineStatusMask( 0x0000000100400000 );

        auto statusPacket = makeZonePacket< FFXIVIpcSetOnlineStatus >( member->getAsPlayer()->getId() );
        statusPacket->data().onlineStatusFlags = 0x0000000100400000;
        framework()->get< World::ServerMgr >()->getSession( member->getAsPlayer()->getId() )->getZoneConnection()->queueOutPacket( statusPacket );

        auto searchInfoPacket = makeZonePacket< FFXIVIpcSetSearchInfo >( member->getAsPlayer()->getId() );
        searchInfoPacket->data().onlineStatusFlags = 0x0000000100400000;
        searchInfoPacket->data().selectRegion = member->getAsPlayer()->getSearchSelectRegion();
        strcpy( searchInfoPacket->data().searchMessage, member->getAsPlayer()->getSearchMessage() );
        member->getAsPlayer()->queuePacket( searchInfoPacket );

        member->getAsPlayer()->sendToInRangeSet( makeActorControl142( member->getAsPlayer()->getId(), SetStatusIcon, static_cast< uint8_t >( member->getAsPlayer()->getOnlineStatus() ) ), true );
        if( member->getAsPlayer() != player.getAsPlayer() )
        {
          if( strcmp ( RpTheme, "" ) != 0 )
            member->getAsPlayer()->sendNotice( 5, "The RP session \"{0}\" has been started by {1}.", RpTheme, player.getName() );
          else
            member->getAsPlayer()->sendNotice( 5, "RP session started by {0}.", player.getName() );
        }
      }
      Logger::info( "NPC: {0}", m_rpNPC.size() );
      for( auto npc : m_rpNPC )
      {
        Logger::info( "{0}", npc->getAsPlayer()->getName() );
        npc->getAsPlayer()->setRPMode( true );
        if( npc->getAsPlayer() != player.getAsPlayer() )
        {
          npc->getAsPlayer()->sendNotice( 5, "RP session started by {0}.", player.getName() );
        }
      }
      Logger::info( "Spectators: {0}", m_rpSpectators.size() );
      for( auto spec : m_rpSpectators )
      {
        Logger::info( "{0}", spec->getAsPlayer()->getName() );
        player.setGmInvis( true );
        spec->getAsPlayer()->setRPMode( true );
        if( spec->getAsPlayer() != player.getAsPlayer() )
        {
          spec->getAsPlayer()->sendNotice( 5, "RP session started by {0}.", player.getName() );
        }
      }
      Logger::info( "===========================================================" );
      if ( !startzone == 0 )
      {
        for( auto member : m_rpMembers )
        {
          member->getAsPlayer()->prepareZoning( startzone, true, 1, 112 );
          member->getAsPlayer()->setZone( startzone );
          member->getAsPlayer()->changePosition( startposx, startposy, startposz, member->getAsPlayer()->getRot() );
          member->getAsPlayer()->sendZoneInPackets( 0x00, 0x00, 0, 110, false );
        }
      }
      isRpStarted = true;
      player.sendNotice( 5, "RP session started." );
    }
  }
  else if( subCommand == "log" )
  {
    if( !isRpStarted == true )
    {
      player.sendUrgent( "You need to start a RP session before using this command. Use \"!rp prepare\" and \"!rp start\"." );
      return;
    }

    char logmessage [255] = "";
    sscanf( params.c_str(), "%[^\n]%*c", &logmessage );
    Logger::info( "[RP Manual Log] {0}", logmessage );
    player.sendNotice( 0, "Message added to the server log." );
  }
  else if( subCommand == "call" )
  {
    if ( isRpPrepared == false )
    {
      player.sendUrgent( "You need to prepare a RP session before using this command. Use \"!rp prepare\".");
      return;
    }
    for( auto member : m_rpMembers )
    {
      if( member->getAsPlayer() != player.getAsPlayer() )
      {
        member->getAsPlayer()->prepareZoning( player.getZoneId(), true, 1, 0 );
        if( member->getAsPlayer()->getCurrentInstance() )
        {
          member->getAsPlayer()->exitInstance();
        }
        if( member->getAsPlayer()->getCurrentZone()->getGuId() != player.getCurrentZone()->getGuId() )
        {
          if( player.getCurrentInstance() )
          {
            auto pInstanceContent = player.getCurrentInstance()->getAsInstanceContent();
            pInstanceContent->bindPlayer( member->getAsPlayer()->getId() );
          }
          member->getAsPlayer()->setInstance( player.getCurrentZone()->getGuId() );
        }
        member->getAsPlayer()->changePosition( player.getPos().x, player.getPos().y, player.getPos().z, player.getRot() );
        member->getAsPlayer()->sendZoneInPackets( 0x00, 0x00, 0, 0, false );
        player.sendNotice( 0, "Calling all players registered to the RP session." );
      }
    }
  }
  else if( subCommand == "remove" || subCommand == "rm" )
  {
  }
  else if( subCommand == "stop" )
  {
    if( !isRpStarted == true )
    {
      player.sendUrgent( "You need to start a RP session before using this command. Use \"!rp prepare\" and \"!rp start\"." );
      return;
    }
      Logger::info( "===========================================================" );
      Logger::info( "RP session stopped by {0}", player.getName() );
      Logger::info( "Participants: {0}", m_rpMembers.size() );
      for( auto member : m_rpMembers )
      {
          Logger::info( "{0}", member->getAsPlayer()->getName() );
          member->getAsPlayer()->setRPMode( false );
          if( member->getAsPlayer() != player.getAsPlayer() )
            member->getAsPlayer()->sendNotice( 5, "RP session stopped by {0}.", player.getName() );
      }
      isRpPrepared = false;
      isRpStarted = false;
      m_rpMembers.clear();
      m_rpNPC.clear();
      m_rpSpectators.clear();
      Logger::info( "===========================RP STOP=========================" );
      player.sendNotice( 5, "RP session stopped." );
  }
  else if( subCommand == "clean" )
  {
  }
  else if( subCommand == "mode" )
  {
  }
  
/*   else if( subCommand == "spectate" )
  {
    uint16_t test;
    sscanf( params.c_str(), "%hd", &test );
    player.queuePacket( makeActorControl143( player.getId(), 0x640, 0, test, 0, 0, 0 ) );
  } */
  else if( subCommand == "storage" )
  {
  }
  
  
  else if( subCommand == "memo" )
  {
  }
  
  else if( subCommand == "loadscreen" )
  {
    if( isBlackScreen == false )
    {
      auto inRange = player.getInRangeActors( false );
      for( auto actor : inRange )
      {
        if( actor->isPlayer() )
        {
          actor->getAsPlayer()->prepareZoning( player.getZoneId(), true, 1, 0 );
        }
      }
      isBlackScreen = true;
    }
    else if( isBlackScreen == true )
    {
      auto inRange = player.getInRangeActors( false );
      for( auto actor : inRange )
      {
        if( actor->isPlayer() )
        {
          actor->getAsPlayer()->changePosition( actor->getAsPlayer()->getPos().x, actor->getAsPlayer()->getPos().y, actor->getAsPlayer()->getPos().z, actor->getAsPlayer()->getRot() );
        }
      }
      isBlackScreen = false;
    }
  }
  
  else
  {
    player.sendUrgent( "{0} is not a valid rp command.", subCommand );
  }
}


void Sapphire::World::Manager::DebugCommandMgr::rpevent( char* data, Entity::Player& player,
                                                       std::shared_ptr< DebugCommand > command )
{
  auto pExdData = framework()->get< Data::ExdDataGenerated >();
  auto pTerriMgr = framework()->get< TerritoryMgr >();
  auto pDb = framework()->get< Db::DbWorkerPool< Db::ZoneDbConnection > >();
  std::string subCommand = "";
  std::string params = "";

  // check if the command has parameters
  std::string tmpCommand = std::string( data + command->getName().length() + 1 );

  std::size_t pos = tmpCommand.find_first_of( " " );

  if( pos != std::string::npos )
    // command has parameters, grab the first part
    subCommand = tmpCommand.substr( 0, pos );
  else
    // no subcommand given
    subCommand = tmpCommand;

  if( command->getName().length() + 1 + pos + 1 < strlen( data ) )
    params = std::string( data + command->getName().length() + 1 + pos + 1 );

  Logger::debug( "[{0}] Command: rpevent subCommand: {1} params: {2}", player.getId(), subCommand, params );

  if( subCommand == "t11bump" )
  {
    Sapphire::Entity::ActorPtr targetActor = player.getAsPlayer();
    if( player.getTargetId() != player.getId() )
    {
      targetActor = player.lookupTargetById( player.getTargetId() );
    }
    // else
      // targetActor = player.getAsPlayer();
    if( !targetActor || !targetActor->isPlayer() )
    {
      player.sendUrgent( "Invalid target." );
      return;
    }
    if ( params == "1l" )
      targetActor->getAsPlayer()->sendToInRangeSet( makeActorControl142( targetActor->getAsPlayer()->getId(), 220, 1972864919, 43049, 4, 1, 0 ), true );
    else if ( params == "2l" )
      targetActor->getAsPlayer()->sendToInRangeSet( makeActorControl142( targetActor->getAsPlayer()->getId(), 220, 2142861116, 41367, 4, 2, 0 ), true );
    else if ( params == "3l" )
      targetActor->getAsPlayer()->sendToInRangeSet( makeActorControl142( targetActor->getAsPlayer()->getId(), 220, 1938652695, 38298, 4, 5, 0 ), true );
    else if ( params == "4l" )
      targetActor->getAsPlayer()->sendToInRangeSet( makeActorControl142( targetActor->getAsPlayer()->getId(), 220, 2280161298, 33556, 4, 6, 0 ), true );
    else if ( params == "1r" )
      targetActor->getAsPlayer()->sendToInRangeSet( makeActorControl142( targetActor->getAsPlayer()->getId(), 220, 2310376224, 42825, 4, 7, 0 ), true );
    else if ( params == "2r" )
      targetActor->getAsPlayer()->sendToInRangeSet( makeActorControl142( targetActor->getAsPlayer()->getId(), 220, 2152036166, 41333, 4, 12, 0 ), true );
    else if ( params == "3r" )
      targetActor->getAsPlayer()->sendToInRangeSet( makeActorControl142( targetActor->getAsPlayer()->getId(), 220, 2341175365, 37917, 4, 13, 0 ), true );
    else if ( params == "4r" )
      targetActor->getAsPlayer()->sendToInRangeSet( makeActorControl142( targetActor->getAsPlayer()->getId(), 220, 2016247826, 33556, 4, 14, 0 ), true );
  }
  else if( subCommand == "adsglow" )
  {
    if ( params == "0" )
      player.sendToInRangeSet( makeActorControl142( player.getId(), 31, 0, 0, 0, 0, 32530 ), true );
    else if ( params == "1" )
      player.sendToInRangeSet( makeActorControl142( player.getId(), 31, 0, 0, 0, 1, 32530 ), true );
    else if ( params == "2" )
      player.sendToInRangeSet( makeActorControl142( player.getId(), 31, 0, 0, 0, 2, 0 ), true );
  }
  else if( subCommand == "afterimage" )
  {
    if ( params == "swap" )
    {
      Sapphire::Entity::ActorPtr targetActor = player.getAsPlayer();
      if( player.getTargetId() != player.getId() )
      {
        targetActor = player.lookupTargetById( player.getTargetId() );
      }
      // else
        // targetActor = player.getAsPlayer();
      if( !targetActor || !targetActor->isPlayer() )
      {
        player.sendUrgent( "Invalid target." );
        return;
      }
    int32_t cyrusposx = player.getPos().x;
    int32_t cyrusposy = player.getPos().y;
    int32_t cyrusposz = player.getPos().z;
    int32_t cyrusrot = player.getRot();
    int32_t imageposx = targetActor->getAsPlayer()->getPos().x;
    int32_t imageposy = targetActor->getAsPlayer()->getPos().y;
    int32_t imageposz = targetActor->getAsPlayer()->getPos().z;
    int32_t imagerot = targetActor->getAsPlayer()->getRot();
    player.changePosition( imageposx, imageposy, imageposz, imagerot );
    targetActor->getAsPlayer()->changePosition( cyrusposx, cyrusposy, cyrusposz, cyrusrot );
    auto effectPacket = std::make_shared< Server::EffectPacket >( player.getId(), targetActor->getAsPlayer()->getId(), 2919 );
    auto effectPacket2 = std::make_shared< Server::EffectPacket >( targetActor->getAsPlayer()->getId(), player.getId(), 2919 );
    player.sendToInRangeSet( effectPacket, true );
    targetActor->getAsPlayer()->sendToInRangeSet( effectPacket2, true );
    }
  }
  else if( subCommand == "khowep" )
  {
    if ( params == "rdm" )
    {
      player.setModelMainWeapon( 0x00000001002008FD );
      player.setModelSubWeapon( 0x000000010019092F );
      player.sendModel();
    }
    else if ( params == "blu" )
    {
      player.setModelMainWeapon( 0x00000000100010961 );
      player.setModelSubWeapon( 0 );
      player.sendModel();
    }
  }
  else if( subCommand == "edenwep" )
  {
    if ( params == "brd" )
    {
      player.setModelMainWeapon( 0x0000000100010265 );
      player.setModelSubWeapon( 0x00000001004602BA );
      player.sendModel();
    }
    else if ( params == "drk" )
    {
      player.setModelMainWeapon( 0x00000001000805DD );
      player.setModelSubWeapon( 0 );
      player.sendModel();
    }
  }
  else if( subCommand == "batwin" )
  {
    if ( params == "art" )
    {
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 9818 );
      player.setbNPCName( 7968 );
      player.setElementalLevel( 70 );
      player.setElement( 4 );
      player.respawn();
      player.setModelMainWeapon( 0x0000000100041F49 );
      player.sendModel();
      return;
    }
    else if ( params == "owain" )
    {
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 9821 );
      player.setbNPCName( 7970 );
      player.setElementalLevel( 70 );
      player.setElement( 1 );
      player.respawn();
      player.setModelMainWeapon( 0x0000000200041F49 );
      player.sendModel();
      return;
    }
  }
  else if( subCommand == "actionlearn" )
  {
    uint32_t action;
    sscanf( params.c_str(), "%u", &action );
    if ( !pExdData->get< Sapphire::Data::Action >( action ) )
    {
      player.sendUrgent ( "{0} is not a valid Action ID.", action );
      return;
    }
    // player.sendToInRangeSet( makeActorControl142( player.getId(), BluActionLearn, 0, 1, 0, 0, 0 ), true );
    auto inRange = player.getInRangeActors( true );
    for( auto actor : inRange )
    {
      if( actor->isPlayer() )
      {
        actor->getAsPlayer()->sendToInRangeSet( makeActorControl142( player.getId(), BluActionLearn, 0, 1, 0, 0, 0 ), true );
        actor->getAsPlayer()->sendNotice( 5, "{0} apprends {1} !", player.getName(), pExdData->get< Sapphire::Data::Action >( action )->name );
      }
    }
    
  }
  
  else if( subCommand == "mount" )
  {
    auto initZonePacket = makeZonePacket< FFXIVIpcInitZone >( player.getId() );
    initZonePacket->data().zoneId = player.getCurrentZone()->getTerritoryTypeId();
    initZonePacket->data().weatherId = static_cast< uint8_t >( player.getCurrentZone()->getCurrentWeather() );
    initZonePacket->data().bitmask = 0x1;
    initZonePacket->data().bitmask1 = 16;
    initZonePacket->data().unknown5 = 0x2A;
    initZonePacket->data().festivalId = player.getCurrentZone()->getCurrentFestival().first;
    initZonePacket->data().additionalFestivalId = player.getCurrentZone()->getCurrentFestival().second;
    initZonePacket->data().pos.x = player.getPos().x;
    initZonePacket->data().pos.y = player.getPos().y;
    initZonePacket->data().pos.z = player.getPos().z;

    player.queuePacket( initZonePacket );
    auto inRange = player.getInRangeActors( true );
    for( auto actor : inRange )
    {
      if( actor->isPlayer() )
      {
        actor->getAsPlayer()->mount( 119 );
        actor->getAsPlayer()->queuePacket( initZonePacket );
        actor->getAsPlayer()->respawn();
      }
    }
    
  }
  else if( subCommand == "shinztk" )
  {
    player.setModelMainWeapon( 0x0000000100011F62 );
    player.sendModel();
  }
  
  else if( subCommand == "flashback" )
  {
  {
    if( isFlashBack == false )
    {
      auto inRange = player.getInRangeActors( true );
      for( auto actor : inRange )
      {
        if( actor->isPlayer() )
        {
          actor->getAsPlayer()->setGmInvis( true );
          actor->getAsPlayer()->queuePacket( makeActorControl143( actor->getAsPlayer()->getId(), Flee, -1 ) );
          actor->getAsPlayer()->respawn();
        }
      }
      isFlashBack = true;
    }
    else if( isFlashBack == true )
    {
      auto inRange = player.getInRangeActors( true );
      for( auto actor : inRange )
      {
        if( actor->isPlayer() )
        {
          actor->getAsPlayer()->setGmInvis( false );
          actor->getAsPlayer()->queuePacket( makeActorControl143( actor->getAsPlayer()->getId(), Flee, 0 ) );
          actor->getAsPlayer()->respawn();
        }
      }
      isFlashBack = false;
    }
  }
  }
  else
  {
    player.sendUrgent( "{0} is not a valid rpevent command.", subCommand );
  }
}


void Sapphire::World::Manager::DebugCommandMgr::enemy( char* data, Entity::Player& player,
                                                       std::shared_ptr< DebugCommand > command )
{
  auto pExdData = framework()->get< Data::ExdDataGenerated >();
  auto pTerriMgr = framework()->get< TerritoryMgr >();
  auto pDb = framework()->get< Db::DbWorkerPool< Db::ZoneDbConnection > >();
  std::string subCommand = "";
  std::string params = "";

  // check if the command has parameters
  std::string tmpCommand = std::string( data + command->getName().length() + 1 );

  std::size_t pos = tmpCommand.find_first_of( " " );

  if( pos != std::string::npos )
    // command has parameters, grab the first part
    subCommand = tmpCommand.substr( 0, pos );
  else
    // no subcommand given
    subCommand = tmpCommand;

  if( command->getName().length() + 1 + pos + 1 < strlen( data ) )
    params = std::string( data + command->getName().length() + 1 + pos + 1 );

  Logger::debug( "[{0}] Command: enemy subCommand: {1} params: {2}", player.getId(), subCommand, params );
  if( subCommand == "set" )
  {
    if ( player.isActingAsEnemy() == false )
    {
      // player.isActingAsEnemy( true );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.respawn();
      player.sendNotice( 0, "Player respawned as an enemy." );
      return;
    }
    else
    {
      // player.isActingAsEnemy( false );
      player.setModelType( 1 );
      player.setSubType( 0 );
      player.setEnemyType( 0 );
      player.setbNPCName( 0 );
      player.setbNPCBase( 0 );
      player.respawn();
      player.sendNotice( 0, "Player respawned as a regular player." );
      return;
    }
  }
  if( subCommand == "friendly" )
  {
    if ( player.isActingAsEnemy() == false )
    {
      // player.isActingAsEnemy( true );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 0 );
      player.respawn();
      player.sendNotice( 0, "Player respawned as a friendly NPC." );
      return;
    }
    else
    {
      // player.isActingAsEnemy( false );
      player.setModelType( 1 );
      player.setSubType( 0 );
      player.setEnemyType( 0 );
      player.setbNPCName( 0 );
      player.setbNPCBase( 0 );
      player.respawn();
      player.sendNotice( 0, "Player respawned as a regular player." );
      return;
    }
  }
  else if( subCommand == "name" )
  {
    auto pExdData = framework()->get< Data::ExdDataGenerated >();
    uint32_t nameId;
    sscanf( params.c_str(), "%u", &nameId );
    if ( !pExdData->get< Sapphire::Data::BNpcName > ( nameId ) )
    {
      player.sendUrgent ( "{0} is not a valid BNpcName ID.", nameId );
      return;
    }
    player.setbNPCName( nameId );
    player.respawn();
    player.sendNotice( 0, "BNPCName set to {0} ({1}).", nameId, pExdData->get< Sapphire::Data::BNpcName >( nameId )->singular );
  }
  
  else if( subCommand == "base" )
  {
    uint32_t baseId;
    sscanf( params.c_str(), "%u", &baseId );
    player.setbNPCBase( baseId );
    player.respawn();
    player.sendNotice( 0, "BNPCBase set to {0}.", baseId );
  }
  
  else if( subCommand == "odinbase" )
  {
    player.setbNPCBase( 882 );
    player.respawn();
  }
  else if( subCommand == "element" || subCommand == "elem" )
  {
    uint32_t element;
    sscanf( params.c_str(), "%u", &element );
    player.setElement( element );
    player.respawn();
    player.sendNotice( 0, "Element set to {0}.", element );
  }
  else if( subCommand == "elvl" )
  {
    uint32_t elementallevel;
    sscanf( params.c_str(), "%u", &elementallevel );
    player.setElementalLevel( elementallevel );
    player.respawn();
    player.sendNotice( 0, "Elemental Level set to {0}.", elementallevel );
  }
  else if( subCommand == "flags" )
  {
    uint32_t displayflags;
    sscanf( params.c_str(), "%u", &displayflags);
    player.setDisplayFlags( displayflags );
    player.respawn();
    player.sendNotice( 0, "DisplayFlags set to {0}.", displayflags );
  }
  else
  {
    player.sendUrgent( "{0} is not a valid enemy command.", subCommand );
  }
}

void Sapphire::World::Manager::DebugCommandMgr::respawn( char* data, Entity::Player& player,
                                                       std::shared_ptr< DebugCommand > command )

{
  player.respawn();
}

void Sapphire::World::Manager::DebugCommandMgr::ely( char* data, Entity::Player& player,
                                                       std::shared_ptr< DebugCommand > command )
{
  uint32_t elyexcuse;

  elyexcuse = rand() %  12;
  if( elyexcuse == 0)
  {
      player.sendDebug( "Oui c'est parceque j'ai pas pu utiliser Restreinte parceque j'avais pas la portée vu que l'angle de la caméra relatif à l'inclinaison de la Lune était pas bon." );
  }
  else if( elyexcuse == 1)
  {
      player.sendDebug( "Oui c'est parceque j'étais en plein opener du coup je regardais mes boutons s'allumer et du coup bah lol." );
  }
  else if( elyexcuse == 2)
  {
      player.sendDebug( "Oui c'est parceque j'ai pas vu Midgardosrmr sur le bord de l'arène en même temps il est pas super grand hein faut comprendre." );
  }
  else if( elyexcuse == 3)
  {
       player.sendDebug( "Oui c'est parceque l'Exaflare était superposé sur le sol et du coup baaaaaah je me suis douché dedans :3" );
  }
  else if( elyexcuse == 4)
  {
       player.sendDebug( "On peut faire une pause de 50 minutes ? J'ai un event Nouvel An à faire." );
  }
  else if( elyexcuse == 5)
  {
       player.sendDebug( "Meeeeeerde j'avais pas vu l'Akh Rhai centré sur moi !!" );
       // inject a packet that spams Akh Rhai on the player here
  }
  else if( elyexcuse == 6)
  {
       player.sendDebug( "Désolée j'étais juste mal placée hihi." );
  }
  else if( elyexcuse == 7)
  {
       player.sendDebug( "Rashaza Yinako utilise Midare Setsugecouille."
       "\nJeido Uran utilise VerBrasier."
       "\nEdenai Tokisaki utilise Flèche Nastrond."
       "\nStormbriga Kitsu utilise Patate Fendeur."
       "\nL'effet La Balance se dissipe."
       "\nElysande Starr utilise Attaque Sournoise." );
  }
  else if( elyexcuse == 8)
  {
       player.sendDebug( "Désolée je serais en retard, j'ai Mahjong et je sais pas comment quitter." );
  }
  else if( elyexcuse == 9)
  {
       player.sendDebug( "Je suis super crevée ce soir." );
       // inflicts some kind of tired status here
  }
  else if( elyexcuse == 10)
  {
      player.setModelChara( 2335 );
      player.respawn();
  }
  else if( elyexcuse == 11)
  {
      player.takeDamage( 9999999 );
  }
}