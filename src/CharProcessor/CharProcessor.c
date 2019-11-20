#include "CharProcessor/CharProcessor.h"
#include <stdio.h>

char CC;
bool EOP;
bool cpStarted = false;
bool cpReadFromFile;

static FILE * cpStream;
static int retval;

bool START(char* path) {

    /* Algoritma */
    if (cpStarted && cpReadFromFile) {
        fclose(cpStream);
    }
    cpStarted = true;

    cpReadFromFile = (path != NULL);
    if (cpReadFromFile) {
        cpStream = fopen(path, "r");
    } else {
        cpStream = stdin;
    }
    
    ADV();
    return cpStream != NULL;
}

void ADV() {
    
    retval = fscanf(cpStream,"%c",&CC);
    EOP = (retval < 1);
    if (cpReadFromFile && EOP) {
        fclose(cpStream);
    }
}
