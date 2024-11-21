#include "MesinKata.h"
#include "MesinKarakter.h"
#include <stdbool.h>
#include <stdio.h>

bool endKata;
Kata currentKata;

void ignoreBlank() {
    while(cc == BLANK) {
        // puts("a");
        adv();
    }
        // puts("n");
}

void startKata() {
    start(NULL);
    ignoreBlank();
    if(cc == MARK) {
        endKata = true;
    } else {
        endKata = false;
        salinKata();
    }
}

void advKata() {
    ignoreBlank();
    if(cc == MARK) {
        endKata = true;
    } else {
        endKata = false;
        salinKata();
    }
}

void salinKata() {
    int i = 0;
    while((cc != MARK) && (cc != BLANK)) {
        currentKata.buffer[i] = cc;
        adv();
        ++i;
    }

    currentKata.length = i;
}

int main() {
    startKata();
    while(!endKata) {
        for (int i = 0; i < currentKata.length; i++)
        {
            // puts("a");
            printf("%c", currentKata.buffer[i]);
            // puts("a");
        }
        printf("\n");
        advKata();
    }
}
