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

    int n;
    cin >> n;

    deque<int> dq;
    for (int i = n; i > 0; i--)
    {
        dq.push_front(i);

        F(j, i)
        {
            dq.push_front(dq.back());
            dq.pop_back();
        }
    }

    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }

    return 0;
}

// 1 2
// 3 4 5 6