#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int l, c;
set<string> result;
set<char> s;
bool visited[15];

void dfs(string pw)
{
    if (pw.size() == l)
    {
        int flag1 = 0, flag2 = 0;
        for (char ele : pw)
        {
            if (ele == 'a' || ele == 'e' || ele == 'i' || ele == 'o' || ele == 'u')
                flag1++;
            else
                flag2++;
        }
        if (flag1 > 0 && flag2 > 1)
        {
            result.insert(pw);
        }
        return;
    }
    int idx = 0;
    for (char ele : s)
    {
        if (!visited[idx] && pw.back() < ele)
        {
            visited[idx] = 1;
            string next = pw + ele;
            dfs(next);
            visited[idx] = 0;
        }
        idx++;
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> l >> c;

    while (c--)
    {
        char temp;
        cin >> temp;
        s.insert(temp);
    }

    dfs("");

    for (string ele : result)
    {
        cout << ele << "\n";
    }

    return 0;
}