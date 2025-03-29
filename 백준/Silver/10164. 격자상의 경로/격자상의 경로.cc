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

int dp[15][15];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    int x = k / m;
    int y = (k - 1) % m;

    if (k == 0)
    {
        y = 0;
    }

    dp[0][0] = 1;

    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            dp[i][j + 1] += dp[i][j];
            dp[i + 1][j] += dp[i][j];
        }
    }

    int result = dp[x][y];

    for (int i = 0; i < n; i++)
    {
        memset(dp[i], 0, sizeof(int) * m);
    }

    dp[x][y] = 1;

    for (int i = x; i <= n; i++)
    {
        for (int j = y; j <= m; j++)
        {
            dp[i][j + 1] += dp[i][j];
            dp[i + 1][j] += dp[i][j];
        }
    }

    cout << result * dp[n - 1][m - 1] << "\n";

    return 0;
}