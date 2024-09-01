#include <iostream>
#include <queue>
using namespace std;

int num[1024][1024];

int second(int a, int b, int c, int d)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.push(d);
    pq.pop();
    return pq.top();
}

int div_con(int offset, int x, int y)
{
    if (offset != 2)
    {
        return second(
            div_con(offset / 2, x, y),
            div_con(offset / 2, x + offset / 2, y),
            div_con(offset / 2, x, y + offset / 2),
            div_con(offset / 2, x + offset / 2, y + offset / 2));
    }
    else
    {
        return second(
            num[x][y],
            num[x][y + 1],
            num[x + 1][y],
            num[x + 1][y + 1]);
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    // 예외처리
    if (n == 1)
    {
        cin >> n;
        cout << n;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> num[i][j];
        }
    }

    cout << div_con(n, 0, 0);

    return 0;
}