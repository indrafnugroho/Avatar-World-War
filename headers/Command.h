//ADT COMMAND
//command.h

#ifndef _COMMAND_H
#define _COMMAND_H

#include "bool.h"
#include "WordProcessor.h"
#include "Player.h"
#include "GameState.h"

void InputCommand(Player* P1, Player* P2, GameState* GS);
/* Melakukan input Command menggunakan Word Processor */

void AttackCommand(Player* P1, Player* P2, GameState* GS);
/* Melakukan mekanisme attack apabila user menginput command Attack,
   yaitu mencetak daftar bangunan yang dimiliki user,
   opsi untuk menyerang dengan bangunan apa,
   daftar bangunan yang dapat diserang (yang saling terhubung),
   opsi bangunan apa yang akan diserang,
   jumlah pasukan yang digunakan untuk menyerang,
   dan hasil akhir penyerangan. */

void LevelUpCommand(Player* PSelf, GameState* GS);
/* Melakukan mekanisme Level_Up apabila user menginput command Level_UP,
   yaitu mencetak daftar bangunan yang dimliki user,
   opsi untuk level up bangunan yang mana,
   dan hasil akhir level up. */

void SkillCommand(Player* P1, Player* P2, GameState* GS);
/* Melakukan mekanisme Skill apabila user menginput command Skill,
   yang disesuaikan dengan efek Skill masing-masing */

void UndoCommand(Player* P1, Player* P2, GameState* GS);
/* Melakukan mekanisme Undo apabila user menginput command Undo.
   User hanya dapat melakukan UNDO hingga command sesudah END_TURN / SKILL. 
   Artinya, setelah command END_TURN / SKILL, pemain tidak dapat melakukan UNDO lagi */

void EndTurnCommand(Player* P1, Player* P2, GameState* GS);
/* Melakukan mekanisme End_Turn apabila user menginput command End_Turn. */

void SaveCommand(Player* P1, Player* P2, GameState* GS);
/* Melakukan mekanisme Save_File, yaitu menyimpan state permainan yang sedang berlangsung*/

void MoveCommand(Player* PSelf, GameState* GS);
/* Melakukan mekanisme Move, yaitu memindahkan pasukan dari suatu bangunan ke bangunan lain milik
   pemain yang terhubung dengan bangunan tersebut. MOVE hanya dapat dilakukan
   sekali untuk tiap bangunan pada tiap gilirannya. */

void ExitCommand(Player* P1, Player* P2, GameState* GS);
/* Melakukan mekanisme Exit, yaitu keluar dari permainan */

#endif