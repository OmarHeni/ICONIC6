#ifndef MYWORK_H_INCLUDED
#define MYWORK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL_rotozoom.h"


typedef struct
{
float zom ;
SDL_Surface* e;
SDL_Surface* imageFond;
SDL_Rect positionFond;
SDL_Rect posecran;
SDL_Rect camera;
}ecran;

typedef struct
{
int rota ;
SDL_Surface* personnage;
SDL_Rect posPer;
SDL_Event event ;
int continuer;
}perso;

typedef struct
{
int rota ;
SDL_Surface* personnage;
SDL_Rect posPer;
SDL_Event event ;
int continuer;
}perso1;

typedef struct
{
int x;
int y;
SDL_Rect rect;
SDL_Surface *image;
double angle;
SDL_Surface *rotation;
int tempsPrecedent;
int tempsActuel,TEMPS;
}zoom;
void init_positions(ecran *e,perso *p,perso1 *p1,zoom *z);
void init_affich(ecran *e,perso *p,perso1 *p1);
void scroll(ecran *e,perso *p,perso1 *p1);
//void rotozoom  (zoom *z,ecran *e,perso *p);
#endif // MYWORK_H_INCLUDED
