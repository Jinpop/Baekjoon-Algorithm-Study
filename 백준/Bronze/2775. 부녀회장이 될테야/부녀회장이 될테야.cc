#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define F(i, n) for (ll i = 1; i <= n; i++)
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
#define MX 1

int dp[15][15];

int main()
{
    fastio;

    // 0층 채우기
    F(i, 14) { dp[0][i] = i; };

    // 나머지 층 채우기
    F(i, 14)
    F(j, 14)
    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    // dp 테이블 확인
    //  F(i, 14)
    //  {
    //      F(j, 14)
    //      cout << dp[i][j] << " ";
    //      cout << "\n";
    //  }

    int T;
    cin >> T;

    F(i, T)
    {
        int t1, t2;
        cin >> t1 >> t2;

        cout << dp[t1][t2] << "\n";
    }

    return 0;
}
