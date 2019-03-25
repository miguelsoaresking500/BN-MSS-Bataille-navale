//Title: Bataille Navale
//Author: MSS
//Date: 14.03.2019
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

#define X 9
#define Y 9


#pragma execution_character_set("UTF-8")

int Grille1[X][Y] =
        {
                1, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0
        };

void Game() {
    int x;
    int y;
    printf("\n  X  A   B   C   D   E   F   G   H   I");
    for (x = 0; x < X; x++) {
        printf("\n");

        if (x == 0) {
            printf("   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐\n  ");
        }
        if (x != 0) {
            printf("   ├───┼───┼───┼───┼───┼───┼───┼───┼───┤\n  ");
        }


        printf("%d", x + 1);
        for (y = 0; y < X; y++) {

            if (Grille1[x][y] == 0) {

                printf("│   ");
            } else if (Grille1[x][y] == 1) {
                printf("│   ");
            } else if (Grille1[x][y] == 2) {
                printf("│ x ");
            } else if (Grille1[x][y] == 3) {
                printf("│ ~ ");
            } else if (Grille1[x][y] == 4) {
                printf("│ X ");
            }


        }
        if (y == 9) {
            printf("│");
        }
        if (x == 8) {
            printf("\n   └───┴───┴───┴───┴───┴───┴───┴───┴───┘");
        }
    }
}

void shoot() {

    int compteur = 0;
    int introx = 0;
    int introy = 0;
    int test = 0;
    char Lettre[1];
    while (test != 1) {
        Game();
        printf("              \nentrez la cordonée horizontale: \n");
        scanf("%d", &introx);

        if (introx == -1) {
            printf("entrez la cordonée horizontale et faites enter\n");
            printf("\nentrez la cordonée horizontale \n");
            scanf("%d", &introx);
        }
        printf("\nentrez la coordonee verticale:\n ");
        scanf("%s", Lettre);

        //if (introy == -1) {
        //   printf("entrez la cordonée Verticale et faites enter\n");
        // printf("entrez la cordonée Verticale ");
        //scanf("%s", Lettre);
        //}
        compteur = compteur + 1;

        if (strcmp(Lettre, "A") == 0) {
            introy = 0;
        } else if (strcmp(Lettre, "B") == 0) {
            introy = 1;
        } else if (strcmp(Lettre, "C") == 0) {
            introy = 2;
        } else if (strcmp(Lettre, "D") == 0) {
            introy = 3;
        } else if (strcmp(Lettre, "E") == 0) {
            introy = 4;
        } else if (strcmp(Lettre, "F") == 0) {
            introy = 5;
        } else if (strcmp(Lettre, "G") == 0) {
            introy = 6;
        } else if (strcmp(Lettre, "H") == 0) {
            introy = 7;
        } else if (strcmp(Lettre, "I") == 0) {
            introy = 8;
        }


        if (Grille1[introx][introy] == 1) {
            printf("\ntouché");
            Grille1[introx][introy] = 2;
        } else if (Grille1[introx][introy] == 2) {
            printf("\ndéjà touché");
        } else if (Grille1[introx][introy] == 3) {
            printf("\n A l'eau");
            Grille1[introx][introy] = 3;
        } else if (Grille1[introx][introy] == 4) {
            printf("\n coulé");
            Grille1[introx][introy] = 4;
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
        if (choix < 0 || choix > 2) {
            printf("Ceci n'est pas un choix !");
        }

        switch (choix) {
            case 0:
                printf("\nA la prochaine !");
                return 0;

            case 1:
                shoot();
                printf("\n\nNouvelle Partie\n");
                printf("\nBievenue sur le mode jeu");
                printf("\nIntroduire 0 pour revenir en arriere ou 1 pour lancer une partie: \n");
                scanf("%d", &choix);
                if (choix == 0) {
                    choix = +100;
                    break;
                } else if (choix == 1) {
                    Game();
                } else {
                    printf("ce n'est pas un choix !\n");
                    break;
                }
                break;


            case 2:
                printf("\n\nInstructions\n");
                printf("\nLes regles s'affichent...");
                printf("\nIntroduire 0 pour revenir en arriere: ");
                scanf("%d", &choix);
                if (choix == 0) {
                    choix = +100;
                    break;
                }
                break;
        }

    } while (choix < 0 || choix > 3);

    return 0;
}
