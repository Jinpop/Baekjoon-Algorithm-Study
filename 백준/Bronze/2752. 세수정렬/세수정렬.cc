#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(a);
    pq.push(b);
    pq.push(c);

    cout << pq.top() << " ";
    pq.pop();
    cout << pq.top() << " ";
    pq.pop();
    cout << pq.top();
    pq.pop();

    return 0;
}