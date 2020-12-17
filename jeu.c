/*
Jeu de type Sobokan avec des sprites de Pokémon génration 3;

Réalisé à la suite du cours sur le C d'Openclassroom.

Décembre 2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_image.h>

int jeu(int continuer)
{
    int run = 1;
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *ecranJeu, *perso = NULL;
    SDL_Rect position, positionPerso;
    SDL_EnableUNICODE(1);
    SDL_EnableKeyRepeat(10,1);
    ecranJeu = SDL_SetVideoMode(768,768,32,SDL_HWSURFACE);

    position.x = 0;
    position.y = 0;
    positionPerso.x = 368;
    positionPerso.y = 368;

    if(ecranJeu == NULL)
    {
        fprintf(stderr,"impossible d'ouvrir ecranJeu, erreur : %s", SDL_GetError() );
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("Pokémon Sokoban jeu", NULL);
    perso = IMG_Load("pikachu.png");

    while(run)
    {
        SDL_WaitEvent(&event);

            switch(event.type)
            {
            case SDL_QUIT:
                run = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {

                case SDLK_UP:
                    positionPerso.y--;
                    break;

                case SDLK_DOWN:
                    positionPerso.y++;
                    break;
                case SDLK_LEFT:
                    positionPerso.x--;
                    break;

                case SDLK_RIGHT:
                    positionPerso.x++;
                    break;
                }

            }
    SDL_FillRect(ecranJeu, NULL, SDL_MapRGB(ecranJeu->format, 255,255,255));
    //SDL_BlitSurface(perso, NULL, ecranJeu, &position);
    SDL_BlitSurface(perso, NULL, ecranJeu, &positionPerso);
    SDL_Flip(ecranJeu);
    }



    printf("jeu");




    return 1;
}
