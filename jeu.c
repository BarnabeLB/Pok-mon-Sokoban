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
    SDL_Surface *ecranJeu, *persoFace, *persoDos, *persoGauche, *persoDroite = NULL;
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
    /*Perso Bas*/
    persoFace = IMG_Load("SachaFace.png");
    SDL_SetColorKey(persoFace, SDL_SRCCOLORKEY, SDL_MapRGB(persoFace->format,219,221,146 ));

    /*Perso Haut*/
    persoDos = IMG_Load("SachaDos.png");
    SDL_SetColorKey(persoDos, SDL_SRCCOLORKEY, SDL_MapRGB(persoDos->format, 219,221,146));
    SDL_SetAlpha(persoDos, SDL_SRCALPHA,0); /*On met en transparences les autres surfaces pour éviter que le jeu se lance
                                                sur une superposition des 4 surfaces perso*/
    /*Perso Gauche*/
    persoGauche = IMG_Load("SachaGauche.png");
    SDL_SetColorKey(persoGauche, SDL_SRCCOLORKEY, SDL_MapRGB(persoGauche->format, 219,221,146));
    SDL_SetAlpha(persoGauche, SDL_SRCALPHA,0);/*idem*/

    /*Perso Droite*/
    persoDroite = IMG_Load("SachaDroite.png");
    SDL_SetColorKey(persoDroite, SDL_SRCCOLORKEY, SDL_MapRGB(persoDroite->format, 219, 221, 146));
    SDL_SetAlpha(persoDroite, SDL_SRCALPHA,0);/*idem*/

    while(run)
    {

        SDL_WaitEvent(&event);


            switch(event.type)
            {
            case SDL_QUIT:
                run = 0;
                break;
            case SDL_KEYDOWN:
                    /* 3.On reset la transparence au début de chaque boucle sinon on finit par bouger des surfaces transparentes
                    et on voit plus rien. On reset après le SDL_KEYDOWN pour ne pas qu'avant d'avoir appuyé sur une touche
                    directionnelle on se retrouve avec les 4 surfaces en superposition*/

        SDL_SetAlpha(persoDos, 0,255);
        SDL_SetAlpha(persoFace, 0,255);
        SDL_SetAlpha(persoGauche, 0,255);
        SDL_SetAlpha(persoDroite, 0,255);

                switch(event.key.keysym.sym)
                {
                    /*2. On met en transparence les surfaces qui ne seront pas bougées durant le SDLK_DIRECTION*/

                case SDLK_UP:

                    positionPerso.y--;
                    SDL_SetAlpha(persoFace, SDL_SRCALPHA,0);
                    SDL_SetAlpha(persoGauche, SDL_SRCALPHA,0);
                    SDL_SetAlpha(persoDroite, SDL_SRCALPHA,0);

                    break;

                case SDLK_DOWN:

                    positionPerso.y++;
                    SDL_SetAlpha(persoDos, SDL_SRCALPHA,0);
                    SDL_SetAlpha(persoGauche, SDL_SRCALPHA,0);
                    SDL_SetAlpha(persoDroite, SDL_SRCALPHA,0);

                    break;
                case SDLK_LEFT:
                    positionPerso.x--;
                    SDL_SetAlpha(persoDos, SDL_SRCALPHA,0);
                    SDL_SetAlpha(persoFace, SDL_SRCALPHA,0);
                    SDL_SetAlpha(persoDroite, SDL_SRCALPHA,0);
                    break;

                case SDLK_RIGHT:
                    positionPerso.x++;
                    SDL_SetAlpha(persoDos, SDL_SRCALPHA,0);
                    SDL_SetAlpha(persoGauche, SDL_SRCALPHA,0);
                    SDL_SetAlpha(persoFace, SDL_SRCALPHA,0);
                    break;

               /* case SDLK_ESCAPE:
                    SDL_SetAlpha(persoFace, SDL_SRCALPHA,0);
                    SDL_SetAlpha(persoGauche, SDL_SRCALPHA,0);
                    SDL_SetAlpha(persoDroite, SDL_SRCALPHA,0);
                    break;*/

                }

            }

    SDL_FillRect(ecranJeu, NULL, SDL_MapRGB(ecranJeu->format, 255,255,255));

/*1. on commence par bliter toutes les surfaces sur la même position*/
    SDL_BlitSurface(persoFace, NULL, ecranJeu, &positionPerso);
    SDL_BlitSurface(persoDos, NULL, ecranJeu, &positionPerso);
    SDL_BlitSurface(persoGauche, NULL, ecranJeu,&positionPerso);
    SDL_BlitSurface(persoDroite, NULL, ecranJeu, &positionPerso);



    SDL_Flip(ecranJeu);




    }








    return 1;
}
