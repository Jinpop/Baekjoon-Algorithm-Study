#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct sum
{
    int left;
    int right;
    int sum;
} sum;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    int to_add = 0;
    int result = 0;
    int number[10][10001];
    int s[10][10001];
    int total_sum = 0;
    vector<sum> v;

    for (int i = 0; i < n; i++)
    {
        sum temp_sum;
        temp_sum.left = -1000000;
        temp_sum.right = -1000000;

        for (int j = 1; j <= m; j++)
        {
            cin >> number[i][j];
            s[i][j] = s[i][j - 1] + number[i][j];

            if (s[i][j] > temp_sum.left)
            {
                temp_sum.left = s[i][j];
            }
        }

        temp_sum.sum = max(s[i][m], 0);

        for (int j = m; j >= 0; j--)
        {
            if (s[i][m] - s[i][j] > temp_sum.right)
            {
                temp_sum.right = s[i][m] - s[i][j];
            }
        }

        int current_sum = number[i][1];
        int max_sum = number[i][1];
        for (int j = 2; j <= m; j++)
        {
            current_sum = max(number[i][j], number[i][j] + current_sum);
            max_sum = max(max_sum, current_sum);
        }
        result = max(result, max_sum);

        if (max_sum < 0)
        {
            // 전부 0이거나 음수인 수열은 배제함
        }
        else if (max_sum == s[i][m])
            // 전체의 합이 최대합인 경우 배치를 신경 쓸 필요는 없음.
            to_add += max_sum;
        else
        {
            v.push_back(temp_sum);
            total_sum += max(s[i][m], 0);
        }
    }

    int max_temp = 0;

    if (v.size() == 1)
    {
        max_temp = max(v.begin()->left, v.begin()->right);
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                int temp_total_sum = total_sum - v[i].sum - v[j].sum;
                max_temp = max(temp_total_sum + v[i].right + v[j].left, max_temp);
                max_temp = max(temp_total_sum + v[i].left + v[j].right, max_temp);
                // cout << v[i].left << " " << v[j].right << "\n";
                // cout << v[i].right << " " << v[j].left << "\n";
            }
        }
    }

    if (max_temp + to_add > result)
    {
        cout << max_temp + to_add;
    }
    else
    {
        cout << result;
    }

    return 0;
}

// 1 1
// -5
// ===== 0

// 2 4
// 1 2 -1 3
// -2 3 4 -1
// ==== 11

// 2 3
// -1 -2 -3
// -4 -5 -6
// ==== 0

// 2 3
// -1 -2 4
// -2 5 -3
// 7%
