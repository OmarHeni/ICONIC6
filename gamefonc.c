#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"gamefonc.h"
SDL_Surface* convpng(char nom[]){
SDL_Surface *tmp ;
SDL_Surface *bouton ;
tmp = IMG_Load(nom);
if(!tmp) {
    printf("Surface : %s\n", Mix_GetError());
    // handle error
}
bouton=SDL_DisplayFormatAlpha(tmp) ;
return bouton ;
}

SDL_Rect getrect(int x,int y,int w, int h){
SDL_Rect pos ;
pos.x = x;
pos.y = y ;
pos.w=w;
pos.h=h ;
return pos ;
}

void setpos(SDL_Rect posm[]){
posm[0]=getrect(0,0,1180,192);
posm[1]=getrect(1180,0,1180,192);
posm[2]=getrect(2360,0,1180,192);
posm[3]=getrect(3540,0,1180,192);
posm[4]=getrect(4720,0,1180,192);
}



void action (stage  *sta,manr *manj,menus *menu ){
SDL_Surface *tmp=NULL;
sta->fenetre=NULL ;
manj->man =NULL ;
SDL_Color color={255,255,255};
menu->font= TTF_OpenFont("BebasNeue Book.ttf",32);
if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)==-1){
printf ("%s  \n",Mix_GetError());
}
sta-> music = Mix_LoadMUS("music/menusong.mp3");
menu->musicb=Mix_LoadWAV("music/mousc.wav");
if(!menu->musicb) {
    printf("Mix_LoadWAV: %s\n", Mix_GetError());
    // handle error
}
setpos(menu->posm);
sta->fenetre = SDL_SetVideoMode(1180,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption("Tate no yusha",NULL);

menu->iconic=TTF_RenderText_Solid(menu->font,"ICONIC6",color);
if (!menu->iconic){
    printf("Problem %s\n", Mix_GetError());
}
SDL_GetClipRect(menu->iconic,&menu->posi);
menu->posi.x=(590-(menu->posi.w/2));
menu->posi.y=(600-(menu->posi.h));
menu->boutonsa[0]=IMG_Load("menu/menu0.jpg");
menu->boutonsa[1]=IMG_Load("menu/menu1.jpg");
menu->boutonsa[2]=IMG_Load("menu/menu2.jpg");
menu->boutonsa[3]=IMG_Load("menu/menu3.jpg");
menu->boutons[0]=IMG_Load("menu/menus0.jpg");
menu->boutons[1]=IMG_Load("menu/menus1.jpg");
menu->boutons[2]=IMG_Load("menu/menus2.jpg");
menu->boutons[3]=IMG_Load("menu/menus3.jpg");
menu->poss[0]=getrect(454,199,263,49);
menu->poss[1]=getrect(452,285,263,49);
menu->poss[2]=getrect(456,377,263,49);
menu->poss[3]=getrect(450,470,263,49);
menu->poss1[0]=getrect(257,196,664,53);
menu->poss1[1]=getrect(257,281,664,53);
menu->poss1[2]=getrect(257,375,664,53);
menu->poss1[3]=getrect(257,465,664,53);
menu->menua = SDL_LoadBMP("menu/menuan.bmp");
menu->menu =IMG_Load("menu/menud.jpg");
sta->paysage=SDL_LoadBMP("/home/omar/gr.bmp");
manj->carre = IMG_Load("carre.jpg");
if(!manj->carre) {
    printf("Surface : %s\n", Mix_GetError());
    // handle error
}
SDL_GetClipRect(manj->carre,&manj->pos2);
SDL_GetClipRect(sta->paysage,&sta->pos);
tmp = IMG_Load("/home/omar/skar.png");
manj->man=SDL_DisplayFormatAlpha(tmp);
SDL_GetClipRect(manj->man,&manj->pos1);
manj->pos2.x=2000;
manj->pos2.y=300;
manj->pos1.x=0;
manj->pos1.y=300;
sta->camera=getrect(0,0,600,1180);
}

/*****************************************/

