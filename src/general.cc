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

vector<string> string_split(std::string input, char delim)
  {
    vector<string> result;
    
    auto lambda_split = [] (string &s, char delim, vector<string> &elements)
      {
        stringstream ss(s);
        string item;
    
        while (getline(ss,item,delim))
          elements.push_back(item);
      
        return elements;
      };
    
    lambda_split(input,delim,result);
    return result;
  }

int string_to_int(string input, bool &success)
  {
    int result;
    char *endptr;
        
    result = strtol(input.c_str(),&endptr,10);
    success = endptr != input.c_str();
        
    return result;
  }

float string_to_float(string input, bool &success)
  {
    double result;
    char *endptr;
        
    result = strtod(input.c_str(),&endptr);
    success = endptr != input.c_str();
        
    return (float) result;
  }

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
  
bool Logger::overwrite_file = true;  // these need to be declared here because of linker
bool Logger::enabled = true;       
ofstream Logger::log_file;

bool Logger::open_log(std::string filename)
  {
    ios_base::openmode mode = (ios_base::openmode) (ios::out | (Logger::overwrite_file ? 0 : ios::app));
    Logger::log_file.open((const char*) filename.c_str(),mode);
    return Logger::log_file.is_open();
  }    

void Logger::close_log()
  {
    Logger::log_file.close();
  }
  
void Logger::log_message(std::string message)
  {
    if (!Logger::enabled | !Logger::log_file.is_open())
      return;
    
    time_t current_time = time(0);       // get time now
    struct tm* now = localtime(&current_time);
    
    Logger::log_file << now->tm_mday << "." << now->tm_mon << "." <<
      (now->tm_year + 1900) << ", " << now->tm_hour << ":" << now->tm_min << ":" <<
      now->tm_sec << ": " << message << endl;
  }   

void Logger::log_error(std::string message)
  { 
    Logger::log_message("ERROR: " + message);
  }

void Logger::disable()
  {
    Logger::enabled = false;
  }
  
void Logger::enable()
  {
    Logger::enabled = true;
  }