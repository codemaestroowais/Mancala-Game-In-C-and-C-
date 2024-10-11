#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

#define length 14

int Row[length];
int Player1 = 1;
int Player2 = 2;
int Player = 1;
int pp = 1;

void Initialize_board() {
    for (int i = 0; i < length; i++) {
        if (i == 0 || i == 7) {
            Row[i] = 0;
        } else {
            Row[i] = 4;
        }
    }
}

void Header() {
    printf("                             $$\\      $$\\                      $$$$$$\\            $$\\\n");
    printf("                             $$$\\    $$$ |                    $$  __$$\\           $$ |\n");
    printf("                             $$$$\\  $$$$ | $$$$$$\\  $$$$$$$\\  $$ /  \\__| $$$$$$\\  $$ | $$$$$$\\\n");
    printf("                             $$\\$$\\$$ $$ | \\____$$\\ $$  __$$\\ $$ |       \\____$$\\ $$ | \\____$$\\\n");
    printf("                             $$ \\$$$  $$ | $$$$$$$ |$$ |  $$ |$$ |       $$$$$$$ |$$ | $$$$$$$ |\n");
    printf("                             $$ |\\$  /$$ |$$  __$$ |$$ |  $$ |$$ |  $$\\ $$  __$$ |$$ |$$  __$$ |\n");
    printf("                             $$ | \\_/ $$ |\\$$$$$$$ |$$ |  $$ |\\$$$$$$  |\\$$$$$$$ |$$ |\\$$$$$$$ |\n");
    printf("                             \\__|     \\__| \\_______|\\__|  \\__| \\______/  \\_______|\\__| \\_______|\n");
    printf("\n\n\n\n");
    printf("                                           $$$$$$\\\n");
    printf("                                          $$  __$$\\\n");
    printf("                                          $$ /  \\__| $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\\n");
    printf("                                          $$ |$$$$\\  \\____$$\\ $$  _$$  _$$\\ $$  __$$\\\n");
    printf("                                          $$ |\\_$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |\n");
    printf("                                          $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|\n");
    printf("                                          \\$$$$$$  |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$\\\n");
    printf("                                           \\______/  \\_______|\\__| \\__| \\__| \\_______|\n");
}

void Display_Board() {
    system("cls");
    Header();
    printf("         __________________Player1's Side___________            \n\n");
    printf("               Pit_1 Pit_2 Pit_3 Pit_4 Pit_5 Pit_6              \n");
    printf("         ----------------------------------------------         \n");
    printf("         |    |     |     |     |     |     |     |    |        \n");
    printf("         |    |     |     |     |     |     |     |    |        \n");
    printf("         |    |     |     |     |     |     |     |    |        \n");
    printf(" Player1 |    |     |     |     |     |     |     |    | Player2\n");
    printf("  Count  |    |-----------------------------------|    |  Count \n");
    printf("         |    |     |     |     |     |     |     |    |        \n");
    printf("         |    |     |     |     |     |     |     |    |        \n");
    printf("         |    |     |     |     |     |     |     |    |        \n");
    printf("         |    |     |     |     |     |     |     |    |        \n");
    printf("         -----------------------------------------------        \n");
    printf("               Pit_1 Pit_2 Pit_3 Pit_4 Pit_5 Pit_6              \n\n");
    printf("         __________________Player2's Side___________            \n");

    gotoxy(11, 8+19);
    printf("%d", Row[7]);
    gotoxy(53, 8+19);
    printf("%d", Row[0]);
    gotoxy(17, 5+19);
    printf("%d", Row[8]);
    gotoxy(23, 5+19);
    printf("%d", Row[9]);
    gotoxy(29, 5+19);
    printf("%d", Row[10]);
    gotoxy(35, 5+19);
    printf("%d", Row[11]);
    gotoxy(41, 5+19);
    printf("%d", Row[12]);
    gotoxy(47, 5+19);
    printf("%d", Row[13]);
    gotoxy(17, 10+19);
    printf("%d", Row[1]);
    gotoxy(23, 10+19);
    printf("%d", Row[2]);
    gotoxy(29, 10+19);
    printf("%d", Row[3]);
    gotoxy(35, 10+19);
    printf("%d", Row[4]);
    gotoxy(41, 10+19);
    printf("%d", Row[5]);
    gotoxy(47, 10+19);
    printf("%d", Row[6]);
}