int showmenu(stage *sta,menus *menu ){
int x,y,i,signe ;
SDL_Event eventt ;
int a = 0 ;

if (menu->frame>=4 ){
signe =-1;
}else if (menu->frame==0){
signe =1;
}
SDL_BlitSurface(menu->menu,NULL,sta->fenetre,&sta->pos);
SDL_BlitSurface(menu->iconic,NULL,sta->fenetre,&menu->posi);
menu->frame+=signe ;
SDL_BlitSurface(menu->menua,&menu->posm[menu->frame],sta->fenetre,&sta->pos);
SDL_PollEvent(&eventt);
switch(eventt.type){
case SDL_KEYDOWN :
if (eventt.key.keysym.sym==SDLK_DOWN){
if (menu->h==1){
menu->j++;
if (menu->j>=4){
menu->j=0;
}
menu->selec[menu->j]=1 ;
if (menu->j>=1){
menu->selec[menu->j-1]=0;
}else if (menu->j==0){
menu->selec[3]=0;
}
menu->h=0;
}
}
if (eventt.key.keysym.sym==SDLK_UP){
if (menu->h==1){
menu->j--;
if (menu->j<=-1){
menu->j=3;
}
menu->selec[menu->j]=1 ;
if (menu->j<=2){
menu->selec[menu->j+1]=0;
}else if (menu->j==3){
menu->selec[0]=0;
}
menu->h=0;
}
}
if (eventt.key.keysym.sym==SDLK_ESCAPE){
return 3 ;
}
if (eventt.key.keysym.sym==SDLK_SPACE){
if (menu->j==0){
menu->boutons[0]=IMG_Load("menu/menuc0.jpg");
SDL_BlitSurface(menu->boutons[0],NULL,sta->fenetre,&(menu->poss1[0]));
SDL_Flip(sta->fenetre);
}
else if (menu->j==1){
menu->boutons[1]=IMG_Load("menu/menuc1.jpg");
SDL_BlitSurface(menu->boutons[1],NULL,sta->fenetre,&(menu->poss1[1]));
SDL_Flip(sta->fenetre);
SDL_Delay(100);
menu->boutons[1]=IMG_Load("menu/menus1.jpg");
}
else if (menu->j==2){
menu->boutons[2]=IMG_Load("menu/menuc2.jpg");
SDL_BlitSurface(menu->boutons[2],NULL,sta->fenetre,&(menu->poss1[2]));
SDL_Flip(sta->fenetre);
SDL_Delay(100);
menu->boutons[2]=IMG_Load("menu/menus2.jpg");
}
else if (menu->j==3){
menu->boutons[3]=IMG_Load("menu/menuc3.jpg");
SDL_BlitSurface(menu->boutons[3],NULL,sta->fenetre,&(menu->poss1[3]));
SDL_Flip(sta->fenetre);
SDL_Delay(100);
}
return menu->j ;
}
break ;
case SDL_KEYUP :
menu->h=1;
break;
case SDL_MOUSEMOTION :
x=eventt.motion.x;
y=eventt.motion.y ;
for (i=0;i<4;i++){
if ((x>menu->poss[i].x) && (x<menu->poss[i].x+menu->poss[i].w) && (y>menu->poss[i].y) && (y<=menu->poss[i].y+menu->poss[i].h) ){
menu->h=1;
if (!menu->selec[i]){
menu->selec[i]=1 ;
menu->j=i;
}
}else if (menu->selec[i]){
menu->selec[i]=0;
}
}
break ;
case SDL_MOUSEBUTTONDOWN :
x=eventt.button.x;
y=eventt.button.y;
for (i=0;i<4;i++){
if ((x>menu->poss[i].x) && (x<menu->poss[i].x+menu->poss[i].w) && (y>menu->poss[i].y) && (y<=menu->poss[i].y+menu->poss[i].h) ){
Mix_PlayChannel(-1,menu->musicb,1);
if (i==0){
menu->boutons[0]=IMG_Load("menu/menuc0.jpg");
SDL_BlitSurface(menu->boutons[0],NULL,sta->fenetre,&(menu->poss1[0]));
SDL_Flip(sta->fenetre);
}
else if (i==1){
menu->boutons[1]=IMG_Load("menu/menuc1.jpg");
SDL_BlitSurface(menu->boutons[1],NULL,sta->fenetre,&(menu->poss1[1]));
SDL_Flip(sta->fenetre);
SDL_Delay(100);
menu->boutons[1]=IMG_Load("menu/menus1.jpg");
}
else if (i==2){
menu->boutons[2]=IMG_Load("menu/menuc2.jpg");
SDL_BlitSurface(menu->boutons[2],NULL,sta->fenetre,&(menu->poss1[2]));
SDL_Flip(sta->fenetre);
SDL_Delay(100);
menu->boutons[2]=IMG_Load("menu/menus2.jpg");
}
else if (i==3){
menu->boutons[3]=IMG_Load("menu/menuc3.jpg");
SDL_BlitSurface(menu->boutons[3],NULL,sta->fenetre,&(menu->poss1[3]));
SDL_Flip(sta->fenetre);
SDL_Delay(100);
}
return i ;
}
}
break ;
}
for (i=0;i<4;i++){
if (menu->selec[i]){
SDL_BlitSurface(menu->boutons[i],NULL,sta->fenetre,&menu->poss1[i]);
}else {
SDL_BlitSurface(menu->boutonsa[i],NULL,sta->fenetre,&menu->poss[i]);
}
}
SDL_Flip(sta->fenetre);
return -1 ; 
}

