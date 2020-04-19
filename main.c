#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fnc.h"
void  main(SDL_Surface *ecran)
{
    personagee pers;

    SDL_Event event;
    int continuer=1,i=0,t;

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO); //initialisation
    ecran=SDL_SetVideoMode(900, 700, 32,SDL_HWSURFACE);//afficher la fenetre

  int recule=0;
    image img;
    pers=init_perso();
    pers=init_perso1();
    img=init_img("bgg.png",0,130);

    SDL_EnableKeyRepeat(100,100); /*Activation de la répétition des touches  100 ms */

    while (continuer)
    {
         SDL_PollEvent(&event);
       switch(event.type)
          {
            case SDL_QUIT:
            continuer= 0;
            break;
          }
            i=input(&pers,i,&continuer,&recule);
            /*pers.positionpersonage.x+=10;
            i++;*/
           printf("%d\n",recule);
            if (i==3)
            {
            i=0;
            }
             SDL_Delay(100);
             display(ecran,img);
            display_perso(ecran,pers,i,pers.positionpersonage,recule);
            SDL_Flip(ecran);
           if (pers.positionpersonage.x>800)
            {
            pers.positionpersonage.x=0; 
            
            }
         if (pers.positionpersonage.y<400)//fixation jump
         pers.positionpersonage.y=400;

  
  }    


   for(i=0;i<=3;i++)
    SDL_FreeSurface(pers.personage[i]);
     for(i=0;i<=3;i++)
    SDL_FreeSurface(pers.personage1[i]);

}






