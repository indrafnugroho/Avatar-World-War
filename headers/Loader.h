/*
Loader.h
DEFINISI ADT MESIN KATA <Loader>
*/

#ifndef _LOADER_H
#define _LOADER_H

#include "WordProcessor.h"
#include "Building.h"
#include "ArrayDin.h"
#include "Graph.h"
#include "GameMap.h"

void ReadConfigFile(char* path, ArrayDin* buildings, Graph* connect, GameMap* map);
/*
I.S.
    Terdapat file eksternal berisi konfigurasi awal permainan.
F.S.
    File konfigurasi dibaca dan diolah sehingga siap dibuat GameMap.
*/

#endif
