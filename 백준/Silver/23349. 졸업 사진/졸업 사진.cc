#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    set<string> names;
    unordered_map<string, vector<int>> times;
    unordered_map<string, priority_queue<int, vector<int>, greater<int>>> gugan;
    unordered_map<string, int> count;

    for (int i = 0; i < n; i++)
    {
        string name, place;
        int a, b;
        cin >> name >> place >> a >> b;

        // 사람당 초기 입력만 저장
        if (names.find(name) == names.end())
        {
            // 사람 이름을 기억한다
            names.insert(name);
            // 구간마다 시작 시간을 기록한다.
            // 이는 최대 겹치는 지점을 확인 할 때 전체 구간을 훑지 않기 위함이다.
            gugan[place].push(a);

            // 장소 초기 입력시 벡터의 크기를 조절한다.
            if (times.find(place) == times.end())
            {
                times[place].resize(50001);
            }

            // 벡터에 범위를 기록하고 최대 겹치는 값을 count에 기록함
            for (int i = a; i < b; i++)
            {
                times[place][i]++;
                if (times[place][i] > count[place])
                {
                    count[place] = times[place][i];
                }
            }
        }
    }

    // 장소 마다 겹치는 구간의 최대 크기를 기록한 count가 있다.
    // 이를 이용하여 max라는 pair에 해당하는 장소를 저장한다.
    // 최대 크기가 겹치는 경우 이름을 사전순으로 비교한다.
    pair<string, int> max = *(count.begin());
    for (auto ele : count)
    {
        if (ele.second > max.second)
        {
            max = ele;
        }
        else if (ele.second == max.second)
        {
            if (max.first > ele.first)
            {
                max = ele;
            }
        }
    }

    // max를 이용하여 답을 출력한다.
    int start_time;
    while(1)
    {
        // gugan을 이용해 최대 겹치는 지점의 시작위치를 확인한다.
        // 가장 많이 제출된 시간대가 여러 개라면, 가장 빠른 시간대를 골라야하기 때문에,
        // 오름차 순 우선 순위 큐에 구간을 저장했다.
        if (times[max.first][gugan[max.first].top()] == max.second)
        {
            start_time = gugan[max.first].top();
            int index = 1;
            while (times[max.first][gugan[max.first].top() + index] == max.second)
            {
                index++;
            }
            cout << max.first << " " << start_time << " " << gugan[max.first].top() + index;
            return 0;
        }
        //구간이 최대 겹치는 지점이 아닐 경우 pop하여 다음 시작지점을 확인할 수 있게 한다.
        gugan[max.first].pop();
    }

    return 0;
}
