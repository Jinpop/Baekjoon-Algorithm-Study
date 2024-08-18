#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[101];
bool visited[101];
int cnt = 0;

void dfs(vector<int> vec)
{
    for (int ele : vec)
    {
        if (visited[ele] == false)
        {
            visited[ele] = true;
            cnt++;
            dfs(v[ele]);
        }
    }
    return;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;  

    for (int i = 0; i <= n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < m; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }

    visited[1] = true;
    for (int ele : v[1])
    {
        if (visited[ele] == false)
        {
            visited[ele] = true;
            cnt++;
            dfs(v[ele]);
        }
    }

    cout << cnt;

    return 0;
}