//Title: Bataille Navale
//Author: MSS
//Date: 14.03.2019
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>


#pragma execution_character_set("UTF-8")

int Grille1[9][9]=
        {
                0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,0,
                0,0,0,0,0,0,0,0,0,
                0,0,0,0,3,0,0,0,0,
                0,0,0,0,3,0,0,0,0,
                0,0,0,0,3,0,0,0,0,
                0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,
                0,0,2,2,0,0,0,0,0
        };

void Game()
{
    int x;
    int y;
    printf("  X  A   B   C   D   E   F   G   H   I");
    for(x= 0;x<9;x++)
    {
        printf("\n");

        if(x==0)
        {
            printf("   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐\n  ");
        }
        if(x!=0)
        {
            printf("   ├───┼───┼───┼───┼───┼───┼───┼───┼───┤\n  ");
        }




        printf("%d",x+1);
        for(y=0;y<9;y++) {

            if (Grille1[x][y] == 0) {

                printf("│   ");
            }
                else if (Grille1[x][y] == 1) {
                    printf("│  l ");
                } else if (Grille1[x][y] == 2) {
                    printf("│ x ");
                } else if (Grille1[x][y] == 3) {
                    printf("│  ");
                } else if (Grille1[x][y] == 4) {
                    printf("│ X ");
                }


        }
        if(y==9)
        {
            printf("│");
        }
        if(x==8)
        {
            printf("\n   └───┴───┴───┴───┴───┴───┴───┴───┴───┘");
        }
    }
}



int main() {
    SetConsoleOutputCP(65001);

    int choix;

    printf("888             888   888   888                888     d8b         \n"
           "888             888   888   888                888     Y8P         \n"
           "888             888   888   888                888                 \n"
           "88888b.  8888b. 888888888888888 .d88b. .d8888b 88888b. 88888888b.  \n"
           "888 \"88b    \"88b888   888   888d8P  Y8b88K     888 \"88b888888 \"88b \n"
           "888  888.d888888888   888   88888888888\"Y8888b.888  888888888  888 \n"
           "888 d88P888  888Y88b. Y88b. 888Y8b.         X88888  888888888 d88P \n"
           "88888P\" \"Y888888 \"Y888 \"Y888888 \"Y8888  88888P'888  88888888888P\"  \n"
           "                                                          888      \n"
           "                                                          888      \n"
           "                                                          888      ");
    //Menu
    do {
        printf("\n\n_______________BATAILLE_NAVALE______________\n\n");
        printf("1. Nouvelle Partie");
        printf("\n2. Apprendre a jouer");
        printf("\n0. Quitter");

        //Que faire ?
        printf("\nIntroduisez un chiffre de 0 a 2: ");
        scanf("%d", &choix);
        if(choix <0 || choix > 2)
        {
            printf("Ceci n'est pas un choix !");
        }

        switch(choix)
        {
            case 0: printf("\nA la prochaine !");
                return 0;

            case 1: printf("\n\nNouvelle Partie\n");
                printf("\nBievenue sur le mode jeu");
                printf("\nIntroduire 0 pour revenir en arriere ou 1 pour lancer une partie: \n");
                scanf("%d",&choix);
                if (choix == 0)
                {
                    choix=+100;
                    break;
                }
                else if(choix==1)
                {
                    Game();
                }
                else
                {
                    printf("ce n'est pas un choix !\n");
                    break;
                }
                break;


            case 2: printf("\n\nInstructions\n");
                printf("\nLes regles s'affichent...");
                printf("\nIntroduire 0 pour revenir en arriere: ");
                scanf("%d",&choix);
                if (choix == 0)
                {
                    choix=+100;
                    break;
                }
                break;
        }

    }while (choix < 0 || choix > 3);

    return 0;
}
