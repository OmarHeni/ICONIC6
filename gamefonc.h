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
FILE *f ;
SDL_Surface *fenetre ;
SDL_Event event ;
SDL_Surface *paysage ;
SDL_Rect pos ;
SDL_Rect ecran ;
int run ; 
SDL_Rect camera ;
}stage ;

/*****************************************/

typedef struct {
int direc;
int bol[5];
TTF_Font *font ;
SDL_Surface *man ;
SDL_Surface *sscore ;
SDL_Rect pos1 ;
SDL_Rect possco ;
int score ; 
int vie ;
SDL_Surface *carre ;
SDL_Rect spos;
SDL_Rect sangpos;
SDL_Rect pos2 ;
SDL_Surface *barre ;
SDL_Surface *song ;
SDL_Rect spart ;
SDL_Rect part[6] ;
int pos ;
SDL_Event event ;
} manr;

/*****************************************/

typedef struct {
int tmp ;
SDL_Rect post ;
TTF_Font *font ;
SDL_Surface *temp ;
int prec ;
int suiv ;
int Num_try ;
int Num_en ;
int t[2] ; 
SDL_Surface *menueng ; 
SDL_Rect posg ;
SDL_Surface *reponse[3] ;
int selec[3] ;
SDL_Rect posen[3] ;
}enigme ; 

typedef struct {
int  i ;
SDL_Surface *gun ;
SDL_Rect mpos ;
SDL_Surface *ball ;
SDL_Rect bpos ;
}machine;

typedef struct {
int prec ;
int now ;
int direc ;
int part ;
SDL_Surface *ball ;
SDL_Rect bpos ;
SDL_Surface *sen ;
SDL_Rect enpart [17];
SDL_Rect posenm ;
}enemie;


void action (stage *sta,manr *manj,menus *menu , machine *mach ,enemie *enm);
void Arduino_Update(stage *sta,manr *manj);
int  showmenu(stage *sta,menus *menu );
void menufree( stage *sta,menus *menu);
int collision (SDL_Rect pos1 ,SDL_Rect pos2);
void eveent (stage *sta,manr *manj);
void dispose (stage *sta,manr *manj,machine *mach,enemie *enm);
void Position_Update (stage *sta,manr *manj);
void intialiser_en (enigme *en );
void Machine_Position (machine * mach, manr *manj,stage *sta);
int menigme(enigme  *en,stage *sta );
void freeenigme(enigme *en);
void freesurface(stage *sta , manr *manj);
void intial (enigme *en );
int reponse (enigme *en,int j);
void Update_enemie (enemie *enm,manr *manj);
void Update_temp(enigme *en,stage *sta,int *rep);
#endif
