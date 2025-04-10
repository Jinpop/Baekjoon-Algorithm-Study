#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int num[n];

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    int x = 0, y = n - 1;

    int x_idx = 0, y_idx = n - 1;
    int sum = abs(num[0] + num[n - 1]);

    while (x + 1 != y)
    {
        int sum1 = abs(num[x + 1] + num[y]);
        int sum2 = abs(num[x] + num[y - 1]);

        if (sum1 > sum2)
        {
            if (sum > sum2)
            {
                sum = sum2;
                y_idx = y - 1;
                x_idx = x;
            }
            y--;
        }
        else
        {
            if (sum > sum1)
            {
                sum = sum1;
                x_idx = x + 1;
                y_idx = y;
            }
            x++;
        }
    }

    cout << num[x_idx] << " " << num[y_idx];

    return 0;
}