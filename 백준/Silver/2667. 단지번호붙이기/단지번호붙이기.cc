#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int t;
bool table[25][25];
int max_cnt;

priority_queue<int, vector<int>, greater<int>> pq;

void dfs(int cnt, int x, int y)
{
    if (x < 0 || y < 0 || x > t - 1 || y > t - 1)
    {
        return;
    }

    if (table[x][y])
    {
        max_cnt++;
        table[x][y] = 0;
        int next = cnt + 1;
        dfs(next, x + 1, y);
        dfs(next, x - 1, y);
        dfs(next, x, y + 1);
        dfs(next, x, y - 1);
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
        for (int j = 0; j < t; j++)
        {
            char temp;
            cin >> temp;
            table[i][j] = temp - '0';
        }
    }

    int cnt = 0;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (table[i][j])
            {
                max_cnt = 0;
                dfs(1, i, j);
                cnt++;
                pq.push(max_cnt);
            }
        }
    }

    cout << cnt << "\n";

    while (!pq.empty())
    {
        cout << pq.top() << "\n";
        pq.pop();
    }

    return 0;
}