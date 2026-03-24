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
    string str, key;
    cin >> str >> key;

    int n = key.size();
    vector<int> f(n);
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        while (j && key[i] != key[j])
            j = f[j - 1];

        if (key[i] == key[j])
            f[i] = ++j;
    }

    string result;
    vector<int> dp(str.size());
    j = 0;
    for (int i = 0; i < str.size(); i++)
    {
        result.push_back(str[i]);
        while (j && str[i] != key[j])
            j = f[j - 1];
        if (str[i] == key[j] && ++j == key.size())
        {
            result.erase(result.size() - key.size(), key.size());
            j = dp[result.size()];
        }
        dp[result.size()] = j;
    }
    cout << result << '\n';
}