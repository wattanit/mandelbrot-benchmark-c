//
// Created by Wattanit Hotrakool on 21/2/2023 AD.
//

#ifndef FOO_WORLD_MANDELBROT_H
#define FOO_WORLD_MANDELBROT_H

#endif //FOO_WORLD_MANDELBROT_H

struct MandelbrotSet{
    int **gridTable;
    int tableSize;
};

struct ComplexVector complex_multiply(struct ComplexVector v1, struct ComplexVector v2);
struct ComplexVector complex_add(struct ComplexVector v1, struct ComplexVector v2);
double complex_abs(struct ComplexVector v);
short check_mandelbrot_membership(struct ComplexVector C);
struct MandelbrotSet create_empty_set(int tableSize);
struct MandelbrotSet construct_set(int tableSize, short verbose);