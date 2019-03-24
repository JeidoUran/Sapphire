#ifndef _GAMECOMMANDHANDLER_H_
#define _GAMECOMMANDHANDLER_H_

#include <map>
#include <Common.h>

#include "DebugCommand/DebugCommand.h"
#include "ForwardsZone.h"
#include "BaseManager.h"

namespace Sapphire::World::Manager
{

  // handler for in game commands
  class DebugCommandMgr : public Manager::BaseManager
  {
  private:
    // container mapping command string to command object
    std::map< std::string, std::shared_ptr< DebugCommand > > m_commandMap;

    std::set< Sapphire::Entity::PlayerPtr > m_rpMembers;
    std::set< Sapphire::Entity::PlayerPtr > m_rpNPC;
    std::set< Sapphire::Entity::PlayerPtr > m_rpSpectators;

    bool isRpPrepared = ( false );
    bool isRpStarted = ( false );
    int32_t startzone = 0;
    int32_t startposx = 0;
    int32_t startposy = 0;
    int32_t startposz = 0;
    char RpTheme [255] = "";


  public:
    DebugCommandMgr( FrameworkPtr pFw );

    ~DebugCommandMgr();

    // register command to command map
    void registerCommand( const std::string& n, DebugCommand::pFunc, const std::string& hText, uint8_t uLevel );

    // execute command if registered
    void execCommand( char* data, Entity::Player& player );

    // help command
    void help( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    // command handler callbacks
    void set( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void get( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void add( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );
    //void debug( char * data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void injectPacket( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void injectChatPacket( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void replay( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void nudge( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void serverInfo( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void unlockCharacter( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void instance( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void housing( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command) ;

    void script( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void random( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void status( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void tell( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void rp( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );

    void ely( char* data, Entity::Player& player, std::shared_ptr< DebugCommand > command );


  };

}
#endif
