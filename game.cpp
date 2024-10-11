#include<iostream>
#include<String>
using namespace std;


const int length=14;
int Row[length];
int Player1=1;
int Player2=2;
int Player=1;
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
void Display_Borad()
{
    for(int i=0; i<14; i++)
    {
        cout<<Row[i];
        cout<<"  ";
        if(i==0 || i==6 || i==7)
        {
            cout<<"\n";
        }
    }
}
int ReturnPit()
{
    int PitNumber;
    cout<<endl<<"Player"+to_string(Player)+"'s turn. Choose Pit number";
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
bool MovePit(int PitNumber)
{
    int Seeds=0;
    if(Player==1)
    {
        PitNumber=PitNumber+8;
    }
    Seeds=Row[PitNumber];

    Row[PitNumber]=0;
    PitNumber--;
    while(Seeds!=0)
    {
        if(PitNumber==0 && Player==1)
        {
            PitNumber=13;
            continue;
        }
        else if(PitNumber==7 && Player==2)
        {
            continue;
        }
        
        Row[PitNumber]=Row[PitNumber-1]+1;
        PitNumber--;
        Seeds--;
        if(PitNumber==0 && Player==2)
        {
            PitNumber=13;
        }
        
    }
    if(PitNumber==7)
    {
        Player=1;
        return true;
    }
    if(PitNumber==0)
    {
        Player=2;
        return true;
    }
    if(Row[PitNumber]>1)
    {
        MovePit(PitNumber);
        return true;
        
    }
    if(Row[PitNumber]==1 && Player==1)
    {
        Player=2;
        return true; 
    }
    if(Row[PitNumber]==1 && Player==2)
    {
        Player=1;
        return true; 
    }


    return true;
}

int main()
{

    bool Check;
    int PitNumber=0;
        Initialize_board();
        while(true)
        {
        Display_Borad();
        Check=Winner();
        if(Check==true)
        {break;
        }
        PitNumber=ReturnPit();
        MovePit(PitNumber);

        }
}