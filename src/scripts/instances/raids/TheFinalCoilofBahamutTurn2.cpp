#include <ScriptObject.h>
#include <Territory/InstanceContent.h>

using namespace Sapphire;

class TheFinalCoilofBahamutTurn2 :
  public Sapphire::ScriptAPI::InstanceContentScript
{
public:
  TheFinalCoilofBahamutTurn2() :
    Sapphire::ScriptAPI::InstanceContentScript( 30017 )
  { }

  void onInit( InstanceContent& instance ) override
  {
    instance.registerEObj( "unknown_0", 2004618, 0, 4, { 8.377602f, -4.963000f, 2.130980f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_w1b2_b0338", 2004622, 5004388, 4, { 0.000000f, -4.963000f, 0.000000f }, 1.000000f, 0.000000f ); 
    // States -> brr_off (id: 2) brr_on2off (id: 3) brr_on (id: 4) brr_off2on (id: 5) 
    instance.registerEObj( "unknown_1", 2004138, 4985190, 4, { 3.028988f, -85.357613f, 329.862915f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "Shortcut", 2000700, 0, 4, { -8.983331f, -89.405617f, 340.705505f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "Entrance", 2000182, 4895376, 5, { -2.304138f, -95.841980f, 373.883514f }, 0.991760f, 0.000048f ); 
    // States -> vf_lock_on (id: 11) vf_lock_of (id: 12) 
    instance.registerEObj( "unknown_2", 2004138, 4772070, 4, { -3.471196f, -85.362328f, 329.862915f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_3", 2004138, 0, 4, { 3.028988f, -85.357613f, 329.862915f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_4", 2004138, 4772073, 4, { 82.671562f, 89.558182f, 312.686188f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_5", 2004138, 4772071, 4, { -87.694283f, 61.779518f, 322.880798f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_6", 2004138, 4772074, 4, { 68.781647f, 74.135750f, 257.001312f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_7", 2004138, 4772072, 4, { -71.265640f, 50.681782f, 262.029907f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_8", 2004138, 0, 4, { 3.045514f, -50.605240f, 198.785202f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_9", 2004131, 4772088, 4, { -0.320496f, -61.905880f, 240.100693f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_10", 2004131, 4772089, 4, { -0.150618f, -58.926769f, 229.063507f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_11", 2004130, 4903493, 4, { 0.167786f, -56.382141f, 216.998505f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_12", 2004138, 4772084, 4, { 5.588670f, -50.254120f, 198.785202f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_13", 2004138, 4985729, 4, { -1.068177f, -50.250832f, 198.785202f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_14", 2004138, 4772077, 4, { 93.772713f, 2.760812f, 164.237198f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_15", 2004138, 4772078, 4, { 62.832458f, 2.703932f, 109.635002f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_16", 2004138, 4772079, 4, { -101.804497f, -15.054380f, 174.336105f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_17", 2004138, 4772080, 4, { -68.094177f, -9.272421f, 114.627701f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_18", 2004131, 4772085, 4, { -33.952530f, 1.069616f, 57.437080f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_19", 2004131, 4772087, 4, { 34.497631f, 1.062853f, 57.576210f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_20", 2004130, 4903494, 4, { -18.231251f, 0.578985f, 63.141258f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_21", 2004130, 4903495, 4, { 18.776350f, 0.578991f, 63.349949f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_22", 2004138, 4772081, 4, { 0.088281f, 0.909978f, 67.335487f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "unknown_23", 2004138, 4772082, 4, { -66.984283f, 1.029588f, -0.043371f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_24", 2004138, 4772083, 4, { 67.627632f, 1.029588f, -0.043371f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_25", 2002735, 0, 4, { 0.046454f, 0.339829f, 55.289249f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118", 2002872, 4896001, 4, { -0.021759f, 0.578989f, 57.955990f }, 1.000000f, 0.000000f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "Allaganterminal", 2004142, 4797408, 8, { 0.001913f, -4.224863f, -30.000130f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgpl_w_lvd_colwithnavi", 2004137, 4895798, 4, { -0.366558f, -4.738363f, -24.911970f }, 1.000000f, 0.000000f ); 

    //! RP Renamed eobjs
    // instance.registerEObj( "bumper1r", 2004138, 4985190, 4, { 3.028988f, -85.357613f, 329.862915f }, 0.991760f, 0.000048f );
    // instance.registerEObj( "bumper1l", 2004138, 4772070, 4, { -3.471196f, -85.362328f, 329.862915f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "bumper2r", 2004138, 4772074, 4, { 68.781647f, 74.135750f, 257.001312f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "bumper2l", 2004138, 4772072, 4, { -71.265640f, 50.681782f, 262.029907f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "grpswitch1", 2004131, 4772088, 4, { -0.320496f, -61.905880f, 240.100693f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "grpswitch2", 2004131, 4772089, 4, { -0.150618f, -58.926769f, 229.063507f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "deathwall1", 2004130, 4903493, 1, { 0.167786f, -56.382141f, 216.998505f }, 0.991760f, 0.000048f ); 
    // instance.registerEObj( "bumper3r", 2004138, 4772084, 4, { 5.588670f, -50.254120f, 198.785202f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "bumper3l", 2004138, 4985729, 4, { -1.068177f, -50.250832f, 198.785202f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "bumper4r", 2004138, 4772078, 4, { 62.832458f, 2.703932f, 109.635002f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "grpswitchleft", 2004131, 4772085, 4, { -33.952530f, 1.069616f, 57.437080f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "grpswitchright", 2004131, 4772087, 4, { 34.497631f, 1.062853f, 57.576210f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "deathwallleft", 2004130, 4903494, 4, { -18.231251f, 0.578985f, 63.141258f }, 1.000000f, 0.000000f ); 
    // instance.registerEObj( "deathwallright", 2004130, 4903495, 4, { 18.776350f, 0.578991f, 63.349949f }, 1.000000f, 0.000000f ); 


    //! RP Added eobjs
    // instance.registerEObj( "magitekdevice", 2000116, 0, 4, { -9.0939f, -95.8329f, 371.464f }, 0.991760f, 1.05987f ); 
    // instance.registerEObj( "bottles", 2009745, 0, 4, { -9.7734f, -95.833f, 375.179f }, 0.991760f, 2.12519f ); 
    // instance.registerEObj( "scatteredtomes", 2009689, 0, 4, { -10.45f, -95.833f, 373.849f }, 1.000000f, 1.54399f ); 
    // instance.registerEObj( "baportal", 2009726, 0, 4, { -4.4316f, 0.716916f, 73.4935f }, 1.000000f, 3.05495f ); 
    // instance.registerEObj( "Exit", 2000139, 0, 4, { 4.4316f, 0.716916f, 73.4935f }, 1.000000f, -3.13671f ); 
    // instance.registerEObj( "journal1", 2005180, 0, 4, { 57.3137f, 0.578998f, 15.3749f }, 1.000000f, -1.25726f ); 
    // instance.registerEObj( "journal2", 2005180, 0, 4, { -49.2352f, 0.578998f, 47.9359f }, 1.000000f, -0.240959f ); 
    // instance.registerEObj( "journal3", 2005180, 0, 4, { -6.48619f, 0.578998f, 60.1023f }, 1.000000f, -1.66932f ); 
    // instance.registerEObj( "bombs1", 2009696, 0, 4, { 101.371f, 2.14994f, 161.703f }, 1.000000f, -2.14853f ); 
    // instance.registerEObj( "bombs2", 2009696, 0, 4, { 90.9342f, 2.14994f, 170.702f }, 1.000000f, 2.73529f ); 
    // instance.registerEObj( "bombs3", 2009696, 0, 4, { 54.7857f, 2.14994f, 110.573f }, 1.000000f, 0.835669f ); 
    // instance.registerEObj( "bombs4", 2009696, 0, 4, { -69.2446f, 48.7749f, 255.001f }, 1.000000f, -0.2508f ); 
    // instance.registerEObj( "bombs5", 2009696, 0, 4, { -96.9974f, 61.8202f, 324.027f }, 1.000000f, 2.10999f ); 

  }

  void onUpdate( InstanceContent& instance, uint64_t tickCount ) override
  {

  }

  void onEnterTerritory( InstanceContent& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {

  }

};

EXPOSE_SCRIPT( TheFinalCoilofBahamutTurn2 );