#include "../general.h"
#include "../being.h"
#include "../game.h"
#include "../dialog.h"

using namespace std;

int main ()
{
  /* assign RPG classes to humanoids and see if they return
     appropriate names */
  
  int return_code = 0;
  HumanoidClass humanoid_class1,
                humanoid_class2,
                humanoid_class3;
  
  Humanoid humanoid1(&humanoid_class1),
           humanoid2(&humanoid_class2),
           humanoid3(&humanoid_class3),
           humanoid4(&humanoid_class3);
  
  humanoid_class1.set_id(1);
  humanoid_class1.set_name("guard");
  
  humanoid_class2.set_id(2);
  humanoid_class2.set_name("villager");
  
  humanoid_class3.set_id(3);
  humanoid_class3.set_name("citizen");
  
  string name1 = humanoid1.get_name();
  string name2 = humanoid2.get_name();
  string name3 = humanoid3.get_name();
  string name4 = humanoid4.get_name();
  
  cout << name1 << endl << name2 << endl << name3 << endl << name4 << endl;
  
  if (name1.compare("guard") == 0 &&
      name2.compare("villager") == 0 &&
      name3.compare("citizen") == 0 &&
      name4.compare("citizen") == 0)
    cout << "OK" << endl;
  else
    {
      cout << "ERROR" << endl;
      return_code = 1;
    }
  
  return return_code;
}