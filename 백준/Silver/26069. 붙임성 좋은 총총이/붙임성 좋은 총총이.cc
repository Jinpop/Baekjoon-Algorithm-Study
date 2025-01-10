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
    set.insert("ChongChong");
    bool flag = 0;

    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;

        if (set.find(s1) != set.end() || set.find(s2) != set.end())
        {
            set.insert(s1);
            set.insert(s2);
        }
    }

    cout << set.size();

    return 0;
}