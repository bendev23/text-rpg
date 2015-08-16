/** \file attributes.cc
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

#include "attributes.h"

// BasicAttributeValues definitions

BasicAttributeValues::BasicAttributeValues()
  {
    current_health = 0;
    current_energy = 0;
  }

BasicAttributeValues::BasicAttributeValues(int p_current_health, int p_current_energy)
  {
    current_health = p_current_health;
    current_energy = p_current_energy;
  }

void BasicAttributeValues::setHealth(int p_health)
  {
    current_health = p_health;
  }

void BasicAttributeValues::setEnergy(int p_energy)
  {
    current_energy = p_energy;
  }

int BasicAttributeValues::getHealth()
  {
    return current_health;
  }

int BasicAttributeValues::getEnergy()
  {
    return current_energy;
  }

// BasicAttribute definitions
 
BasicAttributes::BasicAttributes()
  {
    max_health = 0;
    max_energy = 0;
    armor = 0;
  }

BasicAttributes::BasicAttributes(int p_max_health, int p_max_energy,int p_armor)
  {
    max_health = p_max_health;
    max_energy = p_max_energy;
    armor = p_armor;
  }

void BasicAttributes::setMaxHealth(int p_health)
  {
    max_health = p_health;
  }

void BasicAttributes::setMaxEnergy(int p_energy)
  {
    max_energy = p_energy;
  }

int BasicAttributes::getMaxHealth()
  {
    return max_health;
  }

int BasicAttributes::getMaxEnergy()
  {
    return max_energy;
  }

int BasicAttributes::getArmorValue()
  {
    return armor;
  }

// AdvancedAttributes definitions

AdvancedAttributes::AdvancedAttributes()
  {
    physical_strength = 0;
    will_power = 0;
    agility  = 0;
  }

AdvancedAttributes::AdvancedAttributes(int p_physical_strength, int p_will_power, int p_agility)
  {
    physical_strength = p_physical_strength;
    will_power = p_will_power;
    agility  = p_agility;
  }

void AdvancedAttributes::setStrength(int p_strength)
  {
    physical_strength = p_strength;
  }

void AdvancedAttributes::setWillPower(int p_will_power)
  {
    will_power = p_will_power;
  }

int AdvancedAttributes::getStrength()
  {
    return physical_strength;
  }

int AdvancedAttributes::getWillPower()
  {
    return will_power;
  }

int AdvancedAttributes::getAgility()
  {
    return agility;
   }
