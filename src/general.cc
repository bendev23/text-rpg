/** \file general.cc
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

using namespace std;

void Identifiable::set_id(id_type new_id)
  {
    this->id = new_id;
  }
  
id_type Identifiable::get_id()
  {
    return this->id;
  }
  
void Nameable::set_name(string name)
  {
    this->name = name;
  }
  
string Nameable::get_name()
  {
    return this->name;
  }
  
void Describable::set_description(string name)
  {
    this->description = description;
  }
  
string Describable::get_description()
  {
    return this->description;
  }