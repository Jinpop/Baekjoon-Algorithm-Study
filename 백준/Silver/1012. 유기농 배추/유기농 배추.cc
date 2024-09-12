#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int t, r, c, k;
bool table[50][50];

void dfs(int x, int y)
{
    if (x < 0 || y < 0 || x > r - 1 || y > c - 1)
    {
        return;
    }

    if (table[x][y])
    {
        table[x][y] = 0;
        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> r >> c >> k;
        memset(table, 0, sizeof(table));

        for (int i = 0; i < k; i++)
        {
            int idx1, idx2;
            cin >> idx1 >> idx2;

            table[idx1][idx2] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (table[i][j])
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}