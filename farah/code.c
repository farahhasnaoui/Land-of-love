#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
 int main (int argc,char** argv)
 {


	int menu=1,play=0;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen=NULL;
	screen=SDL_SetVideoMode(600,600,32,SDL_HWSURFACE);
	SDL_WM_SetCaption(" *** Land Of Love ***  ",NULL);

	SDL_Rect screen_rect;
	screen_rect.x=0;
	screen_rect.y=0;

	//Déclaration du fond du menu
	SDL_Surface *background=NULL;
	background=IMG_Load("fond.png");
	SDL_Rect background_rect;
	background_rect.x = 0;
	background_rect.y = 0;
	
       //Déclaration de son nom li mel fou9 "Land of love"
       SDL_Surface *namejeu=NULL;
       namejeu=IMG_Load("landoflove4.png");
       SDL_Rect namejeu_rect;
       namejeu_rect.x = (0/2)-(0/2);
       namejeu_rect.y =0;
 

        //Déclaration du bouton Play et sa position
	SDL_Surface *play_button=NULL;
	play_button=IMG_Load("play4.png");
	SDL_Rect play_button_rect;
	play_button_rect.x = (600/2)-(600/2);
	play_button_rect.y = 0;


     

        //Bouton play en blanc, lorsqu'on clic sur play sa couleur change
	SDL_Surface *play2button=NULL;
	play2button=IMG_Load("play42.png");



        //Déclaration de bouton options
	SDL_Surface *settings_button=NULL;
	settings_button=IMG_Load("options4.png");
	SDL_Rect settings_button_rect;
	settings_button_rect.x = (600/2)-(600/2);
	settings_button_rect.y = 70;
	
        
        //Bouton options en blanc, lorsqu'on clic sur play sa couleur change
        SDL_Surface *settings2button=NULL;
	settings2button=IMG_Load("options42.png");

         

       /* SDL_Surface *barre2=NULL;
	barre2=IMG_Load("barre2.png");
	SDL_Rect barre2_rect;
	barre2_rect.x = (600/2)-(291/2);
	barre2_rect.y = 452; */     //ena njarreb fi faza



	

     
	
        //Déclaration du bouton Quitter et sa position
	SDL_Surface *quit_button=NULL;
	quit_button=IMG_Load("quit4.png");
	SDL_Rect quit_button_rect;
        quit_button_rect.x = (600/2)-(600/2);
	quit_button_rect.y = 140;
	

        //Bouton options en blanc, lorsqu'on clic sur play sa couleur change
	SDL_Surface *quit2_button=NULL;
	quit2_button=IMG_Load("quit42.png");

	
        //Déclaration du bouton X eli melfou9 à gauche et sa position
	SDL_Surface *close_button=NULL;
	close_button=IMG_Load("close.png");
	SDL_Rect close_button_rect;
	close_button_rect.x = 10;
	close_button_rect.y = 25;
	


	
	//Déclaration du bouton Favebook et sa position
	SDL_Surface *facebook=NULL;
	facebook=IMG_Load("facebook.png");
	SDL_Rect facebook_rect;
	facebook_rect.x = 300;
	facebook_rect.y = 300;
	
        //Déclaration du bouton Instagram et sa position
	SDL_Surface *instagram=NULL;
	instagram=IMG_Load("instagram.png");
	SDL_Rect instagram_rect;
	instagram_rect.x = 400;
	instagram_rect.y = 400;

    
     //transparence des boutons:       
        SDL_SetColorKey(instagram, SDL_SRCCOLORKEY, SDL_MapRGB(instagram->format, 255, 255, 255));
	      //  SDL_SetColorKey(facebook, SDL_SRCCOLORKEY, SDL_MapRGB(facebook->format, 255, 255, 255));
	     //   SDL_SetColorKey(namejeu, SDL_SRCCOLORKEY, SDL_MapRGB(namejeu->format, 255, 255, 255));	
        SDL_SetColorKey(play_button, SDL_SRCCOLORKEY, SDL_MapRGB(play_button->format, 255, 255, 255));
        SDL_SetColorKey(settings_button, SDL_SRCCOLORKEY, SDL_MapRGB(settings_button->format, 255, 255, 255));
        SDL_SetColorKey(quit_button, SDL_SRCCOLORKEY, SDL_MapRGB(quit_button->format, 255, 255, 255));

	
        // La musique du background
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
	{
		printf("%s\n",Mix_GetError());
	}
	Mix_Music *music; //construct mix_music_pointer
	music=Mix_LoadMUS("Song.mp3"); //Load the music
	Mix_PlayMusic(music, -1);//play music;

	
        //L'execution de toutes les objet et leur boucle:
	SDL_BlitSurface(background,NULL,screen,&screen_rect);
	int x,y,a,b;
	while(menu)
	{
		SDL_BlitSurface(namejeu,NULL,screen,&namejeu_rect);
		
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					menu=0;
				break;

             //L'execution mta fazet tabdil lalwen ki t3addi souris ala bouton: 
				case SDL_MOUSEMOTION:
					x=event.motion.x;
					y=event.motion.y;
		//Play_Button
               //Lezemni nbaddel les x et les y pour que ça fonctionne
					if (x > (600/2)-(600/2) && x < (600/2)+(600/2) && y > 372 && y < 372 /*+longeur*/)
					{
						SDL_BlitSurface(play2button,NULL,screen,&play_button_rect);
					}
				//Settings_Button
					else if (x > (600/2)-(291/2) && x < (600/2)+(291/2) && y > 452 && y < 520)
					{
						SDL_BlitSurface(settings2button,NULL,screen,&settings_button_rect);
					}
					
					else if (x > (600/2)-(291/2) && x < (600/2)+(291/2) && y > 532 && y < 600)
					{
						SDL_BlitSurface(quit2_button,NULL,screen,&quit_button_rect);
					}
   
					else 
					{
						SDL_BlitSurface(play_button,NULL,screen,&play_button_rect);
SDL_BlitSurface(namejeu,NULL,screen,&namejeu_rect);					SDL_BlitSurface(settings_button,NULL,screen,&settings_button_rect);	SDL_BlitSurface(quit_button,NULL,screen,&quit_button_rect);						SDL_BlitSurface(facebook,NULL,screen,&facebook_rect);
SDL_BlitSurface(close_button,NULL,screen,&close_button_rect);
SDL_BlitSurface(instagram,NULL,screen,&instagram_rect);
					}
				break;

//hedha lkol pour liberer de l'espace apres l'utilisation
//on utilise l fonction SDL_FreeSurface aala de tous les objets du menu
	
		}
            }
              SDL_Flip(screen);
	}
	SDL_FreeSurface(background);
	SDL_FreeSurface(quit_button);
	SDL_FreeSurface(quit2_button);
	SDL_FreeSurface(play2button);
	SDL_FreeSurface(play_button);
	SDL_FreeSurface(settings_button);
	SDL_FreeSurface(settings2button);
	Mix_FreeMusic(music);
	Mix_CloseAudio();

	return 0;
}
