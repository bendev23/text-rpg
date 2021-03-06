/** \file being.cc
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

#include "being.h"

using namespace std;

Being::Being(): NameableIdentifiable()
  {
  }
  
Humanoid::Humanoid(HumanoidClass *humanoid_class): Being()
  {
    this->set_class(humanoid_class);
  }
  
string Humanoid::get_name()
  {
    return this->get_class()->get_name();
  }
  
string Beast::get_name()
  {
    return this->get_class()->get_name();
  }
  
string Humanoid::debug_string(debug_string_flag flags)
  {
    string result = "humanoid:\n";
    result += "  name: " + this->get_name() + "\n";
    return result;
  }