#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        std::map<string, int> closet;
        int n;
        int sum = 1;

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            string x, y;
            cin >> x >> y;

            closet[y]++;
        }

        for (const auto &pair : closet)
        {
            sum *= (pair.second + 1);
        }

        cout << sum - 1 << "\n";
    }
    return 0;
}