#include<iostream>
#include<String>
#include<conio.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
const int length=14;
int Row[length];
int Player1=1;
int Player2=2;
int Player=1;
int pp=1;
void Initialize_board()
{
    for(int i=0; i<14; i++)
    {
        if(i==0 || i==7)
        {
            Row[i]=0;
        }
        
        else
        {
            Row[i]=4;
        }
    }
}
void Header()
{
                                cout<<"                             $$\\      $$\\                      $$$$$$\\            $$\\           "<<endl;
                                cout<<"                             $$$\\    $$$ |                    $$  __$$\\           $$ |          "<<endl;
                                cout<<"                             $$$$\\  $$$$ | $$$$$$\\  $$$$$$$\\  $$ /  \\__| $$$$$$\\  $$ | $$$$$$\\  "<<endl;
                                cout<<"                             $$\\$$\\$$ $$ | \\____$$\\ $$  __$$\\ $$ |       \\____$$\\ $$ | \\____$$\\ "<<endl;
                                cout<<"                             $$ \\$$$  $$ | $$$$$$$ |$$ |  $$ |$$ |       $$$$$$$ |$$ | $$$$$$$ |"<<endl;
                                cout<<"                             $$ |\\$  /$$ |$$  __$$ |$$ |  $$ |$$ |  $$\\ $$  __$$ |$$ |$$  __$$ |"<<endl;
                                cout<<"                             $$ | \\_/ $$ |\\$$$$$$$ |$$ |  $$ |\\$$$$$$  |\\$$$$$$$ |$$ |\\$$$$$$$ |"<<endl;
                                cout<<"                             \\__|     \\__| \\_______|\\__|  \\__| \\______/  \\_______|\\__| \\_______|"<<endl;
                                cout<<"                                                                                                "<<endl;
                                cout<<"                                                                                                "<<endl;
                                cout<<"                                                                                                "<<endl;
                                cout<<"                                           $$$$$$\\                                              "<<endl;
                                cout<<"                                          $$  __$$\\                                             "<<endl;
                                cout<<"                                          $$ /  \\__| $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\            "<<endl;
                                cout<<"                                          $$ |$$$$\\  \\____$$\\ $$  _$$  _$$\\ $$  __$$\\           "<<endl;
                                cout<<"                                          $$ |\\_$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |          "<<endl;
                                cout<<"                                          $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|          "<<endl;
                                cout<<"                                          \\$$$$$$  |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$\\           "<<endl;
                                cout<<"                                           \\______/  \\_______|\\__| \\__| \\__| \\_______|          "<<endl;
}
void Display_Board()
{   
    system("cls");   
    Header();
    cout<<"         __________________Player1's Side___________            "<<endl<<endl;
    cout<<"               Pit_1 Pit_2 Pit_3 Pit_4 Pit_5 Pit_6              "<<endl;
    cout<<"         ----------------------------------------------         "<<endl;
    cout<<"         |    |     |     |     |     |     |     |    |        "<<endl;
    cout<<"         |    |     |     |     |     |     |     |    |        "<<endl;
    cout<<"         |    |     |     |     |     |     |     |    |        "<<endl;
    cout<<" Player1 |    |     |     |     |     |     |     |    | Player2"<<endl;
    cout<<"  Count  |    |-----------------------------------|    |  Count "<<endl;
    cout<<"         |    |     |     |     |     |     |     |    |        "<<endl;
    cout<<"         |    |     |     |     |     |     |     |    |        "<<endl;
    cout<<"         |    |     |     |     |     |     |     |    |        "<<endl;
    cout<<"         |    |     |     |     |     |     |     |    |        "<<endl;
    cout<<"         -----------------------------------------------        "<<endl;
    cout<<"               Pit_1 Pit_2 Pit_3 Pit_4 Pit_5 Pit_6              "<<endl<<endl;
    cout<<"         __________________Player2's Side___________            "<<endl;
 
    gotoxy(11, 8+19);
    cout<<Row[7];
    gotoxy(53, 8+19);
    cout<<Row[0];
    gotoxy(17, 5+19);
    cout<<Row[8];
    gotoxy(23, 5+19);
    cout<<Row[9];
    gotoxy(29, 5+19);
    cout<<Row[10];
    gotoxy(35, 5+19);
    cout<<Row[11];
    gotoxy(41, 5+19);
    cout<<Row[12];
    gotoxy(47, 5+19);
    cout<<Row[13];
    gotoxy(17, 10+19);
    cout<<Row[1];
    gotoxy(23, 10+19);
    cout<<Row[2];
    gotoxy(29, 10+19);
    cout<<Row[3];
    gotoxy(35, 10+19);
    cout<<Row[4];
    gotoxy(41, 10+19);
    cout<<Row[5];
    gotoxy(47, 10+19);
    cout<<Row[6];
}
int ReturnPit()
{
    pp=1;
    int PitNumber;
    gotoxy(5, 19+19);
    cout<<endl<<"Player "+to_string(Player)+"'s turn. Choose Pit number(0-5): ";
    cin>>PitNumber;
    return PitNumber;
}
bool Winner()
{
    if(Row[6]>Row[13] && (Row[1]==0 && Row[2]==0 && Row[3]==0 && Row[4]==0 && Row[5]==0 && Row[0]==0))
    {
        cout<<endl<<"Player 1 wins";
        return true;
    }
    else if(Row[13]>Row[6] && (Row[7]==0 && Row[8]==0 && Row[9]==0 && Row[10]==0 && Row[11]==0 && Row[12]==0))
    {
        cout<<endl<<"Player 2 wins";
        return true;
    }
    return false;    
}
void MovePit1(int PitNumber)
{
    int Seeds=0;
    if(Player==1 && pp==1)
    {
        PitNumber=PitNumber+8;
    }
    if(Player==2 && pp==1)
    {
        PitNumber=PitNumber+1;
    }
        Seeds=Row[PitNumber];

    Row[PitNumber]=0;
    if(PitNumber>7)
    {
        PitNumber--;
    }
    if(PitNumber<7)
    {
        PitNumber++;
    }
    while(Seeds>0)
    {
        if(Player==1 && PitNumber==0)
        {
                PitNumber=13;
                continue;
        }
        if(Player==2 && PitNumber==7)
        {
            PitNumber=6;
            continue;
        }
        Row[PitNumber]=Row[PitNumber]+1;
        Seeds--;
        
        if(Seeds!=0)
        {
        if(PitNumber==7 && Player==1)
        {
            PitNumber=1;
            PitNumber--;
        }
       
        if(PitNumber==6 && Player==1)
        {
            PitNumber=13;
            continue;
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
    }
    if(Row[PitNumber]==1 && Player==1 && (PitNumber!=7 || PitNumber!=0 ))
    {
        Player=2;
        return;
    }
    if(Row[PitNumber]==1 && Player==1 && (PitNumber!=7 || PitNumber!=0 ))
    {
        Player=2;
        return;
    }
    if(PitNumber==7)
    {

        Player=1;
        return;
    }
    if(Row[PitNumber]>1)
    {   
        pp=0;
        MovePit1(PitNumber);
    }
    else if(PitNumber==0)
    {
        Player=2;
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

    
    


int main()
{
    system("cls");
    Initialize_board();

    bool Check;
    int PitNumber=0;
       while (true) {
        Display_Board();
        Check = Winner();
        if (Check) {
            break;
        }

        PitNumber = ReturnPit();
        if(Player==1)
        {
        MovePit1(PitNumber);
        }
        else if(Player==2)
        {
            MovePit2(PitNumber);
        }
    }
    return 0;
    
}