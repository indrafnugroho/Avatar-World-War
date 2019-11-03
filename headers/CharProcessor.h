/*
CharProcessor.h
DEFINISI ADT MESIN KARAKTER <CharProcessor>
*/

#ifndef _CHARPROCESSOR_H
#define _CHARPROCESSOR_H

#include "bool.h"

/* State Mesin */
extern char CC;
extern bool EOP;
extern bool cpStarted;
extern bool cpReadFromFile;

void START(char* path);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika EOF maka EOP akan bernilai true 
          Jika tidak maka EOP akan bernilai false */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, !EOP
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          Jika EOF maka EOP akan bernilai true*/

#endif
