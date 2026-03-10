#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define F(i, n) for (int i = 1; i <= n; i++)
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
#define MX 200001

int n, m;

int main()
{
    fastio;

    cin >> n >> m;

    F(i, m)
    {
        int t1, t2;
        cin >> t1 >> t2;
    }

    if (n <= 3)
    {
        cout << "Yes";
        return 0;
    }

    if (m > n)
        cout << "No";
    else
        cout << "Yes";
}
