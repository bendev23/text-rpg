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

BasicAttributeValues::BasicAttributeValues(int current_health, int current_energy)
  {
    this->current_health = current_health;
    this->current_energy = current_energy;
  }

void BasicAttributeValues::set_health(int health)
  {
    this->current_health = health;
  }

void BasicAttributeValues::set_energy(int energy)
  {
    this->current_energy = energy;
  }

int BasicAttributeValues::get_health()
  {
    return current_health;
  }

int BasicAttributeValues::get_energy()
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

BasicAttributes::BasicAttributes(int max_health, int max_energy, int armor)
  {
    this->max_health = max_health;
    this->max_energy = max_energy;
    this->armor = armor;
  }

void BasicAttributes::set_max_health(int health)
  {
    max_health = health;
  }

void BasicAttributes::set_max_energy(int energy)
  {
    max_energy = energy;
  }

int BasicAttributes::get_max_health()
  {
    return max_health;
  }

int BasicAttributes::get_max_energy()
  {
    return max_energy;
  }

int BasicAttributes::get_armor_value()
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

AdvancedAttributes::AdvancedAttributes(int physical_strength, int will_power, int agility)
  {
    this->physical_strength = physical_strength;
    this->will_power = will_power;
    this->agility = agility;
  }

void AdvancedAttributes::set_strength(int strength)
  {
    physical_strength = strength;
  }

void AdvancedAttributes::set_will_power(int will_power)
  {
    this->will_power = will_power;
  }

int AdvancedAttributes::get_strength()
  {
    return physical_strength;
  }

int AdvancedAttributes::get_will_power()
  {
    return will_power;
  }

int AdvancedAttributes::get_agility()
  {
    return agility;
  }
