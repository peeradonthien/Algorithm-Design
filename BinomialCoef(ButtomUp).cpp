#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> table;
int binomial(int n, int r)
{
    // initial
    for (int i = 0; i <= n; i++)
    {
        table[i][0] = 1;
        table[i][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            table[i][j] = table[i - 1][j] + table[i - 1][j - 1];
        }
    }
    return table[n][r];
}
int main()
{
    int n, r;
    cin >> n >> r;
    table.resize(n+1, vector<int>(n+1));
    cout << binomial(n , r ) << endl;
    /*
    for (auto &x : table)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
        */
}