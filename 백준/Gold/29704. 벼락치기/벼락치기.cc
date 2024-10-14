#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
using namespace std;

int dp[1001][1001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> v;

    int maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;

        v.push_back({t1, t2});
        maxx += t2;
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

    cout << maxx - dp[n][w];

    return 0;
}