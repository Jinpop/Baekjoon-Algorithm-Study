#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int p[100000][3];
    int a[100000][3];
    int b[n][3];

    int max_dp[3];
    int min_dp[3];
    cin >> max_dp[0] >> max_dp[1] >> max_dp[2];

    min_dp[0] = max_dp[0];
    min_dp[1] = max_dp[1];
    min_dp[2] = max_dp[2];

    for (int i = 1; i < n; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;

        int tt1 = t1, tt2 = t2, tt3 = t3;

        t1 += max(max_dp[0], max_dp[1]);
        t2 += max({max_dp[0], max_dp[1], max_dp[2]});
        t3 += max(max_dp[2], max_dp[1]);

        tt1 += min(min_dp[0], min_dp[1]);
        tt2 += min({min_dp[0], min_dp[1], min_dp[2]});
        tt3 += min(min_dp[2], min_dp[1]);

        max_dp[0] = t1;
        max_dp[1] = t2;
        max_dp[2] = t3;

        min_dp[0] = tt1;
        min_dp[1] = tt2;
        min_dp[2] = tt3;
    }

    cout << max({max_dp[0], max_dp[1], max_dp[2]}) << "\n";
    cout << min({min_dp[0], min_dp[1], min_dp[2]});

    return 0;
}