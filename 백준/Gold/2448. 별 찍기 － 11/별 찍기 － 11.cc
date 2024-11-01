#include <iostream>
#include <cstring>
using namespace std;

char result[3500][7000];

void div_con(int n, int x, int y)
{
    if (n == 3)
    {
        for (int i = 0; i < 5; i++)
        {
            result[x][y + i] = '*';
        }
        result[x - 1][y + 1] = '*';
        result[x - 1][y + 3] = '*';
        result[x - 2][y + 2] = '*';
    }
    else
    {
        div_con(n / 2, x, y);
        div_con(n / 2, x, y + n);
        div_con(n / 2, x-n/2, y + n/2);
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    memset(result, ' ', sizeof(result));

    div_con(n, n - 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2 - 1; j++)
        {
            cout << result[i][j];
        }
        cout << "\n";
    }

    return 0;
}

//     *
//    * *
//   *****
//  *     *
// * *   * *
//***** *****

//  *
// * *
//*****