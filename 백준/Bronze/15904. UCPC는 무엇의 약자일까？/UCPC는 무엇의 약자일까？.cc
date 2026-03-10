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

    string str;
    getline(cin, str);

    int cnt = 0;
    string answer = "UCPC";
    for (auto ele : str)
        if (ele == answer[cnt])
            cnt++;

    if (cnt == 4)
        cout << "I love UCPC\n";
    else
        cout << "I hate UCPC\n";
}
