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
I.S.
    Terdapat file eksternal berisi konfigurasi awal permainan.
F.S.
    File konfigurasi dibaca dan diolah sehingga siap dibuat GameMap.
*/

#endif
