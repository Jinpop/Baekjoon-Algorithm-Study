#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define F(i, n) for (ll i = 1; i <= n; i++)
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
#define MX 51

int main()
{
    fastio;

    int n;
    cin >> n;

    vector<pii> v;
    vector<int> v_x;
    vector<int> v_y;
    F(i, n)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v.push_back({t1, t2});
        v_x.push_back(t1);
        v_y.push_back(t2);
    }

    sort(v_x.begin(), v_x.end());
    sort(v_y.begin(), v_y.end());

    ll result[MX] = {0};
    F(i, n)
    result[i] = LLONG_MAX;

    for (int i = 0; i < n; i++)
    {
        if (v_x[i] == v_x[i - 1])
            continue;
        for (int j = 0; j < n; j++)
        {
            if (v_y[j] == v_y[j - 1])
                continue;

            vector<ll> v_sum;
            for (int k = 0; k < n; k++)
                v_sum.push_back(abs(v[k].first - v_x[i]) + abs(v[k].second - v_y[j]));

            sort(v_sum.begin(), v_sum.end());

            ll t_sum = 0;
            F(k, n)
            {
                t_sum += v_sum[k - 1];
                result[k] = min(result[k], t_sum);
            }
        }
    }

    F(i, n)
    cout << result[i] << " ";
}
