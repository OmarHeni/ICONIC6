#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"work.h"
void InitAff(screen sc,background bg,perso p,barrevie b)
{

SDL_BlitSurface(bg.image,NULL,sc.s,&bg.pos);
SDL_BlitSurface(p.imageper,NULL,sc.s,&p.posper);
SDL_BlitSurface(b.imagebarre,NULL,sc.s,&b.posbarre);
SDL_Flip(sc.s);

}
//*******************************************************************************
void Update_score(texte t,screen sc,int sco)
{
char ch[50] ;
printf("%d \n",sco);
sco+=10 ;
sprintf(ch,"%d XP",sco);
t.txt=TTF_RenderText_Solid(t.police,ch,t.color);
SDL_BlitSurface(t.txt,NULL,sc.s,&t.postexte);
}
//********************************************************************************

