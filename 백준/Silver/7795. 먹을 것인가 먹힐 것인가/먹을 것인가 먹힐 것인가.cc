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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        vector<int> num;
        for (int j = 0; j < x; j++)
        {
            int temp;
            cin >> temp;
            num.push_back(temp);
        }

        sort(num.rbegin(), num.rend());

        int total = 0;
        for (int j = 0; j < y; j++)
        {
            int temp;
            cin >> temp;
            int idx = 0;
            while (temp < num[idx] && idx != x)
            {
                total++;
                idx++;
            }
        }

        cout << total << "\n";
    }

    return 0;
}