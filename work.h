#ifndef GAME_FONC
#define GAME_FONC
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct {
SDL_Surface *boutons[2];
SDL_Surface *menu ;
SDL_Surface *menu2;
int selec[2];
SDL_Rect posm ;
SDL_Rect pos[2];
Mix_Chunk *musicb;
int h ;
int j;
int m;
int o;
int l;
}menusj ;

typedef struct{
SDL_Surface* s;
}screen;
typedef struct{
SDL_Surface* imageper;
SDL_Rect posper;
SDL_Surface* imagenokta;
SDL_Rect posnokta1;
}perso;
typedef struct{
SDL_Surface* imagerock;
SDL_Rect posrock;
}rock;
typedef struct{
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
SDL_Surface* imagemini;
SDL_Rect posmini;

}background;
typedef struct{
SDL_Surface* txt;
SDL_Rect postexte;
TTF_Font *police;
SDL_Color color;
}texte;
int showmenud(screen *sc,menusj *menuj );
void save(perso *p,vie *v,int *sco,char nomf[]);
void re(perso *p,vie *v,int *sco,char nomf[],texte *t,screen *sc);
void button (SDL_Event *event,perso *p);
int showmenud2(screen *sc,menusj *menuj );
void setpositions (background *bg,rock *r,perso *p,vie *v,menusj *menuj);
void update (int *test,int *detection,perso *p,SDL_Event *felsa,SDL_Event *event,texte *t,int *sco,screen *sc,vie *v,rock *r);
void load(screen *sc,background *bg, perso *p,rock *r,vie *v,menusj *menuj);
int InitAff(screen sc,background bg,perso p,vie v,rock r,texte t,menusj *menuj,int done2);
void initialiser_score(texte *t ,screen *sc,int *sco);
void deplacement (perso *p,SDL_Event event,int *done,int *detection,rock *r,SDL_Event *felsa,texte *t ,screen *sc,int *sco,vie *v,menusj *menuj);
int collision (perso *p, rock *r);
void Update_Vie (vie *v,int *sco,screen *sc);
#endif





