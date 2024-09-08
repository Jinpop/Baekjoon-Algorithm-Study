#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int table[1000000];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        table[i] = table[i - 1] + 1;

        if (i % 2 == 0)
        {
            table[i] = min(table[i], table[i / 2] + 1);
        }

        if (i % 3 == 0)
        {
            table[i] = min(table[i], table[i / 3] + 1);
        }
    }

    cout << table[n];

    return 0;
}