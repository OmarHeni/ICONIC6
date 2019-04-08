#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_Image.h>
#include "MyWork.h"

int init_affich(ecran e,perso p,fond f)
{
SDL_Init();
p.posPer.x=100;
p.posPer.y=220;

SDL_BlitSurface(f.imagefond, NULL, e.e , &e.posecran);
SDL_BlitSurface(p.personnage, NULL, e.e, &p.posPer);
SDL_Flip(e.e);
return 0;
}
*****************************************************************************************************
void mouse_event (SDL_Event event, perso p,ecran e,fond f){
static int x ;
  while (continuer){
    SDL_POLLEvent(&event);
    switch{
case SDL_Quit:
    continuer=0;
    break;
case SDL_MOUSEBUTTONDOWN:
    if(event.button.button==SDL_BUTTON_LEFT)
        SDL_Delay(3000);
    x = event.button.x;

    break;
            }
           break;
       }
if (x!==0){
if (x>p.posPer.x){
p.posPer.x+=8;
}else if (x<p.posPer.x){
p.posPer.x -= 8 ;
}
}
if (x==p.posPer.x){
x=0 ;
}
 SDL_BlitSurface(f.imagefond,NULL,e.e,&f.positionfond);
 SDL_BlitSurface(p.imageper,NULL,e.e,&p.posPer);
 SDL_Flip(e.e);

}
**************************************************************************************************************


void key_event (SDL_Event event, perso p,ecran e,fond f ){

   SDL_Enable Key Repeat(20,20);
    while(continuer){
        SDL_POLLEvent(&event);
        switch(event.type){
        case SDL_Quit:
        continuer=0;
        break;
        case SDL_KeyDOWN:
            switch(event.key.keysym.sym){
        case SDLK_UP:
            p.posPer.y-=10;
            SDL_waitEvent(&event);
            break;
        case SDLK_DOWN:
           p.posPer.y+=10;
            SDL_waitEvent(&event);
            break;
        case SDLK_RIGHT:
          p.posPer.x+=10;
            SDL_waitEvent(&event);
            break;
        case SDLK_LEFT:
           p.posPer.x-=10;
            SDL_waitEvent(&event);
            break;
            }
           break;
       }

 SDL_BlitSurface(f.imagefond,NULL,e.e,&f.positionfond);
 SDL_BlitSurface(personnage,NULL,e.e,&p.posPer);
 SDL_Flip(e.e);
    }
}
*****************************************************************************************************************************
void scroll(SDL_Event event ,){
const int speed=5;
 static int b[2]={0,0};
while(continuer){
    SDL_Event event;
    while(SDL_POLLEvent(&event)){
        switch(event.type){
    case SDL_Quit:
         continuer=0;
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym){
    case SDLK_RIGHT:
        b[0]=1;
        break;
    case SDLK_LEFT:
        b[1]=1;
        break;
            }
            break;
       }
       case SDL_KEYUP:
        switch(event.key.keysym.sym){
    case SDLK_RIGHT:
        b[0]=0;
        break;
    case SDLK_LEFT:
        b[1]=0;
        break;
            }
            break;
         }

     }
 }

 if (b[0]){
if (p.posPer.x>=1000){
camera.x+=speed;
}else {
  p.posPer.x+=speed;
}
 if(camera.x>=2000-640)
    camera.x=0;
 }
 else {
    if(b[1]){
if (p.posPer.x<=200){ 
  camera.x-=speed;
}else {
  p.posPer.x-=speed;
}
        if(camera.x<=0)
            camera.x=0;
    }
 }
!





