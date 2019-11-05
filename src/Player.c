/*
Player.c
IMPLEMENTASI ABSTRAKSI Player
*/

#include "Player.h"
#include "List.h"

int NbOfBuildings(Player P)
/* Mengembalikan banyaknya bangunan yang dimiliki pemain*/
{
    return (ListSize(ListOfBuildings(P)));
}