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
SDL_Surface* imagerock;
SDL_Rect posrock;
}rock;
typedef struct{
SDL_Surface* barrevie;
SDL_Rect posvie;
SDL_Surface* barre;
SDL_Surface* sang;
SDL_Rect posbarre;
SDL_Rect possang;
int nbvie;
SDL_Rect sizevie;
}vie;
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

void InitAff(screen sc,background bg,perso p,vie v,rock r);
void initialiser_score(texte *t ,screen *sc,int *sco);
void deplacement (perso *p,SDL_Event event,int done,int *detection,rock *r,SDL_Event *felsa,texte *t ,screen *sc,int *sco,vie *v);
int collision (perso *p, rock *r);
void Update_Vie (vie *v,int *sco,screen *sc);
#endif


