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
    bool do_break;
    int result;
    
    while (true)
      {
        do_break = true;
        cout << STRING_PROMPT_INT << ": ";
    
        string line;
        getline(cin, line);
    
        try
          {
            result = stoi(line);
          }
        catch (exception& e)
          {
            cout << STRING_INVALID_VALUE_ENTERED << endl;
            do_break = false;
          }
          
        if (do_break)
          break;
      }
    
    return result;
  }

float CommandLineInterface::read_float()
  {
    bool do_break;
    float result;
    
    while (true)
      {
        do_break = true;
        cout << STRING_PROMPT_FLOAT << ": ";
    
        string line;
        getline(cin, line);
    
        try
          {
            result = stof(line);
          }
        catch (exception& e)
          {
            cout << STRING_INVALID_VALUE_ENTERED << endl;
            do_break = false;
          }
          
        if (do_break)
          break;
      }
    
    return result;
  }