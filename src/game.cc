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
  
CommandLineInterface::CommandLineInterface()
  {
    this->line_length = DEFAULT_LINE_LENGTH;
    this->text_align = TEXT_ALIGN_LEFT;
  }

void CommandLineInterface::write_message(string message, bool new_line)
  { 
    unsigned int i;
    unsigned int current_length;
    unsigned int length_to_add;
    bool first_word;                 // first word of the line
    vector<string> message_split;
    
    switch (this->text_align)
      {
        case TEXT_ALIGN_LEFT:
          message_split = string_split(message);
          current_length = 0;
          first_word = true;     
          
          for (i = 0; i < message_split.size(); i++)
            {
              length_to_add = message_split[i].length() + 1;
              
              if (first_word || current_length + length_to_add <= this->line_length)
                {
                  cout << message_split[i] << " ";
                  current_length += length_to_add;
                  first_word = false;
                }
              else
                {
                  cout << endl;
                  current_length = 0;
                  first_word = true;
                }
            }
            
          break;
          
        case TEXT_ALIGN_BLOCK:
          // TODO
          break;
          
        case TEXT_ALIGN_BREAK:
          current_length = 0;
          
          for (i = 0; i < message.size(); i++)
            {
              if (current_length >= this->line_length)
                {
                  cout << endl;
                  current_length = 0;
                }
                
              cout << message[i];
              current_length++;
            }
            
          break;
          
        case TEXT_ALIGN_NONE:
        default:
          cout << message;
          break;
      }
    
    if (new_line)
      cout << endl;
  }
  
unsigned int write_choice(std::vector<std::string> choices)
  {
    // TODO
    return 0;
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
    
        result = string_to_int(line,success);

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
    
        result = string_to_float(line,success);

        if (success)
          break;
        else
          cout << STRING_INVALID_VALUE_ENTERED << endl;
      }
    
    return result;
  }
  
void CommandLineInterface::write_separator()
  {
    unsigned int i;
    
    for (i = 0; i < this->line_length; i++)
      cout << "_";
    
    cout << endl;
  }
  
void CommandLineInterface::write_table(vector<string> content, unsigned int columns, bool print_head)
  {
    unsigned int greatest_length, remaining_length, spaces_between_columns;
    unsigned int i, j;
    
    spaces_between_columns = 2;
    greatest_length = 0;
    
    for (i = 0; i < content.size(); i++)
      if (content[i].length() > greatest_length)
        greatest_length = content[i].length();
    
    for (i = 0; i < content.size(); i++)
      {
        cout << content[i];
        
        // fill the remaining spaces:
        remaining_length = greatest_length - content[i].length();
        
        for (j = 0; j < remaining_length; j++)
          cout << " ";
        
        if ((i + 1) % columns == 0)  // last column => new line
          {
            cout << endl;
          
            if (i == columns - 1 && print_head)  // head separator
              {
                for (j = 0; j < (columns - 1) * (greatest_length + spaces_between_columns) + greatest_length; j++)
                  cout << "-";
                  
                cout << endl;
              }
          }
        else                         // not last column => spaces
          {
            for (j = 0; j < spaces_between_columns; j++)
              cout << " ";
          }
      }
    
  }