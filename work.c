#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"work.h"


//*******************************************************************************
void deplacement (perso *p,SDL_Event event,int *done,int *detection,rock *r,SDL_Event *felsa,texte *t ,screen *sc,int *sco,vie *v,menusj *menuj)
{
int test;
while(SDL_PollEvent(&event))
{switch(event.type)
 { case SDL_QUIT:
    (*done)=0;
   break;
   case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
     {
      case  SDLK_UP:
       update (&test,detection,p,felsa,&event,t,sco,sc,v,r);
        break;
      case SDLK_DOWN:
          update (&test,detection,p,felsa,&event,t,sco,sc,v,r);
        break;
      case SDLK_RIGHT:
           update (&test,detection,p,felsa,&event,t,sco,sc,v,r);

        break;
       case SDLK_LEFT:
            update (&test,detection,p,felsa,&event,t,sco,sc,v,r);
         break;
       case SDLK_ESCAPE:
        if (menuj->o == 0 ){
menuj->m = 1 ;
}
                    break;
     }
break;
      case SDL_KEYUP :
        switch(event.key.keysym.sym)
     {
    case SDLK_ESCAPE :
if (menuj->m == 0){
        menuj->o = 0 ;
}
        break;
     }
        break;

}
}
}

//*******************************************************************************

int InitAff(screen sc,background bg,perso p,vie v,rock r,texte t,menusj *menuj,int done2)
{
int i,x;
SDL_BlitSurface(bg.image,NULL,sc.s,&bg.pos);
SDL_BlitSurface(p.imageper,NULL,sc.s,&p.posper);
SDL_BlitSurface(bg.imagemini,NULL,sc.s,&bg.posmini);
SDL_BlitSurface(p.imagenokta,NULL,sc.s,&p.posnokta1);
SDL_BlitSurface(v.barre,NULL,sc.s,&v.posbarre);
SDL_BlitSurface(v.sang,&v.sizevie,sc.s,&v.possang);
SDL_BlitSurface(r.imagerock,NULL,sc.s,&r.posrock);
SDL_BlitSurface(t.txt,NULL,sc.s,&t.postexte);
if (done2==1)
{
x=showmenud2(&sc,menuj);
}
if (menuj->m==1){
        SDL_BlitSurface(menuj->menu,NULL,sc.s,&menuj->posm);
for (i=0;i<2;i++){
if (menuj->selec[i]==1){
SDL_BlitSurface(menuj->boutons[i],NULL,sc.s,&menuj->pos[i]);
}
}
}
SDL_Flip(sc.s);
return x;
}

//*******************************************************************************
void initialiser_score(texte *t ,screen *sc,int *sco)
{
TTF_Init();
t->police= TTF_OpenFont("BebasNeue-Book.ttf", 40);
t->color.r = 255;
t->color.g = 0;
t->color.b = 0;

  t->postexte.x = 600;
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
*sco = -10 ;
v->sizevie.w = 0;
}else{

v->sizevie.w =v->nbvie ;
}
SDL_BlitSurface(v->barre,NULL,sc->s,&v->posbarre);
SDL_BlitSurface(v->sang,&v->sizevie,sc->s,&v->possang);
}

//*******************************************************************************

