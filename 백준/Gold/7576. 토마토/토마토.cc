#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int c;
int table[1000][1000];
int n, m;
int total = -1;
queue<pair<int, int>> q;

void push(pair<int, int> idx)
{
    if (idx.first >= 0 && idx.second >= 0 && idx.first < n && idx.second < m && table[idx.first][idx.second] == 0)
    {
        table[idx.first][idx.second] = 1;
        q.push({idx.first, idx.second});
    }
}

void bfs()
{
    while (!q.empty())
    {
        int temp_size = q.size();
        for (int i = 0; i < temp_size; i++)
        {
            // for (int i = 0; i < n; i++)
            // {
            //     for (int j = 0; j < m; j++)
            //     {
            //         cout << table[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            pair<int, int> idx = q.front();
            // cout << idx.first << " " << idx.second << "\n";
            q.pop();
            push({idx.first + 1, idx.second});
            push({idx.first, idx.second + 1});
            push({idx.first - 1, idx.second});
            push({idx.first, idx.second - 1});
        }
        // cout << q.size() << " is size\n";
        // cin >> c;
        total++;
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
            if (table[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (table[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << total;

    return 0;
}