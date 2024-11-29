#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k, b;
    cin >> n >> k >> b;

    bool list[n];
    for (int i = 0; i < n; i++)
    {
        list[i] = 1;
    }

    for (int i = 0; i < b; i++)
    {
        int temp;
        cin >> temp;
        list[temp - 1] = 0;
    }

    int cnt = 0;
    int i;
    for (i = 0; i < k; i++)
    {
        if (list[i])
        {
            cnt++;
        }
    }

    int result = cnt;

    for (int j = 1; j <= n - k; j++)
    {
        if (list[j - 1])
        {
            cnt--;
        }
        if (list[i])
        {
            cnt++;
        }
        result = max(result, cnt);
        i++;
    }

    if (result >= k)
    {
        cout << 0;
        return 0;
    }

    cout << k - result;

    return 0;
}