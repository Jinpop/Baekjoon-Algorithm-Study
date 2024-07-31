#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int m, t, n;

    cin >> m >> t >> n;

    vector<pair<int, int>> l_v, r_v;

    for (int i = 0; i < n; i++)
    {
        int temp;
        string pos;
        cin >> temp >> pos;
        if (pos[0] == 'r')
        {
            r_v.push_back({temp, i});
        }
        else
        {
            l_v.push_back({temp, i});
        }
    }

    sort(l_v.begin(), l_v.end());
    sort(r_v.begin(), r_v.end());

    queue<pair<int, int>> q[2];
    for (pair<int, int> ele : l_v)
    {
        q[0].push(ele);
    }
    for (pair<int, int> ele : r_v)
    {
        q[1].push(ele);
    }

    bool pos = 0;
    int time = 0;
    int result[10001];
    int member = 0;
    while (q[0].size() || q[1].size())
    {
        // 현 위치의 큐가 비었으면 위치를 이동한다.
        if (q[pos].empty())
        {
            pos = !pos;
            if (q[pos].front().first <= time)
            {
                time += t;
            }
            else
            {
                time = q[pos].front().first + t;
            }
        }

        // 현 위치에 준비된 손님이 없는 경우
        if (q[pos].front().first > time)
        {
            // 반대큐가 빈 경우, 현 위치에서 기다린다.
            if (q[!pos].empty())
            {
                time = q[pos].front().first;
            }
            // 반대큐가 차있는 경우.
            else
            {
                // 반댓편에 준비된 손님이 있을 경우 바로 이동한다.
                if (q[!pos].front().first <= time)
                {
                    time += t;
                    pos = !pos;
                }
                // 만약 둘 다 기다리는 손님이 없고,
                //반댓편에 손님이 더 먼저 오면 그만큼 기다린 뒤 위치를 이동한다.
                else if (q[pos].front().first > q[!pos].front().first)
                {
                    time = q[!pos].front().first + t;
                    pos = !pos;
                }
                // 현 위치로 손님이 더 먼저 오거나 같으면 그냥 기다린다.
                else
                {
                    time = q[pos].front().first;
                }
            }
        }

        while (!q[pos].empty() && member < m && q[pos].front().first <= time)
        {
            // cout << time << " " << q[pos].front().first << "\n";
            // int i;
            // cin >> i;
            result[q[pos].front().second] = time + t;
            q[pos].pop();
            member++;
        }

        time += t;
        pos = !pos;
        member = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << "\n";
    }

    return 0;
}