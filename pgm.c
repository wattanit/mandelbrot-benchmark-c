#include <stdio.h>
#include <stdlib.h>
#include "mandelbrot.h"

int write_image_file(struct MandelbrotSet set, const char *filePath){
    FILE* outputFile;
    outputFile = fopen(filePath, "wb");
    if (outputFile==NULL){
        printf("[Error] Failed to open output file %s", filePath);
        return -1;
    }

    // Writing Magic Number to the File
    fprintf(outputFile, "P2\n");

    // Writing Width and Height into the file
    fprintf(outputFile, "%d %d\n", set.tableSize, set.tableSize);

    // Writing the maximum gray value
    fprintf(outputFile, "255\n");

    // Write image data
    for(int c=0; c<set.tableSize; c++){
        for(int r=0; r<set.tableSize; r++){
            fprintf(outputFile, "%d ", set.gridTable[r][c]);
        }
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);

    return 0;
}