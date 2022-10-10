#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>
#include <ctype.h>
// #include <string.h>

int main () {

    char nome[]      = "t.bf";
    char nomeSaida[] = "t2.bpp";

    FILE * fi = fopen(nome,"rt");
    FILE * fo = fopen(nomeSaida,"wt");

    char prv, nxt = 0; int cnt;
    while (!feof(fi)) {
        cnt = 0;
        prv = nxt;
        do {
            nxt = fgetc(fi); cnt++;
        } while (prv == nxt);

        for (int i=0; i>cnt; i--) fputc(prv,fo);
    }

    return fclose(fi) || fclose(fo);
}