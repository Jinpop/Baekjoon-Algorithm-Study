#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int num[50];
int result = 0;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    if (n == 1)
    {
        cout << 'A';
        return 0;
    }

    set<int> set;

    for (int i = -300; i <= 300; i++)
    {
        for (int j = -20000; j <= 20000; j++)
        {
            for (int k = 0; k < n - 1; k++)
            {
                if (num[k] * i + j != num[k + 1])
                {
                    break;
                }
                else if (k + 1 == n - 1)
                {
                    result = num[k + 1] * i + j;
                    set.insert(result);
                }
            }
        }
    }

    if (set.size() == 0)
    {
        cout << 'B';
    }
    else if (set.size() == 1)
    {
        cout << result;
    }
    else
    {
        cout << 'A';
    }

    return 0;
}