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
#include "rpginstance.h"

class Being
  {
    public:
      Being();
  };

class Humanoid: public Being
  {
    public:
      Humanoid();
  };
  
class Beast: public Being, public RPGInstance<BeingClass>
  {
  };
  
class Player: public Humanoid, public RPGInstance<HumanoidClass>
  {
  };
  
#endif