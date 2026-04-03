#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define F(i, n) for (ll i = 1; i <= n; i++)
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
#define MX 1

int main()
{
    fastio;

    string n, m;
    cin >> n;
    m = n, reverse(n.begin(), n.end());
    cout << (n == m);

    return 0;
}
