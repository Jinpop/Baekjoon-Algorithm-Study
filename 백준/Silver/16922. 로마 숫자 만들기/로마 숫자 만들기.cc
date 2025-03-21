#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n;
int num[4] = {1, 5, 10, 50};
bool check[1001];
int result = 0;

void dfs(int idx, int number, int cnt)
{
    if (cnt == n)
    {
        if (check[number] == 0)
        {
            check[number] = 1;
            result++;
        }
        return;
    }

    for (int i = idx; i < 4; i++)
    {
        dfs(i, number + num[i], cnt + 1);
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    dfs(0, 0, 0);

    cout << result << '\n';

    return 0;
}