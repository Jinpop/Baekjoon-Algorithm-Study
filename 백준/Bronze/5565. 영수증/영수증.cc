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

    int a = 9;
    while(a--)
    {
        int temp;
        cin >> temp;

        n-=temp;
    }

    cout << n;

    return 0;
}