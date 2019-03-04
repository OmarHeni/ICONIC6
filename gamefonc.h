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

typedef struct{
Mix_Music *music;
SDL_Surface *fenetre ;
SDL_Event event ;
SDL_Surface *paysage ;
SDL_Rect pos ;
int run ; 
SDL_Rect camera ;
}stage ;
typedef struct {
SDL_Surface *man ;
SDL_Rect pos1 ;
SDL_Surface *carre ;
SDL_Rect pos2 ;
SDL_Event event ;
} manr;
void action (stage  *sta,manr *manj,menus *menu );
int showmenu(stage *sta,menus *menu );
void menufree( stage *sta,menus *menu);
void event (stage *sta);
void update (manr *manj,stage *sta);
void dispose (stage *sta,manr *manj);
void scroll (stage *sta,manr *manj);
#endif
