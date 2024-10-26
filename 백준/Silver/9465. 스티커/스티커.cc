#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define long long ll
#define pair <int, int> pii
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        int num[2][100001];
        for (int j = 1; j <= m; j++)
        {
            cin >> num[0][j];
        }
        for (int j = 1; j <= m; j++)
        {
            cin >> num[1][j];
        }

        int dp[2][100001];
        dp[0][0] = dp[1][0] = 0;
        dp[1][1] = num[1][1];
        dp[0][1] = num[0][1];

        for (int j = 2; j <= m; j++)
        {
            dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + num[0][j];
            dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + num[1][j];
        }

        cout << max(dp[0][m], dp[1][m]) << "\n";
    }

    return 0;
}

// for (int i = 0; i < n; i++)
// {
// }