void update (int *test,int *detection,perso *p,SDL_Event *felsa,SDL_Event *event,texte *t,int *sco,screen *sc,vie *v,rock *r)
{
*test=1;
           if(*detection==0)
          {
          button(event,p);
         *detection=collision(p,r);
         *test=0;
          }
         else if((*detection==1) && (felsa->key.keysym.sym!=event->key.keysym.sym))
         {
          button(event,p);
         *detection=collision(p,r);
         *test=0;
         }
         if (*test==1){
                SDL_EnableKeyRepeat(30,30);
               initialiser_score(t ,sc,sco);
                Update_Vie(v,sco,sc);
         }
        felsa->key.keysym.sym=event->key.keysym.sym;
}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
void setpositions (background *bg,rock *r,perso *p,vie *v,menusj* menuj)
{
bg->pos.x=0;
bg->pos.y=0;
bg->pos.w=bg->image->w;
bg->pos.h=bg->image->h;

bg->posmini.x=430;
bg->posmini.y=488;
bg->posmini.w=bg->imagemini->w;
bg->posmini.h=bg->imagemini->h;

menuj->posm.x=300;
menuj->posm.y=100;
menuj->posm.w=694;
menuj->posm.h=379;

menuj->pos[0].x=609;
menuj->pos[0].y=277;
menuj->pos[0].w=53;
menuj->pos[0].h=27;

menuj->pos[1].x=633;
menuj->pos[1].y=409;
menuj->pos[1].w=65;
menuj->pos[1].h=26;

p->posnokta1.x=436;
p->posnokta1.y=533;
p->posnokta1.w=p->imagenokta->w;
p->posnokta1.h=p->imagenokta->h;

r->posrock.x=500;
r->posrock.y=300;
r->posrock.w=r->imagerock->w;
r->posrock.h=r->imagerock->h;

p->posper.x=20;
p->posper.y=170;
p->posper.w=p->imageper->w;
p->posper.h=p->imageper->h;

v->posvie.x=0;
v->posvie.y=0;
v->posbarre.x=0;
v->posbarre.y=0;
v->possang.x=59;
v->possang.y=11;
SDL_GetClipRect(v->sang,&v->sizevie);
v->nbvie=v->sizevie.w;
}
//*******************************************************************************
void load(screen *sc,background *bg, perso *p,rock *r,vie *v,menusj *menuj)
{
sc->s=SDL_SetVideoMode(1200,600,32, SDL_HWSURFACE |SDL_DOUBLEBUF);
bg->image=SDL_LoadBMP("background.bmp");
bg->imagemini=IMG_Load("mini.png");
p->imagenokta=IMG_Load("nokta.png");
p->imageper=IMG_Load("Fichier 1.png");
r->imagerock=IMG_Load("rock.png");
v->barre=IMG_Load("barre.png");
v->sang=IMG_Load("sang.png");
menuj->menu=IMG_Load("menu.png");
menuj->menu2=IMG_Load("menu2.png");
menuj->boutons[0]=IMG_Load("oui.png");
menuj->boutons[1]=IMG_Load("non.png");
}

//*******************************************************************************


void button (SDL_Event *event,perso *p)
{
if (event->key.keysym.sym==SDLK_UP)
{
if (p->posper.y>0){
p->posper.y -= 4;
p->posnokta1.y -=1;
}
}
else if (event->key.keysym.sym==SDLK_DOWN)
{
    if (p->posper.y<600-p->posper.h){
p->posper.y += 4;
p->posnokta1.y +=1;
}
    }
else if (event->key.keysym.sym==SDLK_RIGHT)
{
    if (p->posper.x<1200-p->posper.w){
p->posper.x += 4;
p->posnokta1.x +=1;
}
    }
else if (event->key.keysym.sym==SDLK_LEFT)
{
    if (p->posper.x>0){
p->posper.x -= 4;
p->posnokta1.x -=1;
}
}
}
/*********************************************************************************************/
int showmenud(screen *sc,menusj *menuj )
{
int x,y,i ;
SDL_Event eventt ;
SDL_PollEvent(&eventt);
switch(eventt.type){
case SDL_QUIT:
SDL_FreeSurface(menuj->boutons[0]);
SDL_FreeSurface(menuj->boutons[1]);
break;
case SDL_KEYDOWN :
if (eventt.key.keysym.sym==SDLK_ESCAPE){
if (menuj->o == 1 ){
menuj->m = 0 ;
}
}
if (eventt.key.keysym.sym==SDLK_DOWN){
if (menuj->h==1){
menuj->j++;
if (menuj->j>=2){
menuj->j=0;
}
menuj->selec[menuj->j]=1 ;
if (menuj->j>=1){
menuj->selec[menuj->j-1]=0;
}else if (menuj->j==0){
menuj->selec[1]=0;
}
menuj->h=0;
}
}
if (eventt.key.keysym.sym==SDLK_UP){
if (menuj->h==1){
menuj->j--;
if (menuj->j<=-1){
menuj->j=1;
}
menuj->selec[menuj->j]=1 ;
if (menuj->j<1){
menuj->selec[menuj->j+1]=0;
}else if (menuj->j==1){
menuj->selec[0]=0;
}
menuj->h=0;
}
}
if (eventt.key.keysym.sym==SDLK_SPACE){
return menuj->j;
}
break;
case SDL_KEYUP :
if (eventt.key.keysym.sym==SDLK_ESCAPE) {
if (menuj->m == 0 ){
menuj->o = 0;
}else if (menuj->m ==1) {
menuj->o = 1;
}
}
menuj->h=1;
break;
case SDL_MOUSEMOTION :
x= eventt.motion.x;
y=eventt.motion.y ;
for (i=0;i<2;i++){
if (x>menuj->pos[i].x && x<menuj->pos[i].x+menuj->pos[i].w && y>menuj->pos[i].y && y<=menuj->pos[i].y+menuj->pos[i].h ){
menuj->h=1 ;
if (menuj->selec[i]==0){
menuj->j=i ;
menuj->selec[i]=1 ;
}
}else
if (menuj->selec[i]==1){
menuj->selec[i]=0;
}
}
break ;
case SDL_MOUSEBUTTONDOWN :
x=eventt.button.x;
y=eventt.button.y;
for (i=0;i<2;i++){
if (x>menuj->pos[i].x && x<menuj->pos[i].x+menuj->pos[i].w && y>menuj->pos[i].y && y<=menuj->pos[i].y+menuj->pos[i].h ){
return i ;
}
}
break ;
}

SDL_Flip(sc->s);
return -1;
}


