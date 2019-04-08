#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"work.h"
int main(void)
{
char ch[10] ;
TTF_Init();
screen sc;
background bg;
perso p;
vie v;
texte t;
rock r;
SDL_Event event;
SDL_Init(SDL_INIT_EVERYTHING);
SDL_Event felsa;
int detection=0;
int sco=0;
int done=1;
char pause;


//*******************************************************************************
sc.s=SDL_SetVideoMode(1200,600,32, SDL_HWSURFACE |SDL_DOUBLEBUF);
bg.image=SDL_LoadBMP("background.bmp");
p.imageper=IMG_Load("Fichier 1.png");
v.barrevie=IMG_Load("barrevie.png");
r.imagerock=IMG_Load("rock.png");
v.barre=IMG_Load("barre.png");
v.sang=IMG_Load("sang.png");

//*******************************************************************************
SDL_Init(SDL_INIT_EVERYTHING);
if( SDL_Init(SDL_INIT_EVERYTHING)!=0){
printf("unabel to initialize SDL:%s\n",SDL_GetError());
return (-1);
}
//*******************************************************************************
initialiser_score(&t ,&sc,&sco);
//*******************************************************************************
bg.pos.x=0;
bg.pos.y=0;
bg.pos.w=bg.image->w;
bg.pos.h=bg.image->h;


r.posrock.x=500;
r.posrock.y=300;
r.posrock.w=r.imagerock->w;
r.posrock.h=r.imagerock->h;

p.posper.x=20;
p.posper.y=260;
p.posper.w=p.imageper->w;
p.posper.h=p.imageper->h;

v.posvie.x=0;
v.posvie.y=0;
v.posbarre.x=0;
v.posbarre.y=0;
v.possang.x=59;
v.possang.y=11;
v.sizevie.w=v.sang->w;
v.sizevie.h=v.sang->h;

//*********************************************************************
InitAff(sc,bg,p,v,r);
//*********************************************************************
detection=collision(&p,&r);
//*************************************DEPLACEMENT*********************
SDL_EnableKeyRepeat(20,20);
SDL_BlitSurface(v.barre,NULL,sc.s,&v.posbarre);
SDL_BlitSurface(v.sang,NULL,sc.s,&v.possang);
while(done)
{
InitAff(sc,bg,p,v,r);
deplacement(&p,event,done,&detection,&r,&felsa,&t ,&sc,&sco,&v);
SDL_BlitSurface(t.txt,NULL,sc.s,&t.postexte);
SDL_Flip(sc.s);
}
//*************************************DEPLACEMENT*********************


pause=getchar();
 TTF_CloseFont(t.police);
    TTF_Quit();

    SDL_FreeSurface(t.txt);
    SDL_Quit();

return 0 ;
}

