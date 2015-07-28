#ifndef RPGINSTANCE_H
#define RPGINSTANCE_H

/** \file rpginstance.h
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
#include "being.h"

class RPGClass
  {
  };

class BeingClass: public RPGClass
  {
  };
  
class BeastClass: public BeingClass
  {
  };
  
class HumanoidClass: public BeingClass
  {
  };
  
class WorldObjectClass: public RPGClass
  {
  };
  
class ItemClass: public RPGClass
  {
  };

class BookClass: public ItemClass
  {
  };
  
class ConsumableClass: public ItemClass
  {
  };
  
class EquipableClass: public ItemClass
  {
  };
  
class Questitem: public ItemClass
  {
  };
  
template <class T>
class RPGInstance
  {
    protected:
      T *rpg_class;

    public:
      void set_class(T *new_class);
      T *get_class();
  };
  
#endif