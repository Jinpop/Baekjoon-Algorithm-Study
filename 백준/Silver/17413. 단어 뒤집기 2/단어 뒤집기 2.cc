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
    str += " ";

    stack<char> sk;
    bool flag = 0;
    for (auto ele : str)
    {
        if (flag == 1)
        {
            if (ele == '>')
                flag = 0;

            cout << ele;
            continue;
        }
        if (ele == '<')
        {
            while (!sk.empty())
            {
                cout << sk.top();
                sk.pop();
            }
            flag = 1;
            cout << ele;
            continue;
        }

        if (ele == ' ')
        {
            while (!sk.empty())
            {
                cout << sk.top();
                sk.pop();
            }
            cout << " ";
        }
        else
            sk.push(ele);
    }
}
