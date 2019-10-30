#include "CharProcessor.h"
#include <stdio.h>

char CC;
bool EOP;

bool readFromFile;
static FILE * pita;
static int retval;

void START(char* path) {

    /* Algoritma */
    if (path == NULL) {
        pita = stdin;
        readFromFile = false;
    } else {
        pita = fopen(path, "r");
        readFromFile = true;
    }
    ADV();
}

void ADV() {

    /* Algoritma */
    retval = fscanf(pita,"%c",&CC);
    if (readFromFile) {
        EOP = (retval == EOF);
    } else {
        EOP = (CC == '\n');
    }
    if (EOP) {
       fclose(pita);
    }
}