#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

#define N 9
struct square
{
    int isVisible=0;
    int real;
    int given;
};
void randBoard(int board[N][N])
{
    int t[18]={1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9};
    int rx,ry;
    for(int i=0;i<9;i++)
    {
        rerere:
        rx=rand()%9;
        ry=rand()%9;
        if(board[ry][rx]==0) board[ry][rx]=t[i];
        else goto rerere;
    }
}
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
bool isSafe(int board[N][N], int row,int col, int num)
{
    for (int x = 0; x <= 8; x++)
        if (board[row][x] == num)
            return false;
    for (int x = 0; x <= 8; x++)
        if (board[x][col] == num)
            return false;
    int sRow = row - row % 3, sCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + sRow][j +
                            sCol] == num)
                return false;

    return true;
}
bool solve(int board[N][N], int row, int col)
{
    if (row == N - 1 && col == N)
        return true;
    if (col == N) {
        row++;
        col = 0;
    }
    if (board[row][col] > 0)
        return solve(board, row, col + 1);

    for (int num = 1; num <= N; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;
            if (solve(board, row, col + 1)) return true;
        }
        board[row][col] = 0;
    }
    return false;
}
int main()
{
        srand(time(NULL));
        reStart:
        system("cls");
        time_t t_start, t_round, t_stop;
        int hints;
        int lives;
        int visible;
        string level;
        int diffic;
        cout<<"Wybierz poziom trudnosci"<<endl;
        cout<<"1. Easy "<<endl;
        cout<<"2. Medium "<<endl;
        cout<<"3. Hard "<<endl;
        cout<<"4. Very Hard "<<endl;
        cin>>diffic;
        switch(diffic)
        {
        case 1:
            {
                level="easy";
                lives=5;
                hints=3;
                visible=41;
                break;
            }
            case 2:
            {
                level="Medium";
                lives=5;
                hints=3;
                visible=32;
                break;
            }
            case 3:
            {
                level="Hard";
                lives=5;
                hints=3;
                visible=27;
                break;
            }
            case 4:
            {
                level="Very Hard";
                lives=3;
                hints=2;
                visible=20;
                break;
            }
            case 5:
            {
                level="Insane!";
                lives=1;
                hints=0;
                visible=(rand()%3)+17;
                break;
            }
            default:
            {
                 cout<<"Blad wyboru!"<<endl;
                 goto reStart;
            }
        }
        reStart2:
        int grid[N][N];
        for(int i=0;i<=8;i++)
        {
            for(int j=0;j<=8;j++)
            {
                grid[i][j]=0;
            }
        }

        newRoll:
        randBoard(grid);
        solve(grid,0,0);
        //print(board);


    int n=11;
    square board[11][11];
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            board[i][j].real=0;
        }
    }
    for(int i=0;i<=n-1;i++)
    {
        board[i][0].real=i-1;
        if(i>=2) board[i][0].isVisible=1;
        else
        {
            board[i][0].real=11;
            board[i][0].isVisible=0;

        }
    }
    for(int i=0;i<=n-1;i++)
    {
        board[0][i].real=i-1;
        if(i>=2) board[0][i].isVisible=1;
        else
        {
            board[0][i].real=11;
            board[0][i].isVisible=0;

        }
    }
    for(int i=0;i<=n-1;i++)
    {
            board[i][1].real=11;
            board[i][1].isVisible=0;
    }
    for(int i=0;i<=n-1;i++)
    {
            board[1][i].real=11;
            board[1][i].isVisible=0;
    }
    for(int i=0;i<=8;i++)
    {
        for(int j=0;j<=8;j++)
        {
            board[i+2][j+2].real=grid[i][j];
        }
    }
    int vx,vy; //visible since begining;
    int okkk=1;
    for(int i=0;i<=visible-1;i++)
    {
        do{
            vx=(rand()%9)+2;
            vy=(rand()%9)+2;
            if(board[vy][vx].isVisible==1) okkk=0;
            else
            {
                board[vy][vx].isVisible=1;
                okkk=1;
            }
        }while(okkk!=1);
    }
    time(&t_start);
    do{
        baack:
        system("cls");
        //PRINT
        for(int i=0;i<=n-1;i++)
        {
            for(int j=0;j<=n-1;j++)
            {
                if(board[i][j].isVisible==0)
                {
                    if (i==0 && j==1 && board[i][j].real==11) printf("%c ",32);
                    else if(board[i][j].real==11) printf("%c",32);
                    else printf("%c ",177);
                    if(j==4 || j==7) printf(" ");
                }
                if(board[i][j].isVisible==1)
                {
                    printf("%d ",board[i][j].real);
                    if(j==4 || j==7) printf(" ");
                }
            }
            if(i==0) cout<<'\t'<<'\t'<<"level: "<<level;
            if(i==2) cout<<'\t'<<'\t'<<"lives: "<<lives;
            if(i==3) cout<<'\t'<<'\t'<<"Hints: "<<hints;
            if(i==5)
            {
                time(&t_round);
                double diff_t;
                diff_t=difftime(t_round, t_start);
                cout<<'\t'<<'\t'<<"Time: "<<diff_t<<" sec";
            }
            if(i==6) cout<<'\t'<<'\t'<<"(Po ostatnim ruchu)";
            cout<<endl;
            if(i==4 || i==7) cout<<endl;
        }
       // cout<<"lives: "<<lives<<endl;
       // cout<<"hints: "<<hints<<endl;
        int ok=1;
        int choice;
        int gx,gy;//give x and y
        cout<<"1. Wpisz "<<endl;
        if(hints>0) cout<<"2. Podpowiedz "<<endl;
        cout<<"Wybor: ";
        do{
            cin>>choice;
            if(hints>0)
            {
                if(choice <1 || choice >2)
                {
                    cout<<"Wybierz poprawna opcje: "<<endl;
                    ok=0;
                }
                else ok=1;
            }
            else if(hints<=0)
            {
                if(choice !=1)
                {
                    cout<<"Wybierz poprawna opcje: "<<endl;
                    ok=0;
                }
                else ok=1;
            }
            //else ok=1;
        }while(ok!=1);
        ok=1;
        cout<<"wybierz pole [x/y]: "<<endl;
        do{
            cin>>gx;
            cin>>gy;
            if(gx==211120 && gy==211120) //pokaz wszystkie
            {
                for(int i=2;i<=10;i++)
                {
                    for(int j=2;j<=10;j++)
                    {
                        board[i][j].isVisible=1;
                    }
                }
                goto baack;
            }
            else if(gx==10601 && gy==10601) //ukryj wszyskie
            {
                for(int i=2;i<=10;i++)
                {
                    for(int j=2;j<=10;j++)
                    {
                        board[i][j].isVisible=0;
                    }
                }
                goto baack;
            }
            else if(gx==10121 && gy==10121) //wygeneruj nowe
            {
                goto reStart2;
            }
            else if(gx==220801 && gy==220801)
            {
                int abc,rx,ry,okk=1;
                cin>>abc;
                for(int i=0;i<=abc-1;i++)
                {
                    do{
                        rx=(rand()%9)+2;
                        ry=(rand()%9)+2;
                        if(board[ry][rx].isVisible==1) okk=0;
                        else
                        {
                            board[ry][rx].isVisible=1;
                            okk=1;
                        }
                    }while(okk!=1);
                }
                goto baack;
            }
            else if(gx==2137 && gy == 2137)
            {
                lives=999;
                hints=999;
                goto baack;
            }
            else if(gx<1 || gx>9 || gy<1 || gy>9)
            {
                cout<<"Pole poza plansza!"<<endl;
                cout<<"wybierz inne pole [x,y]: "<<endl;
                ok=0;
            }
            else if(board[gy+1][gx+1].isVisible==1)
            {
                cout<<"Pole juz uzupelnione!"<<endl;
                cout<<"wybierz inne pole [x,y]: "<<endl;
                ok=0;
            }
        }while(ok!=1);
        gx+=1;
        gy+=1;
        switch(choice)
        {
            case 1:
                {
                    int given;
                    cout<<"Wpisz liczbe: "<<endl;
                    cin>>given;
                    board[gy][gx].given=given;
                    if(board[gy][gx].real==given)
                    {
                        board[gy][gx].isVisible=1;
                        int isWin=0;
                        for(int i=2;i<=10;i++)
                        {
                            for(int j=2;j<=10;j++)
                            {
                                if(board[i][j].isVisible==1) isWin++;
                            }
                        }
                        if(isWin==81) goto endWin;
                    }
                    else
                    {
                        board[gy][gx].isVisible=0;
                        cout<<"Blad!"<<endl;
                        Sleep(1000);
                        lives-=1;
                        if (lives==0)
                        {
                            goto endLose;
                        }
                    }
                    break;
                }
            case 2:
                {
                    board[gy][gx].isVisible=1;
                    hints-=1;
                    break;
                }
        }


    }while(1);
    int repeat;
    while(0)
    {
        endLose:
        system("cls");
        time(&t_stop);
        double endTime;
        endTime=difftime(t_stop,t_start);
        cout<<"Przegrales :C "<<endl;
        cout<<"Gra trwala "<<endTime<<" sekund"<<endl;
        cout<<"Chcesz zagrac jeszcze raz? "<<endl;
        cout<<"1. Tak :D"<<endl;
        cout<<"2. Nie D:"<<endl;
        cin>>repeat;
        if(repeat==1) goto reStart;
        else goto endGame;
    }
    while(0)
    {
        endWin:
        system("cls");
        time(&t_stop);
        double endTime;
        endTime=difftime(t_stop,t_start);
        cout<<"Gra trwala "<<endTime<<" sekund"<<endl;
        cout<<"Wygrales!!! :D "<<endl;
        cout<<"Chcesz zagrac jeszcze raz? "<<endl;
        cout<<"1. Tak :D"<<endl;
        cout<<"2. Nie D:"<<endl;
        cin>>repeat;
        if(repeat==1) goto reStart;
        else goto endGame;
    }
    endGame:
    return 0;
}
