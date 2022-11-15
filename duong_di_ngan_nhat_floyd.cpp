#include <iostream>
#define MAX 100
#define INF 100000
using namespace std;
class Dothi
{
    int n;
    int A[MAX][MAX];

public:
    int d[MAX][MAX], S[MAX][MAX];
    bool read();
    void Floyd();
};

bool Dothi::read()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
            if (i != j && A[i][j] == 0)
                A[i][j] = INF;
        }
}

void Dothi::Floyd()
{
    int next[MAX][MAX];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = A[i][j];
            if (d[i][j] == INF)
                S[i][j] = 0;
            else
                S[i][j] = j;
        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][k] != INF && d[i][j] > (d[i][k] + d[k][j]))
                {
                    d[i][j] = d[i][k] + d[k][j];
                    S[i][j] = S[i][k];
                }

    for (int i = 1; i <= n; i++)
    {
        cout << "\n";
        for (int j = 1; j <= n; j++)
        {
            int u = i;
            if (d[i][j] >= INF)
                cout << "K/c " << i << " -> " << j << " = INF;\n";
            else
            {
                cout << "\nK/c " << i << " -> " << j << " = " << d[i][j] << ";    ";
                cout << u;
                while (u != j)
                {
                    cout << " --> " << S[u][j];
                    u = S[u][j];
                }
            }
        }
    }
}
int main()
{
    Dothi G;
    G.read();
    G.Floyd();
    return 0;
}
