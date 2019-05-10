#include <ScriptObject.h>
#include <Territory/PublicContent.h>
#include "Actor/EventObject.h"
#include <Actor/Player.h>

using namespace Sapphire;

class TheForbiddenLandEurekaHydatos : public Sapphire::ScriptAPI::PublicContentScript
{
public:
  TheForbiddenLandEurekaHydatos() : Sapphire::ScriptAPI::PublicContentScript( 16 )
  { }

  void onPlayerSetup( Sapphire::PublicContent& instance, Entity::Player& player )
  {
    //! Setup Ovni
    if( player.getId() == 2097194 )
    {
      player.setRot( -0.0118475 );
      player.setPos( { -683.286f, 713.0f, -247.779f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 1575 );
      player.setbNPCName( 8060 );
      player.setElementalLevel( 70 );
      player.setElement( 12 );
      player.setModelMainWeapon( 0x0000000000000000 );
      player.sendModel();
      player.setGmInvis( true );
    }

    //! Setup Louhi
    else if( player.getId() == 2097200 )
    {
      player.setRot( -0.0626216 );
      player.setPos( { -51.6689f, 507.982f, -382.459f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 10060 );
      player.setbNPCName( 7529 );
      player.setElementalLevel( 70 );
      player.setElement( 8 );
      player.setModelMainWeapon( 0x0000000000000000000 );
      player.sendModel();
      player.setGmInvis( true );
    }

    //! Setup Penthesilea
    else if( player.getId() == 2097199 )
    {
      player.setRot( -0.0118475 );
      player.setPos( { 549.026f, 515.091f, -331.195f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 10060 );
      player.setbNPCName( 7731 );
      player.setElementalLevel( 70 );
      player.setElement( 7 );
      player.setModelMainWeapon( 0x0000000100051F49 );
      player.sendModel();
      player.setGmInvis( true );
    }

    //! Setup Art
    else if( player.getId() == 2097191 )
    {
      player.setRot( -0.00240898f );
      // player.setPos( { -0.165468f, -81.0911f, 878.663f } );
      player.setPos( { -129.009f, -10.01f, 747.943f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 9818 );
      player.setbNPCName( 7968 );
      player.setElementalLevel( 70 );
      player.setElement( 4 );
      player.setModelMainWeapon( 0x0000000100041F49 );
      player.sendModel();
      player.setGmInvis( true );
    }

    //! Setup Owain
    else if( player.getId() == 2097192 )
    {
      player.setRot( -0.00240898f );
      // player.setPos( { -0.165468f, -81.0911f, 878.663f } );
      player.setPos( { 129.009f, -10.01f, 747.943f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 9821 );
      player.setbNPCName( 7970 );
      player.setElementalLevel( 70 );
      player.setElement( 1 );
      player.setModelMainWeapon( 0x0000000200041F49 );
      player.sendModel();
      player.setGmInvis( true );
    }

    //! Setup ADS 01/GRUN
    else if( player.getId() == 2097198 )
    {
      player.setRot( 0.0215154 );
      player.setPos( { -0.209339f, 22.1594f, 579.866f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 882 );
      player.setbNPCName( 1459 );
      player.setElementalLevel( 70 );
      player.setElement( 14 );
      player.setModelMainWeapon( 0x0000000000000000 );
      player.sendModel();
    }

    //! Setup Small Rooms Mobs
    else if( player.getId() == 2097180 || player.getId() == 2097181 || player.getId() == 2097182 )
    {
      player.setRot( 0.0337155 );
      player.setPos( { -95.5791f, 48.0f, 457.621f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 6015 );
      if( player.getId() == 2097180 )
        player.setbNPCName( 7985 );
      if( player.getId() == 2097181 )
        player.setbNPCName( 7986 );
      if( player.getId() == 2097182 )
        player.setbNPCName( 7987 );
      player.setElementalLevel( 70 );
      player.setElement( 14 );
      player.setModelMainWeapon( 0x0000000000000000 );
      player.sendModel();
      player.setGmInvis( true );
    }

    //! Setup ADS 01/RED
    else if( player.getId() == 2097195 )
    {
      player.setRot( 0.0337155 );
      player.setPos( { 111.94f, 56.0f, 427.917f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 882 );
      player.setbNPCName( 1459 );
      player.setElementalLevel( 70 );
      player.setElement( 14 );
      player.setModelMainWeapon( 0x0000000000000000 );
      player.sendModel();
    }

    //! Setup Allagan Bug
    else if( player.getId() == 2097196 )
    {
      player.setRot( 0.202267f );
      player.setPos( { 108.091f, 56.0f, 431.162f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCName( 1474 );
      player.setElementalLevel( 70 );
      player.setElement( 14 );
      player.setModelMainWeapon( 0x0000000000000000 );
      player.sendModel();
      player.setGmInvis( true );
    }

    //! Setup Allagan Drone
    else if( player.getId() == 2097197 )
    {
      player.setRot( -0.419972f );
      player.setPos( { 116.259f, 56.0f, 431.884f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCName( 2885 );
      player.setElementalLevel( 70 );
      player.setElement( 14 );
      player.setModelMainWeapon( 0x0000000000000000 );
      player.sendModel();
      player.setGmInvis( true );
    }

    //! Setup Neema
    // 2nd Session (Flashback)
    else if( player.getId() == 2097154 )
    {
      player.setRot( -0.538333f );
      player.setPos( { 134.835f, 497.699f, -29.7634f } );

    // 3rd Session
      // player.setRot( 3.12456f );
      // player.setPos( { 50.1586f, 590.0f, 644.67f } );
      // player.setGmInvis( true );

    }

    //! Setup Anjudo (Flashback)
    else if( player.getId() == 2097157 )
    {
      player.setRot( -0.538333f );
      player.setPos( { 134.835f, 497.699f, -29.7634f } );
    }

    //! Setup Khojin (Flashback)
    else if( player.getId() == 2097157 )
    {
      player.setRot( -0.538333f );
      player.setPos( { 134.835f, 497.699f, -29.7634f } );
    }

    //! Setup Cyrus (Flashback)
    else if( player.getId() == 2097158 )
    {
      player.setRot( -2.17353f );
      player.setPos( { -75.1413f, 80.0f, 349.121f } );
    }

    //! Setup Anjudo's Group (3rd Session)
    // else if( player.getId() == 2097157 || player.getId() == 2097155 || player.getId() == 2097158 || player.getId() == 2097159 )
    // {
      // player.setRot( 3.12456f );
      // player.setPos( { 50.1586f, 590.0f, 644.67f } );
    // }

    //! Setup Players
    else
    {
      // 1st Session
      // player.mount( 119 );
      // player.getCurrentZone()->setWeatherOverride( static_cast< Common::Weather >( 10 ) );
      // player.setRot( 1.96528f );
      // player.setPos( { -991.284f, 580.0f, -69.2263f } );

      // 2nd Session
      player.getCurrentZone()->setWeatherOverride( static_cast< Common::Weather >( 10 ) );
      player.setRot(  0.0126879f );
      player.setPos( { 0.0360257f, -45.9304f, 857.436f } );

      // 3rd Session
      // Start in Board Room?
    }

    //! Setup eobjs

    instance.getEObjByName( "redportal" )->setAnimationFlag( 0, 1 );

    instance.getEObjByName( "redportal2" )->setAnimationFlag( 0, 1 );
    instance.getEObjByName( "baportal1" )->setAnimationFlag( 0, 5 );
    instance.getEObjByName( "baportal2" )->setAnimationFlag( 0, 1 );
    instance.getEObjByName( "baportal3" )->setAnimationFlag( 0, 1 );
    instance.getEObjByName( "baportal4" )->setAnimationFlag( 0, 5 );
    instance.getEObjByName( "baportal5" )->setAnimationFlag( 0, 1 );
    instance.getEObjByName( "baportal6" )->setAnimationFlag( 0, 1 );
    instance.getEObjByName( "timegate1" )->setAnimationFlag( 0, 4 );
    instance.getEObjByName( "timegate2" )->setAnimationFlag( 0, 4 );
    instance.getEObjByName( "door1right_collision" )->setAnimationFlag( 0, 4 );
    instance.getEObjByName( "door1left_collision" )->setAnimationFlag( 0, 4 );
    instance.getEObjByName( "door3_collision" )->setAnimationFlag( 0, 4 );
    instance.getEObjByName( "door6_collision" )->setAnimationFlag( 0, 4 );
    instance.getEObjByName( "redportal7" )->setAnimationFlag( 0, 1 );
    instance.getEObjByName( "portal_to_bridge" )->setAnimationFlag( 0, 1 );
    // instance.getEObjByName( "ice_portal" )->setAnimationFlag( 0, 1 );
    // instance.getEObjByName( "water_portal" )->setAnimationFlag( 0, 1 );
    instance.getEObjByName( "light_portal" )->setAnimationFlag( 0, 1 );
    instance.getEObjByName( "wind_portal" )->setAnimationFlag( 0, 1 );
    instance.getEObjByName( "fire_portal" )->setAnimationFlag( 0, 1 );
    instance.getEObjByName( "earth_portal" )->setAnimationFlag( 0, 1 );
  }

  void onInit( PublicContent& instance ) override
  {
    // instance.registerEObj( "unknown_0", 2002735, 0, 4, { -128.923492f, -10.070720f, 777.984375f }, 0.950000f, 0.000048f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118", 2007457, 7763762, 4, { -128.923492f, -10.067880f, 776.580627f }, 1.296936f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "sgvf_w_lvd_b0118_1", 2007457, 7763679, 4, { -128.099503f, -10.068410f, 719.199524f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    // instance.registerEObj( "unknown_1", 2007457, 7768488, 4, { -134.917297f, -10.010040f, 750.439819f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_2", 2002735, 0, 4, { 128.770905f, -10.060530f, 778.620728f }, 0.950000f, 0.000048f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118_2", 2007457, 7763699, 4, { 129.411697f, -10.071260f, 776.331726f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "sgvf_w_lvd_b0118_3", 2007457, 7763700, 4, { 129.411697f, -10.070450f, 720.071106f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    // instance.registerEObj( "unknown_3", 2002735, 0, 4, { -0.015320f, 50.055561f, 493.475586f }, 0.950000f, 0.000048f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118_4", 2007457, 7741189, 4, { 0.512825f, 50.009800f, 495.219513f }, 1.000000f, 0.000000f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "sgvf_w_lvd_b0118_5", 2007457, 7741190, 4, { 36.618351f, 50.055470f, 458.152008f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    // instance.registerEObj( "unknown_4", 2007457, 7745394, 4, { -1.825981f, 50.002331f, 457.632202f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3fd_b1605", 2007457, 7741260, 4, { 1.700844f, 50.002331f, 457.632202f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_5", 2002735, 0, 4, { -143.963501f, 82.207230f, 314.100403f }, 0.950000f, -1.570451f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118_6", 2007457, 7735681, 4, { -143.052795f, 82.207237f, 313.649200f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "sgvf_w_lvd_b0118_7", 2007457, 7735697, 4, { -175.127808f, 82.200317f, 280.994904f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    // instance.registerEObj( "unknown_6", 2009673, 0, 4, { -172.344406f, 81.999977f, 331.537994f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_7", 2009674, 0, 4, { -169.445297f, 81.999969f, 335.805695f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3r1_b1274", 2007457, 7739401, 4, { -162.300003f, 81.999977f, 301.299988f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3r1_b1274_1", 2007457, 7739403, 4, { -160.800003f, 81.999977f, 293.500000f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3r1_b1274_2", 2007457, 7739404, 4, { -154.500000f, 81.999977f, 299.600006f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3r1_b1274_3", 2007457, 7739405, 4, { -187.750305f, 81.999977f, 326.700012f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3r1_b1274_4", 2007457, 7739406, 4, { -189.399994f, 81.999977f, 334.399994f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3r1_b1274_5", 2007457, 7739407, 4, { -195.600296f, 81.999977f, 328.299988f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3r1_b1274_6", 2007457, 7739408, 4, { -162.300293f, 81.999969f, 326.600006f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3r1_b1274_7", 2007457, 7739409, 4, { -154.600296f, 81.999969f, 328.200012f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3r1_b1274_8", 2007457, 7739410, 4, { -160.600006f, 81.999969f, 334.500000f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3r1_b1274_9", 2007457, 7739411, 4, { -187.699997f, 81.999977f, 301.299988f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3r1_b1274_10", 2007457, 7739412, 4, { -195.500000f, 81.999977f, 299.799988f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3r1_b1274_11", 2007457, 7739413, 4, { -189.399994f, 81.999977f, 293.600006f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_8", 2002735, 0, 4, { -17.249100f, 107.999802f, 91.095901f }, 1.250000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_w_lvd_b0118_8", 2007457, 7741873, 4, { -17.065720f, 107.999802f, 93.406097f }, 1.000000f, 0.000000f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    // instance.registerEObj( "sgbg_z3fd_u1_swch1", 2007457, 7740736, 4, { -16.850000f, 93.073082f, 6.992088f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgbg_z3fd_u1_swch1_1", 2007457, 7740728, 4, { 4.200000f, 93.124687f, 16.750000f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgbg_z3fd_u1_swch1_2", 2007457, 7740735, 4, { 1.430000f, 93.073112f, 41.492088f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgbg_z3fd_u1_swch1_3", 2007457, 7740715, 4, { -17.049999f, 93.124702f, 53.500000f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgbg_z3fd_u1_swch1_4", 2007457, 7740733, 4, { -36.349998f, 93.040756f, 39.492088f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgbg_z3fd_u1_swch1_5", 2007457, 7740731, 4, { -38.250000f, 92.990501f, 16.750000f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_9", 2007457, 7770797, 4, { -16.877850f, 93.000000f, 44.238171f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3fd_b1561", 2007457, 7852653, 4, { -17.000000f, 107.999802f, 96.000000f }, 1.000000f, -0.000000f ); 
    // instance.registerEObj( "sgvf_z3fd_b1553", 2007457, 7829944, 4, { -224.003906f, 47.999989f, 428.517914f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3fd_b1553_1", 2007457, 7829713, 4, { -224.003799f, 47.999950f, 488.586304f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3fd_b1553_2", 2007457, 7829943, 4, { -160.018906f, 47.999809f, 428.297485f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3fd_b1553_3", 2007457, 7829936, 4, { -160.018005f, 47.999870f, 490.249390f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3fd_b1553_4", 2007457, 7829941, 4, { -95.944267f, 48.000111f, 425.855713f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "sgvf_z3fd_b1553_5", 2007457, 7829937, 4, { -95.985802f, 48.000111f, 489.578186f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_10", 2009728, 0, 4, { 0.167785f, -46.000000f, 870.389771f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_11", 2009729, 0, 4, { -2.578857f, -46.000000f, 870.267883f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_12", 2009730, 0, 4, { 2.853394f, -46.000000f, 870.206726f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "Headquartersentrance", 2009750, 0, 4, { 125.711800f, 500.150909f, 2.250822f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "Shortcut", 2000700, 0, 4, { -0.076182f, -46.000000f, 888.669983f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_13", 2007457, 7785080, 4, { -223.919098f, 48.999889f, 450.162415f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_14", 2007457, 7785077, 4, { -223.968994f, 48.999859f, 465.901489f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_15", 2007457, 7785078, 4, { -160.043701f, 49.000469f, 450.096497f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_16", 2007457, 7785076, 4, { -159.954895f, 49.000469f, 465.859406f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_17", 2007457, 7785079, 4, { -95.963966f, 48.996689f, 450.156403f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_18", 2007457, 7785075, 4, { -95.994591f, 48.996700f, 465.842712f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_19", 2007457, 7788873, 4, { -128.953903f, -6.912369f, 685.786377f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_20", 2007457, 7788874, 4, { 128.984299f, -6.820808f, 686.304871f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_21", 2007457, 7788876, 4, { -0.137373f, 48.142220f, 523.887878f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_22", 2007457, 7788879, 4, { -60.624149f, 48.783070f, 457.938385f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_23", 2007457, 7788878, 4, { 60.501949f, 48.874641f, 458.060394f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_24", 2007457, 7788880, 4, { -175.036301f, 80.979607f, 253.559097f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_25", 2007457, 7788882, 4, { -16.647579f, 108.995102f, 108.171097f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_26", 2007457, 7830050, 4, { 111.802696f, 80.979607f, 348.622803f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_27", 2007457, 7830083, 4, { -55.840881f, -45.000000f, 878.989624f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_28", 2007457, 7830084, 4, { 56.259121f, -45.000000f, 878.989624f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "Leatherboundjournal", 2009731, 0, 4, { 10.215350f, -46.000000f, 868.765320f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "Leatherboundjournal_1", 2009732, 0, 4, { -10.306930f, -46.000000f, 868.765320f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "Leatherboundjournal_2", 2009733, 0, 4, { 132.798294f, -15.999980f, 860.287476f }, 0.991760f, 0.785458f ); 
    // instance.registerEObj( "Leatherboundjournal_3", 2009734, 0, 4, { -132.577606f, -16.000031f, 860.005371f }, 0.991760f, 0.785458f ); 
    // instance.registerEObj( "Exit", 2009753, 0, 4, { -17.135990f, 92.990494f, 44.998779f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_29", 2007457, 7844636, 4, { -38.071289f, 50.034302f, 457.968994f }, 0.991760f, 0.000048f ); 

    //! RP Renamed eobjs
    // instance.registerEObj( "art_effect", 2007457, 7768488, 4, { -134.917297f, -10.010040f, 750.439819f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "raiden_lightning", 2007457, 7745394, 4, { -1.825981f, 50.002331f, 457.632202f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "raiden_ztk", 2007457, 7741260, 4, { 1.700844f, 50.002331f, 457.632202f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "av_dark_puddle", 2009673, 0, 4, { -172.344406f, 81.999977f, 331.537994f }, 1.000000f, 0.000000f );
    // instance.registerEObj( "av_light_puddle", 2009674, 0, 4, { -169.445297f, 81.999969f, 335.805695f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "bigtrap", 2009728, 0, 4, { 0.167785f, -46.000000f, 870.389771f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "smalltrap", 2009730, 0, 4, { 2.853394f, -46.000000f, 870.206726f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "portal", 2009729, 0, 4, { -2.578857f, -46.000000f, 870.267883f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "ice_portal", 2007457, 7829944, 4, { -224.003906f, 47.999989f, 428.517914f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "water_portal", 2007457, 7829713, 4, { -224.003799f, 47.999950f, 488.586304f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "light_portal", 2007457, 7829943, 4, { -160.018906f, 47.999809f, 428.297485f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "wind_portal", 2007457, 7829936, 4, { -160.018005f, 47.999870f, 490.249390f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "fire_portal", 2007457, 7829941, 4, { -95.944267f, 48.000111f, 425.855713f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "earth_portal", 2007457, 7829937, 4, { -95.985802f, 48.000111f, 489.578186f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "ice_gate_collision", 2007457, 7785080, 4, { -223.919098f, 48.999889f, 450.162415f }, 1.000000f, 0.000000f ); // CLOSED BY DEFAULT
    // instance.registerEObj( "water_gate_collision", 2007457, 7785077, 4, { -223.968994f, 48.999859f, 465.901489f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "light_gate_collision", 2007457, 7785078, 4, { -160.043701f, 49.000469f, 450.096497f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "wind_gate_collision", 2007457, 7785076, 4, { -159.954895f, 49.000469f, 465.859406f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "fire_gate_collision", 2007457, 7785079, 4, { -95.963966f, 48.996689f, 450.156403f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "earth_gate_collision", 2007457, 7785075, 4, { -95.994591f, 48.996700f, 465.842712f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "door1left_collision", 2007457, 7788873, 4, { -128.953903f, -6.912369f, 685.786377f }, 0.991760f, 0.000048f ); // CLOSED BY DEFAULT
    instance.registerEObj( "door1right_collision", 2007457, 7788874, 4, { 128.984299f, -6.820808f, 686.304871f }, 0.991760f, 0.000048f ); // CLOSED BY DEFAULT
    instance.registerEObj( "door2_collision", 2007457, 7788876, 4, { -0.137373f, 48.142220f, 523.887878f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "door3_collision", 2007457, 7788878, 4, { 60.501949f, 48.874641f, 458.060394f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "door4_collision", 2007457, 7830050, 4, { 111.802696f, 80.979607f, 348.622803f }, 0.991760f, 0.000048f );
    // instance.registerEObj( "door5_collision", 2007457, 7788879, 4, { -60.624149f, 48.783070f, 457.938385f }, 0.991760f, 0.000048f ); // UNUSED
    instance.registerEObj( "door6_collision", 2007457, 7788880, 4, { -175.036301f, 80.979607f, 253.559097f }, 0.991760f, 0.000048f ); // REMAINS CLOSED
    // instance.registerEObj( "doorozma_collision", 2007457, 7788882, 4, { -16.647579f, 108.995102f, 108.171097f }, 0.991760f, 0.000048f ); // UNUSED
    // instance.registerEObj( "raiden_path", 2007457, 7844636, 4, { -38.071289f, 50.034302f, 457.968994f }, 0.991760f, 0.000048f ); // UNUSED

    //! RP Altered eobjs
    instance.registerEObj( "Leatherboundjournal", 2005180, 0, 4, { 10.215350f, -46.000000f, 888.765320f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "Leatherboundjournal_1", 2005180, 0, 4, { -10.306930f, -46.000000f, 888.765320f }, 0.991760f, 0.500048f ); 
    instance.registerEObj( "Leatherboundjournal_2", 2005180, 0, 4, { 132.798294f, -15.999980f, 860.287476f }, 0.991760f, 0.785458f ); 
    instance.registerEObj( "Leatherboundjournal_3", 2005180, 0, 4, { -132.577606f, -16.000031f, 860.005371f }, 0.991760f, 0.785458f ); 


    //! RP Added eobjs
    // Hydatos
    // instance.registerEObj( "bluportal", 2009726, 0, 4, { 130.152f, 497.825f, -19.8034f }, 1.000000f, -0.180925f ); 
    instance.registerEObj( "redportal", 2009727, 0, 4, { 130.152f, 497.825f, -19.8034f }, 1.000000f, -0.180925f ); 
    // BA
    // Entrance
    instance.registerEObj( "redportal2", 2009727, 0, 4, { 0.0360257f, -45.9304f, 854.846f }, 1.000000f, 0.022356f ); 
    instance.registerEObj( "barrier1", 2002735, 0, 4, { 17.8324f, -46.0f, 862.874f }, 1.500000f, 1.15027f ); 
    instance.registerEObj( "barrier2", 2002735, 0, 4, { -17.8324f, -46.0f, 862.874f }, 1.500000f, -1.15027f); 
    instance.registerEObj( "barrier3", 2002735, 0, 4, { 17.8324f, -46.0f, 893.874f }, 1.500000f, -1.15027f ); 
    instance.registerEObj( "barrier4", 2002735, 0, 4, { -17.8324f, -46.0f, 893.874f }, 1.500000f, 1.15027f ); 
    instance.registerEObj( "shiny1", 2009481, 0, 1, { 17.8324f, -46.0f, 862.874f }, 2.000000f, 1.15027f ); 
    instance.registerEObj( "shiny2", 2009481, 0, 4, { 19.1835f, -46.0f, 859.856f }, 2.000000f, -1.15027f ); 
    instance.registerEObj( "shiny3", 2009481, 0, 4, { 16.4835f, -46.0f, 866.0f }, 2.000000f, -1.15027f ); 
    instance.registerEObj( "shiny4", 2009481, 0, 4, { -17.8324f, -46.0f, 862.874f }, 2.000000f, 1.15027f ); 
    instance.registerEObj( "shiny5", 2009481, 0, 4, { -19.1835f, -46.0f, 859.856f }, 2.000000f, -1.15027f ); 
    instance.registerEObj( "shiny6", 2009481, 0, 4, { -16.4835f, -46.0f, 866.0f }, 2.000000f, -1.15027f ); 
    instance.registerEObj( "shiny7", 2009481, 0, 4, { 17.8324f, -46.0f, 893.874f }, 2.000000f, 1.15027f ); 
    instance.registerEObj( "shiny8", 2009481, 0, 4, { 16.4835f, -46.0f, 890.856f }, 2.000000f, -1.15027f ); 
    instance.registerEObj( "shiny9", 2009481, 0, 4, { 19.1835f, -46.0f, 897.314f }, 2.000000f, -1.15027f ); 
    instance.registerEObj( "shiny10", 2009481, 0, 4, { -17.8324f, -46.0f, 893.874f }, 2.000000f, 1.15027f ); 
    instance.registerEObj( "shiny11", 2009481, 0, 4, { -16.4835f, -46.0f, 890.856f }, 2.000000f, -1.15027f ); 
    instance.registerEObj( "shiny12", 2009481, 0, 4, { -19.1835f, -46.0f, 897.314f }, 2.000000f, -1.15027f ); 
    instance.registerEObj( "Leatherboundjournal_4", 2005180, 0, 4, { 1.8686f, -46.0f, 870.188f }, 0.991760f, 0.377131f ); 
    // Shin-Zantetsuken and Lance of Virtue Containment Units
    instance.registerEObj( "journalztk", 2005180, 0, 4, { -2.05479f, 50.0023f, 451.499f }, 1.000000f, 0.0175188f ); 
    instance.registerEObj( "timegate1", 2007468, 0, 4, { -19.7907f, 50.0768f, 477.796f }, 1.000000f, 0.0175188f ); 
    instance.registerEObj( "timegate2", 2007468, 0, 4, { 19.7907f, 50.0768f, 438.155f }, 1.000000f, 0.0175188f ); 

    instance.registerEObj( "baportal1", 2009726, 0, 4, { -159.044f, 82.0f, 298.113f }, 1.000000f, -0.738496f ); 
    instance.registerEObj( "baportal2", 2009726, 0, 4, { -159.044f, 82.0f, 329.806f }, 1.000000f, -2.33055f ); 
    instance.registerEObj( "baportal3", 2009726, 0, 4, { -190.799f, 82.0f, 298.324f }, 1.000000f, 0.815023f ); 
    instance.registerEObj( "baportal4", 2009726, 0, 4, { -190.799f, 82.0f, 329.802f }, 1.000000f, 2.34205f ); 
    instance.registerEObj( "baportal5", 2009726, 0, 4, { -200.014f, 82.0f, 313.802f }, 1.000000f, 1.5689f ); 
    instance.registerEObj( "redportal3", 2009727, 0, 4, { -159.044f, 82.0f, 329.806f }, 1.000000f, -2.33055f ); 
    instance.registerEObj( "redportal4", 2009727, 0, 4, { -190.799f, 82.0f, 298.324f }, 1.000000f, 0.815023f ); 
    instance.registerEObj( "redportal5", 2009727, 0, 4, { -200.014f, 82.0f, 313.802f }, 1.000000f, 1.5689f ); 

    instance.registerEObj( "tornpage", 2005180, 0, 4, { -288.963f, 72.0026f, 310.485f }, 1.000000f, 0.125707f ); 
    // Small Rooms
    instance.registerEObj( "key", 2007282, 0, 4, { -14.0436f, 80.2856f, 267.978f }, 1.000000f, -0.699677f ); // clé dans chambre anju
    instance.registerEObj( "scatteredtomes", 2009689, 0, 4, { 34.164f, 80.0001f, 355.328f }, 1.000000f, 2.14483f ); 
    instance.registerEObj( "scatteredtomes2", 2009689, 0, 4, { 39.8161f, 80.0f, 358.031f }, 1.000000f, -3.12194f ); 
    // Board Room
    instance.registerEObj( "fuck_off_krile", 2002558, 0, 4, { -61.3397f, -56.0487f, 823.553f }, 1.750f, -2.35f ); 
    instance.registerEObj( "baportal6", 2009726, 0, 4, { -64.019f, -56.0487f, 832.019f }, 1.000000f, 2.33615f ); 
    instance.registerEObj( "redportal6", 2009727, 0, 4, { -64.019f, -56.0487f, 832.019f }, 1.000000f, 2.33615f ); 
    instance.registerEObj( "scatteredtomes3", 2009689, 0, 4, { -45.4946f, -56.0487f, 842.088f }, 1.000000f, -2.99084f ); 
    instance.registerEObj( "journal", 2005896, 0, 4, { -58.5239f, -55.175f, 835.819f }, 1.000000f, 2.80342f ); 
    instance.registerEObj( "portal_to_bridge", 2009726, 0, 4, { 0.0f, -60.0f, 688.011f }, 1.000000f, -0.0275064f ); 
    instance.registerEObj( "red_portal_to_bridge", 2009727, 0, 4, { 0.0f, -60.0f, 688.011f }, 1.000000f, -0.0275064f ); 
    // Bridge
    instance.registerEObj( "redportal7", 2009727, 0, 4, { 50.0519f, 590.0f, 543.245f }, 1.000000f, -0.00342321f ); 




  }

  void onUpdate( PublicContent& instance, uint32_t currTime ) override
  {

  }

  void onEnterTerritory( PublicContent& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {

  }

};

EXPOSE_SCRIPT( TheForbiddenLandEurekaHydatos );