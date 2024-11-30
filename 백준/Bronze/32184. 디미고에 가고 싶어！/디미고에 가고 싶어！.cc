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

    int a, b;
    cin >> a >> b;

    int cnt = 0;
    if (a % 2 == 0)
    {
        cnt++;
    }
    if (b % 2 == 1)
    {
        cnt++;
    }
    if (cnt == 0 && (a + b) % 2 == 1)
    {
        cnt++;
    }

    cout << (b - a) / 2 + cnt;

    return 0;
}