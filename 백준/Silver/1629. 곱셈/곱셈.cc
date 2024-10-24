#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

long long a, b, c;

long long solve(long long x)
{
    if (x == 1)
    {
        return a % c;
    }
    long long k = solve(x / 2);

    if (x % 2 == 1)
    {
        return k * k % c * a % c;
    }
    else
    {
        return k * k % c;
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> a >> b >> c;

    cout << solve(b);

    return 0;
}