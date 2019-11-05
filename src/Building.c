/*
Building.c
IMPLEMENTASI ABSTRAKSI BUILDING
*/

#include "Building.h"
#include "player.h"

/* Selektor */
#define Type(B) (B).Type
#define Owner(B) (B).owner
#define Pasukan(B) (B).pasukan
#define Level(B) (B).level
#define A(B) (B).A
#define M(B) (B).M
#define U(B) (B).U

void InitialBuilding (Building *B) 
/*
I.S.
    Parameter-parameter pada Building belum terisi
F.S.
    Parameter-parameter pada building terisi, sesuai jenis Building
*/
{
   switch (Type(*B)) {
        case 'C':
            U(*B) = 40;
            if(Level(*B) == 1) {
                A(*B) = 10;
            }
            else if(Level(*B) == 2) {
                A(*B) = 15;
            }
            else if(Level(*B) == 3) {
                A(*B) = 20;
            }
            else {
                A(*B) = 25;
            }
            break;
        
        case 'T':
            U(*B) = 30;
            if(Level(*B) == 1) {
                A(*B) = 5;
            }
            else if(Level(*B) == 2) {
                A(*B) = 10;
            }
            else if(Level(*B) == 3) {
                A(*B) = 20;
            }
            else {
                A(*B) = 30;
            }
            break;

        case 'F':
            U(*B) = 80;
            if(Level(*B) == 1) {
                A(*B) = 10;
            }
            else if(Level(*B) == 2) {
                A(*B) = 20;
            }
            else if(Level(*B) == 3) {
                A(*B) = 30;
            }
            else {
                A(*B) = 40;
            }
            break;
        
        case 'V':
            U(*B) = 20;
            if(Level(*B) == 1) {
                A(*B) = 5;
            }
            else if(Level(*B) == 2) {
                A(*B) = 10;
            }
            else if(Level(*B) == 3) {
                A(*B) = 15;
            }
            else {
                A(*B) = 20;
            }
            break;
    }
}
void AddPasukanNextTurn (Player P,Building B)
/*
I.S.
    Jumlah pasukan pada building sembarang
F.S.
    Ketika giliran pemain P, jumlah pasukan pada setiap building yang dimiliki pemain P bertambah sesuai jenis building
*/
{
    /* KAMUS LOKAL */
    int i;
    List l;

    /* ALGORITMA */
    l = ListOfBuildings(P);
    i = ListFirstElement(l);
    while(i <= ListLastElement(l)) {
        if(Pasukan(ListElementVal(l)) + A(ListElementVal(l)) <= M) {
            Pasukan(ListElementVal(l)) += A(ListElementVal(l));
        }
        i = ListElementNext(l);
    }
}

void LevelAdd (Building *B);
    /*
    I.S.
        Level bangunan sembarang
    F.S.
        - Level bangunan bertambah apabila jumlah pasukan pada bangunan >= M/2
        - Jika level bangunan bertambah, jumlah pasukan pada bangunan berkurang sebanyak M/2
    */