#include <iostream>
#include <algorithm>
#include <vector>
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
    v.push_back(0);  // 1-based indexing을 위해 0 추가

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    // dp, sum 배열을 초기화
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 1e9; // 최대값으로 초기화
            sum[i][j] = 0;
        }
    }
    dp[0][0] = 0;  // 0을 만드는 데 필요한 항목 수는 0

    // dp와 sum 채우기
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];  // i번째 아이템을 선택하지 않은 경우
            sum[i][j] = sum[i - 1][j];

            if (j >= v[i] && dp[i - 1][j - v[i]] + 1 < dp[i][j])
            {
                dp[i][j] = dp[i - 1][j - v[i]] + 1;
                sum[i][j] = sum[i - 1][j - v[i]] + v[i];
            }
        }
    }
    
    // 목표 금액을 만들 수 있는지 확인
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
