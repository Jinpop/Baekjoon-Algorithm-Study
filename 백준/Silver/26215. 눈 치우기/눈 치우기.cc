#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int j = v.size() - 1;
    int i = v.size() - 2;

    int cnt = 0;

    if (n != 1)
    {
        while (v[i] != 0 || v[j] != 0)
        {
            if (v[i] != 0)
            {
                v[i] -= 1;
            }
            if (v[j] != 0)
            {
                v[j] -= 1;
            }

            cnt++;

            sort(v.begin(), v.end());
        }
    }
    else
    {
        cnt = v[0];
    }

    if (cnt > 1440)
    {
        cout << -1;
        return 0;
    }
    cout << cnt;

    return 0;
}
