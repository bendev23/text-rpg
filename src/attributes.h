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
  };

class BasicAttributes
  {
    protected:
      int max_health, max_energy, armor;
  };

class AdvancedAttributes
  {
    protected:
      int physical_strength, will_power, agility; //(vkortelainen) Some more might be added.
  };

#endif
