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
int rep = 0  ;
int j,o ; 
int ex= 0;
int i;
machine mach;
enemie  enm;
enigme en ; 
sta.run=1;
menu.j = -1;
menu.h = 1;
for (i=0;i<4;i++){
menu.selec[i]=0;
}
intial(&en);
i=5;
SDL_Init(SDL_INIT_EVERYTHING);
TTF_Init();
action (&sta,&manj,&menu,&mach,&enm);
printf ("part %d | %d \n",enm.posenm.y,enm.posenm.x);
Mix_PlayMusic(sta.music,-1);
while ((i!=0)&&(i!=3)){
i=showmenu(&sta,&menu);
}
menufree(&sta,&menu);
//sta.music = Mix_LoadMUS("music/games.mp3");
Mix_PlayMusic(sta.music,-1);
if (i==0){
while (sta.run==1){
 Position_Update(&sta,&manj);
Update_enemie (&enm,&manj);
 dispose(&sta,&manj,&mach,&enm);
printf ("%d \n",sta.camera.x);
//Machine_Position (&mach,&manj,&sta);
if (sta.f!=NULL){
Arduino_Update(&sta,&manj);
}
if (collision (manj.pos1,manj.pos2) ) {
inital_button(&manj);
while (en.Num_try <4 && rep == 0){
intialiser_en(&en);
o=en.Num_try ;
while (en.Num_try ==o && rep == 0){
j= menigme(&en,&sta);
rep =reponse(&en,j);
Update_temp(&en,&sta);
}
}
}
}
}
if (sta.f!=NULL){
fclose(sta.f);
}
freeenigme(&en) ;
freesurface(&sta,&manj);
SDL_Quit();
return 0 ;
}

