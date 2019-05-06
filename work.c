#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL_rotozoom.h"
#include "MyWork.h"
void init_positions(ecran *e,perso *p,perso1 *p1,zoom *z)
{
e->positionFond.x=0;
e->positionFond.y=0;
p->rota = 0;
p->posPer.x=100;
p->posPer.y=220;

p1->rota = 0;
p1->posPer.x=100;
p1->posPer.y=220;


e->zom = 1.0;
  e->camera.x=0;
  e->camera.y=0;
  e->camera.w=1180;
  e->camera.h=600;

    z->angle= 0;
    z->tempsPrecedent = 0;
    z->tempsActuel = 0;
    z->rect.x =  150;
    z->rect.y =  150;
}

void init_affich(ecran *e,perso *p,perso1 *p1)
{
e->e=SDL_SetVideoMode(1200,600,32, SDL_HWSURFACE |SDL_DOUBLEBUF);
e->imageFond = SDL_LoadBMP("Forest.bmp");
p->personnage = IMG_Load("ALCHIMIST.png");
p1->personnage = IMG_Load("sene.png");
printf ("afff \n");
SDL_BlitSurface(e->imageFond,NULL, e->e , &e->positionFond);
SDL_BlitSurface(p->personnage, NULL, e->e, &p->posPer);
SDL_BlitSurface(p1->personnage, NULL, e->e, &p1->posPer);

}
/************************************************************************************/
void scroll(ecran *e,perso *p,perso1 *p1)
{
static SDL_Surface *rotation ;
static SDL_Surface * zoom ;
static int m ;
const int speed=5;
 static int b[2];
    SDL_PollEvent(&p->event);
        switch(p->event.type){
    case SDL_QUIT:
         p->continuer=0;
        break;
    case SDL_KEYDOWN:
        switch(p->event.key.keysym.sym){
    case SDLK_RIGHT:
        b[0]=1;
        break;
    case SDLK_LEFT:
        b[1]=1;
            break;
  case SDLK_q :
   p->rota-=1 ;
rotation = rotozoomSurface(p->personnage,p->rota,1.0,1);
break;
case SDLK_d :
p->rota +=1 ;
rotation = rotozoomSurface(p->personnage,p->rota,1.0,1);
break;
}
break;
   case SDL_MOUSEBUTTONDOWN :
if (p->event.button.button == SDL_BUTTON_RIGHT){
if (m!=1){
e->zom +=0.1;
if (e->zom >2){
e->zom = 1.0 ;
}
zoom = rotozoomSurface(e->imageFond,0,e->zom,1);
m= 1 ;
}
}
break;
break;
   case SDL_MOUSEBUTTONUP :
m=0;
break;
       case SDL_KEYUP:
        switch(p->event.key.keysym.sym){
    case SDLK_RIGHT:
        b[0]=0;
        break;
    case SDLK_LEFT:
        b[1]=0;
        break;

       }
            break;
       }

 if (b[0]==1){
if (p->posPer.x>=1000){
e->camera.x+=speed;
}else {
  p->posPer.x+=speed;
 }
}
 else {
    if(b[1]==1){
if (p->posPer.x<=200){
  e->camera.x-=speed;
}else {
  p->posPer.x-=speed;
}
        if(e->camera.x<=0)
            e->camera.x=0;
    }
 }
if (e->zom != 1.0){
 SDL_BlitSurface(zoom,&e->camera,e->e,&e->positionFond);
}else {
 SDL_BlitSurface(e->imageFond,&e->camera,e->e,&e->positionFond);
}
if (p->rota != 0){
 SDL_BlitSurface(rotation,NULL,e->e,&p->posPer);
}else {
 SDL_BlitSurface(p->personnage,NULL,e->e,&p->posPer);
}
 



static int x ;
  while (p1->continuer)
{
    SDL_PollEvent(&p1->event);
    switch(p1->event.type)
{
case SDL_QUIT:
    p1->continuer=0;
    break;
case SDL_MOUSEBUTTONDOWN:
    if(p1->event.button.button==SDL_BUTTON_LEFT)
        SDL_Delay(3000);
    x = p1->event.button.x;

    break;
}
if (x!=0)
{
if (x>p1->posPer.x)
{
p1->posPer.x+=8;
}
else if (x<p1->posPer.x)
{
p1->posPer.x -= 8 ;
}
}


if (x==p1->posPer.x)
{
x=0 ;
}

 SDL_BlitSurface(e->imageFond,NULL,e->e,&e->positionFond);
 SDL_BlitSurface(p1->personnage,NULL,e->e,&p1->posPer);
 SDL_Flip(e->e);
}
}
//**********************************************************************************************************************************
/*void rotozoom  (zoom *z,ecran *e,perso *p)
{

 /*while(p->continuer)
    {
        SDL_PollEvent(&p->event);
        switch(p->event.type)
        {
            case SDL_QUIT:
               p->continuer = 0;
                break;
        }

        z->tempsActuel = SDL_GetTicks();
        if (z->tempsActuel - z->tempsPrecedent > z->TEMPS)
        {
            z->angle += 2; //On augmente l'angle pour que l'image tourne sur elle-même.

            z->tempsPrecedent = z->tempsActuel;
        }
        else
        {
            SDL_Delay(z->TEMPS - (z->tempsActuel - z->tempsPrecedent));
        }

        SDL_FillRect(e->e, NULL, SDL_MapRGB(e->e->format, 255, 255, 255));

        z->rotation = rotozoomSurface(z->image, z->angle, 10, 1); //On transforme la surface image.

        //On positionne l'image en fonction de sa taille.
        z->rect.x =  200 - z->rotation->w / 2;
        z->rect.y =  200 - z->rotation->h / 2;

        SDL_BlitSurface(z->rotation , NULL, e->e, &z->rect); //On affiche la rotation de la surface image.
        SDL_FreeSurface(z->rotation); //On efface rotation car on va la redéfinir dans la prochaine boucle. Si on ne le fait pas, cela crée une fuite de mémoire.

        SDL_Flip(e->e);
    }*/



