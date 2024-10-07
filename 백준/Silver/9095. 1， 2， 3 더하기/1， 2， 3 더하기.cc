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

    int num[12] = {0};
    num[1]=1;
    num[2]=2;
    num[3]=4;

    for (int i = 4; i <= 11; i++)
    {
        num[i] = num[i-1] + num[i-2] + num[i-3];
    }

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        cout << num[temp] << "\n";
    }

    return 0;
}