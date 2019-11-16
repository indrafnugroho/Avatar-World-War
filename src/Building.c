/*
Building.c
IMPLEMENTASI ABSTRAKSI BUILDING
*/

#include "Building.h"
//#include "Loader.h"

void InitializationBuilding (Building *B) 
/*
I.S.
    Parameter-parameter pada Building belum terisi
F.S.
    Parameter-parameter pada building terisi, sesuai jenis Building
*/
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    switch (Type(*B)) {
    case 'C':
        // ke bawah masih salah
        U(*B) = 40;
        if(Level(*B) == 1) A(*B) = 10;
        else if(Level(*B) == 2) A(*B) = 15;
        else if(Level(*B) == 3) A(*B) = 20;
        else A(*B) = 25;
        break;
    
    case 'T':
        U(*B) = 30;
        if(Level(*B) == 1) A(*B) = 5;
        else if(Level(*B) == 2) A(*B) = 10;
        else if(Level(*B) == 3) A(*B) = 20;
        else A(*B) = 30;
        break;

    case 'F':
        U(*B) = 80;
        if(Level(*B) == 1) A(*B) = 10;
        else if(Level(*B) == 2) A(*B) = 20;
        else if(Level(*B) == 3) A(*B) = 30;
        else A(*B) = 40;
        break;
    
    case 'V':
        U(*B) = 20;
        if(Level(*B) == 1) A(*B) = 5;
        else if(Level(*B) == 2) A(*B) = 10;
        else if(Level(*B) == 3) A(*B) = 15;
        else A(*B) = 20;
        break;
    }

}
void AddPasukanNextTurn (Building *B)
/*
I.S.
    Jumlah pasukan pada building sembarang
F.S.
    Ketika giliran pemain P, jumlah pasukan pada setiap building yang dimiliki pemain P bertambah sesuai jenis building
*/
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if(Troops(*B) + A(*B) <= M(*B)) {
        Troops(*B) += A(*B);
    }
}

void LevelAdd (Building *B)
/*
I.S.
    Level bangunan sembarang
F.S.
    - Level bangunan bertambah apabila jumlah pasukan pada bangunan >= M/2
    - Jika level bangunan bertambah, jumlah pasukan pada bangunan berkurang sebanyak M/2
*/
{
    if(Troops(*B) >= M(*B)/2) {
        Level(*B)++;
        Troops(*B) -= M(*B)/2;
    } 
}