/***********************************/

void menufree( stage *sta,menus *menu){
int i ;
for (i=0;i<4;i++){
SDL_FreeSurface(menu->boutons[i]);
}
SDL_FreeSurface(menu->menu);
Mix_FreeChunk(menu->musicb);
SDL_FreeSurface(menu->menua);
SDL_FreeSurface(menu->iconic);
return ;
}

/*******************************************************************/

/*int showmenu(stage *sta ){
int x,y,i ;
SDL_Event eventt ;
const char * labels [2]={"Jouer","exit"};
SDL_Surface* boutons[2] ; 
int selec[2]={0,0};
SDL_Color color[2]={{255,255,255},{255,0,0}}; 
boutons[0]=TTF_RenderText_Solid(sta->font,labels[0],color[0]);
boutons[1]=TTF_RenderText_Solid(sta->font,labels[1],color[0]);
SDL_Rect pos[2];
pos[0].x=((sta->pos.w)/2)+(boutons[0]->clip_rect.w/2) ;
pos[1].x=((sta->pos.w)/2)+(boutons[0]->clip_rect.w/2) ;
pos[0].y=((sta->pos.h)/2)-(boutons[0]->clip_rect.h/2);
pos[1].y=((sta->pos.h)/2)+(boutons[0]->clip_rect.h/2);
SDL_FillRect(sta->fenetre,&sta->pos,SDL_MapRGB(sta->fenetre->format,0,0,0));
SDL_PollEvent(&eventt);
switch(eventt.type){
case SDL_QUIT:
SDL_FreeSurface(boutons[0]);
SDL_FreeSurface(boutons[1]);
break;
case SDL_MOUSEMOTION : 
x= eventt.motion.x;
y=eventt.motion.y ;
for (i=0;i<2;i++){
if (x>pos[i].x && x<pos[i].x+pos[i].w && y>pos[i].y && y>pos[i].y && y<=pos[i].y+pos[i].h ){
if (!selec[i]){
selec[i]=1 ;
SDL_FreeSurface (boutons[i]);
boutons[i]=TTF_RenderText_Solid(sta->font,labels[i],color[1]);
}
}else 
if (selec[i]){
selec[i]=0;
SDL_FreeSurface (boutons[i]);
boutons[i]=TTF_RenderText_Solid(sta->font,labels[i],color[0]);
}
}
break ;
case SDL_MOUSEBUTTONDOWN :
x=eventt.button.x;
y=eventt.button.y;
printf (" x = %d | y=%d \n",x,y);
for (i=0;i<2;i++){
if (x>pos[i].x && x<pos[i].x+pos[i].w && y>pos[i].y && y>pos[i].y && y<=pos[i].y+pos[i].h ){
return i ;
}
}
break ;
}
for (i=0;i<2;i++){
SDL_BlitSurface(boutons[i],NULL,sta->fenetre,&pos[i]);
SDL_Flip(sta->fenetre);
}
return -1;
}
*/

void intial (enigme *en ){
int i ;
for (i=0;i<3;i++){
en->selec[i]=0 ; 
}
en->Num_try = 0 ;
}

