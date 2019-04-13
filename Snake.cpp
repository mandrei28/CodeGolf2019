#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <bitset>
#include <vector>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

unsigned char o[400][2]; //pozitie obstacole
unsigned char p[400][2]; //pozitie puncte
unsigned char no;        //numar obstacole
unsigned char np;       //numar puncte

unsigned long s;        //variabila ajutatoare

void f(char d) {
    static int l, r, i, j, n, m, t, b, A = 22, X[99], Y[99];
    static char M[23][23];

    if(!s)
    {
        s = X[0] = Y[0] = 1;
        i = b = t = l = r = 0;

        for (; i < A; i++)
            for (j = 0; j < A; j++)
                M[i][j] = j && j != 21 ? i != 21 && i ? 46 : 45 : '|';

    for (i = 0; i < max(no,np);)
        M[p[i][0]][p[i][1]] = 42,
        M[o[i][0]][o[i++][1]] = 35;

    M[0][0] = M[0][21] = M[21][0] = M[21][21] = 32;
    }


    n = X[r] - (!d) + (d==2);
    m = Y[r] + (d==1) - (d==3);

    for(i = l ; i < r; i++)
        if(X[i] == n && Y[i] == m)
            t = 1;
    if (n > 20 || !n || m > 20 || !m || M[n][m] == 35 )
            t = 1;
    if(!t)
        M[n][m] == 42 ? b++ : M[X[l]][Y[l++]] = 46,
        X[++r] = n,
        Y[r] = m;


    for (i = l; i <= r;)
            M[X[i]][Y[i++]] = 64;
    for (i = 0; i < A; i++){
        for (j = 0; j < A;)
            cout << M[i][j++];
        cout << '\n';
   }
   string a = " Ai strans: " + to_string(b) + " puncte.\n";
    if (b == np)
        cout << "Ai castigat!"<<a, t = 1;
    else
        if(t)
            cout << "Ai pierdut!"<<a;
}


int main(int argc, char **argv) {
    np = 36;
    no = 6;
    p[0][0]=1;p[0][1]=3;
    p[1][0]=1;p[1][1]=4;
    p[2][0]=1;p[2][1]=5;
    p[3][0]=1;p[3][1]=6;
    p[4][0]=1;p[4][1]=8;
    p[5][0]=1;p[5][1]=12;
    p[6][0]=1;p[6][1]=15;
    p[7][0]=2;p[7][1]=6;
    p[8][0]=2;p[8][1]=8;
    p[9][0]=2;p[9][1]=9;
    p[10][0]=3;p[10][1]=10;
    p[11][0]=4;p[11][1]=17;
    p[12][0]=5;p[12][1]=2;
    p[13][0]=5;p[13][1]=15;
    p[14][0]=6;p[14][1]=9;
    p[15][0]=7;p[15][1]=10;
    p[16][0]=7;p[16][1]=3;
    p[17][0]=8;p[17][1]=6;
    p[18][0]=8;p[18][1]=19;
    p[19][0]=9;p[19][1]=8;
    p[20][0]=9;p[20][1]=18;
    p[21][0]=9;p[21][1]=10;
    p[22][0]=11;p[22][1]=6;
    p[23][0]=12;p[23][1]=10;
    p[24][0]=15;p[24][1]=9;
    p[25][0]=15;p[25][1]=18;
    p[26][0]=16;p[26][1]=15;
    p[27][0]=17;p[27][1]=20;
    p[28][0]=18;p[28][1]=6;
    p[29][0]=19;p[29][1]=10;
    p[30][0]=19;p[30][1]=17;
    p[31][0]=20;p[31][1]=15;
    p[32][0]=20;p[32][1]=20;
    p[33][0]=20;p[33][1]=6;
    p[34][0]=20;p[34][1]=10;
    p[35][0]=20;p[35][1]=17;


    o[0][0]=1;o[0][1]=7;
    o[1][0]=2;o[1][1]=1;
    o[2][0]=3;o[2][1]=5;
    o[3][0]=3;o[3][1]=6;
    o[4][0]=4;o[4][1]=6;
    o[5][0]=5;o[5][1]=6;

    int c = 0;
    while(1)
    {
        c = 0;

        switch((c=getch())) {
        case KEY_UP:
            f(0);
            break;
        case KEY_DOWN:
            f(2);
            break;
        case KEY_LEFT:
            f(3);
            break;
        case KEY_RIGHT:
            f(1);
            break;
        case 'l':
            s = 0;
        default:
            break;
        }

    }


    return 0;

}
