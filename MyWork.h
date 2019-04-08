#ifndef MYWORK_H_INCLUDED
#define MYWORK_H_INCLUDED

typedef struct{
SDL_Surface* e;
SDL_Rect posecran;
}ecran;

typedef struct{
SDL_Surface* personnage;
SDL_Rect posPer;
}perso;

typedef struct{
SDL_Surface* imageFond;
SDL_Rect positionFond;
} fond  ;


int init_affich(ecran e, perso p, fond f);
void mouse_event (SDL_Event event,  perso p, ecran e, fond f);
void key_event (SDL_Event event,  perso p, ecran e, fond f );
void scroll(SDL_Event event , SDL_Rect camera);
#endif // MYWORK_H_INCLUDED
