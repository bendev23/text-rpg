/** \file scriptinterpreter.cc
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

#include "scriptinterpreter.h"

using namespace std;

double my_function(int i, double j) {return i * j;}

ScriptInterpreter::ScriptInterpreter()
  {
    this->chai = new chaiscript::ChaiScript(chaiscript::Std_Lib::library());
    this->chai->add(chaiscript::fun(&my_function), "my_function");
    double d = chai->eval<double>("my_function(3, 4.75);");
    cout << d << endl;
  }
  
ScriptInterpreter::~ScriptInterpreter()
  {
    delete this->chai;
  }