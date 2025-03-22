#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> v;
        unordered_set<int> s;

        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
            s.insert(temp);
        }

        sort(v.begin(), v.end());

        int s_idx = 0, cnt = 0;
        while (s_idx <= v.size() - 2)
        {
            int m_idx = s_idx + 1;

            while (m_idx < v.size() - 1)
            {
                if (s.count(v[m_idx] + v[m_idx] - v[s_idx]))
                {
                    cnt++;
                    // cout << v[s_idx] << ' ' << v[m_idx] << ' ' << v[m_idx] + abs(v[m_idx] - v[s_idx]) << '\n';
                }
                m_idx++;
            }

            s_idx++;
        }

        cout << cnt << '\n';
    }

    return 0;
}