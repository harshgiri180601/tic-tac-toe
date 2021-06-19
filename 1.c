#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

char square[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int check();
void drwaboard();

int main()
{
    int player = 1, i, choice;
    char mark; //X,O
    FILE *f = fopen("txt.file", "w");
    char u1[10], u2[10];
    printf("enter first player name: ");
    scanf("%s", &u1);
    fprintf(f, "%s\t", u1);
    printf("enter second player name: ");
    scanf("%s", &u2);
    fprintf(f, " %s\t", u2);
    do
    {
        drwaboard();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            printf("Invalid move ");

            player--; //decremented to givve another chance to current player
            getch();
        }
        i = check();

        player++;
    } while (i == -1);
    drwaboard();

    if (i == 1)

    {

        if (player == 2)
        {
            printf("\n\nPlayer1 %s Wins!\n\n", u1);
            fprintf(f, "\t%s", u1);
            getch();
        }
        else
        {
            printf("\n\nPlayer2 %s Wins!\n\n", u2);
            fprintf(f, "\t%s", u2);
            getch();
        }
    }
    else

        printf("-------------game draw-----------");
    getch();

    return 0;
}
int check()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

void drwaboard()
{
    printf("\n\n\t tic tac toe \n\n");
    printf("player1(X)---player2(O)\n\n");

    printf("%c   |   %C   |   %c      \n", square[1], square[2], square[3]);
    printf("____|_______|_____\n");

    printf("%c   |   %C   |   %c      \n", square[4], square[5], square[6]);
    printf("____|_______|_____\n");
    printf("%c   |   %C   |   %c     \n", square[7], square[8], square[9]);
}
