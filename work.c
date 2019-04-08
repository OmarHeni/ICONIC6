#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"work.h"


//*******************************************************************************
void deplacement (perso *p,SDL_Event event,int done,int *detection,rock *r,SDL_Event *felsa,texte *t ,screen *sc,int *sco,vie *v)
{
int test;
while(SDL_PollEvent(&event))
{switch(event.type)
 { case SDL_QUIT:
    done=0;
   break;
   case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
     {
      case  SDLK_UP:
        test=1;
           if(*detection==0)
          {
          p->posper.y -= 4;
         *detection=collision(p,r);
         test=0;
          }
         else if((*detection==1) && (felsa->key.keysym.sym!=event.key.keysym.sym))
         {
          p->posper.y -= 4;
         *detection=collision(p,r);
         test=0;
         }
         if (test==1){
                initialiser_score(t ,sc,sco);
                Update_Vie(v,sco,sc);
         }

        felsa->key.keysym.sym=event.key.keysym.sym;
        break;
       case SDLK_DOWN:
            test=1;
           if(*detection==0)
          {
          p->posper.y+=4;
         *detection=collision(p,r);
         test=0;
          }
         else if((*detection==1) && (felsa->key.keysym.sym!=event.key.keysym.sym))
         {
          p->posper.y+=4;
         *detection=collision(p,r);
         test=0;
         }
         if (test==1){
                initialiser_score(t ,sc,sco);
                Update_Vie(v,sco,sc);
         }
         felsa->key.keysym.sym=event.key.keysym.sym;
        break;
       case SDLK_RIGHT:
            test=1;
            if(*detection==0)
          {
          p->posper.x+= 4;
         *detection=collision(p,r);
         test=0;
          }
         else if((*detection==1) && (felsa->key.keysym.sym!=event.key.keysym.sym))
         {
          p->posper.x+= 4;
         *detection=collision(p,r);
         test=0;
         }
         if (test==1){
                initialiser_score(t ,sc,sco);
                Update_Vie(v,sco,sc);
         }

         felsa->key.keysym.sym=event.key.keysym.sym;


        break;
       case SDLK_LEFT:
             test=1;
            if(*detection==0)
          {
          p->posper.x-= 4;
         *detection=collision(p,r);
         test=0;
          }
         else if((*detection==1) && (felsa->key.keysym.sym!=event.key.keysym.sym))
         {
          p->posper.x-= 4;
         *detection=collision(p,r);
         test=0;
         }
         if (test==1){
         initialiser_score(t ,sc,sco);
         Update_Vie(v,sco,sc);
         }
         felsa->key.keysym.sym=event.key.keysym.sym;


         break;
}
}
}
}

//*******************************************************************************
void InitAff(screen sc,background bg,perso p,vie v,rock r)
{

SDL_BlitSurface(bg.image,NULL,sc.s,&bg.pos);
SDL_BlitSurface(p.imageper,NULL,sc.s,&p.posper);
SDL_BlitSurface(v.barre,NULL,sc.s,&v.posbarre);
SDL_BlitSurface(v.sang,NULL,sc.s,&v.possang);
SDL_BlitSurface(r.imagerock,NULL,sc.s,&r.posrock);
SDL_Flip(sc.s);

}
//*******************************************************************************
void initialiser_score(texte *t ,screen *sc,int *sco)
{
TTF_Init();
t->police= TTF_OpenFont("BebasNeue-Book.ttf", 40);
t->color.r = 255;
t->color.g = 0;
t->color.b = 0;

  t->postexte.x = 400;
  t->postexte.y = 0;
char ch[10];
*sco+=10 ;
sprintf(ch,"%d XP",*sco);
t->txt=TTF_RenderText_Solid(t->police,ch,t->color);
SDL_BlitSurface(t->txt,NULL,sc->s,&t->postexte);
SDL_Flip(sc->s);
TTF_Quit();
}
//************************************************************************************


int collision (perso *p, rock *r)
{
if (p->posper.y>=r->posrock.y+r->posrock.h)
return 0;
if (p->posper.x>=r->posrock.x+r->posrock.w)
return 0;
if (p->posper.y+p->posper.h<=r->posrock.y)
return 0 ;
if (p->posper.x+p->posper.w<=r->posrock.x)
return 0 ;
return 1 ;
}
//************************************************************************************



void Update_Vie (vie *v,int *sco,screen *sc)
{
if (v->nbvie>0){

v->nbvie -= 10 ;
}
if (v->nbvie <=0 ){
*sco = 0 ;
v->sizevie.w = 0;
}else{
v->nbvie -= 10 ;
v->sizevie.w =v->nbvie ;
}
SDL_BlitSurface(v->barre,NULL,sc->s,&v->posbarre);
SDL_BlitSurface(v->sang,&v->sizevie,sc->s,&v->possang);
}




