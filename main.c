#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"gamefonc.h"
int main(){
stage sta ;
manr manj ;
menus menu ;
int per= 33 ;
int now ;
int ex= 0;
int i;
sta.run=1;
menu.j = -1;
menu.h = 1;
for (i=0;i<4;i++){
menu.selec[i]=0;
}
i=5;
SDL_Init(SDL_INIT_EVERYTHING);
TTF_Init();
action (&sta,&manj,&menu);
sta.camera.x=0 ;
sta.camera.y=0;
Mix_PlayMusic(sta.music,-1);
while ((i!=0)&&(i!=3)){
i=showmenu(&sta,&menu);
}

menufree(&sta,&menu);

sta.music = Mix_LoadMUS("music/games.mp3");
Mix_PlayMusic(sta.music,-1);
printf (" i = %d | run = %d\n",i,sta.run);
if (i==0){
while (sta.run==1){
 dispose(&sta,&manj);
 SDL_PollEvent(&sta.event);
 event(&sta);
 scroll(&sta,&manj);
}
}
SDL_FreeSurface(manj.man);
SDL_FreeSurface(sta.paysage);
SDL_FreeSurface(sta.fenetre);
Mix_FreeMusic(sta.music);
SDL_Quit();
return 0 ;
}

