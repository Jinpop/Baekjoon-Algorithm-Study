#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> init = {1, 2, 3, 4, 5, 6, 7, 8, 9};
unordered_set<int> vert[9];
unordered_set<int> hori[9];
unordered_set<int> square[3][3];
int num[9][9];
bool out = 0;

pair<int, int> make_idx(int i, int j)
{
    int i_idx = 0, j_idx = 0;
    if (i < 3)
    {
    }
    else if (i < 6)
        i_idx++;
    else
        i_idx += 2;
    if (j < 3)
    {
    }
    else if (j < 6)
        j_idx++;
    else
        j_idx += 2;

    return {i_idx, j_idx};
}

void solve()
{
    bool flag = 0;
    for (int i = 0; i < 9; i++)
    {
        if (!vert[i].empty())
        {
            flag = 1;
            break;
        }
    }

    if (!flag)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << num[i][j];
            }
            cout << "\n";
            out = 1;
        }
        return;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            if (!num[i][j])
            {
                pair<int, int> idx = make_idx(i, j);
                int n = 1;
                while (1)
                {
                    while (!vert[i].count(n) || !hori[j].count(n) || !square[idx.first][idx.second].count(n))
                    {
                        n++;
                        if (n > 9)
                        {
                            return;
                        }
                    }
                    num[i][j] = n;

                    vert[i].erase(n);
                    hori[j].erase(n);
                    square[idx.first][idx.second].erase(n);

                    solve();

                    if (out)
                    {
                        return;
                    }

                    num[i][j] = 0;
                    vert[i].insert(n);
                    hori[j].insert(n);
                    square[idx.first][idx.second].insert(n);
                    n++;
                }
            }
        }
    }
}

int main()
{
    std::cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 9; i++)
    {
        vert[i] = init;
        hori[i] = init;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            square[i][j] = init;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        string temp;
        std::cin >> temp;
        for (int j = 0; j < 9; j++)
        {
            num[i][j] = temp[j] - '0';

            if (num[i][j] != 0)
            {
                vert[i].erase(num[i][j]);
                hori[j].erase(num[i][j]);

                pair<int, int> idx = make_idx(i, j);
                square[idx.first][idx.second].erase(num[i][j]);
            }
        }
    }

    solve();

    return 0;
}