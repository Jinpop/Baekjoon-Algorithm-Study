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

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int dp[1001][10];
    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            dp[i][j] = 0;
            for (int k = j; k < 10; k++)
            {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 10; i++)
    {
        result += dp[n][i];
        result %= 10007;
        // cout << dp[n][i] << " ";
    }
    // cout << "\n";

    cout << result;

    return 0;
}

// 한자리. 0 1 2 3 4 5 6 7 8 9
// 10.
// 두자리. 00 01 02 03 04 05 06 07 08 09
// 11 12 13 14 15 16 17 18 19
// 22 23 24 25 26 27 28 29
// 33 34 35 36 37 38 39
// 44 45 46 47 48 49
// 55 56 57 58 59
// 66 67 68 69
// 77 78 79
// 88 89
// 99
// 55.
// 세자리. 000 001 002 003 004 005 006 007 008 009
// 011 012 013 014 015 016 017 018 019
// 022 023 024 025 026 027 028 029
// 033 034 035 036 037 038 039
// 044 045 046 047 048 049
// 055 056 057 058 059
// 066 067 068 069
// 077 078 079
// 088 089
// 099