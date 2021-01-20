#include <ScriptObject.h>
#include <Territory/InstanceContent.h>

using namespace Sapphire;

class TheCopiedFactory : public Sapphire::ScriptAPI::InstanceContentScript
{
public:
  TheCopiedFactory() : Sapphire::ScriptAPI::InstanceContentScript( 30087 )
  { }

  void onInit( InstanceContent& instance ) override
  {
    instance.registerEObj( "unknown_0", 2002735, 0, 4, { -500.062012f, 423.564301f, 21.562880f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118", 2007457, 8127876, 4, { -500.062012f, 423.962708f, 21.562880f }, 1.000000f, 0.000000f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "unknown_1", 2007457, 8156454, 4, { -501.201111f, 401.000000f, -30.586300f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_2", 2002735, 0, 4, { -702.927979f, 333.582306f, -288.686798f }, 0.991760f, -1.570451f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118_1", 2007457, 8127884, 4, { -702.927979f, 333.582306f, -288.686798f }, 1.000000f, -1.570451f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "unknown_3", 2007457, 8193582, 4, { -804.150330f, -2.569809f, -239.550797f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_4", 2002735, 0, 4, { 900.000000f, -673.015808f, 827.839600f }, 0.991760f, 0.000048f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118_2", 2007457, 8127740, 4, { 900.000000f, -673.015808f, 827.839600f }, 1.000000f, 0.000000f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "unknown_5", 2007457, 0, 4, { 902.487671f, -700.000000f, 675.391174f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_6", 2007457, 8143665, 4, { 899.043213f, -700.000000f, 763.735779f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_7", 2007457, 8196980, 4, { 900.000000f, -700.000000f, 698.575928f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_8", 2002735, 0, 4, { 900.000000f, -700.000122f, 457.747986f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118_3", 2007457, 8128002, 4, { 899.925293f, -700.000000f, 457.567688f }, 1.000000f, 0.000000f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "sgpl_w_lvd_collison_only", 2002618, 8513206, 4, { -500.053986f, 423.636597f, 19.335199f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "unknown_9", 2002735, 0, 4, { -606.236816f, 343.936005f, -287.000000f }, 0.991760f, -1.570451f ); 
    instance.registerEObj( "sgvf_w_lvd_b0118_4", 2007457, 8128069, 4, { -606.000916f, 343.936005f, -287.000000f }, 1.000000f, -1.570451f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "sgvf_w_lvd_b0118_5", 2007457, 8128084, 4, { -626.500000f, 348.117889f, -287.000000f }, 1.000000f, 0.000000f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "sgvf_w_lvd_b0118_6", 2007457, 8128099, 4, { -750.477173f, -495.990204f, 555.077393f }, 1.000000f, -1.570796f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "sgvf_w_lvd_b0118_7", 2007457, 8128100, 4, { -801.180176f, -495.990204f, 534.327271f }, 1.000000f, -0.759259f ); 
    // States -> vf_bextwall_on (id: 3) vf_bextwall_of (id: 4) 
    instance.registerEObj( "unknown_10", 2002735, 0, 4, { -750.062317f, -495.990204f, 555.077393f }, 1.000000f, -1.570796f ); 
    instance.registerEObj( "sgbg_w_qic_004_05a", 2007457, 8155632, 4, { -750.477173f, -495.990204f, 555.077393f }, 1.000000f, -1.570796f ); 
    instance.registerEObj( "Accesspoint", 2010799, 8145319, 4, { -494.069489f, 484.002686f, 242.592606f }, 1.000000f, 1.224958f ); 
    instance.registerEObj( "Accesspoint_1", 2010800, 8146573, 4, { -577.189270f, 352.994202f, -266.399994f }, 0.991760f, 1.417947f ); 
    instance.registerEObj( "Accesspoint_2", 2010801, 8142101, 4, { -678.453125f, 338.311005f, -329.828094f }, 0.991760f, 1.540283f ); 
    instance.registerEObj( "Accesspoint_3", 2010802, 8143950, 4, { -679.987793f, -482.902313f, 606.301880f }, 0.991760f, 1.506345f ); 
    instance.registerEObj( "Accesspoint_4", 2010803, 8143953, 4, { 903.335815f, -677.000000f, 904.332581f }, 1.000000f, 0.035768f ); 
    instance.registerEObj( "Accesspoint_5", 2010804, 8143955, 4, { 903.218323f, -701.000000f, 485.459412f }, 0.991760f, 0.144916f ); 
    instance.registerEObj( "Accesspoint_6", 2010839, 8196872, 4, { -507.031586f, 423.999390f, 78.642242f }, 1.000000f, 0.000000f ); 
    instance.registerEObj( "Entrance", 2000182, 8127769, 5, { -500.104187f, 484.002899f, 248.789597f }, 1.000000f, 0.000000f ); 
    // States -> vf_lock_on (id: 11) vf_lock_of (id: 12) 
    instance.registerEObj( "Exit", 2000139, 0, 4, { 900.000000f, -700.000122f, 403.452911f }, 0.991760f, 0.000048f ); 

  }

  void onUpdate( InstanceContent& instance, uint64_t tickCount ) override
  {

  }

  void onEnterTerritory( InstanceContent& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {

  }

};

EXPOSE_SCRIPT( TheCopiedFactory );