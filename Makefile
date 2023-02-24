all: mandelbrot.o pgm.o main.o
	gcc mandelbrot.o pgm.o main.o -o mandelbrot

mandelbrot.o: mandelbrot.c
	gcc -c mandelbrot.c -o mandelbrot.o

pgm.o: pgm.c
	gcc -c pgm.c -o pgm.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm *.o mandelbrot