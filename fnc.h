#ifndef FNC_H_
#define FNC_H_

typedef struct image
{ 
	SDL_Rect positiond;
        SDL_Surface* back;
}image;

typedef struct personagee

{

	SDL_Surface *personage[7];
	SDL_Surface *personage1[3];	
    SDL_Rect positionpersonage;

}personagee;

image init_img(char nomimage[100],int x,int y);
void display(SDL_Surface *ecran,image img);
personagee init_perso();
void display_perso(SDL_Surface *ecran,personagee pers,int i,SDL_Rect positionpersonage,int recule);
int input(personagee *pers,int i,int *continuer,int *recule);
personagee init_perso1();







#endif
