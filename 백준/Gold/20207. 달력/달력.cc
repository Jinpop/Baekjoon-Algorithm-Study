#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define F(i, n) for (ll i = 1; i <= n; i++)
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
#define MX 367

int num[MX];

int main()
{
    fastio;

    int n;
    cin >> n;

    int mx = 0;
    F(i, n)
    {
        int t1, t2;
        cin >> t1 >> t2;

        t2++;
        num[t1]++;
        num[t2]--;

        mx = max(mx, t2);
    }

    bool flag = 0;
    int s;
    F(i, mx)
    {
        if (!flag && num[i] > 0)
        {
            flag = 1;
            s = i;
        }

        if (flag)
        {
            // cout << num[i] << " ";
            num[i] += num[i - 1];
        }
    }

    int total = 0;
    int l = 0, h = 0;
    for (int i = s; i <= mx; i++)
    {
        if (num[i] != 0)
        {
            l++;
            h = max(num[i], h);
        }
        else
        {
            total += l * h;
            l = 0;
            h = 0;
        }
    }

    cout << total;
}
