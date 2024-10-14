#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
using namespace std;

int dp[1001][10001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, w;
    cin >> w >> n;

    vector<pair<int, int>> v;

    for (int i = 1; i <= n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;

        v.push_back({t2, t1});
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (v[i - 1].first <= j)
            {
                dp[i][j] = max(v[i - 1].second + dp[i - 1][j - v[i - 1].first], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // for (int i = 1; i <= w; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << dp[j][i];
    //     }
    //     cout << "\n";
    // }

    cout << dp[n][w];

    return 0;
}