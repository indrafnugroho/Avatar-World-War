/*
Loader.h
DEFINISI ADT MESIN KATA <Loader>
*/

#ifndef _LOADER_H
#define _LOADER_H

#include "WordProcessor.h"
#include "Building.h"

void ReadConfigFile(char* path);
/*
I.S.
    Terdapat file eksternal berisi konfigurasi awal permainan.
F.S.
    File konfigurasi dibaca dan diolah sehingga siap dibuat GameMap.
*/

#endif
