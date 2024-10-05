#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int temp1 = 0;
    while (n--)
    {
        int temp;
        cin >> temp;
        temp > temp1 ? temp1 = temp : 0;
    }

    cout << temp1;

    return 0;
}