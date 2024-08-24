#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int play[50][9];
bool isvisited[9];
int total = 0;
int n;
bool base[3];

void move_base(int &sum)
{
    for (int j = 0; j < 3; j++)
    {
        if (base[j] == 1)
        {
            if (j == 0)
            {
                sum++;
            }
            else
            {
                base[j - 1] = 1;
            }
            base[j] = 0;
        }
    }
}

void cnt_point(vector<int> order)
{
    int sum = 0;
    int round = 0;
    int idx = 0;
    int out_cnt = 0;

    while (round != n)
    {
        switch (play[round][order[idx]])
        {
        case 1:
            move_base(sum);
            base[2] = 1;
            break;
        case 2:
            move_base(sum);
            base[2] = 1;
            move_base(sum);
            break;
        case 3:
            move_base(sum);
            base[2] = 1;
            move_base(sum);
            move_base(sum);
            break;
        case 4:
            sum++;
            for (int j = 0; j < 3; j++)
            {
                if (base[j] == 1)
                {
                    sum++;
                    base[j] = 0;
                }
            }
            break;
        case 0:
            out_cnt++;
            if (out_cnt == 3)
            {
                round++;
                out_cnt = 0;
                for (int j = 0; j < 3; j++)
                {
                    base[j] = 0;
                }
            }
            break;
        }
        idx++;

        if (idx == 9)
        {
            idx = 0;
        }
    }

    if (total < sum)
    {
        total = sum;
    }
}

void dfs(int cnt, vector<int> order)
{
    if (cnt == 9)
    {
        cnt_point(order);
        return;
    }
    if (cnt == 3)
    {
        vector<int> temp = order;
        temp.push_back(0);
        dfs(cnt + 1, temp);
    }
    for (int i = 1; i < 9; i++)
    {
        if (!isvisited[i])
        {
            isvisited[i] = 1;
            vector<int> temp = order;
            temp.push_back(i);
            dfs(cnt + 1, temp);
            isvisited[i] = 0;
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
        for (int j = 0; j < 9; j++)
        {
            cin >> play[i][j];
        }
    }

    vector<int> order;
    dfs(0, order);

    cout << total;

    return 0;
}