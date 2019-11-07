/*
Player.c
IMPLEMENTASI ABSTRAKSI Player
*/

#include "Player.h"
#include "Queue.h"

void CreateNewPlayer(Player *P)
/*
I.S.
    Parameter-parameter player belum terisi
F.S.
    Parameter-parameter player terisi, keadaan awal player belum memiliki building apapun dan hanya memiliki skill IU.
*/
{
    CreateSkillQueue(P);
    MakeEmpty(&Buildings(*P),30);
}

int NbOfBuildings(Player P)
/* Mengembalikan banyaknya bangunan yang dimiliki pemain*/
{
    return NbElmt(Buildings(P));
}

void ClonePlayer(Player Pin,Player *Pout)
/*
I.S.
    Terdapat sembarang player Pin dan Pout.
F.S.
    Pout memiliki seluruh skill dan building yang dimiliki Pin tanpa tambahan lain.
*/
{
    /* KAMUS LOKAL */
    QueueElement i;

    /* ALGORITMA */
    CopyTab(Buildings(Pin),&Buildings(*Pout));
    for (i = QueueHead(SkillQueue(Skill(Pin))); i <= QueueTail(SkillQueue(Skill(Pin))); i++) {

    }
}