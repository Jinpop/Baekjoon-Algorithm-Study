#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    set<pair<int, int>> s;
    unordered_map<int, int> m;

    int temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2;
        s.insert({temp2, temp1});
        m[temp1] = temp2;
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        switch (temp[0])
        {
        case 'a':
            cin >> temp1 >> temp2;
            m[temp1] = temp2;
            s.insert({temp2, temp1});
            break;
        case 'r':
            int flag;
            cin >> flag;
            if (flag == 1)
                cout << s.rbegin()->second << "\n";
            else
                cout << s.begin()->second << "\n";
            break;
        case 's':
            int num;
            cin >> num;
            s.erase({m[num] ,num});
            break;
        default:
            break;
        }
    }

    return 0;
}
