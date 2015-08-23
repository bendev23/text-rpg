#include "../location.h"
#include "test_helper.h"

int main ()
{
  TestHelper test_helper;
 
  Location location1, location2, location3, location4, location5;
  LocationGroup group1, group2, group3, group4;
  
  location1.set_name("city");
  location2.set_name("village");
  location3.set_name("forest");
  location4.set_name("beach");
  location5.set_name("plains");
  
  location1.create_path("road",&location2,4.5);
  location1.create_path("path",&location5,2);
  location1.create_path("road",&location3,1.85);
  
  location2.create_path("forest",&location3,0.5);
  location2.create_path("forest",&location4,1.77);
  
  location3.create_path("teleport",&location4,0,false);
  location3.create_path("dirty road",&location5,4);
  
  group1.set_name("island");
  group2.set_name("east coast");
  group3.set_name("west coast");
  group4.set_name("civilised area");
  
  group2.set_parent(&group1);
  group3.set_parent(&group1);
  group4.set_parent(&group2);
  
  group2.add_location(&location3);
  group4.add_location(&location1);
  group4.add_location(&location2);
  group3.add_location(&location4);
  group3.add_location(&location5);
  
  cout << group1.debug_string() << endl;
  cout << group2.debug_string() << endl;
  cout << group3.debug_string() << endl;
  cout << group4.debug_string() << endl;
  
  string name;
  
  cout << "testing whole names:" << endl;
  
  name = location1.get_full_name();
  cout << name << endl;
  test_helper.check_condition(name.compare("island, east coast, civilised area, city") == 0,"location 1, full name");
    
  name = location2.get_full_name();
  cout << name << endl;
  test_helper.check_condition(name.compare("island, east coast, civilised area, village") == 0,"location 2, full name");
  
  name = location3.get_full_name();
  cout << name << endl;
  test_helper.check_condition(name.compare("island, east coast, forest") == 0,"location 3, full name");
  
  name = location4.get_full_name();
  cout << name << endl;
  test_helper.check_condition(name.compare("island, west coast, beach") == 0,"location 4, full name");
  
  name = location5.get_full_name();
  cout << name << endl;
  test_helper.check_condition(name.compare("island, west coast, plains") == 0,"location 5, full name");
  
  test_helper.print();
  return test_helper.get_exit_code();
}