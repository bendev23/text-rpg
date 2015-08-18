#ifndef COMBAT_H
#define COMBAT_H

/** \file combat.h
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

#include "being.h"

class CombatScene;

class CombatParticipant
  {
    private:
      Being* being;
      CombatScene* combat_scene;
      CombatParticipant** allies;
      CombatParticipant** enemies;
    public:
      CombatParticipant();
      void set_allies(CombatParticipant**);
      void set_enemies(CombatParticipant**);
      void set_being(Being*);
      void set_combat_scene(CombatScene*);
  };

class CombatScene
  {
    private:
      CombatParticipant* participant;
    public:
      CombatScene();
      void set_participant(CombatParticipant*);
  };


#endif
