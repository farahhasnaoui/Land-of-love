#ifndef FNC_H_
#define FNC_H_

typedef struct image
{ 
	SDL_Rect positiond;
        SDL_Surface* back;
}image;

typedef struct robottt

{

	SDL_Surface *robot[7];
	SDL_Surface *robot1[3];	
    SDL_Rect positionrobot;

}robottt;

image init_img(char nomimage[100],int x,int y);
void display(SDL_Surface *ecran,image img);
robottt init_perso();
void display_perso(SDL_Surface *ecran,robottt rob,int i,SDL_Rect positionrobot,int recule);
int input(robottt *rob,int i,int *continuer,int *recule);
robottt init_perso1();







#endif
