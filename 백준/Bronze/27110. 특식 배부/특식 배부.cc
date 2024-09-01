#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, a, b, c;

    cin >> n >> a >> b >> c;

    cout << min(a, n) + min(b, n) + min(c, n);

    return 0;
}