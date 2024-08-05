#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n * n; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);

        if (pq.size() > n)
        {
            pq.pop();
        }
    }

    cout << pq.top();

    return 0;
}

