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
#include "texts_en.h"

class Identifiable
  {
  };
  
class Nameable
  {
  };
  
class Describable
  {
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
  
#endif