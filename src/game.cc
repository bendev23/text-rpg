/** \file game.cc
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

#include "game.h"

using namespace std;

int CommandLineInterface::string_to_int(string input, bool &success)
  {
	int result;
	char *endptr;
	
	result = strtol(input.c_str(),&endptr,10);
	success = endptr != input.c_str();
	
	return result;
  }

float CommandLineInterface::string_to_float(string input, bool &success)
  {
	double result;
	char *endptr;
	
	result = strtod(input.c_str(),&endptr);
	success = endptr != input.c_str();
	
	return (float) result;
  }
  
void CommandLineInterface::write_message(string message, bool new_line)
  {
    cout << message;
    
    if (new_line)
      cout << endl;
  }
  
bool CommandLineInterface::confirm()
  {
    cout << STRING_CONFIRMATION << ": ";

    string line;
    getline(cin, line);
    
    return (line.compare(STRING_CONFIRMATION_YES) == 0);
  }
  
string CommandLineInterface::read_string()
  {
    cout << STRING_PROMPT_STRING << ": ";
    
    string line;
    getline(cin, line);
    
    return line;
  }
      
int CommandLineInterface::read_int()
  {
    bool success;
    int result;
    
    while (true)
      {
        cout << STRING_PROMPT_INT << ": ";
    
        string line;
        getline(cin, line);
    
        result = this->string_to_int(line,success);
		
		if (success)
          break;
	    else
          cout << STRING_INVALID_VALUE_ENTERED << endl;
      }
    
    return result;
  }

float CommandLineInterface::read_float()
  {
    bool success;
    float result;
    
    while (true)
      {
        cout << STRING_PROMPT_FLOAT << ": ";
    
        string line;
        getline(cin, line);
    
	    result = this->string_to_float(line,success);
	
        if (success)
          break;
	    else
          cout << STRING_INVALID_VALUE_ENTERED << endl;
      }
    
    return result;
  }