#include "../location.h"

using namespace std;

int main ()
{
  int return_code = 0;
 
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
  
  if (location1.get_number_of_paths() != 3)
    {
      cout << "ERROR: wrong number of paths in 'city'." << endl;
      return_code = 1;
    }
    
  if (location2.get_number_of_paths() != 3)
    {
      cout << "ERROR: wrong number of paths in 'village'." << endl;
      return_code = 1;
    }
    
  if (location3.get_number_of_paths() != 4)
    {
      cout << "ERROR: wrong number of paths in 'forest'." << endl;
      return_code = 1;
    }
    
  if (location4.get_number_of_paths() != 1)
    {
      cout << "ERROR: wrong number of paths in 'beach'." << endl;
      return_code = 1;
    }
    
  if (location5.get_number_of_paths() != 2)
    {
      cout << "ERROR: wrong number of paths in 'plains'." << endl;
      return_code = 1;
    }
  
  return return_code;
}