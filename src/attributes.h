#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

/** \file attributes.h
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

class BasicAttributeValues
  {
    protected:
      int current_health, current_energy;
    public:
      BasicAttributeValues();
      BasicAttributeValues(int, int);
      void set_health(int);
      void set_energy(int);
      int get_health();
      int get_energy();
  };

class BasicAttributes
  {
    protected:
      int max_health, max_energy, armor;
    public:
      BasicAttributes();
      BasicAttributes(int,int,int);
      void set_max_health(int);
      void set_max_energy(int);
      void set_armor();
      int get_max_health();
      int get_max_energy();
      int get_armor_value();
  };

class AdvancedAttributes
  {
    protected:
      int physical_strength, will_power, agility; //(vkortelainen) Some more might be added.
    public:
      AdvancedAttributes();
      AdvancedAttributes(int,int,int);
      void set_strength(int);
      void set_will_power(int);
      void set_agility(int);
      int get_strength();
      int get_will_power();
      int get_agility();
  };

#endif
