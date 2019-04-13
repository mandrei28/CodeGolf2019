#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <sstream>

using namespace std;

unsigned char n;            // nr linii tabla
unsigned char m;            // nr coloane tabla
unsigned char t[256][256];  // tabla

unsigned long s;    // variabila ajutatoare

void f(unsigned char c, unsigned char b)
{
    struct P{
    int x,y;
    }x;

    int i,j,k,X,Y;
    static char T[256][256], z;
    list<P> B, C;

    if(!s)
    {
        s = 1;
        z = k = 0;
        for(i = n-1; i > -1 ; i--)
        {
            for(j = 0 ; j < m; j++)
                T[k][j+1] = t[i][j],
                T[n][j] = '_';
            k++;
            T[i][0] = T[i][m+1] = '|';
        }
        T[k][m+1] = T[k][0] = '|';
        T[k][m] = '_';
    }
    if(!z)
    {
        B.clear();
        C.clear();
        for(i = n; i > -1 ; i--)
            if(T[i-1][c+1] != '.' || !i)
            {
                if(i == n)
                    z = 1;
                B.push_back({i,c+1});
                break;
            }
        while(!B.empty())
        {
            x = B.back();
            X=x.x;
            Y=x.y;
            T[X][Y] = '.';
            C.push_back(x);
            if(X == n)
                break;
            B.pop_back();
            if(T[X-1][Y] == b)
                B.push_back({X-1, Y});
            if(T[X][Y-1] == b && Y - 1 )
                B.push_back({X, Y-1});
            if(T[X][Y+1] == b && Y + 1 != m+1)
                B.push_back({X, Y+1});
            if(T[X+1][Y] == b)
                B.push_back({X+1, Y});
        }
        for(auto it: C)
        {
            X = it.x;
            Y = it.y;
            if(C.size() > 2)
                for(i = X ; i < n ;)
                    T[i++][Y] = '.';
            else
                T[X][Y] = b;
        }
        for(i = n ; i > 0 && !z ; i--)
            for(j = 1 ; j < m+1; j++)
                if(T[i-1][j] != '.')
                    T[i][j] = T[i-1][j],
                    T[i-1][j] = '.';
    }
    for(i = 0 ; i <= n ; i++)
    {
        for(j = 0 ; j <= m+1;)
            cout<<T[i][j++];
        cout<<endl;
    }
    z = 2;
    for(i = 0 ; i < n; i++)
        for(j = 1 ; j < m+1; j++)
        {
            if(T[i][j] != '.' && z == 2)
                z = 0;
            if(T[n][j] != '_')
                z = 1;
        }
    if(z == 2)
        cout<<"Ai castigat!\n";
    else
        if(z)
            cout<<"Ai pierdut!\n";
}

