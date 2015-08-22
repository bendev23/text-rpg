#include "../game.h"

using namespace std;

int main ()
{
  int return_code = 0;
 
  World world;
  
  // create some locations:
  Location *location_pointer;
  LocationGroup *location_group_pointer;
  Humanoid *humanoid_pointer;
  HumanoidClass humanoid_class;
  humanoid_class.set_id(1);
  humanoid_class.set_name("just another humanoid");
  
  location_pointer = world.create_location();
  location_pointer->set_name("village");
  location_pointer->set_id(1);
  
  location_pointer = world.create_location();
  location_pointer->set_name("city");
  location_pointer->set_id(2);
  
  location_pointer = world.create_location();
  location_pointer->set_name("jungle");
  location_pointer->set_id(3);
  
  // create some location groups:
  location_group_pointer = world.create_location_group();
  location_group_pointer->set_name("island");
  location_group_pointer->set_id(1);
  
  location_group_pointer = world.create_location_group();
  location_group_pointer->set_name("east coast");
  location_group_pointer->set_id(2);
  
  location_group_pointer = world.create_location_group();
  location_group_pointer->set_name("west coast");
  location_group_pointer->set_id(3);
  
  // create some humanoids:
  humanoid_pointer = world.create_humanoid(&humanoid_class);
  humanoid_pointer->set_id(1);
  
  humanoid_pointer = world.create_humanoid(&humanoid_class);
  humanoid_pointer->set_id(2);
  
  humanoid_pointer = world.create_humanoid(&humanoid_class);
  humanoid_pointer->set_id(3);
  
  humanoid_pointer = world.create_humanoid(&humanoid_class);
  humanoid_pointer->set_id(4);
  
  cout << world.debug_string() << endl;
  
  // TODO: actual testing
  
  return return_code;
}