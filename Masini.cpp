#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
#include <vector>
#include <list>

using namespace std;

void f(unsigned char n, unsigned char p[][5], unsigned char t)
{
    int d=600, e, g, h, i, j, k, l, s, u, v = 0, x, y, z = 0, A[] = {1, 1, -1 , -1}, q = 43;
    struct{
    int X,Y,L,M,D;
    }w[d];
    char m[d][d];
    for(i = 0 ; i < n ;)
    {
        w[i].Y = y = p[i][0];
        w[i].X = x = p[i][1];
        h = p[i][2];
        g = p[i++][3];
        e = x + g - 1;
        k = y + h - 1;
        v = max(e,v);
        z = max(z,k);
        m[x][y] = m[e][y] = m[x][k] = m[e][k] = 46;
        for ( j = y + 1 ; j < k ; j++)
            m[x][j] = m[x][j] != '|' ? 45 : q,
            m[e][j] = m[e][j] != '|' ? 45 : q ;

        for ( j = x + 1 ; j < e; j++)
            m[j][y] = m[j][y] != 45 ? '|' : q,
            m[j][k] = m[j][k] != 45 ? '|' : q ;
    }
    while( t-- )
        for( i = 0 ; i < n ; i++)
        {
            s = p[i][4];
            e = w[i].D % 4;
            k = A[e];
            h = w[i].L = x = w[i].X;
            g = w[i].M = y = w[i].Y;

            s ?
                e & 1 ? y += k : x += k :
                    e & 1 ? x += k : y += k ;

            w[i].X = x;
            w[i].Y = y;

            if(m[x][y] == 46)
                    w[i].D ++;

            for(j = 0 ; m[x][y] == q && j < i;)
            {
                u = w[j].X;
                l = w[j].Y;
                s = w[j].L;
                e = w[j].M;

                if(x + y == u + l)
                    (l + 1 == g || y + 1 == e) ?
                    s < h ? (x = h, y = g ) : (u = s, l = e) :
                    s < h ? (u = s, l = e ) : (x = h, y = g);

                w[i].X = x;
                w[i].Y = y;
                w[j].X = u;
                w[j++].Y = l;
            }
        }
    for(i = 0 ; i < n ;)
        m[w[i].X][w[i++].Y] = 88;
    for(i = 0 ; i <= v; i++)
    {
        for(j = 0 ; j <= z ;j++)
            cout << (m[i][j] ? m[i][j] : ' ');
        cout<<endl;
    }
}

int main(int argc, char **argv)
{
    vector<char> m[600];
    unsigned char n = 2;
    unsigned char t = 21;
    unsigned char p[2][5];
    p[0][0]=3;
    p[0][1]=2;
    p[0][2]=4;
    p[0][3]=4;
    p[0][4]=0;
    p[1][0]=2;
    p[1][1]=1;
    p[1][2]=4;
    p[1][3]=3;
    p[1][4]=0;
    f(n, p, t);
}
