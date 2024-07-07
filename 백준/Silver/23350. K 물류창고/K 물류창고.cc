#include <iostream>
#include <utility>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    std::cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> rail;
    stack<pair<int, int>> s;
    stack<pair<int, int>> temp_s;
    // 들어온 우선순위 갯수를 저장할 배열
    int *priority = new int[m + 1];

    for (int i = 0; i < n; i++)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        // 레일에 pair을 들어온 순서대로 집어 넣는다.
        rail.push(p);
        // 들어온 우선 순위의 갯수를 기록한다.
        priority[p.first]++;
    }

    int prio = 0;
    int wei = 0;
    int cost = 0;

    while (rail.size())
    {
        // 입력 받은 prio 갯수를 이용하여 현재 레일에 있는 컨테이너에서 우선순위가 낮은거 부터 먼저 적재한다.
        if (rail.front().first == m - prio)
        {
            // 우선순위가 같은 경우 s에 있는 무게가 레일 위에 있는 컨테이너보다 작아질 때까지 들어낸다.
            while (s.size() && s.top().first == rail.front().first && s.top().second < rail.front().second)
            {
                // 스택에서 들어낸 무게를 총 비용에 더해준다.
                cost += s.top().second;
                // 스택에서 잠시 빈 공간으로 컨테이너를 옮겨 둔다.
                temp_s.push(s.top());
                s.pop();
            }

            // 무게에 맞게 덜어낸 stack에 해당하는 컨테이너를 옮기고, cost를 추가한다.
            s.push(rail.front());
            cost += rail.front().second;
            rail.pop();

            // rail에서 pop한 우선 순위의 갯수를 배열에서 빼준다.
            priority[m - prio]--;
            // 만약 레일에 해당 우선 순위를 전부 사용했다면 prio변수를 ++한다.
            if (priority[m - prio] == 0)
            {
                prio++;
            }
            
            //임시로 옮겨뒀던 컨테이너를 원위치 시키고 cost를 더해준다.
            while(temp_s.size()){
                cost+=temp_s.top().second;
                s.push(temp_s.top());
                temp_s.pop();
            }
        }
        // 현재 레일에 맨 앞 컨테이너가 우선순위가 맞지 않는 경우
        else
        {
            // 레일의 맨 앞으로 컨테이너를 보내고 cost에 추가한다.
            cost += rail.front().second;
            rail.push(rail.front());
            rail.pop();
        }
    }

    std::cout << cost << "\n";

    delete[] priority;

    return 0;
}