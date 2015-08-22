#include "../game.h"

using namespace std;

int return_code = 0;
 
void check_condition(bool condition)
  {
    if (condition)
      cout << "OK" << endl;
    else
      {
        cout << "Error!" << endl;
        return_code = 1;
      }      
  }

int main ()
{
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
  
  cout << "testing getting by id:" << endl;
  string name;
  
  name = world.get_location_by_id(2)->get_name();
  check_condition(name.compare("city") == 0);
  
  name = world.get_location_by_id(1)->get_name();
  check_condition(name.compare("village") == 0);
  
  check_condition(world.get_location_by_id(1000) == 0);
  
  name = world.get_humanoid_by_id(4)->get_name();
  check_condition(name.compare("just another humanoid") == 0);
  
  return return_code;
}