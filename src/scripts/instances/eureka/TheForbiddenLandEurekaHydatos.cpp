#include <ScriptObject.h>
#include <Territory/PublicContent.h>
#include <Actor/Player.h>

using namespace Sapphire;

class TheForbiddenLandEurekaHydatos : public Sapphire::ScriptAPI::PublicContentScript
{
public:
  TheForbiddenLandEurekaHydatos() : Sapphire::ScriptAPI::PublicContentScript( 639 )
  { }

  void onPlayerSetup( Sapphire::PublicContent& instance, Entity::Player& player )
  {
    player.mount( 119 );
    player.getCurrentZone()->setWeatherOverride( static_cast< Common::Weather >( 10 ) );
    player.setRot( 1.96528 );
    player.setPos( { -991.284f, 580f, -69.2263f } );
  }

  void onInit( PublicContent& instance ) override
  {
    instance.registerEObj( "unknown_0", 2002735, 0, 4, { -128.923492f, -10.070720f, 777.984375f }, 0.950000f, 0.000048f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118", 2007457, 7763762, 4, { -128.923492f, -10.067880f, 776.580627f }, 1.296936f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "sgvf_w_lvd_b0118_1", 2007457, 7763679, 4, { -128.099503f, -10.068410f, 719.199524f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "unknown_1", 2007457, 7768488, 4, { -134.917297f, -10.010040f, 750.439819f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_2", 2002735, 0, 4, { 128.770905f, -10.060530f, 778.620728f }, 0.950000f, 0.000048f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118_2", 2007457, 7763699, 4, { 129.411697f, -10.071260f, 776.331726f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "sgvf_w_lvd_b0118_3", 2007457, 7763700, 4, { 129.411697f, -10.070450f, 720.071106f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "unknown_3", 2002735, 0, 4, { -0.015320f, 50.055561f, 493.475586f }, 0.950000f, 0.000048f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118_4", 2007457, 7741189, 4, { 0.512825f, 50.009800f, 495.219513f }, 1.000000f, 0.000000f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "sgvf_w_lvd_b0118_5", 2007457, 7741190, 4, { 36.618351f, 50.055470f, 458.152008f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "unknown_4", 2007457, 7745394, 4, { -1.825981f, 50.002331f, 457.632202f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3fd_b1605", 2007457, 7741260, 4, { 1.700844f, 50.002331f, 457.632202f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_5", 2002735, 0, 4, { -143.963501f, 82.207230f, 314.100403f }, 0.950000f, -1.570451f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118_6", 2007457, 7735681, 4, { -143.052795f, 82.207237f, 313.649200f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "sgvf_w_lvd_b0118_7", 2007457, 7735697, 4, { -175.127808f, 82.200317f, 280.994904f }, 0.991760f, 0.000048f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "unknown_6", 2009673, 0, 4, { -172.344406f, 81.999977f, 331.537994f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_7", 2009674, 0, 4, { -169.445297f, 81.999969f, 335.805695f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3r1_b1274", 2007457, 7739401, 4, { -162.300003f, 81.999977f, 301.299988f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3r1_b1274_1", 2007457, 7739403, 4, { -160.800003f, 81.999977f, 293.500000f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3r1_b1274_2", 2007457, 7739404, 4, { -154.500000f, 81.999977f, 299.600006f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3r1_b1274_3", 2007457, 7739405, 4, { -187.750305f, 81.999977f, 326.700012f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3r1_b1274_4", 2007457, 7739406, 4, { -189.399994f, 81.999977f, 334.399994f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3r1_b1274_5", 2007457, 7739407, 4, { -195.600296f, 81.999977f, 328.299988f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3r1_b1274_6", 2007457, 7739408, 4, { -162.300293f, 81.999969f, 326.600006f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3r1_b1274_7", 2007457, 7739409, 4, { -154.600296f, 81.999969f, 328.200012f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3r1_b1274_8", 2007457, 7739410, 4, { -160.600006f, 81.999969f, 334.500000f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3r1_b1274_9", 2007457, 7739411, 4, { -187.699997f, 81.999977f, 301.299988f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3r1_b1274_10", 2007457, 7739412, 4, { -195.500000f, 81.999977f, 299.799988f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3r1_b1274_11", 2007457, 7739413, 4, { -189.399994f, 81.999977f, 293.600006f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_8", 2002735, 0, 4, { -17.249100f, 107.999802f, 91.095901f }, 1.250000f, 0.000000f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118_8", 2007457, 7741873, 4, { -17.065720f, 107.999802f, 93.406097f }, 1.000000f, 0.000000f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "sgbg_z3fd_u1_swch1", 2007457, 7740736, 4, { -16.850000f, 93.073082f, 6.992088f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgbg_z3fd_u1_swch1_1", 2007457, 7740728, 4, { 4.200000f, 93.124687f, 16.750000f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgbg_z3fd_u1_swch1_2", 2007457, 7740735, 4, { 1.430000f, 93.073112f, 41.492088f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgbg_z3fd_u1_swch1_3", 2007457, 7740715, 4, { -17.049999f, 93.124702f, 53.500000f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgbg_z3fd_u1_swch1_4", 2007457, 7740733, 4, { -36.349998f, 93.040756f, 39.492088f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgbg_z3fd_u1_swch1_5", 2007457, 7740731, 4, { -38.250000f, 92.990501f, 16.750000f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_9", 2007457, 7770797, 4, { -16.877850f, 93.000000f, 44.238171f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3fd_b1561", 2007457, 7852653, 4, { -17.000000f, 107.999802f, 96.000000f }, 1.000000f, -0.000000f ); 
    instance.registerEObj( "sgvf_z3fd_b1553", 2007457, 7829944, 4, { -224.003906f, 47.999989f, 428.517914f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3fd_b1553_1", 2007457, 7829713, 4, { -224.003799f, 47.999950f, 488.586304f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3fd_b1553_2", 2007457, 7829943, 4, { -160.018906f, 47.999809f, 428.297485f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3fd_b1553_3", 2007457, 7829936, 4, { -160.018005f, 47.999870f, 490.249390f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3fd_b1553_4", 2007457, 7829941, 4, { -95.944267f, 48.000111f, 425.855713f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_z3fd_b1553_5", 2007457, 7829937, 4, { -95.985802f, 48.000111f, 489.578186f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_10", 2009728, 0, 4, { 0.167785f, -46.000000f, 870.389771f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_11", 2009729, 0, 4, { -2.578857f, -46.000000f, 870.267883f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_12", 2009730, 0, 4, { 2.853394f, -46.000000f, 870.206726f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "Headquartersentrance", 2009750, 0, 4, { 125.711800f, 500.150909f, 2.250822f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "Shortcut", 2000700, 0, 4, { -0.076182f, -46.000000f, 888.669983f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_13", 2007457, 7785080, 4, { -223.919098f, 48.999889f, 450.162415f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_14", 2007457, 7785077, 4, { -223.968994f, 48.999859f, 465.901489f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_15", 2007457, 7785078, 4, { -160.043701f, 49.000469f, 450.096497f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_16", 2007457, 7785076, 4, { -159.954895f, 49.000469f, 465.859406f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_17", 2007457, 7785079, 4, { -95.963966f, 48.996689f, 450.156403f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_18", 2007457, 7785075, 4, { -95.994591f, 48.996700f, 465.842712f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_19", 2007457, 7788873, 4, { -128.953903f, -6.912369f, 685.786377f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_20", 2007457, 7788874, 4, { 128.984299f, -6.820808f, 686.304871f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_21", 2007457, 7788876, 4, { -0.137373f, 48.142220f, 523.887878f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_22", 2007457, 7788879, 4, { -60.624149f, 48.783070f, 457.938385f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_23", 2007457, 7788878, 4, { 60.501949f, 48.874641f, 458.060394f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_24", 2007457, 7788880, 4, { -175.036301f, 80.979607f, 253.559097f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_25", 2007457, 7788882, 4, { -16.647579f, 108.995102f, 108.171097f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_26", 2007457, 7830050, 4, { 111.802696f, 80.979607f, 348.622803f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_27", 2007457, 7830083, 4, { -55.840881f, -45.000000f, 878.989624f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_28", 2007457, 7830084, 4, { 56.259121f, -45.000000f, 878.989624f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "Leatherboundjournal", 2009731, 0, 4, { 10.215350f, -46.000000f, 868.765320f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "Leatherboundjournal_1", 2009732, 0, 4, { -10.306930f, -46.000000f, 868.765320f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "Leatherboundjournal_2", 2009733, 0, 4, { 132.798294f, -15.999980f, 860.287476f }, 0.991760f, 0.785458f ); 
    instance.registerEObj( "Leatherboundjournal_3", 2009734, 0, 4, { -132.577606f, -16.000031f, 860.005371f }, 0.991760f, 0.785458f ); 
    instance.registerEObj( "Exit", 2009753, 0, 4, { -17.135990f, 92.990494f, 44.998779f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_29", 2007457, 7844636, 4, { -38.071289f, 50.034302f, 457.968994f }, 0.991760f, 0.000048f ); 

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