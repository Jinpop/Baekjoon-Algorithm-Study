#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
using namespace std;

int dp[1000];
int num[1000];

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
        dp[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (num[i] > num[j])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = max(result, dp[i]);
    }

    cout << result;

    return 0;
}
