#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int cnt = 0;
    int idx = 665;
    while (cnt != n)
    {
        bool flag = 0;
        int count = 0;
        for (auto ele : to_string(idx))
        {
            if (ele == '6')
            {
                count++;
            }
            else
            {
                count = 0;
            }

            if (count == 3)
            {
                cnt++;
                break;
            }
        }

        idx++;
    }

    cout << idx-1;

    return 0;
}