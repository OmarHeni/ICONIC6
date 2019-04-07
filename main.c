#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"work.h"
int main(void)
{
TTF_Init();
screen sc;
background bg;
perso p;
barrevie b;
texte t;
SDL_Event event;
SDL_Init(SDL_INIT_VIDEO);


int sco=0;
int done=1;
char pause;
//*******************************************************************************
//************************************************************
sc.s=SDL_SetVideoMode(1200,600,32, SDL_HWSURFACE |SDL_DOUBLEBUF);
bg.image=SDL_LoadBMP("background.bmp");
p.imageper=IMG_Load("Fichier 1.png");
b.imagebarre=IMG_Load("barrevie.png");

//*******************************************************************************

bg.pos.x=0;
bg.pos.y=0;
bg.pos.w=bg.image->w;
bg.pos.h=bg.image->h;

p.posper.x=20;
p.posper.y=260;
b.posbarre.x=0;
b.posbarre.y=0;


//*******************************************************************************
SDL_Init(SDL_INIT_EVERYTHING);
if( SDL_Init(SDL_INIT_EVERYTHING)!=0){
printf("unabel to initialize SDL:%s\n",SDL_GetError());
return (-1);
}
//***************************************************************************************************
InitAff(sc,bg,p,b);
//*******************************************************************************
 t.police= TTF_OpenFont("BebasNeue-Book.ttf", 25);
t.color.r = 255;
t.color.g = 255;
t.color.b = 255;

  t.postexte.x = 60;
  t.postexte.y = 370;


  SDL_EnableKeyRepeat(20,20);

while(SDL_PollEvent(&event))
{switch(event.type)
 { case SDL_QUIT:
    done=0;
   break;
   case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
     {
       case SDLK_ESCAPE:
         done=0;
        break;
       case  SDLK_UP:
        Update_score(t,sc,sco);
        break;

    }
  }
}
//*******************************************************************
pause=getchar();
TTF_Quit();
SDL_Quit();
return 0 ;
}

