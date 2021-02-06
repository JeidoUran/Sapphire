#include <ScriptObject.h>
#include "Actor/EventObject.h"
#include <Territory/InstanceContent.h>
#include <Actor/Player.h>


using namespace Sapphire;

class TheLabyrinthoftheAncients :
  public Sapphire::ScriptAPI::InstanceContentScript
{
public:
  TheLabyrinthoftheAncients() :
    Sapphire::ScriptAPI::InstanceContentScript( 30001 )
  { }

  void onInit( InstanceContent& instance ) override
  {
    instance.registerEObj( "unknown_0", 2002108, 0, 4, { -109.946503f, 44.168140f, -165.619995f }, 0.991760f, 0.000048f ); 

    // States -> vf_lock_on (id: 11) vf_lock_of (id: 12) 
    instance.registerEObj( "Allaganteleporter", 2001023, 3445281, 4, { -117.450104f, 45.942120f, 317.195892f }, 0.778198f, 0.000048f ); 
    instance.registerEObj( "sgvf_w_lvd_b0294", 2002793, 4493308, 4, { -148.301498f, 48.301128f, 279.915802f }, 1.000000f, 0.000000f ); 
    // States -> barrier_2loop (id: 3) barrier_stop (id: 4) barrier_loop (id: 10) barrier_2stop (id: 11) 
    instance.registerEObj( "sgvf_w_lvd_b0294_1", 2002794, 4493309, 4, { -109.977203f, 48.251709f, 243.024094f }, 0.991760f, 0.000048f ); 
    // States -> barrier_2loop (id: 3) barrier_stop (id: 4) barrier_loop (id: 10) barrier_2stop (id: 11) 
    instance.registerEObj( "sgvf_w_lvd_b0294_2", 2002795, 4493310, 4, { -71.722931f, 48.301121f, 280.086487f }, 1.000000f, 0.000000f ); 
    // States -> barrier_2loop (id: 3) barrier_stop (id: 4) barrier_loop (id: 10) barrier_2stop (id: 11) 
    instance.registerEObj( "unknown_1", 2001024, 4199521, 4, { -451.214386f, 41.580811f, 182.050903f }, 1.000000f, 0.000048f ); 
    instance.registerEObj( "sgpl_l1r1_boss1wall", 2001025, 4303928, 4, { -451.373688f, 24.800070f, 73.862427f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "unknown_2", 2001026, 0, 4, { -451.305206f, 24.873600f, 73.806000f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_3", 2002798, 0, 4, { -355.665405f, 41.884102f, 279.420288f }, 1.550000f, -1.570796f ); 
    instance.registerEObj( "sgvf_w_lvd_b0250", 2002801, 4478011, 4, { -346.181488f, 42.801510f, 279.988708f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "unknown_4", 2002799, 0, 4, { -415.959198f, 42.400002f, 280.898804f }, 1.550000f, -1.570796f ); 
    instance.registerEObj( "sgvf_w_lvd_b0250_1", 2002802, 4478013, 4, { -415.761597f, 42.400002f, 279.982788f }, 1.000000f, 0.000000f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "unknown_5", 2002800, 0, 4, { -452.406799f, 42.400002f, 239.395096f }, 1.550000f, 0.000000f ); 
    instance.registerEObj( "sgvf_w_lvd_b0250_2", 2002803, 4478015, 4, { -451.081909f, 41.580811f, 243.305099f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "sgvf_w_lvd_b0269", 2002839, 4493435, 4, { -413.650909f, 42.000000f, 279.285889f }, 0.991760f, 0.000048f ); 
    // States -> barrier_2loop (id: 3) barrier_stop (id: 4) barrier_loop (id: 10) barrier_2stop (id: 11) 
    instance.registerEObj( "sgvf_w_lvd_b0269_1", 2002840, 4493436, 4, { -450.220612f, 41.580811f, 247.690399f }, 0.991760f, 0.000048f ); 
    // States -> barrier_2loop (id: 3) barrier_stop (id: 4) barrier_loop (id: 10) barrier_2stop (id: 11) 
    instance.registerEObj( "Allaganteleporter_1", 2002807, 3445282, 4, { -301.062592f, 54.375320f, 290.201904f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "Allaganteleporter_2", 2002808, 3974161, 4, { -457.203400f, 38.418018f, 104.051903f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "Shortcut", 2002804, 0, 4, { -451.176910f, 25.504910f, 18.912251f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgpl_l1r1_trash2wall", 2001027, 4304910, 4, { 191.423996f, 51.658699f, 280.097992f }, 0.400000f, 0.000000f ); 
    // States -> on (id: 20) off (id: 21) 
    instance.registerEObj( "sgpl_l1r1_trash2line", 2001028, 4304912, 4, { 191.145798f, 51.767059f, 279.359497f }, 0.400000f, 0.000000f ); 
    instance.registerEObj( "unknown_6", 2001032, 0, 4, { 409.496094f, 66.240303f, 280.004395f }, 0.800000f, -1.570451f ); 
    instance.registerEObj( "sgpl_l1r1_boss2wall", 2001031, 4304071, 4, { 438.027588f, 69.382690f, 281.602203f }, 0.778198f, -1.570451f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "Allaganteleporter_3", 2002809, 3445284, 4, { 115.688499f, 65.110123f, 280.018311f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "unknown_7", 2002813, 4199883, 4, { 253.669495f, 51.066391f, 244.695007f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_8", 2002814, 4199882, 4, { 253.676102f, 51.066399f, 279.965607f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_9", 2002815, 4199881, 4, { 253.683899f, 51.066360f, 315.213013f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_10", 2002816, 4199880, 4, { 213.707596f, 51.052799f, 244.895493f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_11", 2002817, 4199878, 4, { 213.688202f, 51.052799f, 280.125214f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "unknown_12", 2002818, 4199879, 4, { 213.723404f, 51.052799f, 315.105286f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "Allaganteleporter_4", 2002810, 3974166, 4, { 349.215515f, 60.567490f, 268.536591f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "Shortcut_1", 2002805, 0, 4, { 455.122894f, 66.249268f, 279.987701f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_13", 2001030, 4199894, 4, { 264.739899f, 50.679981f, 279.921509f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgpl_l1r1_boss3wall", 2001033, 4305031, 4, { -110.210899f, 44.083248f, -116.227997f }, 0.381470f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "unknown_14", 2001034, 0, 4, { -110.254898f, 44.168098f, -111.387901f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_15", 2001035, 4317566, 4, { -110.054497f, 46.072929f, -214.578705f }, 0.400000f, 0.000000f ); 
    instance.registerEObj( "sgpl_l1r1_boss3wall_1", 2001036, 4305191, 4, { -111.224899f, 67.886620f, -344.147797f }, 0.400000f, 0.000000f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "unknown_16", 2001037, 0, 4, { -109.930298f, 67.892403f, -338.731415f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "Energytowerconsole", 2001038, 0, 4, { -85.032784f, 70.241432f, -343.493713f }, 0.800000f, 1.570451f ); 
    // instance.registerEObj( "Energytowerconsole_1", 2001039, 0, 4, { -85.044861f, 70.240898f, -393.307587f }, 0.800000f, 0.000000f ); 
    // instance.registerEObj( "Energytowerconsole_2", 2001040, 0, 4, { -134.983994f, 70.240898f, -343.431213f }, 0.800000f, 0.000000f ); 
    // instance.registerEObj( "Energytowerconsole_3", 2001041, 0, 4, { -134.925201f, 70.240898f, -393.378296f }, 0.800000f, -1.570451f ); 
    instance.registerEObj( "Allaganteleporter_5", 2002811, 3445283, 4, { -117.500000f, 39.417461f, -60.409302f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_17", 2002819, 4317548, 4, { -109.942200f, 44.168140f, -140.697403f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_18", 2002820, 4317564, 4, { -109.933800f, 44.168140f, -190.218903f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "Allaganteleporter_6", 2002812, 3974167, 4, { -117.461098f, 57.435680f, -288.075104f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "Shortcut_2", 2002806, 0, 4, { -109.976601f, 68.215019f, -378.115906f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_19", 2002821, 4407451, 4, { -110.134598f, 68.248489f, -367.669708f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "Allaganteleporter_7", 2002822, 4322323, 4, { -123.763496f, 650.608582f, 254.596695f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    //instance.registerEObj( "unknown_20", 2001043, 0, 4, { -110.052299f, 650.020020f, 227.514893f }, 0.800000f, 0.000048f ); 
    instance.registerEObj( "unknown_21", 2001044, 4497411, 4, { -109.941299f, 650.720886f, 194.445694f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_31", 2002837, 4478584, 4, { -89.563782f, 650.019226f, 209.632706f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_32", 2002838, 4478586, 4, { -131.352798f, 650.019226f, 210.327194f }, 1.000000f, 0.000000f ); 
    //instance.registerEObj( "Exit", 2000139, 0, 4, { -110.009903f, 650.972229f, 157.832199f }, 0.793408f, 0.000048f ); 

    //! RP Renamed eobjs
    instance.registerEObj( "platform1", 2002823, 4101871, 4, { -71.280701, 650.308350, 191.918152 }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "platform2", 2002824, 4101872, 4, { -109.887199f, 650.970886f, 207.029099f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "platform3", 2002825, 4101873, 4, { -132.905304f, 650.731018f, 191.279907f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "circle1", 2002826, 0, 4, { -78.160004f, 649.950125f, 206.024597f }, 0.800000f, -0.634151f ); 
    instance.registerEObj( "circle2", 2002832, 0, 4, { -85.569000f, 649.950125f, 213.420593f }, 0.800000f, -0.911137f ); 
    instance.registerEObj( "circle3", 2002833, 0, 4, { -94.658401f, 649.950125f, 218.672806f }, 0.800000f, -1.177247f ); 
    instance.registerEObj( "circle4", 2002834, 0, 4, { -125.350403f, 650.550125f, 218.672806f }, 0.800000f, -1.153363f ); 
    instance.registerEObj( "circle5", 2002835, 0, 4, { -134.429901f, 650.550125f, 213.420593f }, 0.800000f, -0.918754f ); 
    instance.registerEObj( "circle6", 2002836, 0, 4, { -141.827698f, 650.550125f, 206.024597f }, 0.800000f, -0.639576f ); 
    instance.registerEObj( "bosswall", 2002793, 4491496, 4, { -110.122498f, 650.015808f, 227.968597f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "arenabarrier", 2001029, 4499125, 4, { -109.987602f, 650.731018f, 181.576202f }, 1.000000f, 0.000000f ); 

    //! RP Altered eobjs
    instance.registerEObj( "Entrance", 2000182, 4317322, 5, { -110.032799f, 11.600000f, 850.444763f }, 0.991760f,  -1.57362f ); 

    //! RP Added eobjs
    //instance.registerEObj( "Shortcut", 2000700, 0, 4, { -101.470718f, 30.392542f, 416.210571f }, 0.991760f, 0.000144f ); 
    //instance.registerEObj( "portal", 2007181, 0, 4, { -110.032799f, 30.372690f, 417.614990f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "lever", 2007580, 0, 4, { -98.091141f, 48.370487f, 268.294373f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "lever2", 2007580, 0, 4, { -98.091141f, 648.716125f, 268.294373f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "switch1", 2008907, 0, 4, { -181.258392f, 690.415771f, 181.339722f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "switch2", 2008907, 0, 4, { -109.736443f, 690.556519f, 253.025848f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "switch3", 2008907, 0, 4, { -37.636600f, 690.598145f, 181.754272f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "platformhint1", 2006281, 0, 4, { -71.280701f, 650.308350f, 191.918152f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "platformhint2", 2006281, 0, 4, { -110.027336f, 650.308350f, 221.570938f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "platformhint3", 2006281, 0, 4, { -148.634933f, 650.308350f, 191.927551f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "circlehint1", 2006281, 0, 4, { -85.569000f, 649.940125f, 213.420593f }, 0.800000f, -0.911137f ); 
    instance.registerEObj( "circlehint2", 2006281, 0, 4, { -134.429901f, 649.940125f, 213.420593f }, 0.800000f, -0.918754f ); 
    instance.registerEObj( "puddle1", 2000680, 0, 4, { -71.280701f, 650.308350f, 191.918152f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "puddle2", 2000680, 0, 4, { -110.027336f, 650.304504f, 221.570938f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "puddle3", 2000680, 0, 4, { -148.634933f, 650.308350f, 191.927551f }, 1.000000f, 0.000000f ); 
    //instance.registerEObj( "test", 2002793, 4493308, 4, { 0.0f, 0.0f, 0.0f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "CTEntrance", 2011102, 0, 4, { -110.041481f, 700.410950f, -73.251411f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "crystal", 2003145, 0, 4, { -37.422192f, 51.373531f, 418.407288f }, 4.000000f, -1.04615f ); 
    instance.registerEObj( "crystal2", 2003145, 0, 4, { -182.863007f, 51.003531f, 418.407288f }, 4.000000f, 0.000000f ); 

  }

  void onUpdate( InstanceContent& instance, uint64_t tickCount ) override
  {

  }

  void onEnterTerritory( InstanceContent& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {

  }

  void onPlayerSetup( InstanceContent& instance, Entity::Player& player )
  {
    //! Setup 1st ADS
    if( player.getId() == 2097209 /* 2097155 */ )
    {
      player.setRot( -0.0466003 );
      player.setPos( { -110.027626f, 28.227448f, 502.090363f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 882 );
      player.setbNPCName( 2641 );
      player.setModelMainWeapon( 0x0000000000000000 );
      player.sendModel();
    }

    //! Setup 2nd ADS
    else if( player.getId() == 2097210 )
    {
      player.setRot( -0.00229883 );
      player.setPos( { -109.986702f, 650.928223f, 181.590897f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 882 );
      player.setbNPCName( 1468 );
      player.setModelMainWeapon( 0x0000000000000000 );
      player.sendModel();
    }

    //! Setup 1st Baby ADS
    else if( player.getId() == 2097211 )
    {
      player.setRot( 1.59457 );
      player.setPos( { -179.126953f, 690.415771f, 181.345612f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 882 );
      player.setbNPCName( 1472 );
      player.setModelMainWeapon( 0x0000000000000000 );
      player.sendModel();
      //player.setGmInvis( true );
    }

    //! Setup 2nd Baby ADS
    else if( player.getId() == 2097212 )
    {
      player.setRot( -3.12546 );
      player.setPos( { -109.680817f, 690.421692f, 249.161118f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 882 );
      player.setbNPCName( 2193 );
      player.setModelMainWeapon( 0x0000000000000000 );
      player.sendModel();
      //player.setGmInvis( true );
    }

    //! Setup 3rd Baby ADS
    else if( player.getId() == 2097213 )
    {
      player.setRot( -1.5888 );
      player.setPos( { -43.466114f, 690.216003f, 181.698944f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 882 );
      player.setbNPCName( 1471 );
      player.setModelMainWeapon( 0x0000000000000000 );
      player.sendModel();
      //player.setGmInvis( true );
    }

    //! Setup Medium ADS
    else if( player.getId() == 2097215 )
    {
      player.setRot( -3.12546 );
      player.setPos( { -109.680817f, 690.421692f, 249.161118f } );
      player.setModelType( 2 );
      player.setSubType( 5 );
      player.setEnemyType( 4 );
      player.setbNPCBase( 882 );
      player.setbNPCName( 2884 );
      player.setModelMainWeapon( 0x0000000000000000 );
      player.sendModel();
      //player.setGmInvis( true );
    }
  //! Setup eobjs

  instance.getEObjByName( "sgvf_w_lvd_b0294" )->setAnimationFlag( 0, 4 );
  instance.getEObjByName( "sgvf_w_lvd_b0294_2" )->setAnimationFlag( 0, 4 );
  }
};

EXPOSE_SCRIPT( TheLabyrinthoftheAncients );