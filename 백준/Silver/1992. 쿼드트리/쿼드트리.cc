#include <iostream>
#include <string>
using namespace std;
int num[64][64];

void check(int n, int x, int y)
{
    int number = num[x][y];
    bool flag = 1;

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (num[i][j] != number)
            {
                flag = 0;
            }
        }
    }

    if (flag)
    {
        cout << number;
    }
    else
    {
        cout << "(";
        check(n / 2, x, y);
        check(n / 2, x, y + n / 2);
        check(n / 2, x + n / 2, y);
        check(n / 2, x + n / 2, y + n / 2);
        cout << ")";
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            num[i][j] = temp[j] - '0';
        }
    }

    check(n, 0, 0);

    return 0;
}