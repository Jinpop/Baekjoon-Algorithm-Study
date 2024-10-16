#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
using namespace std;

int dp[101][100001];
int sum[101][100001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;

    cin >> n >> m;

    vector<int> v;
    v.push_back(0);

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 1e9;
        }
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            sum[i][j] = sum[i - 1][j];

            if (v[i] <= j && dp[i - 1][j - v[i]] + 1 < dp[i][j])
            {
                dp[i][j] = dp[i - 1][j - v[i]] + 1;
                sum[i][j] = sum[i - 1][j - v[i]] + v[i];
            }
        }
    }

    if (sum[n][m] == m)
    {
        cout << dp[n][m];
    }
    else
    {
        cout << -1;
    }

    return 0;
}
