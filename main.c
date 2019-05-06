#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL_rotozoom.h"
#include "MyWork.h"

int main()
{
char pause;
ecran e;

perso p;
perso1 p1;

zoom z;

int done=1;
p.continuer = 1;
p1.continuer = 1;
SDL_Init(SDL_INIT_EVERYTHING);

SDL_Init(SDL_INIT_EVERYTHING);
if( SDL_Init(SDL_INIT_EVERYTHING)!=0){
printf("unabel to initialize SDL:%s\n",SDL_GetError());
return (-1);
}
SDL_EnableKeyRepeat(10,10);
init_positions(&e,&p,&p1,&z);
init_affich(&e,&p,&p1);
p.continuer = 1;
p1.continuer = 1;

while(p.continuer||p1.continuer)
{

 scroll(&e,&p,&p1);
SDL_Flip(e.e);
}



SDL_Quit();
return 0 ;
}



