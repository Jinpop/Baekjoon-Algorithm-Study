#include <iostream>
#include <utility>
using namespace std;
int num[1025][1025] = {0};

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> num[i][j];
            num[i][j] = num[i][j] + num[i][j - 1];
        }
    }

    for (int i = 0; i < m; i++)
    {
        pair<int, int> x, y;
        cin >> x.first >> x.second;
        cin >> y.first >> y.second;

        int result = 0;
        for (int j = x.first; j <= y.first; j++)
        {
            result += num[j][y.second];
            result -= num[j][x.second - 1];
        }

        cout << result << " \n";
    }

    return 0;
}