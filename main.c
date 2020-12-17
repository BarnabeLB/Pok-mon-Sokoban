/*
Jeu de type Sobokan avec des sprites de Pokémon génration 3;

Réalisé à la suite du cours sur le C d'Openclassroom.

Décembre 2020
_____________
main.c
_____________


*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_image.h>

main(int argc, char *argv[])

{

int continuer = 1;

SDL_Event event;
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *ecran = NULL, *ecranAccueil = NULL;
SDL_Rect positionAccueil, perso;
SDL_EnableUNICODE(1); /*nécessaire pour que SDLK_numéro soit reconnu*/

positionAccueil.x = 0;
positionAccueil.y = 0;



if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
    fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
    }

ecran=SDL_SetVideoMode(768,768, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("Pokémon Sokoban", NULL);
ecranAccueil = IMG_Load("EcranAccueil.png");


while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;

            case SDL_KEYDOWN:
            switch(event.key.keysym.unicode)/*.unicode à la place de .sym pour la
                                             reconnaissance des numéros sur le clavier de l'ordi
                                             portable*/
                {
                case SDLK_1:
                    jeu(continuer);
                    /*envoie vers jeu.c */
                    break;
                case SDLK_2:
                    continuer = 0; /*envoie vers éditeur.c*/
                    break;

                }
            break;

        }
SDL_BlitSurface(ecranAccueil, NULL, ecran, &positionAccueil);
SDL_Flip(ecran);

    }





printf("test\n");

SDL_FreeSurface(ecranAccueil);
SDL_FreeSurface(ecran);
SDL_Quit();

return EXIT_SUCCESS;
}
