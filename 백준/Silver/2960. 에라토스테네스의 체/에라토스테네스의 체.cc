#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;

    bool *table = new bool[n + 1]{0};

    int count = 0;
    int num;

    for (int i = 2; i <= n; i++)
    {
        if (table[i] == 0)
        {
            table[i] = 1;
            count++;
            if (count == k)
            {
                cout << i;
                break;
            }

            for (int j = i+i; j <= n; j += i)
            {
                if (table[j] == 0)
                {
                    table[j] = 1;
                    count++;
                    if (count == k)
                    {
                        cout << j;
                        break;
                    }
                }
            }
        }
    }

    delete[] table;

    return 0;
}