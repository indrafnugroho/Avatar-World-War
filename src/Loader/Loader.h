/*
Loader.h
DEFINISI ADT MESIN KATA <Loader>
*/

#ifndef _LOADER_H
#define _LOADER_H

#include "WordProcessor/WordProcessor.h"
#include "Building/Building.h"
#include "ArrayDin/ArrayDin.h"
#include "Graph/Graph.h"
#include "GameMap/GameMap.h"

void ReadConfigFile(char* path, ArrayDin* buildings, Graph* connect, GameMap* map);
/*
Menghasilkan konfigurasi permainan baru dari file konfigurasi
I.S.
    Terdapat file eksternal berisi konfigurasi awal permainan.
F.S.
    File konfigurasi dibaca dan diolah sehingga siap dibuat 
*/

void SaveGameFile(char* path, Player P1, Player P2, ArrayDin buildings, Graph connect, GameMap map, int turn);
/*
Menyimpan game ke dalam file  konfigurasi
I.S.
    Semua parameter telah terdefinisi
F.S.
    Nilai nilai yang ada di parameter disimpan ke dalam file konfigurasi path
*/
void LoadGameFile(char* path, Player* P1, Player* P2, ArrayDin* buildings, Graph* connect, GameMap* map, Player** Pturn);
/*
Memuat permainan dari file save ke parameter yang dibutuhkan untuk game
I.S.
    File save dengan path "path" ada, parameter lain sembarang
F.S.
    File save dibaca dan nilai-nilainya dimasukkan ke dalam parameter-parameter 
*/
#endif
