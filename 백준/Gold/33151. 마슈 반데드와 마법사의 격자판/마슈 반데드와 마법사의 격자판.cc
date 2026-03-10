#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define F(i, n) for (int i = 1; i <= n; i++)
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
#define MX 1001

int n, k;
int table[MX][MX];

void go(int idx, int flag)
{
    F(i, n)
    F(j, n)
    if ((i + j) % 2 == flag)
    {
        table[i][j] += idx;
        k -= idx;

        if (k < 1)
            return;
    }
}

int main()
{
    fastio;

    cin >> n >> k;

    // 안되는 경우
    if (n == 1)
    {
        cout << k;
        return 0;
    }
    if (k < n * n / 2)
    {
        cout << -1;
        return 0;
    }
    if (n % 2 == 0 && k % 2 == 1)
    {
        cout << -1;
        return 0;
    }

    // 체크 무늬 1로 찍기
    bool flag = 0;
    if (n % 2 == 1 && k % 2 == 0)
        flag = 1;
    go(1, flag);

    // F(i, n)
    // {
    //     F(j, n)
    //     cout << table[i][j] << " ";
    //     cout << "\n";
    // }

    while (k > 0)
    {
        flag = !flag;
        go(2, flag);
    }

    F(i, n)
    {
        F(j, n)
        cout << table[i][j] << " ";
        cout << "\n";
    }
}
