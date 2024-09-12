#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<int> isvisited;

void bfs(queue<int> q, int k)
{
    int cnt = 0;
    int temp = q.front();
    while (temp != k)
    {
        int temp_size = q.size();
        for (int i = 0; i < temp_size; i++)
        {
            temp = q.front();
            q.pop();

            if (temp == k)
            {
                break;
            }
            else
            {
                if (isvisited.count(temp - 1) == 0)
                {
                    isvisited.insert(temp - 1);
                    q.push(temp - 1);
                }
                if (isvisited.count(temp + 1) == 0)
                {
                    isvisited.insert(temp + 1);
                    q.push(temp + 1);
                }
                if (isvisited.count(temp * 2) == 0 && temp * 2 <= k + 2)
                {
                    isvisited.insert(temp * 2);
                    q.push(temp * 2);
                }
            }
        }
        cnt++;
    }

    cout << cnt - 1;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    if (n == k)
    {
        cout << 0;
        return 0;
    }

    queue<int> q;
    q.push(n);
    bfs(q, k);

    return 0;
}