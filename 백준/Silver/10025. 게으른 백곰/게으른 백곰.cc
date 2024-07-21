#include <iostream>
#include <map>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    map<int, int> list;
    int max_dis = 0;
    int min_dis = 1000000000;

    while (n--)
    {
        int amount, distance;
        cin >> amount >> distance;
        list[distance] += amount;
        if (max_dis < distance)
            max_dis = distance;
        if (min_dis > distance)
            min_dis = distance;
    }

    int window_size = 2 * m + 1;
    int temp_sum = 0;
    int max_sum = 0;

    // Initial window sum
    for (int i = min_dis - m; i <= min_dis + m; ++i)
    {
        if (list.count(i))
            temp_sum += list[i];
    }
    max_sum = temp_sum;

    // Slide the window from min_dis to max_dis
    for (int i = min_dis + 1; i <= max_dis; ++i)
    {
        if (list.count(i - m - 1))
            temp_sum -= list[i - m - 1];
        if (list.count(i + m))
            temp_sum += list[i + m];

        if (max_sum < temp_sum)
            max_sum = temp_sum;
    }

    cout << max_sum;

    return 0;
}
