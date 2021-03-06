/** \file main.cc
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
#include "being.h"
#include "game.h"
#include "dialog.h"
#include "scriptinterpreter.h"
#include "attributes.h"

using namespace std;

int main ()
  {
    CommandLineInterface interface;
    PlayerCommand command = interface.read_command();
    cout << command.debug_string() << endl;
    return 0;
  }
