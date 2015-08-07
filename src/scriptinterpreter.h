#ifndef SCRIPTINTERPRETER_H
#define SCRIPTINTERPRETER_H

/** \file scriptinterpreter.h
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
#include "chaiscript/chaiscript.hpp"
#include "chaiscript/chaiscript_stdlib.hpp"

#define CHAISCRIPT_NO_THREADS   // turns off thread safety for ChaiScript in favour of performance

class Script
  {
    protected:
      std::string source_text;
  };

class ScriptInterpreter
  {
    protected:
      chaiscript::ChaiScript *chai;

    public:
      ScriptInterpreter();
      ~ScriptInterpreter();
  };

#endif