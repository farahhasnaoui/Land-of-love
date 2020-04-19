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
int input(robottt* rob,int i,int *continuer,int *recule)
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
                rob->positionrobot.x +=50;
                i++;
                
                break;

                case SDLK_LEFT:
               *recule=1;
                rob->positionrobot.x -=50;
                i++;
                break;
                
                case SDLK_UP:
                rob->positionrobot.y-=50;
                i++;
                break;
           }
           break;             
        
        }
return i;
}

robottt init_perso()
{

    robottt rob;
    rob.robot[0] = IMG_Load("droite1.png");
    rob.robot[1] = IMG_Load("droite3.png");
    rob.robot[2] = IMG_Load("droite2.png");
    rob.robot[3] = IMG_Load("droite4.png");


      rob.positionrobot.x = 0;
    rob.positionrobot.y = 400; 

  return rob;

}  

void display_perso(SDL_Surface *ecran,robottt rob,int i,SDL_Rect positionrobot,int recule)
{
    if (recule==0)
SDL_BlitSurface(rob.robot[i],NULL,ecran,&positionrobot);
else if (recule==1)
SDL_BlitSurface(rob.robot1[i],NULL,ecran,&positionrobot);
}

robottt init_perso1()
{

    robottt rob;
    rob.robot1[0] = IMG_Load("gauche1.png");
    rob.robot1[1] = IMG_Load("gauche2.png");
    rob.robot1[2] = IMG_Load("gauche3.png");
        rob.robot1[3] = IMG_Load("gauche4.png");



      rob.positionrobot.x = 0;
    rob.positionrobot.y = 400; 

  return rob;

}  







