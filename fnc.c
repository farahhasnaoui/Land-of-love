#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fnc.h"

image init_img(char nomimage[100],int x,int y)
{
image img;
img.back=IMG_Load(nomimage);//load image
img.positiond.x=x;//position x de bg
img.positiond.y=y;//position y de bg
return img;
}

void display(SDL_Surface *ecran,image img)
{
SDL_BlitSurface(img.back,NULL,ecran,&img.positiond);//afficher l image

}
int input(personagee* pers,int i,int *continuer,int *recule)
{ int t;
SDL_Event event;
    SDL_WaitEvent(&event);
        switch(event.type)
        {
          
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
             
                case SDLK_RIGHT:
               *recule=0;
                pers->positionppersonage.x +=50;
                i++;
                
                break;

                case SDLK_LEFT:
               *recule=1;
                pers->positionpersonage.x -=50;
                i++;
                break;
                
                case SDLK_UP:
                pers->positionpersonage.y-=50;
                i++;
                break;
           }
           break;             
        
        }
return i;
}

personagee init_perso()
{

    personagee pers;
    pers.personage[0] = IMG_Load("droite1.png");
    pers.personage[1] = IMG_Load("droite3.png");
   pers.personage[2] = IMG_Load("droite2.png");
    pers.personage[3] = IMG_Load("droite4.png");


      pers.positionpersonage.x = 0;
    pers.positionpersonage.y = 400; 

  return pers;

}  

void display_perso(SDL_Surface *ecran ,personagee pers,int i,SDL_Rect positionpersonage,int recule)
{
    if (recule==0)
SDL_BlitSurface(pers.personage[i],NULL,ecran,&positionpersonage);
else if (recule==1)
SDL_BlitSurface(pers.personage1[i],NULL,ecran,&positionpersonage);
}

personagee init_perso1()
{

    personagee pers;
    pers.personage1[0] = IMG_Load("gauche1.png");
    pers.personage1[1] = IMG_Load("gauche2.png");
    pers.personage1[2] = IMG_Load("gauche3.png");
        pers.personage1[3] = IMG_Load("gauche4.png");



     pers.personage.x = 0;
    pers.personage.y = 400; 

  return pers;

}  







