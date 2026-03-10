#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<long double, int> pdi;

#define F(i, n) for (ll i = 1; i <= n; i++)
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
#define MX 367

int main()
{
    fastio;

    int n, m;
    cin >> n >> m;

    long double result = 0;
    deque<pdi> mndq;

    F(i, n)
    {
        long double t;
        cin >> t;

        while (!mndq.empty() && mndq.back().first > t)
            mndq.pop_back();

        mndq.push_back({t, i});

        while (!mndq.empty() && mndq.front().second <= i - m)
            mndq.pop_front();

        //--

        result = max(result, t - mndq.front().first);
    }

    cout << fixed << setprecision(10) << (double)result;
}
