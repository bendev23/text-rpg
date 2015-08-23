#include "../general.h"
#include "../being.h"
#include "../game.h"
#include "../dialog.h"
#include "test_helper.h"

int main ()
{
  TestHelper test_helper;
  
  /* assign RPG classes to humanoids and see if they return
     appropriate names */
  
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
  
  test_helper.check_condition(name1.compare("guard") == 0,"name 1 == 'guard'?");
  test_helper.check_condition(name2.compare("villager") == 0,"name 2 == 'villager'?");
  test_helper.check_condition(name3.compare("citizen") == 0,"name 3 == 'citizen'?");
  test_helper.check_condition(name4.compare("citizen") == 0,"name 4 == 'citizen'?");
  
  test_helper.print();
  return test_helper.get_exit_code();
}