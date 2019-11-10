//ADT COMMAND
//command.h

#ifndef _COMMAND_H
#define _COMMAND_H

#include "bool.h"
#include "WordProcessor.h"
#include <stdio.h>

void InputCommand();
/* Melakukan input Command menggunakan Word Processor */

void AttackCommand();
/* Melakukan mekanisme attack apabila user menginput command Attack,
   yaitu mencetak daftar bangunan yang dimiliki user,
   opsi untuk menyerang dengan bangunan apa,
   daftar bangunan yang dapat diserang (yang saling terhubung),
   opsi bangunan apa yang akan diserang,
   jumlah pasukan yang digunakan untuk menyerang,
   dan hasil akhir penyerangan. */

void LevelUpCommand();
/* Melakukan mekanisme Level_Up apabila user menginput command Level_UP,
   yaitu mencetak daftar bangunan yang dimliki user,
   opsi untuk level up bangunan yang mana,
   dan hasil akhir level up. */

void SkillCommand();
/* Melakukan mekanisme Skill apabila user menginput command Skill,
   yang disesuaikan dengan efek Skill masing-masing */

void UndoCommand();
/* Melakukan mekanisme Undo apabila user menginput command Undo.
   User hanya dapat melakukan UNDO hingga command sesudah END_TURN / SKILL. 
   Artinya, setelah command END_TURN / SKILL, pemain tidak dapat melakukan UNDO lagi */

void EndTurnCommand();
/* Melakukan mekanisme End_Turn apabila user menginput command End_Turn. */

void SaveCommand();
/* Melakukan mekanisme Save_File, yaitu menyimpan state permainan yang sedang berlangsung*/

void MoveCommand();
/* Melakukan mekanisme Move, yaitu memindahkan pasukan dari suatu bangunan ke bangunan lain milik
   pemain yang terhubung dengan bangunan tersebut. MOVE hanya dapat dilakukan
   sekali untuk tiap bangunan pada tiap gilirannya. */

void ExitCommand();
/* Melakukan mekanisme Exit, yaitu keluar dari permainan */

#endif