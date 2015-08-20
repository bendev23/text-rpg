/** \file location.cc
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

#include "location.h"

using namespace std;

void LocationGroup::add_location(Location *location)
  {
    if (location == 0)
      {
        Logger::log_error("Attempted to add null location to a group.");
        return;
      }
    
    location->set_group(this);
    this->locations.push_back(location);
  }
  
vector<Location *> LocationGroup::get_locations()
  {
    return this->locations;
  }

string Location::get_full_name()
  {
    LocationGroup *group_pointer = this->group;
    string result = this->get_name();
    
    while (group_pointer != 0)
      {
        result = group_pointer->get_name() + ", " + result;
        group_pointer = group_pointer->get_parent();
      }
    
    return result;
  }
  
string LocationGroup::debug_string(debug_string_flag flags)
  {
    unsigned int i;
    string result = "location group\n";
    result += "  name: " + this->get_name() + "\n";
    result += "  parent: " + (this->parent == 0 ? "none" : this->parent->get_name()) + "\n";
    result += "  locations: ";
    
    for (i = 0; i < this->locations.size(); i++)
      {
        result += this->locations[i]->get_name();
        
        if (i < this->locations.size() - 1)
          result += ", ";
      }
        
    result += "\n";
      
    return result;
  }

void LocationGroup::set_parent(LocationGroup *parent)
  {
    this->parent = parent;
  }
  
void Location::set_group(LocationGroup *group)
  {
    this->group = group;
  }

LocationGroup *Location::get_group()
  {
    return this->group;
  }

LocationGroup *LocationGroup::get_parent()
  {
    return this->parent;
  }
  
void Path::set_destination(Location *destination)
  {
    this->destination = destination;
  }
  
Location *Path::get_destination()
  {
    return this->destination;
  }
  
void Path::set_length(float length_km)
  {
    this->length_km = length_km;
  }
  
float Path::get_length()
  {
    return length_km;
  }
  
void Location::create_path(string name, Location *destination, float length_km, bool bidirectional)
  {
    Path new_path;
    
    if (destination == NULL)
      {
        Logger::log_error("Attempted to create path with NULL destination.");
        return;
      }
    
    new_path.set_name(name);
    new_path.set_destination(destination);
    new_path.set_length(length_km);
    
    this->paths.push_back(new_path);
    
    if (bidirectional)
      destination->create_path(name,this,length_km,false);  
  }

Path::Path()
  {
    this->destination = 0;
    this->length_km = 1.0;   // default value
    this->set_name("path");
  }
  
string Path::debug_string(debug_string_flag flags)
  {
    string result =
      "path: " +
      this->get_name() +
      " leading to " +
      (this->destination == 0 ? "NULL" : this->destination->get_name()) +
      " (" + float_to_string(this->length_km) + ")";
    
    return result;
  }
  
string Location::debug_string(debug_string_flag flags)
  {
    unsigned int i;
    
    string result = "location\n";
    result += "name: " + this->get_name() + "\n";
    
    result += "connections:\n";
    
    for (i = 0; i < this->paths.size(); i++)
      {
        result += this->paths[i].debug_string() + "\n";
      }
      
    return result;
  }
  
unsigned int Location::get_number_of_paths()
  {
    return this->paths.size();
  }