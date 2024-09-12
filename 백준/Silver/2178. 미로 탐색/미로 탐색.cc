#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
bool table[100][100];
int cnt = 1;
queue<pair<int, int>> q;


void push(int x, int y)
{
    if (x >= 0 && y >= 0 && x < n && y < m && table[x][y])
    {
        if (x == n-1 && y == m-1)
        {
            cout << cnt;
            table[n-1][m-1] = 0;
        }

        table[x][y] = 0;
        q.push({x, y});
    }
}

void bfs()
{
    q.push({0, 0});

    while (table[n-1][m-1])
    {
        cnt++;
        int temp_size = q.size();
        for (int i = 0; i < temp_size; i++)
        {
            pair<int,int> temp = q.front();
            q.pop();
            push(temp.first+1,temp.second);
            push(temp.first-1,temp.second);
            push(temp.first,temp.second+1);
            push(temp.first,temp.second-1);
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char temp;
            cin >> temp;
            table[i][j] = temp - '0';
        }
    }

    bfs();

    return 0;
}