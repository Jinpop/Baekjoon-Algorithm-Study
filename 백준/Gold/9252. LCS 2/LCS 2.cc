#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];
string s1, s2;
string s_result = "";

void search(int x, int y)
{
    int num = max({dp[x - 1][y], dp[x][y - 1], dp[x - 1][y - 1]});
    if (num == dp[x][y])
    {
        if (dp[x][y] == dp[x][y - 1])
        {
            search(x, y - 1);
        }
        else if (dp[x][y] == dp[x - 1][y])
        {
            search(x - 1, y);
        }
    }
    else if (num != 0)
    {
        s_result += s1[x - 1];
        search(x - 1, y - 1);
    }
    else
    {
        s_result += s1[x - 1];
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> s1 >> s2;

    int result = 0;
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            result = max(result, dp[i][j]);
        }
    }

    cout << result << "\n";
    if (result != 0)
    {
        search(s1.size(), s2.size());
        for (int i = s_result.size() - 1; i != -1; i--)
        {
            cout << s_result[i];
        }
    }

    return 0;
}