//ADT COMMAND
//command.h

#ifndef _COMMAND_H
#define _COMMAND_H

#include "bool/bool.h"
#include "ArrayDin/ArrayDin.h"
#include "WordProcessor/WordProcessor.h"
#include "Player/Player.h"
#include "Graph/Graph.h"
#include "Stack/Stack.h"
#include "GameState/GameState.h"
void InputCommand(Player* PTurn, Player* PEnemy, ArrayDin* Bldgs, Stack* GState, Graph Connect);
/* Melakukan input Command menggunakan Word Processor */

void AttackCommand(Player* PTurn, Player* PEnemy, ArrayDin Bldgs, Graph Connect);
/* Melakukan mekanisme attack apabila user menginput command Attack,
   yaitu mencetak daftar bangunan yang dimiliki user,
   opsi untuk menyerang dengan bangunan apa,
   daftar bangunan yang dapat diserang (yang saling terhubung),
   opsi bangunan apa yang akan diserang,
   jumlah pasukan yang digunakan untuk menyerang,
   dan hasil akhir penyerangan. */

void LevelUpCommand(Player* PSelf);
/* Melakukan mekanisme Level_Up apabila user menginput command Level_UP,
   yaitu mencetak daftar bangunan yang dimliki user,
   opsi untuk level up bangunan yang mana,
   dan hasil akhir level up. */

void SkillCommand(Player* PTurn, Player* PEnemy);
/* Melakukan mekanisme Skill apabila user menginput command Skill,
   yang disesuaikan dengan efek Skill masing-masing */

void UndoCommand(Player* PTurn, Player* PEnemy, ArrayDin* Bldgs, Stack* GState);
/* Melakukan mekanisme Undo apabila user menginput command Undo.
   User hanya dapat melakukan UNDO hingga command sesudah END_TURN / SKILL. 
   Artinya, setelah command END_TURN / SKILL, pemain tidak dapat melakukan UNDO lagi */

void EndTurnCommand(Player* PTurn, Player* PEnemy);
/* Melakukan mekanisme End_Turn apabila user menginput command End_Turn. */

void SaveCommand(Player* PTurn, Player* PEnemy);
/* Melakukan mekanisme Save_File, yaitu menyimpan state permainan yang sedang berlangsung*/

void MoveCommand(Player* PSelf, ArrayDin Bldgs, Graph Connect);
/* Melakukan mekanisme Move, yaitu memindahkan pasukan dari suatu bangunan ke bangunan lain milik
   pemain yang terhubung dengan bangunan tersebut. MOVE hanya dapat dilakukan
   sekali untuk tiap bangunan pada tiap gilirannya. */

void ExitCommand();
/* Melakukan mekanisme Exit, yaitu keluar dari permainan */

void AddAToAllBuilding (Player* P);
/* Melakukan penambahan pasukan (A) terhadap bangunan player */

void SetToFalse (Player* P);
/*  I.S. Player terdefinisi.
    F.S. Set All AfterAttack and AfterMove All Player's Building to False
*/

#endif
