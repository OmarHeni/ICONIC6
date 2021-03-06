#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "gamefonc.h"
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
/*************************************/
SDL_Rect getrect(int x,int y,int w, int h){
SDL_Rect pos ;
pos.x = x;
pos.y = y ;
pos.w=w;
pos.h=h ;
return pos ;
}
/************************************************/
void shield_pos(manr *manj){
switch (manj->direc){
case 1 :
switch (manj->pos){
case 0 :
manj->spos = getrect(manj->pos1.x+4,34+manj->pos1.y,20,34);
break;
case 1:
manj->spos = getrect(4+manj->pos1.x,42-manj->part[1].y+manj->pos1.y,20,34);
break;
case 3 :
manj->spos = getrect(4+manj->pos1.x,146-manj->part[3].y+manj->pos1.y,20,34);
break;
case 5 :
manj->spos = getrect(4+manj->pos1.x,253-manj->part[5].y+manj->pos1.y,20,34);
break; 
}
break;
case 0 : 
switch (manj->pos){
case 0 :
manj->spos = getrect(34+manj->pos1.x,59+manj->pos1.y,20,34);
break;
case 1:
manj->spos = getrect((110-manj->part[1].x)+manj->pos1.x,42-manj->part[1].y+manj->pos1.y,20,34);
break;
case 3 :
manj->spos = getrect((110-manj->part[3].x)+manj->pos1.x,146-manj->part[3].y+manj->pos1.y,20,34);
break;
case 5 :
manj->spos = getrect((114-manj->part[5].x)+manj->pos1.x,253-manj->part[5].y+manj->pos1.y,20,34);
break;
}
break; 
}
}


/**************************************/
void intial_enemie(enemie *enm){
switch (enm->direc){
case 0 :
enm->sen = convpng("Group 1.png");
enm->enpart[0]=getrect(0,0,41,107);
enm->enpart[1]=getrect(66,0,51,107);
enm->enpart[2]=getrect(122,0,67,107);
enm->enpart[3]=getrect(199,0,60,107);
enm->enpart[4]=getrect(278,0,49,107);
enm->enpart[5]=getrect(354,0,41,107);
enm->enpart[6]=getrect(395,0,68,107);
enm->enpart[7]=getrect(0,106,41,107);
enm->enpart[8]=getrect(55,125,59,95);
enm->enpart[9]=getrect(119,139,63,86);
enm->enpart[10]=getrect(188,155,97,60);
enm->enpart[11]=getrect(285,165,120,50);
enm->enpart[12]=getrect(407,165,137,50);
enm->enpart[13]=getrect(0,222,41,107);
enm->enpart[14]=getrect(71,222,51,119);
enm->enpart[15]=getrect(131,222,72,119);
enm->enpart[16]=getrect(211,222,86,119);
break;
case 1 :
enm->sen = convpng("Group 2.png");
enm->enpart[0]=getrect(497,0,41,107);
enm->enpart[1]=getrect(423,0,51,107);
enm->enpart[2]=getrect(346,0,67,107);
enm->enpart[3]=getrect(265,0,60,107);
enm->enpart[4]=getrect(193,0,49,107);
enm->enpart[5]=getrect(149,0,41,107);
enm->enpart[6]=getrect(82,0,68,107);
enm->enpart[7]=getrect(497,110,41,107);
enm->enpart[8]=getrect(427,125,59,95);
enm->enpart[9]=getrect(458,140,63,86);
enm->enpart[10]=getrect(260,155,97,60);
enm->enpart[11]=getrect(138,165,120,50);
enm->enpart[12]=getrect(0,165,137,50);
enm->enpart[13]=getrect(497,222,41,107);
enm->enpart[14]=getrect(413,224,51,119);
enm->enpart[15]=getrect(340,224,72,119);
enm->enpart[16]=getrect(235,224,99,119);
break;
}
}




/*************************************/

void intialmpos (enemie *enm, int try  ){
switch (try){
case 0:
enm->bpos=getrect(enm->posenm.x,enm->posenm.y+16,20,20);
break;
case 1 :
enm->bpos=getrect(enm->posenm.x,enm->posenm.y+40,20,20);
break;
case 2 :
enm->bpos=getrect(enm->posenm.x,enm->posenm.y+60,20,20);
break;
}
 }


