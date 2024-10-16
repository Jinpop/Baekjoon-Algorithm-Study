#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
using namespace std;

int n, m;
int num[8];
int isvisited[8];

set<vector<int>> result;

void dfs(int cnt, vector<int> s)
{
    if (cnt == m)
    {
        result.insert(s);
        return;
    }

    for (int i = 0; i < n; i++)
    {

        vector<int> temp_s = s;
        temp_s.push_back(num[i]);
        dfs(cnt + 1, temp_s);
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    vector<int> s;
    dfs(0, s);

    for (auto s : result)
    {
        for (auto ele : s)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }

    return 0;
}
