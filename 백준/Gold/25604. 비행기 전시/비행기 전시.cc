#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <map>
using namespace std;

typedef struct line
{
    int number;
    int weight;
    int arrive;
} l;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, t;
    cin >> n >> m >> t;

    queue<l> q[2];

    for (int i = 0; i < n; i++)
    {
        l temp_l;
        bool d;
        cin >> d >> temp_l.weight >> temp_l.arrive;
        temp_l.number = i;
        q[d].push(temp_l);
    }

    bool pos = 0;
    int time = 0;
    int wei = 0;
    map<int, pair<int, int>> result;

    while (!q[pos].empty() || !q[!pos].empty())
    {
        // 현재 지점에 이동시킬 부품이 없을 경우 반대로 넘어가고
        // 현재 지점에 준비된 부품이 없는데 반대 지점엔 준비된 부품이 있을 경우 넘어감.
        if (q[pos].empty() || q[pos].front().arrive > time && !q[!pos].empty() && q[!pos].front().arrive <= time)
        {
            time += t;
            pos = !pos;
        }
        // 양 쪽 지점에 모두 준비된 부품이 없는 경우
        if (!q[pos].empty() && !q[!pos].empty() && q[pos].front().arrive > time && q[!pos].front().arrive > time)
        {
            // 현재 지점의 부품 준비가 더 빠른 경우 준비를 기다림.
            if (q[pos].front().arrive <= q[!pos].front().arrive)
            {
                time = q[pos].front().arrive;
            }
            // 반대 지점이 빠른 경우 준비가 된 뒤 이동함.
            else
            {
                time = q[!pos].front().arrive + t;
                pos = !pos;
            }
        }
        // 반대 지점에 부품이 아예 없고 현재 지점에 준비된 부품이 없는 경우
        if (q[pos].front().arrive > time)
        {
            time = q[pos].front().arrive;
        }

        // 이 시점에서 현재 위치에 준비된 부품은 반드시 존재함.
        while (wei < m && !q[pos].empty() && q[pos].front().arrive <= time)
        {
            // 분할 없이 싣는 경우
            if (q[pos].front().weight + wei <= m)
            {
                wei += q[pos].front().weight;
                // 이전에 분할해서 실은 적이 없는 경우
                if (result.find(q[pos].front().number) == result.end())
                {
                    result[q[pos].front().number] = {time, time + t};
                }
                // 분할되어 있던 부품의 경우 도착 시점만 바꿔준다.
                else
                {
                    result[q[pos].front().number].second = time + t;
                }
                q[pos].pop();
            }
            // 부품을 분할하는 경우
            else
            {
                q[pos].front().weight -= (m - wei);
                wei = m;
                // 이전에 분할해서 실은 적이 없는 경우에만 시작 시간을 체크함
                if (result.find(q[pos].front().number) == result.end())
                {
                    result[q[pos].front().number] = {time, 0};
                }
            }
        }

        // 이동
        pos = !pos;
        wei = 0;
        time += t;
    }

    for (auto ele : result)
    {
        cout << ele.second.first << " " << ele.second.second << "\n";
    }

    return 0;
}