void intialiser_en (enigme *en ){
en->t[0]= 0 ;
en->Num_en = rand()%6+1 ;
printf ("num = %d \n",en->Num_en);
// declaer les positon 
en->posen[0]=getrect(12,185,551,108);
en->posen[1]=getrect(48,275,551,134);
en->posen[2]=getrect(13,404,551,96);
en->posg = getrect(0,0,600,500);
switch (en->Num_en){
// charger les surfaces dans des different cas (le changement du numero du l'enigme
case 1 : 
en->menueng = convpng("fichier enigme/enigme1/enigme1.png");
en->reponse[0]=convpng("fichier enigme/enigme1/enigme1reponse1.png");
en->reponse[1]=convpng("fichier enigme/enigme1/enigme1reponse2.png");
en->reponse[2]=convpng("fichier enigme/enigme1/enigme1reponse3.png");
break ;
case 2 :
en->menueng = convpng("fichier enigme/enigme1/enigme2.png");
en->reponse[0]=convpng("fichier enigme/enigme1/enigme2reponse1.png");
en->reponse[1]=convpng("fichier enigme/enigme1/enigme2reponse2.png");
en->reponse[2]=convpng("fichier enigme/enigme1/enigme2reponse3.png");
break; 
case 3 :
en->menueng = IMG_Load("fichier enigme/enigme2/enigme3.png");
en->posen[0]=getrect(12,185,551,108);
en->reponse[0]=convpng("fichier enigme/enigme2/enigme3reponse1.png");
en->reponse[1]=convpng("fichier enigme/enigme2/enigme3reponse2.png");
en->reponse[2]=convpng("fichier enigme/enigme2/enigme3reponse3.png");
break; 
case 4 :
en->menueng = IMG_Load("fichier enigme/enigme2/enigme4.png");
en->reponse[0]=convpng("fichier enigme/enigme2/enigme4reponse1.png");
en->reponse[1]=convpng("fichier enigme/enigme2/enigme4reponse2.png");
en->reponse[2]=convpng("fichier enigme/enigme2/enigme4reponse3.png");
break ;
case 5 :
en->menueng = IMG_Load("fichier enigme/enigme3/enigme5.png");
en->reponse[0]=convpng("fichier enigme/enigme3/enigme5reponse1.png");
en->reponse[1]=convpng("fichier enigme/enigme3/enigme5reponse2.png");
en->reponse[2]=convpng("fichier enigme/enigme3/enigme5reponse3.png");
break; 
case 6 :
en->menueng = IMG_Load("fichier enigme/enigme3/enigme6.png");
en->reponse[0]=convpng("fichier enigme/enigme3/enigme6reponse1.png");
en->reponse[1]=convpng("fichier enigme/enigme3/enigme6reponse2.png");
en->reponse[2]=convpng("fichier enigme/enigme3/enigme6reponse3.png");
break ;
}
}


int menigme(enigme  *en,stage *sta ){
int x,y,i ;
int static j ;
en->t[1]=0 ; 
SDL_Event eventt ;
SDL_BlitSurface(en->menueng,NULL,sta->fenetre,&en->posg);
SDL_PollEvent(&eventt);
switch(eventt.type){
case SDL_QUIT:
SDL_FreeSurface(en->reponse[0]);
SDL_FreeSurface(en->reponse[1]);
SDL_FreeSurface(en->reponse[2]);
break;
case SDL_MOUSEMOTION :
/* voir si les reponses sont selectioné par la souris ou non par voir si 
la souris dans le rectangle (chaque surface a un rectangle dans SDL) */ 
x=eventt.motion.x;
y=eventt.motion.y;
for (i=0;i<3;i++){
if (x>en->posen[i].x && x<en->posen[i].x+en->posen[i].w && y>en->posen[i].y && y<=en->posen[i].y+en->posen[i].h ){
if (!en->selec[i]){
en->selec[i]=1 ;
}
}else 
if (en->selec[i]){
en->selec[i]=0;
}
}
break ;
case SDL_MOUSEBUTTONDOWN :
// voir si la reponse est pressé ou non 
x=eventt.button.x;
y=eventt.button.y;
for (i=0;i<3;i++){
if (x>en->posen[i].x && x<en->posen[i].x+en->posen[i].w &&  y>en->posen[i].y && y<=en->posen[i].y+en->posen[i].h ){
/* tu peux dire que normalement tu vas retourné l'indice du reponse clické 
mais le programme execute plusieurs fois dans le temp que tu presse (comme ci tu a pressé plusieur fois ) pour ca j'ai fais un tableaux du deux cases le premiere case verifie si a ete pressé la deuxieme verifie si il est pressé dans cette execution pour ca à chaque execution il est intialiser à 0 l'autre est intialise à 0 à chaque apparence d'un enigme */
en->t[0]=1 ;
en->t[1]=1 ;
j=i;
}
}
break ;
}
if (en->t[1]==0 && en->t[0]==1){
/* comme j'ai dit normalement tu vas retourné l'indice du reponse clické aprés verifé la condition que le programme est n'est pas clické dans cette execution mais il a été clické il va retourné l'indice qui est sotké dans la variable j */ 
return j ;
}
for (i=0;i<3;i++){
if (en->selec[i]){
SDL_BlitSurface(en->reponse[i],NULL,sta->fenetre,&en->posen[i]);
}
}
SDL_Flip(sta->fenetre);
return -1;
}


