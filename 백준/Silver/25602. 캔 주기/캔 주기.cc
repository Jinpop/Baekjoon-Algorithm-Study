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

int num[5];
int arr[8][5];
int n, k;
int total = 0;

void dfs(int cnt, int sum)
{
    if (cnt == 2*k)
    {
        if (sum > total)
        {
            total = sum;
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (num[i] > 0)
        {
            num[i]--;
            dfs(cnt + 1, sum + arr[cnt][i]);
            num[i]++;
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < 2*k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    dfs(0, 0);

    cout << total;

    return 0;
}