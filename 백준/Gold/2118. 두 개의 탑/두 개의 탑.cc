#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int num[50001] = {0};

    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        num[i] = num[i] + num[i-1];
    }

    int max = 0;
    int j = 2;
    int i = 1;
    while (j <= n)
    {
        // 안쪽 거리 합
        int sum1 = num[j] - num[i];
        // 바깥쪽 거리 합
        int sum2 = num[n] - num[j] + num[i];
        
        if (min(sum1, sum2) > max)
        {
            max = min(sum1, sum2);
        }

        if (sum1 == sum2)
        {
            break;
        }
        else if (sum1 < sum2) {
            j++;
        }
        else {
            i++;
        }
    }

    cout << max;

    return 0;
}