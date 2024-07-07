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
    int *priority = new int[m + 1];

    for (int i = 0; i < n; i++)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        rail.push(p);
        priority[p.first]++;
    }

    int prio = 0;
    int wei = 0;
    int cost = 0;

    while (rail.size())
    {
        if (rail.front().first == m - prio)
        {
            while (s.size() && s.top().first == rail.front().first && s.top().second < rail.front().second)
            {
                cost += s.top().second;
                temp_s.push(s.top());
                s.pop();
            }

            s.push(rail.front());
            cost += rail.front().second;
            rail.pop();

            priority[m - prio]--;
            if (priority[m - prio] == 0)
            {
                prio++;
            }
            
            while(temp_s.size()){
                cost+=temp_s.top().second;
                s.push(temp_s.top());
                temp_s.pop();
            }
        }
        else
        {
            cost += rail.front().second;
            rail.push(rail.front());
            rail.pop();
        }
    }

    std::cout << cost << "\n";

    delete[] priority;

    return 0;
}