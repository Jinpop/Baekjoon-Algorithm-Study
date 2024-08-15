#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int mid[9999];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        int temp;
        cin >> temp;

        mid[0] = temp;

        priority_queue<int> min_q;
        priority_queue<int, vector<int>, greater<int>> max_q;

        for (int j = 1; j < m; j++)
        {
            cin >> temp;

            if (j % 2 == 1)
            {
                if (mid[j - 1] < temp)
                {
                    max_q.push(temp);
                    min_q.push(mid[j - 1]);
                }
                else
                {
                    max_q.push(mid[j - 1]);
                    min_q.push(temp);
                }
            }
            else
            {
                if (temp > max_q.top())
                {
                    mid[j] = max_q.top();
                    max_q.pop();
                    max_q.push(temp);
                }
                else if (temp < min_q.top())
                {
                    mid[j] = min_q.top();
                    min_q.pop();
                    min_q.push(temp);
                }
                else
                {
                    mid[j] = temp;
                }

                // cout << min_q.top() << " min_q top\n";
                // cout << mid[j] << "\n";
                // int check;
                // cin >> check;
            }
        }

        cout << (m + 1) / 2 << "\n";
        for (int j = 0; j < m; j += 2)
        {
            cout << mid[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}