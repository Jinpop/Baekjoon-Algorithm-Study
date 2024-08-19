#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int i = 0;
    while (n--)
    {
        cout << ++i << "\n";
    }

    return 0;
}