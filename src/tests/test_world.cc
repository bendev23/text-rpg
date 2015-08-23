#include "../game.h"
#include "test_helper.h"

int main ()
{
  TestHelper test_helper;
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
  test_helper.check_condition(name.compare("city") == 0,"location with id 2 == 'city'?");
  
  name = world.get_location_by_id(1)->get_name();
  test_helper.check_condition(name.compare("village") == 0,"location with id 1 == 'village'?");
  
  test_helper.check_condition(world.get_location_by_id(1000) == 0,"does locaiton with id = 1000 exist?");
  
  name = world.get_humanoid_by_id(4)->get_name();
  test_helper.check_condition(name.compare("just another humanoid") == 0,"humanoid with id = 4 == 'just another humanoid'?");
  
  test_helper.print();
  return test_helper.get_exit_code();
}