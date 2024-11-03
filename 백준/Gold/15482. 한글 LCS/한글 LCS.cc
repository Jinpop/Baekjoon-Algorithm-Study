#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s1, s2;

    cin >> s1 >> s2;

    int result = 0;
    for (int i = 1; i <= s1.size()/3; i ++)
    {
        for (int j = 1; j <= s2.size()/3; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (s1.substr((i-1)*3, 3) == s2.substr((j-1)*3, 3))
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            result = max(result, dp[i][j]);
        }
    }

    // for (int i = 1; i <= s1.size() / 3; i++)
    // {
    //     for (int j = 1; j <= s2.size() / 3; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << result;

    return 0;
}