#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int h, w, p;
        cin >> h >> w >> p;

        if (p % h != 0)
        {
            cout << p % h;
        }
        else
        {
            cout << h;
        }

        if (p % h != 0)
        {
            if (p / h + 1 <= 9)
            {
                cout << "0";
            }
            cout << p / h + 1 << "\n";
        }
        else
        {
            if (p / h <= 9)
            {
                cout << "0";
            }
            cout << p / h << "\n";
        }
    }

    return 0;
}