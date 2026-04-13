#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<long double, int> pdi;

#define F(i, n) for (ll i = 1; i <= n; i++)
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
#define MX 1000001

int main()
{
    fastio;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int num[MX] = {0};
        F(i, n)
        cin >> num[i];

        ll total = 0;
        int mx = 0;
        for (int i = n; i > 0; i--)
        {
            mx = max(num[i], mx);
            total += mx - num[i];
        }

        cout << total << "\n";
    }
}

// 1 2
// 3 4 5 6