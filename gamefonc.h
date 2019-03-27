#ifndef GAME_FONC
#define GAME_FONC
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct{
SDL_Surface *boutons[4];
SDL_Surface *boutonsa[4];
SDL_Surface *menua ;
SDL_Surface *menu ;
SDL_Surface *iconic ;
SDL_Rect posi ;
TTF_Font *font ;
int frame ;
int selec[4];
SDL_Rect poss1[4];
SDL_Rect posm[5];
SDL_Rect poss[4];
Mix_Chunk *musicb;
int j ; 
int h ; 
}menus ;

/***************************************/

typedef struct{
Mix_Music *music;
SDL_Surface *fenetre ;
SDL_Event event ;
SDL_Surface *paysage ;
SDL_Rect pos ;
int run ; 
SDL_Rect camera ;
}stage ;

/*****************************************/

typedef struct {
SDL_Surface *man ;
SDL_Rect pos1 ;
SDL_Surface *carre ;
SDL_Rect pos2 ;
SDL_Event event ;
} manr;

/*****************************************/

typedef struct {
int Num_try ;
int Num_en ;
int t[2] ; 
SDL_Surface *menueng ; 
SDL_Rect posg ; 
SDL_Surface *reponse[3] ;
int selec[3] ;
SDL_Rect posen[3] ;
}enigme ; 


void action (stage  *sta,manr *manj,menus *menu );
int  showmenu(stage *sta,menus *menu );
void menufree( stage *sta,menus *menu);
int collision (SDL_Rect pos1 ,SDL_Rect pos2);
void eveent (stage *sta, int bol[]);
void dispose (stage *sta,manr *manj);
void Position_Update (stage *sta,manr *manj);
void intialiser_en (enigme *en );
int menigme(enigme  *en,stage *sta );
void freeenigme(enigme *en);
void freesurface(stage *sta , manr *manj);
void intial (enigme *en );
int reponse (enigme *en,int j);
#endif