int main(int argc, const char* argv[])
{
    /*n = 10;
    m = 10;
    t[0][0] = '.';
    t[0][1] = '.';
    t[0][2] = '.';
    t[0][3] = '.';
    t[0][4] = '.';
    t[0][5] = '.';
    t[0][6] = '.';
    t[0][7] = '.';
    t[0][8] = '.';
    t[0][9] = '.';
    t[1][0] = '.';
    t[1][1] = '.';
    t[1][2] = '.';
    t[1][3] = '.';
    t[1][4] = '.';
    t[1][5] = '.';
    t[1][6] = '.';
    t[1][7] = '.';
    t[1][8] = '.';
    t[1][9] = '.';
    t[2][0] = '.';
    t[2][1] = '.';
    t[2][2] = '.';
    t[2][3] = '.';
    t[2][4] = '.';
    t[2][5] = '.';
    t[2][6] = '.';
    t[2][7] = '.';
    t[2][8] = '.';
    t[2][9] = '.';
    t[3][0] = '.';
    t[3][1] = '.';
    t[3][2] = '.';
    t[3][3] = '.';
    t[3][4] = '.';
    t[3][5] = '.';
    t[3][6] = '.';
    t[3][7] = '.';
    t[3][8] = '.';
    t[3][9] = '.';
    t[4][0] = '.';
    t[4][1] = '.';
    t[4][2] = '.';
    t[4][3] = '.';
    t[4][4] = '.';
    t[4][5] = '.';
    t[4][6] = '.';
    t[4][7] = '.';
    t[4][8] = '.';
    t[4][9] = '.';
    t[5][0] = '.';
    t[5][1] = '.';
    t[5][2] = '.';
    t[5][3] = '.';
    t[5][4] = '.';
    t[5][5] = '.';
    t[5][6] = '.';
    t[5][7] = '.';
    t[5][8] = '.';
    t[5][9] = '.';
    t[6][0] = '#';
    t[6][1] = '.';
    t[6][2] = '.';
    t[6][3] = '#';
    t[6][4] = '*';
    t[6][5] = '.';
    t[6][6] = '.';
    t[6][7] = '.';
    t[6][8] = '.';
    t[6][9] = '%';
    t[7][0] = '#';
    t[7][1] = '*';
    t[7][2] = '*';
    t[7][3] = '#';
    t[7][4] = '*';
    t[7][5] = '*';
    t[7][6] = '#';
    t[7][7] = '*';
    t[7][8] = '*';
    t[7][9] = '%';
    t[8][0] = '#';
    t[8][1] = '*';
    t[8][2] = '*';
    t[8][3] = '#';
    t[8][4] = '*';
    t[8][5] = '*';
    t[8][6] = '#';
    t[8][7] = '*';
    t[8][8] = '*';
    t[8][9] = '%';
    t[9][0] = '#';
    t[9][1] = '#';
    t[9][2] = '#';
    t[9][3] = '#';
    t[9][4] = '#';
    t[9][5] = '#';
    t[9][6] = '#';
    t[9][7] = '#';
    t[9][8] = '#';
    t[9][9] = '#';
    f(5, '*');
    f(4, '@');
    f(5, '@');
    f(1, '#');
    f(3, '#');*/
   /* n = 3;
    m = 11;
    t[0][0] = '=';
    t[0][1] = '=';
    t[0][2] = '=';
    t[0][3] = '=';
    t[0][4] = '=';
    t[0][5] = '.';
    t[0][6] = '=';
    t[0][7] = '=';
    t[0][8] = '=';
    t[0][9] = '=';
    t[0][10] = '=';
    t[1][0] = '.';
    t[1][1] = '.';
    t[1][2] = '.';
    t[1][3] = '.';
    t[1][4] = '.';
    t[1][5] = '.';
    t[1][6] = '.';
    t[1][7] = '.';
    t[1][8] = '.';
    t[1][9] = '.';
    t[1][10] = '.';
    t[2][0] = '.';
    t[2][1] = '.';
    t[2][2] = '.';
    t[2][3] = '.';
    t[2][4] = '.';
    t[2][5] = '.';
    t[2][6] = '.';
    t[2][7] = '.';
    t[2][8] = '.';
    t[2][9] = '.';
    t[2][10] = '.';
    f(0, '*');
    f(1, '=');
    f(2, '=');*/
    string inputFile = "C:\\Users\\marcu\\Desktop\\input.txt";

    ifstream in(inputFile.c_str(), ios::in);
    std::streambuf *cinbuf = std::cin.rdbuf();      //save stdin buffer
    std::cin.rdbuf(in.rdbuf());                     //redirect std::cin to input file (.in)
    if (!in.is_open())
    {
        cout << "Cannot open input file";
        return 1;
    }

    while (!in.eof())
    {
        // joc nou
        s = 0;

        string line;
        getline(in, line);
        std::istringstream snm(line);
        int sn, sm;
        snm >> sn >> sm;
        n = sn;
        m = sm;
        char c[255];
        for (int i = n-1; i >= 0; --i)
        {
            getline(in, line);
            std::istringstream stl(line);
            for (int j = 0; j < m; j++)
            {
                stl >> c;
                c[m]=0;
                t[i][j] = c[j];
            }
        }

        getline(in, line);
        int nt = atoi(line.c_str());

        for (int i = 0; i < nt; i++)
        {
            int col;
            unsigned char c, b;

            getline(in, line);
            std::istringstream st(line);
            st >> col >> b;
            c = col;

            f(c, b);
        }
    }
}
