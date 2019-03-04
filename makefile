
prog:main.o gamefonc.o
	gcc main.o gamefonc.o  -o prog -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc main.c -c  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
gamefonc.o:gamefonc.c 
	gcc gamefonc.c -c  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

