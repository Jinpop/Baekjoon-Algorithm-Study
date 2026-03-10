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

    string key, str;
    cin >> key >> str;

    string rev_key = key;
    reverse(rev_key.begin(), rev_key.end());

    deque<char> left, right;

    int l = 0;
    int r = str.size() - 1;
    bool turn = 1;

    while (l <= r)
    {
        if (turn)
        {
            left.push_back(str[l++]);

            if (left.size() >= key.size())
            {
                bool flag = 1;
                for (int i = 0; i < key.size(); i++)
                {
                    if (left[left.size() - key.size() + i] != key[i])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    for (int i = 0; i < key.size(); i++)
                        left.pop_back();
                    turn = 0;
                }
            }
        }
        else
        {
            right.push_back(str[r--]);

            if (right.size() >= key.size())
            {
                bool flag = 1;
                for (int i = 0; i < key.size(); i++)
                {
                    if (right[right.size() - key.size() + i] != rev_key[i])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    for (int i = 0; i < key.size(); i++)
                        right.pop_back();
                    turn = !turn;
                }
            }
        }
    }

    while (!right.empty())
    {
        left.push_back(right.back());
        right.pop_back();

        if (left.size() >= key.size())
        {
            bool flag = 1;
            for (int i = 0; i < key.size(); i++)
            {
                if (left[left.size() - key.size() + i] != key[i])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                for (int i = 0; i < key.size(); i++)
                    left.pop_back();
                turn = !turn;
            }
        }
    }

    for (char c : left)
        cout << c;

    return 0;
}