int ReturnPit() {
    pp = 1;
    int PitNumber;
    gotoxy(5, 19+19);
    printf("\nPlayer %d's turn. Choose Pit number(0-5): ", Player);
    scanf("%d", &PitNumber);
    return PitNumber;
}

int Winner() {
    if (Row[6] > Row[13] && (Row[1] == 0 && Row[2] == 0 && Row[3] == 0 && Row[4] == 0 && Row[5] == 0 && Row[0] == 0)) {
        printf("\nPlayer 1 wins");
        return 1;
    } else if (Row[13] > Row[6] && (Row[7] == 0 && Row[8] == 0 && Row[9] == 0 && Row[10] == 0 && Row[11] == 0 && Row[12] == 0)) {
        printf("\nPlayer 2 wins");
        return 1;
    }
    return 0;
}

void MovePit1(int PitNumber) {
    int Seeds = 0;
    if (Player == 1 && pp == 1) {
        PitNumber = PitNumber + 8;
    }
    if (Player == 2 && pp == 1) {
        PitNumber = PitNumber + 1;
    }
    Seeds = Row[PitNumber];
    Row[PitNumber] = 0;
    if (PitNumber > 7) {
        PitNumber--;
    }
    if (PitNumber < 7) {
        PitNumber++;
    }
    while (Seeds > 0) {
        if (Player == 1 && PitNumber == 0) {
            PitNumber = 13;
            continue;
        }
        if (Player == 2 && PitNumber == 7) {
            PitNumber = 6;
            continue;
        }
        Row[PitNumber] = Row[PitNumber] + 1;
        Seeds--;
        if (Seeds != 0) {
            if (PitNumber == 7 && Player == 1) {
                PitNumber = 1;
                PitNumber--;
            }
            if (PitNumber == 6 && Player == 1) {
                PitNumber = 13;
                continue;
            }
            if (PitNumber > 7) {
                PitNumber--;
            }
            if (PitNumber < 7) {
                PitNumber++;
            }
        }
    }
    if (Row[PitNumber] == 1 && Player == 1 && (PitNumber != 7 || PitNumber != 0 )) {
        Player = 2;
        return;
    }
    if (Row[PitNumber] == 1 && Player == 1 && (PitNumber != 7 || PitNumber != 0 )) {
        Player = 2;
        return;
    }
    if (PitNumber == 7) {
        Player = 1;
        return;
    }
    if (Row[PitNumber] > 1) {
        pp = 0;
        MovePit1(PitNumber);
    } else if (PitNumber == 0) {
        Player = 2;
    }
    return;
}

void MovePit2(int PitNumber)
{
    int Seeds=0;
    if(Player==2 &&pp==1)
    {
        PitNumber=PitNumber+1;
    }
    Seeds=Row[PitNumber];
    Row[PitNumber]=0;
    if(Player==2 && pp==1)
    {
        PitNumber++;
    }
    else if(PitNumber>7)
    {
        PitNumber--;
    }
    else if(PitNumber<7)
    {
        PitNumber++;
    }
    while(Seeds!=0)
    {
        if(PitNumber==7 )
        {
            PitNumber=1;
            continue;
        }
        Row[PitNumber]=Row[PitNumber]+1;
        Seeds--;
        if(PitNumber==6)
        {
            PitNumber=0;
            continue;
        }
        if(PitNumber==0)
        {
            PitNumber=13;
            continue;
        }
        if(Seeds==0)
        {
            break;
        }
        if(PitNumber>7)
        {
            PitNumber--;
        }
        if(PitNumber<7)
        {
            PitNumber++;
        }
    }


    if(Row[PitNumber]>1)
    {
       
         pp=0;
        MovePit2(PitNumber);
    }
    if(Row[PitNumber]==1 && Player==2 && (PitNumber!=7 || PitNumber!=0 ))
    {
        Player=1;
        return;
    }
    if(PitNumber==0)
    {
        Player=2;
        return;
    }

}

int main() {
    Initialize_board();

    int Check;
    int PitNumber = 0;
    while (1) {
            Display_Board(); // Display the board before each turn
        Check = Winner();
        if (Check) {
            break;
        }

        PitNumber = ReturnPit();
        if (Player == 1) {
            MovePit1(PitNumber);
        } else if (Player == 2) {
            MovePit2(PitNumber);
        }
    }
    return 0;
}
