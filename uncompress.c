#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>
#include <ctype.h>
// #include <string.h>

int num (FILE* in, char* c) {
    char num[256]; int i;

    for (i=0; isdigit(*c) && i<255; i++) {
        num[i] = *c; *c = fgetc(in);
    }
    num[i] = '\0';

    return atoi(num);
}

int main () {

    char nome[]      = "t.bpp";
    char nomeSaida[] = "t.bf";

    FILE * fi = fopen(nome,"rt");
    FILE * fo = fopen(nomeSaida,"wt");

    char c;
    while (!feof(fi))
        if (!isdigit(c = fgetc(fi)))
            fputc(c,fo);
        else 
            for (int i=num(fi,&c); i>0; i--)
                fputc(c,fo);

    return 0;
}