#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include"work.h"
int main(void)
{
TTF_Init();
screen sc;
background bg;
perso p;
vie v;
texte t;
rock r;
menusj menuj;
SDL_Init(SDL_INIT_EVERYTHING);
SDL_Event felsa;
SDL_Event event;
int detection=0;
int sco=-10;
int done=1,done2=1;
int j = -1 ;
menuj.h=1;
menuj.selec[0]=0;
menuj.selec[1]=0;
menuj.j=-1;
menuj.m=0;
menuj.o=0;
menuj.l=0;
int x=-1;
char nomf[5];
strcpy(nomf,"save");
//*******************************************************************************
load(&sc,&bg,&p,&r,&v,&menuj);
//*******************************************************************************

//*******************************************************************************

setpositions (&bg,&r,&p,&v,&menuj);

initialiser_score(&t ,&sc,&sco);
Update_Vie(&v,&sco,&sc);
//*********************************************************************

detection=collision(&p,&r);
//*************************************DEPLACEMENT*********************
SDL_EnableKeyRepeat(10,10);
while(done2)
{
x=InitAff(sc,bg,p,v,r,t,&menuj,done2);
if (x==0)
{
done2=0;
}
else if (x==1)
{
done2=0;
re(&p,&v,&sco,nomf,&t,&sc);
}
}



while(done)
{
InitAff(sc,bg,p,v,r,t,&menuj,done2);
if (menuj.m==1)
{
j=showmenud(&sc,&menuj);//0 heya oui w 1 heya non
}
deplacement(&p,event,&done,&detection,&r,&felsa,&t ,&sc,&sco,&v,&menuj);


if (j==0){
    save(&p,&v,&sco,nomf);
    done=0;
}
else if(j==1)
{done=0;}

SDL_Flip(sc.s);
}
//*************************************DEPLACEMENT*********************



 TTF_CloseFont(t.police);
    TTF_Quit();

    SDL_FreeSurface(t.txt);
    SDL_Quit();

return 0 ;
}


