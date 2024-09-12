#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool isvisited[500001];

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
                if (temp - 1 > -1 && isvisited[temp - 1] == 0)
                {
                    isvisited[temp - 1] = 1;
                    q.push(temp - 1);
                }
                if (isvisited[temp + 1] == 0)
                {
                    isvisited[temp + 1] = 1;
                    q.push(temp + 1);
                }
                if ( isvisited[temp * 2] == 0 && temp * 2 <= k + 2)
                {
                    isvisited[temp * 2] = 1;
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