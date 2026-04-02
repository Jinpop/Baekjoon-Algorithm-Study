#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define F(i, n) for (ll i = 1; i <= n; i++)
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
#define MX 200001

int main()
{
    fastio;

    int n;
    cin >> n;

    string s;
    cin >> s;

    F(i, n)
    {
        string t;
        cin >> t;

        if (t.size() < s.size() - 1)
        {
            cout << "NE\n";
            continue;
        }

        bool c = 1;
        auto ele = s.begin();
        for (int i = 0; *ele != '*'; ele++, i++)
        {
            if (t[i] != *ele)
            {
                c = 0;
                break;
            }
        }

        auto rele = s.rbegin();
        for (int i = t.size() - 1; *rele != '*'; rele++, i--)
        {
            if (t[i] != *rele)
            {
                c = 0;
                break;
            }
        }

        if (c)
            cout << "DA\n";
        else
            cout << "NE\n";
    }
}
