#include <iostream>
#include <vector>
using namespace std;

int num[10000];
int dp[10001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = num[i]; j <= m; j++)
        {
            dp[j] += dp[j - num[i]];
        }
    }

    cout << dp[m];

    return 0;
}