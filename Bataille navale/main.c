//Title: Bataille Navale
//Author: MSS
//Date: 14.03.2019
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

#define X 9
#define Y 9
#define nbgrilles 3

#pragma execution_character_set("UTF-8")
//Grille
int Grille1[X][Y] =
        {

        };
void chosegri() {

    int choosegrille = 1000;
    char randomname[50];
    do
    {
        printf("\n");
        for (int i = 0; i < nbgrilles; i++) {
            printf("\tGrille %d",i+1);
        }
        printf("\t0.Random");

        printf("\n\nChossissez une grille: ");
        scanf("%d", &choosegrille);

        if (choosegrille<1 && choosegrille>nbgrilles)
        {
            printf("\nCette grille n'est pas disponnible ou n'existe pas !");
            choosegrille+=1000;
        }
    }while(choosegrille<0 && choosegrille>nbgrilles);

    if(choosegrille==0)
    {
        choosegrille= rand() % 3;
    }
    FILE *fichier = NULL;
    sprintf(randomname,"Grille%d.txt",choosegrille);
    fichier =fopen(randomname,"r");

    for (int x = 0; x < X;x++)
    {
        for (int y = 0; y <Y ;y++)
        {
            char c = fgetc(fichier);
            Grille1 [x][y]= c - '0';
        }
    }
    fclose(fichier);
}
//Tableau du Bateau
int tabbateau[5] = {0, 0, 0, 0, 0};//pour savoir combien de fois on a touché quel bateau
void coule(int x,int y)
{
    for (int i=1;i<=4;i++)
    {
        if (tabbateau[i]==i)
        {
            for(int s=0 ;s<X;s++)
            {
                for(int nt=0;nt<Y;nt++)
                {
                    if(Grille1[x][y] ==10+i)
                    {
                        Grille1[x][y] +=10;
                    }
                }
            }
        }

    }

}

void Game() {
    int x;
    int y;
    printf("\n  X  1   2   3   4   5   6   7   8   9");
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

            coule(x,y);

            if (Grille1[x][y] == 0 || (Grille1[x][y] == 2 || Grille1[x][y] == 3 || Grille1[x][y] == 4)) {
                printf("│   ");
            } else if (Grille1[x][y] == 12 || Grille1[x][y] == 13 || Grille1[x][y] == 14) {
                printf("│ x ");
            } else if (Grille1[x][y] == -1) {
                printf("│ ~ ");
            } else if (Grille1[x][y] == 22 || Grille1[x][y] == 23 || Grille1[x][y] == 24) {
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
    int introx;
    int introy;
    int GameOver = 0;

    chosegri();
    do {
        Game();
        printf("\ncoordonné Vertical\n");
        scanf("%d", &introy);
        printf("\ncoordonné horizontal\n");
        scanf("%d", &introx);

        int valcase = Grille1[introx - 1][introy - 1];

        if (valcase == 0) {
            Grille1[introx - 1][introy - 1] = -1;
            printf("A l'eau");
        } else if (valcase == 2 || valcase == 3 || valcase == 4) {
            printf("Touché");

            tabbateau[valcase] += 1;
            Grille1[introx - 1][introy - 1] += 10;



        } else if (valcase > 10 || valcase == -1) {
            printf("deja touché");
        }
        GameOver = 1;

        system("cls");

        for (int i = 2; i <= 4; i++) //
        {   if(tabbateau[i]!=i)
            GameOver = 0;
        }
        if (GameOver == 1) {
            printf("\n .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. \n"
                   "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n"
                   "| | ____   ____  | || |     _____    | || |     ______   | || |  _________   | || |     ____     | || |  _______     | || |  ____  ____  | |\n"
                   "| ||_  _| |_  _| | || |    |_   _|   | || |   .' ___  |  | || | |  _   _  |  | || |   .'    `.   | || | |_   __ \\    | || | |_  _||_  _| | |\n"
                   "| |  \\ \\   / /   | || |      | |     | || |  / .'   \\_|  | || | |_/ | | \\_|  | || |  /  .--.  \\  | || |   | |__) |   | || |   \\ \\  / /   | |\n"
                   "| |   \\ \\ / /    | || |      | |     | || |  | |         | || |     | |      | || |  | |    | |  | || |   |  __ /    | || |    \\ \\/ /    | |\n"
                   "| |    \\ ' /     | || |     _| |_    | || |  \\ `.___.'\\  | || |    _| |_     | || |  \\  `--'  /  | || |  _| |  \\ \\_  | || |    _|  |_    | |\n"
                   "| |     \\_/      | || |    |_____|   | || |   `._____.'  | || |   |_____|    | || |   `.____.'   | || | |____| |___| | || |   |______|   | |\n"
                   "| |              | || |              | || |              | || |              | || |              | || |              | || |              | |\n"
                   "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n"
                   " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n");
            system("pause");
        }

    }while(GameOver==0);
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
                    shoot();
                } else {
                    printf("ce n'est pas un choix !\n");
                    break;
                }
                break;


            case 2:
                printf("\n\nInstructions\n");
                printf("\n\nIl y a 3 bateaux dans cette grille un petit, un moyen et un grand.\n\n Vous devez les couler a tout prix.\n Pour lancer les bonbes qui couleront les bateaux il vous suffit de rentrer des cordonnés verticales et horizontales de la grille.\n\n coulez tous les bateaux et vous serez vicorieux");
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
