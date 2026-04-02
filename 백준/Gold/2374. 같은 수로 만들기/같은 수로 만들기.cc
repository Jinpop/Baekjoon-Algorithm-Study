#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define F(i, n) for (ll i = 1; i <= n; i++)
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
#define MX 1000

int num[MX];

int main()
{
    fastio;

    int n;
    cin >> n;

    vector<int> v;
    F(i, n)
    {
        int t;
        cin >> t;

        if (v.empty() || v.back() != t)
            v.push_back(t);
    }

    ll ans = 0;
    stack<int> sk;
    for (auto ele : v)
    {
        if (!sk.empty() && sk.top() < ele)
        {
            ans += ele - sk.top();
            while (!sk.empty() && sk.top() < ele)
                sk.pop();
        }
        sk.push(ele);
    }

    while (sk.size() > 1)
    {
        int t = sk.top();
        sk.pop();
        ans += sk.top() - t;
    }

    cout << ans;
}
