#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define F(i, n) for (int i = 1; i <= n; i++)
#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 1e9
#define MX 5001

int n;
vector<int> v;

int main()
{
    fastio;

    cin >> n;

    F(i, n)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }

    vector<int> comp = v;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i = 0; i < n; i++)
        v[i] = lower_bound(comp.begin(), comp.end(), v[i]) - comp.begin();

    int result = 0;
    for (int mid = 0; mid < n; mid++)
    {
        int idx = min(n - 1 - mid, mid + 1);
        int l = mid - idx + 1, r = mid + idx;

        int table[MX] = {0};
        for (int i = l; i <= mid; i++)
            table[v[i]]++;
        for (int i = mid + 1; i <= r; i++)
            table[v[i]]--;

        int zero_cnt = 0;
        int non_zero[MX] = {0};
        for (int i = 0; i < MX; i++)
            if (table[i] != 0)
            {
                zero_cnt++;
                non_zero[i] = 1;
            }

        while (result < r - l + 1)
        {
            // cout << l << " " << r << "looking !\n";
            if (zero_cnt == 0)
            {
                // cout << l << " " << r << "there !\n";
                result = r - l + 1;
            }

            table[v[r]]++;
            if (table[v[r]] == 0)
            {
                non_zero[v[r]] = 0;
                zero_cnt--;
            }
            else
            {
                if (non_zero[v[r]] == 0)
                {
                    non_zero[v[r]] = 1;
                    zero_cnt++;
                }
            }
            table[v[l]]--;
            if (table[v[l]] == 0)
            {
                non_zero[v[l]] = 0;
                zero_cnt--;
            }
            else
            {
                if (non_zero[v[l]] == 0)
                {
                    non_zero[v[l]] = 1;
                    zero_cnt++;
                }
            }

            r--;
            l++;
        }
    }

    cout << result;
}
