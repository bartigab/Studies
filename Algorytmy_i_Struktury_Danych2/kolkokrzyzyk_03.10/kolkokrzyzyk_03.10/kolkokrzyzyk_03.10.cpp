#include<iostream>
using namespace std;


char tab[3][3] = {};
int row, col;

bool good_parameters(char tab[3][3], int row, int col)
{
    if (tab[row][col] == '\0' && row >= 0 && row <= 2 && col >= 0 && col <= 2)
        return true;
    else
        return false;
}

int is_win(char tab[3][3], int iteracje)
{
    int ocounter = 0;
    int xcounter = 0;
    int remis = 0;
    for (int i = 0; i < 3; i++)//win WIERSZY
    {
        ocounter = 0;
        xcounter = 0;
        for (int k = 0; k < 3; k++)
        {
            if (tab[i][0] == 'o')//pierwsze o,potem check czy reszta też o
            {
                if (tab[i][k] == 'o')
                    ocounter++;
                if (tab[i][k] == 'x')
                {
                    ocounter = 0;
                    break;
                }
            }

            if (tab[i][0] == 'x')//pierwsze x,potem check czy reszta też x
            {
                if (tab[i][k] == 'x')
                    xcounter++;
                if (tab[i][k] == 'o')
                {
                    xcounter = 0;
                    break;
                }
            }
        }
        if (ocounter == 3)
            return 1; //win kolka
        else if (xcounter == 3)
            return -1; //win krzyzyka
    }


    for (int k = 0; k < 3; k++)//win KOLUMN
    {
        ocounter = 0;
        xcounter = 0;
        for (int w = 0; w < 3; w++)
        {
            if (tab[0][k] == 'o')//pierwsze o,potem check czy reszta też o
            {
                if (tab[w][k] == 'o')
                    ocounter++;
                if (tab[w][k] == 'x')
                {
                    ocounter = 0;
                    break;
                }

            }

            if (tab[0][k] == 'x')//pierwsze x,potem check czy reszta też x
            {
                if (tab[w][k] == 'x')
                    xcounter++;
                if (tab[w][k] == 'o')
                {
                    xcounter = 0;
                    break;
                }

            }
        }
        if (ocounter == 3)
            return 1;
        else if (xcounter == 3)
            return -1;
    }

    ocounter = 0;
    xcounter = 0;
    int k = 0;

    for (int w = 2; w >= 0; w--)//win cross1
    {



        if (tab[2][0] == 'o')//pierwsze o,potem check czy reszta też o
        {
            if (tab[w][k] == 'o')
            {
                ocounter++;
                k++;
            }

            if (tab[w][k] == 'x')
            {
                ocounter = 0;
                break;
            }

        }

        if (tab[2][0] == 'x')//pierwsze x,potem check czy reszta też x
        {
            if (tab[w][k] == 'x')
            {
                xcounter++;
                k++;
            }

            if (tab[w][k] == 'o')
            {
                xcounter = 0;
                break;
            }

        }

        if (ocounter == 3)
            return 1;
        else if (xcounter == 3)
            return -1;
    }

    ocounter = 0;
    xcounter = 0;

    for (int i = 0; i < 3; i++)//win cross2
    {
        int k = i;


        if (tab[0][0] == 'o')//pierwsze o,potem check czy reszta też o
        {
            if (tab[i][k] == 'o')
                ocounter++;
            if (tab[i][k] == 'x')
            {
                ocounter = 0;
                break;
            }

        }

        if (tab[0][0] == 'x')//pierwsze x,potem check czy reszta też x
        {
            if (tab[i][k] == 'x')
                xcounter++;
            if (tab[i][k] == 'o')
            {
                xcounter = 0;
                break;
            }

        }
        if (ocounter == 3)
            return 1;
        else if (xcounter == 3)
            return -1;

    }


    if (iteracje == 9)
    {
        return remis;
    }

    return 100;//jeszcze nikt nie wygrał, ani zremisowal
}

int main() {

    for (int i = 0; i < 9; )
    {
        int wynik = 0;
        cin >> row >> col;

        if (i % 2 == 0)//User1 kolko
        {
            while (good_parameters(tab, row, col) == true)
            {
                tab[row][col] = 'o';
                i++;
            }
        }
        else//User2 krzyzyk
        {

            while (good_parameters(tab, row, col) == true)
            {
                tab[row][col] = 'x';
                i++;
            }

        }

        int iteracje = i;
        wynik = is_win(tab, iteracje);
        if (wynik != 100)
        {
            cout << wynik;
            return wynik;

        }

    }

}