#include <iostream>
#include <map>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    map<long long, long long> map;
    for (int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        if (temp != 0)
        {
            map[temp]++;
        }
        else
        {
            if (map.empty())
            {
                cout << "0\n";
            }
            else
            {
                cout << map.begin()->first << "\n";
                map.begin()->second--;
                if (map.begin()->second == 0)
                {
                    map.erase(map.begin());
                }
            }
        }
    }

    return 0;
}