#include <stdio.h>
#include <stdlib.h>
#include "mandelbrot.h"
#include "pgm.h"

int main(int argc, char *argv[]) {
    printf("Constructing mandelbrot set\n");

    int tableSize;
    if (argc>1){
        tableSize = atoi(argv[1]);
    }else{
        tableSize = 1001;
    }

    const char outputPath[] = "output_img.pgm";

    printf("Table size: %d\n", tableSize);
    struct MandelbrotSet set = construct_set(tableSize, 1);

    int result = write_image_file(set, outputPath);
    if (result==0){
        printf("Wrote output file at %s\n", outputPath);
        return 0;
    }else{
        printf("Failed to write output file\n");
        return -1;
    }

}