int reponse (enigme *en ,int j){
FILE *fic ;
int i ;
int x,y;
if (j!=-1){
fic = fopen ("fichier enigme/reponse.txt","r");
while (x!=en->Num_en){
// rechercher l'enigme 
fscanf (fic,"EnigmeNum = %d  =%d\n",&x,&i);
}
if (i==j){
fclose(fic);
return 1 ;
}else {
(en->Num_try)++;
fclose (fic);
return 0 ;
}
}
}

void freeenigme(enigme *en){
int i; 
SDL_FreeSurface(en->menueng);
for (i=0;i<3;i++){
SDL_FreeSurface(en->reponse[i]);
}
}


/*****************************************/
/*
void update (manr *manj,stage *sta){
int dx =manj->pos1.x ;
int dy =manj->pos1.y ; 
switch (sta->event.type){
case SDL_KEYDOWN :
if(sta->event.key.keysym.sym==SDLK_RIGHT) {
dx=dx+5 ;
}
if (sta->event.key.keysym.sym==SDLK_LEFT){
dx=dx-5 ;
}
break ;
}
manj->pos1.x=dx ;
manj->pos1.y=dy ;
if (dx==800){
manj->pos1.x=0;
}
}

/****************************************************/

int collision (SDL_Rect pos1 , SDL_Rect pos2){
if (pos1.y>=pos2.y+pos2.h)
return 0;
if (pos1.x>=pos2.x+pos2.w)
return 0;
if (pos1.y+pos1.h<=pos2.y)
return 0 ;
if (pos1.x+pos1.w<=pos2.x)
return 0 ;
return 1 ;
}

void jump (manr *manj){
static int i = (-5) ; 
static int j = 0 ;
static int k = 0 ;
int diff ; 

diff = i+j ; 
manj->pos1.y+=diff ;
if (manj->pos1.y<=300){
k = 0 ;
j=0 ;
}
}

void dispose (stage *sta,manr *manj){
SDL_BlitSurface(sta->paysage,&sta->camera,sta->fenetre,NULL);
SDL_BlitSurface(manj->man,NULL,sta->fenetre, & manj->pos1);
SDL_BlitSurface(manj->carre,NULL,sta->fenetre,&manj->pos2);
SDL_Flip(sta->fenetre);
}

/*********************************************************/


void eveent (stage *sta, int bol[]){
SDL_PollEvent(&sta->event);
switch (sta->event.type){
case SDL_QUIT :
sta->run =0;
break;
case SDL_KEYDOWN :
switch (sta->event.key.keysym.sym){
case SDLK_RIGHT :
bol[0]=1;
break;
case SDLK_LEFT : 
bol[1]=1;
break;
case SDLK_UP :
bol[2]=1;
break;
case SDLK_ESCAPE :
sta->run =0;
break;
}
break;
case SDL_KEYUP :
switch (sta->event.key.keysym.sym){
case SDLK_RIGHT :
bol[0]=0 ;
break;
case SDLK_LEFT : 
bol[1]=0;
break;
}
break;
}
}


/***************************************************/

void Position_Update (stage *sta,manr *manj){
static int bol[3]={0,0,0};
static int o = 0 ;
static int jp = 10 ;
sta->camera.w=1180;
sta->camera.h=600;
eveent (sta,bol);
if (bol[0]==1){
if (!collision(manj->pos1,manj->pos2)){
if (manj->pos1.x<800){
manj->pos1.x+=10;
}
else if (manj->pos1.x>=800){
(sta->camera.x)+=5;
manj->pos2.x-=5 ;
}
}
}else if (bol[1]==1){
if (manj->pos1.x>400){
manj->pos1.x-=10;
}
else if (manj->pos1.x<=400){
(sta->camera.x)-=5;
manj->pos2.x+=5 ;
}
}else if (bol[2]==1){
manj->pos1.y-=jp ;
o++;
if (o%2==0){
jp-=1 ;
}
}
if (sta->camera.x>=(2000-800)){
sta->camera.x=0;
}
if (manj->pos1.y>=300){
bol[2]=0;
manj->pos1.y=300;
jp =(-jp);
}
if (sta->camera.x<=0){
sta->camera.x=0;
}
SDL_Flip(sta->fenetre);
}

void freesurface(stage *sta , manr *manj){
SDL_FreeSurface(manj->man);
SDL_FreeSurface(sta->paysage);
SDL_FreeSurface(sta->fenetre);
SDL_FreeSurface(manj->carre);
Mix_FreeMusic(sta->music);
}

