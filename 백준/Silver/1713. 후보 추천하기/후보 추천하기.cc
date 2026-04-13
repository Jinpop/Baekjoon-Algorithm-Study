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

pii cnt[MX];

int main()
{
    fastio;

    int m, n;
    cin >> m >> n;

    int total = 0;
    F(i, n)
    {
        int t;
        cin >> t;

        if (cnt[t].first == 0)
            total++;

        if (total > m)
        {
            vector<pair<pii, int>> v;
            F(i, 100)
            if (cnt[i].first >= 1)
                v.push_back({cnt[i], i});

            sort(v.begin(), v.end());
            cnt[v[0].second] = {0, 0};
            total--;
        }

        cnt[t].first++;
        if (cnt[t].first == 1)
            cnt[t].second = i;
    }

    F(i, 100)
    if (cnt[i].first > 0)
        cout << i << " ";

    return 0;
}

// 1 2
// 3 4 5 6