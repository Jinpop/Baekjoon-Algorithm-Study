#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<long double, int> pdi;

#define F(i, n) for (ll i = 1; i <= n; i++)
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
#define MX 101

int main()
{
    fastio;

    ll n;
    cin >> n;

    vector<ll> v;
    ll total = 0;
    F(i, n)
    {
        ll t;
        cin >> t;

        v.push_back(t);
        total += t;
    }

    ll cnt_idx = total / n;
    ll cur = 0;
    ll result = 0;

    F(T, 2)
    for (int i = 0; i < n; i++)
    {
        ll temp = v[i] - cnt_idx;
        if (temp > 0)
        {
            cur += temp;
            v[i] = cnt_idx;
        }
        else if (temp < 0)
        {
            if (cur == 0)
                continue;

            ll need = cnt_idx - v[i];
            if (cur >= need)
            {
                cur -= need;
                v[i] = cnt_idx;
            }
            else
            {
                v[i] += cur;
                cur = 0;
            }
        }

        result += cur;
    }

    cout << result;

    return 0;
}

// 1 2
// 3 4 5 6