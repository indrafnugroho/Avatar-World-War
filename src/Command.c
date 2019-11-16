/* Command.c
   Implementasi Command.h */

#include "Command.h"
#include <stdio.h>

void InputCommand(Game* GG) {
/*  Melakukan input Command menggunakan Word Processor */

    Word input;   
    printf("ENTER COMMAND: ");
    ScanWord(&input);

    (*GG).Buildings
    /* 
    Word Processing
    */
}

void AttackCommand() {
/*  Melakukan mekanisme attack apabila user menginput command Attack,
    yaitu mencetak daftar bangunan yang dimiliki user,
    opsi untuk menyerang dengan bangunan apa,
    daftar bangunan yang dapat diserang (yang saling terhubung),
    opsi bangunan apa yang akan diserang,
    jumlah pasukan yang digunakan untuk menyerang,
    dan hasil akhir penyerangan. */
    
    printf("Daftar bangunan:\n");
    /*
    List of Player's Building
    */

    printf("Bangunan yang digunakan untuk menyerang: ");
    // Word Processing

    printf("Daftar bangunan yang dapat diserang:\n");
    /*
    List of Connected Foe's Building
    */

    printf("Bangunan yang diserang: ");
    //Word Processing

    printf("Jumlah pasukan: ");
    //Word Processing

    /*
    Processing Attack Command
    */
}

void LevelUpCommand() {
/*  Melakukan mekanisme Level_Up apabila user menginput command Level_UP,
    yaitu mencetak daftar bangunan yang dimliki user,
    opsi untuk level up bangunan yang mana,
    dan hasil akhir level up. */
    
    printf("Daftar bangunan:\n");
    /*
    List of Player's Building(s)
    */

    printf("Bangunan yang akan di level up: ");
    // Word Processing


}

void SkillCommand() {}
/*  Melakukan mekanisme Skill apabila user menginput command Skill,
    yang disesuaikan dengan efek Skill masing-masing */

void UndoCommand() {}
/*  Melakukan mekanisme Undo apabila user menginput command Undo.
    User hanya dapat melakukan UNDO hingga command sesudah END_TURN / SKILL. 
    Artinya, setelah command END_TURN / SKILL, pemain tidak dapat melakukan UNDO lagi */

void EndTurnCommand() {}
/*  Melakukan mekanisme End_Turn apabila user menginput command End_Turn. */

void SaveCommand() {}
/*  Melakukan mekanisme Save_File, yaitu menyimpan state permainan yang sedang berlangsung*/

void MoveCommand() {
/*  Melakukan mekanisme Move, yaitu memindahkan pasukan dari suatu bangunan ke bangunan lain milik
    pemain yang terhubung dengan bangunan tersebut. MOVE hanya dapat dilakukan
    sekali untuk tiap bangunan pada tiap gilirannya. */

    printf("Daftar bangunan:\n");
    /*
    List of Player's Building(s)
    */

    printf("Pilih bangunan: ");
    //Word Processing

    printf("Daftar bangunan terdekat:\n");
    /*
    List of Player's Connected Building
    */

    printf("Bangunan yang akan menerima: ");
    //Word Processing

    printf("Jumlah pasukan: ");
    //Word Processing

    /* Result */
}

void ExitCommand() {}
/*  Melakukan mekanisme Exit, yaitu keluar dari permainan */