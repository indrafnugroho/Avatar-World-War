/*
Player.c
IMPLEMENTASI ABSTRAKSI Player
*/

#include "Player.h"
#include "Queue.h"

void CreateSkillQueue(Player* P)
/*
I.S.
    Pada awal permainan, pemain belum memiliki skill.
F.S.
    Queue skill pemain dibuat, dengan skill awal hanya berisi IU.
*/
{
    /* KAMUS LOKAL */
    int IU = 1;

    /* ALGORITMA */
    QueueCreate(&SkillQueue(*P));
    QueueAdd(&SkillQueue(*P),IU);
}

void CreateNewPlayer(Player *P)
/*
I.S.
    Parameter-parameter player belum terisi
F.S.
    Parameter-parameter player terisi, keadaan awal building dan skill player belum ada
*/
{
    CreateSkillQueue(P);
}

int NbOfBuildings(Player P)
/* Mengembalikan banyaknya bangunan yang dimiliki pemain*/
{
}