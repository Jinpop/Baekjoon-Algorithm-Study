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

    string n, m;
    cin >> n >> m;

    int idx = 0;
    reverse(m.begin(), m.end());

    vector<char> v;
    for (auto ele : n)
    {
        v.push_back(ele);

        if (v.size() >= m.size() && v.back() == m[0])
        {
            int idx = v.size() - 1;

            bool flag = 1;
            for (int i = 0; i < m.size(); i++)
            {
                if (v[idx--] != m[i])
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
                for (int i = 0; i < m.size(); i++)
                    v.pop_back();
        }
    }

    if (v.empty())
        cout << "FRULA";
    for (auto ele : v)
        cout << ele;
}
