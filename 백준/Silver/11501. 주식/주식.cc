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
        int cnt[10000] = {0};
        F(i, n)
        {
            cin >> num[i];
            cnt[num[i]]++;
        }

        ll total = 0;
        int idx = 10000;
        int prev_i = 1;
        F(i, n)
        {
            while (cnt[idx] <= 0 && idx != 0)
                idx--;

            if (num[i] == idx)
            {
                for (int j = prev_i; j <= i; j++)
                {
                    total += idx - num[j];
                    cnt[num[j]]--;
                }
                prev_i = i + 1;
            }
        }

        cout << total << "\n";
    }
}

// 1 2
// 3 4 5 6