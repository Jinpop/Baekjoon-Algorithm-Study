#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
using namespace std;

int num[100000];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    int maxs = num[0], sum = num[0];

    for (int i = 1; i < n; ++i)
    {
        // 최대 부분합을 갱신
        sum = max(num[i], sum + num[i]);
        maxs = max(maxs, sum);
    }

    cout << maxs;

    return 0;
}