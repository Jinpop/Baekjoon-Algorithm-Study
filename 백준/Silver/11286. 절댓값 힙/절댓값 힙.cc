#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if (temp == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top().second << "\n";
                pq.pop();
            }
            else {
                cout << "0\n";
            }
        }
        else
        {
            pq.push({abs(temp), temp});
        }
    }

    for (int i = 0; i < cnt; i++)
    {
    }

    return 0;
}