#include "CharProcessor.h"
#include <stdio.h>

char CC;
bool EOP;
bool cpStarted = false;
bool cpReadFromFile;

static FILE * cpStream;
static int retval;

void START(char* path) {

    /* Algoritma */
    cpStarted = true;
    if (path == NULL) {
        cpStream = stdin;
        cpReadFromFile = false;
    } else {
        cpStream = fopen(path, "r");
        cpReadFromFile = true;
    }
    ADV();
}

void ADV() {
    
    retval = fscanf(cpStream,"%c",&CC);
    EOP = (retval < 1);
    if (cpReadFromFile && EOP) {
        fclose(cpStream);
    }
}