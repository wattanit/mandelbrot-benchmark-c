//
// Created by Wattanit Hotrakool on 21/2/2023 AD.
//
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define MAX_ITER 500

struct MandelbrotSet{
    int **gridTable;
    int tableSize;
};

struct ComplexVector{
    double re;
    double im;
};

struct ComplexVector complex_multiply(struct ComplexVector v1, struct ComplexVector v2){
    struct ComplexVector result;
    result.re = (v1.re * v2.re) + (v1.im * v2.im * -1);
    result.im = (v1.re * v2.im) + (v1.im * v2.re);
    return result;
}

struct ComplexVector complex_add(struct ComplexVector v1, struct ComplexVector v2){
    struct ComplexVector result;
    result.re = v1.re + v2.re;
    result.im = v1.im + v2.im;
    return result;
}

double complex_abs(struct ComplexVector v){
    double abs = sqrt((v.re * v.re) + (v.im * v.im));
    return abs;
}

short check_mandelbrot_membership(struct ComplexVector C){
    struct ComplexVector Z;
    Z.re = 0.0;
    Z.im = 0.0;

    for(int iter=0; iter<MAX_ITER; iter++){
        struct ComplexVector Z_squared = complex_multiply(Z, Z);
        struct ComplexVector Z_new = complex_add(Z_squared, C);

        if (complex_abs(Z_new)>=2.0){
            return 0;
        }else{
            Z.re = Z_new.re;
            Z.im = Z_new.im;
        }
    }

    return 1;
}

struct MandelbrotSet create_empty_set(int tableSize){
    struct MandelbrotSet set;
    set.tableSize = tableSize;

    set.gridTable = (int**) calloc(tableSize, sizeof(int*));
    for(int r=0; r<tableSize; r++){
        set.gridTable[r] = (int*) calloc(tableSize, sizeof(int));
    }

    return set;
}

struct MandelbrotSet construct_set(int tableSize, short verbose){
    struct MandelbrotSet set = create_empty_set(tableSize);

    if ((tableSize % 2)!=1){
        printf("[Error] grid size must be odd number\n");
        return set;
    }

    int r_center = tableSize/2;
    int c_center = tableSize/2;
    double r_scale = (double) r_center/2;
    double c_scale = (double) c_center/2;

    for(int r=0; r<tableSize; r++){
        if (verbose>0){
            printf("checking row %d\n", r);
        }

        for(int c=0; c<tableSize; c++){
            struct ComplexVector C;
            C.re = ((double) r-r_center)/r_scale;
            C.im = ((double) c-c_center)/c_scale;

            short is_set_member = check_mandelbrot_membership(C);
            if (is_set_member==1){
                set.gridTable[r][c] = 255;
            }else{
                set.gridTable[r][c] = 0;
            }
        }
    }

    return set;
}