#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;

    int cnt = 1;
    while (m > n)
    {
        if (m % 10 == 1)
        {
            m /= 10;
        }
        else if (m % 2 == 0)
        {
            m /= 2;
        }
        else
        {
            cout << -1;
            return 0;
        }

        cnt++;
    }

    if (m != n)
    {
        cout << -1;
        return 0;
    }

    cout << cnt;

    return 0;
}