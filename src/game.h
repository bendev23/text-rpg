#ifndef GAME_H
#define GAME_H

/** \file game.h
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

/**
 * Represents the game engine. Communicates with the player using
 * interface class and executes appropriate actions on the game world.
 */

class Game
  {
  };

/**
 * Represents the game world, holds information about everything within
 * it, including all locations, beings, items, the player etc. Provides
 * methods for simulating the game world.
 */
  
class World: public NameableDescribable
  {
  };

/**
 * Provides means of communication with the user and all communication with
 * the user must be done via this class.
 */
  
class CommandLineInterface
  {
    protected:
      unsigned int line_length;           // a hint for the class, says how long one command-line line is
  
    public:
     CommandLineInterface();
      
     /**
       * Writes out given message.
       * 
       * @param message message to be written
       * @param new_line if true, new line will be printed at the end, otherwise not
       */
      
      void write_message(std::string message, bool new_line=true);
      
      /**
       * Asks the user for confirmation.
       * 
       * @return true if the user chose to confirm, false otherwise
       */
      
      bool confirm();

      /**
       * Prompts the user to enter a string value.
       * 
       * @return user-entered string value
       */
    
      std::string read_string();
      
      /**
       * Prompts the user to enter an int value. The prompt is
       * repeated until a valid integer is entered.
       * 
       * @return user-entered int value
       */
      
      int read_int();
      
      /**
       * Prompts the user to enter an int value. The prompt is
       * repeated until a valid integer is entered.
       * 
       * @return user-entered int value
       */
      
      float read_float();
      
      /**
       * Prints a horizontal text separator.
       */
      
      void write_separator();
      
      /**
       * Prints a vector of strings as a table with given number
       * of columns.
       * 
       * @param content vector of strings to fill the table with (left to right,
       *   top to bottom)
       * @param columns number of table columns
       * @param print_head if true, the first row will be printed as table head
       */
      
      void write_table(std::vector<std::string> content, unsigned int columns, bool print_head=true);
  };
  
#endif
