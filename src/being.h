#ifndef BEING_H
#define BEING_H

/** \file being.h
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
#include "attributes.h"
#include "rpginstance.h"

class Being
  {
    protected:
      int gender; //(vkortelainen) Do more than 2 genders exist within this game?
      BasicAttributeValues basic_attribute_values;
      //AbilityClass abilities[];
      //BeingScripts scripts;
    public:
      Being();
  };

enum HumanoidStatus
  {
    HUMANOID_STATUS_NORMAL,
    HUMANOID_STATUS_PROTECTED,
    HUMANOID_STATUS_UNKILLABLE
  };

class Humanoid: public Being
  {
    protected:
      BasicAttributes basic_attributes;
      AdvancedAttributes advanced_attributes;
      int level;
      //Equipment equipment;
      HumanoidStatus status;
      //Dialog* current_dialog; //(vkortelainen) Unclear if pointer or not.
      //ActivityPlan activity_plan;
    public:
      Humanoid();
      
      int get_weight();
  };
  
class Beast: public Being, public RPGInstance<BeingClass>
  {
  };
  
class Player: public Humanoid, public RPGInstance<HumanoidClass>
  {
  };
  
#endif
