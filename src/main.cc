/** \file main.cc
 *
 */

/*
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "general.h"
#include "being.h"
#include "game.h"
#include "dialog.h"
#include "scriptinterpreter.h"

using namespace std;

int main ()
{
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
  
  cout << humanoid1.get_name() << endl;
  cout << humanoid2.get_name() << endl;
  cout << humanoid3.get_name() << endl;
  cout << humanoid4.get_name() << endl;
  return 0;
}