void save(perso *p,vie *v,int *sco,char nomf[])
{
FILE* fich;
fich=fopen(nomf,"w");
/*pos personnage w pos nokta w score wel vie*/
fprintf(fich,"%d - %d - %d - %d - %d - %d\n", p->posper.x,p->posper.y,p->posnokta1.x,p->posnokta1.y,v->nbvie,*sco);
fclose(fich);
}

void re(perso *p,vie *v,int *sco,char nomf[],texte *t,screen *sc)
{
int a,b,c,d,e,f;
FILE* fich;
fich=fopen(nomf,"r");
fscanf(fich,"%d - %d - %d - %d - %d - %d\n",&a,&b,&c,&d,&e,&f);
p->posper.x=a;
p->posper.y=b;
p->posnokta1.x=c;
p->posnokta1.y=d;
v->nbvie=e;
*sco=f-10;
fclose(fich);
initialiser_score(t ,sc,sco);
v->sizevie.w =v->nbvie ;

SDL_BlitSurface(v->barre,NULL,sc->s,&v->posbarre);
SDL_BlitSurface(v->sang,&v->sizevie,sc->s,&v->possang);

}



int showmenud2(screen *sc,menusj *menuj )
{
int x,y,i ;
SDL_Event eventt ;
SDL_BlitSurface(menuj->menu2,NULL,sc->s,&menuj->posm);
SDL_PollEvent(&eventt);
switch(eventt.type){
case SDL_QUIT:
SDL_FreeSurface(menuj->boutons[0]);
SDL_FreeSurface(menuj->boutons[1]);
break;
case SDL_KEYDOWN :
if (eventt.key.keysym.sym==SDLK_DOWN){
if (menuj->h==1){
menuj->j++;
if (menuj->j>=2){
menuj->j=0;
}
menuj->selec[menuj->j]=1 ;
if (menuj->j>=1){
menuj->selec[menuj->j-1]=0;
}else if (menuj->j==0){
menuj->selec[1]=0;
}
menuj->h=0;
}
}
if (eventt.key.keysym.sym==SDLK_UP){
if (menuj->h==1){
menuj->j--;
if (menuj->j<=-1){
menuj->j=1;
}
menuj->selec[menuj->j]=1 ;
if (menuj->j<1){
menuj->selec[menuj->j+1]=0;
}else if (menuj->j==1){
menuj->selec[0]=0;
}
menuj->h=0;
}
}
if (eventt.key.keysym.sym==SDLK_SPACE){
return menuj->j;
}
break;
case SDL_KEYUP :
menuj->h=1;
break;
case SDL_MOUSEMOTION :
x= eventt.motion.x;
y=eventt.motion.y ;
for (i=0;i<2;i++){
if (x>menuj->pos[i].x && x<menuj->pos[i].x+menuj->pos[i].w && y>menuj->pos[i].y && y<=menuj->pos[i].y+menuj->pos[i].h ){
menuj->h=1 ;
if (menuj->selec[i]==0){
menuj->j=i ;
menuj->selec[i]=1 ;
}
}else
if (menuj->selec[i]==1){
menuj->selec[i]=0;
}
}
break ;
case SDL_MOUSEBUTTONDOWN :
x=eventt.button.x;
y=eventt.button.y;
for (i=0;i<2;i++){
if (x>menuj->pos[i].x && x<menuj->pos[i].x+menuj->pos[i].w && y>menuj->pos[i].y && y<=menuj->pos[i].y+menuj->pos[i].h ){
return i ;
}
}
break ;
}
for (i=0;i<2;i++){
if (menuj->selec[i]==1){
SDL_BlitSurface(menuj->boutons[i],NULL,sc->s,&menuj->pos[i]);
}
}
SDL_Flip(sc->s);
return -1;
}











