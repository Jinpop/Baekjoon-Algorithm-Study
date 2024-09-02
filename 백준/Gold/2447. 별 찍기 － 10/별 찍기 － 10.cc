#include <iostream>
using namespace std;

bool result[6561][6561];

void div_con(int size, int x, int y, bool center)
{
    if (center)
    {
        for (int i = x; i < x + size; i++)
        {
            for (int j = y; j < y + size; j++)
            {
                result[i][j] = 0;
            }
        }
    }
    else if (size == 1)
    {
        result[x][y] = 1;
    }
    else
    {
        int offset = size / 3;
        

        for (int i = 0; i < 3 * offset; i += offset)
        {
            for (int j = 0; j < 3 * offset; j += offset)
            {
                bool flag = 0;
                if (i == offset && j == offset)
                {
                    flag = 1;
                }
                div_con(size / 3, x+i, y+j, flag);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    div_con(n, 0, 0, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (result[i][j])
            {
                cout << '*';
            }
            else
            {
                cout << ' ';
            }
        }

        cout << "\n";
    }

    return 0;
}