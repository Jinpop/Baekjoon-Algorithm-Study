#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    while (n--)
    {
        int m;
        string temp;
        cin >> m >> temp;

        for (auto ele : temp)
        {
            for (int i = 0; i < m; i++)
            {
                cout << ele;
            }
        }
        cout << "\n";
    }

    return 0;
}