#ifndef MESIN_KATA_H
#define MESIN_KATA_H

#include "MesinKarakter.h"
#include <stdbool.h>

#define BUFFER_SIZE 100
#define BLANK ' '

#define MARK NEW_LINE

typedef struct {
    char buffer[BUFFER_SIZE];
    int length;
} Kata;

extern bool endKata;
extern Kata currentKata;

void ignoreBlank();
void startKata();
void advKata();
void salinKata();

int getNum();

#endif


