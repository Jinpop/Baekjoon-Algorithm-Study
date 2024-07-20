#include <iostream>
using namespace std;

int num[129][129];
int blue = 0, white = 0;

void check(int offset, int x, int y)
{
    int val = num[x][y];

    // cout << num[x][y] << " < - val \n";
    bool flag = 1;

    for (int i = x; i < offset + x; i++)
    {
        for (int j = y; j < offset + y; j++)
        {
            // cout << num[i][j] << " ";
            if (num[i][j] != val)
            {
                flag = 0;
            }
        }
        // cout << "\n";
    }

    // cout << "\n";
    // int temp;
    // cin >> temp;
    // cout << "\n";

    // 체크한 면이 정사각형인 경우 카운트해줌
    if (flag)
    {
        if (val)
        {
            // cout << "blue\n";
            blue++;
        }
        else
        {
            // cout << "white\n";
            white++;
        }
    }
    // 정사각형면이 아닌 경우 4개로 나눔.
    else
    {
        // cout << "NAH\n";
        check(offset / 2, x, y);
        check(offset / 2, x + offset / 2, y);
        check(offset / 2, x, y + offset / 2);
        check(offset / 2, x + offset / 2, y + offset / 2);
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    // 입력 받기
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> num[i][j];
        }
    }

    // 정사각형 면을 체크하는 함수
    check(n, 1, 1);

    cout << white << "\n" << blue;

    return 0;
}