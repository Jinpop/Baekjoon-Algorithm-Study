#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    set<string> set;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (s != "ENTER")
        {
            if (set.find(s) == set.end())
            {
                set.insert(s);
                cnt++;
            }
        }
        else
        {
            set.clear();
        }
    }

    cout << cnt;

    return 0;
}