/****************************/


void setpos(SDL_Rect posm[]){
posm[0]=getrect(0,0,1180,192);
posm[1]=getrect(1180,0,1180,192);
posm[2]=getrect(2360,0,1180,192);
posm[3]=getrect(3540,0,1180,192);
posm[4]=getrect(4720,0,1180,192);
}

/*************************/

void inital_part(manr *manj,int i){
switch (i){
case 0 :
manj->man=convpng("Group 4.png");
manj->part[0]=getrect(0,0,58,106);
manj->part[1]=getrect(75,0,67,106);
manj->part[2]=getrect(0,120,58,106);
manj->part[3]=getrect(75,120,67,106);
manj->part[4]=getrect(0,250,58,106);
manj->part[5]=getrect(75,250,67,106);
break;
case 1 :
manj->man=convpng("Group 5.png");
manj->part[0]=getrect(78,0,58,106);
manj->part[1]=getrect(0,0,67,106);
manj->part[2]=getrect(78,120,58,106);
manj->part[3]=getrect(0,120,67,106);
manj->part[4]=getrect(78,250,58,106);
manj->part[5]=getrect(0,250,67,106);
break;
}
}

/**************************/

void action (stage *sta,manr *manj,menus *menu , machine *mach,enemie *enm ){
int i;
SDL_Surface *tmp=NULL;
sta->fenetre=NULL ;
    char chemin[]="/dev/ttyACM0";
manj->man =NULL ;
manj->pos=0;
manj->x =0; 
SDL_Color color={255,255,255};
manj->font= TTF_OpenFont("BebasNeue Book.ttf",32);
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
//enm->prec = SDL_GetTicks();
enm->direc = 0 ;
intial_enemie(enm);
enm->posenm=getrect(1000,300,41,107);
mach ->mpos=getrect(955,300,255,146);
setpos(menu->posm);
sta->fenetre = SDL_SetVideoMode(1180,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption("Tate no yusha",NULL);

mach->i = 0;
manj->sscore=TTF_RenderText_Solid(menu->font,"0 XP",color);
menu->iconic=TTF_RenderText_Solid(menu->font,"ICONIC6",color);
if (!menu->iconic){
    printf("Problem %s\n", Mix_GetError());
}
    sta->f=fopen(chemin,"r+");
    if(sta->f == NULL)
printf ("Erreur d'ouverture du fichier \n");
manj->barre = convpng("LifeBarE.png");
manj->song = convpng("sang.png");
SDL_GetClipRect(manj->sscore,&manj->possco);
manj->possco.x=350;
SDL_GetClipRect(menu->iconic,&menu->posi);
menu->posi.x=(590-(menu->posi.w/2));
menu->posi.y=(600-(menu->posi.h));
manj->score=0;
menu->boutonsa[0]=IMG_Load("menu/menu0.jpg");
menu->boutonsa[1]=IMG_Load("menu/menu1.jpg");
menu->boutonsa[2]=IMG_Load("menu/menu2.jpg");
menu->boutonsa[3]=IMG_Load("menu/menu3.jpg");
menu->boutons[0]=IMG_Load("menu/menus0.jpg");
menu->boutons[1]=IMG_Load("menu/menus1.jpg");
menu->boutons[2]=IMG_Load("menu/menus2.jpg");
menu->boutons[3]=IMG_Load("menu/menus3.jpg");
manj->vie = 230 ;
enm->pos2 = 900 ;
intialmpos(enm,0);
menu->poss[0]=getrect(454,199,263,49);
menu->poss[1]=getrect(452,285,263,49);
menu->poss[2]=getrect(456,377,263,49);
menu->poss[3]=getrect(450,470,263,49);
menu->poss1[0]=getrect(257,196,664,53);
menu->poss1[1]=getrect(257,281,664,53);
menu->poss1[2]=getrect(257,375,664,53);
menu->poss1[3]=getrect(257,465,664,53);
enm->ball = convpng("ball.png");
mach->gun = convpng("machine.png");
menu->menua = SDL_LoadBMP("menu/menuan.bmp");
menu->menu =IMG_Load("menu/menud.jpg");
sta->paysage=SDL_LoadBMP("/home/omar/gr.bmp");
manj->carre = convpng("drapeau.png");

if(!manj->carre) {
    printf("Surface : %s\n", Mix_GetError());
    // handle error
}
SDL_GetClipRect(manj->carre,&manj->pos2);
SDL_GetClipRect(sta->paysage,&sta->pos);
manj->direc= 0 ;
inital_part(manj,0);
for (i=0;i<3;i++){
manj->bol[i]=0;
}
manj->pos2.x=2000;
manj->pos2.y=300;
manj->pos1=getrect(0,300,58,106);
manj->spart=getrect(0,0,230,25);
manj->sangpos=getrect(43,11,230,25);
sta->ecran=getrect(0,0,1180,600);
sta->camera=getrect(0,0,1180,600);
shield_pos(manj);
}

/****************************************/

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

/*******************************************************/

void intialiser_en (enigme *en ){
en->t[0]= 0 ;
en->Num_en = rand()%6+1 ;
en->post= getrect(1000,0,0,0);
en->font= TTF_OpenFont("BebasNeue Book.ttf",32);
en->prec=SDL_GetTicks();
en->tmp  = 0 ;
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

/******************************************/

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

/*************************************************/

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

/****************************************/

/******************************************/
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

/****************************************************/

void Arduino_Update(stage *sta,manr *manj)
{
static int x ;
int d;
    fscanf(sta->f,"%d",&d);
if (d==1){
manj->bol[0]=1 ;
}else if (d==0) {
manj->bol[0]=0;
}
if (collision(manj->pos1,manj->pos2)){
printf ("here \n");
    fprintf(sta->f,"c%d\n",1);
x=1 ;
}else if (!collision(manj->pos1,manj->pos2) && x==1){
printf ("here 2\n");
    fprintf(sta->f,"c%d\n",0);
x=0 ;
}
}
/*void arduino_Write(stage *sta){
    fprintf(sta->f,"c%d\n",1);

}
*/
/*****************************************************/

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

/*************************************************/

void dispose (stage *sta,manr *manj,machine *mach,enemie *enm){
SDL_BlitSurface(sta->paysage,&sta->camera,sta->fenetre,NULL);
if (manj->pos2.x>0){
SDL_BlitSurface(manj->carre,NULL,sta->fenetre,&manj->pos2);
}
//SDL_BlitSurface(mach->gun,NULL,sta->fenetre,&mach->mpos);
if (!collision(enm->bpos,enm->posenm)){
SDL_BlitSurface(enm->ball,NULL,sta->fenetre,&enm->bpos);
}
SDL_BlitSurface(manj->man,&manj->part[manj->pos],sta->fenetre, & manj->pos1);
SDL_BlitSurface(manj->barre,NULL,sta->fenetre,NULL);
SDL_BlitSurface(manj->song,&manj->spart,sta->fenetre,&manj->sangpos);
SDL_BlitSurface(manj->sscore,NULL,sta->fenetre,&manj->possco);
/*printf("pos = %d | %d | %d | %d \n",enm->enpart[enm->part].x,enm->enpart[enm->part].y,enm->enpart[enm->part].w,enm->enpart[enm->part].h);*/
SDL_BlitSurface(enm->sen,&enm->enpart[enm->part],sta->fenetre,&enm->posenm);
SDL_Flip(sta->fenetre);
}

/*********************************************************/


void eveent (stage *sta,manr *manj){
SDL_EnableKeyRepeat(0,SDL_DEFAULT_REPEAT_INTERVAL);
SDL_PollEvent(&sta->event);
switch (sta->event.type){
case SDL_QUIT :
sta->run =0;
break;
case SDL_KEYDOWN :
switch (sta->event.key.keysym.sym){
case SDLK_RIGHT :
manj->bol[0]=1;
break;
case SDLK_LEFT : 
manj->bol[1]=1;
break;
case SDLK_UP :
if (manj->bol[4]==1){
if (manj->pos<5){
manj->pos+=2;
}
}else {
manj->bol[2]=1;
}
break; 
case SDLK_DOWN : 
if (manj->bol[4]==1){
if (manj->pos>1){
manj->pos-=2;
}
}else {
manj->bol[2]=1;
}
break;
case SDLK_ESCAPE :
sta->run =0;
case SDLK_x :
if (manj->bol[4]==0){
manj->bol[4]=1;
}else  {
manj->bol[4]=0;
}
if (manj->bol[4]==1){
if (manj->pos%2==0){
manj->pos++ ;
}
}else {
manj->pos = 0 ;
}
break;
}
break;
case SDL_KEYUP :
switch (sta->event.key.keysym.sym){
case SDLK_RIGHT :
manj->bol[0]=0 ;
break;
case SDLK_LEFT : 
manj->bol[1]=0;
break;
}
case SDL_MOUSEBUTTONDOWN :
if (sta->event.button.button==SDL_BUTTON_LEFT){
manj->x=sta->event.button.x;
}
break;
}
}

/***************************************************/



/***************************************************/

void Position_Update (stage *sta,manr *manj){
static int o = 0 ;
static int jp = 10 ;
shield_pos(manj);
eveent (sta,manj);
if (manj->bol[0]==1){
manj->x=0;
if (manj->direc==1){
inital_part(manj,0);
manj->direc = 0 ;
}
if (manj->pos1.x<1000){
manj->pos1.x+=5;
}
else if (manj->pos1.x>=1000){
(sta->camera.x)+=5;
manj->pos2.x-=5 ;
}
}if (manj->bol[1]==1){
manj->x=0;
if (manj->direc==0){
inital_part(manj,1);
manj->direc = 1 ;
}

if (manj->pos1.x>200){
manj->pos1.x-=5;
}
else if (manj->pos1.x<=200){
(sta->camera.x)-=5;
manj->pos2.x+=5 ;
}
}if (manj->bol[2]==1){
manj->pos1.y-=jp ;
o++;
if (o%2==0){
jp-=1 ;
}

}else if (manj->x!=0) {
if (manj->x>manj->pos1.x){
manj->pos1.x+=10 ;
if (manj->pos1.x>manj->x){
manj->x = 0;
}
}else if (manj->x<manj->pos1.x){
manj->pos1.x-=10 ;
if (manj->pos1.x<manj->x){
manj->x = 0;
}
}
}
if (sta->camera.x>=800){
sta->camera.x=0;
}
if (manj->pos1.y>=300){
manj->bol[2]=0;
manj->pos1.y=300;
jp =(-jp);
}
if (sta->camera.x<=0){
sta->camera.x=0;
}
SDL_Flip(sta->fenetre);
}

/**********************************************/

void freesurface(stage *sta , manr *manj ){
SDL_FreeSurface(manj->man);
SDL_FreeSurface(sta->paysage);
SDL_FreeSurface(sta->fenetre);
SDL_FreeSurface(manj->carre);
Mix_FreeMusic(sta->music);
}

/*********************************************/

int Collision_trigo(SDL_Rect pos1 ,SDL_Rect pos2 ){
int rayon1 = (pos1.h/2);
int rayon2 = (pos2.h/2);
SDL_Rect centre1 = getrect(pos1.x+pos1.w/2,pos1.y+pos1.h/2,1,1);
SDL_Rect centre2 = getrect(pos2.x+pos2.w/2,pos2.y+pos2.h/2,1,1);
float dist = sqrt((centre1.x-centre2.x)*(centre1.x-centre2.x)+(centre1.y-centre2.y)*(centre1.y-centre2.y));
/*printf (" rayon = %d \n",rayon1+rayon2);
if (dist<70){
printf ("dist =%f \n",dist);
}*/
if (dist<=(rayon1+rayon2)){
return  1 ;
}
return 0 ;
}
/******************************************/
void inital_button (manr *manj){
int i = 0 ;
for (i=0;i<5;i++){
manj->bol[i]=0;
}
}

/*********************************************/

void Update_temp(enigme *en,stage *sta){
SDL_Rect rect ;
SDL_Color color={255,255,255};
static char ch[50] ;
en->suiv = SDL_GetTicks();
if (en->suiv - en->prec>=1000){
en->tmp ++ ;
if (en->tmp<10){
sprintf(ch,"00:0%d",en->tmp);
}else if (en->tmp==10){
sprintf(ch,"00:%d",en->tmp);
}
en->prec=en->suiv ;
}
en->temp=TTF_RenderText_Solid(en->font,ch,color);
SDL_GetClipRect(en->temp,&rect);
rect.x=en->post.x;
rect.y=en->post.y;
rect.w+=6;
SDL_BlitSurface(sta->paysage,&rect,sta->fenetre,&rect);
SDL_BlitSurface(en->temp,NULL,sta->fenetre,&en->post);
if (en->tmp==10){
en->tmp = 0 ;
en->Num_try-- ;
}
}

/*********************************************/

void Update_Vie (manr *manj){
if (manj->vie>0){
manj->vie -= 10 ;
}
if (manj->vie <=0 ){
manj->score = 0 ;
manj->spart.w = 0;
}else{
manj->spart.w =manj->vie ;
}
}

/************************************************/

void Update_score(manr *manj){
SDL_Color color={255,255,255};
char ch[50] ;
manj->score+=10 ;
sprintf(ch,"%d XP",manj->score);
manj->sscore=TTF_RenderText_Solid(manj->font,ch,color);
}
/************************************************/
/*void Machine_Position (machine * mach, manr *manj,stage *sta){
mach ->bpos.x = mach ->bpos.x - 20 ;
if (Collision_trigo(manj->spos,mach->bpos)){
Update_score(manj,sta);
mach->i = rand()%3;
intialmpos(mach,mach->i);
}else if (collision(manj->pos1,mach->bpos)){
mach->i = rand()%3;
intialmpos(mach,mach->i);
Update_Vie(mach,manj);
}
}

/********************************************/

void Update_enemie (enemie *enm,manr *manj){
static int i ; 
i++;
static int j ;
//enm->now =SDL_GetTicks();
if (i%10==0){
enm->part++;
}
printf ("%d \n",enm->part);
//enm->prec= enm->now ;
if (( enm->posenm.x>enm->pos2 &&enm-> direc ==0) ){
enm->direc = 1;
intial_enemie(enm);
}
if ((enm-> direc == 1 && enm->posenm.x<enm->pos2)){
enm->direc = 0;
intial_enemie(enm);
}
if ((enm->posenm.x-manj->pos1.x)>=200 || (manj->pos1.x-enm->posenm.x)>=200 ||manj->pos1.x==1000 || manj->pos1.x==200  ){
intialmpos(enm,j);
if (enm->part<0 || enm->part >5){
enm->part=0;
//printf ("hereeee \n");
}
printf ("%d \n",enm->pos2);
if (enm->posenm.x>enm->pos2){
enm->posenm.x-=6;
if ((enm->posenm.x)<=enm->pos2){
enm->pos2=rand()%1180;
}
}else {
enm->posenm.x+=6;
if ((enm->posenm.x)>=enm->pos2){
enm->pos2=rand()%1180;
}
}
}else{
 if (enm->part<13 || enm->part >16){
enm->part=13;
}
if (enm->posenm.x>manj->pos1.x){
enm ->bpos.x = enm ->bpos.x - 6 ;
}else if (enm->posenm.x<manj->pos1.x){
enm->bpos.x = enm ->bpos.x + 6 ;
}
if (enm->posenm.x>manj->pos1.x && enm-> direc == 0) {
enm->direc = 1;
intial_enemie(enm);
}else if (enm->posenm.x<manj->pos1.x && enm->direc == 1){
enm->direc = 0;
intial_enemie(enm);
}
if (Collision_trigo(manj->spos,enm->bpos)){
j= rand()%3 ;
Update_score(manj);
intialmpos(enm,j);
}else if (collision(manj->pos1,enm->bpos)){
j= rand()%3 ;
intialmpos(enm,j);
Update_Vie(manj);
}
}
}

