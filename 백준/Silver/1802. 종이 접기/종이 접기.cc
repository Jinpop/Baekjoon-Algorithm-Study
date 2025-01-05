#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

string s;

bool div_con(int x, int y)
{
    if (x == y)
    {
        return 1;
    }

    int a = x, b = y;
    while (x != y)
    {
        if (s[x] == s[y])
        {
            return 0;
        }
        x++;
        y--;
    }

    return div_con(a, b / 2 - 1);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;

        if (div_con(0, s.size() - 1))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}