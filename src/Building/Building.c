/*
Building.c
IMPLEMENTASI ABSTRAKSI BUILDING
*/

#include "Building/Building.h"
//#include "Loader.h"
#include <stdio.h>
void InitializationBuilding (Building *B) {
/*  I.S.Parameter-parameter pada Building belum terisi
    F.S.Parameter-parameter pada building terisi, sesuai jenis Building */
    Level(*B) = 1;
    switch(Type(*B)) {
    case 'C' :
        A(*B) = 10;
        M(*B) = 40;
        Pb(*B) = false;
        U(*B) = 40;
        break;
    case 'T' :
        A(*B) = 5;
        M(*B) = 20;
        Pb(*B) = true;
        U(*B) = 30;
        break;
    case 'F' :
        A(*B) = 10;
        M(*B) = 20;
        Pb(*B) = false;
        U(*B) = 80;
        break;
    case 'V' :
        A(*B) = 5;
        M(*B) = 20;
        Pb(*B) = false;
        U(*B) = 20;
        break;
    }
    Troops(*B) = U(*B);
    AfterAttack(*B) = false;
    AfterMove(*B) = false;
}
void AddPasukanNextTurn (Building *B)
/*  I.S. Jumlah pasukan pada building sembarang
    F.S. Ketika giliran pemain P, jumlah pasukan pada setiap building yang dimiliki pemain P bertambah sesuai jenis building */
{
    if(Troops(*B) + A(*B) <= M(*B)) {
        Troops(*B) += A(*B);
    }
}

void LevelAdd (Building *B) {
/*  I.S. Level bangunan kurang dari 4
    F.S.
    - Level bangunan bertambah apabila jumlah pasukan pada bangunan >= M/2
    - Jika level bangunan bertambah, jumlah pasukan pada bangunan berkurang sebanyak M/2
    - Nilai A, M, dan Pb berubah sesuai Type Bangunan dan Level */
    if(Troops(*B) >= M(*B)/2 && Level(*B) < 4) {
        Level(*B)++;
        Troops(*B) -= M(*B)/2;
     
        switch (Type(*B)) {
        case 'C' :
            switch (Level(*B)) {
            case 2 :
                A(*B) = 15;
                M(*B) = 60;
                Pb(*B) = false;
                break;
            case 3 :
                A(*B) = 20;
                M(*B) = 80;
                Pb(*B) = false;
                break;
            case 4 :
                A(*B) = 25;
                M(*B) = 100;
                Pb(*B) = false;
                break;
            }
            printf("Your Castle leveled up to level %d!\n", Level(*B));
            break;
        case 'T' :
            switch (Level(*B)) {
            case 2 :
                A(*B) = 10;
                M(*B) = 30;
                Pb(*B) = true;
                break;
            case 3 :
                A(*B) = 20;
                M(*B) = 40;
                Pb(*B) = true;
                break;
            case 4 :
                A(*B) = 30;
                M(*B) = 50;
                Pb(*B) = true;
                break;
            }
            printf("Your Tower leveled up to level %d!\n", Level(*B));
            break;
        case 'F' :
            switch (Level(*B)) {
            case 2 :
                A(*B) = 20;
                M(*B) = 40;
                Pb(*B) = false;
                break;
            case 3 :
                A(*B) = 30;
                M(*B) = 60;
                Pb(*B) = true;
                break;
            case 4 :
                A(*B) = 40;
                M(*B) = 80;
                Pb(*B) = true;
                break;
            }
            printf("Your Fort leveled up to level %d!\n", Level(*B));
            break;
        case 'V' :
            switch (Level(*B)) {
            case 2 :
                A(*B) = 10;
                M(*B) = 30;
                Pb(*B) = false;
                break;
            case 3 :
                A(*B) = 15;
                M(*B) = 40;
                Pb(*B) = false;
                break;
            case 4 :
                A(*B) = 20;
                M(*B) = 50;
                Pb(*B) = false;
                break;
            }
            printf("Your Village leveled up to level %d!\n", Level(*B));
            break;
        }
    }
}

void SetLvBuildingToLv1 (Building* B) {
/*  I.S. B terdefinisi
    F.S. B menjadi level 1 dengan segala komponen di dalamnya diubah */
    Level(*B) = 1;
    switch(Type(*B)) {
    case 'C' :
        A(*B) = 10;
        M(*B) = 40;
        Pb(*B) = false;
        break;
    case 'T' :
        A(*B) = 5;
        M(*B) = 20;
        Pb(*B) = true;
        break;
    case 'F' :
        A(*B) = 10;
        M(*B) = 20;
        Pb(*B) = false;
        break;
    case 'V' :
        A(*B) = 5;
        M(*B) = 20;
        Pb(*B) = false;
        break;
    }
}

void PrintBuilding(Building B) {
/* Menampilkan info bangunan B */
    switch (Type(B)) {
        case 'C' :
            printf("Castle lv. %d (%d,%d): %d troops\n", Level(B), Koordinat(B).x, Koordinat(B).y, Troops(B));
            break;
        case 'T' :
            printf("Tower lv. %d (%d,%d): %d troops\n", Level(B), Koordinat(B).x, Koordinat(B).y, Troops(B));
            break;
        case 'F' :
            printf("Fort lv. %d (%d,%d): %d troops\n", Level(B), Koordinat(B).x, Koordinat(B).y, Troops(B));
            break;
        case 'V' :
            printf("Village lv. %d (%d,%d): %d troops\n", Level(B), Koordinat(B).x, Koordinat(B).y, Troops(B));
            break;
    }

}

Building CopyBuilding(Building Bin) { 
/*  Mengembalikan salinan dari Bin */
    /* Kamus Lokal */
    Building Bout;
    
    /* Algoritma */
    Koordinat(Bout) = Koordinat(Bin);
    Type(Bout) = Type(Bin);
    Troops(Bout) = Troops(Bin);
    Level(Bout) = Level(Bin);
    A(Bout) = A(Bin);
    M(Bout) = M(Bin);
    Pb(Bout) = Pb(Bin);
    U(Bout) = U(Bin);
    AfterAttack(Bout) = AfterAttack(Bin);
    AfterMove(Bout) = AfterMove(Bin);
    return Bout; 
}


