#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int dp[17][17];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    bool check;

    int x = (k - 1) / m + 1;
    int y = (k - 1) % m + 1;

    if (!y)
        y = 1;

    dp[0][1] = 1;

    // cout << x << " " << y << " x y\n";

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    int result = dp[x][y];

    memset(dp, 0, sizeof(dp));

    dp[x][y - 1] = 1;

    for (int i = x; i <= n; i++)
    {
        for (int j = y; j <= m; j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    if (dp[n][m] == 0)
    {
        dp[n][m] = 1;
    }

    cout << result * dp[n][m] << "\n";

    return 0;
}