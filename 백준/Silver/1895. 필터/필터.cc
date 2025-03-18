#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, t;
    int arr[40][40];

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cin >> t;

    vector<int> result;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            vector<int> v;
            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    v.push_back(arr[i + a][j + b]);
                }
            }
            sort(v.begin(), v.end());
            result.push_back(v[4]);
        }
    }

    int cnt = 0;
    for (auto ele : result)
    {
        if (ele >= t)
        {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}