#include <stdlib.h>
#include <stdio.h>
#include "hexreader.h"


hexstream readstream(char* filename) {
    FILE *fp;
    hexstream hs;
    char line[32];

    fp = fopen(filename, "r+");
    if(fp == NULL) {
      perror("Error opening file");
      exit(-1);
    }

    int i;
    for (i = 0 ; i < STREAMMAX ; i++) {
        if (fgets(line, sizeof(line), fp) == NULL) {
            break;
        }
        else {
            if (sscanf(line, "%lx", &hs.stream[i]) == 0) {
                printf("Hex-value in input file (%s) is not correctly formatted.\n", filename);
                exit(0);
            }
        }
    }
    hs.length = i;
    return hs;
}
