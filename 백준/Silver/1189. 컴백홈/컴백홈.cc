#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k;
char table[5][5];
int total = 0;

void dfs(int cnt, int x, int y)
{
    if (cnt > k || x < 0 || y < 0 || x > c - 1 || y > r - 1 || table[y][x] == 'T')
    {
        return;
    }
    else if (x == c - 1 && y == 0)
    {
        if (cnt == k)
        {
            total++;
        }
        return;
    }

    if (table[y][x] == '.')
    {
        table[y][x] = 'T';
        dfs(cnt + 1, x + 1, y);
        dfs(cnt + 1, x - 1, y);
        dfs(cnt + 1, x, y + 1);
        dfs(cnt + 1, x, y - 1);
        table[y][x] = '.';
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> r >> c >> k;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> table[i][j];
        }
    }

    dfs(1, 0, r - 1);

    cout << total;

    return 0;
}