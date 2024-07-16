#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        unordered_map<string, int> category;
        for (int j = 0; j < m; j++)
        {
            string temp;
            cin >> temp >> temp;
            category[temp]++;
        }

        int result = 1;
        for (pair<string, int> ele : category)
        {
            result *= ele.second + 1;
        }

        cout << result - 1 << "\n";
    }

    return 0;
}