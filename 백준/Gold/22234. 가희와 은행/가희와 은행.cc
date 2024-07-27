#include <iostream>
#include <utility>
#include <map>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, t, w;
    cin >> n >> t >> w;

    queue<pair<int, int>> q;

    // 대기 고객 입력
    for (int i = 0; i < n; i++)
    {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        q.push(temp);
    }

    int m;
    cin >> m;
    // 신규 고객 입력
    map<int, pair<int, int>> sort_new_q;
    for (int i = 0; i < m; i++)
    {
        int come;
        pair<int, int> temp;
        cin >> temp.first >> temp.second >> come;

        sort_new_q[come] = temp;
    }

    queue<pair<int, int>> new_q;
    queue<int> come_q;

    for (auto ele : sort_new_q)
    {
        new_q.push(ele.second);
        come_q.push(ele.first);
    }

    // 스케줄링 구현
    int temp_t = t;
    int total_time = 0;
    while (total_time++ != w)
    {
        temp_t--;
        // 처리 중인 고객 출력
        cout << q.front().first << "\n";
        q.front().second--;

        // 신규 고객 추가
        if (!come_q.empty() && come_q.front() == total_time)
        {
            come_q.pop();
            q.push(new_q.front());
            new_q.pop();
        }

        // 고객의 업무가 안끝남.
        if (q.front().second > 0)
        {
            // 고객에게 할당된 시간이 끝난 경우
            if (temp_t == 0)
            {
                q.push(q.front());
                q.pop();
                temp_t = t;
            }
        }
        // 고객의 업무가 끝남.
        else
        {
            q.pop();
            temp_t = t;
        }
    }

    return 0;
}