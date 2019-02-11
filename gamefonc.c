#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include"gamefonc.h"

void action (stage  *sta,manr *manj ){
SDL_Surface *tmp=NULL;
sta->fenetre=NULL ;
manj->man =NULL ;
if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
printf ("%s  \n",Mix_GetError());
}
sta-> music = Mix_LoadMUS("GAME intro.mp3");
Mix_PlayMusic(sta->music,-1);

sta->fenetre = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
SDL_WM_SetCaption("Tate no yusha",NULL);
sta->paysage=SDL_LoadBMP("/home/omar/gr.bmp");
manj->doura = IMG_Load("doura.jpg");
SDL_GetClipRect(manj->doura,&manj->pos2);
SDL_GetClipRect(sta->paysage,&sta->pos);
tmp = IMG_Load("/home/omar/skar.png");
manj->man=SDL_DisplayFormatAlpha(tmp) ;
SDL_GetClipRect(manj->man,&manj->pos1);
manj->pos2.x=1000;
manj->pos2.y=300;

manj->pos1.x=0;
manj->pos1.y=300;
}
void event (stage *sta){
switch (sta->event.type){
case SDL_QUIT :
sta->run =0;
break;
case SDL_KEYDOWN :
if (sta->event.key.keysym.sym==SDLK_ESCAPE){
sta->run =0;
}
break ;
}
}
void update (manr *manj,stage *sta){
int dx =manj->pos1.x ;
int dy =manj->pos1.y ; 
switch (sta->event.type){
case SDL_KEYDOWN :
if(sta->event.key.keysym.sym==SDLK_RIGHT) {
dx=dx+5 ;
}
if (sta->event.key.keysym.sym==SDLK_LEFT){
dx=dx-5 ;
}
if (sta->event.key.keysym.sym==SDLK_UP){
dy=dy-5 ;
}
if (sta->event.key.keysym.sym==SDLK_DOWN){
dy=dy+5 ;
}
break ;
}

manj->pos1.x=dx  ;
manj->pos1.y=dy ;
if (dx==800){
manj->pos1.x=0;
}
}

void dispose (stage *sta,manr *manj){
SDL_BlitSurface(sta->paysage,&sta->camera,sta->fenetre,NULL);
SDL_BlitSurface(manj->man,NULL,sta->fenetre, & manj->pos1);

SDL_Flip(sta->fenetre);
}

void scroll (stage *sta,manr *manj){
static int bol[2]={0,0};
static int lp =0;
sta->camera.w=800;
sta->camera.h=600;
switch (sta->event.type){
case SDL_KEYDOWN :
switch (sta->event.key.keysym.sym){
case SDLK_RIGHT :
bol[0]=1 ;
break;
case SDLK_LEFT : 
bol[1]=1;
break;
}
break;
case SDL_KEYUP :
switch (sta->event.key.keysym.sym){
case SDLK_RIGHT :
bol[0]=0 ;
break;
case SDLK_LEFT : 
bol[1]=0;
break;
}
break;
}
if (bol[0]==1){
(sta->camera.x)+=5;
printf (" camera = %d \n",sta->camera.x);
}else if (bol[1]==1){
(sta->camera.x)-=5;
}
if (sta->camera.x>=(2000-800)){
sta->camera.x=0;
lp++ ; 
if (lp>1){
SDL_BlitSurface(manj->doura,NULL,sta->fenetre,& manj->pos2);
}
}

if (sta->camera.x<=0){
sta->camera.x=0;
}
}
