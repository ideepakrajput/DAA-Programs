#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m = 8;
    int n = 4;
    int p[n + 1] = {0, 1, 2, 5, 6};
    int w[n + 1] = {0, 2, 3, 4, 5};
    cout << "Maximum Capacity of bag: " << m << endl;
    cout << "Number of Objects: " << n << endl;

    int v[n + 1][m + 1] = {0};

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            v[i][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= m; k++)
        {
            int a = k - w[i];
            if (a < 0)
                v[i][k] = v[i - 1][k];
            else
                v[i][k] = max(v[i - 1][k], v[i - 1][a] + p[i]);
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }

    int profit = v[n][m];
    int weight = 8;
    int result[n] = {0};
    for (int i = m; i >= 0;)
    {
        if (profit == 0)
            break;
        for (int j = 0; j <= n; j++)
        {
            if (v[j][i] == profit)
            {
                result[j - 1] = 1;
                weight -= w[j];
                profit -= p[j];
                i = weight;
                break;
            }
            if (j == n)
                i--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "--->" << result[i] << endl;
    }
    cout << "Maximum Profit: " << v[n][m] << endl;
    return 0;
}
