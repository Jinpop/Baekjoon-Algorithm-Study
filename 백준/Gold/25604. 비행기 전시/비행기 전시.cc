#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m, t;
    cin >> n >> m >> t;

    queue<pair<int, pair<int, int>>> q[2];
    map<int, pair<int, int>> map;

    for (int i = 0; i < n; i++)
    {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        q[temp1].push({i, {temp2, temp3}});
    }

    int cur_t = 0;
    bool cur_pos = 0;
    int cur_wei = 0;
    while (q[0].size() || q[1].size())
    {
        // 부품분해기다리기---------------------------------------------------------------------
        // 현재 지점에 부품이 있고 준비된게 없는 경우
        if (q[cur_pos].empty())
        {
            cur_t+=t;
            cur_pos=!cur_pos;
            continue;
        }

        if (!q[cur_pos].empty() && q[cur_pos].front().second.second > cur_t)
        {
            // 반대 지점 큐가 비었거나 현재 지점의 준비가 더 빠른 경우
            if (q[!cur_pos].empty() || q[cur_pos].front().second.second <= q[!cur_pos].front().second.second)
            {
                cur_t = q[cur_pos].front().second.second;
            }
            // 반대 지점은 준비가 되어 있는 경우
            else if (q[cur_pos].front().second.second > cur_t && q[!cur_pos].front().second.second <= cur_t)
            {
                cur_pos = !cur_pos;
                cur_t+=t;
            }
            // 반대 지점의 준비 속도가 더 빠른 경우
            else 
            {
                cur_pos = !cur_pos;
                cur_t = q[cur_pos].front().second.second + t;
            }
        }

        // 부품싣기-----------------------------------------------------------------------
        //  최대 적재량 만큼 싣는다.
        vector<int> temp_order;
        vector<pair<int,int>> temp_container;
        while (!q[cur_pos].empty() && q[cur_pos].front().second.second <= cur_t && cur_wei < m)
        {
            // 부품을 한번에 이동할 수 있는 경우.
            if (q[cur_pos].front().second.first <= m - cur_wei)
            {
                cur_wei += q[cur_pos].front().second.first;
                temp_order.push_back(q[cur_pos].front().first);
                q[cur_pos].pop();
            }
            // 부품을 분해하는 경우
            else
            {
                q[cur_pos].front().second.first -= (m - cur_wei);
                cur_wei = m;
                temp_order.push_back(q[cur_pos].front().first);
                break;
            }
        }

        // 부품을이동시킨다-----------------------------------------------------------------------
        int before_t = cur_t;
        cur_pos = !cur_pos;
        cur_t += t;
        cur_wei = 0;
        for (int ele : temp_order)
        {
            // 분할해서 보낸 경우
            if (map.find(ele) != map.end())
            {
                map[ele].second = cur_t;
            }
            else
            {
                map.insert({ele, {before_t, cur_t}});
            }
        }
    }

    for (auto ele : map)
    {
        cout << ele.second.first << " " << ele.second.second << "\n";
    }

    return 0;
}