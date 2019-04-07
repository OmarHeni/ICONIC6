#ifndef GAME_FONC
#define GAME_FONC
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct{
SDL_Surface* s;
}screen;
typedef struct{
SDL_Surface* imageper;
SDL_Rect posper;
}perso;
typedef struct{
SDL_Surface* imagebarre;
SDL_Rect posbarre;
}barrevie;
typedef struct{
SDL_Surface* image;
SDL_Rect pos;
}background;
typedef struct{
SDL_Surface* txt;
SDL_Rect postexte;
TTF_Font *police;
SDL_Color color;
}texte;

void InitAff(screen sc,background bg,perso p,barrevie b);
void Update_score(texte t,screen sc,int sco);
#endif


