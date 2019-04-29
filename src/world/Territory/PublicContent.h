#ifndef SAPPHIRE_PUBLICCONTENT_H
#define SAPPHIRE_PUBLICCONTENT_H

#include "Zone.h"
#include "Event/Director.h"
#include "Forwards.h"

namespace Sapphire::Data
{
  struct PublicContent;
}

namespace Sapphire
{
  class PublicContent : public Event::Director, public Zone
  {
  public:
    enum PublicContentState
    {
      Created,
      DutyReset,
      DutyInProgress,
      DutyFinished
    };

    PublicContent( std::shared_ptr< Sapphire::Data::PublicContent > pZoneConfiguration,
                     uint16_t territoryType,
                     uint32_t guId,
                     const std::string& internalName,
                     const std::string& contentName,
                     uint32_t publicContentId,
                     FrameworkPtr pFw );

    virtual ~PublicContent();

    bool init() override;

    void onBeforePlayerZoneIn( Entity::Player& player ) override;

    void onPlayerZoneIn( Entity::Player& player ) override;

    void onLeaveTerritory( Entity::Player& player ) override;

    void onFinishLoading( Entity::Player& player ) override;

    void onInitDirector( Entity::Player& player ) override;

    void onDirectorSync( Entity::Player& player ) override;

    void onUpdate( uint64_t tickCount ) override;

    void onTalk( Entity::Player& player, uint32_t eventId, uint64_t actorId );

    void onEnterTerritory( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2 ) override;

    void onRegisterEObj( Entity::EventObjectPtr object ) override;

    void setVar( uint8_t index, uint8_t value );

    void setSequence( uint8_t value );

    void setBranch( uint8_t value );

    void startQte();

    void startEventCutscene();

    void endEventCutscene();

    void clearDirector( Entity::Player& player );

    /*! set the current bgm index (inside bgm.exd) */
    void setCurrentBGM( uint16_t bgmId );

    /*! set the current bgm for a specific player */
    void setPlayerBGM( Entity::Player& player, uint16_t bgmId );

    /*! get the currently playing bgm index */
    uint16_t getCurrentBGM() const;

    bool hasPlayerPreviouslySpawned( Entity::Player& player ) const;

    PublicContentState getState() const;

    std::shared_ptr< Sapphire::Data::PublicContent > getZoneConfiguration() const;

    uint32_t getPublicContentId() const;

    Entity::EventObjectPtr getEObjByName( const std::string& name );

    /*! binds a player to the instance */
    bool bindPlayer( uint32_t playerId );

    /*! removes bind of player from the instance */
    void unbindPlayer( uint32_t playerId );

    /*! return true if the player is bound to the instance */
    bool isPlayerBound( uint32_t playerId ) const;

    /*! number of milliseconds after all players are ready for the instance to commence (spawn circle removed) */
    const uint32_t instanceStartDelay = 1250;

  private:
    std::shared_ptr< Sapphire::Data::PublicContent > m_zoneConfiguration;
    uint32_t m_publicContentId;
    PublicContentState m_state;
    uint16_t m_currentBgm;

    int64_t m_instanceExpireTime;
    uint64_t m_instanceCommenceTime;

    Entity::EventObjectPtr m_pEntranceEObj;

    std::map< std::string, Entity::EventObjectPtr > m_eventObjectMap;
    std::unordered_map< uint32_t, Entity::EventObjectPtr > m_eventIdToObjectMap;
    std::set< uint32_t > m_spawnedPlayers;

    // the players which are bound to the instance, regardless of inside or offline
    std::set< uint32_t > m_boundPlayerIds;
    Entity::PlayerPtr m_pPlayer;
  };

}
#endif //SAPPHIRE_PUBLICCONTENT_H