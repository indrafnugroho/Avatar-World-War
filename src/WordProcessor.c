#include <stdio.h>
#include "WordProcessor.h"
#include "CharProcessor.h"

Word CWord;
Word TEMPWORD;
bool EndWord;

const char MAXNUMASCII = '9';
const char MINNUMASCII = '0';

void CreateEmpty(Word* w) {
    int i;
    for (i = 0; i < NMax; i++) {
        (*w).Tab[i] = MARK;
    }
}

void IgnoreBlank()
{
    while ((CC == BLANK || CC == NEWLINE) && !EOP) {
        ADV();
    }
}

void STARTWORD(char* path)
{
    EndWord = false;
    CreateEmpty(&CWord);
    if (path != NULL || !cpStarted || (path == NULL && (cpReadFromFile))) {
        START(path);
    }
    ADVWORD();
}

void ADVWORD()
{
    IgnoreBlank();
    if (EOP) {
        EndWord = true;
    } else {
        EndWord = false;
        SalinWord();
    }
}

void SalinWord()
{
    CreateEmpty(&CWord);
    int i = 0;
    while (i < NMax && !EOP && (CC != BLANK && CC != NEWLINE)) {
        CWord.Tab[i] = CC;
        i++;
        ADV();
    }
    if (EOP) {
        EndWord = true;
    }
}

void CopyWord(Word from, Word* to) {
    CreateEmpty(to);
    int i = 0;
    while (i < NMax) {
        if (from.Tab[i] == MARK) {
            i = NMax;
        } else {
            (*to).Tab[i] = from.Tab[i];
            i++;
        }
    }
}

void ScanWord(Word* to) {
    if (!cpStarted || cpReadFromFile) {
        STARTWORD(NULL);
    } else {
        ADVWORD();
    }
    CreateEmpty(to);
    CopyWord(CWord, to);
}

void ScanInt(int* to) {
    ScanWord(&TEMPWORD);
    WordToInt(TEMPWORD, to);
}

void ScanString(char* to, int limit) {
    int rLimit = limit-1;
    int i, j;
    for (i = 0; i < limit; i++) {
        to[i] = MARK;
    }
    i = 0;
    IgnoreBlank();
    while (i < rLimit && !EOP && CC != NEWLINE) {
        ScanWord(&TEMPWORD);
        j = 0;
        while (i < rLimit && TEMPWORD.Tab[j] != MARK) {
            to[i] = TEMPWORD.Tab[j];
            i++;
            j++;
        }
        while (i < rLimit && !EOP && CC == BLANK) {
            to[i] = BLANK;
            i++;
            ADV();
        }
    }
}

void OutputWord(Word w, bool newline) {
    int i = 0;
    bool printed = false;
    while (i < NMax) {
        if (w.Tab[i] == MARK) {
            i = NMax;
        } else {
            printf("%c", w.Tab[i]);
            printed = true;
            i++;
        }
        
    }
    if (printed && newline) printf("\n");
}

void PrintWord(Word w) {
    OutputWord(w, true);
}

void WriteWord(Word w) {
    OutputWord(w, false);
}

bool WordToInt(Word w, int* i) {
    int t = 0;
    int j = 0;
    bool neg = false;
    if (w.Tab[j] == '-') {
        neg = true;
        j = 1;
    }
    while (j < NMax) {
        if (w.Tab[j] == MARK) {
            j = NMax;
        } else {
            if (w.Tab[j] > '9' || w.Tab[j] < '0') {
                return false;
            }
            int a = (w.Tab[j] - '0');
            t = t*10 + a;
            j++;
        }
    }
    
    (*i) = t;
    if (neg) { 
        (*i) *= -1;
    }

    return true;
}