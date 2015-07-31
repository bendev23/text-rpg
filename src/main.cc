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

using namespace std;

int main ()
{
  CommandLineInterface interface;
  interface.write_message("Hello, this will be an RPG.",true);
  interface.write_separator();
  
  vector<string> test_vector;
  
  test_vector.push_back("name");
  test_vector.push_back("attribute1");
  test_vector.push_back("attribute2");
  test_vector.push_back("something");
  
  test_vector.push_back("Joe");
  test_vector.push_back("15");
  test_vector.push_back("250");
  test_vector.push_back("no");
  
  test_vector.push_back("Marry");
  test_vector.push_back("2");
  test_vector.push_back("750");
  test_vector.push_back("yes");
  
  test_vector.push_back("Sam");
  test_vector.push_back("5");
  test_vector.push_back("10");
  test_vector.push_back("no");
  
  interface.write_table(test_vector, 4, true);
  
  return 0;
}
