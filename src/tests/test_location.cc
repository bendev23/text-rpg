#include "../location.h"
#include "test_helper.h"

using namespace std;

int main ()
{
  TestHelper test_helper;
 
  Location location1, location2, location3, location4, location5;
  
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
  
  cout << location1.debug_string() << endl;
  cout << location2.debug_string() << endl;
  cout << location3.debug_string() << endl;
  cout << location4.debug_string() << endl;
  cout << location5.debug_string() << endl;
  
  test_helper.check_condition(location1.get_number_of_paths() == 3,"location 1, # of paths == 3?");
  test_helper.check_condition(location2.get_number_of_paths() == 3,"location 2, # of paths == 3?");
  test_helper.check_condition(location3.get_number_of_paths() == 4,"location 3, # of paths == 4?");
  test_helper.check_condition(location4.get_number_of_paths() == 1,"location 4, # of paths == 1?");
  test_helper.check_condition(location5.get_number_of_paths() == 2,"location 5, # of paths == 2?");
  
  test_helper.print();
  return test_helper.get_exit_code();
}