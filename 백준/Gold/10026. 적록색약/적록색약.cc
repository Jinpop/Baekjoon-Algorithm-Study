#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char table[100][100];
int n;
char target;
queue<pair<int, int>> q;

void push(pair<int, int> idx)
{
    if (idx.first >= 0 && idx.second >= 0 && idx.first < n && idx.second < n && table[idx.first][idx.second] == target)
    {
        table[idx.first][idx.second] = table[idx.first][idx.second] - 'A' + 'a';
        q.push({idx.first, idx.second});
    }
}

void push2(pair<int, int> idx)
{
    if (idx.first >= 0 && idx.second >= 0 && idx.first < n && idx.second < n && table[idx.first][idx.second] == target)
    {
        table[idx.first][idx.second] = 'x';
        q.push({idx.first, idx.second});
    }
}

void bfs1()
{
    pair<int, int> idx = q.front();
    target = table[idx.first][idx.second];

    while (!q.empty())
    {
        int temp_size = q.size();

        for (int i = 0; i < temp_size; i++)
        {
            idx = q.front();
            q.pop();

            // 소문자로 바꿈
            if (table[idx.first][idx.second] < 90)
            {
                table[idx.first][idx.second] = table[idx.first][idx.second] - 'A' + 'a';
            }

            push({idx.first + 1, idx.second});
            push({idx.first - 1, idx.second});
            push({idx.first, idx.second + 1});
            push({idx.first, idx.second - 1});
        }
    }
}

void bfs2()
{
    pair<int, int> idx = q.front();
    target = table[idx.first][idx.second];

    while (!q.empty())
    {
        int temp_size = q.size();

        for (int i = 0; i < temp_size; i++)
        {
            idx = q.front();
            q.pop();

            // 소문자로 바꿈
            table[idx.first][idx.second] = 'x';

            push2({idx.first + 1, idx.second});
            push2({idx.first - 1, idx.second});
            push2({idx.first, idx.second + 1});
            push2({idx.first, idx.second - 1});
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> table[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] < 90)
            {
                q.push({i, j});
                bfs1();
                cnt++;
            }
        }
    }

    cout << cnt << " ";
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] == 'g')
            {
                table[i][j] = 'r';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] != 'x')
            {
                q.push({i, j});
                bfs2();
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}