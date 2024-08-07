#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int, int>> room;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        room.push_back({s, t});
        pq.push(t);
    }

    sort(room.begin(), room.end());

    for (auto ele : room)
    {
        if (ele.first >= pq.top())
        {
            pq.pop();
        }
    }

    cout << pq.size();

    return 0;
}
