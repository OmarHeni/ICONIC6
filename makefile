prog:main.o fct.o
	gcc main.o fct.o -lSDL -lSDL_image -lSDL_ttf -o prog
main.o:main.c
	gcc main.c  -lSDL -lSDL_image -lSDL_ttf -c
fct.o:fct.c
	gcc -c fct.c
