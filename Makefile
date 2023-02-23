all: mandelbrot.o main.o
	gcc mandelbrot.o main.o -o mandelbrot

mandelbrot.o: mandelbrot.c
	gcc -c mandelbrot.c -o mandelbrot.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm *.o mandelbrot