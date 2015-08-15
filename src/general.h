#ifndef GENERAL_H
#define GENERAL_H

/** \file general.h
 * General declarations.
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

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <ctime>
#include <sstream>

#include "texts_en.h"

#define ENGINE_VERSION "0.0"   // this will hold the engine version later
#define DEFAULT_LINE_LENGTH 50

typedef unsigned int id_type;

int string_to_int(std::string input, bool &success);      // these functions exist because stoi and stof can't be used due to gcc bug on Windows
float string_to_float(std::string input, bool &success);
std::string float_to_string(float input);

/**
 * Splits given string by spaces.
 */

std::vector<std::string> string_split(std::string input, char delim=' ');

/**
 * Class used for logging events (normal messages and errors). The class
 * uses static members to function and can be configured.
 */

class Logger
  {
    protected:
      static bool overwrite_file;    ///< whether the log file should be overwritten of appended to
      static bool enabled;           ///< whether logging is enabled
      static std::ofstream log_file;
      
    public:
      /**
       * Opens given file for logging.
       */
      static bool open_log(std::string filename);
      
      /**
       * Closes the currently opened log file.
       */
      static void close_log();
      
      /**
       * Logs given message. If no file is opened for logging or
       * logging is disabled, nothing happens.
       */
      static void log_message(std::string message);
      
      /**
       * Same as log_message but marks the message as error in the log.
       */
      static void log_error(std::string message);
      
      /**
       * Disables logging.
       */
      static void disable();
      
      /**
       * Enables logging.
       */
      static void enable();
  };
  
typedef enum
  {
    DEBUG_STRING_BRIEF = 0x01,     ///< brief debug string
    DEBUG_STRING_LARGE = 0x02      ///< large debug string with a lot of info
  } debug_string_flag;
  
/**
 * Provides a method for retrieving a debug string for development purposes.
 */
  
class DebugSerializable
  {
    public:
      /**
       * Returns a debug string. Optional flags can be provided to control
       * what information the string will contain.
       */
      
      virtual std::string debug_string(debug_string_flag flags=(debug_string_flag) 0)=0;
  };
  
class Identifiable
  {
    protected:
      id_type id;
    public:  
      void set_id(id_type new_id);
      id_type get_id();
  };
  
class Nameable
  {
    protected:
      std::string name;
    public:
      virtual void set_name(std::string name);
      virtual std::string get_name();
  };
  
class Describable
  {
    protected:
      std::string description;
    public:
      virtual void set_description(std::string description);
      virtual std::string get_description();
  };
  
class NameableIdentifiable: public Nameable, public Identifiable
  {
  };
  
class NameableDescribable: public Nameable, public Describable
  {
  };
  
class DescribableIdentifiable: public Describable, public Identifiable
  {
  };

class NameableDescribableIdentifiable:public Nameable, public Identifiable, public Describable
  {
  };
  
class Location;  // forward declaration for Locatable
  
class Locatable
  {
    protected:
      Location *location;
  };
  
#endif
